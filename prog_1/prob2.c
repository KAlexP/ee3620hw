// Problem 2 Code
int problem_2(void) {
  FILE* fout = fopen("prog_sol_2.txt", "w");
  if (fout == NULL) {
    perror("output file failed");
    return EXIT_FAILURE;
  }
  double I[][3]  = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  double A[][3]  = {{0, 1, 0}, {0, 0, 1}, {-2.5063, -25.1125, -0.6}};
  double x_t[3]  = {1.5, 2, -1};
  double delta_t = 0.001f;
  double time;
  // avoid unnecessary function calls in loop
  mat_scale(delta_t, A, A);
  mat_add(I, A, A);
  // Do iterative math
  for (time = 0.0; time < 10.0; time += delta_t) {
    // print the result
    fprintf(fout, "%.3lf\t%.10lf\n", time, x_t[0]);
    // get next x_t value
    mat_vec_mult(A, x_t, x_t);
  }
  return EXIT_SUCCESS;
}
