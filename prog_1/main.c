#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Functions for the problem
int problem_1(void);
int problem_2(void);
int problem_3(void);

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
  
  bool done = false;
  char count = 0;
  while(!done){
    (count > 2) ? done = true: count++;
    switch(problem){
      case 1: problem_1() ? printf("Problem 1 success\n"): printf("Error in Problem 1\n");
        break;
      case 2: problem_2() ? printf("Problem 1 success\n"): printf("Error in Problem 1\n");
        break;
      case 3: problem_3() ? printf("Problem 1 success\n"): printf("Error in Problem 1\n");
        break;
      default: 
        printf("Error please choose 1-3.\n");
        break;
    }
  }
  return EXIT_SUCCESS;
}


int problem_1(void){
FILE *fout = fopen("prog_sol_1.txt","w");
  if(fout == NULL){
    perror("output file failed");
    return EXIT_FAILURE;
  }


  return EXIT_SUCCESS;
}
// Problem 2 Code
int problem_2(void){
FILE *fout = fopen("dump_file","w");
  if(fout == NULL){
    perror("output file failed");
    return EXIT_FAILURE;
  }


  return EXIT_SUCCESS;
}
// Problem 3 Code
int problem_3(void){
 FILE *fout = fopen("dump_file","w");
  if(fout == NULL){
    perror("output file failed");
    return EXIT_FAILURE;
  } 
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

