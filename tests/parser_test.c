#include "../header.h"

START_TEST(parser_1) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.394", ")", "^", "log", "(", "0.779", ")", "/", "ln", "(", "(", "0.716", "*", "0.716", ")", "-", "(", "x", "^", "0.716", ")", ")", "+", "acos", "(", "0.209", ")", "^", "acos", "(", "0.216", ")", "^", "sqrt", "(", "(", "0.820", "-", "0.820", ")", "-", "(", "0.820", "*", "0.820", ")", ")", "^", "atan", "(", "0.366", ")", "^", "actg", "(", "0.989", ")", "*", "sin", "(", "(", "0.985", "-", "0.985", ")", "+", "(", "0.658", "^", "0.985", ")", ")", "*", "asin", "(", "0.718", ")", "^", "tan", "(", "0.599", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.394)^log(0.779)/ln((0.716*0.716)-(x^0.716))+acos(0.209)^acos(0.216)^sqrt((0.820-0.820)-(0.820*0.820))^atan(0.366)^actg(0.989)*sin((0.985-0.985)+(0.658^0.985))*asin(0.718)^tan(0.599)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.798", ")", "+", "ln", "(", "0.271", ")", "/", "ln", "(", "(", "0.409", "/", "0.409", ")", "^", "(", "x", "/", "0.409", ")", ")", "+", "sqrt", "(", "0.775", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.798)+ln(0.271)/ln((0.409/0.409)^(x/0.409))+sqrt(0.775)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "203", "%", "617"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+203%617"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.192", ")", "*", "sqrt", "(", "0.755", ")", "-", "asin", "(", "(", "0.197", "/", "0.197", ")", "-", "(", "0.197", "*", "0.197", ")", ")", "+", "atan", "(", "0.497", ")", "/", "asin", "(", "0.705", ")", "+", "ctg", "(", "(", "0.911", "+", "0.911", ")", "-", "(", "x", "+", "0.911", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.192)*sqrt(0.755)-asin((0.197/0.197)-(0.197*0.197))+atan(0.497)/asin(0.705)+ctg((0.911+0.911)-(x+0.911))/"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.81", ")", "^", "sqrt", "(", "0.874", ")", "^", "acos", "(", "(", "0.739", "/", "0.739", ")", "/", "(", "0.6", "/", "0.739", ")", ")", "/", "acos", "(", "0.814", ")", "-", "asin", "(", "0.677", ")", "+", "ctg", "(", "(", "0.258", "/", "0.258", ")", "-", "(", "0.456", "-", "0.258", ")", ")", "/", "tan", "(", "0.854", ")", "+", "log", "(", "0.800", ")", "+", "sin", "(", "(", "0.809", "-", "0.809", ")", "-", "(", "x", "*", "0.809", ")", ")", "+", "sqrt", "(", "0.761", ")", "/", "cos", "(", "0.92", ")", "/", "ctg", "(", "(", "0.318", "+", "0.318", ")", "/", "(", "0.318", "+", "0.318", ")", ")", "+", "atan", "(", "0.495", ")", "*", "actg", "(", "0.896", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.81)^sqrt(0.874)^acos((0.739/0.739)/(0.6/0.739))/acos(0.814)-asin(0.677)+ctg((0.258/0.258)-(0.456-0.258))/tan(0.854)+log(0.800)+sin((0.809-0.809)-(x*0.809))+sqrt(0.761)/cos(0.92)/ctg((0.318+0.318)/(0.318+0.318))+atan(0.495)*actg(0.896)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.213", ")", "^", "ctg", "(", "0.46", ")", "-", "ln", "(", "(", "0.810", "/", "0.810", ")", "/", "(", "0.896", "^", "0.810", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.213)^ctg(0.46)-ln((0.810/0.810)/(0.896^0.810))*"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.564", ")", "*", "atan", "(", "0.209", ")", "^", "sqrt", "(", "(", "0.135", "-", "0.135", ")", "+", "(", "0.676", "^", "0.135", ")", ")", "+", "asin", "(", "0.28", ")", "^", "cos", "(", "0.692", ")", "/", "asin", "(", "(", "0.805", "-", "0.805", ")", "^", "(", "0.413", "-", "0.805", ")", ")", "-", "acos", "(", "0.132", ")", "/", "tan", "(", "0.410", ")", "+", "ctg", "(", "(", "0.956", "+", "0.956", ")", "+", "(", "0.757", "*", "0.956", ")", ")", "-", "acos", "(", "0.577", ")", "+", "acos", "(", "0.702", ")", "-", "log", "(", "(", "0.512", "*", "0.512", ")", "+", "(", "0.512", "-", "0.512", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.564)*atan(0.209)^sqrt((0.135-0.135)+(0.676^0.135))+asin(0.28)^cos(0.692)/asin((0.805-0.805)^(0.413-0.805))-acos(0.132)/tan(0.410)+ctg((0.956+0.956)+(0.757*0.956))-acos(0.577)+acos(0.702)-log((0.512*0.512)+(0.512-0.512))-"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "652", "%", "334"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+652%334"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.31", ")", "*", "atan", "(", "0.628", ")", "-", "ln", "(", "(", "0.666", "^", "0.666", ")", "+", "(", "x", "/", "0.666", ")", ")", "*", "actg", "(", "0.626", ")", "-", "actg", "(", "0.666", ")", "/", "acos", "(", "(", "0.253", "+", "0.253", ")", "/", "(", "x", "/", "0.253", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.31)*atan(0.628)-ln((0.666^0.666)+(x/0.666))*actg(0.626)-actg(0.666)/acos((0.253+0.253)/(x/0.253))^"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "262", "%", "519"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+262%519"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.623", ")", "+", "log", "(", "0.487", ")", "^", "atan", "(", "(", "0.576", "-", "0.576", ")", "*", "(", "x", "^", "0.576", ")", ")", "^", "log", "(", "0.215", ")", "+", "actg", "(", "0.579", ")", "/", "cos", "(", "(", "0.865", "/", "0.865", ")", "^", "(", "0.865", "/", "0.865", ")", ")", "*", "sqrt", "(", "0.499", ")", "-", "ctg", "(", "0.644", ")", "-", "ln", "(", "(", "0.612", "/", "0.612", ")", "-", "(", "0.612", "-", "0.612", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.623)+log(0.487)^atan((0.576-0.576)*(x^0.576))^log(0.215)+actg(0.579)/cos((0.865/0.865)^(0.865/0.865))*sqrt(0.499)-ctg(0.644)-ln((0.612/0.612)-(0.612-0.612))*"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.55", ")", "+", "actg", "(", "0.51", ")", "*", "acos", "(", "(", "0.511", "*", "0.511", ")", "*", "(", "x", "+", "0.511", ")", ")", "*", "sqrt", "(", "0.832", ")", "+", "cos", "(", "0.719", ")", "/", "asin", "(", "(", "0.729", "-", "0.729", ")", "^", "(", "x", "^", "0.729", ")", ")", "^", "actg", "(", "0.952", ")", "^", "0.340"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.55)+actg(0.51)*acos((0.511*0.511)*(x+0.511))*sqrt(0.832)+cos(0.719)/asin((0.729-0.729)^(x^0.729))^actg(0.952)^0.340"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.239", ")", "*", "actg", "(", "0.347", ")", "-", "asin", "(", "(", "0.898", "/", "0.898", ")", "/", "(", "0.898", "/", "0.898", ")", ")", "/", "log", "(", "0.541", ")", "-", "atan", "(", "0.487", ")", "/", "ctg", "(", "(", "0.686", "/", "0.686", ")", "-", "(", "0.686", "*", "0.686", ")", ")", "+", "asin", "(", "0.276", ")", "^", "sin", "(", "0.966", ")", "+", "asin", "(", "(", "0.308", "*", "0.308", ")", "^", "(", "x", "+", "0.308", ")", ")", "/", "sqrt", "(", "0.945", ")", "^", "sin", "(", "0.403", ")", "/", "tan", "(", "(", "0.21", "/", "0.21", ")", "+", "(", "x", "+", "0.21", ")", ")", "-", "cos", "(", "0.38", ")", "+", "acos", "(", "0.760", ")", "-", "ln", "(", "(", "0.386", "/", "0.386", ")", "/", "(", "x", "-", "0.386", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.239)*actg(0.347)-asin((0.898/0.898)/(0.898/0.898))/log(0.541)-atan(0.487)/ctg((0.686/0.686)-(0.686*0.686))+asin(0.276)^sin(0.966)+asin((0.308*0.308)^(x+0.308))/sqrt(0.945)^sin(0.403)/tan((0.21/0.21)+(x+0.21))-cos(0.38)+acos(0.760)-ln((0.386/0.386)/(x-0.386))*"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.174", ")", "^", "ln", "(", "0.553", ")", "^", "sqrt", "(", "(", "0.286", "+", "0.286", ")", "/", "(", "x", "+", "0.286", ")", ")", "^", "sin", "(", "0.563", ")", "^", "atan", "(", "0.23", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.174)^ln(0.553)^sqrt((0.286+0.286)/(x+0.286))^sin(0.563)^atan(0.23)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.717", ")", "+", "actg", "(", "0.483", ")", "/", "sqrt", "(", "(", "0.411", "+", "0.411", ")", "/", "(", "0.748", "^", "0.411", ")", ")", "+", "atan", "(", "0.880", ")", "+", "tan", "(", "0.54", ")", "^", "ln", "(", "(", "0.614", "-", "0.614", ")", "*", "(", "x", "-", "0.614", ")", ")", "-", "ln", "(", "0.619", ")", "-", "log", "(", "0.775", ")", "*", "ctg", "(", "(", "0.429", "-", "0.429", ")", "*", "(", "x", "/", "0.429", ")", ")", "-", "sin", "(", "0.969", ")", "^", "acos", "(", "0.895", ")", "/", "actg", "(", "(", "0.207", "/", "0.207", ")", "-", "(", "0.765", "*", "0.207", ")", ")", "+", "acos", "(", "0.475", ")", "^", "acos", "(", "0.267", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.717)+actg(0.483)/sqrt((0.411+0.411)/(0.748^0.411))+atan(0.880)+tan(0.54)^ln((0.614-0.614)*(x-0.614))-ln(0.619)-log(0.775)*ctg((0.429-0.429)*(x/0.429))-sin(0.969)^acos(0.895)/actg((0.207/0.207)-(0.765*0.207))+acos(0.475)^acos(0.267)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.652", ")", "-", "cos", "(", "0.662", ")", "/", "tan", "(", "(", "0.694", "*", "0.694", ")", "*", "(", "0.694", "/", "0.694", ")", ")", "*", "asin", "(", "0.878", ")", "/", "atan", "(", "0.178", ")", "*", "ctg", "(", "(", "0.694", "+", "0.694", ")", "*", "(", "0.544", "*", "0.694", ")", ")", "*", "ctg", "(", "0.680", ")", "/", "actg", "(", "0.578", ")", "/", "sqrt", "(", "(", "0.6", "-", "0.6", ")", "^", "(", "x", "/", "0.6", ")", ")", "/", "actg", "(", "0.218", ")", "+", "actg", "(", "0.645", ")", "*", "log", "(", "(", "0.623", "-", "0.623", ")", "-", "(", "0.954", "-", "0.623", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.652)-cos(0.662)/tan((0.694*0.694)*(0.694/0.694))*asin(0.878)/atan(0.178)*ctg((0.694+0.694)*(0.544*0.694))*ctg(0.680)/actg(0.578)/sqrt((0.6-0.6)^(x/0.6))/actg(0.218)+actg(0.645)*log((0.623-0.623)-(0.954-0.623))-"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.114", ")", "-", "tan", "(", "0.265", ")", "-", "actg", "(", "(", "0.354", "-", "0.354", ")", "*", "(", "x", "*", "0.354", ")", ")", "-", "ln", "(", "0.516", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.114)-tan(0.265)-actg((0.354-0.354)*(x*0.354))-ln(0.516)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.103", ")", "-", "tan", "(", "0.678", ")", "*", "asin", "(", "(", "0.191", "/", "0.191", ")", "^", "(", "0.191", "*", "0.191", ")", ")", "/", "acos", "(", "0.136", ")", "/", "tan", "(", "0.702", ")", "+", "sqrt", "(", "(", "0.849", "+", "0.849", ")", "-", "(", "0.357", "/", "0.849", ")", ")", "/", "tan", "(", "0.363", ")", "-", "atan", "(", "0.70", ")", "/", "cos", "(", "(", "0.75", "+", "0.75", ")", "^", "(", "0.75", "*", "0.75", ")", ")", "/", "atan", "(", "0.888", ")", "/", "asin", "(", "0.167", ")", "*", "log", "(", "(", "0.794", "*", "0.794", ")", "/", "(", "0.794", "^", "0.794", ")", ")", "^", "ctg", "(", "0.267", ")", "^", "0.867"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.103)-tan(0.678)*asin((0.191/0.191)^(0.191*0.191))/acos(0.136)/tan(0.702)+sqrt((0.849+0.849)-(0.357/0.849))/tan(0.363)-atan(0.70)/cos((0.75+0.75)^(0.75*0.75))/atan(0.888)/asin(0.167)*log((0.794*0.794)/(0.794^0.794))^ctg(0.267)^0.867"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.659", ")", "-", "atan", "(", "0.725", ")", "+", "log", "(", "(", "0.240", "^", "0.240", ")", "*", "(", "x", "+", "0.240", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.659)-atan(0.725)+log((0.240^0.240)*(x+0.240))+"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.1", ")", "+", "actg", "(", "0.42", ")", "+", "cos", "(", "(", "0.976", "*", "0.976", ")", "^", "(", "0.785", "/", "0.976", ")", ")", "*", "sqrt", "(", "0.592", ")", "*", "cos", "(", "0.664", ")", "+", "asin", "(", "(", "0.619", "^", "0.619", ")", "-", "(", "0.619", "^", "0.619", ")", ")", "/", "actg", "(", "0.202", ")", "-", "cos", "(", "0.520", ")", "*", "cos", "(", "(", "0.449", "/", "0.449", ")", "^", "(", "0.449", "+", "0.449", ")", ")", "*", "cos", "(", "0.406", ")", "*", "acos", "(", "0.401", ")", "/", "cos", "(", "(", "0.603", "/", "0.603", ")", "-", "(", "0.603", "*", "0.603", ")", ")", "/", "actg", "(", "0.723", ")", "+", "cos", "(", "0.752", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.1)+actg(0.42)+cos((0.976*0.976)^(0.785/0.976))*sqrt(0.592)*cos(0.664)+asin((0.619^0.619)-(0.619^0.619))/actg(0.202)-cos(0.520)*cos((0.449/0.449)^(0.449+0.449))*cos(0.406)*acos(0.401)/cos((0.603/0.603)-(0.603*0.603))/actg(0.723)+cos(0.752)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.104", ")", "/", "actg", "(", "0.382", ")", "+", "asin", "(", "(", "0.527", "+", "0.527", ")", "*", "(", "x", "*", "0.527", ")", ")", "^", "sin", "(", "0.103", ")", "/", "acos", "(", "0.252", ")", "^", "sqrt", "(", "(", "0.19", "-", "0.19", ")", "/", "(", "0.825", "+", "0.19", ")", ")", "-", "asin", "(", "0.177", ")", "/", "ctg", "(", "0.337", ")", "^", "sqrt", "(", "(", "0.704", "^", "0.704", ")", "^", "(", "0.704", "*", "0.704", ")", ")", "+", "atan", "(", "0.44", ")", "-", "actg", "(", "0.261", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.104)/actg(0.382)+asin((0.527+0.527)*(x*0.527))^sin(0.103)/acos(0.252)^sqrt((0.19-0.19)/(0.825+0.19))-asin(0.177)/ctg(0.337)^sqrt((0.704^0.704)^(0.704*0.704))+atan(0.44)-actg(0.261)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.36", ")", "-", "0.31"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.36)-0.31"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "701", "%", "31"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+701%31"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.453", ")", "*", "cos", "(", "0.163", ")", "/", "log", "(", "(", "0.14", "-", "0.14", ")", "*", "(", "x", "^", "0.14", ")", ")", "^", "sin", "(", "0.333", ")", "/", "sin", "(", "0.183", ")", "-", "tan", "(", "(", "0.982", "+", "0.982", ")", "+", "(", "0.387", "-", "0.982", ")", ")", "^", "acos", "(", "0.746", ")", "-", "atan", "(", "0.128", ")", "+", "asin", "(", "(", "0.371", "+", "0.371", ")", "+", "(", "0.318", "/", "0.371", ")", ")", "-", "log", "(", "0.505", ")", "^", "cos", "(", "0.558", ")", "^", "acos", "(", "(", "0.831", "/", "0.831", ")", "+", "(", "0.195", "/", "0.831", ")", ")", "-", "sin", "(", "0.519", ")", "/", "tan", "(", "0.502", ")", "^", "tan", "(", "(", "0.293", "/", "0.293", ")", "^", "(", "x", "-", "0.293", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.453)*cos(0.163)/log((0.14-0.14)*(x^0.14))^sin(0.333)/sin(0.183)-tan((0.982+0.982)+(0.387-0.982))^acos(0.746)-atan(0.128)+asin((0.371+0.371)+(0.318/0.371))-log(0.505)^cos(0.558)^acos((0.831/0.831)+(0.195/0.831))-sin(0.519)/tan(0.502)^tan((0.293/0.293)^(x-0.293))/"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.246", ")", "^", "0.548"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.246)^0.548"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.321", ")", "/", "atan", "(", "0.933", ")", "^", "sqrt", "(", "(", "0.447", "-", "0.447", ")", "+", "(", "0.231", "/", "0.447", ")", ")", "/", "asin", "(", "0.11", ")", "^", "atan", "(", "0.337", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.321)/atan(0.933)^sqrt((0.447-0.447)+(0.231/0.447))/asin(0.11)^atan(0.337)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.882", ")", "/", "sin", "(", "0.805", ")", "*", "acos", "(", "(", "0.638", "^", "0.638", ")", "/", "(", "0.638", "/", "0.638", ")", ")", "*", "actg", "(", "0.250", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.882)/sin(0.805)*acos((0.638^0.638)/(0.638/0.638))*actg(0.250)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.805", ")", "*", "sqrt", "(", "0.223", ")", "-", "atan", "(", "(", "0.811", "^", "0.811", ")", "-", "(", "0.889", "+", "0.811", ")", ")", "*", "sin", "(", "0.647", ")", "/", "atan", "(", "0.982", ")", "-", "asin", "(", "(", "0.364", "*", "0.364", ")", "+", "(", "0.520", "-", "0.364", ")", ")", "-", "cos", "(", "0.164", ")", "-", "log", "(", "0.423", ")", "-", "sqrt", "(", "(", "0.528", "/", "0.528", ")", "/", "(", "0.528", "+", "0.528", ")", ")", "*", "ln", "(", "0.443", ")", "/", "ctg", "(", "0.368", ")", "+", "atan", "(", "(", "0.466", "-", "0.466", ")", "/", "(", "0.466", "/", "0.466", ")", ")", "+", "sin", "(", "0.751", ")", "-", "sin", "(", "0.160", ")", "/", "sin", "(", "(", "0.945", "*", "0.945", ")", "*", "(", "x", "*", "0.945", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.805)*sqrt(0.223)-atan((0.811^0.811)-(0.889+0.811))*sin(0.647)/atan(0.982)-asin((0.364*0.364)+(0.520-0.364))-cos(0.164)-log(0.423)-sqrt((0.528/0.528)/(0.528+0.528))*ln(0.443)/ctg(0.368)+atan((0.466-0.466)/(0.466/0.466))+sin(0.751)-sin(0.160)/sin((0.945*0.945)*(x*0.945))+"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.934", ")", "/", "acos", "(", "0.465", ")", "/", "ln", "(", "(", "0.685", "/", "0.685", ")", "^", "(", "0.799", "*", "0.685", ")", ")", "*", "sin", "(", "0.468", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.934)/acos(0.465)/ln((0.685/0.685)^(0.799*0.685))*sin(0.468)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.860", ")", "*", "actg", "(", "0.640", ")", "^", "actg", "(", "(", "0.774", "+", "0.774", ")", "+", "(", "0.774", "+", "0.774", ")", ")", "/", "log", "(", "0.40", ")", "+", "acos", "(", "0.598", ")", "-", "log", "(", "(", "0.259", "-", "0.259", ")", "+", "(", "x", "+", "0.259", ")", ")", "+", "acos", "(", "0.539", ")", "-", "sqrt", "(", "0.336", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.860)*actg(0.640)^actg((0.774+0.774)+(0.774+0.774))/log(0.40)+acos(0.598)-log((0.259-0.259)+(x+0.259))+acos(0.539)-sqrt(0.336)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.157", ")", "*", "atan", "(", "0.305", ")", "^", "actg", "(", "(", "0.909", "*", "0.909", ")", "+", "(", "x", "^", "0.909", ")", ")", "^", "tan", "(", "0.864", ")", "^", "atan", "(", "0.137", ")", "+", "actg", "(", "(", "0.421", "*", "0.421", ")", "^", "(", "0.421", "^", "0.421", ")", ")", "^", "atan", "(", "0.51", ")", "+", "sin", "(", "0.100", ")", "/", "log", "(", "(", "0.908", "*", "0.908", ")", "-", "(", "0.908", "*", "0.908", ")", ")", "^", "ln", "(", "0.205", ")", "*", "asin", "(", "0.322", ")", "+", "log", "(", "(", "0.0", "/", "0.0", ")", "+", "(", "0.0", "/", "0.0", ")", ")", "+", "log", "(", "0.185", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.157)*atan(0.305)^actg((0.909*0.909)+(x^0.909))^tan(0.864)^atan(0.137)+actg((0.421*0.421)^(0.421^0.421))^atan(0.51)+sin(0.100)/log((0.908*0.908)-(0.908*0.908))^ln(0.205)*asin(0.322)+log((0.0/0.0)+(0.0/0.0))+log(0.185)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.252", ")", "+", "acos", "(", "0.624", ")", "*", "asin", "(", "(", "0.881", "*", "0.881", ")", "^", "(", "0.772", "^", "0.881", ")", ")", "*", "log", "(", "0.986", ")", "-", "actg", "(", "0.17", ")", "^", "tan", "(", "(", "0.102", "/", "0.102", ")", "*", "(", "x", "^", "0.102", ")", ")", "+", "atan", "(", "0.163", ")", "*", "atan", "(", "0.5", ")", "^", "cos", "(", "(", "0.949", "-", "0.949", ")", "-", "(", "0.949", "*", "0.949", ")", ")", "+", "log", "(", "0.509", ")", "^", "atan", "(", "0.909", ")", "^", "sin", "(", "(", "0.894", "+", "0.894", ")", "-", "(", "0.174", "*", "0.894", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.252)+acos(0.624)*asin((0.881*0.881)^(0.772^0.881))*log(0.986)-actg(0.17)^tan((0.102/0.102)*(x^0.102))+atan(0.163)*atan(0.5)^cos((0.949-0.949)-(0.949*0.949))+log(0.509)^atan(0.909)^sin((0.894+0.894)-(0.174*0.894))*"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.110", ")", "^", "tan", "(", "0.301", ")", "*", "log", "(", "(", "0.690", "^", "0.690", ")", "-", "(", "0.700", "+", "0.690", ")", ")", "/", "atan", "(", "0.202", ")", "+", "tan", "(", "0.98", ")", "^", "ctg", "(", "(", "0.878", "^", "0.878", ")", "/", "(", "0.878", "-", "0.878", ")", ")", "*", "sqrt", "(", "0.646", ")", "/", "ctg", "(", "0.604", ")", "-", "asin", "(", "(", "0.809", "-", "0.809", ")", "+", "(", "x", "+", "0.809", ")", ")", "-", "asin", "(", "0.670", ")", "+", "sqrt", "(", "0.963", ")", "^", "log", "(", "(", "0.897", "*", "0.897", ")", "-", "(", "0.269", "*", "0.897", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.110)^tan(0.301)*log((0.690^0.690)-(0.700+0.690))/atan(0.202)+tan(0.98)^ctg((0.878^0.878)/(0.878-0.878))*sqrt(0.646)/ctg(0.604)-asin((0.809-0.809)+(x+0.809))-asin(0.670)+sqrt(0.963)^log((0.897*0.897)-(0.269*0.897))/"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.667", ")", "-", "sin", "(", "0.7", ")", "/", "sqrt", "(", "(", "0.145", "*", "0.145", ")", "-", "(", "0.712", "^", "0.145", ")", ")", "-", "ln", "(", "0.640", ")", "-", "acos", "(", "0.224", ")", "-", "ln", "(", "(", "0.412", "+", "0.412", ")", "+", "(", "0.412", "-", "0.412", ")", ")", "*", "atan", "(", "0.484", ")", "+", "cos", "(", "0.391", ")", "+", "tan", "(", "(", "0.49", "/", "0.49", ")", "^", "(", "0.899", "^", "0.49", ")", ")", "/", "cos", "(", "0.315", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.667)-sin(0.7)/sqrt((0.145*0.145)-(0.712^0.145))-ln(0.640)-acos(0.224)-ln((0.412+0.412)+(0.412-0.412))*atan(0.484)+cos(0.391)+tan((0.49/0.49)^(0.899^0.49))/cos(0.315)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.805", ")", "-", "actg", "(", "0.827", ")", "+", "sqrt", "(", "(", "0.479", "*", "0.479", ")", "-", "(", "0.479", "^", "0.479", ")", ")", "^", "atan", "(", "0.351", ")", "^", "sin", "(", "0.725", ")", "^", "atan", "(", "(", "0.600", "^", "0.600", ")", "-", "(", "x", "+", "0.600", ")", ")", "-", "sqrt", "(", "0.114", ")", "-", "sqrt", "(", "0.122", ")", "*", "atan", "(", "(", "0.176", "-", "0.176", ")", "*", "(", "x", "+", "0.176", ")", ")", "*", "asin", "(", "0.61", ")", "+", "tan", "(", "0.253", ")", "/", "sin", "(", "(", "0.653", "*", "0.653", ")", "^", "(", "0.653", "-", "0.653", ")", ")", "-", "tan", "(", "0.659", ")", "-", "actg", "(", "0.708", ")", "^", "log", "(", "(", "0.981", "^", "0.981", ")", "*", "(", "0.981", "*", "0.981", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.805)-actg(0.827)+sqrt((0.479*0.479)-(0.479^0.479))^atan(0.351)^sin(0.725)^atan((0.600^0.600)-(x+0.600))-sqrt(0.114)-sqrt(0.122)*atan((0.176-0.176)*(x+0.176))*asin(0.61)+tan(0.253)/sin((0.653*0.653)^(0.653-0.653))-tan(0.659)-actg(0.708)^log((0.981^0.981)*(0.981*0.981))^"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.439", ")", "+", "actg", "(", "0.129", ")", "^", "sin", "(", "(", "0.250", "-", "0.250", ")", "-", "(", "0.250", "*", "0.250", ")", ")", "^", "sqrt", "(", "0.155", ")", "^", "acos", "(", "0.657", ")", "-", "ln", "(", "(", "0.195", "/", "0.195", ")", "+", "(", "0.195", "*", "0.195", ")", ")", "-", "ctg", "(", "0.753", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.439)+actg(0.129)^sin((0.250-0.250)-(0.250*0.250))^sqrt(0.155)^acos(0.657)-ln((0.195/0.195)+(0.195*0.195))-ctg(0.753)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.86", ")", "-", "log", "(", "0.665", ")", "-", "actg", "(", "(", "0.351", "+", "0.351", ")", "/", "(", "0.351", "+", "0.351", ")", ")", "+", "acos", "(", "0.20", ")", "^", "log", "(", "0.162", ")", "/", "atan", "(", "(", "0.537", "-", "0.537", ")", "+", "(", "0.693", "+", "0.537", ")", ")", "/", "tan", "(", "0.46", ")", "/", "tan", "(", "0.560", ")", "*", "tan", "(", "(", "0.126", "/", "0.126", ")", "-", "(", "0.100", "/", "0.126", ")", ")", "+", "actg", "(", "0.669", ")", "^", "tan", "(", "0.602", ")", "*", "acos", "(", "(", "0.952", "^", "0.952", ")", "^", "(", "0.952", "+", "0.952", ")", ")", "+", "log", "(", "0.404", ")", "+", "sin", "(", "0.370", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.86)-log(0.665)-actg((0.351+0.351)/(0.351+0.351))+acos(0.20)^log(0.162)/atan((0.537-0.537)+(0.693+0.537))/tan(0.46)/tan(0.560)*tan((0.126/0.126)-(0.100/0.126))+actg(0.669)^tan(0.602)*acos((0.952^0.952)^(0.952+0.952))+log(0.404)+sin(0.370)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.62", ")", "/", "cos", "(", "0.840", ")", "+", "atan", "(", "(", "0.711", "*", "0.711", ")", "-", "(", "0.678", "^", "0.711", ")", ")", "*", "ctg", "(", "0.783", ")", "-", "0.348"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.62)/cos(0.840)+atan((0.711*0.711)-(0.678^0.711))*ctg(0.783)-0.348"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.623", ")", "-", "asin", "(", "0.616", ")", "+", "sin", "(", "(", "0.642", "-", "0.642", ")", "+", "(", "0.426", "^", "0.642", ")", ")", "+", "actg", "(", "0.701", ")", "/", "cos", "(", "0.236", ")", "-", "ctg", "(", "(", "0.217", "-", "0.217", ")", "-", "(", "0.427", "*", "0.217", ")", ")", "^", "sin", "(", "0.189", ")", "/", "actg", "(", "0.199", ")", "-", "log", "(", "(", "0.27", "-", "0.27", ")", "+", "(", "0.27", "/", "0.27", ")", ")", "-", "asin", "(", "0.443", ")", "*", "asin", "(", "0.349", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.623)-asin(0.616)+sin((0.642-0.642)+(0.426^0.642))+actg(0.701)/cos(0.236)-ctg((0.217-0.217)-(0.427*0.217))^sin(0.189)/actg(0.199)-log((0.27-0.27)+(0.27/0.27))-asin(0.443)*asin(0.349)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.499", ")", "-", "sin", "(", "0.840", ")", "+", "tan", "(", "(", "0.635", "+", "0.635", ")", "/", "(", "0.262", "-", "0.635", ")", ")", "*", "cos", "(", "0.59", ")", "*", "actg", "(", "0.736", ")", "+", "ctg", "(", "(", "0.697", "+", "0.697", ")", "-", "(", "x", "+", "0.697", ")", ")", "+", "atan", "(", "0.652", ")", "^", "ln", "(", "0.372", ")", "/", "acos", "(", "(", "0.577", "+", "0.577", ")", "^", "(", "0.482", "+", "0.577", ")", ")", "*", "atan", "(", "0.167", ")", "-", "cos", "(", "0.350", ")", "*", "actg", "(", "(", "0.475", "^", "0.475", ")", "+", "(", "0.475", "/", "0.475", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.499)-sin(0.840)+tan((0.635+0.635)/(0.262-0.635))*cos(0.59)*actg(0.736)+ctg((0.697+0.697)-(x+0.697))+atan(0.652)^ln(0.372)/acos((0.577+0.577)^(0.482+0.577))*atan(0.167)-cos(0.350)*actg((0.475^0.475)+(0.475/0.475))-"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.715", ")", "-", "acos", "(", "0.99", ")", "-", "acos", "(", "(", "0.948", "/", "0.948", ")", "-", "(", "x", "+", "0.948", ")", ")", "*", "sqrt", "(", "0.26", ")", "*", "cos", "(", "0.878", ")", "/", "asin", "(", "(", "0.794", "/", "0.794", ")", "*", "(", "0.794", "^", "0.794", ")", ")", "-", "actg", "(", "0.561", ")", "+", "ctg", "(", "0.215", ")", "/", "ctg", "(", "(", "0.389", "/", "0.389", ")", "*", "(", "0.389", "*", "0.389", ")", ")", "^", "ln", "(", "0.613", ")", "-", "cos", "(", "0.253", ")", "/", "actg", "(", "(", "0.348", "*", "0.348", ")", "*", "(", "x", "+", "0.348", ")", ")", "^", "atan", "(", "0.303", ")", "*", "tan", "(", "0.120", ")", "*", "ln", "(", "(", "0.720", "^", "0.720", ")", "-", "(", "0.973", "/", "0.720", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.715)-acos(0.99)-acos((0.948/0.948)-(x+0.948))*sqrt(0.26)*cos(0.878)/asin((0.794/0.794)*(0.794^0.794))-actg(0.561)+ctg(0.215)/ctg((0.389/0.389)*(0.389*0.389))^ln(0.613)-cos(0.253)/actg((0.348*0.348)*(x+0.348))^atan(0.303)*tan(0.120)*ln((0.720^0.720)-(0.973/0.720))^"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.796", ")", "/", "acos", "(", "0.245", ")", "/", "atan", "(", "(", "0.895", "/", "0.895", ")", "+", "(", "x", "/", "0.895", ")", ")", "+", "tan", "(", "0.12", ")", "+", "cos", "(", "0.628", ")", "/", "tan", "(", "(", "0.622", "+", "0.622", ")", "/", "(", "x", "^", "0.622", ")", ")", "/", "sin", "(", "0.38", ")", "/", "actg", "(", "0.175", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.796)/acos(0.245)/atan((0.895/0.895)+(x/0.895))+tan(0.12)+cos(0.628)/tan((0.622+0.622)/(x^0.622))/sin(0.38)/actg(0.175)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "22", "%", "296"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+22%296"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.283", ")", "-", "ln", "(", "0.170", ")", "-", "log", "(", "(", "0.624", "-", "0.624", ")", "/", "(", "x", "+", "0.624", ")", ")", "^", "cos", "(", "0.410", ")", "-", "actg", "(", "0.874", ")", "+", "sqrt", "(", "(", "0.647", "/", "0.647", ")", "*", "(", "0.274", "^", "0.647", ")", ")", "-", "tan", "(", "0.821", ")", "+", "actg", "(", "0.692", ")", "+", "ctg", "(", "(", "0.4", "-", "0.4", ")", "/", "(", "0.16", "^", "0.4", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.283)-ln(0.170)-log((0.624-0.624)/(x+0.624))^cos(0.410)-actg(0.874)+sqrt((0.647/0.647)*(0.274^0.647))-tan(0.821)+actg(0.692)+ctg((0.4-0.4)/(0.16^0.4))-"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.710", ")", "*", "acos", "(", "0.576", ")", "-", "asin", "(", "(", "0.210", "/", "0.210", ")", "+", "(", "0.210", "+", "0.210", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.710)*acos(0.576)-asin((0.210/0.210)+(0.210+0.210))/"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.751", ")", "*", "sqrt", "(", "0.506", ")", "/", "cos", "(", "(", "0.943", "*", "0.943", ")", "/", "(", "x", "^", "0.943", ")", ")", "^", "actg", "(", "0.409", ")", "/", "acos", "(", "0.802", ")", "*", "sqrt", "(", "(", "0.658", "-", "0.658", ")", "/", "(", "x", "*", "0.658", ")", ")", "-", "ctg", "(", "0.641", ")", "-", "ln", "(", "0.600", ")", "*", "ctg", "(", "(", "0.726", "^", "0.726", ")", "*", "(", "0.46", "*", "0.726", ")", ")", "/", "atan", "(", "0.955", ")", "/", "acos", "(", "0.223", ")", "^", "actg", "(", "(", "0.443", "*", "0.443", ")", "^", "(", "x", "-", "0.443", ")", ")", "*", "sin", "(", "0.248", ")", "+", "tan", "(", "0.403", ")", "*", "atan", "(", "(", "0.555", "^", "0.555", ")", "+", "(", "0.628", "-", "0.555", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.751)*sqrt(0.506)/cos((0.943*0.943)/(x^0.943))^actg(0.409)/acos(0.802)*sqrt((0.658-0.658)/(x*0.658))-ctg(0.641)-ln(0.600)*ctg((0.726^0.726)*(0.46*0.726))/atan(0.955)/acos(0.223)^actg((0.443*0.443)^(x-0.443))*sin(0.248)+tan(0.403)*atan((0.555^0.555)+(0.628-0.555))+"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "392", "%", "553"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+392%553"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "451", "%", "421"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+451%421"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "471", "%", "918"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+471%918"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.143", ")", "/", "sin", "(", "0.41", ")", "*", "sin", "(", "(", "0.719", "*", "0.719", ")", "+", "(", "0.719", "/", "0.719", ")", ")", "+", "acos", "(", "0.497", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.143)/sin(0.41)*sin((0.719*0.719)+(0.719/0.719))+acos(0.497)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "585", "%", "47"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+585%47"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.30", ")", "+", "actg", "(", "0.750", ")", "/", "log", "(", "(", "0.549", "+", "0.549", ")", "*", "(", "x", "^", "0.549", ")", ")", "/", "ctg", "(", "0.400", ")", "*", "atan", "(", "0.834", ")", "*", "log", "(", "(", "0.43", "^", "0.43", ")", "^", "(", "0.43", "*", "0.43", ")", ")", "*", "cos", "(", "0.831", ")", "/", "0.561"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.30)+actg(0.750)/log((0.549+0.549)*(x^0.549))/ctg(0.400)*atan(0.834)*log((0.43^0.43)^(0.43*0.43))*cos(0.831)/0.561"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.802", ")", "/", "log", "(", "0.287", ")", "*", "ctg", "(", "(", "0.967", "^", "0.967", ")", "^", "(", "0.967", "*", "0.967", ")", ")", "*", "ln", "(", "0.35", ")", "+", "acos", "(", "0.405", ")", "+", "tan", "(", "(", "0.306", "-", "0.306", ")", "/", "(", "x", "+", "0.306", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.802)/log(0.287)*ctg((0.967^0.967)^(0.967*0.967))*ln(0.35)+acos(0.405)+tan((0.306-0.306)/(x+0.306))/"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.38", ")", "/", "actg", "(", "0.169", ")", "-", "actg", "(", "(", "0.931", "/", "0.931", ")", "-", "(", "0.314", "^", "0.931", ")", ")", "^", "actg", "(", "0.811", ")", "/", "atan", "(", "0.706", ")", "*", "actg", "(", "(", "0.660", "^", "0.660", ")", "*", "(", "0.635", "/", "0.660", ")", ")", "-", "sqrt", "(", "0.811", ")", "-", "cos", "(", "0.347", ")", "-", "tan", "(", "(", "0.844", "+", "0.844", ")", "^", "(", "x", "-", "0.844", ")", ")", "-", "ln", "(", "0.32", ")", "+", "sqrt", "(", "0.417", ")", "^", "log", "(", "(", "0.242", "-", "0.242", ")", "^", "(", "0.242", "*", "0.242", ")", ")", "*", "atan", "(", "0.877", ")", "^", "0.471"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.38)/actg(0.169)-actg((0.931/0.931)-(0.314^0.931))^actg(0.811)/atan(0.706)*actg((0.660^0.660)*(0.635/0.660))-sqrt(0.811)-cos(0.347)-tan((0.844+0.844)^(x-0.844))-ln(0.32)+sqrt(0.417)^log((0.242-0.242)^(0.242*0.242))*atan(0.877)^0.471"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.101", ")", "^", "ln", "(", "0.497", ")", "*", "log", "(", "(", "0.992", "^", "0.992", ")", "-", "(", "x", "+", "0.992", ")", ")", "*", "tan", "(", "0.381", ")", "/", "actg", "(", "0.165", ")", "+", "sqrt", "(", "(", "0.105", "*", "0.105", ")", "-", "(", "0.105", "*", "0.105", ")", ")", "+", "ln", "(", "0.715", ")", "-", "tan", "(", "0.830", ")", "^", "acos", "(", "(", "0.673", "*", "0.673", ")", "-", "(", "0.673", "*", "0.673", ")", ")", "-", "cos", "(", "0.451", ")", "+", "ln", "(", "0.840", ")", "^", "tan", "(", "(", "0.465", "+", "0.465", ")", "^", "(", "0.465", "-", "0.465", ")", ")", "/", "acos", "(", "0.900", ")", "*", "sqrt", "(", "0.29", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.101)^ln(0.497)*log((0.992^0.992)-(x+0.992))*tan(0.381)/actg(0.165)+sqrt((0.105*0.105)-(0.105*0.105))+ln(0.715)-tan(0.830)^acos((0.673*0.673)-(0.673*0.673))-cos(0.451)+ln(0.840)^tan((0.465+0.465)^(0.465-0.465))/acos(0.900)*sqrt(0.29)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.412", ")", "^", "ln", "(", "0.410", ")", "/", "cos", "(", "(", "0.324", "/", "0.324", ")", "^", "(", "x", "*", "0.324", ")", ")", "^", "acos", "(", "0.827", ")", "/", "sin", "(", "0.16", ")", "+", "ctg", "(", "(", "0.15", "^", "0.15", ")", "^", "(", "x", "+", "0.15", ")", ")", "+", "sqrt", "(", "0.598", ")", "/", "cos", "(", "0.483", ")", "/", "asin", "(", "(", "0.628", "/", "0.628", ")", "+", "(", "0.784", "^", "0.628", ")", ")", "-", "log", "(", "0.869", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.412)^ln(0.410)/cos((0.324/0.324)^(x*0.324))^acos(0.827)/sin(0.16)+ctg((0.15^0.15)^(x+0.15))+sqrt(0.598)/cos(0.483)/asin((0.628/0.628)+(0.784^0.628))-log(0.869)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.631", ")", "^", "tan", "(", "0.981", ")", "^", "ctg", "(", "(", "0.203", "^", "0.203", ")", "*", "(", "0.203", "-", "0.203", ")", ")", "+", "sin", "(", "0.371", ")", "*", "ctg", "(", "0.573", ")", "*", "ln", "(", "(", "0.614", "^", "0.614", ")", "^", "(", "0.933", "-", "0.614", ")", ")", "^", "cos", "(", "0.847", ")", "/", "log", "(", "0.776", ")", "-", "tan", "(", "(", "0.356", "*", "0.356", ")", "*", "(", "0.356", "*", "0.356", ")", ")", "-", "sqrt", "(", "0.92", ")", "/", "atan", "(", "0.252", ")", "/", "acos", "(", "(", "0.372", "^", "0.372", ")", "-", "(", "x", "+", "0.372", ")", ")", "-", "log", "(", "0.232", ")", "^", "sin", "(", "0.880", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.631)^tan(0.981)^ctg((0.203^0.203)*(0.203-0.203))+sin(0.371)*ctg(0.573)*ln((0.614^0.614)^(0.933-0.614))^cos(0.847)/log(0.776)-tan((0.356*0.356)*(0.356*0.356))-sqrt(0.92)/atan(0.252)/acos((0.372^0.372)-(x+0.372))-log(0.232)^sin(0.880)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.584", ")", "-", "atan", "(", "0.908", ")", "^", "asin", "(", "(", "0.353", "+", "0.353", ")", "^", "(", "0.977", "^", "0.353", ")", ")", "*", "log", "(", "0.46", ")", "*", "ctg", "(", "0.597", ")", "*", "actg", "(", "(", "0.232", "^", "0.232", ")", "/", "(", "0.232", "/", "0.232", ")", ")", "^", "sin", "(", "0.812", ")", "/", "actg", "(", "0.580", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.584)-atan(0.908)^asin((0.353+0.353)^(0.977^0.353))*log(0.46)*ctg(0.597)*actg((0.232^0.232)/(0.232/0.232))^sin(0.812)/actg(0.580)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.181", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.181)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.586", ")", "*", "asin", "(", "0.713", ")", "-", "tan", "(", "(", "0.279", "/", "0.279", ")", "*", "(", "0.497", "-", "0.279", ")", ")", "^", "cos", "(", "0.679", ")", "/", "actg", "(", "0.709", ")", "-", "ctg", "(", "(", "0.4", "+", "0.4", ")", "^", "(", "0.908", "^", "0.4", ")", ")", "^", "sqrt", "(", "0.440", ")", "^", "ln", "(", "0.554", ")", "-", "tan", "(", "(", "0.965", "-", "0.965", ")", "-", "(", "x", "*", "0.965", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.586)*asin(0.713)-tan((0.279/0.279)*(0.497-0.279))^cos(0.679)/actg(0.709)-ctg((0.4+0.4)^(0.908^0.4))^sqrt(0.440)^ln(0.554)-tan((0.965-0.965)-(x*0.965))^"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.694", ")", "*", "tan", "(", "0.749", ")", "^", "sqrt", "(", "(", "0.107", "+", "0.107", ")", "-", "(", "0.87", "^", "0.107", ")", ")", "/", "cos", "(", "0.130", ")", "*", "ln", "(", "0.818", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.694)*tan(0.749)^sqrt((0.107+0.107)-(0.87^0.107))/cos(0.130)*ln(0.818)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.10", ")", "*", "sin", "(", "0.714", ")", "*", "cos", "(", "(", "0.809", "+", "0.809", ")", "*", "(", "0.363", "/", "0.809", ")", ")", "/", "ln", "(", "0.473", ")", "^", "ln", "(", "0.356", ")", "/", "tan", "(", "(", "0.93", "+", "0.93", ")", "+", "(", "x", "-", "0.93", ")", ")", "/", "acos", "(", "0.667", ")", "+", "sqrt", "(", "0.208", ")", "+", "acos", "(", "(", "0.411", "-", "0.411", ")", "+", "(", "x", "*", "0.411", ")", ")", "^", "actg", "(", "0.583", ")", "/", "actg", "(", "0.950", ")", "^", "atan", "(", "(", "0.604", "^", "0.604", ")", "+", "(", "0.604", "^", "0.604", ")", ")", "-", "sin", "(", "0.735", ")", "+", "0.476"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.10)*sin(0.714)*cos((0.809+0.809)*(0.363/0.809))/ln(0.473)^ln(0.356)/tan((0.93+0.93)+(x-0.93))/acos(0.667)+sqrt(0.208)+acos((0.411-0.411)+(x*0.411))^actg(0.583)/actg(0.950)^atan((0.604^0.604)+(0.604^0.604))-sin(0.735)+0.476"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.137", ")", "^", "actg", "(", "0.185", ")", "^", "asin", "(", "(", "0.144", "/", "0.144", ")", "*", "(", "x", "/", "0.144", ")", ")", "+", "ln", "(", "0.84", ")", "*", "log", "(", "0.891", ")", "/", "actg", "(", "(", "0.977", "+", "0.977", ")", "^", "(", "0.977", "-", "0.977", ")", ")", "-", "sin", "(", "0.897", ")", "-", "sqrt", "(", "0.365", ")", "+", "sin", "(", "(", "0.962", "/", "0.962", ")", "/", "(", "x", "^", "0.962", ")", ")", "^", "ln", "(", "0.964", ")", "*", "acos", "(", "0.744", ")", "+", "actg", "(", "(", "0.728", "*", "0.728", ")", "^", "(", "x", "+", "0.728", ")", ")", "^", "cos", "(", "0.668", ")", "^", "acos", "(", "0.249", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.137)^actg(0.185)^asin((0.144/0.144)*(x/0.144))+ln(0.84)*log(0.891)/actg((0.977+0.977)^(0.977-0.977))-sin(0.897)-sqrt(0.365)+sin((0.962/0.962)/(x^0.962))^ln(0.964)*acos(0.744)+actg((0.728*0.728)^(x+0.728))^cos(0.668)^acos(0.249)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.430", ")", "-", "actg", "(", "0.147", ")", "-", "sin", "(", "(", "0.379", "*", "0.379", ")", "*", "(", "x", "*", "0.379", ")", ")", "*", "log", "(", "0.300", ")", "/", "atan", "(", "0.664", ")", "/", "asin", "(", "(", "0.912", "^", "0.912", ")", "/", "(", "0.912", "^", "0.912", ")", ")", "+", "ctg", "(", "0.787", ")", "+", "atan", "(", "0.839", ")", "/", "cos", "(", "(", "0.731", "-", "0.731", ")", "-", "(", "x", "*", "0.731", ")", ")", "/", "asin", "(", "0.857", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.430)-actg(0.147)-sin((0.379*0.379)*(x*0.379))*log(0.300)/atan(0.664)/asin((0.912^0.912)/(0.912^0.912))+ctg(0.787)+atan(0.839)/cos((0.731-0.731)-(x*0.731))/asin(0.857)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.589", ")", "*", "sin", "(", "0.417", ")", "*", "sin", "(", "(", "0.226", "/", "0.226", ")", "+", "(", "0.487", "/", "0.226", ")", ")", "-", "asin", "(", "0.469", ")", "*", "sin", "(", "0.953", ")", "*", "actg", "(", "(", "0.124", "-", "0.124", ")", "^", "(", "0.271", "/", "0.124", ")", ")", "/", "sqrt", "(", "0.710", ")", "/", "ln", "(", "0.323", ")", "^", "actg", "(", "(", "0.361", "^", "0.361", ")", "+", "(", "0.361", "+", "0.361", ")", ")", "/", "sin", "(", "0.851", ")", "^", "0.651"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.589)*sin(0.417)*sin((0.226/0.226)+(0.487/0.226))-asin(0.469)*sin(0.953)*actg((0.124-0.124)^(0.271/0.124))/sqrt(0.710)/ln(0.323)^actg((0.361^0.361)+(0.361+0.361))/sin(0.851)^0.651"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.330", ")", "^", "ctg", "(", "0.373", ")", "^", "asin", "(", "(", "0.271", "^", "0.271", ")", "+", "(", "0.271", "*", "0.271", ")", ")", "-", "atan", "(", "0.884", ")", "*", "asin", "(", "0.613", ")", "^", "asin", "(", "(", "0.955", "-", "0.955", ")", "-", "(", "0.778", "-", "0.955", ")", ")", "/", "log", "(", "0.784", ")", "+", "ln", "(", "0.152", ")", "-", "acos", "(", "(", "0.857", "-", "0.857", ")", "/", "(", "0.127", "+", "0.857", ")", ")", "-", "actg", "(", "0.691", ")", "*", "0.956"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.330)^ctg(0.373)^asin((0.271^0.271)+(0.271*0.271))-atan(0.884)*asin(0.613)^asin((0.955-0.955)-(0.778-0.955))/log(0.784)+ln(0.152)-acos((0.857-0.857)/(0.127+0.857))-actg(0.691)*0.956"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.642", ")", "/", "ctg", "(", "0.518", ")", "/", "acos", "(", "(", "0.729", "-", "0.729", ")", "^", "(", "0.413", "+", "0.729", ")", ")", "-", "sqrt", "(", "0.777", ")", "^", "sqrt", "(", "0.574", ")", "+", "asin", "(", "(", "0.668", "/", "0.668", ")", "+", "(", "0.698", "+", "0.668", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.642)/ctg(0.518)/acos((0.729-0.729)^(0.413+0.729))-sqrt(0.777)^sqrt(0.574)+asin((0.668/0.668)+(0.698+0.668))*"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.666", ")", "/", "ln", "(", "0.508", ")", "/", "sin", "(", "(", "0.925", "+", "0.925", ")", "-", "(", "x", "+", "0.925", ")", ")", "+", "tan", "(", "0.288", ")", "*", "0.138"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.666)/ln(0.508)/sin((0.925+0.925)-(x+0.925))+tan(0.288)*0.138"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.2", ")", "/", "acos", "(", "0.409", ")", "/", "asin", "(", "(", "0.304", "+", "0.304", ")", "-", "(", "x", "*", "0.304", ")", ")", "/", "sin", "(", "0.322", ")", "/", "cos", "(", "0.164", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.2)/acos(0.409)/asin((0.304+0.304)-(x*0.304))/sin(0.322)/cos(0.164)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.92", ")", "+", "ctg", "(", "0.851", ")", "*", "actg", "(", "(", "0.491", "^", "0.491", ")", "*", "(", "x", "^", "0.491", ")", ")", "/", "ctg", "(", "0.713", ")", "*", "asin", "(", "0.415", ")", "/", "log", "(", "(", "0.532", "*", "0.532", ")", "/", "(", "0.103", "/", "0.532", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.92)+ctg(0.851)*actg((0.491^0.491)*(x^0.491))/ctg(0.713)*asin(0.415)/log((0.532*0.532)/(0.103/0.532))^"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.271", ")", "-", "sin", "(", "0.28", ")", "-", "acos", "(", "(", "0.971", "+", "0.971", ")", "+", "(", "x", "-", "0.971", ")", ")", "*", "tan", "(", "0.242", ")", "^", "actg", "(", "0.128", ")", "^", "sin", "(", "(", "0.297", "*", "0.297", ")", "^", "(", "x", "+", "0.297", ")", ")", "*", "ctg", "(", "0.675", ")", "+", "log", "(", "0.175", ")", "*", "actg", "(", "(", "0.197", "/", "0.197", ")", "*", "(", "0.699", "+", "0.197", ")", ")", "/", "sin", "(", "0.330", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.271)-sin(0.28)-acos((0.971+0.971)+(x-0.971))*tan(0.242)^actg(0.128)^sin((0.297*0.297)^(x+0.297))*ctg(0.675)+log(0.175)*actg((0.197/0.197)*(0.699+0.197))/sin(0.330)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.524", ")", "/", "sin", "(", "0.827", ")", "^", "cos", "(", "(", "0.442", "+", "0.442", ")", "^", "(", "0.442", "/", "0.442", ")", ")", "*", "acos", "(", "0.495", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.524)/sin(0.827)^cos((0.442+0.442)^(0.442/0.442))*acos(0.495)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.69", ")", "-", "ln", "(", "0.861", ")", "*", "ctg", "(", "(", "0.304", "+", "0.304", ")", "^", "(", "x", "+", "0.304", ")", ")", "/", "log", "(", "0.911", ")", "-", "ctg", "(", "0.393", ")", "-", "ln", "(", "(", "0.674", "*", "0.674", ")", "^", "(", "0.674", "+", "0.674", ")", ")", "^", "actg", "(", "0.440", ")", "+", "sin", "(", "0.955", ")", "*", "sqrt", "(", "(", "0.700", "/", "0.700", ")", "*", "(", "0.700", "^", "0.700", ")", ")", "/", "log", "(", "0.712", ")", "-", "acos", "(", "0.257", ")", "-", "ln", "(", "(", "0.421", "+", "0.421", ")", "*", "(", "0.421", "*", "0.421", ")", ")", "^", "actg", "(", "0.399", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.69)-ln(0.861)*ctg((0.304+0.304)^(x+0.304))/log(0.911)-ctg(0.393)-ln((0.674*0.674)^(0.674+0.674))^actg(0.440)+sin(0.955)*sqrt((0.700/0.700)*(0.700^0.700))/log(0.712)-acos(0.257)-ln((0.421+0.421)*(0.421*0.421))^actg(0.399)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.240", ")", "^", "asin", "(", "0.431", ")", "+", "ctg", "(", "(", "0.996", "^", "0.996", ")", "/", "(", "0.375", "*", "0.996", ")", ")", "+", "sin", "(", "0.701", ")", "^", "0.12"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.240)^asin(0.431)+ctg((0.996^0.996)/(0.375*0.996))+sin(0.701)^0.12"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.279", ")", "*", "actg", "(", "0.124", ")", "-", "asin", "(", "(", "0.787", "*", "0.787", ")", "/", "(", "0.150", "/", "0.787", ")", ")", "/", "ln", "(", "0.300", ")", "*", "sqrt", "(", "0.915", ")", "+", "ln", "(", "(", "0.444", "+", "0.444", ")", "/", "(", "0.444", "*", "0.444", ")", ")", "+", "log", "(", "0.749", ")", "/", "sqrt", "(", "0.496", ")", "/", "acos", "(", "(", "0.814", "+", "0.814", ")", "*", "(", "x", "*", "0.814", ")", ")", "+", "cos", "(", "0.915", ")", "/", "asin", "(", "0.321", ")", "^", "atan", "(", "(", "0.299", "/", "0.299", ")", "/", "(", "0.299", "/", "0.299", ")", ")", "/", "ctg", "(", "0.861", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.279)*actg(0.124)-asin((0.787*0.787)/(0.150/0.787))/ln(0.300)*sqrt(0.915)+ln((0.444+0.444)/(0.444*0.444))+log(0.749)/sqrt(0.496)/acos((0.814+0.814)*(x*0.814))+cos(0.915)/asin(0.321)^atan((0.299/0.299)/(0.299/0.299))/ctg(0.861)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.766", ")", "-", "ln", "(", "0.114", ")", "*", "log", "(", "(", "0.956", "/", "0.956", ")", "+", "(", "0.956", "*", "0.956", ")", ")", "/", "sin", "(", "0.845", ")", "/", "atan", "(", "0.160", ")", "*", "ln", "(", "(", "0.986", "/", "0.986", ")", "/", "(", "x", "*", "0.986", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.766)-ln(0.114)*log((0.956/0.956)+(0.956*0.956))/sin(0.845)/atan(0.160)*ln((0.986/0.986)/(x*0.986))*"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.53", ")", "+", "asin", "(", "0.459", ")", "+", "sin", "(", "(", "0.113", "-", "0.113", ")", "/", "(", "0.949", "^", "0.113", ")", ")", "-", "ctg", "(", "0.545", ")", "-", "acos", "(", "0.124", ")", "*", "tan", "(", "(", "0.457", "^", "0.457", ")", "^", "(", "0.765", "*", "0.457", ")", ")", "^", "ln", "(", "0.873", ")", "/", "ctg", "(", "0.925", ")", "-", "cos", "(", "(", "0.90", "/", "0.90", ")", "+", "(", "0.90", "/", "0.90", ")", ")", "^", "ln", "(", "0.529", ")", "+", "0.715"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.53)+asin(0.459)+sin((0.113-0.113)/(0.949^0.113))-ctg(0.545)-acos(0.124)*tan((0.457^0.457)^(0.765*0.457))^ln(0.873)/ctg(0.925)-cos((0.90/0.90)+(0.90/0.90))^ln(0.529)+0.715"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.164", ")", "/", "sin", "(", "0.487", ")", "*", "ctg", "(", "(", "0.88", "*", "0.88", ")", "-", "(", "0.88", "/", "0.88", ")", ")", "-", "actg", "(", "0.242", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.164)/sin(0.487)*ctg((0.88*0.88)-(0.88/0.88))-actg(0.242)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.959", ")", "+", "acos", "(", "0.292", ")", "^", "cos", "(", "(", "0.652", "-", "0.652", ")", "^", "(", "0.21", "/", "0.652", ")", ")", "-", "asin", "(", "0.263", ")", "/", "log", "(", "0.790", ")", "^", "sqrt", "(", "(", "0.816", "*", "0.816", ")", "*", "(", "x", "+", "0.816", ")", ")", "/", "ctg", "(", "0.330", ")", "/", "actg", "(", "0.943", ")", "^", "actg", "(", "(", "0.217", "^", "0.217", ")", "-", "(", "0.217", "^", "0.217", ")", ")", "+", "actg", "(", "0.210", ")", "/", "actg", "(", "0.898", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.959)+acos(0.292)^cos((0.652-0.652)^(0.21/0.652))-asin(0.263)/log(0.790)^sqrt((0.816*0.816)*(x+0.816))/ctg(0.330)/actg(0.943)^actg((0.217^0.217)-(0.217^0.217))+actg(0.210)/actg(0.898)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.496", ")", "^", "asin", "(", "0.569", ")", "+", "ln", "(", "(", "0.697", "^", "0.697", ")", "*", "(", "0.697", "-", "0.697", ")", ")", "+", "sqrt", "(", "0.538", ")", "^", "acos", "(", "0.264", ")", "/", "actg", "(", "(", "0.128", "/", "0.128", ")", "/", "(", "0.73", "+", "0.128", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.496)^asin(0.569)+ln((0.697^0.697)*(0.697-0.697))+sqrt(0.538)^acos(0.264)/actg((0.128/0.128)/(0.73+0.128))+"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.792", ")", "^", "ctg", "(", "0.748", ")", "-", "cos", "(", "(", "0.255", "-", "0.255", ")", "^", "(", "0.255", "/", "0.255", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.792)^ctg(0.748)-cos((0.255-0.255)^(0.255/0.255))-"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.782", ")", "-", "log", "(", "0.325", ")", "*", "ln", "(", "(", "0.306", "-", "0.306", ")", "/", "(", "0.225", "+", "0.306", ")", ")", "-", "acos", "(", "0.866", ")", "-", "ln", "(", "0.270", ")", "/", "acos", "(", "(", "0.681", "-", "0.681", ")", "+", "(", "0.681", "/", "0.681", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.782)-log(0.325)*ln((0.306-0.306)/(0.225+0.306))-acos(0.866)-ln(0.270)/acos((0.681-0.681)+(0.681/0.681))+"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.227", ")", "*", "cos", "(", "0.675", ")", "+", "acos", "(", "(", "0.102", "*", "0.102", ")", "/", "(", "x", "^", "0.102", ")", ")", "*", "cos", "(", "0.807", ")", "/", "ctg", "(", "0.329", ")", "-", "ctg", "(", "(", "0.624", "^", "0.624", ")", "*", "(", "0.624", "+", "0.624", ")", ")", "*", "cos", "(", "0.486", ")", "-", "cos", "(", "0.461", ")", "-", "sin", "(", "(", "0.978", "/", "0.978", ")", "*", "(", "0.93", "^", "0.978", ")", ")", "/", "ctg", "(", "0.518", ")", "/", "0.87"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.227)*cos(0.675)+acos((0.102*0.102)/(x^0.102))*cos(0.807)/ctg(0.329)-ctg((0.624^0.624)*(0.624+0.624))*cos(0.486)-cos(0.461)-sin((0.978/0.978)*(0.93^0.978))/ctg(0.518)/0.87"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.436", ")", "+", "atan", "(", "0.704", ")", "+", "sin", "(", "(", "0.274", "^", "0.274", ")", "^", "(", "0.274", "-", "0.274", ")", ")", "*", "ln", "(", "0.501", ")", "/", "sqrt", "(", "0.678", ")", "/", "sin", "(", "(", "0.699", "^", "0.699", ")", "-", "(", "0.699", "^", "0.699", ")", ")", "+", "atan", "(", "0.596", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.436)+atan(0.704)+sin((0.274^0.274)^(0.274-0.274))*ln(0.501)/sqrt(0.678)/sin((0.699^0.699)-(0.699^0.699))+atan(0.596)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.166", ")", "-", "ln", "(", "0.156", ")", "+", "tan", "(", "(", "0.403", "/", "0.403", ")", "-", "(", "0.782", "*", "0.403", ")", ")", "^", "sin", "(", "0.293", ")", "+", "ln", "(", "0.298", ")", "-", "sqrt", "(", "(", "0.327", "/", "0.327", ")", "/", "(", "x", "+", "0.327", ")", ")", "*", "tan", "(", "0.343", ")", "*", "atan", "(", "0.310", ")", "*", "ln", "(", "(", "0.157", "/", "0.157", ")", "*", "(", "0.157", "/", "0.157", ")", ")", "*", "cos", "(", "0.419", ")", "/", "asin", "(", "0.552", ")", "+", "acos", "(", "(", "0.230", "+", "0.230", ")", "-", "(", "0.794", "+", "0.230", ")", ")", "^", "tan", "(", "0.973", ")", "+", "sin", "(", "0.506", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.166)-ln(0.156)+tan((0.403/0.403)-(0.782*0.403))^sin(0.293)+ln(0.298)-sqrt((0.327/0.327)/(x+0.327))*tan(0.343)*atan(0.310)*ln((0.157/0.157)*(0.157/0.157))*cos(0.419)/asin(0.552)+acos((0.230+0.230)-(0.794+0.230))^tan(0.973)+sin(0.506)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.836", ")", "/", "atan", "(", "0.286", ")", "*", "asin", "(", "(", "0.128", "/", "0.128", ")", "/", "(", "0.31", "*", "0.128", ")", ")", "-", "asin", "(", "0.373", ")", "*", "log", "(", "0.963", ")", "/", "asin", "(", "(", "0.91", "*", "0.91", ")", "^", "(", "x", "*", "0.91", ")", ")", "-", "atan", "(", "0.476", ")", "+", "asin", "(", "0.807", ")", "-", "atan", "(", "(", "0.752", "+", "0.752", ")", "+", "(", "x", "*", "0.752", ")", ")", "*", "ctg", "(", "0.714", ")", "+", "ln", "(", "0.471", ")", "/", "ctg", "(", "(", "0.112", "-", "0.112", ")", "+", "(", "0.220", "/", "0.112", ")", ")", "*", "actg", "(", "0.498", ")", "+", "ctg", "(", "0.83", ")", "-", "sqrt", "(", "(", "0.759", "^", "0.759", ")", "-", "(", "0.364", "-", "0.759", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.836)/atan(0.286)*asin((0.128/0.128)/(0.31*0.128))-asin(0.373)*log(0.963)/asin((0.91*0.91)^(x*0.91))-atan(0.476)+asin(0.807)-atan((0.752+0.752)+(x*0.752))*ctg(0.714)+ln(0.471)/ctg((0.112-0.112)+(0.220/0.112))*actg(0.498)+ctg(0.83)-sqrt((0.759^0.759)-(0.364-0.759))-"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.87", ")", "+", "ctg", "(", "0.9", ")", "*", "log", "(", "(", "0.521", "*", "0.521", ")", "+", "(", "0.521", "-", "0.521", ")", ")", "*", "asin", "(", "0.472", ")", "/", "0.930"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.87)+ctg(0.9)*log((0.521*0.521)+(0.521-0.521))*asin(0.472)/0.930"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.37", ")", "-", "sin", "(", "0.781", ")", "+", "actg", "(", "(", "0.892", "*", "0.892", ")", "-", "(", "0.892", "*", "0.892", ")", ")", "/", "actg", "(", "0.204", ")", "^", "cos", "(", "0.932", ")", "-", "actg", "(", "(", "0.825", "*", "0.825", ")", "*", "(", "0.825", "*", "0.825", ")", ")", "/", "ln", "(", "0.973", ")", "*", "atan", "(", "0.376", ")", "*", "sqrt", "(", "(", "0.49", "+", "0.49", ")", "/", "(", "0.512", "-", "0.49", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.37)-sin(0.781)+actg((0.892*0.892)-(0.892*0.892))/actg(0.204)^cos(0.932)-actg((0.825*0.825)*(0.825*0.825))/ln(0.973)*atan(0.376)*sqrt((0.49+0.49)/(0.512-0.49))/"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.655", ")", "^", "ctg", "(", "0.513", ")", "/", "asin", "(", "(", "0.972", "-", "0.972", ")", "/", "(", "x", "-", "0.972", ")", ")", "/", "atan", "(", "0.454", ")", "+", "ctg", "(", "0.113", ")", "+", "tan", "(", "(", "0.819", "-", "0.819", ")", "^", "(", "0.819", "+", "0.819", ")", ")", "*", "sin", "(", "0.846", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.655)^ctg(0.513)/asin((0.972-0.972)/(x-0.972))/atan(0.454)+ctg(0.113)+tan((0.819-0.819)^(0.819+0.819))*sin(0.846)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.333", ")", "-", "log", "(", "0.162", ")", "+", "sqrt", "(", "(", "0.462", "^", "0.462", ")", "/", "(", "0.967", "*", "0.462", ")", ")", "^", "tan", "(", "0.405", ")", "/", "ln", "(", "0.209", ")", "-", "actg", "(", "(", "0.859", "-", "0.859", ")", "/", "(", "x", "/", "0.859", ")", ")", "-", "ctg", "(", "0.530", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.333)-log(0.162)+sqrt((0.462^0.462)/(0.967*0.462))^tan(0.405)/ln(0.209)-actg((0.859-0.859)/(x/0.859))-ctg(0.530)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.703", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.703)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "983", "%", "606"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+983%606"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.559", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.559)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.486", ")", "+", "ln", "(", "0.50", ")", "-", "acos", "(", "(", "0.147", "^", "0.147", ")", "*", "(", "x", "+", "0.147", ")", ")", "-", "ln", "(", "0.415", ")", "-", "sin", "(", "0.622", ")", "-", "ln", "(", "(", "0.631", "/", "0.631", ")", "^", "(", "0.631", "-", "0.631", ")", ")", "+", "sin", "(", "0.576", ")", "^", "asin", "(", "0.978", ")", "*", "atan", "(", "(", "0.931", "^", "0.931", ")", "+", "(", "0.989", "+", "0.931", ")", ")", "^", "acos", "(", "0.49", ")", "-", "sqrt", "(", "0.466", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.486)+ln(0.50)-acos((0.147^0.147)*(x+0.147))-ln(0.415)-sin(0.622)-ln((0.631/0.631)^(0.631-0.631))+sin(0.576)^asin(0.978)*atan((0.931^0.931)+(0.989+0.931))^acos(0.49)-sqrt(0.466)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.431", ")", "^", "sqrt", "(", "0.10", ")", "+", "tan", "(", "(", "0.662", "-", "0.662", ")", "*", "(", "x", "-", "0.662", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.431)^sqrt(0.10)+tan((0.662-0.662)*(x-0.662))+"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.198", ")", "/", "tan", "(", "0.330", ")", "^", "ctg", "(", "(", "0.885", "-", "0.885", ")", "-", "(", "x", "/", "0.885", ")", ")", "*", "log", "(", "0.533", ")", "*", "atan", "(", "0.768", ")", "-", "ln", "(", "(", "0.770", "/", "0.770", ")", "/", "(", "0.877", "+", "0.770", ")", ")", "/", "atan", "(", "0.7", ")", "/", "acos", "(", "0.35", ")", "/", "actg", "(", "(", "0.113", "+", "0.113", ")", "/", "(", "0.935", "*", "0.113", ")", ")", "/", "actg", "(", "0.855", ")", "*", "log", "(", "0.716", ")", "/", "tan", "(", "(", "0.431", "*", "0.431", ")", "*", "(", "0.182", "/", "0.431", ")", ")", "-", "atan", "(", "0.426", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.198)/tan(0.330)^ctg((0.885-0.885)-(x/0.885))*log(0.533)*atan(0.768)-ln((0.770/0.770)/(0.877+0.770))/atan(0.7)/acos(0.35)/actg((0.113+0.113)/(0.935*0.113))/actg(0.855)*log(0.716)/tan((0.431*0.431)*(0.182/0.431))-atan(0.426)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.550", ")", "-", "sin", "(", "0.640", ")", "*", "acos", "(", "(", "0.65", "*", "0.65", ")", "+", "(", "0.65", "^", "0.65", ")", ")", "+", "ctg", "(", "0.281", ")", "+", "sin", "(", "0.95", ")", "/", "sqrt", "(", "(", "0.754", "*", "0.754", ")", "+", "(", "0.867", "^", "0.754", ")", ")", "^", "sqrt", "(", "0.346", ")", "-", "log", "(", "0.245", ")", "^", "acos", "(", "(", "0.360", "^", "0.360", ")", "*", "(", "0.613", "+", "0.360", ")", ")", "+", "ln", "(", "0.630", ")", "/", "sqrt", "(", "0.586", ")", "+", "sqrt", "(", "(", "0.697", "-", "0.697", ")", "/", "(", "x", "^", "0.697", ")", ")", "+", "asin", "(", "0.445", ")", "+", "tan", "(", "0.217", ")", "/", "sin", "(", "(", "0.199", "/", "0.199", ")", "^", "(", "0.199", "-", "0.199", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.550)-sin(0.640)*acos((0.65*0.65)+(0.65^0.65))+ctg(0.281)+sin(0.95)/sqrt((0.754*0.754)+(0.867^0.754))^sqrt(0.346)-log(0.245)^acos((0.360^0.360)*(0.613+0.360))+ln(0.630)/sqrt(0.586)+sqrt((0.697-0.697)/(x^0.697))+asin(0.445)+tan(0.217)/sin((0.199/0.199)^(0.199-0.199))-"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.87", ")", "-", "ctg", "(", "0.979", ")", "+", "sqrt", "(", "(", "0.797", "^", "0.797", ")", "-", "(", "0.862", "-", "0.797", ")", ")", "*", "cos", "(", "0.128", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.87)-ctg(0.979)+sqrt((0.797^0.797)-(0.862-0.797))*cos(0.128)"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.181", ")", "+", "0.281"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.181)+0.281"};
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.461", ")", "*", "asin", "(", "0.356", ")", "+", "ctg", "(", "(", "0.858", "*", "0.858", ")", "*", "(", "x", "-", "0.858", ")", ")", "-", "actg", "(", "0.350", ")", "-", "tan", "(", "0.325", ")", "^", "atan", "(", "(", "0.490", "+", "0.490", ")", "^", "(", "0.490", "+", "0.490", ")", ")", "-", "atan", "(", "0.386", ")", "^", "log", "(", "0.34", ")", "+", "cos", "(", "(", "0.106", "/", "0.106", ")", "-", "(", "0.850", "-", "0.106", ")", ")", "^", "acos", "(", "0.827", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.461)*asin(0.356)+ctg((0.858*0.858)*(x-0.858))-actg(0.350)-tan(0.325)^atan((0.490+0.490)^(0.490+0.490))-atan(0.386)^log(0.34)+cos((0.106/0.106)-(0.850-0.106))^acos(0.827)"};
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
