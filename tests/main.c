#include "../header.h"

int main() {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char string[] = {"0.1+0.1+0.2+0.3+0.4"};
  parser(&stack, string);
  output(&stack);
  sort_station(&stack); 
  printf("Expression: %s\nResult: %.6f\n", string, stack.stack[0].value);
  output(&stack);
  free_stack(&stack);
  return exit_code;
}
