#include "main.h"

/*******************************************************************************
 * Function Title: main
 * Summary: This funcion facilitates the selection and calling of a problem
 *          function and prints relevant error statements
 *
 * Inputs:
 *     int argc: the amount of arguements passed to main
 *     char** argv: the arguements passed as a string to main
 * Outputs:
 *     int: an error code to the operating system on program execution
 *
 * Compile Instructions: gcc main.c -o main
 ********************************************************************************
 * Pseudocode
 *   Begin
 *     if there was no number passed in the command line
 *       prompt input for problem selection
 *     else
 *       convert command line input
 *     call correct problem number 1,2, or 3
 *       call function
 *       if it returns error
 *         print Error
 *       else
 *         print success
 *   End
 *******************************************************************************/
int main(int argc, char** argv) {
  //  Begin Program
  int problem;
  // If no arguements prompt and recieve input
  if (argc < 2) {
    printf("Enter problem number: ");  // Prompt user to select problem
    scanf("%d", &problem);             // accept user input
  } else {
    // else use command line arguement
    problem = atoi(argv[1]); // Assign the value from the command line
  }
  // Do the selected problem
  switch (
      problem) { // if the problem fails to make a file print Error statement
    case 1:
      (problem_1() == 0) ? printf("Problem 1 success\n")
                         : printf("Error in Problem 1\n");
      break;
    case 2:
      (problem_2() == 0) ? printf("Problem 2 success\n")
                         : printf("Error in Problem 2\n");
      break;
    case 3:
      (problem_3() == 0) ? printf("Problem 3 success\n")
                         : printf("Error in Problem 3\n");
      break;
    default:
      printf("Error please choose 1-3.\n");
  }
  // End Program
  return EXIT_SUCCESS;
}


