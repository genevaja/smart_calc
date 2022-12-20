#include "../header.h"

int main(int argc, char **argv) {
  if (argc < 2)
    return 0;
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char expression[MAX_BUF] = {'\0'};
  strcpy(expression, argv[1]);
  // char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char exit_msg[100] = {'\0'}; 
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    // printf("EXIT MESSAGE: %s\n", exit_msg);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      printf("MY_RESULT: %s\n", my_result);
  }

  free_stack(&stack);
  return exit_code;
}




  // char *expression = {"
  //   -
  //   0.345
  //   +0.345+(-0.345)+0.345+tan(0.564)-log(0.872)-tan((0.969+0.969)+(0.969/0.969))+atan(0.314)+asin(0.506)/asin((0.981+0.981)^(0.837^0.981))-ln(0.701)^sin(0.677)-tan((0.190+0.190)-(x+0.190))-sqrt(0.685)^ln(0.140)-log((0.321^0.321)+(x+0.321))/"};
  //
