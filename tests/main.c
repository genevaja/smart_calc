#include "../header.h"

int main() {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.423", ")", "-", "ln", "(", "0.197", ")", "^", "cos", "(", "(", "0.642", "+", "0.642", ")", "^", "(", "0.120", "+", "0.642", ")", ")", "-", "sqrt", "(", "0.432", ")", "*", "sin", "(", "0.800", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.423)-ln(0.197)^cos((0.642+0.642)^(0.120+0.642))-sqrt(0.432)*sin(0.800)"};
  exit_code = parser(&stack, example);
  stack_output(&stack);
  free_stack(&stack);
  return exit_code;
}
