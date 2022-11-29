#include "../header.h"

START_TEST(calc_1) {
  char *string = "1+x";
  char *variable = "2";
  double result = 0;
  int exit_code = calc(string, variable, &result);
  ck_assert_int_eq(exit_code, 0);
  ck_assert_double_eq_tol(result, 3.000000, 1e-6);
}
END_TEST

START_TEST(calc_2) {
  char *string = "1+2";
  char *variable = NULL; 
  double result = 0;
  int exit_code = calc(string, variable, &result);
  ck_assert_int_eq(exit_code, 0);
  ck_assert_double_eq_tol(result, 3.000000, 1e-6);
}
END_TEST

START_TEST(calc_3) {
  char *string = "1+2-5";
  char *variable = NULL; 
  double result = 0;
  int exit_code = calc(string, variable, &result);
  ck_assert_int_eq(exit_code, 0);
  ck_assert_double_eq_tol(result, -2.000000, 1e-6);
}
END_TEST

START_TEST(calc_4) {
  char *string = "1+2+(-5)";
  char *variable = NULL; 
  double result = 0;
  int exit_code = calc(string, variable, &result);
  ck_assert_int_eq(exit_code, 0);
  ck_assert_double_eq_tol(result, -2.000000, 1e-6);
}
END_TEST

START_TEST(calc_5) {
  char *string = "-10+1+2";
  char *variable = NULL; 
  double result = 0;
  int exit_code = calc(string, variable, &result);
  ck_assert_int_eq(exit_code, 0);
  ck_assert_double_eq_tol(result, -7.000000, 1e-6);
}
END_TEST

START_TEST(calc_6) {
  char *string = "-0.345+0.345+(-0.345)+0.345+cos(0.505)*0.674";
  char *variable = NULL; 
  double result = 0;
  int exit_code = calc(string, variable, &result);
  ck_assert_int_eq(exit_code, 0);
  ck_assert_double_eq_tol(result, 0.5898675, 1e-7);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_calc;

  s = suite_create("calc_test");

  tc_calc = tcase_create("calc_test");
  tcase_add_test(tc_calc, calc_1);
  tcase_add_test(tc_calc, calc_2);
  tcase_add_test(tc_calc, calc_3);
  tcase_add_test(tc_calc, calc_4);
  tcase_add_test(tc_calc, calc_5);
  tcase_add_test(tc_calc, calc_6);
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
