#include "../header.h"

START_TEST(notation_1) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  // char *string[] = {"asin", "(", "0.206", ")", "+", "log", "(", "0.498", ")", "^", "atan", "(", "(", "0.289", "+", "0.289", ")", "^", "(", "x", "*", "0.289", ")", ")", "-", "asin", "(", "0.252", ")", "/", "actg", "(", "0.501", ")"};


  // char *string[] = {"asin", "(", "0.206", ")", "+", "log", "(", "0.498", ")", "^", "atan", "(", "(", "0.289", "+", "0.289", ")", "^", "(", "x", "*", "0.289", ")", ")", "-", "asin", "(", "0.252", ")", "/", "actg", "(", "0.501", ")"};
  char *string[] = {"0.206", "asin", "0.498", "log", "0.289", "0.289", "+", "x", "0.289", "*", "^", "atan", "^", "0.252", "asin", "-", "+"};

  char *example = {"asin(0.206)+log(0.498)^atan((0.289+0.289)^(x*0.289))-asin(0.252)/actg(0.501)"};
  if (parser(&stack, example)) {
    exit_code = notation(&stack);
  } else {
    exit_code = FAILURE;
  }
  // ck_assert_int_eq(exit_code, 0);
  // ck_assert((int)sizeof(string)/8 == stack.size);
  // if (((int)sizeof(string)/8) == stack.size) {
  //   for (int i = 0; i < stack.size; i++) {
  //     ck_assert_int_eq(strcmp(string[i], stack.data[i]), 0);
  //   }
  // }
  free_stack(&stack);
}
END_TEST


Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_notation;

    s = suite_create("notation");

    tc_notation = tcase_create("notation");
    tcase_add_test(tc_notation, notation_1);

    suite_add_tcase(s, tc_notation);
    
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
