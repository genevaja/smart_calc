#include "../header.h"

START_TEST(calc_1) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.506)+sin(0.660)*asin((0.340-0.340)^(0.30^0.340))+cos(0.745)/tan(0.40)^atan((0.582-0.582)^(0.339^0.582))/atan(0.876)*0.326"};
  char *py_result = {"0.8872297"};
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
  char *expression = {"log(0.35)^tan(0.378)*ln((0.706^0.706)^(0.706^0.706))^atan(0.668)-acos(0.321)*tan((0.937-0.937)^(0.535+0.937))/tan(0.675)^acos(0.160)+sin((0.496/0.496)^(x-0.496))+atan(0.468)^sqrt(0.716)-asin((0.373+0.373)^(x^0.373))/sin(0.222)"};
  char *py_result = {"(-3.6838581508551256+0.0121694071907619j)"};
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
  char *expression = {"asin(0.750)+asin(0.336)+sin((0.614/0.614)^(0.788/0.614))/asin(0.929)^ln(0.827)+log((0.663+0.663)-(0.433^0.663))/sqrt(0.427)-cos(0.260)+ln((0.429^0.429)+(0.826/0.429))-sqrt(0.21)*asin(0.204)/acos((0.960^0.960)^(x-0.960))^"};
  char *py_result = {"unexpected EOF while parsing (<string>, line 1)"};
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

START_TEST(calc_4) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.141)^sin(0.819)/sqrt((0.457-0.457)+(0.260+0.457))-sin(0.414)/acos(0.870)+ln((0.370*0.370)*(0.370/0.370))*"};
  char *py_result = {"unexpected EOF while parsing (<string>, line 1)"};
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

START_TEST(calc_5) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.797)^0.416"};
  char *py_result = {"0.9669168"};
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

START_TEST(calc_6) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"796%316"};
  char *py_result = {"164"};
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

START_TEST(calc_7) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.230)^cos(0.634)*asin((0.420/0.420)^(0.420/0.420))/log(0.849)+ln(0.514)/log((0.302-0.302)^(0.352*0.302))/tan(0.149)/cos(0.187)^atan((0.315/0.315)/(0.741-0.315))+log(0.529)*cos(0.583)"};
  char *py_result = {"math domain error"};
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

START_TEST(calc_8) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.345)^cos(0.436)/atan((0.292/0.292)/(0.989-0.292))-atan(0.819)/log(0.544)/sin((0.536^0.536)+(x-0.536))^sqrt(0.773)/atan(0.890)+atan((0.480-0.480)*(x/0.480))^atan(0.681)/0.345"};
  char *py_result = {"9.9718191"};
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

START_TEST(calc_9) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.252)^sqrt(0.691)^ln((0.599-0.599)*(x/0.599))+cos(0.972)/log(0.929)/sqrt((0.849-0.849)-(0.630*0.849))^acos(0.928)-log(0.429)"};
  char *py_result = {"math domain error"};
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

START_TEST(calc_10) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.422)-acos(0.964)-tan((0.976/0.976)-(0.976/0.976))/log(0.640)"};
  char *py_result = {"0.1301871"};
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
