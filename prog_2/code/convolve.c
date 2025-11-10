#include "convolve.h"
#include <stdlib.h>
#include <stdio.h>

int conv(double *f1, int len1, double *f2, int len2, double **y){
  int leny = len1 + len2 - 1;
  int k,m;
  int in_b, m_start;
  double sum = 0;
  // Allocate The proper amount of memory for y
  *y = malloc((sizeof(double) * leny));
  for(k=0; k < leny; ++k){
    m_start = (k - (len1-1)) > 0 ? (k - (len1 - 1)) : 0;
    in_b = (k < len2) < len2   ? k : (len2 - 1);
    sum = 0.0;
    printf("\n\n");
    for(m=m_start; m < in_b && m < len1; ++m){
      sum += f1[m] * f2[k-m-1];
      printf("f1[%d] * f2[%d] = %lf\tsum: %lf\n", m, k-m, f1[m] * f2[k-m],sum);
    }
    (*y)[k] = sum;
  }
  return leny;
}
  
