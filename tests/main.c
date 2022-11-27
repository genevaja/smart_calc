#include "../header.h"

int main() {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char string[] = {"0.1+0.1"};
  parser(&stack, string);
  sort_station(&stack); 
  stack_output(&stack);
  free_stack(&stack);
  return exit_code;
}
