#include "../header.h"

START_TEST(parser_1) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"sin", "(", "0.856", ")", "^", "acos", "(", "0.294", ")", "/", "actg", "(", "(", "0.971", "/", "0.971", ")", "*", "(", "x", "*", "0.971", ")", ")", "*"};
  char *example = {"sin(0.856)^acos(0.294)/actg((0.971/0.971)*(x*0.971))*"};
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
  char *string[] = {"tan", "(", "0.763", ")", "*", "log", "(", "0.910", ")", "+", "tan", "(", "(", "0.932", "^", "0.932", ")", "/", "(", "0.932", "/", "0.932", ")", ")", "/", "ctg", "(", "0.668", ")", "-", "sqrt", "(", "0.336", ")", "+", "sqrt", "(", "(", "0.743", "^", "0.743", ")", "^", "(", "0.282", "-", "0.743", ")", ")", "+", "sin", "(", "0.847", ")", "*", "ctg", "(", "0.0", ")", "^", "ln", "(", "(", "0.194", "*", "0.194", ")", "/", "(", "0.194", "^", "0.194", ")", ")", "^"};
  char *example = {"tan(0.763)*log(0.910)+tan((0.932^0.932)/(0.932/0.932))/ctg(0.668)-sqrt(0.336)+sqrt((0.743^0.743)^(0.282-0.743))+sin(0.847)*ctg(0.0)^ln((0.194*0.194)/(0.194^0.194))^"};
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
  char *string[] = {"913", "%", "317"};
  char *example = {"913%317"};
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
  char *string[] = {"actg", "(", "0.143", ")", "-", "0.778"};
  char *example = {"actg(0.143)-0.778"};
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
  char *string[] = {"501", "%", "837"};
  char *example = {"501%837"};
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
  char *string[] = {"sqrt", "(", "0.457", ")"};
  char *example = {"sqrt(0.457)"};
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
  char *string[] = {"tan", "(", "0.639", ")", "+", "atan", "(", "0.738", ")", "+", "sqrt", "(", "(", "0.985", "/", "0.985", ")", "/", "(", "x", "-", "0.985", ")", ")", "/", "sin", "(", "0.95", ")", "/", "cos", "(", "0.642", ")", "-", "acos", "(", "(", "0.884", "+", "0.884", ")", "/", "(", "0.92", "/", "0.884", ")", ")", "*", "sin", "(", "0.551", ")", "^", "ctg", "(", "0.45", ")", "+", "acos", "(", "(", "0.656", "-", "0.656", ")", "^", "(", "0.944", "+", "0.656", ")", ")", "-", "atan", "(", "0.112", ")", "/", "acos", "(", "0.968", ")", "/", "acos", "(", "(", "0.106", "-", "0.106", ")", "*", "(", "x", "/", "0.106", ")", ")", "+", "ln", "(", "0.967", ")"};
  char *example = {"tan(0.639)+atan(0.738)+sqrt((0.985/0.985)/(x-0.985))/sin(0.95)/cos(0.642)-acos((0.884+0.884)/(0.92/0.884))*sin(0.551)^ctg(0.45)+acos((0.656-0.656)^(0.944+0.656))-atan(0.112)/acos(0.968)/acos((0.106-0.106)*(x/0.106))+ln(0.967)"};
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
  char *string[] = {"sin", "(", "0.549", ")", "+", "ctg", "(", "0.251", ")", "-", "cos", "(", "(", "0.520", "^", "0.520", ")", "*", "(", "0.195", "/", "0.520", ")", ")", "+", "asin", "(", "0.905", ")", "^", "tan", "(", "0.779", ")", "^", "atan", "(", "(", "0.604", "/", "0.604", ")", "/", "(", "0.604", "/", "0.604", ")", ")", "^", "log", "(", "0.750", ")", "*", "acos", "(", "0.640", ")", "*", "asin", "(", "(", "0.349", "+", "0.349", ")", "+", "(", "0.910", "-", "0.349", ")", ")", "*", "cos", "(", "0.676", ")"};
  char *example = {"sin(0.549)+ctg(0.251)-cos((0.520^0.520)*(0.195/0.520))+asin(0.905)^tan(0.779)^atan((0.604/0.604)/(0.604/0.604))^log(0.750)*acos(0.640)*asin((0.349+0.349)+(0.910-0.349))*cos(0.676)"};
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
  char *string[] = {"ctg", "(", "0.867", ")", "^", "acos", "(", "0.262", ")", "+", "ctg", "(", "(", "0.293", "+", "0.293", ")", "+", "(", "0.577", "/", "0.293", ")", ")", "+", "cos", "(", "0.470", ")", "^", "log", "(", "0.23", ")"};
  char *example = {"ctg(0.867)^acos(0.262)+ctg((0.293+0.293)+(0.577/0.293))+cos(0.470)^log(0.23)"};
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
  char *string[] = {"ctg", "(", "0.495", ")", "/", "sin", "(", "0.694", ")", "*", "acos", "(", "(", "0.450", "/", "0.450", ")", "-", "(", "0.450", "+", "0.450", ")", ")", "/", "tan", "(", "0.461", ")", "^", "ctg", "(", "0.340", ")", "-", "sin", "(", "(", "0.599", "*", "0.599", ")", "^", "(", "0.835", "^", "0.599", ")", ")", "+", "cos", "(", "0.494", ")", "+", "sqrt", "(", "0.154", ")", "*", "ln", "(", "(", "0.485", "/", "0.485", ")", "-", "(", "0.47", "^", "0.485", ")", ")", "*", "tan", "(", "0.854", ")", "^", "sqrt", "(", "0.683", ")", "*", "ln", "(", "(", "0.816", "+", "0.816", ")", "^", "(", "0.816", "^", "0.816", ")", ")", "*", "ctg", "(", "0.311", ")", "*", "0.994"};
  char *example = {"ctg(0.495)/sin(0.694)*acos((0.450/0.450)-(0.450+0.450))/tan(0.461)^ctg(0.340)-sin((0.599*0.599)^(0.835^0.599))+cos(0.494)+sqrt(0.154)*ln((0.485/0.485)-(0.47^0.485))*tan(0.854)^sqrt(0.683)*ln((0.816+0.816)^(0.816^0.816))*ctg(0.311)*0.994"};
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
  char *string[] = {"actg", "(", "0.935", ")", "/", "0.270"};
  char *example = {"actg(0.935)/0.270"};
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
  char *string[] = {"sqrt", "(", "0.648", ")", "*", "actg", "(", "0.332", ")", "-", "ctg", "(", "(", "0.939", "^", "0.939", ")", "+", "(", "0.337", "-", "0.939", ")", ")", "-", "ctg", "(", "0.42", ")", "^", "ctg", "(", "0.68", ")", "^", "acos", "(", "(", "0.546", "-", "0.546", ")", "*", "(", "0.171", "-", "0.546", ")", ")", "-", "asin", "(", "0.534", ")", "-", "log", "(", "0.780", ")", "+", "ln", "(", "(", "0.65", "*", "0.65", ")", "-", "(", "0.65", "/", "0.65", ")", ")", "*", "cos", "(", "0.426", ")", "*", "log", "(", "0.660", ")"};
  char *example = {"sqrt(0.648)*actg(0.332)-ctg((0.939^0.939)+(0.337-0.939))-ctg(0.42)^ctg(0.68)^acos((0.546-0.546)*(0.171-0.546))-asin(0.534)-log(0.780)+ln((0.65*0.65)-(0.65/0.65))*cos(0.426)*log(0.660)"};
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
  char *string[] = {"378", "%", "452"};
  char *example = {"378%452"};
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
  char *string[] = {"asin", "(", "0.464", ")", "+", "cos", "(", "0.420", ")", "-", "asin", "(", "(", "0.623", "/", "0.623", ")", "*", "(", "0.437", "^", "0.623", ")", ")", "-", "sin", "(", "0.531", ")", "+", "log", "(", "0.852", ")", "-", "tan", "(", "(", "0.839", "/", "0.839", ")", "^", "(", "x", "*", "0.839", ")", ")", "^", "atan", "(", "0.525", ")", "*", "actg", "(", "0.596", ")", "^", "cos", "(", "(", "0.934", "^", "0.934", ")", "/", "(", "0.864", "*", "0.934", ")", ")", "*", "ctg", "(", "0.263", ")", "^", "tan", "(", "0.627", ")", "^", "ln", "(", "(", "0.68", "/", "0.68", ")", "+", "(", "x", "/", "0.68", ")", ")", "*", "atan", "(", "0.436", ")"};
  char *example = {"asin(0.464)+cos(0.420)-asin((0.623/0.623)*(0.437^0.623))-sin(0.531)+log(0.852)-tan((0.839/0.839)^(x*0.839))^atan(0.525)*actg(0.596)^cos((0.934^0.934)/(0.864*0.934))*ctg(0.263)^tan(0.627)^ln((0.68/0.68)+(x/0.68))*atan(0.436)"};
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
  char *string[] = {"ln", "(", "0.943", ")", "-", "sqrt", "(", "0.990", ")", "-", "actg", "(", "(", "0.270", "/", "0.270", ")", "/", "(", "0.270", "*", "0.270", ")", ")", "+"};
  char *example = {"ln(0.943)-sqrt(0.990)-actg((0.270/0.270)/(0.270*0.270))+"};
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
  char *string[] = {"cos", "(", "0.179", ")", "*", "actg", "(", "0.435", ")", "*", "tan", "(", "(", "0.75", "^", "0.75", ")", "^", "(", "0.54", "*", "0.75", ")", ")", "+", "sqrt", "(", "0.710", ")", "^", "cos", "(", "0.714", ")", "*", "acos", "(", "(", "0.748", "+", "0.748", ")", "^", "(", "0.748", "^", "0.748", ")", ")", "/", "sin", "(", "0.568", ")"};
  char *example = {"cos(0.179)*actg(0.435)*tan((0.75^0.75)^(0.54*0.75))+sqrt(0.710)^cos(0.714)*acos((0.748+0.748)^(0.748^0.748))/sin(0.568)"};
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
  char *string[] = {"acos", "(", "0.467", ")", "+", "0.158"};
  char *example = {"acos(0.467)+0.158"};
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
  char *string[] = {"ln", "(", "0.595", ")", "+", "atan", "(", "0.730", ")", "*", "sqrt", "(", "(", "0.51", "+", "0.51", ")", "+", "(", "x", "^", "0.51", ")", ")", "+"};
  char *example = {"ln(0.595)+atan(0.730)*sqrt((0.51+0.51)+(x^0.51))+"};
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
  char *string[] = {"266", "%", "245"};
  char *example = {"266%245"};
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
  char *string[] = {"log", "(", "0.308", ")", "^", "tan", "(", "0.447", ")", "*", "sqrt", "(", "(", "0.585", "-", "0.585", ")", "+", "(", "x", "^", "0.585", ")", ")", "-", "tan", "(", "0.324", ")", "*", "actg", "(", "0.387", ")", "^", "ctg", "(", "(", "0.810", "*", "0.810", ")", "*", "(", "0.810", "+", "0.810", ")", ")", "+", "cos", "(", "0.559", ")", "+", "ln", "(", "0.707", ")", "*", "sqrt", "(", "(", "0.180", "^", "0.180", ")", "-", "(", "0.180", "/", "0.180", ")", ")", "/"};
  char *example = {"log(0.308)^tan(0.447)*sqrt((0.585-0.585)+(x^0.585))-tan(0.324)*actg(0.387)^ctg((0.810*0.810)*(0.810+0.810))+cos(0.559)+ln(0.707)*sqrt((0.180^0.180)-(0.180/0.180))/"};
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
  char *string[] = {"tan", "(", "0.457", ")", "^", "asin", "(", "0.807", ")", "/", "ctg", "(", "(", "0.989", "*", "0.989", ")", "*", "(", "0.543", "-", "0.989", ")", ")", "-", "tan", "(", "0.130", ")"};
  char *example = {"tan(0.457)^asin(0.807)/ctg((0.989*0.989)*(0.543-0.989))-tan(0.130)"};
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
  char *string[] = {"sqrt", "(", "0.912", ")", "/", "tan", "(", "0.691", ")", "*", "sqrt", "(", "(", "0.13", "+", "0.13", ")", "-", "(", "0.207", "^", "0.13", ")", ")", "-", "atan", "(", "0.769", ")", "^", "actg", "(", "0.205", ")", "-", "tan", "(", "(", "0.325", "-", "0.325", ")", "*", "(", "x", "+", "0.325", ")", ")", "-", "ctg", "(", "0.232", ")", "/", "sin", "(", "0.236", ")", "+", "tan", "(", "(", "0.5", "+", "0.5", ")", "-", "(", "0.5", "-", "0.5", ")", ")", "*", "log", "(", "0.865", ")", "-", "asin", "(", "0.819", ")", "*", "asin", "(", "(", "0.365", "/", "0.365", ")", "-", "(", "0.941", "-", "0.365", ")", ")", "-", "ln", "(", "0.192", ")", "-", "log", "(", "0.750", ")", "/", "tan", "(", "(", "0.21", "^", "0.21", ")", "*", "(", "0.682", "^", "0.21", ")", ")", "*"};
  char *example = {"sqrt(0.912)/tan(0.691)*sqrt((0.13+0.13)-(0.207^0.13))-atan(0.769)^actg(0.205)-tan((0.325-0.325)*(x+0.325))-ctg(0.232)/sin(0.236)+tan((0.5+0.5)-(0.5-0.5))*log(0.865)-asin(0.819)*asin((0.365/0.365)-(0.941-0.365))-ln(0.192)-log(0.750)/tan((0.21^0.21)*(0.682^0.21))*"};
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
  char *string[] = {"log", "(", "0.16", ")", "^", "tan", "(", "0.381", ")", "*", "acos", "(", "(", "0.884", "*", "0.884", ")", "+", "(", "0.492", "-", "0.884", ")", ")", "+", "actg", "(", "0.134", ")", "^", "sin", "(", "0.985", ")", "*", "atan", "(", "(", "0.662", "*", "0.662", ")", "*", "(", "0.662", "*", "0.662", ")", ")", "*", "asin", "(", "0.893", ")", "-", "cos", "(", "0.7", ")", "^", "tan", "(", "(", "0.140", "*", "0.140", ")", "+", "(", "x", "^", "0.140", ")", ")", "-", "acos", "(", "0.283", ")"};
  char *example = {"log(0.16)^tan(0.381)*acos((0.884*0.884)+(0.492-0.884))+actg(0.134)^sin(0.985)*atan((0.662*0.662)*(0.662*0.662))*asin(0.893)-cos(0.7)^tan((0.140*0.140)+(x^0.140))-acos(0.283)"};
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
  char *string[] = {"acos", "(", "0.857", ")"};
  char *example = {"acos(0.857)"};
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
  char *string[] = {"sin", "(", "0.867", ")", "/", "actg", "(", "0.376", ")", "/", "asin", "(", "(", "0.484", "+", "0.484", ")", "/", "(", "0.484", "/", "0.484", ")", ")", "/", "asin", "(", "0.303", ")", "+", "tan", "(", "0.15", ")", "^", "ln", "(", "(", "0.728", "-", "0.728", ")", "/", "(", "x", "/", "0.728", ")", ")", "/", "acos", "(", "0.634", ")", "+", "log", "(", "0.546", ")", "^", "ln", "(", "(", "0.941", "^", "0.941", ")", "+", "(", "0.941", "/", "0.941", ")", ")", "+", "ctg", "(", "0.769", ")", "*", "0.187"};
  char *example = {"sin(0.867)/actg(0.376)/asin((0.484+0.484)/(0.484/0.484))/asin(0.303)+tan(0.15)^ln((0.728-0.728)/(x/0.728))/acos(0.634)+log(0.546)^ln((0.941^0.941)+(0.941/0.941))+ctg(0.769)*0.187"};
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
  char *string[] = {"log", "(", "0.770", ")", "+", "atan", "(", "0.243", ")", "*", "sin", "(", "(", "0.89", "/", "0.89", ")", "+", "(", "0.89", "^", "0.89", ")", ")", "^", "tan", "(", "0.577", ")", "*", "cos", "(", "0.546", ")"};
  char *example = {"log(0.770)+atan(0.243)*sin((0.89/0.89)+(0.89^0.89))^tan(0.577)*cos(0.546)"};
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
  char *string[] = {"atan", "(", "0.799", ")", "*", "sqrt", "(", "0.660", ")", "/", "sqrt", "(", "(", "0.493", "-", "0.493", ")", "+", "(", "x", "*", "0.493", ")", ")", "/", "tan", "(", "0.705", ")", "^", "sqrt", "(", "0.71", ")", "+", "log", "(", "(", "0.96", "/", "0.96", ")", "*", "(", "x", "*", "0.96", ")", ")", "/", "asin", "(", "0.501", ")", "/", "sqrt", "(", "0.831", ")", "^", "cos", "(", "(", "0.209", "-", "0.209", ")", "-", "(", "x", "/", "0.209", ")", ")", "-", "cos", "(", "0.828", ")"};
  char *example = {"atan(0.799)*sqrt(0.660)/sqrt((0.493-0.493)+(x*0.493))/tan(0.705)^sqrt(0.71)+log((0.96/0.96)*(x*0.96))/asin(0.501)/sqrt(0.831)^cos((0.209-0.209)-(x/0.209))-cos(0.828)"};
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
  char *string[] = {"ln", "(", "0.167", ")", "-", "tan", "(", "0.10", ")", "+", "sin", "(", "(", "0.447", "-", "0.447", ")", "/", "(", "x", "-", "0.447", ")", ")", "^", "ln", "(", "0.912", ")", "^", "ln", "(", "0.598", ")", "^", "actg", "(", "(", "0.148", "*", "0.148", ")", "+", "(", "0.162", "*", "0.148", ")", ")", "^", "sin", "(", "0.587", ")", "-", "ln", "(", "0.296", ")", "*", "cos", "(", "(", "0.56", "/", "0.56", ")", "^", "(", "0.820", "+", "0.56", ")", ")", "/", "acos", "(", "0.795", ")", "^", "ctg", "(", "0.111", ")", "+", "atan", "(", "(", "0.605", "/", "0.605", ")", "*", "(", "0.617", "^", "0.605", ")", ")", "*", "asin", "(", "0.159", ")", "-", "cos", "(", "0.412", ")", "/", "tan", "(", "(", "0.118", "-", "0.118", ")", "*", "(", "x", "-", "0.118", ")", ")", "-"};
  char *example = {"ln(0.167)-tan(0.10)+sin((0.447-0.447)/(x-0.447))^ln(0.912)^ln(0.598)^actg((0.148*0.148)+(0.162*0.148))^sin(0.587)-ln(0.296)*cos((0.56/0.56)^(0.820+0.56))/acos(0.795)^ctg(0.111)+atan((0.605/0.605)*(0.617^0.605))*asin(0.159)-cos(0.412)/tan((0.118-0.118)*(x-0.118))-"};
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
  char *string[] = {"log", "(", "0.83", ")", "/", "sqrt", "(", "0.197", ")", "+", "tan", "(", "(", "0.677", "-", "0.677", ")", "^", "(", "x", "*", "0.677", ")", ")", "^", "ln", "(", "0.483", ")", "^", "acos", "(", "0.953", ")", "-", "asin", "(", "(", "0.994", "+", "0.994", ")", "/", "(", "x", "-", "0.994", ")", ")", "^", "log", "(", "0.564", ")", "^", "log", "(", "0.457", ")", "*", "acos", "(", "(", "0.587", "+", "0.587", ")", "/", "(", "x", "*", "0.587", ")", ")", "^", "asin", "(", "0.107", ")", "*", "sqrt", "(", "0.507", ")"};
  char *example = {"log(0.83)/sqrt(0.197)+tan((0.677-0.677)^(x*0.677))^ln(0.483)^acos(0.953)-asin((0.994+0.994)/(x-0.994))^log(0.564)^log(0.457)*acos((0.587+0.587)/(x*0.587))^asin(0.107)*sqrt(0.507)"};
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
  char *string[] = {"sin", "(", "0.324", ")"};
  char *example = {"sin(0.324)"};
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
  char *string[] = {"tan", "(", "0.407", ")", "-", "tan", "(", "0.574", ")", "-", "actg", "(", "(", "0.38", "*", "0.38", ")", "^", "(", "x", "^", "0.38", ")", ")", "+", "tan", "(", "0.641", ")", "-", "0.25"};
  char *example = {"tan(0.407)-tan(0.574)-actg((0.38*0.38)^(x^0.38))+tan(0.641)-0.25"};
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
  char *string[] = {"ln", "(", "0.771", ")", "+", "atan", "(", "0.293", ")", "*", "atan", "(", "(", "0.279", "*", "0.279", ")", "+", "(", "0.279", "+", "0.279", ")", ")", "/", "atan", "(", "0.169", ")", "+", "atan", "(", "0.228", ")", "-", "sqrt", "(", "(", "0.320", "*", "0.320", ")", "/", "(", "0.890", "/", "0.320", ")", ")", "+", "tan", "(", "0.318", ")", "-", "ln", "(", "0.444", ")", "-", "actg", "(", "(", "0.482", "-", "0.482", ")", "/", "(", "x", "*", "0.482", ")", ")", "+", "ctg", "(", "0.478", ")", "^", "sin", "(", "0.537", ")"};
  char *example = {"ln(0.771)+atan(0.293)*atan((0.279*0.279)+(0.279+0.279))/atan(0.169)+atan(0.228)-sqrt((0.320*0.320)/(0.890/0.320))+tan(0.318)-ln(0.444)-actg((0.482-0.482)/(x*0.482))+ctg(0.478)^sin(0.537)"};
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
  char *string[] = {"atan", "(", "0.51", ")", "+", "sqrt", "(", "0.321", ")", "^", "cos", "(", "(", "0.563", "^", "0.563", ")", "/", "(", "0.563", "-", "0.563", ")", ")", "/", "sqrt", "(", "0.23", ")", "-", "sin", "(", "0.883", ")", "*", "acos", "(", "(", "0.307", "-", "0.307", ")", "+", "(", "x", "^", "0.307", ")", ")", "*", "sqrt", "(", "0.135", ")", "-", "actg", "(", "0.835", ")", "^", "ctg", "(", "(", "0.737", "^", "0.737", ")", "+", "(", "0.581", "-", "0.737", ")", ")", "+"};
  char *example = {"atan(0.51)+sqrt(0.321)^cos((0.563^0.563)/(0.563-0.563))/sqrt(0.23)-sin(0.883)*acos((0.307-0.307)+(x^0.307))*sqrt(0.135)-actg(0.835)^ctg((0.737^0.737)+(0.581-0.737))+"};
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
  char *string[] = {"sqrt", "(", "0.420", ")", "*", "atan", "(", "0.368", ")", "-", "actg", "(", "(", "0.189", "*", "0.189", ")", "+", "(", "0.929", "/", "0.189", ")", ")", "^", "sin", "(", "0.594", ")", "-", "log", "(", "0.332", ")", "-", "log", "(", "(", "0.120", "^", "0.120", ")", "+", "(", "x", "-", "0.120", ")", ")", "*"};
  char *example = {"sqrt(0.420)*atan(0.368)-actg((0.189*0.189)+(0.929/0.189))^sin(0.594)-log(0.332)-log((0.120^0.120)+(x-0.120))*"};
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
  char *string[] = {"sin", "(", "0.426", ")", "-", "asin", "(", "0.874", ")", "+", "ln", "(", "(", "0.729", "/", "0.729", ")", "-", "(", "0.729", "*", "0.729", ")", ")", "-", "atan", "(", "0.541", ")", "-", "ctg", "(", "0.552", ")", "*", "asin", "(", "(", "0.297", "+", "0.297", ")", "^", "(", "0.297", "^", "0.297", ")", ")", "/", "sin", "(", "0.510", ")", "/", "atan", "(", "0.196", ")"};
  char *example = {"sin(0.426)-asin(0.874)+ln((0.729/0.729)-(0.729*0.729))-atan(0.541)-ctg(0.552)*asin((0.297+0.297)^(0.297^0.297))/sin(0.510)/atan(0.196)"};
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
  char *string[] = {"ln", "(", "0.179", ")", "/", "ctg", "(", "0.677", ")", "+", "asin", "(", "(", "0.553", "+", "0.553", ")", "/", "(", "0.386", "*", "0.553", ")", ")", "+", "tan", "(", "0.922", ")", "+", "log", "(", "0.715", ")", "-", "atan", "(", "(", "0.451", "*", "0.451", ")", "^", "(", "0.451", "/", "0.451", ")", ")", "*", "sqrt", "(", "0.609", ")", "-", "sin", "(", "0.233", ")", "+", "tan", "(", "(", "0.367", "^", "0.367", ")", "-", "(", "0.367", "+", "0.367", ")", ")", "*", "cos", "(", "0.197", ")", "-", "ctg", "(", "0.386", ")", "+", "cos", "(", "(", "0.441", "-", "0.441", ")", "*", "(", "0.441", "-", "0.441", ")", ")", "-", "log", "(", "0.378", ")"};
  char *example = {"ln(0.179)/ctg(0.677)+asin((0.553+0.553)/(0.386*0.553))+tan(0.922)+log(0.715)-atan((0.451*0.451)^(0.451/0.451))*sqrt(0.609)-sin(0.233)+tan((0.367^0.367)-(0.367+0.367))*cos(0.197)-ctg(0.386)+cos((0.441-0.441)*(0.441-0.441))-log(0.378)"};
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
  char *string[] = {"ctg", "(", "0.502", ")", "^", "ln", "(", "0.916", ")", "+", "sin", "(", "(", "0.842", "*", "0.842", ")", "-", "(", "x", "-", "0.842", ")", ")", "/", "acos", "(", "0.43", ")", "/", "cos", "(", "0.718", ")", "/", "log", "(", "(", "0.340", "^", "0.340", ")", "^", "(", "0.193", "*", "0.340", ")", ")", "*", "ctg", "(", "0.617", ")", "^", "sqrt", "(", "0.502", ")", "-", "acos", "(", "(", "0.477", "*", "0.477", ")", "+", "(", "0.477", "^", "0.477", ")", ")", "/", "actg", "(", "0.609", ")", "/", "sin", "(", "0.544", ")", "/", "cos", "(", "(", "0.518", "+", "0.518", ")", "/", "(", "0.518", "-", "0.518", ")", ")", "/", "sin", "(", "0.105", ")", "^", "0.374"};
  char *example = {"ctg(0.502)^ln(0.916)+sin((0.842*0.842)-(x-0.842))/acos(0.43)/cos(0.718)/log((0.340^0.340)^(0.193*0.340))*ctg(0.617)^sqrt(0.502)-acos((0.477*0.477)+(0.477^0.477))/actg(0.609)/sin(0.544)/cos((0.518+0.518)/(0.518-0.518))/sin(0.105)^0.374"};
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
  char *string[] = {"ctg", "(", "0.772", ")", "*", "actg", "(", "0.897", ")", "-", "tan", "(", "(", "0.581", "-", "0.581", ")", "*", "(", "0.581", "^", "0.581", ")", ")", "-", "atan", "(", "0.55", ")", "/", "tan", "(", "0.832", ")", "/", "log", "(", "(", "0.742", "/", "0.742", ")", "/", "(", "0.680", "-", "0.742", ")", ")", "-", "cos", "(", "0.827", ")", "*", "acos", "(", "0.29", ")", "-", "sin", "(", "(", "0.176", "-", "0.176", ")", "^", "(", "0.176", "/", "0.176", ")", ")", "/", "acos", "(", "0.443", ")", "*", "0.182"};
  char *example = {"ctg(0.772)*actg(0.897)-tan((0.581-0.581)*(0.581^0.581))-atan(0.55)/tan(0.832)/log((0.742/0.742)/(0.680-0.742))-cos(0.827)*acos(0.29)-sin((0.176-0.176)^(0.176/0.176))/acos(0.443)*0.182"};
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
  char *string[] = {"sin", "(", "0.772", ")", "-", "actg", "(", "0.724", ")", "*", "sin", "(", "(", "0.197", "/", "0.197", ")", "/", "(", "0.197", "/", "0.197", ")", ")", "+", "actg", "(", "0.390", ")", "/", "log", "(", "0.867", ")", "^", "ln", "(", "(", "0.814", "+", "0.814", ")", "^", "(", "0.814", "^", "0.814", ")", ")", "/", "sin", "(", "0.871", ")", "/", "sqrt", "(", "0.328", ")", "/", "cos", "(", "(", "0.982", "^", "0.982", ")", "*", "(", "0.508", "-", "0.982", ")", ")", "^", "actg", "(", "0.560", ")", "/", "0.238"};
  char *example = {"sin(0.772)-actg(0.724)*sin((0.197/0.197)/(0.197/0.197))+actg(0.390)/log(0.867)^ln((0.814+0.814)^(0.814^0.814))/sin(0.871)/sqrt(0.328)/cos((0.982^0.982)*(0.508-0.982))^actg(0.560)/0.238"};
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
  char *string[] = {"actg", "(", "0.665", ")", "+", "asin", "(", "0.636", ")", "^", "cos", "(", "(", "0.340", "-", "0.340", ")", "^", "(", "0.340", "-", "0.340", ")", ")", "*", "acos", "(", "0.194", ")", "/", "atan", "(", "0.599", ")", "+", "cos", "(", "(", "0.600", "/", "0.600", ")", "+", "(", "x", "-", "0.600", ")", ")", "/", "cos", "(", "0.500", ")"};
  char *example = {"actg(0.665)+asin(0.636)^cos((0.340-0.340)^(0.340-0.340))*acos(0.194)/atan(0.599)+cos((0.600/0.600)+(x-0.600))/cos(0.500)"};
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
  char *string[] = {"sqrt", "(", "0.428", ")", "+", "ctg", "(", "0.231", ")", "/", "sqrt", "(", "(", "0.962", "/", "0.962", ")", "^", "(", "0.962", "*", "0.962", ")", ")", "^", "ctg", "(", "0.238", ")", "*", "log", "(", "0.499", ")", "/", "tan", "(", "(", "0.98", "*", "0.98", ")", "*", "(", "x", "^", "0.98", ")", ")", "^"};
  char *example = {"sqrt(0.428)+ctg(0.231)/sqrt((0.962/0.962)^(0.962*0.962))^ctg(0.238)*log(0.499)/tan((0.98*0.98)*(x^0.98))^"};
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
  char *string[] = {"ctg", "(", "0.26", ")", "^", "tan", "(", "0.164", ")", "+", "acos", "(", "(", "0.29", "/", "0.29", ")", "+", "(", "0.142", "*", "0.29", ")", ")", "+", "sin", "(", "0.27", ")", "*", "asin", "(", "0.405", ")", "+", "acos", "(", "(", "0.242", "*", "0.242", ")", "+", "(", "0.242", "/", "0.242", ")", ")", "^", "cos", "(", "0.536", ")", "/", "sqrt", "(", "0.454", ")", "/", "ln", "(", "(", "0.288", "+", "0.288", ")", "-", "(", "x", "^", "0.288", ")", ")", "-"};
  char *example = {"ctg(0.26)^tan(0.164)+acos((0.29/0.29)+(0.142*0.29))+sin(0.27)*asin(0.405)+acos((0.242*0.242)+(0.242/0.242))^cos(0.536)/sqrt(0.454)/ln((0.288+0.288)-(x^0.288))-"};
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
  char *string[] = {"actg", "(", "0.779", ")", "*", "sin", "(", "0.78", ")", "*", "actg", "(", "(", "0.530", "^", "0.530", ")", "+", "(", "0.530", "^", "0.530", ")", ")", "+"};
  char *example = {"actg(0.779)*sin(0.78)*actg((0.530^0.530)+(0.530^0.530))+"};
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
  char *string[] = {"ctg", "(", "0.118", ")", "+", "actg", "(", "0.785", ")", "^", "tan", "(", "(", "0.83", "-", "0.83", ")", "+", "(", "x", "/", "0.83", ")", ")", "*", "ln", "(", "0.684", ")", "^", "sqrt", "(", "0.627", ")", "^", "ln", "(", "(", "0.949", "+", "0.949", ")", "+", "(", "0.949", "/", "0.949", ")", ")", "/", "ln", "(", "0.192", ")", "/", "log", "(", "0.192", ")", "^", "atan", "(", "(", "0.335", "^", "0.335", ")", "+", "(", "0.335", "+", "0.335", ")", ")", "/", "ln", "(", "0.279", ")", "+", "sqrt", "(", "0.765", ")"};
  char *example = {"ctg(0.118)+actg(0.785)^tan((0.83-0.83)+(x/0.83))*ln(0.684)^sqrt(0.627)^ln((0.949+0.949)+(0.949/0.949))/ln(0.192)/log(0.192)^atan((0.335^0.335)+(0.335+0.335))/ln(0.279)+sqrt(0.765)"};
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
  char *string[] = {"ctg", "(", "0.92", ")"};
  char *example = {"ctg(0.92)"};
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
  char *string[] = {"actg", "(", "0.257", ")", "*", "cos", "(", "0.326", ")", "/", "sin", "(", "(", "0.946", "/", "0.946", ")", "-", "(", "0.399", "-", "0.946", ")", ")", "+", "sqrt", "(", "0.104", ")", "^", "ln", "(", "0.378", ")", "^", "sqrt", "(", "(", "0.956", "+", "0.956", ")", "^", "(", "x", "/", "0.956", ")", ")", "/", "tan", "(", "0.981", ")", "-", "ctg", "(", "0.862", ")", "+", "sqrt", "(", "(", "0.210", "/", "0.210", ")", "-", "(", "x", "^", "0.210", ")", ")", "*", "tan", "(", "0.739", ")"};
  char *example = {"actg(0.257)*cos(0.326)/sin((0.946/0.946)-(0.399-0.946))+sqrt(0.104)^ln(0.378)^sqrt((0.956+0.956)^(x/0.956))/tan(0.981)-ctg(0.862)+sqrt((0.210/0.210)-(x^0.210))*tan(0.739)"};
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
  char *string[] = {"ln", "(", "0.219", ")", "/", "sqrt", "(", "0.856", ")", "*", "ctg", "(", "(", "0.729", "-", "0.729", ")", "*", "(", "x", "+", "0.729", ")", ")", "+", "sqrt", "(", "0.154", ")"};
  char *example = {"ln(0.219)/sqrt(0.856)*ctg((0.729-0.729)*(x+0.729))+sqrt(0.154)"};
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
  char *string[] = {"sin", "(", "0.418", ")", "*", "0.881"};
  char *example = {"sin(0.418)*0.881"};
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
  char *string[] = {"sin", "(", "0.695", ")", "+", "tan", "(", "0.733", ")", "^", "cos", "(", "(", "0.467", "*", "0.467", ")", "*", "(", "x", "^", "0.467", ")", ")", "*", "acos", "(", "0.212", ")", "+", "ln", "(", "0.15", ")", "/", "actg", "(", "(", "0.614", "/", "0.614", ")", "-", "(", "0.776", "*", "0.614", ")", ")", "^", "ln", "(", "0.551", ")", "*", "acos", "(", "0.355", ")", "*", "ctg", "(", "(", "0.239", "-", "0.239", ")", "/", "(", "x", "/", "0.239", ")", ")", "-", "actg", "(", "0.424", ")", "/", "sin", "(", "0.73", ")", "-", "actg", "(", "(", "0.388", "+", "0.388", ")", "-", "(", "0.388", "+", "0.388", ")", ")", "-", "tan", "(", "0.762", ")", "^", "asin", "(", "0.85", ")", "-", "tan", "(", "(", "0.394", "^", "0.394", ")", "^", "(", "0.394", "^", "0.394", ")", ")", "/"};
  char *example = {"sin(0.695)+tan(0.733)^cos((0.467*0.467)*(x^0.467))*acos(0.212)+ln(0.15)/actg((0.614/0.614)-(0.776*0.614))^ln(0.551)*acos(0.355)*ctg((0.239-0.239)/(x/0.239))-actg(0.424)/sin(0.73)-actg((0.388+0.388)-(0.388+0.388))-tan(0.762)^asin(0.85)-tan((0.394^0.394)^(0.394^0.394))/"};
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
  char *string[] = {"sqrt", "(", "0.369", ")", "/", "ln", "(", "0.466", ")", "+", "log", "(", "(", "0.433", "-", "0.433", ")", "/", "(", "0.676", "^", "0.433", ")", ")", "*", "actg", "(", "0.288", ")", "+", "cos", "(", "0.590", ")"};
  char *example = {"sqrt(0.369)/ln(0.466)+log((0.433-0.433)/(0.676^0.433))*actg(0.288)+cos(0.590)"};
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
  char *string[] = {"atan", "(", "0.421", ")", "/", "asin", "(", "0.284", ")", "*", "actg", "(", "(", "0.413", "/", "0.413", ")", "-", "(", "x", "^", "0.413", ")", ")", "*", "atan", "(", "0.183", ")", "/", "tan", "(", "0.165", ")", "-", "acos", "(", "(", "0.3", "*", "0.3", ")", "-", "(", "0.3", "-", "0.3", ")", ")", "/", "cos", "(", "0.798", ")", "+", "tan", "(", "0.212", ")", "-", "log", "(", "(", "0.785", "*", "0.785", ")", "^", "(", "0.785", "+", "0.785", ")", ")", "^", "ctg", "(", "0.515", ")", "^", "ctg", "(", "0.741", ")"};
  char *example = {"atan(0.421)/asin(0.284)*actg((0.413/0.413)-(x^0.413))*atan(0.183)/tan(0.165)-acos((0.3*0.3)-(0.3-0.3))/cos(0.798)+tan(0.212)-log((0.785*0.785)^(0.785+0.785))^ctg(0.515)^ctg(0.741)"};
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
  char *string[] = {"375", "%", "997"};
  char *example = {"375%997"};
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
  char *string[] = {"ctg", "(", "0.171", ")", "/", "ctg", "(", "0.171", ")", "^", "sin", "(", "(", "0.536", "+", "0.536", ")", "-", "(", "0.536", "+", "0.536", ")", ")", "+", "ctg", "(", "0.750", ")", "^", "ln", "(", "0.242", ")", "*", "log", "(", "(", "0.32", "/", "0.32", ")", "/", "(", "0.953", "/", "0.32", ")", ")", "-", "acos", "(", "0.184", ")", "+", "acos", "(", "0.313", ")", "-", "sqrt", "(", "(", "0.46", "+", "0.46", ")", "*", "(", "x", "^", "0.46", ")", ")", "/", "atan", "(", "0.998", ")", "/", "atan", "(", "0.537", ")", "/", "sin", "(", "(", "0.890", "+", "0.890", ")", "*", "(", "0.109", "^", "0.890", ")", ")", "+"};
  char *example = {"ctg(0.171)/ctg(0.171)^sin((0.536+0.536)-(0.536+0.536))+ctg(0.750)^ln(0.242)*log((0.32/0.32)/(0.953/0.32))-acos(0.184)+acos(0.313)-sqrt((0.46+0.46)*(x^0.46))/atan(0.998)/atan(0.537)/sin((0.890+0.890)*(0.109^0.890))+"};
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
  char *string[] = {"log", "(", "0.736", ")", "^", "ln", "(", "0.36", ")", "/", "ln", "(", "(", "0.614", "+", "0.614", ")", "^", "(", "0.658", "-", "0.614", ")", ")", "+", "sin", "(", "0.168", ")", "/", "sqrt", "(", "0.487", ")", "*", "tan", "(", "(", "0.458", "/", "0.458", ")", "+", "(", "0.135", "-", "0.458", ")", ")", "-", "atan", "(", "0.884", ")", "-", "ln", "(", "0.138", ")"};
  char *example = {"log(0.736)^ln(0.36)/ln((0.614+0.614)^(0.658-0.614))+sin(0.168)/sqrt(0.487)*tan((0.458/0.458)+(0.135-0.458))-atan(0.884)-ln(0.138)"};
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
  char *string[] = {"sin", "(", "0.911", ")", "/", "asin", "(", "0.278", ")", "+", "tan", "(", "(", "0.104", "^", "0.104", ")", "/", "(", "x", "^", "0.104", ")", ")", "+", "atan", "(", "0.139", ")", "*", "atan", "(", "0.650", ")"};
  char *example = {"sin(0.911)/asin(0.278)+tan((0.104^0.104)/(x^0.104))+atan(0.139)*atan(0.650)"};
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
  char *string[] = {"acos", "(", "0.549", ")", "+", "ctg", "(", "0.597", ")", "+", "tan", "(", "(", "0.669", "+", "0.669", ")", "*", "(", "x", "+", "0.669", ")", ")", "+", "cos", "(", "0.47", ")", "*", "tan", "(", "0.853", ")", "-", "log", "(", "(", "0.157", "*", "0.157", ")", "^", "(", "x", "/", "0.157", ")", ")", "-", "actg", "(", "0.500", ")", "/", "atan", "(", "0.106", ")", "-", "tan", "(", "(", "0.582", "-", "0.582", ")", "*", "(", "x", "*", "0.582", ")", ")", "-", "sqrt", "(", "0.234", ")", "^", "atan", "(", "0.271", ")", "^", "sin", "(", "(", "0.509", "-", "0.509", ")", "*", "(", "0.753", "+", "0.509", ")", ")", "^", "cos", "(", "0.635", ")", "*", "acos", "(", "0.179", ")"};
  char *example = {"acos(0.549)+ctg(0.597)+tan((0.669+0.669)*(x+0.669))+cos(0.47)*tan(0.853)-log((0.157*0.157)^(x/0.157))-actg(0.500)/atan(0.106)-tan((0.582-0.582)*(x*0.582))-sqrt(0.234)^atan(0.271)^sin((0.509-0.509)*(0.753+0.509))^cos(0.635)*acos(0.179)"};
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
  char *string[] = {"asin", "(", "0.372", ")", "-", "tan", "(", "0.943", ")", "-", "log", "(", "(", "0.440", "-", "0.440", ")", "+", "(", "x", "+", "0.440", ")", ")", "+", "sin", "(", "0.605", ")", "*", "atan", "(", "0.809", ")", "-", "log", "(", "(", "0.43", "+", "0.43", ")", "^", "(", "0.43", "+", "0.43", ")", ")", "^", "actg", "(", "0.217", ")", "-", "acos", "(", "0.652", ")"};
  char *example = {"asin(0.372)-tan(0.943)-log((0.440-0.440)+(x+0.440))+sin(0.605)*atan(0.809)-log((0.43+0.43)^(0.43+0.43))^actg(0.217)-acos(0.652)"};
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
  char *string[] = {"acos", "(", "0.172", ")", "+", "0.265"};
  char *example = {"acos(0.172)+0.265"};
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
  char *string[] = {"ctg", "(", "0.390", ")", "*", "sqrt", "(", "0.740", ")", "*", "sin", "(", "(", "0.433", "*", "0.433", ")", "^", "(", "0.433", "+", "0.433", ")", ")", "^", "acos", "(", "0.875", ")", "-", "sin", "(", "0.242", ")", "-", "log", "(", "(", "0.290", "-", "0.290", ")", "-", "(", "x", "-", "0.290", ")", ")", "*", "atan", "(", "0.553", ")", "/", "asin", "(", "0.581", ")"};
  char *example = {"ctg(0.390)*sqrt(0.740)*sin((0.433*0.433)^(0.433+0.433))^acos(0.875)-sin(0.242)-log((0.290-0.290)-(x-0.290))*atan(0.553)/asin(0.581)"};
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
  char *string[] = {"cos", "(", "0.579", ")"};
  char *example = {"cos(0.579)"};
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
  char *string[] = {"log", "(", "0.786", ")", "-", "sin", "(", "0.907", ")", "^", "cos", "(", "(", "0.67", "-", "0.67", ")", "-", "(", "0.994", "/", "0.67", ")", ")", "*", "sin", "(", "0.206", ")", "/", "actg", "(", "0.743", ")", "*", "log", "(", "(", "0.178", "/", "0.178", ")", "*", "(", "0.537", "/", "0.178", ")", ")", "+", "sin", "(", "0.371", ")", "^", "cos", "(", "0.397", ")", "^", "actg", "(", "(", "0.616", "+", "0.616", ")", "*", "(", "x", "*", "0.616", ")", ")", "+", "actg", "(", "0.382", ")", "+", "actg", "(", "0.970", ")", "-", "atan", "(", "(", "0.222", "*", "0.222", ")", "*", "(", "0.359", "+", "0.222", ")", ")", "+", "asin", "(", "0.907", ")", "^", "0.418"};
  char *example = {"log(0.786)-sin(0.907)^cos((0.67-0.67)-(0.994/0.67))*sin(0.206)/actg(0.743)*log((0.178/0.178)*(0.537/0.178))+sin(0.371)^cos(0.397)^actg((0.616+0.616)*(x*0.616))+actg(0.382)+actg(0.970)-atan((0.222*0.222)*(0.359+0.222))+asin(0.907)^0.418"};
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
  char *string[] = {"ln", "(", "0.976", ")"};
  char *example = {"ln(0.976)"};
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
  char *string[] = {"acos", "(", "0.352", ")", "-", "actg", "(", "0.312", ")", "+", "tan", "(", "(", "0.591", "^", "0.591", ")", "^", "(", "x", "/", "0.591", ")", ")", "-", "log", "(", "0.393", ")", "^", "atan", "(", "0.112", ")", "-", "tan", "(", "(", "0.266", "/", "0.266", ")", "*", "(", "x", "-", "0.266", ")", ")", "^", "asin", "(", "0.944", ")", "+", "cos", "(", "0.990", ")", "^", "actg", "(", "(", "0.239", "+", "0.239", ")", "-", "(", "x", "+", "0.239", ")", ")", "-"};
  char *example = {"acos(0.352)-actg(0.312)+tan((0.591^0.591)^(x/0.591))-log(0.393)^atan(0.112)-tan((0.266/0.266)*(x-0.266))^asin(0.944)+cos(0.990)^actg((0.239+0.239)-(x+0.239))-"};
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
  char *string[] = {"cos", "(", "0.508", ")", "^", "atan", "(", "0.823", ")", "*", "acos", "(", "(", "0.354", "^", "0.354", ")", "-", "(", "x", "-", "0.354", ")", ")", "^", "ln", "(", "0.584", ")", "^", "atan", "(", "0.162", ")", "^", "sin", "(", "(", "0.783", "*", "0.783", ")", "-", "(", "0.964", "^", "0.783", ")", ")", "*", "cos", "(", "0.440", ")", "/", "asin", "(", "0.370", ")", "^", "cos", "(", "(", "0.981", "*", "0.981", ")", "-", "(", "0.981", "/", "0.981", ")", ")", "*", "tan", "(", "0.390", ")", "*", "0.114"};
  char *example = {"cos(0.508)^atan(0.823)*acos((0.354^0.354)-(x-0.354))^ln(0.584)^atan(0.162)^sin((0.783*0.783)-(0.964^0.783))*cos(0.440)/asin(0.370)^cos((0.981*0.981)-(0.981/0.981))*tan(0.390)*0.114"};
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
  char *string[] = {"acos", "(", "0.718", ")", "/", "acos", "(", "0.555", ")", "-", "sqrt", "(", "(", "0.779", "-", "0.779", ")", "+", "(", "0.779", "*", "0.779", ")", ")", "-", "cos", "(", "0.742", ")", "^", "ln", "(", "0.636", ")", "*", "sin", "(", "(", "0.274", "^", "0.274", ")", "/", "(", "0.238", "*", "0.274", ")", ")", "*", "acos", "(", "0.229", ")", "+", "ctg", "(", "0.81", ")", "+", "log", "(", "(", "0.725", "^", "0.725", ")", "/", "(", "0.725", "-", "0.725", ")", ")", "/", "ctg", "(", "0.321", ")"};
  char *example = {"acos(0.718)/acos(0.555)-sqrt((0.779-0.779)+(0.779*0.779))-cos(0.742)^ln(0.636)*sin((0.274^0.274)/(0.238*0.274))*acos(0.229)+ctg(0.81)+log((0.725^0.725)/(0.725-0.725))/ctg(0.321)"};
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
  char *string[] = {"atan", "(", "0.671", ")", "+", "sin", "(", "0.808", ")", "^", "actg", "(", "(", "0.537", "^", "0.537", ")", "*", "(", "0.537", "/", "0.537", ")", ")", "+", "cos", "(", "0.238", ")", "+", "0.957"};
  char *example = {"atan(0.671)+sin(0.808)^actg((0.537^0.537)*(0.537/0.537))+cos(0.238)+0.957"};
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
  char *string[] = {"asin", "(", "0.374", ")", "*", "asin", "(", "0.174", ")", "*", "tan", "(", "(", "0.492", "+", "0.492", ")", "/", "(", "0.492", "-", "0.492", ")", ")", "*"};
  char *example = {"asin(0.374)*asin(0.174)*tan((0.492+0.492)/(0.492-0.492))*"};
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
  char *string[] = {"actg", "(", "0.320", ")", "-", "sin", "(", "0.84", ")", "+", "tan", "(", "(", "0.456", "-", "0.456", ")", "+", "(", "x", "^", "0.456", ")", ")", "^", "asin", "(", "0.80", ")"};
  char *example = {"actg(0.320)-sin(0.84)+tan((0.456-0.456)+(x^0.456))^asin(0.80)"};
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
  char *string[] = {"cos", "(", "0.312", ")", "-", "sin", "(", "0.904", ")", "-", "ln", "(", "(", "0.896", "/", "0.896", ")", "^", "(", "x", "+", "0.896", ")", ")", "^", "actg", "(", "0.744", ")", "-", "ln", "(", "0.336", ")", "-", "atan", "(", "(", "0.387", "-", "0.387", ")", "-", "(", "x", "/", "0.387", ")", ")", "+", "ln", "(", "0.984", ")", "+", "0.909"};
  char *example = {"cos(0.312)-sin(0.904)-ln((0.896/0.896)^(x+0.896))^actg(0.744)-ln(0.336)-atan((0.387-0.387)-(x/0.387))+ln(0.984)+0.909"};
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
  char *string[] = {"asin", "(", "0.746", ")", "+", "0.637"};
  char *example = {"asin(0.746)+0.637"};
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
  char *string[] = {"atan", "(", "0.448", ")", "+", "asin", "(", "0.542", ")", "+", "acos", "(", "(", "0.259", "^", "0.259", ")", "^", "(", "0.259", "^", "0.259", ")", ")", "^", "ln", "(", "0.217", ")", "*", "acos", "(", "0.993", ")", "-", "ctg", "(", "(", "0.484", "*", "0.484", ")", "-", "(", "0.852", "/", "0.484", ")", ")", "-", "actg", "(", "0.599", ")", "+", "ctg", "(", "0.146", ")", "^", "atan", "(", "(", "0.745", "-", "0.745", ")", "^", "(", "0.765", "*", "0.745", ")", ")", "^", "ln", "(", "0.361", ")", "-", "ctg", "(", "0.701", ")", "^", "ln", "(", "(", "0.908", "-", "0.908", ")", "-", "(", "0.892", "*", "0.908", ")", ")", "^", "asin", "(", "0.790", ")", "^", "ctg", "(", "0.497", ")", "^", "ln", "(", "(", "0.473", "/", "0.473", ")", "+", "(", "0.378", "-", "0.473", ")", ")", "+"};
  char *example = {"atan(0.448)+asin(0.542)+acos((0.259^0.259)^(0.259^0.259))^ln(0.217)*acos(0.993)-ctg((0.484*0.484)-(0.852/0.484))-actg(0.599)+ctg(0.146)^atan((0.745-0.745)^(0.765*0.745))^ln(0.361)-ctg(0.701)^ln((0.908-0.908)-(0.892*0.908))^asin(0.790)^ctg(0.497)^ln((0.473/0.473)+(0.378-0.473))+"};
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
  char *string[] = {"atan", "(", "0.617", ")", "*", "cos", "(", "0.545", ")", "^", "atan", "(", "(", "0.920", "-", "0.920", ")", "-", "(", "0.920", "+", "0.920", ")", ")", "/", "ln", "(", "0.170", ")", "+", "asin", "(", "0.125", ")", "^", "actg", "(", "(", "0.714", "*", "0.714", ")", "+", "(", "x", "+", "0.714", ")", ")", "/", "ctg", "(", "0.568", ")"};
  char *example = {"atan(0.617)*cos(0.545)^atan((0.920-0.920)-(0.920+0.920))/ln(0.170)+asin(0.125)^actg((0.714*0.714)+(x+0.714))/ctg(0.568)"};
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
  char *string[] = {"ctg", "(", "0.731", ")", "+", "cos", "(", "0.969", ")", "*", "sqrt", "(", "(", "0.984", "^", "0.984", ")", "^", "(", "0.636", "+", "0.984", ")", ")", "^", "atan", "(", "0.24", ")"};
  char *example = {"ctg(0.731)+cos(0.969)*sqrt((0.984^0.984)^(0.636+0.984))^atan(0.24)"};
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
  char *string[] = {"ctg", "(", "0.469", ")", "+", "sin", "(", "0.135", ")", "^", "asin", "(", "(", "0.246", "*", "0.246", ")", "-", "(", "x", "-", "0.246", ")", ")", "^", "asin", "(", "0.633", ")", "/", "sqrt", "(", "0.749", ")", "*", "actg", "(", "(", "0.279", "-", "0.279", ")", "*", "(", "0.434", "-", "0.279", ")", ")", "^", "sqrt", "(", "0.252", ")", "/", "sin", "(", "0.528", ")", "+", "acos", "(", "(", "0.286", "^", "0.286", ")", "*", "(", "0.376", "/", "0.286", ")", ")", "^", "asin", "(", "0.280", ")"};
  char *example = {"ctg(0.469)+sin(0.135)^asin((0.246*0.246)-(x-0.246))^asin(0.633)/sqrt(0.749)*actg((0.279-0.279)*(0.434-0.279))^sqrt(0.252)/sin(0.528)+acos((0.286^0.286)*(0.376/0.286))^asin(0.280)"};
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
  char *string[] = {"log", "(", "0.930", ")", "*", "cos", "(", "0.685", ")", "+", "sin", "(", "(", "0.319", "^", "0.319", ")", "^", "(", "0.199", "+", "0.319", ")", ")", "*", "atan", "(", "0.774", ")", "/", "sin", "(", "0.117", ")", "*", "asin", "(", "(", "0.870", "+", "0.870", ")", "^", "(", "0.870", "-", "0.870", ")", ")", "-"};
  char *example = {"log(0.930)*cos(0.685)+sin((0.319^0.319)^(0.199+0.319))*atan(0.774)/sin(0.117)*asin((0.870+0.870)^(0.870-0.870))-"};
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
  char *string[] = {"sin", "(", "0.718", ")", "*", "ctg", "(", "0.538", ")", "-", "ln", "(", "(", "0.817", "^", "0.817", ")", "/", "(", "x", "-", "0.817", ")", ")", "*"};
  char *example = {"sin(0.718)*ctg(0.538)-ln((0.817^0.817)/(x-0.817))*"};
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
  char *string[] = {"actg", "(", "0.774", ")", "+", "log", "(", "0.810", ")", "*", "asin", "(", "(", "0.424", "^", "0.424", ")", "*", "(", "x", "/", "0.424", ")", ")", "+", "ln", "(", "0.760", ")"};
  char *example = {"actg(0.774)+log(0.810)*asin((0.424^0.424)*(x/0.424))+ln(0.760)"};
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
  char *string[] = {"actg", "(", "0.997", ")", "*", "sin", "(", "0.191", ")", "+", "ctg", "(", "(", "0.803", "^", "0.803", ")", "^", "(", "x", "+", "0.803", ")", ")", "/", "ctg", "(", "0.673", ")", "^", "ctg", "(", "0.552", ")", "^", "sqrt", "(", "(", "0.698", "-", "0.698", ")", "-", "(", "0.314", "^", "0.698", ")", ")", "/", "atan", "(", "0.391", ")", "-", "actg", "(", "0.949", ")", "-", "actg", "(", "(", "0.309", "/", "0.309", ")", "-", "(", "0.309", "+", "0.309", ")", ")", "^", "asin", "(", "0.847", ")"};
  char *example = {"actg(0.997)*sin(0.191)+ctg((0.803^0.803)^(x+0.803))/ctg(0.673)^ctg(0.552)^sqrt((0.698-0.698)-(0.314^0.698))/atan(0.391)-actg(0.949)-actg((0.309/0.309)-(0.309+0.309))^asin(0.847)"};
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
  char *string[] = {"tan", "(", "0.711", ")", "^", "ln", "(", "0.520", ")", "^", "tan", "(", "(", "0.124", "+", "0.124", ")", "+", "(", "0.124", "*", "0.124", ")", ")", "/", "sin", "(", "0.261", ")", "*", "log", "(", "0.251", ")", "*", "log", "(", "(", "0.544", "^", "0.544", ")", "-", "(", "0.943", "*", "0.544", ")", ")", "^", "asin", "(", "0.727", ")", "*", "sin", "(", "0.855", ")", "^", "log", "(", "(", "0.663", "-", "0.663", ")", "/", "(", "x", "+", "0.663", ")", ")", "-", "tan", "(", "0.737", ")", "-", "sqrt", "(", "0.673", ")", "+", "atan", "(", "(", "0.952", "^", "0.952", ")", "-", "(", "x", "-", "0.952", ")", ")", "*"};
  char *example = {"tan(0.711)^ln(0.520)^tan((0.124+0.124)+(0.124*0.124))/sin(0.261)*log(0.251)*log((0.544^0.544)-(0.943*0.544))^asin(0.727)*sin(0.855)^log((0.663-0.663)/(x+0.663))-tan(0.737)-sqrt(0.673)+atan((0.952^0.952)-(x-0.952))*"};
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
  char *string[] = {"tan", "(", "0.486", ")", "/", "actg", "(", "0.671", ")", "-", "ln", "(", "(", "0.704", "/", "0.704", ")", "*", "(", "0.270", "+", "0.704", ")", ")", "^", "sqrt", "(", "0.152", ")", "^", "ctg", "(", "0.554", ")", "/", "ctg", "(", "(", "0.55", "*", "0.55", ")", "/", "(", "x", "+", "0.55", ")", ")", "^", "tan", "(", "0.736", ")", "^", "actg", "(", "0.158", ")"};
  char *example = {"tan(0.486)/actg(0.671)-ln((0.704/0.704)*(0.270+0.704))^sqrt(0.152)^ctg(0.554)/ctg((0.55*0.55)/(x+0.55))^tan(0.736)^actg(0.158)"};
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
  char *string[] = {"ctg", "(", "0.196", ")", "-", "tan", "(", "0.700", ")", "-", "ctg", "(", "(", "0.39", "*", "0.39", ")", "*", "(", "0.39", "/", "0.39", ")", ")", "^", "acos", "(", "0.139", ")", "-", "sin", "(", "0.926", ")", "^", "acos", "(", "(", "0.896", "*", "0.896", ")", "+", "(", "0.896", "-", "0.896", ")", ")", "/", "atan", "(", "0.807", ")", "/", "sin", "(", "0.188", ")", "/", "atan", "(", "(", "0.630", "+", "0.630", ")", "*", "(", "0.876", "-", "0.630", ")", ")", "/", "ctg", "(", "0.314", ")", "-", "sin", "(", "0.616", ")", "+", "ln", "(", "(", "0.443", "^", "0.443", ")", "*", "(", "0.498", "^", "0.443", ")", ")", "^"};
  char *example = {"ctg(0.196)-tan(0.700)-ctg((0.39*0.39)*(0.39/0.39))^acos(0.139)-sin(0.926)^acos((0.896*0.896)+(0.896-0.896))/atan(0.807)/sin(0.188)/atan((0.630+0.630)*(0.876-0.630))/ctg(0.314)-sin(0.616)+ln((0.443^0.443)*(0.498^0.443))^"};
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
  char *string[] = {"ctg", "(", "0.768", ")", "^", "asin", "(", "0.51", ")", "^", "ln", "(", "(", "0.878", "/", "0.878", ")", "*", "(", "0.878", "*", "0.878", ")", ")", "-", "actg", "(", "0.566", ")", "*", "ctg", "(", "0.749", ")", "*", "acos", "(", "(", "0.877", "-", "0.877", ")", "+", "(", "x", "+", "0.877", ")", ")", "+", "atan", "(", "0.11", ")", "-", "ln", "(", "0.717", ")"};
  char *example = {"ctg(0.768)^asin(0.51)^ln((0.878/0.878)*(0.878*0.878))-actg(0.566)*ctg(0.749)*acos((0.877-0.877)+(x+0.877))+atan(0.11)-ln(0.717)"};
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
  char *string[] = {"log", "(", "0.353", ")", "-", "ctg", "(", "0.696", ")", "^", "ctg", "(", "(", "0.791", "^", "0.791", ")", "+", "(", "0.791", "/", "0.791", ")", ")", "+", "acos", "(", "0.467", ")", "^", "0.784"};
  char *example = {"log(0.353)-ctg(0.696)^ctg((0.791^0.791)+(0.791/0.791))+acos(0.467)^0.784"};
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
  char *string[] = {"acos", "(", "0.380", ")", "^", "asin", "(", "0.834", ")", "/", "sin", "(", "(", "0.575", "/", "0.575", ")", "-", "(", "x", "*", "0.575", ")", ")", "^", "sin", "(", "0.20", ")", "/", "tan", "(", "0.687", ")", "*", "sin", "(", "(", "0.86", "^", "0.86", ")", "/", "(", "0.951", "+", "0.86", ")", ")", "-", "ln", "(", "0.101", ")", "*", "asin", "(", "0.174", ")", "*", "ctg", "(", "(", "0.134", "*", "0.134", ")", "-", "(", "0.151", "-", "0.134", ")", ")", "^", "log", "(", "0.640", ")", "-", "ln", "(", "0.778", ")"};
  char *example = {"acos(0.380)^asin(0.834)/sin((0.575/0.575)-(x*0.575))^sin(0.20)/tan(0.687)*sin((0.86^0.86)/(0.951+0.86))-ln(0.101)*asin(0.174)*ctg((0.134*0.134)-(0.151-0.134))^log(0.640)-ln(0.778)"};
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
  char *string[] = {"log", "(", "0.904", ")", "^", "tan", "(", "0.968", ")", "+", "tan", "(", "(", "0.981", "+", "0.981", ")", "-", "(", "0.981", "^", "0.981", ")", ")", "-", "ctg", "(", "0.513", ")", "/", "actg", "(", "0.350", ")", "^", "log", "(", "(", "0.114", "/", "0.114", ")", "^", "(", "x", "^", "0.114", ")", ")", "-", "actg", "(", "0.123", ")"};
  char *example = {"log(0.904)^tan(0.968)+tan((0.981+0.981)-(0.981^0.981))-ctg(0.513)/actg(0.350)^log((0.114/0.114)^(x^0.114))-actg(0.123)"};
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
  char *string[] = {"ln", "(", "0.525", ")"};
  char *example = {"ln(0.525)"};
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
  char *string[] = {"ln", "(", "0.326", ")"};
  char *example = {"ln(0.326)"};
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
  char *string[] = {"sqrt", "(", "0.953", ")", "+", "tan", "(", "0.977", ")", "*", "atan", "(", "(", "0.135", "^", "0.135", ")", "/", "(", "0.300", "+", "0.135", ")", ")", "/", "sqrt", "(", "0.275", ")", "^", "ln", "(", "0.567", ")", "^", "atan", "(", "(", "0.583", "*", "0.583", ")", "+", "(", "0.583", "^", "0.583", ")", ")", "*"};
  char *example = {"sqrt(0.953)+tan(0.977)*atan((0.135^0.135)/(0.300+0.135))/sqrt(0.275)^ln(0.567)^atan((0.583*0.583)+(0.583^0.583))*"};
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
  char *string[] = {"atan", "(", "0.892", ")", "^", "acos", "(", "0.205", ")", "+", "ln", "(", "(", "0.100", "/", "0.100", ")", "^", "(", "0.100", "^", "0.100", ")", ")", "+", "tan", "(", "0.176", ")", "*", "acos", "(", "0.917", ")", "-", "atan", "(", "(", "0.427", "^", "0.427", ")", "*", "(", "0.343", "/", "0.427", ")", ")", "/", "atan", "(", "0.907", ")", "^", "acos", "(", "0.275", ")", "^", "log", "(", "(", "0.32", "+", "0.32", ")", "^", "(", "x", "^", "0.32", ")", ")", "*"};
  char *example = {"atan(0.892)^acos(0.205)+ln((0.100/0.100)^(0.100^0.100))+tan(0.176)*acos(0.917)-atan((0.427^0.427)*(0.343/0.427))/atan(0.907)^acos(0.275)^log((0.32+0.32)^(x^0.32))*"};
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
  char *string[] = {"tan", "(", "0.76", ")", "/", "ln", "(", "0.493", ")", "/", "ln", "(", "(", "0.638", "^", "0.638", ")", "^", "(", "0.745", "^", "0.638", ")", ")", "*"};
  char *example = {"tan(0.76)/ln(0.493)/ln((0.638^0.638)^(0.745^0.638))*"};
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
  char *string[] = {"sqrt", "(", "0.146", ")", "+", "sin", "(", "0.500", ")", "+", "acos", "(", "(", "0.591", "+", "0.591", ")", "/", "(", "0.591", "/", "0.591", ")", ")", "^", "tan", "(", "0.462", ")", "^", "tan", "(", "0.804", ")", "*", "tan", "(", "(", "0.702", "/", "0.702", ")", "/", "(", "x", "*", "0.702", ")", ")", "^"};
  char *example = {"sqrt(0.146)+sin(0.500)+acos((0.591+0.591)/(0.591/0.591))^tan(0.462)^tan(0.804)*tan((0.702/0.702)/(x*0.702))^"};
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
  char *string[] = {"asin", "(", "0.722", ")", "*", "sqrt", "(", "0.492", ")", "/", "log", "(", "(", "0.953", "+", "0.953", ")", "^", "(", "0.953", "^", "0.953", ")", ")", "/", "ln", "(", "0.573", ")", "/", "ln", "(", "0.71", ")", "^", "log", "(", "(", "0.428", "-", "0.428", ")", "^", "(", "0.428", "*", "0.428", ")", ")", "+", "asin", "(", "0.260", ")", "-", "acos", "(", "0.119", ")", "^", "asin", "(", "(", "0.217", "/", "0.217", ")", "*", "(", "0.217", "/", "0.217", ")", ")", "-", "sqrt", "(", "0.225", ")"};
  char *example = {"asin(0.722)*sqrt(0.492)/log((0.953+0.953)^(0.953^0.953))/ln(0.573)/ln(0.71)^log((0.428-0.428)^(0.428*0.428))+asin(0.260)-acos(0.119)^asin((0.217/0.217)*(0.217/0.217))-sqrt(0.225)"};
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
  char *string[] = {"sin", "(", "0.426", ")", "^", "cos", "(", "0.457", ")", "*", "cos", "(", "(", "0.156", "*", "0.156", ")", "/", "(", "x", "^", "0.156", ")", ")", "+", "cos", "(", "0.131", ")", "^", "asin", "(", "0.207", ")", "/", "ln", "(", "(", "0.292", "/", "0.292", ")", "^", "(", "0.292", "/", "0.292", ")", ")", "^"};
  char *example = {"sin(0.426)^cos(0.457)*cos((0.156*0.156)/(x^0.156))+cos(0.131)^asin(0.207)/ln((0.292/0.292)^(0.292/0.292))^"};
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
  char *string[] = {"ctg", "(", "0.328", ")", "^", "ctg", "(", "0.638", ")", "-", "asin", "(", "(", "0.807", "+", "0.807", ")", "+", "(", "0.638", "*", "0.807", ")", ")", "*", "sqrt", "(", "0.39", ")", "+", "log", "(", "0.183", ")", "*", "asin", "(", "(", "0.304", "+", "0.304", ")", "/", "(", "0.304", "-", "0.304", ")", ")", "*", "actg", "(", "0.467", ")", "^", "atan", "(", "0.210", ")", "-", "asin", "(", "(", "0.774", "*", "0.774", ")", "+", "(", "0.774", "+", "0.774", ")", ")", "+"};
  char *example = {"ctg(0.328)^ctg(0.638)-asin((0.807+0.807)+(0.638*0.807))*sqrt(0.39)+log(0.183)*asin((0.304+0.304)/(0.304-0.304))*actg(0.467)^atan(0.210)-asin((0.774*0.774)+(0.774+0.774))+"};
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
  char *string[] = {"cos", "(", "0.3", ")", "-", "0.857"};
  char *example = {"cos(0.3)-0.857"};
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
  char *string[] = {"acos", "(", "0.158", ")", "*", "asin", "(", "0.138", ")", "^", "acos", "(", "(", "0.649", "/", "0.649", ")", "/", "(", "0.649", "^", "0.649", ")", ")", "*", "tan", "(", "0.108", ")", "+", "tan", "(", "0.749", ")", "/", "asin", "(", "(", "0.153", "-", "0.153", ")", "+", "(", "0.630", "^", "0.153", ")", ")", "^", "sqrt", "(", "0.531", ")", "*", "tan", "(", "0.73", ")", "-", "asin", "(", "(", "0.745", "*", "0.745", ")", "*", "(", "0.189", "*", "0.745", ")", ")", "+", "tan", "(", "0.595", ")", "+", "0.383"};
  char *example = {"acos(0.158)*asin(0.138)^acos((0.649/0.649)/(0.649^0.649))*tan(0.108)+tan(0.749)/asin((0.153-0.153)+(0.630^0.153))^sqrt(0.531)*tan(0.73)-asin((0.745*0.745)*(0.189*0.745))+tan(0.595)+0.383"};
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
  char *string[] = {"atan", "(", "0.264", ")", "*", "sqrt", "(", "0.401", ")", "/", "ctg", "(", "(", "0.375", "^", "0.375", ")", "+", "(", "x", "*", "0.375", ")", ")", "*", "ctg", "(", "0.281", ")", "*", "0.255"};
  char *example = {"atan(0.264)*sqrt(0.401)/ctg((0.375^0.375)+(x*0.375))*ctg(0.281)*0.255"};
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
  char *string[] = {"sqrt", "(", "0.740", ")", "-", "actg", "(", "0.84", ")", "^", "log", "(", "(", "0.348", "*", "0.348", ")", "+", "(", "0.348", "*", "0.348", ")", ")", "+", "actg", "(", "0.863", ")"};
  char *example = {"sqrt(0.740)-actg(0.84)^log((0.348*0.348)+(0.348*0.348))+actg(0.863)"};
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
  char *string[] = {"acos", "(", "0.459", ")", "-", "asin", "(", "0.362", ")", "-", "sqrt", "(", "(", "0.512", "^", "0.512", ")", "*", "(", "x", "-", "0.512", ")", ")", "*"};
  char *example = {"acos(0.459)-asin(0.362)-sqrt((0.512^0.512)*(x-0.512))*"};
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
  char *string[] = {"tan", "(", "0.104", ")", "+", "log", "(", "0.127", ")", "/", "log", "(", "(", "0.354", "-", "0.354", ")", "/", "(", "x", "-", "0.354", ")", ")", "-", "ln", "(", "0.685", ")", "^", "actg", "(", "0.712", ")", "^", "atan", "(", "(", "0.384", "^", "0.384", ")", "*", "(", "0.384", "/", "0.384", ")", ")", "-", "atan", "(", "0.274", ")", "*", "actg", "(", "0.463", ")", "+", "atan", "(", "(", "0.193", "^", "0.193", ")", "/", "(", "0.747", "*", "0.193", ")", ")", "*", "asin", "(", "0.168", ")", "/", "actg", "(", "0.435", ")", "-", "acos", "(", "(", "0.798", "^", "0.798", ")", "+", "(", "x", "+", "0.798", ")", ")", "^"};
  char *example = {"tan(0.104)+log(0.127)/log((0.354-0.354)/(x-0.354))-ln(0.685)^actg(0.712)^atan((0.384^0.384)*(0.384/0.384))-atan(0.274)*actg(0.463)+atan((0.193^0.193)/(0.747*0.193))*asin(0.168)/actg(0.435)-acos((0.798^0.798)+(x+0.798))^"};
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
