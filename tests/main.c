#include "../header.h"

int main() {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char string[] = {"((((2.123+2.321)+2.1005)^2.384)/6.211)*10"};
  // char string[] = {"0.1+0.1+8%3"};
  // char string[] = {"2.2^2.2+0.1+0.2-0.5"};
  exit_code = parser(&stack, string);
  // output(&stack);
  if (!exit_code) {
    exit_code = sort_station(&stack); 
    // printf("CHECK: %+.6f\n", 0.0 - 1.0);
    if (!exit_code) {
      printf("Expression: %s\nResult: %+.20f\n", string, stack.stack[0].value);
    }
    // output(&stack);
  }
  free_stack(&stack);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    fprintf(stderr, "%s", error[exit_code]);
  }
  return exit_code;
}
