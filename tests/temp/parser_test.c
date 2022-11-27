#include "../header.h"

START_TEST(parser_1) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.423", ")", "-", "ln", "(", "0.197", ")", "^", "cos", "(", "(", "0.642", "+", "0.642", ")", "^", "(", "0.120", "+", "0.642", ")", ")", "-", "sqrt", "(", "0.432", ")", "*", "sin", "(", "0.800", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.423)-ln(0.197)^cos((0.642+0.642)^(0.120+0.642))-sqrt(0.432)*sin(0.800)"};
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
