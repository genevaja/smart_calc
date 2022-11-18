#include "../header.h"

START_TEST(parser_1) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sin", "(", "7.89", ")", "/", "4.715"};
  char *example = {"sin(7.89)/4.715"};
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
  char *string[] = {"ctg", "(", "8.58", ")", "*", "3.467"};
  char *example = {"ctg(8.58)*3.467"};
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
  char *string[] = {"ln", "(", "0.394", ")"};
  char *example = {"ln(0.394)"};
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

START_TEST(parser_4) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"log", "(", "0.812", ")"};
  char *example = {"log(0.812)"};
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

START_TEST(parser_5) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sqrt", "(", "7.521", ")"};
  char *example = {"sqrt(7.521)"};
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

START_TEST(parser_6) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"acos", "(", "8.960", ")"};
  char *example = {"acos(8.960)"};
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

START_TEST(parser_7) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"acos", "(", "5.336", ")", "+", "1.189"};
  char *example = {"acos(5.336)+1.189"};
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

START_TEST(parser_8) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"acos", "(", "4.215", ")", "^", "cos", "(", "(", "5.827", "^", "5.827", ")", "-", "(", "5.827", "*", "5.827", ")", ")"};
  char *example = {"acos(4.215)^cos((5.827^5.827)-(5.827*5.827))"};
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

START_TEST(parser_9) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"tan", "(", "6.989", ")"};
  char *example = {"tan(6.989)"};
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

START_TEST(parser_10) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"atan", "(", "7.64", ")"};
  char *example = {"atan(7.64)"};
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

START_TEST(parser_11) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"acos", "(", "0.759", ")", "*", "8.613"};
  char *example = {"acos(0.759)*8.613"};
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

START_TEST(parser_12) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sin", "(", "0.778", ")", "*", "sin", "(", "(", "8.258", "-", "8.258", ")", "-", "(", "8.258", "^", "8.258", ")", ")"};
  char *example = {"sin(0.778)*sin((8.258-8.258)-(8.258^8.258))"};
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

START_TEST(parser_13) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"954", "%", "840"};
  char *example = {"954%840"};
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

START_TEST(parser_14) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sin", "(", "0.484", ")"};
  char *example = {"sin(0.484)"};
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

START_TEST(parser_15) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"acos", "(", "7.872", ")"};
  char *example = {"acos(7.872)"};
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

START_TEST(parser_16) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"tan", "(", "4.307", ")"};
  char *example = {"tan(4.307)"};
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

START_TEST(parser_17) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"ctg", "(", "5.938", ")", "+", "4.760"};
  char *example = {"ctg(5.938)+4.760"};
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

START_TEST(parser_18) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"ln", "(", "0.988", ")"};
  char *example = {"ln(0.988)"};
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

START_TEST(parser_19) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"ctg", "(", "3.969", ")"};
  char *example = {"ctg(3.969)"};
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

START_TEST(parser_20) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"ln", "(", "6.15", ")"};
  char *example = {"ln(6.15)"};
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

START_TEST(parser_21) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"ln", "(", "6.286", ")"};
  char *example = {"ln(6.286)"};
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

START_TEST(parser_22) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sqrt", "(", "1.904", ")", "/", "tan", "(", "(", "5.944", "*", "5.944", ")", "+", "(", "4.745", "^", "5.944", ")", ")"};
  char *example = {"sqrt(1.904)/tan((5.944*5.944)+(4.745^5.944))"};
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

START_TEST(parser_23) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"cos", "(", "5.121", ")", "+", "tan", "(", "(", "0.279", "+", "0.279", ")", "^", "(", "7.472", "-", "0.279", ")", ")"};
  char *example = {"cos(5.121)+tan((0.279+0.279)^(7.472-0.279))"};
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

START_TEST(parser_24) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"ctg", "(", "3.783", ")", "*", "7.53"};
  char *example = {"ctg(3.783)*7.53"};
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

