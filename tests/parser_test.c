#include "../header.h"

START_TEST(parser_1) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.428", ")", "*", "actg", "(", "0.98", ")", "*", "sqrt", "(", "(", "0.328", "*", "0.328", ")", "/", "(", "0.328", "/", "0.328", ")", ")", "/", "ln", "(", "0.308", ")", "*", "ln", "(", "0.250", ")", "/", "acos", "(", "(", "0.736", "/", "0.736", ")", "-", "(", "x", "/", "0.736", ")", ")", "^", "tan", "(", "0.584", ")", "^", "atan", "(", "0.985", ")", "*", "acos", "(", "(", "0.22", "-", "0.22", ")", "/", "(", "x", "+", "0.22", ")", ")", "*", "sin", "(", "0.698", ")", "/", "tan", "(", "0.551", ")", "+", "actg", "(", "(", "0.21", "+", "0.21", ")", "+", "(", "0.186", "-", "0.21", ")", ")", "*", "asin", "(", "0.105", ")", "*", "ln", "(", "0.498", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.428)*actg(0.98)*sqrt((0.328*0.328)/(0.328/0.328))/ln(0.308)*ln(0.250)/acos((0.736/0.736)-(x/0.736))^tan(0.584)^atan(0.985)*acos((0.22-0.22)/(x+0.22))*sin(0.698)/tan(0.551)+actg((0.21+0.21)+(0.186-0.21))*asin(0.105)*ln(0.498)"};
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
