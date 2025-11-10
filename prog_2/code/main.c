#include <stdio.h>
#include <stdlib.h>
#include "convolve.h"

int main(void){
  int itr, leny;
  double *y;
  const int len1 = 6,len2 = 7, len3 = 4, len4 = 5;
  const double f1[len1] = {0,1,2,3,2,1};
  const double f2[len2] = {-2,-2,-2,-2,-2,-2,-2};
  const double f3[len3] = {1,-1,1,-1};
  const double f4[len4] = {0,0,0,-3,-3};
  const double X[3] =  {0.4,0.35,0.25};
  const double Y[4] = {0.25,0.20,0.20,0.35};

 
  printf("f1: ");
  for(itr = 0; itr < len1; itr++){
    printf(" %5lf", f1[itr]);
  }
  printf("\nf2: ");
  for(itr = 0; itr < len2; itr++){
    printf(" %5lf", f2[itr]);
  }
  printf("\nf3: ");
  for(itr = 0; itr < len3; itr++){
    printf(" %5lf", f3[itr]);
  }
  printf("\nf4: ");
  for(itr = 0; itr < len4; itr++){
    printf(" %5lf", f4[itr]);
  }
  printf("\n\n");
  leny = conv(f1,len1,f1,len1,&y);
  printf("f1 * f1: ");
  for(itr = 0; itr < leny; ++itr){
    printf(" %5lf",y[itr]);
  }
  free(y);
  printf("\nf1 * f2: ");
  leny = conv(f1,len1,f2,len2, &y);
  for(itr = 0; itr < leny; ++itr){
    printf(" %5lf",y[itr]);
  }
  free(y);
  printf("\nX * Y: ");
  leny = conv(X,3,Y,4, &y);
  for(itr = 0; itr < leny; ++itr){
    printf(" %5lf",y[itr]);
  }
  free(y);
  return 0;
}