START_TEST(parser_25) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"atan", "(", "3.814", ")"};
  char *example = {"atan(3.814)"};
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

START_TEST(parser_26) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"actg", "(", "0.592", ")", "-", "asin", "(", "(", "4.768", "^", "4.768", ")", "+", "(", "4.768", "*", "4.768", ")", ")"};
  char *example = {"actg(0.592)-asin((4.768^4.768)+(4.768*4.768))"};
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

START_TEST(parser_27) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"ln", "(", "0.84", ")", "*", "3.541"};
  char *example = {"ln(0.84)*3.541"};
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

START_TEST(parser_28) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sin", "(", "9.765", ")", "+", "tan", "(", "(", "6.525", "-", "6.525", ")", "-", "(", "x", "*", "6.525", ")", ")"};
  char *example = {"sin(9.765)+tan((6.525-6.525)-(x*6.525))"};
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

START_TEST(parser_29) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"log", "(", "0.490", ")"};
  char *example = {"log(0.490)"};
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

START_TEST(parser_30) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sqrt", "(", "0.341", ")", "*", "3.998"};
  char *example = {"sqrt(0.341)*3.998"};
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

START_TEST(parser_31) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"acos", "(", "8.509", ")", "/", "sqrt", "(", "(", "8.16", "*", "8.16", ")", "*", "(", "8.16", "-", "8.16", ")", ")"};
  char *example = {"acos(8.509)/sqrt((8.16*8.16)*(8.16-8.16))"};
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

START_TEST(parser_32) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sin", "(", "6.466", ")", "-", "tan", "(", "(", "9.377", "+", "9.377", ")", "*", "(", "9.377", "/", "9.377", ")", ")"};
  char *example = {"sin(6.466)-tan((9.377+9.377)*(9.377/9.377))"};
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

START_TEST(parser_33) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"cos", "(", "9.640", ")"};
  char *example = {"cos(9.640)"};
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

START_TEST(parser_34) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"ctg", "(", "0.623", ")"};
  char *example = {"ctg(0.623)"};
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

START_TEST(parser_35) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"asin", "(", "6.400", ")"};
  char *example = {"asin(6.400)"};
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

START_TEST(parser_36) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"cos", "(", "4.84", ")", "^", "5.157"};
  char *example = {"cos(4.84)^5.157"};
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

START_TEST(parser_37) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sin", "(", "1.578", ")"};
  char *example = {"sin(1.578)"};
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

START_TEST(parser_38) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"atan", "(", "5.464", ")"};
  char *example = {"atan(5.464)"};
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

START_TEST(parser_39) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sin", "(", "9.927", ")", "+", "acos", "(", "(", "1.308", "^", "1.308", ")", "^", "(", "x", "+", "1.308", ")", ")"};
  char *example = {"sin(9.927)+acos((1.308^1.308)^(x+1.308))"};
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

START_TEST(parser_40) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"1875", "%", "322"};
  char *example = {"1875%322"};
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

START_TEST(parser_41) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sin", "(", "1.104", ")", "^", "1.285"};
  char *example = {"sin(1.104)^1.285"};
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

START_TEST(parser_42) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"actg", "(", "9.930", ")"};
  char *example = {"actg(9.930)"};
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

START_TEST(parser_43) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"ctg", "(", "5.307", ")"};
  char *example = {"ctg(5.307)"};
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

START_TEST(parser_44) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"atan", "(", "7.821", ")", "+", "2.457"};
  char *example = {"atan(7.821)+2.457"};
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

START_TEST(parser_45) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"acos", "(", "2.78", ")", "/", "cos", "(", "(", "4.604", "-", "4.604", ")", "/", "(", "4.604", "*", "4.604", ")", ")"};
  char *example = {"acos(2.78)/cos((4.604-4.604)/(4.604*4.604))"};
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

START_TEST(parser_46) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sqrt", "(", "2.223", ")"};
  char *example = {"sqrt(2.223)"};
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

