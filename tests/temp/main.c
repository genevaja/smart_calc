#include "../header.h"

int main() {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+tan(0.386)^tan(0.644)-asin((0.110+0.110)/(0.595^0.110))*log(0.209)^asin(0.322)+asin((0.500/0.500)^(x^0.500))+ln(0.431)*tan(0.633)^ln((0.921*0.921)*(0.921+0.921))^sqrt(0.649)*sin(0.697)/tan((0.67/0.67)^(x^0.67))*sin(0.354)-0.702"};
  // char *py_result = {"Too long weird result"};
  char *x_var = {"0.1522"};
  // char exit_msg[50] = {'\0'};
  double result = 0.0;
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    printf("%s", error[exit_code]);
    // sprintf(exit_msg, "%s", error[exit_code]);
    // ck_assert_str_eq(exit_msg, py_result);
  } else {
    printf("Else: %.7f", result);
  }
  free_stack(&stack);
}
