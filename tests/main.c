#include "../header.h"

int main() {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+sin(0.299)^atan(0.371)/acos((0.333/0.333)*(0.333*0.333))-acos(0.297)/sqrt(0.707)+tan((0.591^0.591)*(0.157*0.591))/log(0.555)^acos(0.943)-acos((0.969^0.969)+(0.866^0.969))+acos(0.897)*log(0.341)/sqrt((0.810*0.810)*(0.150+0.810))*log(0.413)^acos(0.383)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char exit_msg[100] = {'\0'}; 
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    // printf("EXIT MESSAGE: %s\n", exit_msg);
    if (strcmp(py_result, exit_msg)) {
      printf("PY_RES: %s\tEXIT_MSG: %s\n", py_result, exit_msg);
    }

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