START_TEST(parser_47) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"asin", "(", "3.0", ")", "-", "ln", "(", "(", "6.122", "/", "6.122", ")", "*", "(", "x", "-", "6.122", ")", ")"};
  char *example = {"asin(3.0)-ln((6.122/6.122)*(x-6.122))"};
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

START_TEST(parser_48) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sin", "(", "2.373", ")"};
  char *example = {"sin(2.373)"};
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

START_TEST(parser_49) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"atan", "(", "3.647", ")"};
  char *example = {"atan(3.647)"};
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

START_TEST(parser_50) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"log", "(", "3.954", ")", "+", "log", "(", "(", "1.146", "^", "1.146", ")", "-", "(", "x", "*", "1.146", ")", ")"};
  char *example = {"log(3.954)+log((1.146^1.146)-(x*1.146))"};
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

START_TEST(parser_51) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"cos", "(", "8.156", ")", "*", "3.530"};
  char *example = {"cos(8.156)*3.530"};
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

START_TEST(parser_52) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"acos", "(", "3.337", ")", "-", "cos", "(", "(", "3.406", "/", "3.406", ")", "/", "(", "x", "+", "3.406", ")", ")"};
  char *example = {"acos(3.337)-cos((3.406/3.406)/(x+3.406))"};
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

START_TEST(parser_53) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"asin", "(", "7.792", ")", "^", "asin", "(", "(", "7.762", "^", "7.762", ")", "^", "(", "x", "^", "7.762", ")", ")"};
  char *example = {"asin(7.792)^asin((7.762^7.762)^(x^7.762))"};
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

START_TEST(parser_54) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"log", "(", "9.457", ")", "*", "sin", "(", "(", "9.597", "^", "9.597", ")", "-", "(", "x", "*", "9.597", ")", ")"};
  char *example = {"log(9.457)*sin((9.597^9.597)-(x*9.597))"};
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

START_TEST(parser_55) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"ln", "(", "9.699", ")", "^", "log", "(", "(", "6.351", "^", "6.351", ")", "-", "(", "x", "/", "6.351", ")", ")"};
  char *example = {"ln(9.699)^log((6.351^6.351)-(x/6.351))"};
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

START_TEST(parser_56) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"tan", "(", "5.830", ")"};
  char *example = {"tan(5.830)"};
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

START_TEST(parser_57) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"atan", "(", "8.293", ")"};
  char *example = {"atan(8.293)"};
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

START_TEST(parser_58) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"actg", "(", "8.701", ")", "-", "asin", "(", "(", "8.236", "-", "8.236", ")", "-", "(", "x", "*", "8.236", ")", ")"};
  char *example = {"actg(8.701)-asin((8.236-8.236)-(x*8.236))"};
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

START_TEST(parser_59) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sin", "(", "6.869", ")"};
  char *example = {"sin(6.869)"};
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

START_TEST(parser_60) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"ctg", "(", "7.57", ")", "^", "2.565"};
  char *example = {"ctg(7.57)^2.565"};
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

START_TEST(parser_61) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"ctg", "(", "5.931", ")", "-", "asin", "(", "(", "6.553", "^", "6.553", ")", "-", "(", "6.553", "-", "6.553", ")", ")"};
  char *example = {"ctg(5.931)-asin((6.553^6.553)-(6.553-6.553))"};
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

START_TEST(parser_62) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"acos", "(", "4.939", ")", "+", "tan", "(", "(", "3.125", "+", "3.125", ")", "^", "(", "4.686", "-", "3.125", ")", ")"};
  char *example = {"acos(4.939)+tan((3.125+3.125)^(4.686-3.125))"};
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

START_TEST(parser_63) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"ln", "(", "4.937", ")"};
  char *example = {"ln(4.937)"};
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

START_TEST(parser_64) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sin", "(", "5.259", ")"};
  char *example = {"sin(5.259)"};
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

START_TEST(parser_65) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"asin", "(", "4.164", ")"};
  char *example = {"asin(4.164)"};
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

