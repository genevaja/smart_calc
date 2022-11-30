#include "common_fn.h"

int calc(char *expr, char *variables, double *result) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  exit_code = parser(&stack, expr, variables);
  if (!exit_code) {
    exit_code = sort_station(&stack);
    if (!exit_code) {
      *result = stack.stack[0].value;
    }
  }
  free_stack(&stack);
  // if (exit_code > 0) {
  //   char *error[] = ERRORS;
  //   fprintf(stderr, "%s", error[exit_code]);
  // }
  return exit_code;
}
