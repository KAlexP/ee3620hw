#include <stdio.h>
#include <stdlib.h>
#include "convolve.h"
#include "matrix.h"

void Ft_conv_Ht(void);
int  program_1_code(void);

int main(void) {
  int          itr, leny;
  double*      y;
  const int    len1 = 6, len2 = 7, len3 = 4, len4 = 5;
  const double f1[len1] = {0, 1, 2, 3, 2, 1};
  const double f2[len2] = {-2, -2, -2, -2, -2, -2, -2};
  const double f3[len3] = {1, -1, 1, -1};
  const double f4[len4] = {0, 0, 0, -3, -3};
  const double X[3]     = {0.4, 0.35, 0.25};
  const double Y[4]     = {0.25, 0.20, 0.20, 0.35};

  printf("f1: ");
  for (itr = 0; itr < len1; itr++) { printf(" %5.0lf", f1[itr]); }
  printf("\nf2: ");
  for (itr = 0; itr < len2; itr++) { printf(" %5.0lf", f2[itr]); }
  printf("\nf3: ");
  for (itr = 0; itr < len3; itr++) { printf(" %5.0lf", f3[itr]); }
  printf("\nf4: ");
  for (itr = 0; itr < len4; itr++) { printf(" %5.0lf", f4[itr]); }
  printf("\n\n");
  /*  Problem 2.A   */
  leny = conv(f1, len1, f1, len1, &y);
  printf("f1 * f1: ");
  for (itr = 0; itr < leny; ++itr) { printf(" %5.0lf", y[itr]); }
  free(y);
  /*   Problem 2.B  */
  printf("\nf1 * f2: ");
  leny = conv(f1, len1, f2, len2, &y);
  for (itr = 0; itr < leny; ++itr) { printf(" %5.0lf", y[itr]); }
  free(y);
  /* Problem 2.C */
  printf("\nf1 * f3: ");
  leny = conv(f1, len1, f3, len3, &y);
  for (itr = 0; itr < leny; ++itr) { printf(" %5.0lf", y[itr]); }
  free(y);
  /* Problem 2.D */
  printf("\nf2 * f3: ");
  leny = conv(f2, len2, f3, len3, &y);
  for (itr = 0; itr < leny; ++itr) { printf(" %5.0lf", y[itr]); }
  free(y);
  /* Problem 2.E */
  printf("\nf1 * f4: ");
  leny = conv(f1, len1, f4, len4, &y);
  for (itr = 0; itr < leny; ++itr) { printf(" %5.0lf", y[itr]); }
  free(y);
  // Get results for the zero input 
  program_1_code();
  // Perform the convolution and summing of h_t and zero_input
  Ft_conv_Ht();
  return 0;
}

int program_1_code(void) {
  FILE* fout = fopen("zero_input.txt", "w");
  if (fout == NULL) {
    perror("output file failed");
    return EXIT_FAILURE;
  }
  double I[][3]  = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  double A[][3]  = {{0, 1, 0}, {0, 0, 1}, {-15, -12, -5}};
  double x_t[3]  = {-2, 3, 4};
  double delta_t = 0.001f;
  double time;
  // avoid unnecessary function calls in loop
  mat_scale(delta_t, A, A);
  mat_add(I, A, A);
  // Do iterative math
  for (time = 0.0; time < 10.0; time += delta_t) {
    // print the result
    fprintf(fout, "%.10lf\n", x_t[0]);
    // get next x_t value
    mat_vec_mult(A, x_t, x_t);
  }
  fclose(fout);
  return EXIT_SUCCESS;
}

void Ft_conv_Ht(void) {
  double ft[10000] = {0};
  double ht[10000] = {0};
  double zi[10000] = {0};
  char   buff[100];
  int     leny = 0;
  double* y;
  FILE*   FT_FILE = fopen("sine.txt", "r");
  if (FT_FILE == NULL) {
    printf("Error: sine.txt doesn't exist\n");
    exit(1);
  }
  FILE* HT_FILE = fopen("h_t.txt", "r");
  if (HT_FILE == NULL) {
    printf("Error: h_t.txt doesn't exist\n");
    exit(1);
  }
  FILE* ZI_FILE = fopen("zero_input.txt", "r");
  if (ZI_FILE == NULL) {
    printf("error: zero_input.txt didn't open\n");
    exit(1);
  }
  FILE* TOTAL_RESPONSE = fopen("total_result.txt", "w");
  if (TOTAL_RESPONSE == NULL) {
    printf("total_result.txt not opened\n");
    exit(1);
  }
  for (int i = 0; i < 10000; i++) {
    if (!fgets(buff, sizeof(buff), FT_FILE)) { printf("Reached end of file at line %d\n", i); break; }
    char*  endptr;
    double value = strtod(buff, &endptr);
    if (endptr == buff) { printf("Invalid number on line %d: %s\n", i, buff); continue; }
    ft[i] = value;
  }
  fclose(FT_FILE);
  for (int i = 0; i < 10000; i++) {
    if (!fgets(buff, sizeof(buff), HT_FILE)) { printf("Reached end of file at line %d\n", i); break; }
    char*  endptr;
    double value = strtod(buff, &endptr);
    if (endptr == buff) { printf("Invalid number on line %d: %s\n", i, buff); continue; }
    ht[i] = value;
  }
  fclose(HT_FILE);
  // Perform the convolution
  leny = conv(ht, sizeof(ht) / sizeof(ht[0]), ft, sizeof(ft) / sizeof(ft[0]), &y);
  // Scale the convolution by 0.001
  for(int itr = 0; itr < leny; itr++){
    y[itr] *= 0.001;
  }
  for (int i = 0; i < 10000; i++) {
    if (!fgets(buff, sizeof(buff), ZI_FILE)) {printf("Reached end of file at line %d\n", i); break; }
    char*  endptr;
    double value = strtod(buff, &endptr);
    if (endptr == buff) { printf("Invalid number on line %d: %s\n", i, buff); continue; }
    zi[i] = value;
  }
  fclose(ZI_FILE);
  double temp = 0;
  for (int itr = 0; itr < 20000; itr++) {
    if (itr < 10000) {
      temp = zi[itr];
    } else {
      temp = 0;
    }
    fprintf(TOTAL_RESPONSE, "%lf\t%.10lf\n", (double) itr / 1000, y[itr] + temp);
  }
  free(y);
}