START_TEST(parser_66) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sqrt", "(", "0.405", ")", "/", "ctg", "(", "(", "5.9", "-", "5.9", ")", "*", "(", "x", "/", "5.9", ")", ")"};
  char *example = {"sqrt(0.405)/ctg((5.9-5.9)*(x/5.9))"};
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

START_TEST(parser_67) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"acos", "(", "3.620", ")"};
  char *example = {"acos(3.620)"};
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

START_TEST(parser_68) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"53", "%", "324"};
  char *example = {"53%324"};
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

START_TEST(parser_69) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sin", "(", "1.358", ")"};
  char *example = {"sin(1.358)"};
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

START_TEST(parser_70) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"tan", "(", "4.332", ")"};
  char *example = {"tan(4.332)"};
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

START_TEST(parser_71) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"atan", "(", "7.984", ")", "/", "ln", "(", "(", "5.216", "+", "5.216", ")", "-", "(", "8.35", "-", "5.216", ")", ")"};
  char *example = {"atan(7.984)/ln((5.216+5.216)-(8.35-5.216))"};
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

START_TEST(parser_72) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"atan", "(", "3.423", ")", "-", "log", "(", "(", "7.615", "*", "7.615", ")", "^", "(", "8.244", "-", "7.615", ")", ")"};
  char *example = {"atan(3.423)-log((7.615*7.615)^(8.244-7.615))"};
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

START_TEST(parser_73) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"acos", "(", "2.984", ")", "*", "acos", "(", "(", "7.853", "/", "7.853", ")", "/", "(", "7.853", "^", "7.853", ")", ")"};
  char *example = {"acos(2.984)*acos((7.853/7.853)/(7.853^7.853))"};
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

START_TEST(parser_74) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"actg", "(", "3.492", ")", "-", "7.383"};
  char *example = {"actg(3.492)-7.383"};
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

START_TEST(parser_75) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sin", "(", "6.653", ")"};
  char *example = {"sin(6.653)"};
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

START_TEST(parser_76) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"tan", "(", "8.646", ")", "*", "ctg", "(", "(", "3.106", "-", "3.106", ")", "*", "(", "3.106", "+", "3.106", ")", ")"};
  char *example = {"tan(8.646)*ctg((3.106-3.106)*(3.106+3.106))"};
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

START_TEST(parser_77) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"log", "(", "9.324", ")", "/", "9.960"};
  char *example = {"log(9.324)/9.960"};
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

START_TEST(parser_78) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"ln", "(", "6.16", ")"};
  char *example = {"ln(6.16)"};
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

START_TEST(parser_79) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"ctg", "(", "6.345", ")", "-", "9.134"};
  char *example = {"ctg(6.345)-9.134"};
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

START_TEST(parser_80) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"tan", "(", "0.286", ")", "/", "9.242"};
  char *example = {"tan(0.286)/9.242"};
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

START_TEST(parser_81) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sqrt", "(", "0.160", ")", "-", "ln", "(", "(", "0.343", "-", "0.343", ")", "/", "(", "0.343", "+", "0.343", ")", ")"};
  char *example = {"sqrt(0.160)-ln((0.343-0.343)/(0.343+0.343))"};
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

START_TEST(parser_82) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"atan", "(", "4.519", ")", "*", "acos", "(", "(", "3.753", "^", "3.753", ")", "-", "(", "3.753", "^", "3.753", ")", ")"};
  char *example = {"atan(4.519)*acos((3.753^3.753)-(3.753^3.753))"};
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

START_TEST(parser_83) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"sin", "(", "7.23", ")"};
  char *example = {"sin(7.23)"};
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

START_TEST(parser_84) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"asin", "(", "0.987", ")"};
  char *example = {"asin(0.987)"};
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

START_TEST(parser_85) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"actg", "(", "8.475", ")", "*", "5.406"};
  char *example = {"actg(8.475)*5.406"};
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

START_TEST(parser_86) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"asin", "(", "4.672", ")"};
  char *example = {"asin(4.672)"};
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

