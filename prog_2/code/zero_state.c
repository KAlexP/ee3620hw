#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

int main(void){
  double stop = 10.0,d_T = 0.001, c_dt;
  double result = 0;
  FILE *fout = fopen("zero_state.txt","w");
  for(c_dt =0; c_dt < stop; c_dt += d_T){
    result = -0.175 * exp(-2.604*c_dt) + 2 * (0.201*exp(-1.198*c_dt)*cos(2.08*c_dt + 1.12));
    fprintf(fout,"%lf\n",result);
  }
  fclose(fout);
  return 0;
}
