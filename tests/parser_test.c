#include "../header.h"

START_TEST(parser_1) {
  int exit_code = SUCCESS;
  stack_t stack;
  init_stack(&stack);
  char *string[] = {"ln", "(", "0.409", ")", "*", "tan", "(", "0.734", ")", "-", "log", "(", "(", "0.868", "^", "0.868", ")", "-", "(", "0.868", "^", "0.868", ")", ")", "-", "actg", "(", "0.869", ")", "-", "ln", "(", "0.168", ")", "+", "tan", "(", "(", "0.570", "-", "0.570", ")", "*", "(", "0.873", "*", "0.570", ")", ")", "/", "ln", "(", "0.696", ")"};
  char *example = {"ln(0.409)*tan(0.734)-log((0.868^0.868)-(0.868^0.868))-actg(0.869)-ln(0.168)+tan((0.570-0.570)*(0.873*0.570))/ln(0.696)"};
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
  char *string[] = {"134", "%", "877"};
  char *example = {"134%877"};
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
  char *string[] = {"log", "(", "0.142", ")", "*", "sin", "(", "0.842", ")", "^", "ctg", "(", "(", "0.710", "^", "0.710", ")", "/", "(", "x", "/", "0.710", ")", ")", "-", "log", "(", "0.353", ")", "-", "atan", "(", "0.904", ")", "^", "tan", "(", "(", "0.20", "-", "0.20", ")", "*", "(", "x", "^", "0.20", ")", ")", "^", "asin", "(", "0.916", ")", "*", "sin", "(", "0.713", ")"};
  char *example = {"log(0.142)*sin(0.842)^ctg((0.710^0.710)/(x/0.710))-log(0.353)-atan(0.904)^tan((0.20-0.20)*(x^0.20))^asin(0.916)*sin(0.713)"};
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
  char *string[] = {"actg", "(", "0.759", ")", "-", "actg", "(", "0.138", ")", "*", "acos", "(", "(", "0.883", "-", "0.883", ")", "-", "(", "0.781", "/", "0.883", ")", ")", "^", "ln", "(", "0.179", ")", "^", "actg", "(", "0.452", ")", "-", "ctg", "(", "(", "0.114", "+", "0.114", ")", "^", "(", "x", "/", "0.114", ")", ")", "*", "ln", "(", "0.287", ")", "-", "ln", "(", "0.137", ")", "^", "actg", "(", "(", "0.826", "+", "0.826", ")", "+", "(", "x", "+", "0.826", ")", ")", "/", "atan", "(", "0.477", ")"};
  char *example = {"actg(0.759)-actg(0.138)*acos((0.883-0.883)-(0.781/0.883))^ln(0.179)^actg(0.452)-ctg((0.114+0.114)^(x/0.114))*ln(0.287)-ln(0.137)^actg((0.826+0.826)+(x+0.826))/atan(0.477)"};
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
  char *string[] = {"asin", "(", "0.370", ")", "^", "sqrt", "(", "0.596", ")", "^", "sin", "(", "(", "0.84", "+", "0.84", ")", "/", "(", "0.679", "*", "0.84", ")", ")", "-", "sin", "(", "0.716", ")", "/", "log", "(", "0.982", ")"};
  char *example = {"asin(0.370)^sqrt(0.596)^sin((0.84+0.84)/(0.679*0.84))-sin(0.716)/log(0.982)"};
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
  char *string[] = {"cos", "(", "0.511", ")", "/", "0.78"};
  char *example = {"cos(0.511)/0.78"};
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
  char *string[] = {"tan", "(", "0.120", ")", "+", "atan", "(", "0.830", ")", "*", "atan", "(", "(", "0.604", "+", "0.604", ")", "-", "(", "0.604", "-", "0.604", ")", ")", "+", "ln", "(", "0.404", ")", "*", "sin", "(", "0.733", ")", "*", "sin", "(", "(", "0.668", "-", "0.668", ")", "^", "(", "x", "^", "0.668", ")", ")", "+", "ln", "(", "0.365", ")", "/", "0.104"};
  char *example = {"tan(0.120)+atan(0.830)*atan((0.604+0.604)-(0.604-0.604))+ln(0.404)*sin(0.733)*sin((0.668-0.668)^(x^0.668))+ln(0.365)/0.104"};
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
  char *string[] = {"atan", "(", "0.640", ")", "+", "sqrt", "(", "0.771", ")", "+", "log", "(", "(", "0.471", "/", "0.471", ")", "-", "(", "x", "/", "0.471", ")", ")", "^", "asin", "(", "0.353", ")", "/", "atan", "(", "0.799", ")", "-", "sqrt", "(", "(", "0.128", "^", "0.128", ")", "-", "(", "0.142", "/", "0.128", ")", ")", "-", "ctg", "(", "0.640", ")"};
  char *example = {"atan(0.640)+sqrt(0.771)+log((0.471/0.471)-(x/0.471))^asin(0.353)/atan(0.799)-sqrt((0.128^0.128)-(0.142/0.128))-ctg(0.640)"};
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
  char *string[] = {"14", "%", "261"};
  char *example = {"14%261"};
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
  char *string[] = {"tan", "(", "0.259", ")", "^", "tan", "(", "0.15", ")", "*", "actg", "(", "(", "0.881", "*", "0.881", ")", "-", "(", "0.819", "^", "0.881", ")", ")", "-", "ctg", "(", "0.733", ")"};
  char *example = {"tan(0.259)^tan(0.15)*actg((0.881*0.881)-(0.819^0.881))-ctg(0.733)"};
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
  char *string[] = {"actg", "(", "0.977", ")", "-", "tan", "(", "0.949", ")", "+", "tan", "(", "(", "0.878", "-", "0.878", ")", "-", "(", "0.878", "+", "0.878", ")", ")", "+", "ln", "(", "0.741", ")", "^", "ctg", "(", "0.383", ")", "+", "acos", "(", "(", "0.901", "/", "0.901", ")", "/", "(", "x", "+", "0.901", ")", ")", "^", "asin", "(", "0.714", ")", "/", "acos", "(", "0.327", ")", "^", "ctg", "(", "(", "0.458", "+", "0.458", ")", "^", "(", "0.268", "*", "0.458", ")", ")", "-", "tan", "(", "0.722", ")", "/", "acos", "(", "0.417", ")", "^", "sin", "(", "(", "0.421", "-", "0.421", ")", "/", "(", "0.421", "-", "0.421", ")", ")", "-", "acos", "(", "0.139", ")"};
  char *example = {"actg(0.977)-tan(0.949)+tan((0.878-0.878)-(0.878+0.878))+ln(0.741)^ctg(0.383)+acos((0.901/0.901)/(x+0.901))^asin(0.714)/acos(0.327)^ctg((0.458+0.458)^(0.268*0.458))-tan(0.722)/acos(0.417)^sin((0.421-0.421)/(0.421-0.421))-acos(0.139)"};
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
  char *string[] = {"actg", "(", "0.990", ")", "-", "sqrt", "(", "0.318", ")", "^", "sin", "(", "(", "0.458", "^", "0.458", ")", "+", "(", "x", "+", "0.458", ")", ")", "/", "atan", "(", "0.366", ")", "^", "sqrt", "(", "0.494", ")", "+", "sin", "(", "(", "0.137", "-", "0.137", ")", "^", "(", "0.137", "*", "0.137", ")", ")", "-", "ln", "(", "0.432", ")", "/", "ctg", "(", "0.187", ")", "-", "sqrt", "(", "(", "0.73", "-", "0.73", ")", "*", "(", "x", "+", "0.73", ")", ")", "+", "actg", "(", "0.472", ")", "^", "log", "(", "0.458", ")", "*", "ctg", "(", "(", "0.518", "+", "0.518", ")", "+", "(", "x", "+", "0.518", ")", ")", "^", "atan", "(", "0.63", ")", "+", "acos", "(", "0.887", ")"};
  char *example = {"actg(0.990)-sqrt(0.318)^sin((0.458^0.458)+(x+0.458))/atan(0.366)^sqrt(0.494)+sin((0.137-0.137)^(0.137*0.137))-ln(0.432)/ctg(0.187)-sqrt((0.73-0.73)*(x+0.73))+actg(0.472)^log(0.458)*ctg((0.518+0.518)+(x+0.518))^atan(0.63)+acos(0.887)"};
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
  char *string[] = {"sin", "(", "0.806", ")", "+", "asin", "(", "0.998", ")", "-", "ln", "(", "(", "0.905", "^", "0.905", ")", "-", "(", "0.342", "^", "0.905", ")", ")", "*", "actg", "(", "0.88", ")", "-", "cos", "(", "0.111", ")", "^", "actg", "(", "(", "0.188", "^", "0.188", ")", "-", "(", "0.532", "^", "0.188", ")", ")", "*", "log", "(", "0.382", ")", "^", "log", "(", "0.726", ")", "/", "sqrt", "(", "(", "0.975", "/", "0.975", ")", "/", "(", "x", "^", "0.975", ")", ")", "-", "acos", "(", "0.915", ")"};
  char *example = {"sin(0.806)+asin(0.998)-ln((0.905^0.905)-(0.342^0.905))*actg(0.88)-cos(0.111)^actg((0.188^0.188)-(0.532^0.188))*log(0.382)^log(0.726)/sqrt((0.975/0.975)/(x^0.975))-acos(0.915)"};
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
  char *string[] = {"acos", "(", "0.436", ")", "/", "cos", "(", "0.253", ")", "+", "sqrt", "(", "(", "0.368", "^", "0.368", ")", "-", "(", "x", "+", "0.368", ")", ")", "+", "sqrt", "(", "0.774", ")", "^", "atan", "(", "0.709", ")", "^", "cos", "(", "(", "0.447", "/", "0.447", ")", "*", "(", "0.447", "/", "0.447", ")", ")", "-", "cos", "(", "0.919", ")", "+", "tan", "(", "0.868", ")", "+", "sqrt", "(", "(", "0.560", "*", "0.560", ")", "/", "(", "x", "*", "0.560", ")", ")", "/", "tan", "(", "0.191", ")", "-", "cos", "(", "0.28", ")", "-", "tan", "(", "(", "0.880", "-", "0.880", ")", "*", "(", "0.880", "*", "0.880", ")", ")", "+", "cos", "(", "0.193", ")", "+", "ctg", "(", "0.395", ")"};
  char *example = {"acos(0.436)/cos(0.253)+sqrt((0.368^0.368)-(x+0.368))+sqrt(0.774)^atan(0.709)^cos((0.447/0.447)*(0.447/0.447))-cos(0.919)+tan(0.868)+sqrt((0.560*0.560)/(x*0.560))/tan(0.191)-cos(0.28)-tan((0.880-0.880)*(0.880*0.880))+cos(0.193)+ctg(0.395)"};
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
  char *string[] = {"acos", "(", "0.536", ")", "+", "sin", "(", "0.642", ")", "^", "ctg", "(", "(", "0.736", "/", "0.736", ")", "+", "(", "0.736", "/", "0.736", ")", ")", "^", "tan", "(", "0.734", ")"};
  char *example = {"acos(0.536)+sin(0.642)^ctg((0.736/0.736)+(0.736/0.736))^tan(0.734)"};
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
  char *string[] = {"tan", "(", "0.393", ")", "-", "sin", "(", "0.90", ")", "^", "log", "(", "(", "0.820", "-", "0.820", ")", "*", "(", "0.820", "+", "0.820", ")", ")", "+", "atan", "(", "0.276", ")", "*", "actg", "(", "0.424", ")", "/", "sin", "(", "(", "0.714", "*", "0.714", ")", "-", "(", "0.306", "*", "0.714", ")", ")", "+", "sin", "(", "0.362", ")", "-", "tan", "(", "0.70", ")", "-", "ln", "(", "(", "0.114", "/", "0.114", ")", "-", "(", "0.114", "+", "0.114", ")", ")", "*", "asin", "(", "0.258", ")"};
  char *example = {"tan(0.393)-sin(0.90)^log((0.820-0.820)*(0.820+0.820))+atan(0.276)*actg(0.424)/sin((0.714*0.714)-(0.306*0.714))+sin(0.362)-tan(0.70)-ln((0.114/0.114)-(0.114+0.114))*asin(0.258)"};
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
  char *string[] = {"ln", "(", "0.593", ")", "/", "actg", "(", "0.928", ")", "-", "tan", "(", "(", "0.911", "/", "0.911", ")", "+", "(", "0.732", "^", "0.911", ")", ")", "^", "cos", "(", "0.445", ")", "*", "ctg", "(", "0.904", ")", "+", "acos", "(", "(", "0.832", "^", "0.832", ")", "^", "(", "0.935", "/", "0.832", ")", ")", "+"};
  char *example = {"ln(0.593)/actg(0.928)-tan((0.911/0.911)+(0.732^0.911))^cos(0.445)*ctg(0.904)+acos((0.832^0.832)^(0.935/0.832))+"};
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
  char *string[] = {"atan", "(", "0.205", ")", "/", "sin", "(", "0.782", ")", "/", "asin", "(", "(", "0.364", "+", "0.364", ")", "^", "(", "x", "*", "0.364", ")", ")", "+", "acos", "(", "0.505", ")", "+", "ctg", "(", "0.74", ")", "/", "sin", "(", "(", "0.467", "/", "0.467", ")", "/", "(", "x", "+", "0.467", ")", ")", "+", "sqrt", "(", "0.806", ")", "*", "tan", "(", "0.792", ")", "*", "actg", "(", "(", "0.475", "^", "0.475", ")", "-", "(", "x", "+", "0.475", ")", ")", "^", "actg", "(", "0.693", ")", "^", "log", "(", "0.744", ")"};
  char *example = {"atan(0.205)/sin(0.782)/asin((0.364+0.364)^(x*0.364))+acos(0.505)+ctg(0.74)/sin((0.467/0.467)/(x+0.467))+sqrt(0.806)*tan(0.792)*actg((0.475^0.475)-(x+0.475))^actg(0.693)^log(0.744)"};
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
  char *string[] = {"asin", "(", "0.447", ")", "/", "ctg", "(", "0.662", ")", "+", "sqrt", "(", "(", "0.666", "+", "0.666", ")", "-", "(", "x", "/", "0.666", ")", ")", "/", "atan", "(", "0.388", ")", "*", "acos", "(", "0.229", ")"};
  char *example = {"asin(0.447)/ctg(0.662)+sqrt((0.666+0.666)-(x/0.666))/atan(0.388)*acos(0.229)"};
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
  char *string[] = {"sqrt", "(", "0.371", ")", "^", "cos", "(", "0.69", ")", "-", "actg", "(", "(", "0.744", "-", "0.744", ")", "^", "(", "0.682", "+", "0.744", ")", ")", "^", "tan", "(", "0.400", ")", "*", "tan", "(", "0.996", ")", "^", "asin", "(", "(", "0.27", "+", "0.27", ")", "-", "(", "0.27", "^", "0.27", ")", ")", "-", "tan", "(", "0.656", ")", "/", "cos", "(", "0.109", ")", "/", "actg", "(", "(", "0.933", "-", "0.933", ")", "/", "(", "0.933", "/", "0.933", ")", ")", "/", "sin", "(", "0.990", ")", "/", "asin", "(", "0.812", ")"};
  char *example = {"sqrt(0.371)^cos(0.69)-actg((0.744-0.744)^(0.682+0.744))^tan(0.400)*tan(0.996)^asin((0.27+0.27)-(0.27^0.27))-tan(0.656)/cos(0.109)/actg((0.933-0.933)/(0.933/0.933))/sin(0.990)/asin(0.812)"};
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
  char *string[] = {"acos", "(", "0.25", ")", "/", "log", "(", "0.745", ")", "+", "ctg", "(", "(", "0.677", "*", "0.677", ")", "*", "(", "0.243", "+", "0.677", ")", ")", "-"};
  char *example = {"acos(0.25)/log(0.745)+ctg((0.677*0.677)*(0.243+0.677))-"};
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
  char *string[] = {"tan", "(", "0.764", ")", "^", "atan", "(", "0.687", ")", "^", "sin", "(", "(", "0.562", "+", "0.562", ")", "-", "(", "0.99", "/", "0.562", ")", ")", "-", "log", "(", "0.88", ")", "-", "atan", "(", "0.838", ")", "+", "sqrt", "(", "(", "0.794", "^", "0.794", ")", "^", "(", "0.249", "*", "0.794", ")", ")", "-", "ln", "(", "0.72", ")", "*", "0.858"};
  char *example = {"tan(0.764)^atan(0.687)^sin((0.562+0.562)-(0.99/0.562))-log(0.88)-atan(0.838)+sqrt((0.794^0.794)^(0.249*0.794))-ln(0.72)*0.858"};
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
  char *string[] = {"actg", "(", "0.124", ")", "/", "actg", "(", "0.81", ")", "/", "cos", "(", "(", "0.726", "-", "0.726", ")", "*", "(", "0.769", "^", "0.726", ")", ")", "+", "tan", "(", "0.55", ")", "-", "sqrt", "(", "0.607", ")", "-", "actg", "(", "(", "0.282", "-", "0.282", ")", "*", "(", "x", "+", "0.282", ")", ")", "*", "log", "(", "0.916", ")", "*", "log", "(", "0.186", ")", "/", "asin", "(", "(", "0.741", "+", "0.741", ")", "/", "(", "0.450", "*", "0.741", ")", ")", "^", "actg", "(", "0.213", ")"};
  char *example = {"actg(0.124)/actg(0.81)/cos((0.726-0.726)*(0.769^0.726))+tan(0.55)-sqrt(0.607)-actg((0.282-0.282)*(x+0.282))*log(0.916)*log(0.186)/asin((0.741+0.741)/(0.450*0.741))^actg(0.213)"};
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
  char *string[] = {"cos", "(", "0.407", ")", "+", "tan", "(", "0.885", ")", "*", "sqrt", "(", "(", "0.203", "-", "0.203", ")", "+", "(", "0.260", "/", "0.203", ")", ")", "/", "ctg", "(", "0.452", ")", "/", "0.314"};
  char *example = {"cos(0.407)+tan(0.885)*sqrt((0.203-0.203)+(0.260/0.203))/ctg(0.452)/0.314"};
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
  char *string[] = {"actg", "(", "0.169", ")", "*", "cos", "(", "0.790", ")", "-", "sqrt", "(", "(", "0.656", "-", "0.656", ")", "-", "(", "x", "^", "0.656", ")", ")", "^", "asin", "(", "0.804", ")", "/", "sqrt", "(", "0.208", ")", "*", "ln", "(", "(", "0.902", "^", "0.902", ")", "^", "(", "x", "*", "0.902", ")", ")", "/", "sqrt", "(", "0.714", ")", "/", "asin", "(", "0.358", ")", "/", "tan", "(", "(", "0.464", "*", "0.464", ")", "*", "(", "0.4", "-", "0.464", ")", ")", "+", "acos", "(", "0.267", ")", "+", "ctg", "(", "0.916", ")"};
  char *example = {"actg(0.169)*cos(0.790)-sqrt((0.656-0.656)-(x^0.656))^asin(0.804)/sqrt(0.208)*ln((0.902^0.902)^(x*0.902))/sqrt(0.714)/asin(0.358)/tan((0.464*0.464)*(0.4-0.464))+acos(0.267)+ctg(0.916)"};
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
  char *string[] = {"ctg", "(", "0.385", ")"};
  char *example = {"ctg(0.385)"};
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
  char *string[] = {"acos", "(", "0.52", ")", "/", "atan", "(", "0.367", ")", "/", "sqrt", "(", "(", "0.877", "^", "0.877", ")", "*", "(", "0.664", "^", "0.877", ")", ")", "^", "sqrt", "(", "0.643", ")", "*", "log", "(", "0.666", ")", "^", "actg", "(", "(", "0.90", "-", "0.90", ")", "*", "(", "x", "*", "0.90", ")", ")", "+", "atan", "(", "0.749", ")", "-", "ctg", "(", "0.976", ")", "^", "actg", "(", "(", "0.106", "*", "0.106", ")", "-", "(", "x", "-", "0.106", ")", ")", "*", "asin", "(", "0.403", ")", "*", "ln", "(", "0.689", ")", "^", "acos", "(", "(", "0.38", "+", "0.38", ")", "^", "(", "x", "+", "0.38", ")", ")", "^", "tan", "(", "0.480", ")", "-", "0.605"};
  char *example = {"acos(0.52)/atan(0.367)/sqrt((0.877^0.877)*(0.664^0.877))^sqrt(0.643)*log(0.666)^actg((0.90-0.90)*(x*0.90))+atan(0.749)-ctg(0.976)^actg((0.106*0.106)-(x-0.106))*asin(0.403)*ln(0.689)^acos((0.38+0.38)^(x+0.38))^tan(0.480)-0.605"};
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
  char *string[] = {"sin", "(", "0.287", ")", "^", "asin", "(", "0.340", ")", "-", "asin", "(", "(", "0.993", "-", "0.993", ")", "*", "(", "x", "^", "0.993", ")", ")", "*", "ctg", "(", "0.938", ")", "^", "acos", "(", "0.163", ")", "*", "tan", "(", "(", "0.538", "-", "0.538", ")", "-", "(", "0.538", "*", "0.538", ")", ")", "+", "atan", "(", "0.67", ")", "-", "ctg", "(", "0.197", ")", "+", "ln", "(", "(", "0.487", "-", "0.487", ")", "-", "(", "0.487", "-", "0.487", ")", ")", "*", "ln", "(", "0.590", ")", "*", "0.692"};
  char *example = {"sin(0.287)^asin(0.340)-asin((0.993-0.993)*(x^0.993))*ctg(0.938)^acos(0.163)*tan((0.538-0.538)-(0.538*0.538))+atan(0.67)-ctg(0.197)+ln((0.487-0.487)-(0.487-0.487))*ln(0.590)*0.692"};
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
  char *string[] = {"968", "%", "9"};
  char *example = {"968%9"};
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
  char *string[] = {"sqrt", "(", "0.329", ")", "+", "tan", "(", "0.114", ")", "-", "ln", "(", "(", "0.504", "+", "0.504", ")", "-", "(", "0.940", "/", "0.504", ")", ")", "*", "sqrt", "(", "0.831", ")", "-", "sin", "(", "0.520", ")", "-", "cos", "(", "(", "0.508", "/", "0.508", ")", "*", "(", "0.508", "/", "0.508", ")", ")", "^", "sin", "(", "0.818", ")", "*", "atan", "(", "0.560", ")", "/", "asin", "(", "(", "0.760", "^", "0.760", ")", "+", "(", "0.760", "+", "0.760", ")", ")", "/"};
  char *example = {"sqrt(0.329)+tan(0.114)-ln((0.504+0.504)-(0.940/0.504))*sqrt(0.831)-sin(0.520)-cos((0.508/0.508)*(0.508/0.508))^sin(0.818)*atan(0.560)/asin((0.760^0.760)+(0.760+0.760))/"};
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
  char *string[] = {"ctg", "(", "0.701", ")", "/", "cos", "(", "0.473", ")", "^", "ctg", "(", "(", "0.703", "/", "0.703", ")", "-", "(", "x", "+", "0.703", ")", ")", "/", "tan", "(", "0.56", ")"};
  char *example = {"ctg(0.701)/cos(0.473)^ctg((0.703/0.703)-(x+0.703))/tan(0.56)"};
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
  char *string[] = {"ln", "(", "0.404", ")", "*", "tan", "(", "0.91", ")", "-", "ln", "(", "(", "0.83", "-", "0.83", ")", "+", "(", "x", "/", "0.83", ")", ")", "^", "ln", "(", "0.318", ")", "*", "ctg", "(", "0.42", ")", "+", "acos", "(", "(", "0.52", "/", "0.52", ")", "/", "(", "0.234", "+", "0.52", ")", ")", "/", "ctg", "(", "0.497", ")", "+", "cos", "(", "0.18", ")", "/", "atan", "(", "(", "0.23", "*", "0.23", ")", "*", "(", "0.23", "*", "0.23", ")", ")", "*", "asin", "(", "0.828", ")", "-", "sin", "(", "0.718", ")", "^", "cos", "(", "(", "0.435", "/", "0.435", ")", "+", "(", "x", "-", "0.435", ")", ")", "^", "cos", "(", "0.756", ")"};
  char *example = {"ln(0.404)*tan(0.91)-ln((0.83-0.83)+(x/0.83))^ln(0.318)*ctg(0.42)+acos((0.52/0.52)/(0.234+0.52))/ctg(0.497)+cos(0.18)/atan((0.23*0.23)*(0.23*0.23))*asin(0.828)-sin(0.718)^cos((0.435/0.435)+(x-0.435))^cos(0.756)"};
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
  char *string[] = {"sin", "(", "0.28", ")", "+", "ln", "(", "0.352", ")", "-", "sqrt", "(", "(", "0.982", "+", "0.982", ")", "/", "(", "x", "+", "0.982", ")", ")", "+", "log", "(", "0.68", ")", "*", "sin", "(", "0.631", ")", "+", "tan", "(", "(", "0.256", "+", "0.256", ")", "^", "(", "0.256", "*", "0.256", ")", ")", "-", "actg", "(", "0.72", ")", "+", "sin", "(", "0.416", ")", "^", "sqrt", "(", "(", "0.914", "-", "0.914", ")", "+", "(", "0.361", "*", "0.914", ")", ")", "/", "actg", "(", "0.966", ")", "*", "ctg", "(", "0.887", ")"};
  char *example = {"sin(0.28)+ln(0.352)-sqrt((0.982+0.982)/(x+0.982))+log(0.68)*sin(0.631)+tan((0.256+0.256)^(0.256*0.256))-actg(0.72)+sin(0.416)^sqrt((0.914-0.914)+(0.361*0.914))/actg(0.966)*ctg(0.887)"};
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
  char *string[] = {"acos", "(", "0.185", ")", "/", "sin", "(", "0.816", ")", "*", "actg", "(", "(", "0.938", "+", "0.938", ")", "-", "(", "0.157", "+", "0.938", ")", ")", "^", "sin", "(", "0.597", ")"};
  char *example = {"acos(0.185)/sin(0.816)*actg((0.938+0.938)-(0.157+0.938))^sin(0.597)"};
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
  char *string[] = {"log", "(", "0.657", ")", "*", "sqrt", "(", "0.107", ")", "-", "cos", "(", "(", "0.745", "^", "0.745", ")", "+", "(", "0.748", "/", "0.745", ")", ")", "^", "sqrt", "(", "0.885", ")", "-", "asin", "(", "0.955", ")", "+", "actg", "(", "(", "0.63", "^", "0.63", ")", "-", "(", "0.63", "*", "0.63", ")", ")", "/", "cos", "(", "0.529", ")", "/", "0.684"};
  char *example = {"log(0.657)*sqrt(0.107)-cos((0.745^0.745)+(0.748/0.745))^sqrt(0.885)-asin(0.955)+actg((0.63^0.63)-(0.63*0.63))/cos(0.529)/0.684"};
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
  char *string[] = {"ln", "(", "0.851", ")", "^", "acos", "(", "0.71", ")", "*", "cos", "(", "(", "0.466", "-", "0.466", ")", "/", "(", "0.466", "/", "0.466", ")", ")", "+", "sqrt", "(", "0.623", ")", "+", "atan", "(", "0.834", ")", "^", "ln", "(", "(", "0.469", "^", "0.469", ")", "-", "(", "0.469", "/", "0.469", ")", ")", "*", "tan", "(", "0.833", ")", "-", "log", "(", "0.494", ")", "-", "tan", "(", "(", "0.146", "+", "0.146", ")", "^", "(", "x", "*", "0.146", ")", ")", "+", "ln", "(", "0.66", ")", "*", "actg", "(", "0.118", ")", "+", "ln", "(", "(", "0.154", "/", "0.154", ")", "+", "(", "0.678", "^", "0.154", ")", ")", "+", "cos", "(", "0.710", ")", "*", "atan", "(", "0.792", ")"};
  char *example = {"ln(0.851)^acos(0.71)*cos((0.466-0.466)/(0.466/0.466))+sqrt(0.623)+atan(0.834)^ln((0.469^0.469)-(0.469/0.469))*tan(0.833)-log(0.494)-tan((0.146+0.146)^(x*0.146))+ln(0.66)*actg(0.118)+ln((0.154/0.154)+(0.678^0.154))+cos(0.710)*atan(0.792)"};
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
  char *string[] = {"atan", "(", "0.524", ")", "*", "sin", "(", "0.215", ")", "^", "tan", "(", "(", "0.493", "*", "0.493", ")", "*", "(", "0.493", "*", "0.493", ")", ")", "*", "asin", "(", "0.178", ")", "*", "sqrt", "(", "0.17", ")", "+", "sin", "(", "(", "0.899", "*", "0.899", ")", "/", "(", "x", "-", "0.899", ")", ")", "+", "log", "(", "0.82", ")", "*", "tan", "(", "0.790", ")", "-", "log", "(", "(", "0.217", "-", "0.217", ")", "+", "(", "0.217", "-", "0.217", ")", ")", "^", "ctg", "(", "0.770", ")", "+", "sin", "(", "0.740", ")", "+", "actg", "(", "(", "0.426", "^", "0.426", ")", "+", "(", "0.426", "+", "0.426", ")", ")", "-", "cos", "(", "0.189", ")", "+", "asin", "(", "0.439", ")", "+", "cos", "(", "(", "0.935", "+", "0.935", ")", "*", "(", "x", "*", "0.935", ")", ")", "+"};
  char *example = {"atan(0.524)*sin(0.215)^tan((0.493*0.493)*(0.493*0.493))*asin(0.178)*sqrt(0.17)+sin((0.899*0.899)/(x-0.899))+log(0.82)*tan(0.790)-log((0.217-0.217)+(0.217-0.217))^ctg(0.770)+sin(0.740)+actg((0.426^0.426)+(0.426+0.426))-cos(0.189)+asin(0.439)+cos((0.935+0.935)*(x*0.935))+"};
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
  char *string[] = {"cos", "(", "0.319", ")", "+", "ctg", "(", "0.249", ")", "-", "log", "(", "(", "0.239", "-", "0.239", ")", "+", "(", "0.988", "^", "0.239", ")", ")", "^", "sqrt", "(", "0.452", ")", "^", "log", "(", "0.505", ")", "^", "tan", "(", "(", "0.167", "^", "0.167", ")", "-", "(", "0.167", "/", "0.167", ")", ")", "-", "ctg", "(", "0.880", ")", "-", "sqrt", "(", "0.667", ")", "^", "atan", "(", "(", "0.188", "-", "0.188", ")", "+", "(", "0.188", "-", "0.188", ")", ")", "-"};
  char *example = {"cos(0.319)+ctg(0.249)-log((0.239-0.239)+(0.988^0.239))^sqrt(0.452)^log(0.505)^tan((0.167^0.167)-(0.167/0.167))-ctg(0.880)-sqrt(0.667)^atan((0.188-0.188)+(0.188-0.188))-"};
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
  char *string[] = {"ln", "(", "0.584", ")", "*", "sqrt", "(", "0.891", ")", "^", "acos", "(", "(", "0.88", "^", "0.88", ")", "-", "(", "0.823", "/", "0.88", ")", ")", "*", "actg", "(", "0.60", ")", "/", "cos", "(", "0.65", ")", "^", "actg", "(", "(", "0.918", "/", "0.918", ")", "/", "(", "0.918", "^", "0.918", ")", ")", "^", "asin", "(", "0.304", ")", "-", "sqrt", "(", "0.896", ")"};
  char *example = {"ln(0.584)*sqrt(0.891)^acos((0.88^0.88)-(0.823/0.88))*actg(0.60)/cos(0.65)^actg((0.918/0.918)/(0.918^0.918))^asin(0.304)-sqrt(0.896)"};
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
  char *string[] = {"sin", "(", "0.32", ")", "*", "asin", "(", "0.426", ")", "*", "ln", "(", "(", "0.410", "^", "0.410", ")", "+", "(", "x", "^", "0.410", ")", ")", "^", "actg", "(", "0.772", ")", "^", "sqrt", "(", "0.442", ")", "*", "log", "(", "(", "0.736", "^", "0.736", ")", "/", "(", "x", "+", "0.736", ")", ")", "+", "sqrt", "(", "0.784", ")", "-", "0.242"};
  char *example = {"sin(0.32)*asin(0.426)*ln((0.410^0.410)+(x^0.410))^actg(0.772)^sqrt(0.442)*log((0.736^0.736)/(x+0.736))+sqrt(0.784)-0.242"};
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
  char *string[] = {"log", "(", "0.378", ")", "^", "actg", "(", "0.784", ")", "-", "ln", "(", "(", "0.880", "*", "0.880", ")", "^", "(", "0.433", "^", "0.880", ")", ")", "+", "sqrt", "(", "0.472", ")", "/", "sin", "(", "0.185", ")", "^", "acos", "(", "(", "0.842", "*", "0.842", ")", "^", "(", "0.733", "+", "0.842", ")", ")", "/", "asin", "(", "0.469", ")", "*", "ln", "(", "0.490", ")", "*", "atan", "(", "(", "0.876", "/", "0.876", ")", "+", "(", "x", "^", "0.876", ")", ")", "+", "asin", "(", "0.637", ")", "^", "sqrt", "(", "0.605", ")", "^", "log", "(", "(", "0.153", "^", "0.153", ")", "^", "(", "x", "*", "0.153", ")", ")", "+", "atan", "(", "0.328", ")", "+", "cos", "(", "0.474", ")"};
  char *example = {"log(0.378)^actg(0.784)-ln((0.880*0.880)^(0.433^0.880))+sqrt(0.472)/sin(0.185)^acos((0.842*0.842)^(0.733+0.842))/asin(0.469)*ln(0.490)*atan((0.876/0.876)+(x^0.876))+asin(0.637)^sqrt(0.605)^log((0.153^0.153)^(x*0.153))+atan(0.328)+cos(0.474)"};
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
  char *string[] = {"tan", "(", "0.865", ")", "*", "actg", "(", "0.980", ")", "-", "ctg", "(", "(", "0.988", "/", "0.988", ")", "+", "(", "0.988", "+", "0.988", ")", ")", "/"};
  char *example = {"tan(0.865)*actg(0.980)-ctg((0.988/0.988)+(0.988+0.988))/"};
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
  char *string[] = {"log", "(", "0.761", ")", "/", "ctg", "(", "0.748", ")", "/", "atan", "(", "(", "0.342", "+", "0.342", ")", "*", "(", "x", "/", "0.342", ")", ")", "*", "log", "(", "0.602", ")", "+", "ctg", "(", "0.196", ")", "^", "ctg", "(", "(", "0.505", "-", "0.505", ")", "-", "(", "0.542", "+", "0.505", ")", ")", "*", "log", "(", "0.922", ")"};
  char *example = {"log(0.761)/ctg(0.748)/atan((0.342+0.342)*(x/0.342))*log(0.602)+ctg(0.196)^ctg((0.505-0.505)-(0.542+0.505))*log(0.922)"};
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
  char *string[] = {"ctg", "(", "0.519", ")", "^", "tan", "(", "0.385", ")", "/", "ctg", "(", "(", "0.722", "+", "0.722", ")", "/", "(", "0.722", "/", "0.722", ")", ")", "^", "sin", "(", "0.321", ")", "^", "sqrt", "(", "0.836", ")", "/", "atan", "(", "(", "0.520", "*", "0.520", ")", "-", "(", "0.383", "/", "0.520", ")", ")", "+", "actg", "(", "0.390", ")"};
  char *example = {"ctg(0.519)^tan(0.385)/ctg((0.722+0.722)/(0.722/0.722))^sin(0.321)^sqrt(0.836)/atan((0.520*0.520)-(0.383/0.520))+actg(0.390)"};
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
  char *string[] = {"cos", "(", "0.155", ")", "/", "asin", "(", "0.709", ")", "*", "actg", "(", "(", "0.129", "+", "0.129", ")", "/", "(", "0.129", "^", "0.129", ")", ")", "-", "atan", "(", "0.306", ")", "/", "atan", "(", "0.115", ")", "+", "asin", "(", "(", "0.209", "+", "0.209", ")", "^", "(", "0.209", "-", "0.209", ")", ")", "/", "actg", "(", "0.44", ")", "^", "asin", "(", "0.20", ")", "*", "ctg", "(", "(", "0.797", "-", "0.797", ")", "+", "(", "0.504", "*", "0.797", ")", ")", "/", "ln", "(", "0.656", ")", "*", "tan", "(", "0.666", ")"};
  char *example = {"cos(0.155)/asin(0.709)*actg((0.129+0.129)/(0.129^0.129))-atan(0.306)/atan(0.115)+asin((0.209+0.209)^(0.209-0.209))/actg(0.44)^asin(0.20)*ctg((0.797-0.797)+(0.504*0.797))/ln(0.656)*tan(0.666)"};
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
  char *string[] = {"actg", "(", "0.805", ")", "/", "tan", "(", "0.144", ")", "/", "acos", "(", "(", "0.941", "*", "0.941", ")", "^", "(", "0.941", "+", "0.941", ")", ")", "^", "cos", "(", "0.659", ")", "^", "acos", "(", "0.883", ")", "+", "sqrt", "(", "(", "0.600", "/", "0.600", ")", "-", "(", "x", "+", "0.600", ")", ")", "-", "asin", "(", "0.137", ")", "/", "log", "(", "0.245", ")", "*", "tan", "(", "(", "0.259", "^", "0.259", ")", "^", "(", "0.259", "^", "0.259", ")", ")", "^", "sin", "(", "0.110", ")", "-", "sin", "(", "0.238", ")", "^", "actg", "(", "(", "0.944", "/", "0.944", ")", "*", "(", "0.944", "+", "0.944", ")", ")", "-", "log", "(", "0.473", ")"};
  char *example = {"actg(0.805)/tan(0.144)/acos((0.941*0.941)^(0.941+0.941))^cos(0.659)^acos(0.883)+sqrt((0.600/0.600)-(x+0.600))-asin(0.137)/log(0.245)*tan((0.259^0.259)^(0.259^0.259))^sin(0.110)-sin(0.238)^actg((0.944/0.944)*(0.944+0.944))-log(0.473)"};
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
  char *string[] = {"atan", "(", "0.989", ")"};
  char *example = {"atan(0.989)"};
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
  char *string[] = {"asin", "(", "0.409", ")", "^", "tan", "(", "0.292", ")", "^", "ln", "(", "(", "0.458", "^", "0.458", ")", "/", "(", "x", "-", "0.458", ")", ")", "^", "acos", "(", "0.240", ")", "*", "log", "(", "0.944", ")", "*", "atan", "(", "(", "0.803", "+", "0.803", ")", "/", "(", "0.803", "/", "0.803", ")", ")", "/", "sqrt", "(", "0.717", ")", "+", "actg", "(", "0.469", ")", "/", "sin", "(", "(", "0.962", "*", "0.962", ")", "/", "(", "0.262", "-", "0.962", ")", ")", "^", "log", "(", "0.864", ")", "*", "ctg", "(", "0.794", ")", "/", "ctg", "(", "(", "0.908", "-", "0.908", ")", "^", "(", "0.36", "*", "0.908", ")", ")", "-", "actg", "(", "0.629", ")", "+", "0.600"};
  char *example = {"asin(0.409)^tan(0.292)^ln((0.458^0.458)/(x-0.458))^acos(0.240)*log(0.944)*atan((0.803+0.803)/(0.803/0.803))/sqrt(0.717)+actg(0.469)/sin((0.962*0.962)/(0.262-0.962))^log(0.864)*ctg(0.794)/ctg((0.908-0.908)^(0.36*0.908))-actg(0.629)+0.600"};
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
  char *string[] = {"atan", "(", "0.873", ")", "*", "ctg", "(", "0.995", ")", "+", "log", "(", "(", "0.398", "+", "0.398", ")", "^", "(", "0.907", "-", "0.398", ")", ")", "*", "ctg", "(", "0.224", ")", "/", "ln", "(", "0.815", ")", "/", "asin", "(", "(", "0.413", "-", "0.413", ")", "-", "(", "x", "^", "0.413", ")", ")", "^", "ln", "(", "0.613", ")", "-", "actg", "(", "0.918", ")", "-", "asin", "(", "(", "0.399", "+", "0.399", ")", "^", "(", "0.399", "^", "0.399", ")", ")", "+", "cos", "(", "0.883", ")", "+", "0.219"};
  char *example = {"atan(0.873)*ctg(0.995)+log((0.398+0.398)^(0.907-0.398))*ctg(0.224)/ln(0.815)/asin((0.413-0.413)-(x^0.413))^ln(0.613)-actg(0.918)-asin((0.399+0.399)^(0.399^0.399))+cos(0.883)+0.219"};
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
  char *string[] = {"tan", "(", "0.335", ")", "-", "atan", "(", "0.760", ")", "^", "actg", "(", "(", "0.705", "/", "0.705", ")", "-", "(", "0.640", "^", "0.705", ")", ")", "-", "sqrt", "(", "0.466", ")", "*", "acos", "(", "0.883", ")", "-", "log", "(", "(", "0.341", "-", "0.341", ")", "^", "(", "0.341", "+", "0.341", ")", ")", "^", "ln", "(", "0.199", ")", "-", "ctg", "(", "0.912", ")", "/", "log", "(", "(", "0.404", "+", "0.404", ")", "/", "(", "x", "-", "0.404", ")", ")", "-", "acos", "(", "0.704", ")", "/", "sqrt", "(", "0.56", ")", "/", "atan", "(", "(", "0.370", "*", "0.370", ")", "^", "(", "x", "/", "0.370", ")", ")", "*"};
  char *example = {"tan(0.335)-atan(0.760)^actg((0.705/0.705)-(0.640^0.705))-sqrt(0.466)*acos(0.883)-log((0.341-0.341)^(0.341+0.341))^ln(0.199)-ctg(0.912)/log((0.404+0.404)/(x-0.404))-acos(0.704)/sqrt(0.56)/atan((0.370*0.370)^(x/0.370))*"};
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
  char *string[] = {"sin", "(", "0.862", ")", "*", "actg", "(", "0.159", ")", "/", "asin", "(", "(", "0.114", "-", "0.114", ")", "+", "(", "0.114", "*", "0.114", ")", ")", "/", "sqrt", "(", "0.580", ")", "+", "actg", "(", "0.876", ")"};
  char *example = {"sin(0.862)*actg(0.159)/asin((0.114-0.114)+(0.114*0.114))/sqrt(0.580)+actg(0.876)"};
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
  char *string[] = {"ln", "(", "0.157", ")", "+", "ln", "(", "0.189", ")", "+", "log", "(", "(", "0.471", "/", "0.471", ")", "^", "(", "0.476", "/", "0.471", ")", ")", "*", "cos", "(", "0.847", ")", "-", "atan", "(", "0.37", ")"};
  char *example = {"ln(0.157)+ln(0.189)+log((0.471/0.471)^(0.476/0.471))*cos(0.847)-atan(0.37)"};
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
  char *string[] = {"cos", "(", "0.842", ")", "^", "cos", "(", "0.42", ")", "+", "sqrt", "(", "(", "0.470", "/", "0.470", ")", "+", "(", "x", "-", "0.470", ")", ")", "*", "log", "(", "0.274", ")", "/", "sqrt", "(", "0.882", ")", "/", "log", "(", "(", "0.762", "-", "0.762", ")", "-", "(", "0.762", "*", "0.762", ")", ")", "^", "actg", "(", "0.31", ")", "+", "actg", "(", "0.286", ")", "+", "acos", "(", "(", "0.127", "-", "0.127", ")", "-", "(", "0.127", "^", "0.127", ")", ")", "+", "cos", "(", "0.850", ")", "^", "asin", "(", "0.424", ")", "-", "tan", "(", "(", "0.467", "-", "0.467", ")", "/", "(", "0.47", "*", "0.467", ")", ")", "-", "cos", "(", "0.438", ")", "+", "acos", "(", "0.522", ")", "-", "atan", "(", "(", "0.758", "^", "0.758", ")", "*", "(", "0.758", "/", "0.758", ")", ")", "/"};
  char *example = {"cos(0.842)^cos(0.42)+sqrt((0.470/0.470)+(x-0.470))*log(0.274)/sqrt(0.882)/log((0.762-0.762)-(0.762*0.762))^actg(0.31)+actg(0.286)+acos((0.127-0.127)-(0.127^0.127))+cos(0.850)^asin(0.424)-tan((0.467-0.467)/(0.47*0.467))-cos(0.438)+acos(0.522)-atan((0.758^0.758)*(0.758/0.758))/"};
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
  char *string[] = {"actg", "(", "0.358", ")", "^", "sqrt", "(", "0.723", ")", "^", "ctg", "(", "(", "0.246", "^", "0.246", ")", "/", "(", "x", "*", "0.246", ")", ")", "+", "actg", "(", "0.903", ")", "/", "log", "(", "0.858", ")", "/", "cos", "(", "(", "0.475", "+", "0.475", ")", "^", "(", "x", "+", "0.475", ")", ")", "/", "ln", "(", "0.584", ")", "*", "acos", "(", "0.946", ")", "*", "sin", "(", "(", "0.27", "^", "0.27", ")", "-", "(", "x", "-", "0.27", ")", ")", "^"};
  char *example = {"actg(0.358)^sqrt(0.723)^ctg((0.246^0.246)/(x*0.246))+actg(0.903)/log(0.858)/cos((0.475+0.475)^(x+0.475))/ln(0.584)*acos(0.946)*sin((0.27^0.27)-(x-0.27))^"};
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
  char *string[] = {"tan", "(", "0.446", ")"};
  char *example = {"tan(0.446)"};
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
  char *string[] = {"ln", "(", "0.706", ")", "+", "ctg", "(", "0.423", ")", "+", "tan", "(", "(", "0.31", "/", "0.31", ")", "-", "(", "x", "/", "0.31", ")", ")", "*", "atan", "(", "0.804", ")"};
  char *example = {"ln(0.706)+ctg(0.423)+tan((0.31/0.31)-(x/0.31))*atan(0.804)"};
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
  char *string[] = {"sin", "(", "0.764", ")", "^", "ctg", "(", "0.119", ")", "*", "ln", "(", "(", "0.74", "*", "0.74", ")", "/", "(", "0.74", "^", "0.74", ")", ")", "+", "ln", "(", "0.970", ")", "+", "cos", "(", "0.602", ")", "+", "cos", "(", "(", "0.773", "-", "0.773", ")", "+", "(", "x", "*", "0.773", ")", ")", "^", "sqrt", "(", "0.446", ")", "/", "0.849"};
  char *example = {"sin(0.764)^ctg(0.119)*ln((0.74*0.74)/(0.74^0.74))+ln(0.970)+cos(0.602)+cos((0.773-0.773)+(x*0.773))^sqrt(0.446)/0.849"};
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
  char *string[] = {"acos", "(", "0.523", ")", "/", "log", "(", "0.782", ")", "/", "actg", "(", "(", "0.616", "*", "0.616", ")", "*", "(", "x", "*", "0.616", ")", ")", "*", "ctg", "(", "0.415", ")", "+", "sin", "(", "0.494", ")", "*", "tan", "(", "(", "0.407", "^", "0.407", ")", "+", "(", "x", "+", "0.407", ")", ")", "^"};
  char *example = {"acos(0.523)/log(0.782)/actg((0.616*0.616)*(x*0.616))*ctg(0.415)+sin(0.494)*tan((0.407^0.407)+(x+0.407))^"};
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
  char *string[] = {"atan", "(", "0.905", ")", "*", "acos", "(", "0.762", ")", "-", "ln", "(", "(", "0.520", "*", "0.520", ")", "+", "(", "0.828", "-", "0.520", ")", ")", "-", "ln", "(", "0.57", ")", "^", "log", "(", "0.288", ")", "-", "actg", "(", "(", "0.763", "+", "0.763", ")", "^", "(", "0.700", "*", "0.763", ")", ")", "*", "sqrt", "(", "0.662", ")", "/", "actg", "(", "0.47", ")", "+", "ln", "(", "(", "0.694", "-", "0.694", ")", "*", "(", "x", "/", "0.694", ")", ")", "*", "sin", "(", "0.504", ")", "^", "ctg", "(", "0.211", ")", "-", "atan", "(", "(", "0.672", "^", "0.672", ")", "^", "(", "x", "-", "0.672", ")", ")", "^", "actg", "(", "0.423", ")", "/", "actg", "(", "0.520", ")", "/", "atan", "(", "(", "0.585", "-", "0.585", ")", "-", "(", "x", "*", "0.585", ")", ")", "^"};
  char *example = {"atan(0.905)*acos(0.762)-ln((0.520*0.520)+(0.828-0.520))-ln(0.57)^log(0.288)-actg((0.763+0.763)^(0.700*0.763))*sqrt(0.662)/actg(0.47)+ln((0.694-0.694)*(x/0.694))*sin(0.504)^ctg(0.211)-atan((0.672^0.672)^(x-0.672))^actg(0.423)/actg(0.520)/atan((0.585-0.585)-(x*0.585))^"};
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
  char *string[] = {"acos", "(", "0.964", ")", "^", "tan", "(", "0.215", ")", "/", "sin", "(", "(", "0.257", "-", "0.257", ")", "-", "(", "0.336", "*", "0.257", ")", ")", "+", "sqrt", "(", "0.796", ")", "^", "acos", "(", "0.63", ")", "-", "tan", "(", "(", "0.295", "-", "0.295", ")", "*", "(", "0.484", "+", "0.295", ")", ")", "/", "sin", "(", "0.56", ")", "/", "atan", "(", "0.211", ")", "-", "log", "(", "(", "0.472", "/", "0.472", ")", "*", "(", "0.7", "+", "0.472", ")", ")", "*", "ln", "(", "0.398", ")", "/", "ln", "(", "0.186", ")", "/", "ctg", "(", "(", "0.919", "/", "0.919", ")", "-", "(", "0.919", "^", "0.919", ")", ")", "/", "atan", "(", "0.895", ")", "^", "acos", "(", "0.433", ")"};
  char *example = {"acos(0.964)^tan(0.215)/sin((0.257-0.257)-(0.336*0.257))+sqrt(0.796)^acos(0.63)-tan((0.295-0.295)*(0.484+0.295))/sin(0.56)/atan(0.211)-log((0.472/0.472)*(0.7+0.472))*ln(0.398)/ln(0.186)/ctg((0.919/0.919)-(0.919^0.919))/atan(0.895)^acos(0.433)"};
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
  char *string[] = {"ctg", "(", "0.251", ")", "*", "sqrt", "(", "0.404", ")", "-", "tan", "(", "(", "0.160", "*", "0.160", ")", "*", "(", "0.160", "/", "0.160", ")", ")", "+", "asin", "(", "0.186", ")", "-", "sqrt", "(", "0.670", ")", "*", "tan", "(", "(", "0.420", "+", "0.420", ")", "+", "(", "0.420", "/", "0.420", ")", ")", "-", "asin", "(", "0.789", ")", "/", "ln", "(", "0.534", ")", "-", "actg", "(", "(", "0.80", "^", "0.80", ")", "*", "(", "x", "*", "0.80", ")", ")", "+", "cos", "(", "0.271", ")", "^", "0.785"};
  char *example = {"ctg(0.251)*sqrt(0.404)-tan((0.160*0.160)*(0.160/0.160))+asin(0.186)-sqrt(0.670)*tan((0.420+0.420)+(0.420/0.420))-asin(0.789)/ln(0.534)-actg((0.80^0.80)*(x*0.80))+cos(0.271)^0.785"};
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
  char *string[] = {"asin", "(", "0.27", ")", "*", "acos", "(", "0.132", ")", "^", "tan", "(", "(", "0.450", "-", "0.450", ")", "/", "(", "x", "-", "0.450", ")", ")", "+", "log", "(", "0.992", ")", "*", "ctg", "(", "0.785", ")", "-", "sin", "(", "(", "0.660", "*", "0.660", ")", "/", "(", "x", "+", "0.660", ")", ")", "/", "cos", "(", "0.879", ")", "^", "0.696"};
  char *example = {"asin(0.27)*acos(0.132)^tan((0.450-0.450)/(x-0.450))+log(0.992)*ctg(0.785)-sin((0.660*0.660)/(x+0.660))/cos(0.879)^0.696"};
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
  char *string[] = {"log", "(", "0.391", ")", "/", "0.171"};
  char *example = {"log(0.391)/0.171"};
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
  char *string[] = {"cos", "(", "0.217", ")", "+", "sin", "(", "0.442", ")", "^", "cos", "(", "(", "0.168", "*", "0.168", ")", "*", "(", "0.168", "/", "0.168", ")", ")", "*", "sqrt", "(", "0.73", ")", "/", "0.111"};
  char *example = {"cos(0.217)+sin(0.442)^cos((0.168*0.168)*(0.168/0.168))*sqrt(0.73)/0.111"};
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
  char *string[] = {"asin", "(", "0.574", ")", "+", "tan", "(", "0.115", ")", "^", "sin", "(", "(", "0.479", "-", "0.479", ")", "^", "(", "x", "+", "0.479", ")", ")", "-", "acos", "(", "0.66", ")", "^", "ctg", "(", "0.172", ")", "*", "actg", "(", "(", "0.844", "/", "0.844", ")", "+", "(", "x", "-", "0.844", ")", ")", "^", "ln", "(", "0.116", ")"};
  char *example = {"asin(0.574)+tan(0.115)^sin((0.479-0.479)^(x+0.479))-acos(0.66)^ctg(0.172)*actg((0.844/0.844)+(x-0.844))^ln(0.116)"};
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
  char *string[] = {"atan", "(", "0.312", ")", "^", "cos", "(", "0.283", ")", "+", "atan", "(", "(", "0.390", "*", "0.390", ")", "-", "(", "0.390", "*", "0.390", ")", ")", "*", "atan", "(", "0.956", ")", "/", "sin", "(", "0.14", ")", "+", "atan", "(", "(", "0.811", "-", "0.811", ")", "/", "(", "x", "^", "0.811", ")", ")", "^", "actg", "(", "0.810", ")", "-", "sqrt", "(", "0.838", ")", "/", "sin", "(", "(", "0.593", "+", "0.593", ")", "-", "(", "x", "-", "0.593", ")", ")", "-", "actg", "(", "0.676", ")", "*", "0.470"};
  char *example = {"atan(0.312)^cos(0.283)+atan((0.390*0.390)-(0.390*0.390))*atan(0.956)/sin(0.14)+atan((0.811-0.811)/(x^0.811))^actg(0.810)-sqrt(0.838)/sin((0.593+0.593)-(x-0.593))-actg(0.676)*0.470"};
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
  char *string[] = {"602", "%", "455"};
  char *example = {"602%455"};
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
  char *string[] = {"tan", "(", "0.864", ")", "^", "ln", "(", "0.576", ")", "/", "cos", "(", "(", "0.851", "/", "0.851", ")", "*", "(", "0.643", "-", "0.851", ")", ")", "-", "ctg", "(", "0.822", ")", "-", "asin", "(", "0.353", ")", "*", "ln", "(", "(", "0.935", "-", "0.935", ")", "-", "(", "x", "/", "0.935", ")", ")", "+", "tan", "(", "0.410", ")", "-", "asin", "(", "0.542", ")", "+", "tan", "(", "(", "0.521", "*", "0.521", ")", "*", "(", "0.921", "*", "0.521", ")", ")", "*", "asin", "(", "0.127", ")", "/", "asin", "(", "0.542", ")", "*", "asin", "(", "(", "0.859", "*", "0.859", ")", "^", "(", "0.859", "^", "0.859", ")", ")", "/", "sqrt", "(", "0.687", ")", "/", "tan", "(", "0.698", ")"};
  char *example = {"tan(0.864)^ln(0.576)/cos((0.851/0.851)*(0.643-0.851))-ctg(0.822)-asin(0.353)*ln((0.935-0.935)-(x/0.935))+tan(0.410)-asin(0.542)+tan((0.521*0.521)*(0.921*0.521))*asin(0.127)/asin(0.542)*asin((0.859*0.859)^(0.859^0.859))/sqrt(0.687)/tan(0.698)"};
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
  char *string[] = {"tan", "(", "0.280", ")", "^", "ctg", "(", "0.274", ")", "+", "cos", "(", "(", "0.229", "^", "0.229", ")", "-", "(", "0.11", "/", "0.229", ")", ")", "-", "sin", "(", "0.583", ")", "/", "sin", "(", "0.200", ")", "^", "sqrt", "(", "(", "0.842", "-", "0.842", ")", "/", "(", "0.580", "/", "0.842", ")", ")", "+", "ln", "(", "0.869", ")"};
  char *example = {"tan(0.280)^ctg(0.274)+cos((0.229^0.229)-(0.11/0.229))-sin(0.583)/sin(0.200)^sqrt((0.842-0.842)/(0.580/0.842))+ln(0.869)"};
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
  char *string[] = {"asin", "(", "0.579", ")", "^", "atan", "(", "0.705", ")", "+", "sin", "(", "(", "0.141", "*", "0.141", ")", "+", "(", "0.692", "*", "0.141", ")", ")", "-", "ln", "(", "0.29", ")", "*", "acos", "(", "0.63", ")", "^", "asin", "(", "(", "0.361", "-", "0.361", ")", "/", "(", "0.361", "^", "0.361", ")", ")", "-", "ctg", "(", "0.853", ")", "*", "ln", "(", "0.539", ")", "*", "atan", "(", "(", "0.106", "*", "0.106", ")", "-", "(", "0.957", "/", "0.106", ")", ")", "-", "atan", "(", "0.338", ")", "+", "log", "(", "0.367", ")", "^", "sin", "(", "(", "0.513", "+", "0.513", ")", "/", "(", "0.513", "*", "0.513", ")", ")", "-"};
  char *example = {"asin(0.579)^atan(0.705)+sin((0.141*0.141)+(0.692*0.141))-ln(0.29)*acos(0.63)^asin((0.361-0.361)/(0.361^0.361))-ctg(0.853)*ln(0.539)*atan((0.106*0.106)-(0.957/0.106))-atan(0.338)+log(0.367)^sin((0.513+0.513)/(0.513*0.513))-"};
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
  char *string[] = {"ln", "(", "0.964", ")", "/", "sin", "(", "0.913", ")", "*", "ctg", "(", "(", "0.364", "*", "0.364", ")", "-", "(", "0.402", "/", "0.364", ")", ")", "+", "sqrt", "(", "0.128", ")", "*", "ctg", "(", "0.659", ")", "^", "ln", "(", "(", "0.161", "-", "0.161", ")", "*", "(", "x", "/", "0.161", ")", ")", "-", "asin", "(", "0.358", ")", "*", "acos", "(", "0.663", ")", "^", "acos", "(", "(", "0.722", "/", "0.722", ")", "-", "(", "0.722", "*", "0.722", ")", ")", "^", "acos", "(", "0.93", ")", "/", "actg", "(", "0.381", ")", "*", "log", "(", "(", "0.897", "*", "0.897", ")", "+", "(", "0.897", "*", "0.897", ")", ")", "+", "log", "(", "0.485", ")", "*", "atan", "(", "0.519", ")"};
  char *example = {"ln(0.964)/sin(0.913)*ctg((0.364*0.364)-(0.402/0.364))+sqrt(0.128)*ctg(0.659)^ln((0.161-0.161)*(x/0.161))-asin(0.358)*acos(0.663)^acos((0.722/0.722)-(0.722*0.722))^acos(0.93)/actg(0.381)*log((0.897*0.897)+(0.897*0.897))+log(0.485)*atan(0.519)"};
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
  char *string[] = {"tan", "(", "0.768", ")", "-", "atan", "(", "0.974", ")", "*", "cos", "(", "(", "0.853", "^", "0.853", ")", "+", "(", "x", "^", "0.853", ")", ")", "*", "sin", "(", "0.519", ")", "-", "ln", "(", "0.81", ")", "+", "sin", "(", "(", "0.329", "*", "0.329", ")", "^", "(", "x", "^", "0.329", ")", ")", "+", "sqrt", "(", "0.594", ")", "-", "asin", "(", "0.102", ")", "^", "atan", "(", "(", "0.837", "-", "0.837", ")", "*", "(", "0.837", "/", "0.837", ")", ")", "-", "sqrt", "(", "0.363", ")", "/", "ctg", "(", "0.748", ")", "*", "acos", "(", "(", "0.337", "+", "0.337", ")", "*", "(", "x", "-", "0.337", ")", ")", "+", "acos", "(", "0.945", ")"};
  char *example = {"tan(0.768)-atan(0.974)*cos((0.853^0.853)+(x^0.853))*sin(0.519)-ln(0.81)+sin((0.329*0.329)^(x^0.329))+sqrt(0.594)-asin(0.102)^atan((0.837-0.837)*(0.837/0.837))-sqrt(0.363)/ctg(0.748)*acos((0.337+0.337)*(x-0.337))+acos(0.945)"};
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
  char *string[] = {"tan", "(", "0.4", ")", "+", "sqrt", "(", "0.242", ")", "-", "cos", "(", "(", "0.129", "+", "0.129", ")", "+", "(", "0.129", "+", "0.129", ")", ")", "+", "asin", "(", "0.140", ")", "+", "log", "(", "0.929", ")", "+", "atan", "(", "(", "0.990", "^", "0.990", ")", "-", "(", "0.990", "/", "0.990", ")", ")", "/", "atan", "(", "0.66", ")", "+", "ctg", "(", "0.442", ")", "*", "log", "(", "(", "0.128", "^", "0.128", ")", "-", "(", "0.168", "^", "0.128", ")", ")", "-", "ln", "(", "0.701", ")", "^", "sqrt", "(", "0.929", ")"};
  char *example = {"tan(0.4)+sqrt(0.242)-cos((0.129+0.129)+(0.129+0.129))+asin(0.140)+log(0.929)+atan((0.990^0.990)-(0.990/0.990))/atan(0.66)+ctg(0.442)*log((0.128^0.128)-(0.168^0.128))-ln(0.701)^sqrt(0.929)"};
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
  char *string[] = {"atan", "(", "0.337", ")"};
  char *example = {"atan(0.337)"};
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
  char *string[] = {"747", "%", "726"};
  char *example = {"747%726"};
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
  char *string[] = {"acos", "(", "0.918", ")", "+", "tan", "(", "0.391", ")", "/", "log", "(", "(", "0.667", "+", "0.667", ")", "-", "(", "0.667", "*", "0.667", ")", ")", "^", "actg", "(", "0.594", ")", "^", "asin", "(", "0.881", ")", "*", "actg", "(", "(", "0.392", "^", "0.392", ")", "+", "(", "0.392", "-", "0.392", ")", ")", "^", "acos", "(", "0.407", ")"};
  char *example = {"acos(0.918)+tan(0.391)/log((0.667+0.667)-(0.667*0.667))^actg(0.594)^asin(0.881)*actg((0.392^0.392)+(0.392-0.392))^acos(0.407)"};
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
  char *string[] = {"atan", "(", "0.289", ")", "+", "sin", "(", "0.95", ")", "+", "actg", "(", "(", "0.764", "^", "0.764", ")", "^", "(", "0.764", "^", "0.764", ")", ")", "^", "acos", "(", "0.32", ")", "-", "cos", "(", "0.216", ")"};
  char *example = {"atan(0.289)+sin(0.95)+actg((0.764^0.764)^(0.764^0.764))^acos(0.32)-cos(0.216)"};
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
  char *string[] = {"acos", "(", "0.283", ")", "*", "ctg", "(", "0.81", ")", "*", "acos", "(", "(", "0.587", "*", "0.587", ")", "/", "(", "0.759", "/", "0.587", ")", ")", "/", "tan", "(", "0.622", ")", "^", "atan", "(", "0.167", ")", "^", "actg", "(", "(", "0.659", "*", "0.659", ")", "+", "(", "0.718", "/", "0.659", ")", ")", "+", "ln", "(", "0.580", ")"};
  char *example = {"acos(0.283)*ctg(0.81)*acos((0.587*0.587)/(0.759/0.587))/tan(0.622)^atan(0.167)^actg((0.659*0.659)+(0.718/0.659))+ln(0.580)"};
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
  char *string[] = {"sin", "(", "0.443", ")", "*", "sin", "(", "0.718", ")", "^", "ln", "(", "(", "0.72", "^", "0.72", ")", "+", "(", "0.72", "-", "0.72", ")", ")", "+", "atan", "(", "0.411", ")", "/", "acos", "(", "0.348", ")", "-", "asin", "(", "(", "0.527", "-", "0.527", ")", "/", "(", "0.527", "*", "0.527", ")", ")", "*"};
  char *example = {"sin(0.443)*sin(0.718)^ln((0.72^0.72)+(0.72-0.72))+atan(0.411)/acos(0.348)-asin((0.527-0.527)/(0.527*0.527))*"};
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
  char *string[] = {"ctg", "(", "0.976", ")", "*", "atan", "(", "0.49", ")", "/", "sin", "(", "(", "0.857", "-", "0.857", ")", "+", "(", "0.986", "+", "0.857", ")", ")", "/", "log", "(", "0.652", ")", "/", "sin", "(", "0.10", ")", "^", "log", "(", "(", "0.693", "*", "0.693", ")", "+", "(", "x", "-", "0.693", ")", ")", "+", "tan", "(", "0.684", ")", "-", "tan", "(", "0.265", ")", "/", "sqrt", "(", "(", "0.374", "/", "0.374", ")", "*", "(", "0.374", "+", "0.374", ")", ")", "-", "ln", "(", "0.998", ")", "-", "ln", "(", "0.553", ")", "+", "sqrt", "(", "(", "0.595", "*", "0.595", ")", "^", "(", "0.823", "+", "0.595", ")", ")", "+", "tan", "(", "0.191", ")"};
  char *example = {"ctg(0.976)*atan(0.49)/sin((0.857-0.857)+(0.986+0.857))/log(0.652)/sin(0.10)^log((0.693*0.693)+(x-0.693))+tan(0.684)-tan(0.265)/sqrt((0.374/0.374)*(0.374+0.374))-ln(0.998)-ln(0.553)+sqrt((0.595*0.595)^(0.823+0.595))+tan(0.191)"};
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
  char *string[] = {"cos", "(", "0.305", ")", "/", "actg", "(", "0.472", ")", "/", "actg", "(", "(", "0.623", "^", "0.623", ")", "+", "(", "x", "-", "0.623", ")", ")", "^", "acos", "(", "0.698", ")", "*", "sin", "(", "0.478", ")", "*", "cos", "(", "(", "0.613", "+", "0.613", ")", "+", "(", "0.93", "-", "0.613", ")", ")", "/", "cos", "(", "0.641", ")", "^", "asin", "(", "0.131", ")", "^", "log", "(", "(", "0.439", "/", "0.439", ")", "/", "(", "0.439", "/", "0.439", ")", ")", "*", "sin", "(", "0.246", ")", "/", "sqrt", "(", "0.12", ")", "*", "actg", "(", "(", "0.125", "/", "0.125", ")", "+", "(", "0.125", "*", "0.125", ")", ")", "^", "cos", "(", "0.606", ")"};
  char *example = {"cos(0.305)/actg(0.472)/actg((0.623^0.623)+(x-0.623))^acos(0.698)*sin(0.478)*cos((0.613+0.613)+(0.93-0.613))/cos(0.641)^asin(0.131)^log((0.439/0.439)/(0.439/0.439))*sin(0.246)/sqrt(0.12)*actg((0.125/0.125)+(0.125*0.125))^cos(0.606)"};
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
  char *string[] = {"acos", "(", "0.495", ")", "/", "ctg", "(", "0.112", ")", "^", "atan", "(", "(", "0.586", "+", "0.586", ")", "*", "(", "0.586", "-", "0.586", ")", ")", "/", "acos", "(", "0.975", ")", "-", "ctg", "(", "0.760", ")", "+", "sin", "(", "(", "0.491", "^", "0.491", ")", "/", "(", "0.491", "*", "0.491", ")", ")", "-", "ctg", "(", "0.335", ")", "^", "cos", "(", "0.704", ")", "/", "atan", "(", "(", "0.807", "*", "0.807", ")", "-", "(", "0.807", "*", "0.807", ")", ")", "*", "asin", "(", "0.255", ")", "/", "acos", "(", "0.663", ")", "^", "atan", "(", "(", "0.900", "+", "0.900", ")", "+", "(", "x", "+", "0.900", ")", ")", "*", "sin", "(", "0.860", ")", "*", "0.587"};
  char *example = {"acos(0.495)/ctg(0.112)^atan((0.586+0.586)*(0.586-0.586))/acos(0.975)-ctg(0.760)+sin((0.491^0.491)/(0.491*0.491))-ctg(0.335)^cos(0.704)/atan((0.807*0.807)-(0.807*0.807))*asin(0.255)/acos(0.663)^atan((0.900+0.900)+(x+0.900))*sin(0.860)*0.587"};
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
  char *string[] = {"actg", "(", "0.15", ")", "/", "cos", "(", "0.391", ")", "+", "log", "(", "(", "0.630", "/", "0.630", ")", "/", "(", "x", "+", "0.630", ")", ")", "*", "cos", "(", "0.864", ")", "/", "asin", "(", "0.503", ")", "-", "tan", "(", "(", "0.359", "-", "0.359", ")", "/", "(", "x", "*", "0.359", ")", ")", "-", "ln", "(", "0.290", ")"};
  char *example = {"actg(0.15)/cos(0.391)+log((0.630/0.630)/(x+0.630))*cos(0.864)/asin(0.503)-tan((0.359-0.359)/(x*0.359))-ln(0.290)"};
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
  char *string[] = {"sin", "(", "0.165", ")", "+", "log", "(", "0.198", ")", "*", "actg", "(", "(", "0.276", "+", "0.276", ")", "^", "(", "0.852", "/", "0.276", ")", ")", "^", "cos", "(", "0.816", ")", "^", "actg", "(", "0.885", ")", "/", "log", "(", "(", "0.396", "^", "0.396", ")", "+", "(", "x", "-", "0.396", ")", ")", "^", "actg", "(", "0.678", ")", "+", "log", "(", "0.348", ")", "-", "sin", "(", "(", "0.779", "^", "0.779", ")", "-", "(", "x", "-", "0.779", ")", ")", "^", "acos", "(", "0.486", ")", "-", "0.939"};
  char *example = {"sin(0.165)+log(0.198)*actg((0.276+0.276)^(0.852/0.276))^cos(0.816)^actg(0.885)/log((0.396^0.396)+(x-0.396))^actg(0.678)+log(0.348)-sin((0.779^0.779)-(x-0.779))^acos(0.486)-0.939"};
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
  char *string[] = {"cos", "(", "0.256", ")", "-", "ctg", "(", "0.361", ")", "-", "atan", "(", "(", "0.45", "/", "0.45", ")", "+", "(", "x", "/", "0.45", ")", ")", "^", "asin", "(", "0.120", ")", "/", "acos", "(", "0.637", ")", "-", "ctg", "(", "(", "0.362", "*", "0.362", ")", "^", "(", "x", "+", "0.362", ")", ")", "/", "log", "(", "0.724", ")", "^", "actg", "(", "0.579", ")", "-", "ctg", "(", "(", "0.721", "+", "0.721", ")", "+", "(", "0.252", "-", "0.721", ")", ")", "*", "ln", "(", "0.111", ")", "+", "0.307"};
  char *example = {"cos(0.256)-ctg(0.361)-atan((0.45/0.45)+(x/0.45))^asin(0.120)/acos(0.637)-ctg((0.362*0.362)^(x+0.362))/log(0.724)^actg(0.579)-ctg((0.721+0.721)+(0.252-0.721))*ln(0.111)+0.307"};
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
  char *string[] = {"tan", "(", "0.507", ")", "^", "atan", "(", "0.734", ")", "*", "actg", "(", "(", "0.735", "^", "0.735", ")", "+", "(", "0.289", "/", "0.735", ")", ")", "+", "cos", "(", "0.904", ")", "-", "ctg", "(", "0.975", ")", "+", "cos", "(", "(", "0.571", "/", "0.571", ")", "-", "(", "0.704", "^", "0.571", ")", ")", "^", "actg", "(", "0.456", ")", "^", "log", "(", "0.50", ")"};
  char *example = {"tan(0.507)^atan(0.734)*actg((0.735^0.735)+(0.289/0.735))+cos(0.904)-ctg(0.975)+cos((0.571/0.571)-(0.704^0.571))^actg(0.456)^log(0.50)"};
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
  char *string[] = {"sqrt", "(", "0.458", ")", "-", "log", "(", "0.868", ")", "-", "asin", "(", "(", "0.468", "*", "0.468", ")", "^", "(", "0.468", "*", "0.468", ")", ")", "/", "asin", "(", "0.497", ")", "^", "ctg", "(", "0.545", ")", "/", "acos", "(", "(", "0.598", "^", "0.598", ")", "+", "(", "x", "/", "0.598", ")", ")", "-", "sin", "(", "0.230", ")", "-", "asin", "(", "0.666", ")", "^", "log", "(", "(", "0.838", "+", "0.838", ")", "^", "(", "0.838", "^", "0.838", ")", ")", "/", "ln", "(", "0.466", ")"};
  char *example = {"sqrt(0.458)-log(0.868)-asin((0.468*0.468)^(0.468*0.468))/asin(0.497)^ctg(0.545)/acos((0.598^0.598)+(x/0.598))-sin(0.230)-asin(0.666)^log((0.838+0.838)^(0.838^0.838))/ln(0.466)"};
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
  char *string[] = {"atan", "(", "0.936", ")", "*", "ctg", "(", "0.84", ")", "-", "ln", "(", "(", "0.48", "^", "0.48", ")", "*", "(", "0.564", "*", "0.48", ")", ")", "*", "sqrt", "(", "0.653", ")", "*", "ctg", "(", "0.342", ")", "/", "tan", "(", "(", "0.350", "+", "0.350", ")", "+", "(", "0.350", "^", "0.350", ")", ")", "/", "tan", "(", "0.643", ")", "-", "tan", "(", "0.527", ")", "*", "actg", "(", "(", "0.196", "-", "0.196", ")", "+", "(", "x", "+", "0.196", ")", ")", "/", "log", "(", "0.125", ")", "^", "actg", "(", "0.915", ")", "^", "atan", "(", "(", "0.69", "^", "0.69", ")", "*", "(", "0.69", "-", "0.69", ")", ")", "-", "ln", "(", "0.765", ")", "*", "atan", "(", "0.592", ")"};
  char *example = {"atan(0.936)*ctg(0.84)-ln((0.48^0.48)*(0.564*0.48))*sqrt(0.653)*ctg(0.342)/tan((0.350+0.350)+(0.350^0.350))/tan(0.643)-tan(0.527)*actg((0.196-0.196)+(x+0.196))/log(0.125)^actg(0.915)^atan((0.69^0.69)*(0.69-0.69))-ln(0.765)*atan(0.592)"};
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
  char *string[] = {"atan", "(", "0.663", ")", "/", "atan", "(", "0.271", ")", "^", "atan", "(", "(", "0.686", "/", "0.686", ")", "+", "(", "x", "+", "0.686", ")", ")", "+"};
  char *example = {"atan(0.663)/atan(0.271)^atan((0.686/0.686)+(x+0.686))+"};
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
  char *string[] = {"ctg", "(", "0.740", ")", "/", "cos", "(", "0.780", ")", "/", "asin", "(", "(", "0.649", "+", "0.649", ")", "+", "(", "0.649", "/", "0.649", ")", ")", "-", "sin", "(", "0.138", ")", "*", "ln", "(", "0.62", ")", "+", "sqrt", "(", "(", "0.889", "-", "0.889", ")", "+", "(", "0.889", "-", "0.889", ")", ")", "/", "tan", "(", "0.374", ")", "-", "atan", "(", "0.130", ")", "^", "tan", "(", "(", "0.243", "*", "0.243", ")", "^", "(", "0.243", "*", "0.243", ")", ")", "*", "actg", "(", "0.130", ")", "^", "sin", "(", "0.593", ")", "-", "actg", "(", "(", "0.525", "^", "0.525", ")", "^", "(", "0.157", "-", "0.525", ")", ")", "-", "acos", "(", "0.592", ")", "/", "asin", "(", "0.551", ")", "^", "ctg", "(", "(", "0.870", "*", "0.870", ")", "-", "(", "0.805", "*", "0.870", ")", ")", "/"};
  char *example = {"ctg(0.740)/cos(0.780)/asin((0.649+0.649)+(0.649/0.649))-sin(0.138)*ln(0.62)+sqrt((0.889-0.889)+(0.889-0.889))/tan(0.374)-atan(0.130)^tan((0.243*0.243)^(0.243*0.243))*actg(0.130)^sin(0.593)-actg((0.525^0.525)^(0.157-0.525))-acos(0.592)/asin(0.551)^ctg((0.870*0.870)-(0.805*0.870))/"};
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
  char *string[] = {"log", "(", "0.234", ")", "/", "ln", "(", "0.291", ")", "+", "atan", "(", "(", "0.457", "-", "0.457", ")", "*", "(", "0.457", "-", "0.457", ")", ")", "*", "sqrt", "(", "0.639", ")", "-", "log", "(", "0.255", ")", "/", "tan", "(", "(", "0.621", "+", "0.621", ")", "+", "(", "0.621", "/", "0.621", ")", ")", "^", "sqrt", "(", "0.813", ")"};
  char *example = {"log(0.234)/ln(0.291)+atan((0.457-0.457)*(0.457-0.457))*sqrt(0.639)-log(0.255)/tan((0.621+0.621)+(0.621/0.621))^sqrt(0.813)"};
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
  char *string[] = {"acos", "(", "0.63", ")", "/", "0.968"};
  char *example = {"acos(0.63)/0.968"};
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
  char *string[] = {"sin", "(", "0.33", ")", "/", "cos", "(", "0.800", ")", "/", "acos", "(", "(", "0.942", "/", "0.942", ")", "/", "(", "x", "+", "0.942", ")", ")", "^", "sqrt", "(", "0.939", ")", "*", "log", "(", "0.106", ")", "+", "ctg", "(", "(", "0.423", "^", "0.423", ")", "+", "(", "x", "-", "0.423", ")", ")", "^", "acos", "(", "0.71", ")", "-", "cos", "(", "0.816", ")", "+", "cos", "(", "(", "0.834", "*", "0.834", ")", "*", "(", "0.834", "/", "0.834", ")", ")", "+", "cos", "(", "0.836", ")"};
  char *example = {"sin(0.33)/cos(0.800)/acos((0.942/0.942)/(x+0.942))^sqrt(0.939)*log(0.106)+ctg((0.423^0.423)+(x-0.423))^acos(0.71)-cos(0.816)+cos((0.834*0.834)*(0.834/0.834))+cos(0.836)"};
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
  char *string[] = {"ln", "(", "0.67", ")", "^", "0.652"};
  char *example = {"ln(0.67)^0.652"};
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
  char *string[] = {"acos", "(", "0.885", ")", "*", "acos", "(", "0.827", ")", "+", "ctg", "(", "(", "0.589", "/", "0.589", ")", "*", "(", "0.912", "^", "0.589", ")", ")", "-", "sqrt", "(", "0.75", ")", "*", "tan", "(", "0.888", ")", "+", "actg", "(", "(", "0.339", "^", "0.339", ")", "-", "(", "0.339", "/", "0.339", ")", ")", "*", "cos", "(", "0.720", ")", "+", "ln", "(", "0.697", ")", "+", "tan", "(", "(", "0.440", "*", "0.440", ")", "*", "(", "x", "^", "0.440", ")", ")", "^", "sin", "(", "0.71", ")", "/", "log", "(", "0.432", ")", "^", "ln", "(", "(", "0.963", "+", "0.963", ")", "/", "(", "x", "-", "0.963", ")", ")", "*"};
  char *example = {"acos(0.885)*acos(0.827)+ctg((0.589/0.589)*(0.912^0.589))-sqrt(0.75)*tan(0.888)+actg((0.339^0.339)-(0.339/0.339))*cos(0.720)+ln(0.697)+tan((0.440*0.440)*(x^0.440))^sin(0.71)/log(0.432)^ln((0.963+0.963)/(x-0.963))*"};
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
  char *string[] = {"log", "(", "0.979", ")", "+", "actg", "(", "0.388", ")", "-", "atan", "(", "(", "0.31", "-", "0.31", ")", "/", "(", "x", "/", "0.31", ")", ")", "+"};
  char *example = {"log(0.979)+actg(0.388)-atan((0.31-0.31)/(x/0.31))+"};
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
  char *string[] = {"sin", "(", "0.409", ")", "/", "cos", "(", "0.622", ")", "/", "cos", "(", "(", "0.776", "+", "0.776", ")", "/", "(", "0.790", "*", "0.776", ")", ")", "/"};
  char *example = {"sin(0.409)/cos(0.622)/cos((0.776+0.776)/(0.790*0.776))/"};
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
  char *string[] = {"cos", "(", "0.434", ")", "^", "ctg", "(", "0.139", ")", "*", "sqrt", "(", "(", "0.588", "+", "0.588", ")", "+", "(", "x", "+", "0.588", ")", ")", "/", "log", "(", "0.520", ")", "-", "sqrt", "(", "0.176", ")", "^", "asin", "(", "(", "0.941", "^", "0.941", ")", "-", "(", "x", "/", "0.941", ")", ")", "/", "log", "(", "0.528", ")", "+", "sin", "(", "0.302", ")", "/", "actg", "(", "(", "0.856", "-", "0.856", ")", "/", "(", "x", "^", "0.856", ")", ")", "*"};
  char *example = {"cos(0.434)^ctg(0.139)*sqrt((0.588+0.588)+(x+0.588))/log(0.520)-sqrt(0.176)^asin((0.941^0.941)-(x/0.941))/log(0.528)+sin(0.302)/actg((0.856-0.856)/(x^0.856))*"};
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
  char *string[] = {"ctg", "(", "0.580", ")", "/", "acos", "(", "0.737", ")", "^", "acos", "(", "(", "0.231", "^", "0.231", ")", "*", "(", "0.231", "*", "0.231", ")", ")", "/", "log", "(", "0.980", ")", "-", "acos", "(", "0.15", ")", "/", "tan", "(", "(", "0.465", "/", "0.465", ")", "*", "(", "0.455", "/", "0.465", ")", ")", "^", "sqrt", "(", "0.821", ")", "^", "atan", "(", "0.568", ")", "/", "sqrt", "(", "(", "0.255", "^", "0.255", ")", "+", "(", "x", "+", "0.255", ")", ")", "^", "actg", "(", "0.335", ")", "^", "ctg", "(", "0.192", ")", "-", "sqrt", "(", "(", "0.123", "/", "0.123", ")", "*", "(", "x", "*", "0.123", ")", ")", "-", "sqrt", "(", "0.525", ")", "+", "asin", "(", "0.201", ")", "*", "asin", "(", "(", "0.368", "*", "0.368", ")", "^", "(", "0.489", "/", "0.368", ")", ")", "/"};
  char *example = {"ctg(0.580)/acos(0.737)^acos((0.231^0.231)*(0.231*0.231))/log(0.980)-acos(0.15)/tan((0.465/0.465)*(0.455/0.465))^sqrt(0.821)^atan(0.568)/sqrt((0.255^0.255)+(x+0.255))^actg(0.335)^ctg(0.192)-sqrt((0.123/0.123)*(x*0.123))-sqrt(0.525)+asin(0.201)*asin((0.368*0.368)^(0.489/0.368))/"};
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
  char *string[] = {"ln", "(", "0.809", ")", "*", "acos", "(", "0.935", ")", "+", "actg", "(", "(", "0.866", "+", "0.866", ")", "^", "(", "0.866", "/", "0.866", ")", ")", "-"};
  char *example = {"ln(0.809)*acos(0.935)+actg((0.866+0.866)^(0.866/0.866))-"};
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
