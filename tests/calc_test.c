#include "../header.h"

START_TEST(calc_1) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+log(0.258)*ln(0.951)+sin((0.862/0.862)^(x-0.862))/atan(0.311)-tan(0.596)*sin((0.959*0.959)/(0.510+0.959))*cos(0.899)-ln(0.213)"};
  char *py_result = {"1.9570829"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_2) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+tan(0.564)-log(0.872)-tan((0.969+0.969)+(0.969/0.969))+atan(0.314)+asin(0.506)/asin((0.981+0.981)^(0.837^0.981))-ln(0.701)^sin(0.677)-tan((0.190+0.190)-(x+0.190))-sqrt(0.685)^ln(0.140)-log((0.321^0.321)+(x+0.321))/"};
  char *py_result = {"Wrong expression"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_3) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+ln(0.96)^cos(0.610)-tan((0.867-0.867)/(x*0.867))-"};
  char *py_result = {"Wrong expression"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

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
