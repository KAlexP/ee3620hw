#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Functions for the problem
void problem_1(void);
void problem_2(void);
void problem_3(void);

// 3x3 matrix functions
void mat_scale(double scale, double mat[][3], double prod[][3]);
void mat_sub(double left[][3], double right[][3], double diff[][3]);
void mat_vec_mult(double mat[][3], double *v, double *prod);

int main(int argc, char** argv){
  int problem = 1;
  if(argc < 2){
    printf("Enter problem problem: ");  // Prompt user to select problem
    scanf("%d", &problem);              // accept user input
  } else {
    problem = atoi(argv[1]);            // Assign the value from the command line
  }
  FILE *fout = fopen("dump_file","w");
  if(fout == NULL){
    perror("output file failed");
    return EXIT_FAILURE;
  }
  bool done = false;
  char count = 0;
  while(!done){
    (count > 2) ? done = true: count++;
    switch(problem){
      case 1: problem_1();
        break;
      case 2: problem_2();
        break;
      case 3: problem_3();
        break;
      default: 
        printf("Error please choose 1-3.\n");
        break;
    }
  }
  return EXIT_SUCCESS;
}


void problem_1(void){

}
void problem_2(void){

}
void problem_3(void){
  
}

// scale matrix `mat` by a and save in prod
void mat_scale(double scale, double mat[][3], double prod[][3]){
  int i, j;
  for(i = 0; i < 3; ++i){
    for(j = 0; j < 3; ++j){
      prod[i][j] = scale * mat[i][j];
    }
  }
}

// subtract right from left and stor in diff
void mat_sub(double left[][3], double right[][3], double diff[][3]){
  int i,j;
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      diff[i][j] = left[i][j] - right[i][j];
    }
  }
}
// Unsafe if used incorrectly!
void mat_vec_mult(double mat[][3], double *v, double *prod){
  double sum;
  int i,j;
  for(i = 0; i < 3; i++){
    sum = 0;
    for (j = 0; j < 3; j++){
      sum += m[i][j] * v[y];
    }
    prod[i] = sum;
  }
}

