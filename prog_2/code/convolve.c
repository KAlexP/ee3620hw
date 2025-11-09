#include "convolve.h"
#include <stdlib.h>

int conv(double *f1, int len1, double *f2, int len2, double **y){
  int leny = len1 + len2 - 1;
  int k,m;
  int in_b, out_b;
  double sum = 0;
  // Allocate The proper amount of memory for y
  *y = malloc((sizeof(double) * leny));
  for(k=0; k < leny; ++k){
    out_b = (k - (len1-1)) > 0 ? (k - (len1 - 1)) : 0;
    in_b = (k < len2) < len2   ? k : (len2 - 1);
    sum = 0;
    for(m=out_b; m < in_b && m < len1; ++m){
      sum += f1[m] * f2[k-m];
    }
    (*y)[k] = sum;
  }
  return leny;
}
  
