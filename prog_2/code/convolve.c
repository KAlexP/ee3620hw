#include "convolve.h"
#include <stdlib.h>
#include <stdio.h>

int conv(double *f1, int len1, double *f2, int len2, double **y){
  int leny = len1 + len2 - 1;
  int in_b, m_start;
  // Allocate The proper amount of memory for y
  *y = malloc((sizeof(double) * leny));
  for(int i = 0; i < len1; i++){
    for(int j = 0; j < len2; j++){
      (*y)[i+j] += f1[i] * f2[j];
    }
  }
  return leny;
}
