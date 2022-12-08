#include "../header.h"

START_TEST(calc_1) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+cos(0.258)*acos(0.887)+acos((0.10*0.10)+(x^0.10))/asin(0.945)/sin(0.407)/sqrt((0.900/0.900)-(0.900/0.900))-log(0.307)^log(0.542)*log((0.479*0.479)/(x/0.479))-cos(0.569)-asin(0.152)+cos((0.967+0.967)/(0.967/0.967))*ln(0.543)/tan(0.749)*cos((0.476*0.476)-(x*0.476))/"};
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

START_TEST(calc_2) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+atan(0.630)*atan(0.927)+atan((0.853+0.853)/(x^0.853))+asin(0.56)+cos(0.350)-tan((0.730/0.730)*(0.971*0.730))-tan(0.758)*tan(0.209)^cos((0.29+0.29)*(0.29+0.29))+cos(0.624)*sqrt(0.172)*asin((0.381^0.381)*(0.449/0.381))^atan(0.316)/0.750"};
  char *py_result = {"2.7735670"};
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
  char *expression = {"-0.345+0.345+(-0.345)+0.345+atan(0.343)+log(0.687)^atan((0.301+0.301)-(x/0.301))*atan(0.253)*log(0.775)/acos((0.118*0.118)^(0.118+0.118))+"};
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

START_TEST(calc_4) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+sin(0.166)*tan(0.211)*cos((0.605/0.605)^(0.605/0.605))^tan(0.759)*ln(0.517)*tan((0.59/0.59)^(0.59/0.59))+atan(0.996)^atan(0.123)/sqrt((0.812-0.812)^(0.111-0.812))+atan(0.310)-asin(0.217)*acos((0.672+0.672)/(x*0.672))^sin(0.215)"};
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

START_TEST(calc_5) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+ln(0.664)*atan(0.509)+log((0.810^0.810)-(x^0.810))^tan(0.546)^asin(0.456)^sin((0.90/0.90)+(0.686^0.90))*atan(0.701)/0.1"};
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

START_TEST(calc_6) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+sin(0.299)^atan(0.371)/acos((0.333/0.333)*(0.333*0.333))-acos(0.297)/sqrt(0.707)+tan((0.591^0.591)*(0.157*0.591))/log(0.555)^acos(0.943)-acos((0.969^0.969)+(0.866^0.969))+acos(0.897)*log(0.341)/sqrt((0.810*0.810)*(0.150+0.810))*log(0.413)^acos(0.383)"};
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

START_TEST(calc_7) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+asin(0.366)/log(0.834)*asin((0.54+0.54)+(0.876^0.54))/sin(0.571)/log(0.718)^asin((0.325/0.325)-(0.897^0.325))-log(0.19)/tan(0.334)"};
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
  char *expression = {"-0.345+0.345+(-0.345)+0.345+acos(0.800)-cos(0.538)*acos((0.115+0.115)-(0.346*0.115))+sin(0.36)*log(0.535)+atan((0.64-0.64)^(0.64*0.64))-cos(0.664)"};
  char *py_result = {"-1.4242831"};
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
  char *expression = {"-0.345+0.345+(-0.345)+0.345+asin(0.831)^log(0.662)/asin((0.962^0.962)+(x^0.962))^sqrt(0.659)-log(0.873)/acos((0.530+0.530)-(x^0.530))-acos(0.229)/sqrt(0.416)-acos((0.832-0.832)/(0.832*0.832))/tan(0.494)*atan(0.776)-tan((0.330+0.330)*(x^0.330))*cos(0.268)^log(0.313)/tan((0.149/0.149)-(0.190-0.149))/"};
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

START_TEST(calc_10) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"-0.345+0.345+(-0.345)+0.345+sin(0.692)-tan(0.768)^ln((0.501/0.501)*(0.501*0.501))^log(0.503)-log(0.93)/acos((0.653+0.653)^(0.413-0.653))*tan(0.285)*sin(0.328)-atan((0.478*0.478)/(0.478+0.478))*acos(0.340)*sin(0.202)/ln((0.70*0.70)*(0.591^0.70))-cos(0.790)"};
  char *py_result = {"-1.2017121"};
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
