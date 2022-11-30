#include "../header.h"

START_TEST(calc_1) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+sin(0.686)*sqrt(0.305)^sqrt((0.141/0.141)^(0.847+0.141))*log(0.53)-sin(0.860)*asin((0.92+0.92)-(0.809+0.92))+cos(0.633)+sqrt(0.959)-sin((0.2/0.2)+(x/0.2))-"};
  char *py_result = {"Wrong expression"};
  char *x_var = {"0.1522"};
  exit_code = parser(&stack, expression, x_var);
  char exit_msg[50] = {'\0'}; 
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  ck_assert_int_eq(exit_code, 0);
  char my_result[50] = {"\\0"};
  double result = 0.0, float_py_result = atof(py_result);
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  sprintf(my_result, "%.7f", stack.stack[0].value);
  ck_assert_double_eq_tol(result, float_py_result, 1e-7);
  free_stack(&stack);
}
END_TEST

START_TEST(calc_2) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+ln(0.691)/asin(0.483)/tan((0.538/0.538)^(x^0.538))/cos(0.196)-tan(0.269)-acos((0.588/0.588)*(0.601*0.588))-ln(0.649)+acos(0.635)-sqrt((0.641-0.641)*(0.641*0.641))*"};
  char *py_result = {"Wrong expression"};
  char *x_var = {"0.1522"};
  exit_code = parser(&stack, expression, x_var);
  char exit_msg[50] = {'\0'}; 
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  ck_assert_int_eq(exit_code, 0);
  char my_result[50] = {"\\0"};
  double result = 0.0, float_py_result = atof(py_result);
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  sprintf(my_result, "%.7f", stack.stack[0].value);
  ck_assert_double_eq_tol(result, float_py_result, 1e-7);
  free_stack(&stack);
}
END_TEST

START_TEST(calc_3) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+393%211"};
  char *py_result = {"182.0"};
  char *x_var = {"0.1522"};
  exit_code = parser(&stack, expression, x_var);
  char exit_msg[50] = {'\0'}; 
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  ck_assert_int_eq(exit_code, 0);
  char my_result[50] = {"\\0"};
  double result = 0.0, float_py_result = atof(py_result);
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  sprintf(my_result, "%.7f", stack.stack[0].value);
  ck_assert_double_eq_tol(result, float_py_result, 1e-7);
  free_stack(&stack);
}
END_TEST

START_TEST(calc_4) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+log(0.866)^tan(0.468)*acos((0.123-0.123)/(0.56^0.123))-acos(0.934)+log(0.354)+atan((0.480*0.480)/(0.207*0.480))^acos(0.596)/tan(0.373)+acos((0.448^0.448)*(0.950/0.448))*log(0.159)+asin(0.529)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  exit_code = parser(&stack, expression, x_var);
  char exit_msg[50] = {'\0'}; 
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  ck_assert_int_eq(exit_code, 0);
  char my_result[50] = {"\\0"};
  double result = 0.0, float_py_result = atof(py_result);
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  sprintf(my_result, "%.7f", stack.stack[0].value);
  ck_assert_double_eq_tol(result, float_py_result, 1e-7);
  free_stack(&stack);
}
END_TEST

START_TEST(calc_5) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+sin(0.367)-log(0.52)-sqrt((0.596^0.596)-(0.596/0.596))*acos(0.253)-0.964"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  exit_code = parser(&stack, expression, x_var);
  char exit_msg[50] = {'\0'}; 
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  ck_assert_int_eq(exit_code, 0);
  char my_result[50] = {"\\0"};
  double result = 0.0, float_py_result = atof(py_result);
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  sprintf(my_result, "%.7f", stack.stack[0].value);
  ck_assert_double_eq_tol(result, float_py_result, 1e-7);
  free_stack(&stack);
}
END_TEST

