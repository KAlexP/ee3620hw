#ifndef __MATRIX_H_
#define __MATRIX_H_
// 2x2 Matrix and Vector Functions
void mat_scale2(double scale, double mat[][2], double prod[][2]);
void mat_sub2(double left[][2], double right[][2], double diff[][2]);
void mat_add2(double left[][2], double right[][2], double sum[][2]);
void mat_vec_mult2(double mat[][2], double* vector, double* prod);
// 3x3 Matrix and Vector Functions
void mat_scale(double scale, double mat[][3], double prod[][3]);
void mat_sub(double left[][3], double right[][3], double diff[][3]);
void mat_add(double left[][3], double right[][3], double sum[][3]);
void mat_vec_mult(double mat[][3], double* vector, double* prod);
#endif
