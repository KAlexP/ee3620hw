#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

int main(void){
  double stop = 10.0,d_T = 0.001, c_dt;
  FILE *fout = fopen("sine.txt","w");
  for(c_dt =0; c_dt < stop; c_dt += d_T){
    fprintf(fout,"%lf\n",sin(2.5 * M_PI * c_dt));
  }
  fclose(fout);
  return 0;
}