START_TEST(calc_6) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+ln(0.530)+atan(0.447)-tan((0.403+0.403)-(0.559+0.403))^tan(0.704)-acos(0.740)-sqrt((0.418-0.418)/(0.418+0.418))+cos(0.178)^cos(0.861)+sqrt((0.213*0.213)-(0.213/0.213))-asin(0.568)-0.963"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  exit_code = parser(&stack, expression, x_var);
  char exit_msg[50] = {'\0'}; 
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  ck_assert_int_eq(exit_code, 0);
  char my_result[50] = {"\\0"};
  double result = 0.0, float_py_result = atof(py_result);
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  sprintf(my_result, "%.7f", stack.stack[0].value);
  ck_assert_double_eq_tol(result, float_py_result, 1e-7);
  free_stack(&stack);
}
END_TEST

START_TEST(calc_7) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+ln(0.928)*tan(0.922)^cos((0.334*0.334)*(0.334/0.334))-tan(0.674)^sqrt(0.790)+sqrt((0.628*0.628)-(0.628^0.628))+asin(0.882)-ln(0.477)^sin((0.878-0.878)*(0.550*0.878))-atan(0.29)/0.190"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  exit_code = parser(&stack, expression, x_var);
  char exit_msg[50] = {'\0'}; 
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  ck_assert_int_eq(exit_code, 0);
  char my_result[50] = {"\\0"};
  double result = 0.0, float_py_result = atof(py_result);
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  sprintf(my_result, "%.7f", stack.stack[0].value);
  ck_assert_double_eq_tol(result, float_py_result, 1e-7);
  free_stack(&stack);
}
END_TEST

START_TEST(calc_8) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+sin(0.26)*sin(0.796)-asin((0.841+0.841)-(x^0.841))^"};
  char *py_result = {"Wrong expression"};
  char *x_var = {"0.1522"};
  exit_code = parser(&stack, expression, x_var);
  char exit_msg[50] = {'\0'}; 
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  ck_assert_int_eq(exit_code, 0);
  char my_result[50] = {"\\0"};
  double result = 0.0, float_py_result = atof(py_result);
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  sprintf(my_result, "%.7f", stack.stack[0].value);
  ck_assert_double_eq_tol(result, float_py_result, 1e-7);
  free_stack(&stack);
}
END_TEST

START_TEST(calc_9) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.97)^sin(0.553)-asin((0.820^0.820)*(x-0.820))-sqrt(0.330)^cos(0.312)+log((0.948^0.948)-(0.948-0.948))/acos(0.595)+sqrt(0.857)"};
  char *py_result = {"1.9076658"};
  char *x_var = {"0.1522"};
  exit_code = parser(&stack, expression, x_var);
  char exit_msg[50] = {'\0'}; 
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  ck_assert_int_eq(exit_code, 0);
  char my_result[50] = {"\\0"};
  double result = 0.0, float_py_result = atof(py_result);
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  sprintf(my_result, "%.7f", stack.stack[0].value);
  ck_assert_double_eq_tol(result, float_py_result, 1e-7);
  free_stack(&stack);
}
END_TEST

START_TEST(calc_10) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+atan(0.916)*tan(0.696)*acos((0.63^0.63)+(x^0.63))+"};
  char *py_result = {"Wrong expression"};
  char *x_var = {"0.1522"};
  exit_code = parser(&stack, expression, x_var);
  char exit_msg[50] = {'\0'}; 
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  ck_assert_int_eq(exit_code, 0);
  char my_result[50] = {"\\0"};
  double result = 0.0, float_py_result = atof(py_result);
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  }

  sprintf(my_result, "%.7f", stack.stack[0].value);
  ck_assert_double_eq_tol(result, float_py_result, 1e-7);
  free_stack(&stack);
}
END_TEST

Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_calc;

    s = suite_create("calc");

    tc_calc = tcase_create("calc");
    tcase_add_test(tc_calc, calc_1);
    tcase_add_test(tc_calc, calc_2);
    tcase_add_test(tc_calc, calc_3);
    tcase_add_test(tc_calc, calc_4);
    tcase_add_test(tc_calc, calc_5);
    tcase_add_test(tc_calc, calc_6);
    tcase_add_test(tc_calc, calc_7);
    tcase_add_test(tc_calc, calc_8);
    tcase_add_test(tc_calc, calc_9);
    tcase_add_test(tc_calc, calc_10);

    suite_add_tcase(s, tc_calc);
    
    return s;
}

int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;
    s = sprintf_test();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
