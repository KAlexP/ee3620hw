#include "main.h"

// Problem 3 Code
int problem_3(void) {
  FILE* fout = fopen("prog_sol_3.txt", "w");
  if (fout == NULL) {
    perror("output file failed");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
