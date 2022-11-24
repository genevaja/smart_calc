#include "../header.h"

START_TEST(parser_1) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"ln", "(", "0.380", ")", "/", "log", "(", "0.519", ")", "^", "sqrt", "(", "(", "0.366", "^", "0.366", ")", "/", "(", "0.117", "*", "0.366", ")", ")", "*", "cos", "(", "0.40", ")", "*", "actg", "(", "0.372", ")", "*", "acos", "(", "(", "0.651", "/", "0.651", ")", "+", "(", "x", "-", "0.651", ")", ")", "/", "atan", "(", "0.612", ")", "^", "sqrt", "(", "0.56", ")", "*", "sin", "(", "(", "0.629", "/", "0.629", ")", "+", "(", "0.908", "-", "0.629", ")", ")", "^", "ctg", "(", "0.801", ")", "/", "atan", "(", "0.602", ")", "/", "atan", "(", "(", "0.745", "-", "0.745", ")", "/", "(", "0.807", "/", "0.745", ")", ")", "+", "log", "(", "0.669", ")", "/", "0.414"};
  char *example = {"ln(0.380)/log(0.519)^sqrt((0.366^0.366)/(0.117*0.366))*cos(0.40)*actg(0.372)*acos((0.651/0.651)+(x-0.651))/atan(0.612)^sqrt(0.56)*sin((0.629/0.629)+(0.908-0.629))^ctg(0.801)/atan(0.602)/atan((0.745-0.745)/(0.807/0.745))+log(0.669)/0.414"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_2) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"sqrt", "(", "0.777", ")", "^", "actg", "(", "0.189", ")", "+", "ln", "(", "(", "0.50", "*", "0.50", ")", "*", "(", "0.50", "-", "0.50", ")", ")", "^", "actg", "(", "0.422", ")", "+", "atan", "(", "0.96", ")", "/", "tan", "(", "(", "0.515", "^", "0.515", ")", "/", "(", "0.515", "+", "0.515", ")", ")", "/"};
  char *example = {"sqrt(0.777)^actg(0.189)+ln((0.50*0.50)*(0.50-0.50))^actg(0.422)+atan(0.96)/tan((0.515^0.515)/(0.515+0.515))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_3) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"cos", "(", "0.482", ")", "*", "asin", "(", "0.552", ")", "-", "atan", "(", "(", "0.703", "+", "0.703", ")", "+", "(", "0.7", "+", "0.703", ")", ")", "-", "ctg", "(", "0.135", ")", "^", "ctg", "(", "0.460", ")", "/", "ctg", "(", "(", "0.127", "*", "0.127", ")", "*", "(", "0.127", "*", "0.127", ")", ")", "-", "cos", "(", "0.51", ")", "^", "actg", "(", "0.838", ")", "/", "atan", "(", "(", "0.480", "*", "0.480", ")", "-", "(", "x", "-", "0.480", ")", ")", "/", "tan", "(", "0.467", ")", "*", "ln", "(", "0.737", ")", "/", "tan", "(", "(", "0.166", "-", "0.166", ")", "^", "(", "0.166", "^", "0.166", ")", ")", "^", "ln", "(", "0.264", ")", "-", "atan", "(", "0.45", ")"};
  char *example = {"cos(0.482)*asin(0.552)-atan((0.703+0.703)+(0.7+0.703))-ctg(0.135)^ctg(0.460)/ctg((0.127*0.127)*(0.127*0.127))-cos(0.51)^actg(0.838)/atan((0.480*0.480)-(x-0.480))/tan(0.467)*ln(0.737)/tan((0.166-0.166)^(0.166^0.166))^ln(0.264)-atan(0.45)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_4) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"log", "(", "0.468", ")"};
  char *example = {"log(0.468)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_5) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"ln", "(", "0.278", ")", "-", "sqrt", "(", "0.799", ")", "/", "actg", "(", "(", "0.835", "+", "0.835", ")", "+", "(", "0.650", "+", "0.835", ")", ")", "+", "acos", "(", "0.903", ")", "-", "acos", "(", "0.813", ")", "*", "acos", "(", "(", "0.48", "*", "0.48", ")", "/", "(", "x", "^", "0.48", ")", ")", "*", "acos", "(", "0.135", ")", "-", "tan", "(", "0.135", ")", "*", "log", "(", "(", "0.718", "-", "0.718", ")", "-", "(", "0.718", "*", "0.718", ")", ")", "*", "ctg", "(", "0.482", ")", "-", "log", "(", "0.304", ")"};
  char *example = {"ln(0.278)-sqrt(0.799)/actg((0.835+0.835)+(0.650+0.835))+acos(0.903)-acos(0.813)*acos((0.48*0.48)/(x^0.48))*acos(0.135)-tan(0.135)*log((0.718-0.718)-(0.718*0.718))*ctg(0.482)-log(0.304)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_6) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"sin", "(", "0.750", ")", "+", "cos", "(", "0.498", ")", "/", "tan", "(", "(", "0.958", "*", "0.958", ")", "+", "(", "0.958", "*", "0.958", ")", ")", "/", "actg", "(", "0.292", ")", "*", "log", "(", "0.488", ")", "^", "asin", "(", "(", "0.63", "^", "0.63", ")", "*", "(", "0.63", "/", "0.63", ")", ")", "^", "log", "(", "0.11", ")", "/", "actg", "(", "0.367", ")"};
  char *example = {"sin(0.750)+cos(0.498)/tan((0.958*0.958)+(0.958*0.958))/actg(0.292)*log(0.488)^asin((0.63^0.63)*(0.63/0.63))^log(0.11)/actg(0.367)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_7) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"atan", "(", "0.478", ")"};
  char *example = {"atan(0.478)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_8) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"actg", "(", "0.334", ")", "^", "sqrt", "(", "0.592", ")", "*", "actg", "(", "(", "0.471", "/", "0.471", ")", "^", "(", "0.47", "+", "0.471", ")", ")", "^", "ln", "(", "0.874", ")"};
  char *example = {"actg(0.334)^sqrt(0.592)*actg((0.471/0.471)^(0.47+0.471))^ln(0.874)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_9) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"atan", "(", "0.810", ")", "/", "tan", "(", "0.437", ")", "*", "actg", "(", "(", "0.61", "*", "0.61", ")", "^", "(", "0.758", "/", "0.61", ")", ")", "*", "actg", "(", "0.524", ")", "-", "0.50"};
  char *example = {"atan(0.810)/tan(0.437)*actg((0.61*0.61)^(0.758/0.61))*actg(0.524)-0.50"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_10) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"acos", "(", "0.922", ")", "/", "sqrt", "(", "0.600", ")", "*", "asin", "(", "(", "0.764", "-", "0.764", ")", "/", "(", "x", "/", "0.764", ")", ")", "*", "cos", "(", "0.146", ")", "*", "log", "(", "0.298", ")", "-", "log", "(", "(", "0.959", "+", "0.959", ")", "+", "(", "0.255", "+", "0.959", ")", ")", "+"};
  char *example = {"acos(0.922)/sqrt(0.600)*asin((0.764-0.764)/(x/0.764))*cos(0.146)*log(0.298)-log((0.959+0.959)+(0.255+0.959))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_11) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"sqrt", "(", "0.433", ")", "+", "asin", "(", "0.46", ")", "+", "actg", "(", "(", "0.118", "/", "0.118", ")", "*", "(", "x", "-", "0.118", ")", ")", "+", "ctg", "(", "0.367", ")", "/", "sqrt", "(", "0.930", ")", "^", "actg", "(", "(", "0.620", "-", "0.620", ")", "-", "(", "x", "+", "0.620", ")", ")", "+", "ln", "(", "0.105", ")", "+", "cos", "(", "0.969", ")", "/", "tan", "(", "(", "0.517", "-", "0.517", ")", "^", "(", "0.577", "-", "0.517", ")", ")", "^", "log", "(", "0.848", ")", "/", "cos", "(", "0.126", ")"};
  char *example = {"sqrt(0.433)+asin(0.46)+actg((0.118/0.118)*(x-0.118))+ctg(0.367)/sqrt(0.930)^actg((0.620-0.620)-(x+0.620))+ln(0.105)+cos(0.969)/tan((0.517-0.517)^(0.577-0.517))^log(0.848)/cos(0.126)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_12) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"941", "%", "617"};
  char *example = {"941%617"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_13) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"log", "(", "0.20", ")", "/", "log", "(", "0.974", ")", "^", "sin", "(", "(", "0.273", "-", "0.273", ")", "-", "(", "x", "+", "0.273", ")", ")", "^", "log", "(", "0.268", ")", "/", "log", "(", "0.473", ")", "^", "ln", "(", "(", "0.195", "+", "0.195", ")", "-", "(", "x", "*", "0.195", ")", ")", "*", "asin", "(", "0.648", ")", "/", "ln", "(", "0.833", ")"};
  char *example = {"log(0.20)/log(0.974)^sin((0.273-0.273)-(x+0.273))^log(0.268)/log(0.473)^ln((0.195+0.195)-(x*0.195))*asin(0.648)/ln(0.833)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_14) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"tan", "(", "0.674", ")", "^", "ctg", "(", "0.119", ")", "+", "log", "(", "(", "0.542", "*", "0.542", ")", "^", "(", "0.116", "+", "0.542", ")", ")", "/", "asin", "(", "0.230", ")", "*", "cos", "(", "0.887", ")"};
  char *example = {"tan(0.674)^ctg(0.119)+log((0.542*0.542)^(0.116+0.542))/asin(0.230)*cos(0.887)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_15) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"actg", "(", "0.7", ")", "+", "asin", "(", "0.488", ")", "^", "sqrt", "(", "(", "0.231", "-", "0.231", ")", "/", "(", "0.781", "^", "0.231", ")", ")", "/", "acos", "(", "0.889", ")", "/", "cos", "(", "0.458", ")", "/", "sqrt", "(", "(", "0.480", "^", "0.480", ")", "*", "(", "0.480", "+", "0.480", ")", ")", "*", "ln", "(", "0.23", ")"};
  char *example = {"actg(0.7)+asin(0.488)^sqrt((0.231-0.231)/(0.781^0.231))/acos(0.889)/cos(0.458)/sqrt((0.480^0.480)*(0.480+0.480))*ln(0.23)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_16) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"sin", "(", "0.154", ")", "-", "acos", "(", "0.164", ")", "-", "actg", "(", "(", "0.738", "+", "0.738", ")", "+", "(", "0.738", "-", "0.738", ")", ")", "*", "log", "(", "0.248", ")", "/", "ctg", "(", "0.69", ")", "^", "ctg", "(", "(", "0.698", "*", "0.698", ")", "+", "(", "0.469", "^", "0.698", ")", ")", "/", "tan", "(", "0.677", ")", "-", "sin", "(", "0.356", ")", "*", "asin", "(", "(", "0.509", "^", "0.509", ")", "+", "(", "0.89", "*", "0.509", ")", ")", "-", "log", "(", "0.819", ")", "+", "log", "(", "0.678", ")", "^", "ln", "(", "(", "0.326", "/", "0.326", ")", "^", "(", "0.326", "-", "0.326", ")", ")", "+", "tan", "(", "0.358", ")", "/", "cos", "(", "0.798", ")"};
  char *example = {"sin(0.154)-acos(0.164)-actg((0.738+0.738)+(0.738-0.738))*log(0.248)/ctg(0.69)^ctg((0.698*0.698)+(0.469^0.698))/tan(0.677)-sin(0.356)*asin((0.509^0.509)+(0.89*0.509))-log(0.819)+log(0.678)^ln((0.326/0.326)^(0.326-0.326))+tan(0.358)/cos(0.798)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_17) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"cos", "(", "0.675", ")", "*", "acos", "(", "0.133", ")", "/", "asin", "(", "(", "0.970", "*", "0.970", ")", "/", "(", "x", "^", "0.970", ")", ")", "-", "sin", "(", "0.124", ")", "-", "sqrt", "(", "0.924", ")", "+", "ln", "(", "(", "0.178", "/", "0.178", ")", "-", "(", "0.371", "/", "0.178", ")", ")", "/", "actg", "(", "0.644", ")", "*", "cos", "(", "0.530", ")", "/", "sin", "(", "(", "0.726", "+", "0.726", ")", "^", "(", "x", "/", "0.726", ")", ")", "-", "ln", "(", "0.387", ")", "+", "acos", "(", "0.321", ")", "+", "acos", "(", "(", "0.399", "+", "0.399", ")", "+", "(", "0.399", "+", "0.399", ")", ")", "-", "acos", "(", "0.922", ")", "*", "asin", "(", "0.101", ")"};
  char *example = {"cos(0.675)*acos(0.133)/asin((0.970*0.970)/(x^0.970))-sin(0.124)-sqrt(0.924)+ln((0.178/0.178)-(0.371/0.178))/actg(0.644)*cos(0.530)/sin((0.726+0.726)^(x/0.726))-ln(0.387)+acos(0.321)+acos((0.399+0.399)+(0.399+0.399))-acos(0.922)*asin(0.101)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_18) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"asin", "(", "0.892", ")", "^", "acos", "(", "0.66", ")", "*", "ln", "(", "(", "0.246", "^", "0.246", ")", "*", "(", "x", "-", "0.246", ")", ")", "^", "tan", "(", "0.842", ")", "/", "sin", "(", "0.318", ")", "/", "ctg", "(", "(", "0.996", "-", "0.996", ")", "^", "(", "x", "-", "0.996", ")", ")", "-", "asin", "(", "0.940", ")", "-", "0.483"};
  char *example = {"asin(0.892)^acos(0.66)*ln((0.246^0.246)*(x-0.246))^tan(0.842)/sin(0.318)/ctg((0.996-0.996)^(x-0.996))-asin(0.940)-0.483"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_19) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"log", "(", "0.190", ")", "-", "log", "(", "0.645", ")", "+", "ctg", "(", "(", "0.544", "*", "0.544", ")", "-", "(", "0.171", "*", "0.544", ")", ")", "+", "tan", "(", "0.205", ")", "/", "ln", "(", "0.113", ")", "*", "tan", "(", "(", "0.290", "^", "0.290", ")", "*", "(", "x", "-", "0.290", ")", ")", "-", "acos", "(", "0.487", ")", "+", "ctg", "(", "0.345", ")", "+", "ln", "(", "(", "0.920", "*", "0.920", ")", "^", "(", "x", "/", "0.920", ")", ")", "^", "sqrt", "(", "0.274", ")", "-", "ctg", "(", "0.164", ")", "/", "cos", "(", "(", "0.891", "*", "0.891", ")", "*", "(", "0.891", "^", "0.891", ")", ")", "/", "ln", "(", "0.157", ")", "/", "ln", "(", "0.798", ")"};
  char *example = {"log(0.190)-log(0.645)+ctg((0.544*0.544)-(0.171*0.544))+tan(0.205)/ln(0.113)*tan((0.290^0.290)*(x-0.290))-acos(0.487)+ctg(0.345)+ln((0.920*0.920)^(x/0.920))^sqrt(0.274)-ctg(0.164)/cos((0.891*0.891)*(0.891^0.891))/ln(0.157)/ln(0.798)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_20) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"actg", "(", "0.742", ")", "*", "actg", "(", "0.59", ")", "-", "ln", "(", "(", "0.998", "^", "0.998", ")", "-", "(", "x", "+", "0.998", ")", ")", "-", "cos", "(", "0.445", ")", "-", "log", "(", "0.620", ")", "/", "sqrt", "(", "(", "0.936", "-", "0.936", ")", "+", "(", "0.936", "/", "0.936", ")", ")", "+", "actg", "(", "0.778", ")", "+", "acos", "(", "0.101", ")", "/", "sin", "(", "(", "0.98", "-", "0.98", ")", "+", "(", "x", "-", "0.98", ")", ")", "^", "sin", "(", "0.260", ")"};
  char *example = {"actg(0.742)*actg(0.59)-ln((0.998^0.998)-(x+0.998))-cos(0.445)-log(0.620)/sqrt((0.936-0.936)+(0.936/0.936))+actg(0.778)+acos(0.101)/sin((0.98-0.98)+(x-0.98))^sin(0.260)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_21) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"actg", "(", "0.609", ")", "+", "cos", "(", "0.293", ")", "-", "ctg", "(", "(", "0.701", "-", "0.701", ")", "-", "(", "x", "+", "0.701", ")", ")", "+", "sqrt", "(", "0.243", ")", "-", "asin", "(", "0.623", ")", "+", "cos", "(", "(", "0.606", "+", "0.606", ")", "^", "(", "0.942", "-", "0.606", ")", ")", "*", "log", "(", "0.230", ")"};
  char *example = {"actg(0.609)+cos(0.293)-ctg((0.701-0.701)-(x+0.701))+sqrt(0.243)-asin(0.623)+cos((0.606+0.606)^(0.942-0.606))*log(0.230)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_22) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"actg", "(", "0.439", ")", "+", "sqrt", "(", "0.375", ")", "/", "cos", "(", "(", "0.183", "/", "0.183", ")", "/", "(", "0.472", "-", "0.183", ")", ")", "/", "cos", "(", "0.472", ")", "+", "0.183"};
  char *example = {"actg(0.439)+sqrt(0.375)/cos((0.183/0.183)/(0.472-0.183))/cos(0.472)+0.183"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_23) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"asin", "(", "0.737", ")", "+", "acos", "(", "0.578", ")", "/", "ln", "(", "(", "0.572", "/", "0.572", ")", "^", "(", "x", "+", "0.572", ")", ")", "+", "sin", "(", "0.138", ")", "/", "acos", "(", "0.575", ")", "-", "atan", "(", "(", "0.783", "+", "0.783", ")", "+", "(", "0.530", "+", "0.783", ")", ")", "-", "ctg", "(", "0.149", ")", "/", "tan", "(", "0.635", ")"};
  char *example = {"asin(0.737)+acos(0.578)/ln((0.572/0.572)^(x+0.572))+sin(0.138)/acos(0.575)-atan((0.783+0.783)+(0.530+0.783))-ctg(0.149)/tan(0.635)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_24) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"ctg", "(", "0.438", ")", "*", "actg", "(", "0.583", ")", "*", "sqrt", "(", "(", "0.934", "*", "0.934", ")", "/", "(", "x", "-", "0.934", ")", ")", "-", "acos", "(", "0.661", ")", "/", "ln", "(", "0.266", ")", "^", "sin", "(", "(", "0.819", "^", "0.819", ")", "+", "(", "x", "-", "0.819", ")", ")", "+", "tan", "(", "0.937", ")", "*", "tan", "(", "0.815", ")", "+", "acos", "(", "(", "0.740", "*", "0.740", ")", "/", "(", "x", "*", "0.740", ")", ")", "^", "log", "(", "0.914", ")", "-", "sin", "(", "0.117", ")", "-", "tan", "(", "(", "0.56", "*", "0.56", ")", "^", "(", "0.56", "+", "0.56", ")", ")", "+", "log", "(", "0.64", ")", "*", "0.828"};
  char *example = {"ctg(0.438)*actg(0.583)*sqrt((0.934*0.934)/(x-0.934))-acos(0.661)/ln(0.266)^sin((0.819^0.819)+(x-0.819))+tan(0.937)*tan(0.815)+acos((0.740*0.740)/(x*0.740))^log(0.914)-sin(0.117)-tan((0.56*0.56)^(0.56+0.56))+log(0.64)*0.828"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_25) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"log", "(", "0.888", ")", "^", "sin", "(", "0.755", ")", "*", "cos", "(", "(", "0.619", "^", "0.619", ")", "*", "(", "x", "*", "0.619", ")", ")", "*", "ctg", "(", "0.261", ")", "/", "actg", "(", "0.258", ")", "^", "sin", "(", "(", "0.19", "*", "0.19", ")", "*", "(", "x", "^", "0.19", ")", ")", "/", "ctg", "(", "0.275", ")", "-", "ln", "(", "0.975", ")", "/", "ln", "(", "(", "0.353", "+", "0.353", ")", "*", "(", "0.353", "+", "0.353", ")", ")", "^", "ln", "(", "0.171", ")", "*", "acos", "(", "0.127", ")"};
  char *example = {"log(0.888)^sin(0.755)*cos((0.619^0.619)*(x*0.619))*ctg(0.261)/actg(0.258)^sin((0.19*0.19)*(x^0.19))/ctg(0.275)-ln(0.975)/ln((0.353+0.353)*(0.353+0.353))^ln(0.171)*acos(0.127)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_26) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"ctg", "(", "0.753", ")", "+", "acos", "(", "0.235", ")", "^", "actg", "(", "(", "0.682", "-", "0.682", ")", "^", "(", "x", "+", "0.682", ")", ")", "-", "asin", "(", "0.340", ")", "/", "sqrt", "(", "0.700", ")", "*", "atan", "(", "(", "0.710", "-", "0.710", ")", "^", "(", "x", "/", "0.710", ")", ")", "*", "tan", "(", "0.285", ")", "*", "cos", "(", "0.180", ")"};
  char *example = {"ctg(0.753)+acos(0.235)^actg((0.682-0.682)^(x+0.682))-asin(0.340)/sqrt(0.700)*atan((0.710-0.710)^(x/0.710))*tan(0.285)*cos(0.180)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_27) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"ln", "(", "0.456", ")", "+", "tan", "(", "0.948", ")", "/", "actg", "(", "(", "0.616", "/", "0.616", ")", "*", "(", "0.616", "+", "0.616", ")", ")", "*", "atan", "(", "0.801", ")", "/", "atan", "(", "0.279", ")", "/", "asin", "(", "(", "0.404", "*", "0.404", ")", "-", "(", "0.404", "/", "0.404", ")", ")", "-", "sin", "(", "0.217", ")", "*", "acos", "(", "0.71", ")"};
  char *example = {"ln(0.456)+tan(0.948)/actg((0.616/0.616)*(0.616+0.616))*atan(0.801)/atan(0.279)/asin((0.404*0.404)-(0.404/0.404))-sin(0.217)*acos(0.71)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_28) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"sqrt", "(", "0.493", ")", "/", "cos", "(", "0.975", ")", "-", "sin", "(", "(", "0.794", "^", "0.794", ")", "-", "(", "0.794", "/", "0.794", ")", ")", "/", "log", "(", "0.583", ")", "*", "sin", "(", "0.517", ")", "/", "tan", "(", "(", "0.263", "/", "0.263", ")", "/", "(", "x", "*", "0.263", ")", ")", "+", "atan", "(", "0.474", ")", "/", "log", "(", "0.330", ")", "*", "acos", "(", "(", "0.825", "*", "0.825", ")", "+", "(", "0.539", "+", "0.825", ")", ")", "*", "log", "(", "0.803", ")"};
  char *example = {"sqrt(0.493)/cos(0.975)-sin((0.794^0.794)-(0.794/0.794))/log(0.583)*sin(0.517)/tan((0.263/0.263)/(x*0.263))+atan(0.474)/log(0.330)*acos((0.825*0.825)+(0.539+0.825))*log(0.803)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_29) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"acos", "(", "0.29", ")", "/", "atan", "(", "0.35", ")", "/", "tan", "(", "(", "0.64", "*", "0.64", ")", "/", "(", "0.64", "/", "0.64", ")", ")", "-", "ctg", "(", "0.510", ")", "+", "atan", "(", "0.905", ")", "+", "cos", "(", "(", "0.414", "-", "0.414", ")", "*", "(", "0.216", "+", "0.414", ")", ")", "+", "sqrt", "(", "0.71", ")", "*", "ln", "(", "0.857", ")", "-", "atan", "(", "(", "0.389", "+", "0.389", ")", "-", "(", "0.389", "*", "0.389", ")", ")", "-", "tan", "(", "0.560", ")", "-", "actg", "(", "0.321", ")", "/", "actg", "(", "(", "0.552", "/", "0.552", ")", "-", "(", "0.374", "+", "0.552", ")", ")", "+", "ctg", "(", "0.52", ")", "+", "0.970"};
  char *example = {"acos(0.29)/atan(0.35)/tan((0.64*0.64)/(0.64/0.64))-ctg(0.510)+atan(0.905)+cos((0.414-0.414)*(0.216+0.414))+sqrt(0.71)*ln(0.857)-atan((0.389+0.389)-(0.389*0.389))-tan(0.560)-actg(0.321)/actg((0.552/0.552)-(0.374+0.552))+ctg(0.52)+0.970"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_30) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"log", "(", "0.229", ")"};
  char *example = {"log(0.229)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_31) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"tan", "(", "0.674", ")", "-", "cos", "(", "0.370", ")", "^", "atan", "(", "(", "0.84", "^", "0.84", ")", "*", "(", "0.388", "-", "0.84", ")", ")", "/", "log", "(", "0.675", ")", "^", "tan", "(", "0.163", ")", "^", "tan", "(", "(", "0.131", "+", "0.131", ")", "*", "(", "0.131", "*", "0.131", ")", ")", "/", "tan", "(", "0.78", ")", "/", "asin", "(", "0.100", ")", "+", "atan", "(", "(", "0.160", "^", "0.160", ")", "/", "(", "0.522", "*", "0.160", ")", ")", "^"};
  char *example = {"tan(0.674)-cos(0.370)^atan((0.84^0.84)*(0.388-0.84))/log(0.675)^tan(0.163)^tan((0.131+0.131)*(0.131*0.131))/tan(0.78)/asin(0.100)+atan((0.160^0.160)/(0.522*0.160))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_32) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"sin", "(", "0.888", ")", "*", "sqrt", "(", "0.431", ")", "/", "log", "(", "(", "0.66", "-", "0.66", ")", "/", "(", "x", "/", "0.66", ")", ")", "*", "actg", "(", "0.905", ")", "^", "cos", "(", "0.56", ")", "*", "sqrt", "(", "(", "0.67", "*", "0.67", ")", "/", "(", "0.177", "/", "0.67", ")", ")", "+", "acos", "(", "0.232", ")", "+", "atan", "(", "0.185", ")"};
  char *example = {"sin(0.888)*sqrt(0.431)/log((0.66-0.66)/(x/0.66))*actg(0.905)^cos(0.56)*sqrt((0.67*0.67)/(0.177/0.67))+acos(0.232)+atan(0.185)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_33) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"atan", "(", "0.303", ")", "+", "ln", "(", "0.281", ")", "-", "sin", "(", "(", "0.929", "-", "0.929", ")", "*", "(", "0.439", "*", "0.929", ")", ")", "*", "cos", "(", "0.903", ")", "^", "atan", "(", "0.181", ")", "/", "tan", "(", "(", "0.895", "*", "0.895", ")", "*", "(", "0.895", "+", "0.895", ")", ")", "+", "log", "(", "0.751", ")", "^", "acos", "(", "0.519", ")", "/", "ln", "(", "(", "0.894", "+", "0.894", ")", "*", "(", "x", "/", "0.894", ")", ")", "+", "acos", "(", "0.812", ")", "/", "tan", "(", "0.695", ")", "^", "acos", "(", "(", "0.935", "-", "0.935", ")", "*", "(", "0.56", "^", "0.935", ")", ")", "-", "asin", "(", "0.133", ")", "^", "atan", "(", "0.411", ")", "*", "ln", "(", "(", "0.876", "^", "0.876", ")", "/", "(", "0.294", "*", "0.876", ")", ")", "^"};
  char *example = {"atan(0.303)+ln(0.281)-sin((0.929-0.929)*(0.439*0.929))*cos(0.903)^atan(0.181)/tan((0.895*0.895)*(0.895+0.895))+log(0.751)^acos(0.519)/ln((0.894+0.894)*(x/0.894))+acos(0.812)/tan(0.695)^acos((0.935-0.935)*(0.56^0.935))-asin(0.133)^atan(0.411)*ln((0.876^0.876)/(0.294*0.876))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_34) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"sin", "(", "0.195", ")", "+", "acos", "(", "0.28", ")", "^", "sin", "(", "(", "0.645", "*", "0.645", ")", "-", "(", "0.645", "+", "0.645", ")", ")", "-", "sqrt", "(", "0.240", ")", "-", "asin", "(", "0.957", ")", "-", "sqrt", "(", "(", "0.812", "+", "0.812", ")", "/", "(", "x", "*", "0.812", ")", ")", "^", "actg", "(", "0.74", ")", "^", "acos", "(", "0.210", ")", "/", "ctg", "(", "(", "0.216", "-", "0.216", ")", "/", "(", "0.216", "/", "0.216", ")", ")", "+", "asin", "(", "0.315", ")", "/", "tan", "(", "0.710", ")", "*", "asin", "(", "(", "0.928", "*", "0.928", ")", "*", "(", "x", "+", "0.928", ")", ")", "+", "actg", "(", "0.221", ")", "^", "atan", "(", "0.499", ")", "*", "ln", "(", "(", "0.402", "^", "0.402", ")", "-", "(", "x", "^", "0.402", ")", ")", "+"};
  char *example = {"sin(0.195)+acos(0.28)^sin((0.645*0.645)-(0.645+0.645))-sqrt(0.240)-asin(0.957)-sqrt((0.812+0.812)/(x*0.812))^actg(0.74)^acos(0.210)/ctg((0.216-0.216)/(0.216/0.216))+asin(0.315)/tan(0.710)*asin((0.928*0.928)*(x+0.928))+actg(0.221)^atan(0.499)*ln((0.402^0.402)-(x^0.402))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_35) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"tan", "(", "0.306", ")", "+", "asin", "(", "0.79", ")", "-", "acos", "(", "(", "0.388", "/", "0.388", ")", "*", "(", "x", "/", "0.388", ")", ")", "^", "asin", "(", "0.313", ")", "-", "sin", "(", "0.964", ")", "*", "atan", "(", "(", "0.767", "/", "0.767", ")", "*", "(", "0.127", "-", "0.767", ")", ")", "/", "ln", "(", "0.215", ")", "*", "sin", "(", "0.1", ")", "-", "atan", "(", "(", "0.917", "+", "0.917", ")", "-", "(", "0.929", "-", "0.917", ")", ")", "^", "atan", "(", "0.944", ")", "+", "0.756"};
  char *example = {"tan(0.306)+asin(0.79)-acos((0.388/0.388)*(x/0.388))^asin(0.313)-sin(0.964)*atan((0.767/0.767)*(0.127-0.767))/ln(0.215)*sin(0.1)-atan((0.917+0.917)-(0.929-0.917))^atan(0.944)+0.756"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_36) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"tan", "(", "0.126", ")", "^", "tan", "(", "0.263", ")", "/", "sin", "(", "(", "0.968", "/", "0.968", ")", "-", "(", "0.496", "^", "0.968", ")", ")", "-", "ctg", "(", "0.477", ")", "/", "0.144"};
  char *example = {"tan(0.126)^tan(0.263)/sin((0.968/0.968)-(0.496^0.968))-ctg(0.477)/0.144"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_37) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"atan", "(", "0.600", ")", "-", "sqrt", "(", "0.668", ")", "/", "sqrt", "(", "(", "0.747", "-", "0.747", ")", "-", "(", "0.280", "/", "0.747", ")", ")", "-", "cos", "(", "0.3", ")"};
  char *example = {"atan(0.600)-sqrt(0.668)/sqrt((0.747-0.747)-(0.280/0.747))-cos(0.3)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_38) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"log", "(", "0.569", ")", "^", "acos", "(", "0.677", ")", "/", "sin", "(", "(", "0.23", "+", "0.23", ")", "^", "(", "x", "/", "0.23", ")", ")", "-", "cos", "(", "0.812", ")", "+", "sin", "(", "0.878", ")", "-", "log", "(", "(", "0.283", "/", "0.283", ")", "/", "(", "0.283", "-", "0.283", ")", ")", "*", "acos", "(", "0.718", ")", "-", "sin", "(", "0.123", ")", "*", "actg", "(", "(", "0.639", "/", "0.639", ")", "^", "(", "0.674", "*", "0.639", ")", ")", "+", "log", "(", "0.971", ")", "/", "sqrt", "(", "0.332", ")", "/", "ln", "(", "(", "0.396", "*", "0.396", ")", "+", "(", "x", "*", "0.396", ")", ")", "-", "cos", "(", "0.469", ")", "-", "0.343"};
  char *example = {"log(0.569)^acos(0.677)/sin((0.23+0.23)^(x/0.23))-cos(0.812)+sin(0.878)-log((0.283/0.283)/(0.283-0.283))*acos(0.718)-sin(0.123)*actg((0.639/0.639)^(0.674*0.639))+log(0.971)/sqrt(0.332)/ln((0.396*0.396)+(x*0.396))-cos(0.469)-0.343"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_39) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"asin", "(", "0.310", ")", "-", "asin", "(", "0.592", ")", "*", "acos", "(", "(", "0.546", "-", "0.546", ")", "-", "(", "0.546", "^", "0.546", ")", ")", "-", "actg", "(", "0.61", ")"};
  char *example = {"asin(0.310)-asin(0.592)*acos((0.546-0.546)-(0.546^0.546))-actg(0.61)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_40) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"actg", "(", "0.229", ")", "-", "atan", "(", "0.654", ")", "+", "tan", "(", "(", "0.448", "+", "0.448", ")", "/", "(", "0.448", "/", "0.448", ")", ")", "/", "sin", "(", "0.815", ")", "/", "ctg", "(", "0.460", ")", "/", "asin", "(", "(", "0.379", "+", "0.379", ")", "+", "(", "0.722", "/", "0.379", ")", ")", "-", "sin", "(", "0.885", ")", "*", "sqrt", "(", "0.809", ")", "/", "actg", "(", "(", "0.286", "/", "0.286", ")", "^", "(", "0.286", "+", "0.286", ")", ")", "-"};
  char *example = {"actg(0.229)-atan(0.654)+tan((0.448+0.448)/(0.448/0.448))/sin(0.815)/ctg(0.460)/asin((0.379+0.379)+(0.722/0.379))-sin(0.885)*sqrt(0.809)/actg((0.286/0.286)^(0.286+0.286))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_41) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"793", "%", "689"};
  char *example = {"793%689"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_42) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"ln", "(", "0.428", ")", "*", "tan", "(", "0.12", ")", "/", "sqrt", "(", "(", "0.613", "/", "0.613", ")", "-", "(", "0.613", "/", "0.613", ")", ")", "^", "asin", "(", "0.827", ")", "^", "cos", "(", "0.60", ")", "/", "actg", "(", "(", "0.984", "*", "0.984", ")", "*", "(", "0.333", "/", "0.984", ")", ")", "+", "atan", "(", "0.212", ")", "^", "log", "(", "0.485", ")", "+", "cos", "(", "(", "0.16", "^", "0.16", ")", "^", "(", "x", "+", "0.16", ")", ")", "*", "log", "(", "0.223", ")", "/", "acos", "(", "0.734", ")", "-", "sqrt", "(", "(", "0.488", "/", "0.488", ")", "+", "(", "0.169", "-", "0.488", ")", ")", "-", "cos", "(", "0.510", ")"};
  char *example = {"ln(0.428)*tan(0.12)/sqrt((0.613/0.613)-(0.613/0.613))^asin(0.827)^cos(0.60)/actg((0.984*0.984)*(0.333/0.984))+atan(0.212)^log(0.485)+cos((0.16^0.16)^(x+0.16))*log(0.223)/acos(0.734)-sqrt((0.488/0.488)+(0.169-0.488))-cos(0.510)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_43) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"448", "%", "893"};
  char *example = {"448%893"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_44) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"tan", "(", "0.254", ")", "/", "log", "(", "0.709", ")", "-", "asin", "(", "(", "0.310", "*", "0.310", ")", "/", "(", "x", "/", "0.310", ")", ")", "*", "asin", "(", "0.288", ")", "/", "cos", "(", "0.194", ")", "/", "tan", "(", "(", "0.890", "/", "0.890", ")", "^", "(", "0.878", "-", "0.890", ")", ")", "*", "atan", "(", "0.533", ")", "+", "tan", "(", "0.181", ")", "^", "sqrt", "(", "(", "0.1", "*", "0.1", ")", "-", "(", "0.1", "-", "0.1", ")", ")", "^", "tan", "(", "0.981", ")", "*", "ln", "(", "0.357", ")", "*", "cos", "(", "(", "0.848", "*", "0.848", ")", "*", "(", "x", "^", "0.848", ")", ")", "-", "sin", "(", "0.343", ")", "-", "ctg", "(", "0.964", ")", "^", "cos", "(", "(", "0.681", "-", "0.681", ")", "+", "(", "x", "-", "0.681", ")", ")", "^"};
  char *example = {"tan(0.254)/log(0.709)-asin((0.310*0.310)/(x/0.310))*asin(0.288)/cos(0.194)/tan((0.890/0.890)^(0.878-0.890))*atan(0.533)+tan(0.181)^sqrt((0.1*0.1)-(0.1-0.1))^tan(0.981)*ln(0.357)*cos((0.848*0.848)*(x^0.848))-sin(0.343)-ctg(0.964)^cos((0.681-0.681)+(x-0.681))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_45) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"266", "%", "930"};
  char *example = {"266%930"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_46) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"log", "(", "0.749", ")", "^", "acos", "(", "0.711", ")", "-", "asin", "(", "(", "0.198", "^", "0.198", ")", "^", "(", "x", "*", "0.198", ")", ")", "-", "ln", "(", "0.789", ")", "*", "log", "(", "0.941", ")", "*", "cos", "(", "(", "0.59", "-", "0.59", ")", "*", "(", "0.59", "/", "0.59", ")", ")", "-", "cos", "(", "0.963", ")"};
  char *example = {"log(0.749)^acos(0.711)-asin((0.198^0.198)^(x*0.198))-ln(0.789)*log(0.941)*cos((0.59-0.59)*(0.59/0.59))-cos(0.963)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_47) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"ln", "(", "0.489", ")", "-", "cos", "(", "0.289", ")", "/", "sqrt", "(", "(", "0.793", "+", "0.793", ")", "/", "(", "x", "*", "0.793", ")", ")", "+", "tan", "(", "0.760", ")", "+", "tan", "(", "0.34", ")", "*", "sqrt", "(", "(", "0.217", "+", "0.217", ")", "/", "(", "x", "^", "0.217", ")", ")", "^", "sqrt", "(", "0.662", ")", "/", "ln", "(", "0.136", ")", "^", "cos", "(", "(", "0.231", "-", "0.231", ")", "+", "(", "0.231", "/", "0.231", ")", ")", "-", "sqrt", "(", "0.673", ")", "/", "acos", "(", "0.863", ")", "*", "ln", "(", "(", "0.79", "-", "0.79", ")", "+", "(", "0.850", "-", "0.79", ")", ")", "+", "atan", "(", "0.279", ")", "/", "cos", "(", "0.548", ")", "-", "tan", "(", "(", "0.959", "-", "0.959", ")", "+", "(", "0.959", "+", "0.959", ")", ")", "+"};
  char *example = {"ln(0.489)-cos(0.289)/sqrt((0.793+0.793)/(x*0.793))+tan(0.760)+tan(0.34)*sqrt((0.217+0.217)/(x^0.217))^sqrt(0.662)/ln(0.136)^cos((0.231-0.231)+(0.231/0.231))-sqrt(0.673)/acos(0.863)*ln((0.79-0.79)+(0.850-0.79))+atan(0.279)/cos(0.548)-tan((0.959-0.959)+(0.959+0.959))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_48) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"acos", "(", "0.746", ")", "*", "actg", "(", "0.984", ")", "/", "acos", "(", "(", "0.472", "/", "0.472", ")", "-", "(", "x", "^", "0.472", ")", ")", "^", "ln", "(", "0.40", ")", "-", "ln", "(", "0.626", ")", "*", "cos", "(", "(", "0.783", "*", "0.783", ")", "^", "(", "0.783", "-", "0.783", ")", ")", "*", "ctg", "(", "0.347", ")", "-", "log", "(", "0.2", ")", "-", "acos", "(", "(", "0.142", "^", "0.142", ")", "+", "(", "0.142", "^", "0.142", ")", ")", "+", "asin", "(", "0.339", ")", "^", "sqrt", "(", "0.113", ")", "-", "actg", "(", "(", "0.888", "^", "0.888", ")", "*", "(", "0.888", "/", "0.888", ")", ")", "+", "ln", "(", "0.939", ")", "+", "ctg", "(", "0.812", ")", "+", "sqrt", "(", "(", "0.103", "-", "0.103", ")", "/", "(", "x", "^", "0.103", ")", ")", "-"};
  char *example = {"acos(0.746)*actg(0.984)/acos((0.472/0.472)-(x^0.472))^ln(0.40)-ln(0.626)*cos((0.783*0.783)^(0.783-0.783))*ctg(0.347)-log(0.2)-acos((0.142^0.142)+(0.142^0.142))+asin(0.339)^sqrt(0.113)-actg((0.888^0.888)*(0.888/0.888))+ln(0.939)+ctg(0.812)+sqrt((0.103-0.103)/(x^0.103))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_49) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"log", "(", "0.244", ")"};
  char *example = {"log(0.244)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_50) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"ctg", "(", "0.882", ")", "/", "sin", "(", "0.52", ")", "^", "actg", "(", "(", "0.683", "-", "0.683", ")", "/", "(", "x", "-", "0.683", ")", ")", "/", "sqrt", "(", "0.416", ")", "+", "actg", "(", "0.763", ")", "/", "cos", "(", "(", "0.970", "/", "0.970", ")", "-", "(", "0.729", "*", "0.970", ")", ")", "-", "ctg", "(", "0.949", ")", "+", "acos", "(", "0.757", ")", "/", "ctg", "(", "(", "0.111", "/", "0.111", ")", "/", "(", "x", "/", "0.111", ")", ")", "*", "acos", "(", "0.678", ")", "^", "0.329"};
  char *example = {"ctg(0.882)/sin(0.52)^actg((0.683-0.683)/(x-0.683))/sqrt(0.416)+actg(0.763)/cos((0.970/0.970)-(0.729*0.970))-ctg(0.949)+acos(0.757)/ctg((0.111/0.111)/(x/0.111))*acos(0.678)^0.329"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_51) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"log", "(", "0.181", ")", "/", "atan", "(", "0.177", ")", "^", "asin", "(", "(", "0.455", "*", "0.455", ")", "-", "(", "0.455", "-", "0.455", ")", ")", "-", "tan", "(", "0.126", ")", "+", "acos", "(", "0.704", ")", "/", "asin", "(", "(", "0.578", "-", "0.578", ")", "+", "(", "x", "+", "0.578", ")", ")", "/", "atan", "(", "0.41", ")", "/", "actg", "(", "0.695", ")", "/", "tan", "(", "(", "0.38", "-", "0.38", ")", "+", "(", "0.38", "^", "0.38", ")", ")", "*", "actg", "(", "0.215", ")", "^", "tan", "(", "0.981", ")", "/", "ln", "(", "(", "0.516", "+", "0.516", ")", "+", "(", "0.668", "/", "0.516", ")", ")", "^", "sin", "(", "0.97", ")"};
  char *example = {"log(0.181)/atan(0.177)^asin((0.455*0.455)-(0.455-0.455))-tan(0.126)+acos(0.704)/asin((0.578-0.578)+(x+0.578))/atan(0.41)/actg(0.695)/tan((0.38-0.38)+(0.38^0.38))*actg(0.215)^tan(0.981)/ln((0.516+0.516)+(0.668/0.516))^sin(0.97)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_52) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"sqrt", "(", "0.651", ")", "+", "tan", "(", "0.514", ")", "/", "acos", "(", "(", "0.455", "^", "0.455", ")", "*", "(", "0.596", "-", "0.455", ")", ")", "-", "atan", "(", "0.18", ")", "^", "ln", "(", "0.332", ")", "-", "acos", "(", "(", "0.13", "*", "0.13", ")", "^", "(", "x", "*", "0.13", ")", ")", "/"};
  char *example = {"sqrt(0.651)+tan(0.514)/acos((0.455^0.455)*(0.596-0.455))-atan(0.18)^ln(0.332)-acos((0.13*0.13)^(x*0.13))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_53) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"cos", "(", "0.576", ")", "-", "atan", "(", "0.511", ")", "/", "ln", "(", "(", "0.220", "-", "0.220", ")", "*", "(", "0.220", "+", "0.220", ")", ")", "-", "asin", "(", "0.481", ")", "+", "tan", "(", "0.706", ")", "^", "tan", "(", "(", "0.666", "+", "0.666", ")", "/", "(", "0.522", "^", "0.666", ")", ")", "*", "asin", "(", "0.665", ")", "/", "ctg", "(", "0.11", ")"};
  char *example = {"cos(0.576)-atan(0.511)/ln((0.220-0.220)*(0.220+0.220))-asin(0.481)+tan(0.706)^tan((0.666+0.666)/(0.522^0.666))*asin(0.665)/ctg(0.11)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_54) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"asin", "(", "0.621", ")", "^", "actg", "(", "0.38", ")", "+", "ln", "(", "(", "0.351", "*", "0.351", ")", "+", "(", "0.351", "/", "0.351", ")", ")", "^", "sqrt", "(", "0.44", ")", "/", "atan", "(", "0.552", ")", "^", "tan", "(", "(", "0.290", "*", "0.290", ")", "*", "(", "0.290", "/", "0.290", ")", ")", "^", "atan", "(", "0.521", ")", "-", "cos", "(", "0.764", ")", "-", "log", "(", "(", "0.177", "^", "0.177", ")", "^", "(", "x", "*", "0.177", ")", ")", "-", "cos", "(", "0.4", ")", "/", "sin", "(", "0.664", ")"};
  char *example = {"asin(0.621)^actg(0.38)+ln((0.351*0.351)+(0.351/0.351))^sqrt(0.44)/atan(0.552)^tan((0.290*0.290)*(0.290/0.290))^atan(0.521)-cos(0.764)-log((0.177^0.177)^(x*0.177))-cos(0.4)/sin(0.664)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_55) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"tan", "(", "0.531", ")", "^", "sqrt", "(", "0.857", ")", "+", "ctg", "(", "(", "0.929", "+", "0.929", ")", "+", "(", "0.739", "*", "0.929", ")", ")", "-", "ln", "(", "0.301", ")", "-", "tan", "(", "0.352", ")", "+", "actg", "(", "(", "0.816", "-", "0.816", ")", "-", "(", "0.862", "^", "0.816", ")", ")", "-", "actg", "(", "0.224", ")", "^", "tan", "(", "0.152", ")", "*", "cos", "(", "(", "0.453", "-", "0.453", ")", "*", "(", "x", "+", "0.453", ")", ")", "^", "tan", "(", "0.42", ")", "*", "atan", "(", "0.739", ")", "+", "actg", "(", "(", "0.237", "/", "0.237", ")", "^", "(", "x", "+", "0.237", ")", ")", "*", "cos", "(", "0.936", ")", "/", "atan", "(", "0.886", ")", "+", "sqrt", "(", "(", "0.510", "/", "0.510", ")", "^", "(", "0.510", "/", "0.510", ")", ")", "-"};
  char *example = {"tan(0.531)^sqrt(0.857)+ctg((0.929+0.929)+(0.739*0.929))-ln(0.301)-tan(0.352)+actg((0.816-0.816)-(0.862^0.816))-actg(0.224)^tan(0.152)*cos((0.453-0.453)*(x+0.453))^tan(0.42)*atan(0.739)+actg((0.237/0.237)^(x+0.237))*cos(0.936)/atan(0.886)+sqrt((0.510/0.510)^(0.510/0.510))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_56) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"cos", "(", "0.980", ")", "+", "actg", "(", "0.702", ")", "-", "log", "(", "(", "0.416", "/", "0.416", ")", "-", "(", "x", "-", "0.416", ")", ")", "*", "asin", "(", "0.918", ")"};
  char *example = {"cos(0.980)+actg(0.702)-log((0.416/0.416)-(x-0.416))*asin(0.918)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_57) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"actg", "(", "0.605", ")", "/", "0.772"};
  char *example = {"actg(0.605)/0.772"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_58) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"tan", "(", "0.639", ")", "/", "atan", "(", "0.263", ")", "^", "asin", "(", "(", "0.649", "/", "0.649", ")", "+", "(", "x", "^", "0.649", ")", ")", "*", "atan", "(", "0.695", ")", "-", "0.465"};
  char *example = {"tan(0.639)/atan(0.263)^asin((0.649/0.649)+(x^0.649))*atan(0.695)-0.465"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_59) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"cos", "(", "0.530", ")", "-", "log", "(", "0.49", ")", "+", "ctg", "(", "(", "0.567", "/", "0.567", ")", "*", "(", "x", "/", "0.567", ")", ")", "+", "actg", "(", "0.16", ")"};
  char *example = {"cos(0.530)-log(0.49)+ctg((0.567/0.567)*(x/0.567))+actg(0.16)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_60) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"ln", "(", "0.407", ")", "-", "sqrt", "(", "0.265", ")", "-", "ln", "(", "(", "0.973", "-", "0.973", ")", "+", "(", "0.973", "^", "0.973", ")", ")", "^", "log", "(", "0.653", ")", "+", "log", "(", "0.823", ")", "^", "actg", "(", "(", "0.169", "/", "0.169", ")", "/", "(", "x", "/", "0.169", ")", ")", "^", "acos", "(", "0.612", ")", "-", "atan", "(", "0.598", ")", "^", "sqrt", "(", "(", "0.690", "*", "0.690", ")", "/", "(", "0.129", "*", "0.690", ")", ")", "/", "log", "(", "0.711", ")", "/", "0.565"};
  char *example = {"ln(0.407)-sqrt(0.265)-ln((0.973-0.973)+(0.973^0.973))^log(0.653)+log(0.823)^actg((0.169/0.169)/(x/0.169))^acos(0.612)-atan(0.598)^sqrt((0.690*0.690)/(0.129*0.690))/log(0.711)/0.565"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_61) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"sin", "(", "0.897", ")", "+", "acos", "(", "0.219", ")", "*", "tan", "(", "(", "0.88", "/", "0.88", ")", "/", "(", "x", "^", "0.88", ")", ")", "-", "acos", "(", "0.81", ")", "*", "sin", "(", "0.396", ")", "*", "asin", "(", "(", "0.281", "/", "0.281", ")", "^", "(", "0.281", "^", "0.281", ")", ")", "/", "atan", "(", "0.273", ")", "+", "log", "(", "0.586", ")", "*", "cos", "(", "(", "0.568", "+", "0.568", ")", "/", "(", "0.568", "*", "0.568", ")", ")", "*"};
  char *example = {"sin(0.897)+acos(0.219)*tan((0.88/0.88)/(x^0.88))-acos(0.81)*sin(0.396)*asin((0.281/0.281)^(0.281^0.281))/atan(0.273)+log(0.586)*cos((0.568+0.568)/(0.568*0.568))*"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_62) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"tan", "(", "0.470", ")", "/", "cos", "(", "0.199", ")", "/", "ln", "(", "(", "0.469", "-", "0.469", ")", "+", "(", "0.469", "^", "0.469", ")", ")", "-", "asin", "(", "0.967", ")", "-", "tan", "(", "0.967", ")", "+", "tan", "(", "(", "0.96", "*", "0.96", ")", "-", "(", "0.96", "+", "0.96", ")", ")", "*", "acos", "(", "0.110", ")"};
  char *example = {"tan(0.470)/cos(0.199)/ln((0.469-0.469)+(0.469^0.469))-asin(0.967)-tan(0.967)+tan((0.96*0.96)-(0.96+0.96))*acos(0.110)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_63) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"log", "(", "0.6", ")", "/", "sqrt", "(", "0.260", ")", "/", "ctg", "(", "(", "0.434", "+", "0.434", ")", "/", "(", "0.434", "^", "0.434", ")", ")", "^", "sin", "(", "0.79", ")", "+", "tan", "(", "0.812", ")", "-", "sin", "(", "(", "0.378", "+", "0.378", ")", "*", "(", "0.316", "/", "0.378", ")", ")", "+", "acos", "(", "0.502", ")", "/", "ln", "(", "0.697", ")", "*", "acos", "(", "(", "0.942", "/", "0.942", ")", "*", "(", "x", "^", "0.942", ")", ")", "*", "atan", "(", "0.686", ")", "+", "cos", "(", "0.310", ")", "/", "ln", "(", "(", "0.42", "*", "0.42", ")", "/", "(", "x", "+", "0.42", ")", ")", "+", "ln", "(", "0.80", ")"};
  char *example = {"log(0.6)/sqrt(0.260)/ctg((0.434+0.434)/(0.434^0.434))^sin(0.79)+tan(0.812)-sin((0.378+0.378)*(0.316/0.378))+acos(0.502)/ln(0.697)*acos((0.942/0.942)*(x^0.942))*atan(0.686)+cos(0.310)/ln((0.42*0.42)/(x+0.42))+ln(0.80)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_64) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"log", "(", "0.404", ")", "/", "log", "(", "0.28", ")", "*", "sqrt", "(", "(", "0.905", "-", "0.905", ")", "/", "(", "0.851", "+", "0.905", ")", ")", "+", "asin", "(", "0.768", ")", "^", "acos", "(", "0.620", ")", "-", "sin", "(", "(", "0.902", "-", "0.902", ")", "^", "(", "0.902", "/", "0.902", ")", ")", "^", "atan", "(", "0.620", ")", "/", "sin", "(", "0.180", ")", "*", "ln", "(", "(", "0.166", "*", "0.166", ")", "*", "(", "x", "+", "0.166", ")", ")", "+", "actg", "(", "0.909", ")", "/", "acos", "(", "0.53", ")", "/", "tan", "(", "(", "0.543", "/", "0.543", ")", "-", "(", "0.551", "^", "0.543", ")", ")", "+", "asin", "(", "0.257", ")", "*", "ln", "(", "0.715", ")"};
  char *example = {"log(0.404)/log(0.28)*sqrt((0.905-0.905)/(0.851+0.905))+asin(0.768)^acos(0.620)-sin((0.902-0.902)^(0.902/0.902))^atan(0.620)/sin(0.180)*ln((0.166*0.166)*(x+0.166))+actg(0.909)/acos(0.53)/tan((0.543/0.543)-(0.551^0.543))+asin(0.257)*ln(0.715)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_65) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"log", "(", "0.788", ")", "^", "atan", "(", "0.269", ")", "+", "log", "(", "(", "0.753", "-", "0.753", ")", "/", "(", "x", "+", "0.753", ")", ")", "-", "atan", "(", "0.934", ")"};
  char *example = {"log(0.788)^atan(0.269)+log((0.753-0.753)/(x+0.753))-atan(0.934)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_66) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"asin", "(", "0.193", ")", "-", "log", "(", "0.860", ")", "/", "ctg", "(", "(", "0.652", "*", "0.652", ")", "-", "(", "x", "*", "0.652", ")", ")", "*", "sqrt", "(", "0.715", ")", "/", "atan", "(", "0.456", ")", "*", "asin", "(", "(", "0.641", "*", "0.641", ")", "^", "(", "x", "-", "0.641", ")", ")", "*", "cos", "(", "0.69", ")", "/", "0.428"};
  char *example = {"asin(0.193)-log(0.860)/ctg((0.652*0.652)-(x*0.652))*sqrt(0.715)/atan(0.456)*asin((0.641*0.641)^(x-0.641))*cos(0.69)/0.428"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_67) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"actg", "(", "0.445", ")", "*", "cos", "(", "0.484", ")", "/", "log", "(", "(", "0.18", "-", "0.18", ")", "*", "(", "x", "/", "0.18", ")", ")", "-", "ln", "(", "0.451", ")", "*", "log", "(", "0.977", ")", "*", "log", "(", "(", "0.174", "-", "0.174", ")", "-", "(", "0.174", "/", "0.174", ")", ")", "/", "sin", "(", "0.141", ")", "*", "acos", "(", "0.991", ")", "*", "atan", "(", "(", "0.321", "^", "0.321", ")", "+", "(", "0.515", "+", "0.321", ")", ")", "/"};
  char *example = {"actg(0.445)*cos(0.484)/log((0.18-0.18)*(x/0.18))-ln(0.451)*log(0.977)*log((0.174-0.174)-(0.174/0.174))/sin(0.141)*acos(0.991)*atan((0.321^0.321)+(0.515+0.321))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_68) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"asin", "(", "0.650", ")", "-", "sin", "(", "0.495", ")", "^", "tan", "(", "(", "0.998", "^", "0.998", ")", "/", "(", "x", "-", "0.998", ")", ")", "/", "acos", "(", "0.573", ")", "+", "actg", "(", "0.894", ")", "+", "actg", "(", "(", "0.119", "*", "0.119", ")", "*", "(", "0.449", "^", "0.119", ")", ")", "*"};
  char *example = {"asin(0.650)-sin(0.495)^tan((0.998^0.998)/(x-0.998))/acos(0.573)+actg(0.894)+actg((0.119*0.119)*(0.449^0.119))*"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_69) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"log", "(", "0.439", ")", "*", "sqrt", "(", "0.120", ")", "^", "sin", "(", "(", "0.197", "+", "0.197", ")", "^", "(", "0.197", "^", "0.197", ")", ")", "/", "atan", "(", "0.13", ")", "+", "tan", "(", "0.902", ")", "/", "tan", "(", "(", "0.929", "/", "0.929", ")", "*", "(", "0.327", "*", "0.929", ")", ")", "*", "atan", "(", "0.851", ")", "*", "ln", "(", "0.495", ")"};
  char *example = {"log(0.439)*sqrt(0.120)^sin((0.197+0.197)^(0.197^0.197))/atan(0.13)+tan(0.902)/tan((0.929/0.929)*(0.327*0.929))*atan(0.851)*ln(0.495)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_70) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"tan", "(", "0.822", ")", "^", "cos", "(", "0.305", ")", "+", "ln", "(", "(", "0.491", "+", "0.491", ")", "+", "(", "0.196", "/", "0.491", ")", ")", "*", "acos", "(", "0.181", ")", "+", "sqrt", "(", "0.14", ")", "*", "cos", "(", "(", "0.137", "+", "0.137", ")", "*", "(", "0.576", "+", "0.137", ")", ")", "^"};
  char *example = {"tan(0.822)^cos(0.305)+ln((0.491+0.491)+(0.196/0.491))*acos(0.181)+sqrt(0.14)*cos((0.137+0.137)*(0.576+0.137))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_71) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"ctg", "(", "0.968", ")", "+", "ctg", "(", "0.136", ")", "^", "log", "(", "(", "0.131", "*", "0.131", ")", "+", "(", "x", "-", "0.131", ")", ")", "/", "sqrt", "(", "0.201", ")", "/", "0.924"};
  char *example = {"ctg(0.968)+ctg(0.136)^log((0.131*0.131)+(x-0.131))/sqrt(0.201)/0.924"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_72) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"tan", "(", "0.196", ")", "+", "atan", "(", "0.862", ")", "+", "atan", "(", "(", "0.366", "/", "0.366", ")", "*", "(", "x", "^", "0.366", ")", ")", "-", "atan", "(", "0.453", ")", "-", "sin", "(", "0.605", ")"};
  char *example = {"tan(0.196)+atan(0.862)+atan((0.366/0.366)*(x^0.366))-atan(0.453)-sin(0.605)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_73) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"ln", "(", "0.675", ")", "^", "ctg", "(", "0.599", ")", "+", "log", "(", "(", "0.996", "+", "0.996", ")", "/", "(", "0.996", "*", "0.996", ")", ")", "+", "cos", "(", "0.165", ")", "/", "tan", "(", "0.342", ")", "*", "sin", "(", "(", "0.91", "/", "0.91", ")", "-", "(", "x", "-", "0.91", ")", ")", "^", "ctg", "(", "0.650", ")", "/", "ln", "(", "0.140", ")", "/", "ln", "(", "(", "0.850", "-", "0.850", ")", "*", "(", "0.924", "*", "0.850", ")", ")", "^", "sqrt", "(", "0.859", ")", "/", "ctg", "(", "0.851", ")", "^", "sqrt", "(", "(", "0.122", "/", "0.122", ")", "^", "(", "x", "-", "0.122", ")", ")", "^", "atan", "(", "0.831", ")", "+", "ln", "(", "0.724", ")", "+", "cos", "(", "(", "0.264", "+", "0.264", ")", "^", "(", "x", "^", "0.264", ")", ")", "+"};
  char *example = {"ln(0.675)^ctg(0.599)+log((0.996+0.996)/(0.996*0.996))+cos(0.165)/tan(0.342)*sin((0.91/0.91)-(x-0.91))^ctg(0.650)/ln(0.140)/ln((0.850-0.850)*(0.924*0.850))^sqrt(0.859)/ctg(0.851)^sqrt((0.122/0.122)^(x-0.122))^atan(0.831)+ln(0.724)+cos((0.264+0.264)^(x^0.264))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_74) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"ln", "(", "0.784", ")", "-", "actg", "(", "0.301", ")", "^", "actg", "(", "(", "0.105", "/", "0.105", ")", "*", "(", "0.447", "-", "0.105", ")", ")", "/", "tan", "(", "0.191", ")", "^", "cos", "(", "0.191", ")", "-", "atan", "(", "(", "0.300", "/", "0.300", ")", "-", "(", "0.803", "^", "0.300", ")", ")", "*", "asin", "(", "0.163", ")", "^", "ctg", "(", "0.129", ")", "^", "log", "(", "(", "0.539", "/", "0.539", ")", "^", "(", "0.539", "/", "0.539", ")", ")", "/", "actg", "(", "0.846", ")", "*", "sin", "(", "0.460", ")", "/", "log", "(", "(", "0.120", "^", "0.120", ")", "-", "(", "0.958", "-", "0.120", ")", ")", "/", "actg", "(", "0.844", ")"};
  char *example = {"ln(0.784)-actg(0.301)^actg((0.105/0.105)*(0.447-0.105))/tan(0.191)^cos(0.191)-atan((0.300/0.300)-(0.803^0.300))*asin(0.163)^ctg(0.129)^log((0.539/0.539)^(0.539/0.539))/actg(0.846)*sin(0.460)/log((0.120^0.120)-(0.958-0.120))/actg(0.844)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_75) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"cos", "(", "0.855", ")", "/", "asin", "(", "0.51", ")", "^", "atan", "(", "(", "0.573", "*", "0.573", ")", "*", "(", "x", "-", "0.573", ")", ")", "/", "sqrt", "(", "0.215", ")", "-", "ctg", "(", "0.709", ")", "*", "actg", "(", "(", "0.329", "*", "0.329", ")", "^", "(", "x", "-", "0.329", ")", ")", "^", "ctg", "(", "0.576", ")", "^", "asin", "(", "0.166", ")", "-", "sin", "(", "(", "0.823", "/", "0.823", ")", "^", "(", "x", "/", "0.823", ")", ")", "*", "actg", "(", "0.584", ")", "^", "tan", "(", "0.127", ")", "/", "ln", "(", "(", "0.322", "/", "0.322", ")", "^", "(", "x", "+", "0.322", ")", ")", "*", "atan", "(", "0.417", ")", "*", "atan", "(", "0.262", ")"};
  char *example = {"cos(0.855)/asin(0.51)^atan((0.573*0.573)*(x-0.573))/sqrt(0.215)-ctg(0.709)*actg((0.329*0.329)^(x-0.329))^ctg(0.576)^asin(0.166)-sin((0.823/0.823)^(x/0.823))*actg(0.584)^tan(0.127)/ln((0.322/0.322)^(x+0.322))*atan(0.417)*atan(0.262)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_76) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"atan", "(", "0.633", ")", "^", "sin", "(", "0.923", ")", "+", "actg", "(", "(", "0.337", "+", "0.337", ")", "*", "(", "0.337", "+", "0.337", ")", ")", "^", "sqrt", "(", "0.755", ")", "+", "asin", "(", "0.475", ")", "/", "cos", "(", "(", "0.550", "+", "0.550", ")", "*", "(", "0.27", "^", "0.550", ")", ")", "*", "actg", "(", "0.691", ")", "-", "cos", "(", "0.771", ")", "/", "ctg", "(", "(", "0.288", "^", "0.288", ")", "-", "(", "x", "^", "0.288", ")", ")", "+", "tan", "(", "0.179", ")", "+", "0.80"};
  char *example = {"atan(0.633)^sin(0.923)+actg((0.337+0.337)*(0.337+0.337))^sqrt(0.755)+asin(0.475)/cos((0.550+0.550)*(0.27^0.550))*actg(0.691)-cos(0.771)/ctg((0.288^0.288)-(x^0.288))+tan(0.179)+0.80"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_77) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"actg", "(", "0.623", ")", "-", "ctg", "(", "0.998", ")", "-", "actg", "(", "(", "0.810", "/", "0.810", ")", "/", "(", "0.511", "+", "0.810", ")", ")", "/", "sqrt", "(", "0.838", ")", "+", "ctg", "(", "0.143", ")", "*", "sqrt", "(", "(", "0.892", "*", "0.892", ")", "*", "(", "0.892", "/", "0.892", ")", ")", "^", "asin", "(", "0.408", ")", "-", "tan", "(", "0.385", ")"};
  char *example = {"actg(0.623)-ctg(0.998)-actg((0.810/0.810)/(0.511+0.810))/sqrt(0.838)+ctg(0.143)*sqrt((0.892*0.892)*(0.892/0.892))^asin(0.408)-tan(0.385)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_78) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"sin", "(", "0.498", ")", "-", "acos", "(", "0.209", ")", "-", "atan", "(", "(", "0.830", "-", "0.830", ")", "/", "(", "0.714", "/", "0.830", ")", ")", "^", "actg", "(", "0.496", ")", "*", "tan", "(", "0.359", ")", "^", "sin", "(", "(", "0.500", "*", "0.500", ")", "/", "(", "x", "^", "0.500", ")", ")", "/", "sin", "(", "0.591", ")", "+", "ln", "(", "0.756", ")", "-", "actg", "(", "(", "0.212", "*", "0.212", ")", "+", "(", "0.212", "-", "0.212", ")", ")", "-", "log", "(", "0.9", ")", "/", "atan", "(", "0.230", ")"};
  char *example = {"sin(0.498)-acos(0.209)-atan((0.830-0.830)/(0.714/0.830))^actg(0.496)*tan(0.359)^sin((0.500*0.500)/(x^0.500))/sin(0.591)+ln(0.756)-actg((0.212*0.212)+(0.212-0.212))-log(0.9)/atan(0.230)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_79) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"atan", "(", "0.138", ")", "*", "actg", "(", "0.171", ")", "-", "cos", "(", "(", "0.401", "*", "0.401", ")", "+", "(", "0.313", "+", "0.401", ")", ")", "^", "ctg", "(", "0.672", ")", "^", "ln", "(", "0.58", ")", "+", "ctg", "(", "(", "0.710", "-", "0.710", ")", "+", "(", "0.710", "*", "0.710", ")", ")", "-", "tan", "(", "0.16", ")", "/", "ln", "(", "0.206", ")", "-", "atan", "(", "(", "0.405", "*", "0.405", ")", "*", "(", "0.905", "-", "0.405", ")", ")", "/", "log", "(", "0.250", ")", "/", "atan", "(", "0.573", ")", "^", "ln", "(", "(", "0.675", "+", "0.675", ")", "+", "(", "0.675", "/", "0.675", ")", ")", "^", "log", "(", "0.421", ")"};
  char *example = {"atan(0.138)*actg(0.171)-cos((0.401*0.401)+(0.313+0.401))^ctg(0.672)^ln(0.58)+ctg((0.710-0.710)+(0.710*0.710))-tan(0.16)/ln(0.206)-atan((0.405*0.405)*(0.905-0.405))/log(0.250)/atan(0.573)^ln((0.675+0.675)+(0.675/0.675))^log(0.421)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_80) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"atan", "(", "0.873", ")", "-", "actg", "(", "0.475", ")", "+", "sin", "(", "(", "0.574", "^", "0.574", ")", "/", "(", "0.649", "+", "0.574", ")", ")", "/", "ctg", "(", "0.352", ")", "/", "atan", "(", "0.869", ")", "*", "ln", "(", "(", "0.370", "*", "0.370", ")", "^", "(", "0.370", "/", "0.370", ")", ")", "*", "cos", "(", "0.20", ")", "-", "acos", "(", "0.936", ")", "+", "sin", "(", "(", "0.397", "-", "0.397", ")", "/", "(", "x", "/", "0.397", ")", ")", "+", "ln", "(", "0.512", ")", "/", "atan", "(", "0.24", ")", "/", "asin", "(", "(", "0.739", "/", "0.739", ")", "/", "(", "0.739", "/", "0.739", ")", ")", "*", "atan", "(", "0.765", ")", "*", "0.228"};
  char *example = {"atan(0.873)-actg(0.475)+sin((0.574^0.574)/(0.649+0.574))/ctg(0.352)/atan(0.869)*ln((0.370*0.370)^(0.370/0.370))*cos(0.20)-acos(0.936)+sin((0.397-0.397)/(x/0.397))+ln(0.512)/atan(0.24)/asin((0.739/0.739)/(0.739/0.739))*atan(0.765)*0.228"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_81) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"118", "%", "303"};
  char *example = {"118%303"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_82) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"sqrt", "(", "0.399", ")", "+", "log", "(", "0.431", ")", "-", "cos", "(", "(", "0.761", "+", "0.761", ")", "^", "(", "0.761", "+", "0.761", ")", ")", "^", "ln", "(", "0.105", ")", "*", "sin", "(", "0.995", ")", "/", "tan", "(", "(", "0.489", "^", "0.489", ")", "-", "(", "x", "-", "0.489", ")", ")", "-", "acos", "(", "0.257", ")", "^", "actg", "(", "0.688", ")", "^", "actg", "(", "(", "0.419", "^", "0.419", ")", "/", "(", "x", "-", "0.419", ")", ")", "^"};
  char *example = {"sqrt(0.399)+log(0.431)-cos((0.761+0.761)^(0.761+0.761))^ln(0.105)*sin(0.995)/tan((0.489^0.489)-(x-0.489))-acos(0.257)^actg(0.688)^actg((0.419^0.419)/(x-0.419))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_83) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"log", "(", "0.683", ")", "^", "atan", "(", "0.973", ")", "-", "ctg", "(", "(", "0.311", "+", "0.311", ")", "-", "(", "0.141", "^", "0.311", ")", ")", "/", "sin", "(", "0.218", ")", "-", "actg", "(", "0.145", ")", "*", "sqrt", "(", "(", "0.808", "+", "0.808", ")", "+", "(", "0.808", "/", "0.808", ")", ")", "^", "sqrt", "(", "0.110", ")", "+", "ln", "(", "0.365", ")", "/", "atan", "(", "(", "0.795", "-", "0.795", ")", "+", "(", "x", "^", "0.795", ")", ")", "-", "atan", "(", "0.71", ")", "^", "asin", "(", "0.145", ")", "-", "log", "(", "(", "0.17", "+", "0.17", ")", "^", "(", "0.687", "+", "0.17", ")", ")", "+", "actg", "(", "0.64", ")", "+", "0.944"};
  char *example = {"log(0.683)^atan(0.973)-ctg((0.311+0.311)-(0.141^0.311))/sin(0.218)-actg(0.145)*sqrt((0.808+0.808)+(0.808/0.808))^sqrt(0.110)+ln(0.365)/atan((0.795-0.795)+(x^0.795))-atan(0.71)^asin(0.145)-log((0.17+0.17)^(0.687+0.17))+actg(0.64)+0.944"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_84) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"atan", "(", "0.934", ")", "*", "log", "(", "0.298", ")", "+", "acos", "(", "(", "0.639", "*", "0.639", ")", "/", "(", "0.793", "-", "0.639", ")", ")", "-", "tan", "(", "0.461", ")", "+", "sqrt", "(", "0.655", ")", "-", "sin", "(", "(", "0.869", "*", "0.869", ")", "-", "(", "0.6", "^", "0.869", ")", ")", "/", "asin", "(", "0.926", ")", "*", "atan", "(", "0.265", ")", "-", "asin", "(", "(", "0.993", "*", "0.993", ")", "-", "(", "0.302", "^", "0.993", ")", ")", "/", "cos", "(", "0.963", ")", "-", "acos", "(", "0.15", ")", "-", "cos", "(", "(", "0.355", "^", "0.355", ")", "*", "(", "x", "/", "0.355", ")", ")", "+"};
  char *example = {"atan(0.934)*log(0.298)+acos((0.639*0.639)/(0.793-0.639))-tan(0.461)+sqrt(0.655)-sin((0.869*0.869)-(0.6^0.869))/asin(0.926)*atan(0.265)-asin((0.993*0.993)-(0.302^0.993))/cos(0.963)-acos(0.15)-cos((0.355^0.355)*(x/0.355))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_85) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"sqrt", "(", "0.302", ")", "*", "atan", "(", "0.140", ")", "-", "cos", "(", "(", "0.926", "-", "0.926", ")", "*", "(", "0.303", "^", "0.926", ")", ")", "-", "ctg", "(", "0.395", ")", "-", "ln", "(", "0.445", ")", "/", "actg", "(", "(", "0.14", "^", "0.14", ")", "+", "(", "0.425", "/", "0.14", ")", ")", "-", "ln", "(", "0.80", ")", "^", "log", "(", "0.454", ")", "-", "ln", "(", "(", "0.885", "+", "0.885", ")", "*", "(", "0.885", "*", "0.885", ")", ")", "/", "sin", "(", "0.234", ")", "*", "cos", "(", "0.750", ")", "+", "cos", "(", "(", "0.290", "*", "0.290", ")", "^", "(", "x", "-", "0.290", ")", ")", "^", "ctg", "(", "0.891", ")", "*", "0.978"};
  char *example = {"sqrt(0.302)*atan(0.140)-cos((0.926-0.926)*(0.303^0.926))-ctg(0.395)-ln(0.445)/actg((0.14^0.14)+(0.425/0.14))-ln(0.80)^log(0.454)-ln((0.885+0.885)*(0.885*0.885))/sin(0.234)*cos(0.750)+cos((0.290*0.290)^(x-0.290))^ctg(0.891)*0.978"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_86) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"asin", "(", "0.803", ")", "+", "acos", "(", "0.635", ")", "-", "acos", "(", "(", "0.322", "*", "0.322", ")", "+", "(", "0.946", "+", "0.322", ")", ")", "*"};
  char *example = {"asin(0.803)+acos(0.635)-acos((0.322*0.322)+(0.946+0.322))*"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_87) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"acos", "(", "0.157", ")", "/", "sin", "(", "0.361", ")", "*", "ctg", "(", "(", "0.463", "^", "0.463", ")", "-", "(", "0.194", "/", "0.463", ")", ")", "/", "cos", "(", "0.869", ")", "^", "tan", "(", "0.293", ")", "/", "asin", "(", "(", "0.9", "*", "0.9", ")", "-", "(", "0.747", "/", "0.9", ")", ")", "+", "sqrt", "(", "0.327", ")", "+", "atan", "(", "0.465", ")", "-", "log", "(", "(", "0.707", "*", "0.707", ")", "-", "(", "x", "+", "0.707", ")", ")", "+"};
  char *example = {"acos(0.157)/sin(0.361)*ctg((0.463^0.463)-(0.194/0.463))/cos(0.869)^tan(0.293)/asin((0.9*0.9)-(0.747/0.9))+sqrt(0.327)+atan(0.465)-log((0.707*0.707)-(x+0.707))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_88) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"sqrt", "(", "0.907", ")", "+", "sqrt", "(", "0.353", ")", "+", "sin", "(", "(", "0.82", "-", "0.82", ")", "/", "(", "x", "*", "0.82", ")", ")", "+", "acos", "(", "0.173", ")", "/", "atan", "(", "0.633", ")", "+", "sqrt", "(", "(", "0.264", "+", "0.264", ")", "+", "(", "0.419", "-", "0.264", ")", ")", "+", "asin", "(", "0.879", ")", "+", "actg", "(", "0.367", ")", "+", "ln", "(", "(", "0.456", "*", "0.456", ")", "^", "(", "0.456", "*", "0.456", ")", ")", "-", "atan", "(", "0.182", ")", "/", "sin", "(", "0.471", ")", "*", "atan", "(", "(", "0.507", "-", "0.507", ")", "-", "(", "0.654", "+", "0.507", ")", ")", "^"};
  char *example = {"sqrt(0.907)+sqrt(0.353)+sin((0.82-0.82)/(x*0.82))+acos(0.173)/atan(0.633)+sqrt((0.264+0.264)+(0.419-0.264))+asin(0.879)+actg(0.367)+ln((0.456*0.456)^(0.456*0.456))-atan(0.182)/sin(0.471)*atan((0.507-0.507)-(0.654+0.507))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_89) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"actg", "(", "0.444", ")", "+", "tan", "(", "0.413", ")", "/", "sin", "(", "(", "0.529", "^", "0.529", ")", "/", "(", "0.529", "*", "0.529", ")", ")", "*", "tan", "(", "0.438", ")", "*", "actg", "(", "0.612", ")", "+", "sqrt", "(", "(", "0.969", "^", "0.969", ")", "-", "(", "0.451", "/", "0.969", ")", ")", "*", "log", "(", "0.266", ")", "-", "0.835"};
  char *example = {"actg(0.444)+tan(0.413)/sin((0.529^0.529)/(0.529*0.529))*tan(0.438)*actg(0.612)+sqrt((0.969^0.969)-(0.451/0.969))*log(0.266)-0.835"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_90) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"ln", "(", "0.653", ")", "^", "ctg", "(", "0.835", ")", "*", "ln", "(", "(", "0.436", "+", "0.436", ")", "/", "(", "0.436", "^", "0.436", ")", ")", "-", "asin", "(", "0.506", ")", "*", "cos", "(", "0.472", ")", "^", "ctg", "(", "(", "0.123", "^", "0.123", ")", "*", "(", "0.123", "+", "0.123", ")", ")", "^", "tan", "(", "0.678", ")", "-", "tan", "(", "0.905", ")", "-", "ctg", "(", "(", "0.847", "+", "0.847", ")", "-", "(", "0.326", "*", "0.847", ")", ")", "^", "ln", "(", "0.12", ")", "+", "acos", "(", "0.188", ")", "+", "sin", "(", "(", "0.997", "^", "0.997", ")", "/", "(", "0.293", "+", "0.997", ")", ")", "+"};
  char *example = {"ln(0.653)^ctg(0.835)*ln((0.436+0.436)/(0.436^0.436))-asin(0.506)*cos(0.472)^ctg((0.123^0.123)*(0.123+0.123))^tan(0.678)-tan(0.905)-ctg((0.847+0.847)-(0.326*0.847))^ln(0.12)+acos(0.188)+sin((0.997^0.997)/(0.293+0.997))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_91) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"asin", "(", "0.297", ")", "^", "atan", "(", "0.479", ")", "^", "actg", "(", "(", "0.788", "^", "0.788", ")", "*", "(", "x", "*", "0.788", ")", ")", "/", "sin", "(", "0.411", ")", "*", "tan", "(", "0.886", ")", "/", "ln", "(", "(", "0.182", "*", "0.182", ")", "*", "(", "0.479", "*", "0.182", ")", ")", "-", "sqrt", "(", "0.530", ")", "+", "tan", "(", "0.460", ")", "-", "cos", "(", "(", "0.199", "+", "0.199", ")", "-", "(", "x", "^", "0.199", ")", ")", "*", "log", "(", "0.504", ")", "/", "asin", "(", "0.506", ")", "+", "acos", "(", "(", "0.738", "-", "0.738", ")", "/", "(", "x", "-", "0.738", ")", ")", "/", "tan", "(", "0.957", ")", "-", "ln", "(", "0.791", ")", "*", "atan", "(", "(", "0.213", "/", "0.213", ")", "+", "(", "x", "/", "0.213", ")", ")", "+"};
  char *example = {"asin(0.297)^atan(0.479)^actg((0.788^0.788)*(x*0.788))/sin(0.411)*tan(0.886)/ln((0.182*0.182)*(0.479*0.182))-sqrt(0.530)+tan(0.460)-cos((0.199+0.199)-(x^0.199))*log(0.504)/asin(0.506)+acos((0.738-0.738)/(x-0.738))/tan(0.957)-ln(0.791)*atan((0.213/0.213)+(x/0.213))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_92) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"cos", "(", "0.92", ")", "-", "acos", "(", "0.379", ")", "-", "ln", "(", "(", "0.213", "*", "0.213", ")", "*", "(", "0.183", "*", "0.213", ")", ")", "+", "sqrt", "(", "0.256", ")", "+", "cos", "(", "0.18", ")", "-", "ln", "(", "(", "0.398", "-", "0.398", ")", "+", "(", "0.398", "/", "0.398", ")", ")", "+", "actg", "(", "0.775", ")", "+", "sin", "(", "0.944", ")", "/", "atan", "(", "(", "0.753", "^", "0.753", ")", "^", "(", "x", "-", "0.753", ")", ")", "/", "cos", "(", "0.299", ")", "*", "tan", "(", "0.281", ")", "^", "tan", "(", "(", "0.459", "-", "0.459", ")", "/", "(", "0.194", "^", "0.459", ")", ")", "*", "log", "(", "0.474", ")", "^", "0.147"};
  char *example = {"cos(0.92)-acos(0.379)-ln((0.213*0.213)*(0.183*0.213))+sqrt(0.256)+cos(0.18)-ln((0.398-0.398)+(0.398/0.398))+actg(0.775)+sin(0.944)/atan((0.753^0.753)^(x-0.753))/cos(0.299)*tan(0.281)^tan((0.459-0.459)/(0.194^0.459))*log(0.474)^0.147"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_93) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"tan", "(", "0.712", ")", "-", "sqrt", "(", "0.280", ")", "+", "actg", "(", "(", "0.613", "^", "0.613", ")", "^", "(", "0.306", "^", "0.613", ")", ")", "^"};
  char *example = {"tan(0.712)-sqrt(0.280)+actg((0.613^0.613)^(0.306^0.613))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_94) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"ctg", "(", "0.766", ")", "*", "cos", "(", "0.488", ")", "^", "sin", "(", "(", "0.227", "^", "0.227", ")", "/", "(", "0.564", "/", "0.227", ")", ")", "*", "sin", "(", "0.188", ")", "-", "ln", "(", "0.926", ")", "+", "ctg", "(", "(", "0.564", "^", "0.564", ")", "-", "(", "x", "*", "0.564", ")", ")", "^", "ctg", "(", "0.589", ")", "/", "ln", "(", "0.643", ")", "^", "acos", "(", "(", "0.398", "+", "0.398", ")", "*", "(", "x", "/", "0.398", ")", ")", "^", "asin", "(", "0.239", ")", "^", "ln", "(", "0.828", ")", "*", "cos", "(", "(", "0.258", "^", "0.258", ")", "^", "(", "0.258", "-", "0.258", ")", ")", "+", "asin", "(", "0.810", ")", "-", "asin", "(", "0.132", ")"};
  char *example = {"ctg(0.766)*cos(0.488)^sin((0.227^0.227)/(0.564/0.227))*sin(0.188)-ln(0.926)+ctg((0.564^0.564)-(x*0.564))^ctg(0.589)/ln(0.643)^acos((0.398+0.398)*(x/0.398))^asin(0.239)^ln(0.828)*cos((0.258^0.258)^(0.258-0.258))+asin(0.810)-asin(0.132)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_95) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"ln", "(", "0.364", ")", "+", "ctg", "(", "0.104", ")", "^", "cos", "(", "(", "0.715", "^", "0.715", ")", "^", "(", "x", "/", "0.715", ")", ")", "+", "tan", "(", "0.126", ")", "-", "ctg", "(", "0.78", ")", "+", "cos", "(", "(", "0.76", "+", "0.76", ")", "+", "(", "0.76", "+", "0.76", ")", ")", "/", "acos", "(", "0.992", ")", "+", "acos", "(", "0.715", ")", "/", "atan", "(", "(", "0.349", "+", "0.349", ")", "+", "(", "0.349", "-", "0.349", ")", ")", "+", "ctg", "(", "0.833", ")", "*", "asin", "(", "0.338", ")", "+", "ctg", "(", "(", "0.516", "*", "0.516", ")", "-", "(", "0.580", "-", "0.516", ")", ")", "/", "acos", "(", "0.74", ")", "-", "0.555"};
  char *example = {"ln(0.364)+ctg(0.104)^cos((0.715^0.715)^(x/0.715))+tan(0.126)-ctg(0.78)+cos((0.76+0.76)+(0.76+0.76))/acos(0.992)+acos(0.715)/atan((0.349+0.349)+(0.349-0.349))+ctg(0.833)*asin(0.338)+ctg((0.516*0.516)-(0.580-0.516))/acos(0.74)-0.555"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_96) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"sin", "(", "0.786", ")", "-", "acos", "(", "0.884", ")", "-", "sin", "(", "(", "0.863", "^", "0.863", ")", "/", "(", "x", "+", "0.863", ")", ")", "*", "atan", "(", "0.599", ")", "+", "asin", "(", "0.185", ")", "*", "log", "(", "(", "0.812", "^", "0.812", ")", "^", "(", "x", "*", "0.812", ")", ")", "*", "actg", "(", "0.639", ")", "*", "0.809"};
  char *example = {"sin(0.786)-acos(0.884)-sin((0.863^0.863)/(x+0.863))*atan(0.599)+asin(0.185)*log((0.812^0.812)^(x*0.812))*actg(0.639)*0.809"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_97) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"sin", "(", "0.807", ")", "/", "sqrt", "(", "0.334", ")", "+", "cos", "(", "(", "0.944", "^", "0.944", ")", "^", "(", "0.998", "^", "0.944", ")", ")", "*", "ln", "(", "0.246", ")", "+", "tan", "(", "0.513", ")", "/", "ctg", "(", "(", "0.6", "*", "0.6", ")", "-", "(", "0.237", "+", "0.6", ")", ")", "^", "ctg", "(", "0.687", ")", "+", "0.430"};
  char *example = {"sin(0.807)/sqrt(0.334)+cos((0.944^0.944)^(0.998^0.944))*ln(0.246)+tan(0.513)/ctg((0.6*0.6)-(0.237+0.6))^ctg(0.687)+0.430"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_98) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"actg", "(", "0.540", ")", "+", "sin", "(", "0.158", ")", "-", "actg", "(", "(", "0.803", "*", "0.803", ")", "+", "(", "0.803", "*", "0.803", ")", ")", "+", "sin", "(", "0.58", ")", "^", "sin", "(", "0.152", ")", "-", "asin", "(", "(", "0.380", "^", "0.380", ")", "*", "(", "0.380", "^", "0.380", ")", ")", "-", "cos", "(", "0.604", ")"};
  char *example = {"actg(0.540)+sin(0.158)-actg((0.803*0.803)+(0.803*0.803))+sin(0.58)^sin(0.152)-asin((0.380^0.380)*(0.380^0.380))-cos(0.604)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_99) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"actg", "(", "0.78", ")", "*", "acos", "(", "0.367", ")", "*", "asin", "(", "(", "0.918", "/", "0.918", ")", "-", "(", "x", "+", "0.918", ")", ")", "/", "acos", "(", "0.95", ")", "+", "actg", "(", "0.587", ")"};
  char *example = {"actg(0.78)*acos(0.367)*asin((0.918/0.918)-(x+0.918))/acos(0.95)+actg(0.587)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  free_stack(&stack);
}
END_TEST

START_TEST(parser_100) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"actg", "(", "0.471", ")", "*", "acos", "(", "0.531", ")", "+", "ln", "(", "(", "0.747", "^", "0.747", ")", "-", "(", "0.747", "+", "0.747", ")", ")", "+", "ln", "(", "0.724", ")"};
  char *example = {"actg(0.471)*acos(0.531)+ln((0.747^0.747)-(0.747+0.747))+ln(0.724)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
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