START_TEST(parser_87) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"cos", "(", "1.760", ")", "*", "ln", "(", "(", "9.320", "-", "9.320", ")", "*", "(", "9.320", "*", "9.320", ")", ")"};
  char *example = {"cos(1.760)*ln((9.320-9.320)*(9.320*9.320))"};
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

START_TEST(parser_88) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"1933", "%", "691"};
  char *example = {"1933%691"};
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

START_TEST(parser_89) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"ctg", "(", "9.687", ")", "^", "8.631"};
  char *example = {"ctg(9.687)^8.631"};
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

START_TEST(parser_90) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"tan", "(", "5.630", ")", "-", "acos", "(", "(", "0.890", "+", "0.890", ")", "*", "(", "1.695", "-", "0.890", ")", ")"};
  char *example = {"tan(5.630)-acos((0.890+0.890)*(1.695-0.890))"};
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

START_TEST(parser_91) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"asin", "(", "8.538", ")", "+", "7.532"};
  char *example = {"asin(8.538)+7.532"};
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

START_TEST(parser_92) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"log", "(", "6.479", ")", "-", "tan", "(", "(", "3.780", "+", "3.780", ")", "^", "(", "x", "+", "3.780", ")", ")"};
  char *example = {"log(6.479)-tan((3.780+3.780)^(x+3.780))"};
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

START_TEST(parser_93) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"asin", "(", "6.855", ")", "^", "sqrt", "(", "(", "7.511", "-", "7.511", ")", "/", "(", "x", "/", "7.511", ")", ")"};
  char *example = {"asin(6.855)^sqrt((7.511-7.511)/(x/7.511))"};
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

START_TEST(parser_94) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"asin", "(", "9.922", ")"};
  char *example = {"asin(9.922)"};
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

START_TEST(parser_95) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"atan", "(", "2.415", ")", "-", "4.456"};
  char *example = {"atan(2.415)-4.456"};
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

START_TEST(parser_96) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"tan", "(", "1.415", ")", "*", "8.167"};
  char *example = {"tan(1.415)*8.167"};
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

START_TEST(parser_97) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"log", "(", "3.668", ")"};
  char *example = {"log(3.668)"};
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

START_TEST(parser_98) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"actg", "(", "2.86", ")", "*", "3.714"};
  char *example = {"actg(2.86)*3.714"};
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

START_TEST(parser_99) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"cos", "(", "8.158", ")", "/", "tan", "(", "(", "1.961", "-", "1.961", ")", "+", "(", "7.74", "-", "1.961", ")", ")"};
  char *example = {"cos(8.158)/tan((1.961-1.961)+(7.74-1.961))"};
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

