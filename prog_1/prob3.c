// Problem 3 Code
int problem_3(void) {
  FILE* fout = fopen("./prog_out/prog_sol_3.txt", "w");
  if (fout == NULL) {
    perror("output file failed");
    return EXIT_FAILURE;
  }
  double A[][2]  = {{0, 1}, {195.651, 869.57}};
  double I[][2]  = {{1, 0}, {0, 1}};
  double x_t[2]  = {5, 847.83};
  double delta_t = 0.001;
  double time;

  mat_scale2(delta_t, A, A);
  mat_add2(I, A, A);
  for (time = 0.0; time <= 10.0; time += delta_t) {
    fprintf(fout, "0.3lf\t0.10lf\n", time, x_t[0]);
    mat_vec_mult2(A, x_t, x_t);
  }
  return EXIT_SUCCESS;
}
