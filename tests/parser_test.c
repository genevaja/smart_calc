#include "../header.h"

START_TEST(parser_1) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.193", ")", "/", "cos", "(", "0.275", ")", "-", "actg", "(", "(", "0.97", "*", "0.97", ")", "^", "(", "0.46", "/", "0.97", ")", ")", "*", "actg", "(", "0.876", ")", "*", "sin", "(", "0.782", ")", "*", "ctg", "(", "(", "0.989", "*", "0.989", ")", "/", "(", "0.989", "^", "0.989", ")", ")", "^", "asin", "(", "0.17", ")", "/", "tan", "(", "0.453", ")", "+", "acos", "(", "(", "0.23", "/", "0.23", ")", "-", "(", "0.234", "/", "0.23", ")", ")", "*", "log", "(", "0.10", ")", "^", "actg", "(", "0.220", ")", "+", "asin", "(", "(", "0.669", "^", "0.669", ")", "-", "(", "0.669", "-", "0.669", ")", ")", "+", "ctg", "(", "0.856", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.193)/cos(0.275)-actg((0.97*0.97)^(0.46/0.97))*actg(0.876)*sin(0.782)*ctg((0.989*0.989)/(0.989^0.989))^asin(0.17)/tan(0.453)+acos((0.23/0.23)-(0.234/0.23))*log(0.10)^actg(0.220)+asin((0.669^0.669)-(0.669-0.669))+ctg(0.856)"};
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
