#include "../header.h"

START_TEST(parser_1) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"asin", "(", "0.578", ")", "*", "log", "(", "0.795", ")", "*", "asin", "(", "(", "0.919", "^", "0.919", ")", "+", "(", "0.919", "*", "0.919", ")", ")", "/", "ln", "(", "0.725", ")", "-", "sin", "(", "0.724", ")", "*", "acos", "(", "(", "0.657", "^", "0.657", ")", "+", "(", "x", "^", "0.657", ")", ")", "-", "atan", "(", "0.656", ")", "^", "ctg", "(", "0.182", ")", "/", "ln", "(", "(", "0.850", "/", "0.850", ")", "+", "(", "0.452", "^", "0.850", ")", ")", "+", "sqrt", "(", "0.214", ")", "+", "(", "-", "5", ")"};
  char *example = {"asin(0.578)*log(0.795)*asin((0.919^0.919)+(0.919*0.919))/ln(0.725)-sin(0.724)*acos((0.657^0.657)+(x^0.657))-atan(0.656)^ctg(0.182)/ln((0.850/0.850)+(0.452^0.850))+sqrt(0.214)+(-5)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  stack_output(&stack);
  free_stack(&stack);
}
END_TEST

Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_parser;

    s = suite_create("parser");

    tc_parser = tcase_create("parser");
    tcase_add_test(tc_parser, parser_1);

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
