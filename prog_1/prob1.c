// Problem 1 Code
int problem_1(void) {
  FILE* fout = fopen("prog_sol_1.txt", "w");
  if (fout == NULL) {
    perror("output file failed");
    return EXIT_FAILURE;
  }
  // Declare and Initialize variables
  double y       = 3.0;
  double delta_t = 0.001;
  double time    = 0;
  double a       = -2.5;
  // This line doesn't change in the loop
  a = (1 + a * delta_t);
  // Do the math iteratively in a loop
  for (time = 0.0; time < 10.0; time += delta_t) {
    // Print the t, y(t) coordinate
    fprintf(fout, "%0.3lf\t%0.10lf\n", time, y);
    // Do the calculation
    y = a * y;
  }
  return EXIT_SUCCESS;
}
