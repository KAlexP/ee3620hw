#include "convolve.h"
#include <stdlib.h>

int conv(double *f1, int len1, double *f2, int len2, double *y){
  int leny = len1 + len2 - 1;
  int sum,k,m;
  // Allocate The proper amount of memory for y
  y = malloc((sizeof(double) * leny));
  for(k=0; k < leny; ++k){
    sum = 0;
    for(m=0; m < k; ++m){
      sum += f1[m] * f2[k-m];
    }
    y[k] = sum;
  }
  return leny;
}
  
