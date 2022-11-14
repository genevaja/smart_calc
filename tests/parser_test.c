#include "../header.h"

START_TEST(parser_1) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sin", "(", "1.423", ")", "^", "cos", "(", "3.25", 
                    ")", "/", "(", "tan", "(", "2", ")", "-", "ctg", "(",
                    "3.1113", ")", ")", "*", "sqrt", "(", "(", "5.12", "+",
                    "10.88", ")", ")", "+", "-", "1"};
  char *example = {"sin(1.423)^cos(3.25)/(tan(2)-ctg(3.1113))*sqrt((5.12+10.88))+-1"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.data[i]), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_2) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sqrt", "(", "41.", ")", "^", "2", "+", "(",
                    "cos", "(", "x", "^", "2", ")", "*", "sin", "(",
                    "21", "-", "7", "+", "-", "1", ")", ")"};
  char *example = "sqrt(41.)^2+(cos(x^2)*sin(21-7+-1))";
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.data[i]), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_3) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  // char *string[] = {"sqrt", "(", "41.", ")", "^", "2", "+", "(",
  //                   "cos", "(", "x", "^", "2", ")", "*", "sin", "(",
  //                   "21", "-", "7", "+", "-", "1", ")", ")"};
  // char *example = {"sqrt(41.)^2+(cos(x^2)*sin(21-7+-1))"};
  char *string[] = {"(", "123.144215", "+", "14223.14213", ")", "*",
                    "1.02847", "/", "0.3212", "-", "sin", "(", "x", ")"};;
  char *example = "(123.144215+14223.14213)*1.02847/0.3212-sin(x)";
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.data[i]), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_parser;

    s = suite_create("parser");

    tc_parser = tcase_create("parser");
    tcase_add_test(tc_parser, parser_1);
    tcase_add_test(tc_parser, parser_2);
    tcase_add_test(tc_parser, parser_3);
    suite_add_tcase(s, tc_parser);

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