START_TEST(parser_100) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"ctg", "(", "6.990", ")"};
  char *example = {"ctg(6.990)"};
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
    tcase_add_test(tc_parser, parser_4);
    tcase_add_test(tc_parser, parser_5);
    tcase_add_test(tc_parser, parser_6);
    tcase_add_test(tc_parser, parser_7);
    tcase_add_test(tc_parser, parser_8);
    tcase_add_test(tc_parser, parser_9);
    tcase_add_test(tc_parser, parser_10);
    tcase_add_test(tc_parser, parser_11);
    tcase_add_test(tc_parser, parser_12);
    tcase_add_test(tc_parser, parser_13);
    tcase_add_test(tc_parser, parser_14);
    tcase_add_test(tc_parser, parser_15);
    tcase_add_test(tc_parser, parser_16);
    tcase_add_test(tc_parser, parser_17);
    tcase_add_test(tc_parser, parser_18);
    tcase_add_test(tc_parser, parser_19);
    tcase_add_test(tc_parser, parser_20);
    tcase_add_test(tc_parser, parser_21);
    tcase_add_test(tc_parser, parser_22);
    tcase_add_test(tc_parser, parser_23);
    tcase_add_test(tc_parser, parser_24);
    tcase_add_test(tc_parser, parser_25);
    tcase_add_test(tc_parser, parser_26);
    tcase_add_test(tc_parser, parser_27);
    tcase_add_test(tc_parser, parser_28);
    tcase_add_test(tc_parser, parser_29);
    tcase_add_test(tc_parser, parser_30);
    tcase_add_test(tc_parser, parser_31);
    tcase_add_test(tc_parser, parser_32);
    tcase_add_test(tc_parser, parser_33);
    tcase_add_test(tc_parser, parser_34);
    tcase_add_test(tc_parser, parser_35);
    tcase_add_test(tc_parser, parser_36);
    tcase_add_test(tc_parser, parser_37);
    tcase_add_test(tc_parser, parser_38);
    tcase_add_test(tc_parser, parser_39);
    tcase_add_test(tc_parser, parser_40);
    tcase_add_test(tc_parser, parser_41);
    tcase_add_test(tc_parser, parser_42);
    tcase_add_test(tc_parser, parser_43);
    tcase_add_test(tc_parser, parser_44);
    tcase_add_test(tc_parser, parser_45);
    tcase_add_test(tc_parser, parser_46);
    tcase_add_test(tc_parser, parser_47);
    tcase_add_test(tc_parser, parser_48);
    tcase_add_test(tc_parser, parser_49);
    tcase_add_test(tc_parser, parser_50);
    tcase_add_test(tc_parser, parser_51);
    tcase_add_test(tc_parser, parser_52);
    tcase_add_test(tc_parser, parser_53);
    tcase_add_test(tc_parser, parser_54);
    tcase_add_test(tc_parser, parser_55);
    tcase_add_test(tc_parser, parser_56);
    tcase_add_test(tc_parser, parser_57);
    tcase_add_test(tc_parser, parser_58);
    tcase_add_test(tc_parser, parser_59);
    tcase_add_test(tc_parser, parser_60);
    tcase_add_test(tc_parser, parser_61);
    tcase_add_test(tc_parser, parser_62);
    tcase_add_test(tc_parser, parser_63);
    tcase_add_test(tc_parser, parser_64);
    tcase_add_test(tc_parser, parser_65);
    tcase_add_test(tc_parser, parser_66);
    tcase_add_test(tc_parser, parser_67);
    tcase_add_test(tc_parser, parser_68);
    tcase_add_test(tc_parser, parser_69);
    tcase_add_test(tc_parser, parser_70);
    tcase_add_test(tc_parser, parser_71);
    tcase_add_test(tc_parser, parser_72);
    tcase_add_test(tc_parser, parser_73);
    tcase_add_test(tc_parser, parser_74);
    tcase_add_test(tc_parser, parser_75);
    tcase_add_test(tc_parser, parser_76);
    tcase_add_test(tc_parser, parser_77);
    tcase_add_test(tc_parser, parser_78);
    tcase_add_test(tc_parser, parser_79);
    tcase_add_test(tc_parser, parser_80);
    tcase_add_test(tc_parser, parser_81);
    tcase_add_test(tc_parser, parser_82);
    tcase_add_test(tc_parser, parser_83);
    tcase_add_test(tc_parser, parser_84);
    tcase_add_test(tc_parser, parser_85);
    tcase_add_test(tc_parser, parser_86);
    tcase_add_test(tc_parser, parser_87);
    tcase_add_test(tc_parser, parser_88);
    tcase_add_test(tc_parser, parser_89);
    tcase_add_test(tc_parser, parser_90);
    tcase_add_test(tc_parser, parser_91);
    tcase_add_test(tc_parser, parser_92);
    tcase_add_test(tc_parser, parser_93);
    tcase_add_test(tc_parser, parser_94);
    tcase_add_test(tc_parser, parser_95);
    tcase_add_test(tc_parser, parser_96);
    tcase_add_test(tc_parser, parser_97);
    tcase_add_test(tc_parser, parser_98);
    tcase_add_test(tc_parser, parser_99);
    tcase_add_test(tc_parser, parser_100);

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
