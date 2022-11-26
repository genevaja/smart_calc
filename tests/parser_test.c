#include "../header.h"

START_TEST(parser_1) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.674", ")", "*", "acos", "(", "0.8", ")", "^", "atan", "(", "(", "0.13", "^", "0.13", ")", "+", "(", "0.13", "+", "0.13", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.674)*acos(0.8)^atan((0.13^0.13)+(0.13+0.13))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "159", "%", "704"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+159%704"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.289", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.289)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.925", ")", "/", "ln", "(", "0.856", ")", "^", "tan", "(", "(", "0.857", "-", "0.857", ")", "^", "(", "0.703", "/", "0.857", ")", ")", "^", "sqrt", "(", "0.23", ")", "/", "actg", "(", "0.28", ")", "-", "actg", "(", "(", "0.602", "/", "0.602", ")", "-", "(", "x", "/", "0.602", ")", ")", "/", "cos", "(", "0.792", ")", "*", "0.150"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.925)/ln(0.856)^tan((0.857-0.857)^(0.703/0.857))^sqrt(0.23)/actg(0.28)-actg((0.602/0.602)-(x/0.602))/cos(0.792)*0.150"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.239", ")", "+", "actg", "(", "0.928", ")", "^", "cos", "(", "(", "0.792", "*", "0.792", ")", "-", "(", "x", "/", "0.792", ")", ")", "+", "ctg", "(", "0.407", ")", "/", "actg", "(", "0.876", ")", "/", "sin", "(", "(", "0.761", "^", "0.761", ")", "*", "(", "x", "^", "0.761", ")", ")", "-", "sin", "(", "0.392", ")", "^", "sin", "(", "0.610", ")", "*", "ln", "(", "(", "0.553", "*", "0.553", ")", "-", "(", "0.553", "-", "0.553", ")", ")", "/", "cos", "(", "0.764", ")", "*", "ln", "(", "0.640", ")", "+", "ctg", "(", "(", "0.103", "+", "0.103", ")", "-", "(", "0.887", "*", "0.103", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.239)+actg(0.928)^cos((0.792*0.792)-(x/0.792))+ctg(0.407)/actg(0.876)/sin((0.761^0.761)*(x^0.761))-sin(0.392)^sin(0.610)*ln((0.553*0.553)-(0.553-0.553))/cos(0.764)*ln(0.640)+ctg((0.103+0.103)-(0.887*0.103))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "15", "%", "827"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+15%827"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.575", ")", "+", "0.996"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.575)+0.996"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.943", ")", "/", "asin", "(", "0.423", ")", "+", "ctg", "(", "(", "0.351", "*", "0.351", ")", "/", "(", "x", "+", "0.351", ")", ")", "^", "ln", "(", "0.349", ")", "+", "cos", "(", "0.697", ")", "^", "acos", "(", "(", "0.878", "/", "0.878", ")", "/", "(", "0.878", "*", "0.878", ")", ")", "+", "cos", "(", "0.632", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.943)/asin(0.423)+ctg((0.351*0.351)/(x+0.351))^ln(0.349)+cos(0.697)^acos((0.878/0.878)/(0.878*0.878))+cos(0.632)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.764", ")", "/", "ln", "(", "0.113", ")", "+", "ctg", "(", "(", "0.48", "/", "0.48", ")", "^", "(", "0.52", "^", "0.48", ")", ")", "/", "ln", "(", "0.244", ")", "-", "0.90"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.764)/ln(0.113)+ctg((0.48/0.48)^(0.52^0.48))/ln(0.244)-0.90"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.551", ")", "^", "ln", "(", "0.749", ")", "*", "sqrt", "(", "(", "0.149", "/", "0.149", ")", "-", "(", "x", "*", "0.149", ")", ")", "-", "log", "(", "0.173", ")", "-", "log", "(", "0.744", ")", "^", "sqrt", "(", "(", "0.409", "-", "0.409", ")", "+", "(", "x", "^", "0.409", ")", ")", "^", "asin", "(", "0.33", ")", "/", "sqrt", "(", "0.578", ")", "*", "sqrt", "(", "(", "0.194", "*", "0.194", ")", "/", "(", "x", "^", "0.194", ")", ")", "^", "tan", "(", "0.173", ")", "+", "0.920"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.551)^ln(0.749)*sqrt((0.149/0.149)-(x*0.149))-log(0.173)-log(0.744)^sqrt((0.409-0.409)+(x^0.409))^asin(0.33)/sqrt(0.578)*sqrt((0.194*0.194)/(x^0.194))^tan(0.173)+0.920"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.6", ")", "*", "ln", "(", "0.181", ")", "^", "atan", "(", "(", "0.900", "+", "0.900", ")", "/", "(", "0.900", "*", "0.900", ")", ")", "/", "tan", "(", "0.928", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.6)*ln(0.181)^atan((0.900+0.900)/(0.900*0.900))/tan(0.928)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.123", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.123)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.453", ")", "*", "sin", "(", "0.847", ")", "^", "tan", "(", "(", "0.16", "^", "0.16", ")", "*", "(", "x", "/", "0.16", ")", ")", "*", "atan", "(", "0.156", ")", "^", "asin", "(", "0.762", ")", "+", "sqrt", "(", "(", "0.635", "+", "0.635", ")", "*", "(", "x", "^", "0.635", ")", ")", "/", "ln", "(", "0.972", ")", "/", "sin", "(", "0.644", ")", "+", "actg", "(", "(", "0.189", "^", "0.189", ")", "+", "(", "0.372", "*", "0.189", ")", ")", "-", "ctg", "(", "0.44", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.453)*sin(0.847)^tan((0.16^0.16)*(x/0.16))*atan(0.156)^asin(0.762)+sqrt((0.635+0.635)*(x^0.635))/ln(0.972)/sin(0.644)+actg((0.189^0.189)+(0.372*0.189))-ctg(0.44)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.460", ")", "/", "sqrt", "(", "0.471", ")", "+", "atan", "(", "(", "0.974", "+", "0.974", ")", "^", "(", "0.872", "*", "0.974", ")", ")", "*", "acos", "(", "0.805", ")", "^", "ctg", "(", "0.890", ")", "*", "ctg", "(", "(", "0.690", "+", "0.690", ")", "-", "(", "0.690", "/", "0.690", ")", ")", "*", "atan", "(", "0.40", ")", "^", "actg", "(", "0.630", ")", "/", "ctg", "(", "(", "0.577", "/", "0.577", ")", "*", "(", "0.577", "+", "0.577", ")", ")", "*", "ctg", "(", "0.373", ")", "*", "atan", "(", "0.413", ")", "^", "log", "(", "(", "0.21", "-", "0.21", ")", "/", "(", "x", "/", "0.21", ")", ")", "^", "asin", "(", "0.504", ")", "+", "ln", "(", "0.27", ")", "/", "ln", "(", "(", "0.475", "/", "0.475", ")", "-", "(", "0.475", "*", "0.475", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.460)/sqrt(0.471)+atan((0.974+0.974)^(0.872*0.974))*acos(0.805)^ctg(0.890)*ctg((0.690+0.690)-(0.690/0.690))*atan(0.40)^actg(0.630)/ctg((0.577/0.577)*(0.577+0.577))*ctg(0.373)*atan(0.413)^log((0.21-0.21)/(x/0.21))^asin(0.504)+ln(0.27)/ln((0.475/0.475)-(0.475*0.475))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.627", ")", "-", "ctg", "(", "0.412", ")", "^", "atan", "(", "(", "0.549", "^", "0.549", ")", "+", "(", "0.965", "*", "0.549", ")", ")", "*", "ln", "(", "0.131", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.627)-ctg(0.412)^atan((0.549^0.549)+(0.965*0.549))*ln(0.131)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.440", ")", "*", "cos", "(", "0.714", ")", "*", "ctg", "(", "(", "0.941", "*", "0.941", ")", "/", "(", "x", "/", "0.941", ")", ")", "*", "asin", "(", "0.76", ")", "+", "cos", "(", "0.43", ")", "/", "sqrt", "(", "(", "0.600", "-", "0.600", ")", "/", "(", "0.600", "^", "0.600", ")", ")", "*", "actg", "(", "0.790", ")", "+", "asin", "(", "0.949", ")", "^", "asin", "(", "(", "0.250", "*", "0.250", ")", "+", "(", "x", "-", "0.250", ")", ")", "*", "acos", "(", "0.406", ")", "/", "sin", "(", "0.350", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.440)*cos(0.714)*ctg((0.941*0.941)/(x/0.941))*asin(0.76)+cos(0.43)/sqrt((0.600-0.600)/(0.600^0.600))*actg(0.790)+asin(0.949)^asin((0.250*0.250)+(x-0.250))*acos(0.406)/sin(0.350)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.410", ")", "*", "cos", "(", "0.808", ")", "-", "atan", "(", "(", "0.97", "*", "0.97", ")", "-", "(", "0.107", "*", "0.97", ")", ")", "-", "log", "(", "0.110", ")", "^", "sin", "(", "0.985", ")", "^", "asin", "(", "(", "0.695", "+", "0.695", ")", "/", "(", "0.695", "-", "0.695", ")", ")", "/", "ln", "(", "0.164", ")", "*", "tan", "(", "0.755", ")", "^", "cos", "(", "(", "0.725", "^", "0.725", ")", "^", "(", "0.725", "*", "0.725", ")", ")", "+", "actg", "(", "0.159", ")", "+", "sin", "(", "0.432", ")", "+", "asin", "(", "(", "0.376", "*", "0.376", ")", "/", "(", "0.376", "/", "0.376", ")", ")", "-", "log", "(", "0.313", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.410)*cos(0.808)-atan((0.97*0.97)-(0.107*0.97))-log(0.110)^sin(0.985)^asin((0.695+0.695)/(0.695-0.695))/ln(0.164)*tan(0.755)^cos((0.725^0.725)^(0.725*0.725))+actg(0.159)+sin(0.432)+asin((0.376*0.376)/(0.376/0.376))-log(0.313)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.993", ")", "^", "cos", "(", "0.24", ")", "/", "atan", "(", "(", "0.372", "+", "0.372", ")", "^", "(", "0.372", "-", "0.372", ")", ")", "*", "sqrt", "(", "0.719", ")", "+", "sqrt", "(", "0.230", ")", "*", "atan", "(", "(", "0.158", "^", "0.158", ")", "*", "(", "0.128", "-", "0.158", ")", ")", "+", "log", "(", "0.500", ")", "+", "asin", "(", "0.126", ")", "*", "sqrt", "(", "(", "0.921", "/", "0.921", ")", "^", "(", "0.921", "/", "0.921", ")", ")", "+", "ctg", "(", "0.684", ")", "+", "atan", "(", "0.76", ")", "/", "cos", "(", "(", "0.38", "^", "0.38", ")", "/", "(", "0.38", "+", "0.38", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.993)^cos(0.24)/atan((0.372+0.372)^(0.372-0.372))*sqrt(0.719)+sqrt(0.230)*atan((0.158^0.158)*(0.128-0.158))+log(0.500)+asin(0.126)*sqrt((0.921/0.921)^(0.921/0.921))+ctg(0.684)+atan(0.76)/cos((0.38^0.38)/(0.38+0.38))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.3", ")", "-", "tan", "(", "0.702", ")", "^", "cos", "(", "(", "0.260", "*", "0.260", ")", "*", "(", "0.260", "^", "0.260", ")", ")", "*", "sin", "(", "0.939", ")", "/", "0.12"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.3)-tan(0.702)^cos((0.260*0.260)*(0.260^0.260))*sin(0.939)/0.12"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.956", ")", "*", "0.824"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.956)*0.824"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.435", ")", "+", "actg", "(", "0.67", ")", "-", "acos", "(", "(", "0.57", "*", "0.57", ")", "-", "(", "0.57", "-", "0.57", ")", ")", "^", "sin", "(", "0.152", ")", "-", "asin", "(", "0.621", ")", "/", "tan", "(", "(", "0.478", "+", "0.478", ")", "+", "(", "0.205", "/", "0.478", ")", ")", "+", "ctg", "(", "0.221", ")", "^", "ctg", "(", "0.481", ")", "*", "tan", "(", "(", "0.351", "/", "0.351", ")", "/", "(", "x", "-", "0.351", ")", ")", "-", "cos", "(", "0.936", ")", "*", "sqrt", "(", "0.481", ")", "*", "sqrt", "(", "(", "0.944", "-", "0.944", ")", "+", "(", "x", "^", "0.944", ")", ")", "+", "tan", "(", "0.11", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.435)+actg(0.67)-acos((0.57*0.57)-(0.57-0.57))^sin(0.152)-asin(0.621)/tan((0.478+0.478)+(0.205/0.478))+ctg(0.221)^ctg(0.481)*tan((0.351/0.351)/(x-0.351))-cos(0.936)*sqrt(0.481)*sqrt((0.944-0.944)+(x^0.944))+tan(0.11)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.417", ")", "^", "tan", "(", "0.554", ")", "^", "tan", "(", "(", "0.358", "*", "0.358", ")", "*", "(", "0.817", "*", "0.358", ")", ")", "^", "ln", "(", "0.608", ")", "+", "log", "(", "0.746", ")", "^", "ln", "(", "(", "0.98", "-", "0.98", ")", "-", "(", "0.98", "+", "0.98", ")", ")", "^", "ln", "(", "0.277", ")", "*", "log", "(", "0.730", ")", "/", "ln", "(", "(", "0.765", "+", "0.765", ")", "^", "(", "0.764", "^", "0.765", ")", ")", "-", "atan", "(", "0.784", ")", "+", "actg", "(", "0.824", ")", "^", "acos", "(", "(", "0.354", "*", "0.354", ")", "-", "(", "0.354", "^", "0.354", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.417)^tan(0.554)^tan((0.358*0.358)*(0.817*0.358))^ln(0.608)+log(0.746)^ln((0.98-0.98)-(0.98+0.98))^ln(0.277)*log(0.730)/ln((0.765+0.765)^(0.764^0.765))-atan(0.784)+actg(0.824)^acos((0.354*0.354)-(0.354^0.354))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.393", ")", "-", "actg", "(", "0.772", ")", "/", "sqrt", "(", "(", "0.548", "/", "0.548", ")", "*", "(", "0.381", "/", "0.548", ")", ")", "-", "log", "(", "0.824", ")", "*", "atan", "(", "0.333", ")", "*", "actg", "(", "(", "0.242", "^", "0.242", ")", "*", "(", "x", "+", "0.242", ")", ")", "/", "log", "(", "0.546", ")", "^", "atan", "(", "0.827", ")", "/", "tan", "(", "(", "0.406", "*", "0.406", ")", "+", "(", "x", "/", "0.406", ")", ")", "^", "cos", "(", "0.469", ")", "*", "sin", "(", "0.914", ")", "-", "log", "(", "(", "0.701", "/", "0.701", ")", "*", "(", "0.399", "*", "0.701", ")", ")", "^", "ln", "(", "0.301", ")", "-", "asin", "(", "0.518", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.393)-actg(0.772)/sqrt((0.548/0.548)*(0.381/0.548))-log(0.824)*atan(0.333)*actg((0.242^0.242)*(x+0.242))/log(0.546)^atan(0.827)/tan((0.406*0.406)+(x/0.406))^cos(0.469)*sin(0.914)-log((0.701/0.701)*(0.399*0.701))^ln(0.301)-asin(0.518)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.961", ")", "*", "asin", "(", "0.474", ")", "^", "ctg", "(", "(", "0.937", "-", "0.937", ")", "-", "(", "0.990", "*", "0.937", ")", ")", "^", "actg", "(", "0.689", ")", "+", "ctg", "(", "0.926", ")", "-", "asin", "(", "(", "0.638", "+", "0.638", ")", "-", "(", "x", "+", "0.638", ")", ")", "*", "atan", "(", "0.397", ")", "*", "atan", "(", "0.618", ")", "+", "cos", "(", "(", "0.97", "*", "0.97", ")", "/", "(", "x", "/", "0.97", ")", ")", "*", "ln", "(", "0.582", ")", "+", "sin", "(", "0.858", ")", "+", "sin", "(", "(", "0.295", "/", "0.295", ")", "^", "(", "0.295", "*", "0.295", ")", ")", "^", "actg", "(", "0.261", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.961)*asin(0.474)^ctg((0.937-0.937)-(0.990*0.937))^actg(0.689)+ctg(0.926)-asin((0.638+0.638)-(x+0.638))*atan(0.397)*atan(0.618)+cos((0.97*0.97)/(x/0.97))*ln(0.582)+sin(0.858)+sin((0.295/0.295)^(0.295*0.295))^actg(0.261)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.20", ")", "*", "ln", "(", "0.368", ")", "+", "log", "(", "(", "0.69", "+", "0.69", ")", "-", "(", "0.69", "/", "0.69", ")", ")", "/", "tan", "(", "0.132", ")", "^", "tan", "(", "0.854", ")", "^", "ln", "(", "(", "0.103", "^", "0.103", ")", "/", "(", "x", "*", "0.103", ")", ")", "-", "asin", "(", "0.915", ")", "/", "0.528"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.20)*ln(0.368)+log((0.69+0.69)-(0.69/0.69))/tan(0.132)^tan(0.854)^ln((0.103^0.103)/(x*0.103))-asin(0.915)/0.528"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.203", ")", "^", "tan", "(", "0.122", ")", "-", "tan", "(", "(", "0.536", "*", "0.536", ")", "/", "(", "0.453", "/", "0.536", ")", ")", "+", "sin", "(", "0.991", ")", "-", "acos", "(", "0.815", ")", "+", "ln", "(", "(", "0.78", "*", "0.78", ")", "/", "(", "0.724", "+", "0.78", ")", ")", "-", "cos", "(", "0.152", ")", "+", "log", "(", "0.388", ")", "-", "actg", "(", "(", "0.881", "/", "0.881", ")", "^", "(", "0.881", "+", "0.881", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.203)^tan(0.122)-tan((0.536*0.536)/(0.453/0.536))+sin(0.991)-acos(0.815)+ln((0.78*0.78)/(0.724+0.78))-cos(0.152)+log(0.388)-actg((0.881/0.881)^(0.881+0.881))*"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.815", ")", "-", "acos", "(", "0.445", ")", "*", "ctg", "(", "(", "0.494", "-", "0.494", ")", "^", "(", "0.410", "-", "0.494", ")", ")", "/", "asin", "(", "0.266", ")", "+", "ln", "(", "0.683", ")", "*", "sqrt", "(", "(", "0.419", "+", "0.419", ")", "+", "(", "0.419", "/", "0.419", ")", ")", "/", "sin", "(", "0.647", ")", "/", "ln", "(", "0.509", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.815)-acos(0.445)*ctg((0.494-0.494)^(0.410-0.494))/asin(0.266)+ln(0.683)*sqrt((0.419+0.419)+(0.419/0.419))/sin(0.647)/ln(0.509)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.775", ")", "*", "atan", "(", "0.457", ")", "-", "sqrt", "(", "(", "0.948", "*", "0.948", ")", "+", "(", "0.948", "*", "0.948", ")", ")", "/", "sqrt", "(", "0.602", ")", "+", "cos", "(", "0.302", ")", "/", "sqrt", "(", "(", "0.796", "^", "0.796", ")", "^", "(", "0.796", "*", "0.796", ")", ")", "-", "sin", "(", "0.872", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.775)*atan(0.457)-sqrt((0.948*0.948)+(0.948*0.948))/sqrt(0.602)+cos(0.302)/sqrt((0.796^0.796)^(0.796*0.796))-sin(0.872)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.434", ")", "/", "sin", "(", "0.217", ")", "*", "actg", "(", "(", "0.114", "+", "0.114", ")", "^", "(", "x", "*", "0.114", ")", ")", "+", "tan", "(", "0.989", ")", "-", "actg", "(", "0.167", ")", "^", "asin", "(", "(", "0.610", "/", "0.610", ")", "*", "(", "0.421", "^", "0.610", ")", ")", "-", "sin", "(", "0.785", ")", "+", "acos", "(", "0.666", ")", "^", "sqrt", "(", "(", "0.564", "^", "0.564", ")", "^", "(", "0.564", "*", "0.564", ")", ")", "/", "asin", "(", "0.859", ")", "*", "sin", "(", "0.611", ")", "-", "log", "(", "(", "0.841", "^", "0.841", ")", "+", "(", "x", "^", "0.841", ")", ")", "/", "ln", "(", "0.816", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.434)/sin(0.217)*actg((0.114+0.114)^(x*0.114))+tan(0.989)-actg(0.167)^asin((0.610/0.610)*(0.421^0.610))-sin(0.785)+acos(0.666)^sqrt((0.564^0.564)^(0.564*0.564))/asin(0.859)*sin(0.611)-log((0.841^0.841)+(x^0.841))/ln(0.816)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.6", ")", "*", "atan", "(", "0.867", ")", "*", "cos", "(", "(", "0.828", "/", "0.828", ")", "+", "(", "0.370", "-", "0.828", ")", ")", "-", "actg", "(", "0.925", ")", "^", "tan", "(", "0.475", ")", "/", "ctg", "(", "(", "0.378", "-", "0.378", ")", "/", "(", "x", "/", "0.378", ")", ")", "^", "ln", "(", "0.544", ")", "^", "0.837"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.6)*atan(0.867)*cos((0.828/0.828)+(0.370-0.828))-actg(0.925)^tan(0.475)/ctg((0.378-0.378)/(x/0.378))^ln(0.544)^0.837"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "964", "%", "918"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+964%918"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.215", ")", "^", "sqrt", "(", "0.95", ")", "/", "ctg", "(", "(", "0.325", "*", "0.325", ")", "/", "(", "0.519", "*", "0.325", ")", ")", "-", "asin", "(", "0.569", ")", "/", "atan", "(", "0.310", ")", "/", "sqrt", "(", "(", "0.836", "-", "0.836", ")", "+", "(", "x", "/", "0.836", ")", ")", "/", "acos", "(", "0.661", ")", "*", "cos", "(", "0.538", ")", "*", "actg", "(", "(", "0.902", "-", "0.902", ")", "+", "(", "0.902", "/", "0.902", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.215)^sqrt(0.95)/ctg((0.325*0.325)/(0.519*0.325))-asin(0.569)/atan(0.310)/sqrt((0.836-0.836)+(x/0.836))/acos(0.661)*cos(0.538)*actg((0.902-0.902)+(0.902/0.902))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.324", ")", "*", "cos", "(", "0.692", ")", "-", "sqrt", "(", "(", "0.207", "/", "0.207", ")", "+", "(", "x", "/", "0.207", ")", ")", "-", "acos", "(", "0.645", ")", "+", "sqrt", "(", "0.71", ")", "/", "acos", "(", "(", "0.562", "^", "0.562", ")", "+", "(", "0.454", "*", "0.562", ")", ")", "^", "sin", "(", "0.145", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.324)*cos(0.692)-sqrt((0.207/0.207)+(x/0.207))-acos(0.645)+sqrt(0.71)/acos((0.562^0.562)+(0.454*0.562))^sin(0.145)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.332", ")", "/", "sqrt", "(", "0.44", ")", "/", "ln", "(", "(", "0.907", "/", "0.907", ")", "^", "(", "x", "-", "0.907", ")", ")", "-", "actg", "(", "0.628", ")", "*", "sqrt", "(", "0.701", ")", "^", "log", "(", "(", "0.881", "-", "0.881", ")", "-", "(", "x", "-", "0.881", ")", ")", "-", "asin", "(", "0.199", ")", "/", "tan", "(", "0.687", ")", "^", "tan", "(", "(", "0.338", "/", "0.338", ")", "^", "(", "0.338", "*", "0.338", ")", ")", "/", "sqrt", "(", "0.88", ")", "-", "sqrt", "(", "0.579", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.332)/sqrt(0.44)/ln((0.907/0.907)^(x-0.907))-actg(0.628)*sqrt(0.701)^log((0.881-0.881)-(x-0.881))-asin(0.199)/tan(0.687)^tan((0.338/0.338)^(0.338*0.338))/sqrt(0.88)-sqrt(0.579)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.522", ")", "-", "sqrt", "(", "0.247", ")", "+", "ln", "(", "(", "0.355", "/", "0.355", ")", "/", "(", "0.355", "*", "0.355", ")", ")", "-", "actg", "(", "0.606", ")", "+", "sin", "(", "0.263", ")", "/", "actg", "(", "(", "0.499", "*", "0.499", ")", "^", "(", "x", "/", "0.499", ")", ")", "/", "asin", "(", "0.742", ")", "/", "0.987"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.522)-sqrt(0.247)+ln((0.355/0.355)/(0.355*0.355))-actg(0.606)+sin(0.263)/actg((0.499*0.499)^(x/0.499))/asin(0.742)/0.987"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.807", ")", "/", "cos", "(", "0.761", ")", "/", "asin", "(", "(", "0.222", "^", "0.222", ")", "*", "(", "0.222", "*", "0.222", ")", ")", "-", "sqrt", "(", "0.341", ")", "*", "cos", "(", "0.977", ")", "^", "ln", "(", "(", "0.172", "/", "0.172", ")", "-", "(", "0.172", "/", "0.172", ")", ")", "*", "acos", "(", "0.109", ")", "*", "0.568"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.807)/cos(0.761)/asin((0.222^0.222)*(0.222*0.222))-sqrt(0.341)*cos(0.977)^ln((0.172/0.172)-(0.172/0.172))*acos(0.109)*0.568"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.706", ")", "-", "sqrt", "(", "0.752", ")", "-", "ctg", "(", "(", "0.872", "/", "0.872", ")", "+", "(", "x", "*", "0.872", ")", ")", "+", "ln", "(", "0.662", ")", "*", "asin", "(", "0.496", ")", "^", "sqrt", "(", "(", "0.972", "/", "0.972", ")", "-", "(", "x", "*", "0.972", ")", ")", "*", "acos", "(", "0.981", ")", "-", "0.797"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.706)-sqrt(0.752)-ctg((0.872/0.872)+(x*0.872))+ln(0.662)*asin(0.496)^sqrt((0.972/0.972)-(x*0.972))*acos(0.981)-0.797"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.829", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.829)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.664", ")", "^", "cos", "(", "0.112", ")", "-", "cos", "(", "(", "0.124", "*", "0.124", ")", "*", "(", "0.410", "+", "0.124", ")", ")", "^", "sqrt", "(", "0.168", ")", "+", "log", "(", "0.345", ")", "*", "asin", "(", "(", "0.566", "^", "0.566", ")", "-", "(", "x", "+", "0.566", ")", ")", "+", "asin", "(", "0.650", ")", "*", "acos", "(", "0.610", ")", "-", "tan", "(", "(", "0.341", "-", "0.341", ")", "/", "(", "0.790", "/", "0.341", ")", ")", "-", "asin", "(", "0.399", ")", "-", "ln", "(", "0.477", ")", "^", "sqrt", "(", "(", "0.122", "^", "0.122", ")", "^", "(", "x", "/", "0.122", ")", ")", "-", "sqrt", "(", "0.623", ")", "-", "0.735"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.664)^cos(0.112)-cos((0.124*0.124)*(0.410+0.124))^sqrt(0.168)+log(0.345)*asin((0.566^0.566)-(x+0.566))+asin(0.650)*acos(0.610)-tan((0.341-0.341)/(0.790/0.341))-asin(0.399)-ln(0.477)^sqrt((0.122^0.122)^(x/0.122))-sqrt(0.623)-0.735"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.570", ")", "+", "log", "(", "0.85", ")", "-", "ln", "(", "(", "0.568", "-", "0.568", ")", "^", "(", "x", "/", "0.568", ")", ")", "/", "sin", "(", "0.15", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.570)+log(0.85)-ln((0.568-0.568)^(x/0.568))/sin(0.15)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.372", ")", "-", "log", "(", "0.124", ")", "*", "tan", "(", "(", "0.369", "*", "0.369", ")", "+", "(", "0.369", "+", "0.369", ")", ")", "/", "ctg", "(", "0.303", ")", "*", "log", "(", "0.569", ")", "^", "ctg", "(", "(", "0.935", "+", "0.935", ")", "^", "(", "0.935", "*", "0.935", ")", ")", "*", "asin", "(", "0.901", ")", "/", "sin", "(", "0.58", ")", "*", "asin", "(", "(", "0.660", "+", "0.660", ")", "+", "(", "0.660", "-", "0.660", ")", ")", "^", "log", "(", "0.161", ")", "*", "log", "(", "0.581", ")", "/", "atan", "(", "(", "0.368", "*", "0.368", ")", "-", "(", "0.368", "-", "0.368", ")", ")", "+", "asin", "(", "0.543", ")", "^", "ctg", "(", "0.309", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.372)-log(0.124)*tan((0.369*0.369)+(0.369+0.369))/ctg(0.303)*log(0.569)^ctg((0.935+0.935)^(0.935*0.935))*asin(0.901)/sin(0.58)*asin((0.660+0.660)+(0.660-0.660))^log(0.161)*log(0.581)/atan((0.368*0.368)-(0.368-0.368))+asin(0.543)^ctg(0.309)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.38", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.38)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.800", ")", "/", "acos", "(", "0.978", ")", "+", "atan", "(", "(", "0.764", "^", "0.764", ")", "+", "(", "0.764", "-", "0.764", ")", ")", "/", "asin", "(", "0.392", ")", "^", "acos", "(", "0.740", ")", "^", "ln", "(", "(", "0.299", "^", "0.299", ")", "*", "(", "x", "+", "0.299", ")", ")", "/", "asin", "(", "0.265", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.800)/acos(0.978)+atan((0.764^0.764)+(0.764-0.764))/asin(0.392)^acos(0.740)^ln((0.299^0.299)*(x+0.299))/asin(0.265)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.430", ")", "^", "ctg", "(", "0.175", ")", "*", "sin", "(", "(", "0.952", "+", "0.952", ")", "-", "(", "0.952", "/", "0.952", ")", ")", "/", "ctg", "(", "0.436", ")", "/", "log", "(", "0.905", ")", "-", "sqrt", "(", "(", "0.861", "/", "0.861", ")", "+", "(", "x", "/", "0.861", ")", ")", "*", "tan", "(", "0.147", ")", "^", "sqrt", "(", "0.950", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.430)^ctg(0.175)*sin((0.952+0.952)-(0.952/0.952))/ctg(0.436)/log(0.905)-sqrt((0.861/0.861)+(x/0.861))*tan(0.147)^sqrt(0.950)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.421", ")", "-", "acos", "(", "0.288", ")", "+", "ln", "(", "(", "0.549", "*", "0.549", ")", "+", "(", "0.549", "-", "0.549", ")", ")", "+", "asin", "(", "0.856", ")", "*", "actg", "(", "0.941", ")", "/", "cos", "(", "(", "0.463", "/", "0.463", ")", "-", "(", "x", "+", "0.463", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.421)-acos(0.288)+ln((0.549*0.549)+(0.549-0.549))+asin(0.856)*actg(0.941)/cos((0.463/0.463)-(x+0.463))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.740", ")", "-", "asin", "(", "0.773", ")", "^", "asin", "(", "(", "0.753", "*", "0.753", ")", "^", "(", "x", "*", "0.753", ")", ")", "/", "actg", "(", "0.376", ")", "^", "sqrt", "(", "0.272", ")", "/", "cos", "(", "(", "0.876", "-", "0.876", ")", "+", "(", "x", "-", "0.876", ")", ")", "*", "atan", "(", "0.611", ")", "/", "asin", "(", "0.412", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.740)-asin(0.773)^asin((0.753*0.753)^(x*0.753))/actg(0.376)^sqrt(0.272)/cos((0.876-0.876)+(x-0.876))*atan(0.611)/asin(0.412)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.331", ")", "+", "sqrt", "(", "0.921", ")", "*", "atan", "(", "(", "0.896", "/", "0.896", ")", "*", "(", "0.896", "*", "0.896", ")", ")", "+", "tan", "(", "0.435", ")", "^", "asin", "(", "0.117", ")", "^", "cos", "(", "(", "0.8", "*", "0.8", ")", "/", "(", "0.8", "^", "0.8", ")", ")", "/", "actg", "(", "0.57", ")", "-", "actg", "(", "0.291", ")", "-", "log", "(", "(", "0.16", "^", "0.16", ")", "-", "(", "0.87", "/", "0.16", ")", ")", "+", "actg", "(", "0.213", ")", "/", "asin", "(", "0.216", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.331)+sqrt(0.921)*atan((0.896/0.896)*(0.896*0.896))+tan(0.435)^asin(0.117)^cos((0.8*0.8)/(0.8^0.8))/actg(0.57)-actg(0.291)-log((0.16^0.16)-(0.87/0.16))+actg(0.213)/asin(0.216)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.184", ")", "-", "cos", "(", "0.661", ")", "/", "cos", "(", "(", "0.209", "^", "0.209", ")", "+", "(", "0.209", "/", "0.209", ")", ")", "*", "acos", "(", "0.451", ")", "-", "ln", "(", "0.202", ")", "+", "asin", "(", "(", "0.870", "+", "0.870", ")", "-", "(", "0.870", "/", "0.870", ")", ")", "^", "cos", "(", "0.15", ")", "-", "acos", "(", "0.721", ")", "*", "sqrt", "(", "(", "0.692", "-", "0.692", ")", "*", "(", "0.692", "^", "0.692", ")", ")", "-", "ln", "(", "0.186", ")", "-", "acos", "(", "0.554", ")", "*", "actg", "(", "(", "0.47", "+", "0.47", ")", "/", "(", "0.47", "+", "0.47", ")", ")", "-", "sqrt", "(", "0.923", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.184)-cos(0.661)/cos((0.209^0.209)+(0.209/0.209))*acos(0.451)-ln(0.202)+asin((0.870+0.870)-(0.870/0.870))^cos(0.15)-acos(0.721)*sqrt((0.692-0.692)*(0.692^0.692))-ln(0.186)-acos(0.554)*actg((0.47+0.47)/(0.47+0.47))-sqrt(0.923)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.214", ")", "^", "actg", "(", "0.434", ")", "+", "atan", "(", "(", "0.485", "+", "0.485", ")", "+", "(", "x", "^", "0.485", ")", ")", "/", "tan", "(", "0.108", ")", "+", "atan", "(", "0.132", ")", "+", "tan", "(", "(", "0.487", "+", "0.487", ")", "^", "(", "0.786", "-", "0.487", ")", ")", "/", "log", "(", "0.882", ")", "^", "ln", "(", "0.212", ")", "/", "log", "(", "(", "0.68", "/", "0.68", ")", "+", "(", "0.368", "-", "0.68", ")", ")", "/", "ln", "(", "0.532", ")", "-", "0.417"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.214)^actg(0.434)+atan((0.485+0.485)+(x^0.485))/tan(0.108)+atan(0.132)+tan((0.487+0.487)^(0.786-0.487))/log(0.882)^ln(0.212)/log((0.68/0.68)+(0.368-0.68))/ln(0.532)-0.417"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.404", ")", "/", "tan", "(", "0.123", ")", "*", "sqrt", "(", "(", "0.346", "/", "0.346", ")", "+", "(", "0.346", "/", "0.346", ")", ")", "+", "sqrt", "(", "0.758", ")", "*", "sqrt", "(", "0.988", ")", "-", "ln", "(", "(", "0.760", "/", "0.760", ")", "+", "(", "0.624", "*", "0.760", ")", ")", "/", "atan", "(", "0.140", ")", "/", "asin", "(", "0.656", ")", "/", "sin", "(", "(", "0.745", "+", "0.745", ")", "+", "(", "0.798", "/", "0.745", ")", ")", "/", "actg", "(", "0.750", ")", "-", "ctg", "(", "0.236", ")", "-", "sqrt", "(", "(", "0.282", "-", "0.282", ")", "+", "(", "x", "*", "0.282", ")", ")", "+", "ctg", "(", "0.407", ")", "-", "atan", "(", "0.485", ")", "+", "actg", "(", "(", "0.51", "^", "0.51", ")", "^", "(", "x", "-", "0.51", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.404)/tan(0.123)*sqrt((0.346/0.346)+(0.346/0.346))+sqrt(0.758)*sqrt(0.988)-ln((0.760/0.760)+(0.624*0.760))/atan(0.140)/asin(0.656)/sin((0.745+0.745)+(0.798/0.745))/actg(0.750)-ctg(0.236)-sqrt((0.282-0.282)+(x*0.282))+ctg(0.407)-atan(0.485)+actg((0.51^0.51)^(x-0.51))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.781", ")", "-", "atan", "(", "0.278", ")", "-", "cos", "(", "(", "0.848", "*", "0.848", ")", "+", "(", "x", "/", "0.848", ")", ")", "+", "sqrt", "(", "0.966", ")", "/", "actg", "(", "0.775", ")", "+", "atan", "(", "(", "0.189", "*", "0.189", ")", "^", "(", "x", "^", "0.189", ")", ")", "-", "actg", "(", "0.248", ")", "^", "asin", "(", "0.536", ")", "*", "log", "(", "(", "0.922", "/", "0.922", ")", "+", "(", "0.922", "/", "0.922", ")", ")", "*", "asin", "(", "0.451", ")", "+", "asin", "(", "0.511", ")", "-", "tan", "(", "(", "0.970", "+", "0.970", ")", "^", "(", "x", "^", "0.970", ")", ")", "*", "ln", "(", "0.758", ")", "+", "cos", "(", "0.572", ")", "*", "cos", "(", "(", "0.992", "+", "0.992", ")", "+", "(", "0.801", "/", "0.992", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.781)-atan(0.278)-cos((0.848*0.848)+(x/0.848))+sqrt(0.966)/actg(0.775)+atan((0.189*0.189)^(x^0.189))-actg(0.248)^asin(0.536)*log((0.922/0.922)+(0.922/0.922))*asin(0.451)+asin(0.511)-tan((0.970+0.970)^(x^0.970))*ln(0.758)+cos(0.572)*cos((0.992+0.992)+(0.801/0.992))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.591", ")", "-", "log", "(", "0.312", ")", "/", "log", "(", "(", "0.705", "-", "0.705", ")", "-", "(", "0.237", "/", "0.705", ")", ")", "-", "tan", "(", "0.500", ")", "^", "sqrt", "(", "0.343", ")", "^", "asin", "(", "(", "0.312", "/", "0.312", ")", "+", "(", "0.312", "*", "0.312", ")", ")", "*", "sqrt", "(", "0.304", ")", "*", "asin", "(", "0.114", ")", "^", "ln", "(", "(", "0.677", "/", "0.677", ")", "*", "(", "0.607", "+", "0.677", ")", ")", "+", "actg", "(", "0.601", ")", "/", "acos", "(", "0.478", ")", "^", "tan", "(", "(", "0.992", "+", "0.992", ")", "-", "(", "0.560", "*", "0.992", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.591)-log(0.312)/log((0.705-0.705)-(0.237/0.705))-tan(0.500)^sqrt(0.343)^asin((0.312/0.312)+(0.312*0.312))*sqrt(0.304)*asin(0.114)^ln((0.677/0.677)*(0.607+0.677))+actg(0.601)/acos(0.478)^tan((0.992+0.992)-(0.560*0.992))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.262", ")", "*", "sin", "(", "0.415", ")", "-", "ctg", "(", "(", "0.200", "^", "0.200", ")", "*", "(", "0.726", "*", "0.200", ")", ")", "+", "sqrt", "(", "0.107", ")", "-", "0.813"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.262)*sin(0.415)-ctg((0.200^0.200)*(0.726*0.200))+sqrt(0.107)-0.813"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.359", ")", "+", "tan", "(", "0.863", ")", "/", "atan", "(", "(", "0.470", "/", "0.470", ")", "^", "(", "x", "-", "0.470", ")", ")", "/", "tan", "(", "0.715", ")", "-", "actg", "(", "0.116", ")", "+", "ctg", "(", "(", "0.974", "-", "0.974", ")", "/", "(", "x", "^", "0.974", ")", ")", "^", "actg", "(", "0.82", ")", "*", "cos", "(", "0.904", ")", "*", "sqrt", "(", "(", "0.70", "^", "0.70", ")", "*", "(", "x", "+", "0.70", ")", ")", "/", "sqrt", "(", "0.31", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.359)+tan(0.863)/atan((0.470/0.470)^(x-0.470))/tan(0.715)-actg(0.116)+ctg((0.974-0.974)/(x^0.974))^actg(0.82)*cos(0.904)*sqrt((0.70^0.70)*(x+0.70))/sqrt(0.31)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "521", "%", "947"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+521%947"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.112", ")", "*", "actg", "(", "0.763", ")", "-", "atan", "(", "(", "0.133", "-", "0.133", ")", "/", "(", "0.133", "*", "0.133", ")", ")", "*", "tan", "(", "0.762", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.112)*actg(0.763)-atan((0.133-0.133)/(0.133*0.133))*tan(0.762)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.387", ")", "/", "sqrt", "(", "0.870", ")", "^", "atan", "(", "(", "0.175", "-", "0.175", ")", "*", "(", "0.48", "/", "0.175", ")", ")", "+", "atan", "(", "0.885", ")", "-", "asin", "(", "0.119", ")", "-", "asin", "(", "(", "0.198", "/", "0.198", ")", "-", "(", "x", "^", "0.198", ")", ")", "/", "actg", "(", "0.20", ")", "^", "0.519"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.387)/sqrt(0.870)^atan((0.175-0.175)*(0.48/0.175))+atan(0.885)-asin(0.119)-asin((0.198/0.198)-(x^0.198))/actg(0.20)^0.519"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.930", ")", "*", "cos", "(", "0.378", ")", "^", "cos", "(", "(", "0.290", "-", "0.290", ")", "/", "(", "0.290", "-", "0.290", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.930)*cos(0.378)^cos((0.290-0.290)/(0.290-0.290))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "825", "%", "157"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+825%157"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.848", ")", "^", "ctg", "(", "0.546", ")", "/", "tan", "(", "(", "0.652", "/", "0.652", ")", "*", "(", "0.758", "*", "0.652", ")", ")", "^", "acos", "(", "0.442", ")", "+", "log", "(", "0.602", ")", "+", "log", "(", "(", "0.284", "*", "0.284", ")", "^", "(", "0.284", "-", "0.284", ")", ")", "+", "sqrt", "(", "0.645", ")", "^", "sin", "(", "0.886", ")", "^", "asin", "(", "(", "0.925", "-", "0.925", ")", "-", "(", "0.995", "^", "0.925", ")", ")", "/", "acos", "(", "0.24", ")", "/", "acos", "(", "0.663", ")", "-", "log", "(", "(", "0.860", "*", "0.860", ")", "-", "(", "0.828", "*", "0.860", ")", ")", "/", "sqrt", "(", "0.676", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.848)^ctg(0.546)/tan((0.652/0.652)*(0.758*0.652))^acos(0.442)+log(0.602)+log((0.284*0.284)^(0.284-0.284))+sqrt(0.645)^sin(0.886)^asin((0.925-0.925)-(0.995^0.925))/acos(0.24)/acos(0.663)-log((0.860*0.860)-(0.828*0.860))/sqrt(0.676)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.725", ")", "^", "tan", "(", "0.271", ")", "-", "sqrt", "(", "(", "0.870", "*", "0.870", ")", "+", "(", "x", "/", "0.870", ")", ")", "+", "sqrt", "(", "0.132", ")", "^", "log", "(", "0.795", ")", "+", "actg", "(", "(", "0.30", "^", "0.30", ")", "+", "(", "0.841", "*", "0.30", ")", ")", "*", "tan", "(", "0.272", ")", "+", "sin", "(", "0.475", ")", "^", "sin", "(", "(", "0.940", "*", "0.940", ")", "^", "(", "0.806", "/", "0.940", ")", ")", "*", "sqrt", "(", "0.478", ")", "*", "ctg", "(", "0.593", ")", "^", "tan", "(", "(", "0.930", "*", "0.930", ")", "-", "(", "x", "+", "0.930", ")", ")", "*", "cos", "(", "0.752", ")", "*", "actg", "(", "0.816", ")", "/", "acos", "(", "(", "0.355", "^", "0.355", ")", "*", "(", "0.355", "*", "0.355", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.725)^tan(0.271)-sqrt((0.870*0.870)+(x/0.870))+sqrt(0.132)^log(0.795)+actg((0.30^0.30)+(0.841*0.30))*tan(0.272)+sin(0.475)^sin((0.940*0.940)^(0.806/0.940))*sqrt(0.478)*ctg(0.593)^tan((0.930*0.930)-(x+0.930))*cos(0.752)*actg(0.816)/acos((0.355^0.355)*(0.355*0.355))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.931", ")", "^", "sqrt", "(", "0.852", ")", "-", "tan", "(", "(", "0.557", "*", "0.557", ")", "^", "(", "0.557", "/", "0.557", ")", ")", "^", "ctg", "(", "0.621", ")", "*", "ln", "(", "0.159", ")", "-", "sin", "(", "(", "0.630", "*", "0.630", ")", "/", "(", "0.425", "+", "0.630", ")", ")", "-", "ln", "(", "0.427", ")", "^", "sin", "(", "0.729", ")", "^", "ln", "(", "(", "0.419", "-", "0.419", ")", "+", "(", "0.879", "-", "0.419", ")", ")", "/", "log", "(", "0.732", ")", "-", "cos", "(", "0.510", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.931)^sqrt(0.852)-tan((0.557*0.557)^(0.557/0.557))^ctg(0.621)*ln(0.159)-sin((0.630*0.630)/(0.425+0.630))-ln(0.427)^sin(0.729)^ln((0.419-0.419)+(0.879-0.419))/log(0.732)-cos(0.510)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.82", ")", "+", "tan", "(", "0.72", ")", "*", "sin", "(", "(", "0.467", "+", "0.467", ")", "*", "(", "0.265", "/", "0.467", ")", ")", "*", "ctg", "(", "0.932", ")", "-", "tan", "(", "0.100", ")", "+", "acos", "(", "(", "0.535", "+", "0.535", ")", "/", "(", "x", "^", "0.535", ")", ")", "*", "log", "(", "0.646", ")", "/", "ln", "(", "0.482", ")", "/", "actg", "(", "(", "0.579", "/", "0.579", ")", "*", "(", "x", "^", "0.579", ")", ")", "+", "actg", "(", "0.100", ")", "*", "acos", "(", "0.170", ")", "/", "actg", "(", "(", "0.295", "/", "0.295", ")", "^", "(", "x", "-", "0.295", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.82)+tan(0.72)*sin((0.467+0.467)*(0.265/0.467))*ctg(0.932)-tan(0.100)+acos((0.535+0.535)/(x^0.535))*log(0.646)/ln(0.482)/actg((0.579/0.579)*(x^0.579))+actg(0.100)*acos(0.170)/actg((0.295/0.295)^(x-0.295))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.285", ")", "*", "acos", "(", "0.663", ")", "*", "ctg", "(", "(", "0.146", "-", "0.146", ")", "/", "(", "0.724", "*", "0.146", ")", ")", "+", "cos", "(", "0.388", ")", "+", "log", "(", "0.386", ")", "-", "sin", "(", "(", "0.26", "-", "0.26", ")", "/", "(", "x", "^", "0.26", ")", ")", "/", "ln", "(", "0.302", ")", "-", "sqrt", "(", "0.428", ")", "-", "atan", "(", "(", "0.946", "^", "0.946", ")", "*", "(", "x", "^", "0.946", ")", ")", "*", "acos", "(", "0.610", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.285)*acos(0.663)*ctg((0.146-0.146)/(0.724*0.146))+cos(0.388)+log(0.386)-sin((0.26-0.26)/(x^0.26))/ln(0.302)-sqrt(0.428)-atan((0.946^0.946)*(x^0.946))*acos(0.610)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.116", ")", "-", "sin", "(", "0.689", ")", "-", "ctg", "(", "(", "0.575", "*", "0.575", ")", "/", "(", "0.986", "/", "0.575", ")", ")", "+", "atan", "(", "0.732", ")", "^", "log", "(", "0.652", ")", "-", "tan", "(", "(", "0.725", "/", "0.725", ")", "^", "(", "0.605", "-", "0.725", ")", ")", "^", "sin", "(", "0.341", ")", "-", "asin", "(", "0.361", ")", "/", "ln", "(", "(", "0.855", "*", "0.855", ")", "/", "(", "x", "-", "0.855", ")", ")", "^", "log", "(", "0.223", ")", "*", "0.699"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.116)-sin(0.689)-ctg((0.575*0.575)/(0.986/0.575))+atan(0.732)^log(0.652)-tan((0.725/0.725)^(0.605-0.725))^sin(0.341)-asin(0.361)/ln((0.855*0.855)/(x-0.855))^log(0.223)*0.699"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "972", "%", "983"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+972%983"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.834", ")", "^", "sin", "(", "0.445", ")", "-", "actg", "(", "(", "0.0", "+", "0.0", ")", "-", "(", "0.156", "*", "0.0", ")", ")", "+", "log", "(", "0.782", ")", "+", "cos", "(", "0.492", ")", "/", "ln", "(", "(", "0.299", "/", "0.299", ")", "-", "(", "0.299", "/", "0.299", ")", ")", "+", "log", "(", "0.939", ")", "*", "0.251"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.834)^sin(0.445)-actg((0.0+0.0)-(0.156*0.0))+log(0.782)+cos(0.492)/ln((0.299/0.299)-(0.299/0.299))+log(0.939)*0.251"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.108", ")", "-", "sqrt", "(", "0.111", ")", "-", "ln", "(", "(", "0.983", "*", "0.983", ")", "^", "(", "0.597", "-", "0.983", ")", ")", "+", "cos", "(", "0.138", ")", "+", "acos", "(", "0.1", ")", "^", "actg", "(", "(", "0.828", "^", "0.828", ")", "*", "(", "0.701", "*", "0.828", ")", ")", "^", "ln", "(", "0.148", ")", "^", "acos", "(", "0.960", ")", "/", "ctg", "(", "(", "0.614", "^", "0.614", ")", "^", "(", "0.614", "*", "0.614", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.108)-sqrt(0.111)-ln((0.983*0.983)^(0.597-0.983))+cos(0.138)+acos(0.1)^actg((0.828^0.828)*(0.701*0.828))^ln(0.148)^acos(0.960)/ctg((0.614^0.614)^(0.614*0.614))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.613", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.613)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.917", ")", "-", "cos", "(", "0.696", ")", "+", "atan", "(", "(", "0.2", "*", "0.2", ")", "+", "(", "0.908", "-", "0.2", ")", ")", "*", "cos", "(", "0.101", ")", "/", "0.921"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.917)-cos(0.696)+atan((0.2*0.2)+(0.908-0.2))*cos(0.101)/0.921"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.244", ")", "^", "sqrt", "(", "0.970", ")", "+", "cos", "(", "(", "0.258", "/", "0.258", ")", "*", "(", "0.971", "-", "0.258", ")", ")", "*", "ln", "(", "0.784", ")", "-", "atan", "(", "0.464", ")", "-", "sin", "(", "(", "0.122", "-", "0.122", ")", "+", "(", "0.585", "*", "0.122", ")", ")", "-", "log", "(", "0.981", ")", "*", "actg", "(", "0.157", ")", "/", "ln", "(", "(", "0.512", "*", "0.512", ")", "/", "(", "x", "+", "0.512", ")", ")", "+", "actg", "(", "0.414", ")", "/", "asin", "(", "0.356", ")", "*", "ctg", "(", "(", "0.728", "-", "0.728", ")", "+", "(", "0.728", "^", "0.728", ")", ")", "-", "ctg", "(", "0.16", ")", "*", "tan", "(", "0.246", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.244)^sqrt(0.970)+cos((0.258/0.258)*(0.971-0.258))*ln(0.784)-atan(0.464)-sin((0.122-0.122)+(0.585*0.122))-log(0.981)*actg(0.157)/ln((0.512*0.512)/(x+0.512))+actg(0.414)/asin(0.356)*ctg((0.728-0.728)+(0.728^0.728))-ctg(0.16)*tan(0.246)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.494", ")", "+", "cos", "(", "0.968", ")", "-", "actg", "(", "(", "0.202", "-", "0.202", ")", "*", "(", "0.202", "/", "0.202", ")", ")", "*", "asin", "(", "0.886", ")", "/", "tan", "(", "0.552", ")", "/", "ctg", "(", "(", "0.852", "/", "0.852", ")", "-", "(", "0.621", "^", "0.852", ")", ")", "^", "ln", "(", "0.58", ")", "-", "acos", "(", "0.873", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.494)+cos(0.968)-actg((0.202-0.202)*(0.202/0.202))*asin(0.886)/tan(0.552)/ctg((0.852/0.852)-(0.621^0.852))^ln(0.58)-acos(0.873)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.488", ")", "/", "0.815"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.488)/0.815"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.988", ")", "-", "asin", "(", "0.824", ")", "/", "atan", "(", "(", "0.336", "*", "0.336", ")", "+", "(", "0.877", "+", "0.336", ")", ")", "-", "sqrt", "(", "0.217", ")", "-", "asin", "(", "0.651", ")", "^", "actg", "(", "(", "0.795", "/", "0.795", ")", "*", "(", "x", "+", "0.795", ")", ")", "+", "log", "(", "0.914", ")", "/", "atan", "(", "0.345", ")", "+", "ctg", "(", "(", "0.58", "-", "0.58", ")", "/", "(", "x", "/", "0.58", ")", ")", "-", "tan", "(", "0.581", ")", "-", "actg", "(", "0.631", ")", "+", "atan", "(", "(", "0.277", "/", "0.277", ")", "+", "(", "0.838", "-", "0.277", ")", ")", "*", "tan", "(", "0.34", ")", "^", "0.240"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.988)-asin(0.824)/atan((0.336*0.336)+(0.877+0.336))-sqrt(0.217)-asin(0.651)^actg((0.795/0.795)*(x+0.795))+log(0.914)/atan(0.345)+ctg((0.58-0.58)/(x/0.58))-tan(0.581)-actg(0.631)+atan((0.277/0.277)+(0.838-0.277))*tan(0.34)^0.240"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "595", "%", "976"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+595%976"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.587", ")", "+", "sin", "(", "0.398", ")", "-", "tan", "(", "(", "0.799", "/", "0.799", ")", "+", "(", "0.799", "*", "0.799", ")", ")", "/", "tan", "(", "0.776", ")", "/", "ln", "(", "0.283", ")", "+", "tan", "(", "(", "0.281", "/", "0.281", ")", "^", "(", "x", "+", "0.281", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.587)+sin(0.398)-tan((0.799/0.799)+(0.799*0.799))/tan(0.776)/ln(0.283)+tan((0.281/0.281)^(x+0.281))*"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.177", ")", "+", "sin", "(", "0.206", ")", "/", "sqrt", "(", "(", "0.994", "*", "0.994", ")", "-", "(", "x", "*", "0.994", ")", ")", "/", "cos", "(", "0.14", ")", "*", "log", "(", "0.815", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.177)+sin(0.206)/sqrt((0.994*0.994)-(x*0.994))/cos(0.14)*log(0.815)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.408", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.408)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.83", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.83)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.493", ")", "*", "asin", "(", "0.614", ")", "/", "acos", "(", "(", "0.151", "^", "0.151", ")", "+", "(", "0.151", "+", "0.151", ")", ")", "*", "atan", "(", "0.802", ")", "/", "ctg", "(", "0.987", ")", "/", "sqrt", "(", "(", "0.71", "+", "0.71", ")", "^", "(", "x", "-", "0.71", ")", ")", "+", "sqrt", "(", "0.524", ")", "/", "atan", "(", "0.293", ")", "+", "log", "(", "(", "0.224", "*", "0.224", ")", "^", "(", "0.18", "*", "0.224", ")", ")", "/", "sin", "(", "0.397", ")", "^", "log", "(", "0.460", ")", "+", "ctg", "(", "(", "0.18", "^", "0.18", ")", "^", "(", "x", "*", "0.18", ")", ")", "^", "log", "(", "0.529", ")", "*", "0.53"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.493)*asin(0.614)/acos((0.151^0.151)+(0.151+0.151))*atan(0.802)/ctg(0.987)/sqrt((0.71+0.71)^(x-0.71))+sqrt(0.524)/atan(0.293)+log((0.224*0.224)^(0.18*0.224))/sin(0.397)^log(0.460)+ctg((0.18^0.18)^(x*0.18))^log(0.529)*0.53"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.820", ")", "+", "asin", "(", "0.476", ")", "*", "acos", "(", "(", "0.468", "*", "0.468", ")", "/", "(", "0.468", "*", "0.468", ")", ")", "+", "log", "(", "0.455", ")", "+", "asin", "(", "0.215", ")", "*", "tan", "(", "(", "0.860", "+", "0.860", ")", "/", "(", "0.223", "/", "0.860", ")", ")", "/", "acos", "(", "0.908", ")", "-", "actg", "(", "0.931", ")", "*", "ctg", "(", "(", "0.512", "/", "0.512", ")", "*", "(", "x", "^", "0.512", ")", ")", "/", "atan", "(", "0.628", ")", "/", "acos", "(", "0.477", ")", "*", "ctg", "(", "(", "0.237", "+", "0.237", ")", "^", "(", "x", "*", "0.237", ")", ")", "-", "atan", "(", "0.804", ")", "-", "0.344"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.820)+asin(0.476)*acos((0.468*0.468)/(0.468*0.468))+log(0.455)+asin(0.215)*tan((0.860+0.860)/(0.223/0.860))/acos(0.908)-actg(0.931)*ctg((0.512/0.512)*(x^0.512))/atan(0.628)/acos(0.477)*ctg((0.237+0.237)^(x*0.237))-atan(0.804)-0.344"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.123", ")", "+", "log", "(", "0.705", ")", "*", "atan", "(", "(", "0.257", "^", "0.257", ")", "+", "(", "x", "-", "0.257", ")", ")", "*", "atan", "(", "0.195", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.123)+log(0.705)*atan((0.257^0.257)+(x-0.257))*atan(0.195)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.879", ")", "*", "actg", "(", "0.186", ")", "^", "asin", "(", "(", "0.848", "/", "0.848", ")", "*", "(", "0.545", "+", "0.848", ")", ")", "-", "cos", "(", "0.316", ")", "^", "acos", "(", "0.890", ")", "-", "sqrt", "(", "(", "0.564", "-", "0.564", ")", "^", "(", "0.688", "*", "0.564", ")", ")", "*", "tan", "(", "0.910", ")", "*", "tan", "(", "0.502", ")", "/", "atan", "(", "(", "0.716", "/", "0.716", ")", "*", "(", "x", "*", "0.716", ")", ")", "-", "asin", "(", "0.973", ")", "-", "log", "(", "0.15", ")", "*", "actg", "(", "(", "0.316", "/", "0.316", ")", "-", "(", "0.806", "/", "0.316", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.879)*actg(0.186)^asin((0.848/0.848)*(0.545+0.848))-cos(0.316)^acos(0.890)-sqrt((0.564-0.564)^(0.688*0.564))*tan(0.910)*tan(0.502)/atan((0.716/0.716)*(x*0.716))-asin(0.973)-log(0.15)*actg((0.316/0.316)-(0.806/0.316))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.855", ")", "-", "asin", "(", "0.53", ")", "+", "ctg", "(", "(", "0.460", "*", "0.460", ")", "-", "(", "0.460", "^", "0.460", ")", ")", "-", "sqrt", "(", "0.157", ")", "-", "sqrt", "(", "0.4", ")", "/", "sqrt", "(", "(", "0.406", "-", "0.406", ")", "+", "(", "0.406", "-", "0.406", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.855)-asin(0.53)+ctg((0.460*0.460)-(0.460^0.460))-sqrt(0.157)-sqrt(0.4)/sqrt((0.406-0.406)+(0.406-0.406))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.382", ")", "/", "acos", "(", "0.656", ")", "+", "sqrt", "(", "(", "0.811", "^", "0.811", ")", "/", "(", "x", "+", "0.811", ")", ")", "/", "atan", "(", "0.557", ")", "^", "ctg", "(", "0.923", ")", "/", "cos", "(", "(", "0.106", "*", "0.106", ")", "/", "(", "0.509", "*", "0.106", ")", ")", "*", "ln", "(", "0.928", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.382)/acos(0.656)+sqrt((0.811^0.811)/(x+0.811))/atan(0.557)^ctg(0.923)/cos((0.106*0.106)/(0.509*0.106))*ln(0.928)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.247", ")", "+", "sin", "(", "0.221", ")", "-", "acos", "(", "(", "0.905", "+", "0.905", ")", "*", "(", "0.899", "*", "0.905", ")", ")", "*", "log", "(", "0.987", ")", "^", "tan", "(", "0.260", ")", "/", "actg", "(", "(", "0.367", "*", "0.367", ")", "^", "(", "0.770", "*", "0.367", ")", ")", "*", "ctg", "(", "0.892", ")", "+", "0.340"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.247)+sin(0.221)-acos((0.905+0.905)*(0.899*0.905))*log(0.987)^tan(0.260)/actg((0.367*0.367)^(0.770*0.367))*ctg(0.892)+0.340"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.160", ")", "*", "ln", "(", "0.307", ")", "^", "sqrt", "(", "(", "0.809", "*", "0.809", ")", "+", "(", "x", "*", "0.809", ")", ")", "+", "cos", "(", "0.772", ")", "+", "acos", "(", "0.70", ")", "^", "atan", "(", "(", "0.235", "+", "0.235", ")", "+", "(", "0.235", "^", "0.235", ")", ")", "^", "asin", "(", "0.9", ")", "*", "asin", "(", "0.269", ")", "^", "atan", "(", "(", "0.135", "-", "0.135", ")", "*", "(", "x", "/", "0.135", ")", ")", "-", "log", "(", "0.369", ")", "+", "asin", "(", "0.496", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.160)*ln(0.307)^sqrt((0.809*0.809)+(x*0.809))+cos(0.772)+acos(0.70)^atan((0.235+0.235)+(0.235^0.235))^asin(0.9)*asin(0.269)^atan((0.135-0.135)*(x/0.135))-log(0.369)+asin(0.496)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.175", ")", "^", "sin", "(", "0.998", ")", "*", "actg", "(", "(", "0.597", "+", "0.597", ")", "-", "(", "0.194", "+", "0.597", ")", ")", "-", "tan", "(", "0.373", ")", "+", "asin", "(", "0.972", ")", "*", "ln", "(", "(", "0.629", "/", "0.629", ")", "/", "(", "0.629", "+", "0.629", ")", ")", "/", "cos", "(", "0.79", ")", "+", "asin", "(", "0.438", ")", "+", "ln", "(", "(", "0.309", "^", "0.309", ")", "-", "(", "x", "+", "0.309", ")", ")", "-", "sin", "(", "0.751", ")", "^", "tan", "(", "0.469", ")", "*", "cos", "(", "(", "0.877", "-", "0.877", ")", "*", "(", "x", "-", "0.877", ")", ")", "+", "cos", "(", "0.777", ")", "^", "tan", "(", "0.6", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.175)^sin(0.998)*actg((0.597+0.597)-(0.194+0.597))-tan(0.373)+asin(0.972)*ln((0.629/0.629)/(0.629+0.629))/cos(0.79)+asin(0.438)+ln((0.309^0.309)-(x+0.309))-sin(0.751)^tan(0.469)*cos((0.877-0.877)*(x-0.877))+cos(0.777)^tan(0.6)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "363", "%", "405"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+363%405"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.766", ")", "*", "tan", "(", "0.663", ")", "*", "cos", "(", "(", "0.161", "*", "0.161", ")", "*", "(", "x", "-", "0.161", ")", ")", "^", "asin", "(", "0.461", ")", "*", "ctg", "(", "0.857", ")", "*", "log", "(", "(", "0.367", "*", "0.367", ")", "*", "(", "0.686", "+", "0.367", ")", ")", "-", "ln", "(", "0.210", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.766)*tan(0.663)*cos((0.161*0.161)*(x-0.161))^asin(0.461)*ctg(0.857)*log((0.367*0.367)*(0.686+0.367))-ln(0.210)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.598", ")", "*", "ctg", "(", "0.534", ")", "+", "ctg", "(", "(", "0.606", "^", "0.606", ")", "^", "(", "0.12", "^", "0.606", ")", ")", "*", "tan", "(", "0.280", ")", "-", "acos", "(", "0.990", ")", "-", "actg", "(", "(", "0.240", "/", "0.240", ")", "-", "(", "0.49", "+", "0.240", ")", ")", "+", "sqrt", "(", "0.700", ")", "^", "ln", "(", "0.188", ")", "^", "ctg", "(", "(", "0.927", "*", "0.927", ")", "-", "(", "x", "*", "0.927", ")", ")", "/", "atan", "(", "0.446", ")", "-", "sqrt", "(", "0.804", ")", "/", "ln", "(", "(", "0.753", "^", "0.753", ")", "/", "(", "0.753", "+", "0.753", ")", ")", "^", "asin", "(", "0.93", ")", "^", "acos", "(", "0.632", ")", "^", "sqrt", "(", "(", "0.382", "-", "0.382", ")", "^", "(", "0.382", "+", "0.382", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.598)*ctg(0.534)+ctg((0.606^0.606)^(0.12^0.606))*tan(0.280)-acos(0.990)-actg((0.240/0.240)-(0.49+0.240))+sqrt(0.700)^ln(0.188)^ctg((0.927*0.927)-(x*0.927))/atan(0.446)-sqrt(0.804)/ln((0.753^0.753)/(0.753+0.753))^asin(0.93)^acos(0.632)^sqrt((0.382-0.382)^(0.382+0.382))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.28", ")", "^", "tan", "(", "0.226", ")", "+", "ctg", "(", "(", "0.658", "^", "0.658", ")", "*", "(", "x", "/", "0.658", ")", ")", "^", "tan", "(", "0.180", ")", "-", "tan", "(", "0.503", ")", "/", "sin", "(", "(", "0.789", "^", "0.789", ")", "/", "(", "x", "*", "0.789", ")", ")", "+", "acos", "(", "0.123", ")", "+", "0.832"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.28)^tan(0.226)+ctg((0.658^0.658)*(x/0.658))^tan(0.180)-tan(0.503)/sin((0.789^0.789)/(x*0.789))+acos(0.123)+0.832"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.787", ")", "*", "sqrt", "(", "0.390", ")", "-", "actg", "(", "(", "0.13", "*", "0.13", ")", "^", "(", "0.13", "-", "0.13", ")", ")", "*", "tan", "(", "0.733", ")", "-", "cos", "(", "0.913", ")", "^", "actg", "(", "(", "0.565", "^", "0.565", ")", "^", "(", "0.565", "*", "0.565", ")", ")", "*", "log", "(", "0.753", ")", "+", "cos", "(", "0.382", ")", "*", "atan", "(", "(", "0.745", "-", "0.745", ")", "^", "(", "0.174", "^", "0.745", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.787)*sqrt(0.390)-actg((0.13*0.13)^(0.13-0.13))*tan(0.733)-cos(0.913)^actg((0.565^0.565)^(0.565*0.565))*log(0.753)+cos(0.382)*atan((0.745-0.745)^(0.174^0.745))*"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.990", ")", "-", "atan", "(", "0.65", ")", "+", "acos", "(", "(", "0.185", "-", "0.185", ")", "-", "(", "x", "*", "0.185", ")", ")", "+", "ctg", "(", "0.192", ")", "-", "log", "(", "0.250", ")", "+", "sin", "(", "(", "0.989", "*", "0.989", ")", "+", "(", "0.451", "^", "0.989", ")", ")", "+", "atan", "(", "0.923", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.990)-atan(0.65)+acos((0.185-0.185)-(x*0.185))+ctg(0.192)-log(0.250)+sin((0.989*0.989)+(0.451^0.989))+atan(0.923)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.368", ")", "+", "cos", "(", "0.940", ")", "+", "sqrt", "(", "(", "0.864", "+", "0.864", ")", "*", "(", "0.864", "*", "0.864", ")", ")", "+", "sin", "(", "0.563", ")", "+", "log", "(", "0.363", ")", "/", "atan", "(", "(", "0.516", "/", "0.516", ")", "+", "(", "0.516", "-", "0.516", ")", ")", "*", "log", "(", "0.168", ")", "^", "log", "(", "0.36", ")", "-", "sqrt", "(", "(", "0.394", "/", "0.394", ")", "/", "(", "0.464", "+", "0.394", ")", ")", "-", "asin", "(", "0.95", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.368)+cos(0.940)+sqrt((0.864+0.864)*(0.864*0.864))+sin(0.563)+log(0.363)/atan((0.516/0.516)+(0.516-0.516))*log(0.168)^log(0.36)-sqrt((0.394/0.394)/(0.464+0.394))-asin(0.95)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.377", ")", "+", "ctg", "(", "0.789", ")", "+", "ctg", "(", "(", "0.583", "/", "0.583", ")", "-", "(", "0.583", "+", "0.583", ")", ")", "*", "ctg", "(", "0.317", ")", "*", "cos", "(", "0.760", ")", "+", "tan", "(", "(", "0.285", "^", "0.285", ")", "-", "(", "0.337", "-", "0.285", ")", ")", "*", "sqrt", "(", "0.431", ")", "/", "sqrt", "(", "0.454", ")", "^", "acos", "(", "(", "0.197", "+", "0.197", ")", "/", "(", "0.197", "+", "0.197", ")", ")", "-", "sqrt", "(", "0.376", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.377)+ctg(0.789)+ctg((0.583/0.583)-(0.583+0.583))*ctg(0.317)*cos(0.760)+tan((0.285^0.285)-(0.337-0.285))*sqrt(0.431)/sqrt(0.454)^acos((0.197+0.197)/(0.197+0.197))-sqrt(0.376)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.220", ")", "+", "tan", "(", "0.641", ")", "^", "acos", "(", "(", "0.409", "*", "0.409", ")", "*", "(", "0.75", "+", "0.409", ")", ")", "/", "tan", "(", "0.444", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.220)+tan(0.641)^acos((0.409*0.409)*(0.75+0.409))/tan(0.444)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.748", ")", "*", "acos", "(", "0.920", ")", "+", "tan", "(", "(", "0.681", "^", "0.681", ")", "+", "(", "x", "+", "0.681", ")", ")", "*", "ctg", "(", "0.635", ")", "-", "tan", "(", "0.41", ")", "*", "ctg", "(", "(", "0.417", "^", "0.417", ")", "-", "(", "x", "/", "0.417", ")", ")", "^", "log", "(", "0.270", ")", "-", "sqrt", "(", "0.62", ")", "/", "ln", "(", "(", "0.908", "+", "0.908", ")", "/", "(", "x", "-", "0.908", ")", ")", "-", "sin", "(", "0.630", ")", "+", "atan", "(", "0.609", ")", "+", "acos", "(", "(", "0.505", "-", "0.505", ")", "*", "(", "x", "-", "0.505", ")", ")", "*", "ln", "(", "0.411", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.748)*acos(0.920)+tan((0.681^0.681)+(x+0.681))*ctg(0.635)-tan(0.41)*ctg((0.417^0.417)-(x/0.417))^log(0.270)-sqrt(0.62)/ln((0.908+0.908)/(x-0.908))-sin(0.630)+atan(0.609)+acos((0.505-0.505)*(x-0.505))*ln(0.411)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.709", ")", "-", "tan", "(", "0.818", ")", "/", "atan", "(", "(", "0.47", "*", "0.47", ")", "*", "(", "0.464", "+", "0.47", ")", ")", "*", "ln", "(", "0.676", ")", "^", "0.17"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.709)-tan(0.818)/atan((0.47*0.47)*(0.464+0.47))*ln(0.676)^0.17"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.968", ")", "/", "atan", "(", "0.146", ")", "-", "log", "(", "(", "0.730", "^", "0.730", ")", "-", "(", "x", "-", "0.730", ")", ")", "-", "ln", "(", "0.280", ")", "+", "ctg", "(", "0.313", ")", "-", "cos", "(", "(", "0.160", "/", "0.160", ")", "+", "(", "0.160", "-", "0.160", ")", ")", "-", "acos", "(", "0.754", ")", "*", "cos", "(", "0.975", ")", "*", "cos", "(", "(", "0.136", "*", "0.136", ")", "*", "(", "x", "^", "0.136", ")", ")", "/", "cos", "(", "0.868", ")", "+", "cos", "(", "0.928", ")", "^", "sqrt", "(", "(", "0.475", "^", "0.475", ")", "-", "(", "0.475", "+", "0.475", ")", ")", "*", "atan", "(", "0.159", ")", "+", "0.441"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.968)/atan(0.146)-log((0.730^0.730)-(x-0.730))-ln(0.280)+ctg(0.313)-cos((0.160/0.160)+(0.160-0.160))-acos(0.754)*cos(0.975)*cos((0.136*0.136)*(x^0.136))/cos(0.868)+cos(0.928)^sqrt((0.475^0.475)-(0.475+0.475))*atan(0.159)+0.441"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_101) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.626", ")", "/", "atan", "(", "0.274", ")", "*", "sqrt", "(", "(", "0.681", "-", "0.681", ")", "+", "(", "x", "+", "0.681", ")", ")", "^", "actg", "(", "0.654", ")", "-", "acos", "(", "0.132", ")", "/", "atan", "(", "(", "0.932", "*", "0.932", ")", "-", "(", "0.932", "/", "0.932", ")", ")", "+", "sqrt", "(", "0.48", ")", "^", "log", "(", "0.464", ")", "*", "ctg", "(", "(", "0.658", "/", "0.658", ")", "/", "(", "x", "-", "0.658", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.626)/atan(0.274)*sqrt((0.681-0.681)+(x+0.681))^actg(0.654)-acos(0.132)/atan((0.932*0.932)-(0.932/0.932))+sqrt(0.48)^log(0.464)*ctg((0.658/0.658)/(x-0.658))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_102) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.462", ")", "^", "sqrt", "(", "0.764", ")", "*", "log", "(", "(", "0.197", "-", "0.197", ")", "^", "(", "0.197", "-", "0.197", ")", ")", "-", "ctg", "(", "0.941", ")", "/", "sin", "(", "0.684", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.462)^sqrt(0.764)*log((0.197-0.197)^(0.197-0.197))-ctg(0.941)/sin(0.684)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_103) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.985", ")", "/", "ln", "(", "0.280", ")", "-", "ctg", "(", "(", "0.465", "+", "0.465", ")", "/", "(", "0.465", "*", "0.465", ")", ")", "^", "acos", "(", "0.893", ")", "^", "sqrt", "(", "0.647", ")", "^", "atan", "(", "(", "0.121", "-", "0.121", ")", "^", "(", "0.121", "/", "0.121", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.985)/ln(0.280)-ctg((0.465+0.465)/(0.465*0.465))^acos(0.893)^sqrt(0.647)^atan((0.121-0.121)^(0.121/0.121))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_104) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.455", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.455)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_105) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.56", ")", "*", "sqrt", "(", "0.490", ")", "-", "atan", "(", "(", "0.941", "-", "0.941", ")", "-", "(", "0.533", "/", "0.941", ")", ")", "^", "sqrt", "(", "0.232", ")", "/", "actg", "(", "0.207", ")", "+", "ctg", "(", "(", "0.351", "*", "0.351", ")", "/", "(", "0.351", "-", "0.351", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.56)*sqrt(0.490)-atan((0.941-0.941)-(0.533/0.941))^sqrt(0.232)/actg(0.207)+ctg((0.351*0.351)/(0.351-0.351))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_106) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.790", ")", "-", "sin", "(", "0.605", ")", "+", "sin", "(", "(", "0.171", "*", "0.171", ")", "^", "(", "0.518", "-", "0.171", ")", ")", "-", "actg", "(", "0.149", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.790)-sin(0.605)+sin((0.171*0.171)^(0.518-0.171))-actg(0.149)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_107) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "680", "%", "712"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+680%712"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_108) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.157", ")", "-", "0.933"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.157)-0.933"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_109) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.682", ")", "*", "atan", "(", "0.209", ")", "/", "atan", "(", "(", "0.762", "^", "0.762", ")", "*", "(", "0.314", "^", "0.762", ")", ")", "-", "sqrt", "(", "0.615", ")", "+", "ctg", "(", "0.784", ")", "^", "atan", "(", "(", "0.763", "/", "0.763", ")", "*", "(", "x", "/", "0.763", ")", ")", "^", "tan", "(", "0.585", ")", "*", "ln", "(", "0.486", ")", "/", "asin", "(", "(", "0.242", "/", "0.242", ")", "*", "(", "0.242", "*", "0.242", ")", ")", "^", "tan", "(", "0.659", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.682)*atan(0.209)/atan((0.762^0.762)*(0.314^0.762))-sqrt(0.615)+ctg(0.784)^atan((0.763/0.763)*(x/0.763))^tan(0.585)*ln(0.486)/asin((0.242/0.242)*(0.242*0.242))^tan(0.659)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_110) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.745", ")", "-", "sqrt", "(", "0.553", ")", "^", "sin", "(", "(", "0.616", "*", "0.616", ")", "^", "(", "0.616", "^", "0.616", ")", ")", "^", "cos", "(", "0.805", ")", "+", "sqrt", "(", "0.835", ")", "/", "atan", "(", "(", "0.876", "*", "0.876", ")", "+", "(", "0.876", "*", "0.876", ")", ")", "*", "tan", "(", "0.730", ")", "-", "ln", "(", "0.50", ")", "/", "tan", "(", "(", "0.153", "*", "0.153", ")", "+", "(", "x", "*", "0.153", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.745)-sqrt(0.553)^sin((0.616*0.616)^(0.616^0.616))^cos(0.805)+sqrt(0.835)/atan((0.876*0.876)+(0.876*0.876))*tan(0.730)-ln(0.50)/tan((0.153*0.153)+(x*0.153))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_111) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.656", ")", "^", "cos", "(", "0.377", ")", "*", "tan", "(", "(", "0.917", "^", "0.917", ")", "^", "(", "0.149", "+", "0.917", ")", ")", "^", "acos", "(", "0.262", ")", "*", "log", "(", "0.371", ")", "/", "cos", "(", "(", "0.290", "/", "0.290", ")", "/", "(", "x", "*", "0.290", ")", ")", "/", "sqrt", "(", "0.458", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.656)^cos(0.377)*tan((0.917^0.917)^(0.149+0.917))^acos(0.262)*log(0.371)/cos((0.290/0.290)/(x*0.290))/sqrt(0.458)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_112) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.498", ")", "*", "asin", "(", "0.952", ")", "+", "sqrt", "(", "(", "0.326", "*", "0.326", ")", "*", "(", "0.902", "+", "0.326", ")", ")", "^", "sin", "(", "0.68", ")", "-", "ln", "(", "0.258", ")", "^", "actg", "(", "(", "0.393", "^", "0.393", ")", "-", "(", "x", "/", "0.393", ")", ")", "-", "sqrt", "(", "0.201", ")", "/", "log", "(", "0.6", ")", "/", "log", "(", "(", "0.321", "-", "0.321", ")", "^", "(", "x", "-", "0.321", ")", ")", "+", "sqrt", "(", "0.97", ")", "*", "atan", "(", "0.694", ")", "/", "tan", "(", "(", "0.290", "/", "0.290", ")", "^", "(", "x", "^", "0.290", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.498)*asin(0.952)+sqrt((0.326*0.326)*(0.902+0.326))^sin(0.68)-ln(0.258)^actg((0.393^0.393)-(x/0.393))-sqrt(0.201)/log(0.6)/log((0.321-0.321)^(x-0.321))+sqrt(0.97)*atan(0.694)/tan((0.290/0.290)^(x^0.290))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_113) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.186", ")", "*", "tan", "(", "0.460", ")", "+", "sqrt", "(", "(", "0.51", "/", "0.51", ")", "-", "(", "0.280", "+", "0.51", ")", ")", "+", "atan", "(", "0.686", ")", "/", "tan", "(", "0.799", ")", "*", "ln", "(", "(", "0.888", "^", "0.888", ")", "+", "(", "0.888", "-", "0.888", ")", ")", "-", "sqrt", "(", "0.400", ")", "-", "atan", "(", "0.963", ")", "+", "actg", "(", "(", "0.799", "+", "0.799", ")", "/", "(", "x", "/", "0.799", ")", ")", "+", "atan", "(", "0.890", ")", "/", "sin", "(", "0.89", ")", "/", "cos", "(", "(", "0.430", "+", "0.430", ")", "-", "(", "0.224", "-", "0.430", ")", ")", "+", "sqrt", "(", "0.741", ")", "-", "0.189"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.186)*tan(0.460)+sqrt((0.51/0.51)-(0.280+0.51))+atan(0.686)/tan(0.799)*ln((0.888^0.888)+(0.888-0.888))-sqrt(0.400)-atan(0.963)+actg((0.799+0.799)/(x/0.799))+atan(0.890)/sin(0.89)/cos((0.430+0.430)-(0.224-0.430))+sqrt(0.741)-0.189"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_114) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.627", ")", "*", "ctg", "(", "0.529", ")", "*", "ctg", "(", "(", "0.438", "/", "0.438", ")", "+", "(", "x", "*", "0.438", ")", ")", "-", "sin", "(", "0.783", ")", "^", "atan", "(", "0.167", ")", "+", "tan", "(", "(", "0.804", "*", "0.804", ")", "*", "(", "0.279", "/", "0.804", ")", ")", "/", "asin", "(", "0.743", ")", "^", "cos", "(", "0.117", ")", "+", "acos", "(", "(", "0.817", "+", "0.817", ")", "-", "(", "x", "*", "0.817", ")", ")", "*", "ctg", "(", "0.11", ")", "-", "log", "(", "0.815", ")", "+", "asin", "(", "(", "0.907", "+", "0.907", ")", "^", "(", "x", "^", "0.907", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.627)*ctg(0.529)*ctg((0.438/0.438)+(x*0.438))-sin(0.783)^atan(0.167)+tan((0.804*0.804)*(0.279/0.804))/asin(0.743)^cos(0.117)+acos((0.817+0.817)-(x*0.817))*ctg(0.11)-log(0.815)+asin((0.907+0.907)^(x^0.907))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_115) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.32", ")", "/", "asin", "(", "0.665", ")", "+", "cos", "(", "(", "0.968", "+", "0.968", ")", "/", "(", "0.968", "-", "0.968", ")", ")", "/", "atan", "(", "0.301", ")", "*", "cos", "(", "0.433", ")", "+", "cos", "(", "(", "0.180", "+", "0.180", ")", "/", "(", "x", "-", "0.180", ")", ")", "^", "asin", "(", "0.432", ")", "-", "0.988"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.32)/asin(0.665)+cos((0.968+0.968)/(0.968-0.968))/atan(0.301)*cos(0.433)+cos((0.180+0.180)/(x-0.180))^asin(0.432)-0.988"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_116) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.713", ")", "/", "ctg", "(", "0.543", ")", "^", "ctg", "(", "(", "0.928", "^", "0.928", ")", "-", "(", "0.402", "+", "0.928", ")", ")", "+", "log", "(", "0.721", ")", "*", "actg", "(", "0.47", ")", "^", "acos", "(", "(", "0.488", "^", "0.488", ")", "/", "(", "x", "*", "0.488", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.713)/ctg(0.543)^ctg((0.928^0.928)-(0.402+0.928))+log(0.721)*actg(0.47)^acos((0.488^0.488)/(x*0.488))*"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_117) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.187", ")", "*", "cos", "(", "0.713", ")", "*", "ctg", "(", "(", "0.290", "-", "0.290", ")", "-", "(", "x", "^", "0.290", ")", ")", "-", "ctg", "(", "0.546", ")", "-", "log", "(", "0.324", ")", "/", "cos", "(", "(", "0.964", "/", "0.964", ")", "*", "(", "0.964", "*", "0.964", ")", ")", "-", "ctg", "(", "0.796", ")", "-", "ln", "(", "0.680", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.187)*cos(0.713)*ctg((0.290-0.290)-(x^0.290))-ctg(0.546)-log(0.324)/cos((0.964/0.964)*(0.964*0.964))-ctg(0.796)-ln(0.680)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_118) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.494", ")", "^", "sin", "(", "0.535", ")", "+", "tan", "(", "(", "0.319", "^", "0.319", ")", "-", "(", "0.911", "-", "0.319", ")", ")", "^", "cos", "(", "0.966", ")", "-", "asin", "(", "0.277", ")", "^", "cos", "(", "(", "0.374", "-", "0.374", ")", "-", "(", "0.374", "-", "0.374", ")", ")", "/", "sin", "(", "0.612", ")", "-", "asin", "(", "0.792", ")", "-", "ln", "(", "(", "0.720", "/", "0.720", ")", "+", "(", "0.895", "/", "0.720", ")", ")", "^", "tan", "(", "0.941", ")", "+", "ln", "(", "0.834", ")", "/", "atan", "(", "(", "0.46", "^", "0.46", ")", "^", "(", "x", "*", "0.46", ")", ")", "+", "log", "(", "0.725", ")", "-", "asin", "(", "0.600", ")", "^", "ctg", "(", "(", "0.729", "-", "0.729", ")", "*", "(", "0.729", "^", "0.729", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.494)^sin(0.535)+tan((0.319^0.319)-(0.911-0.319))^cos(0.966)-asin(0.277)^cos((0.374-0.374)-(0.374-0.374))/sin(0.612)-asin(0.792)-ln((0.720/0.720)+(0.895/0.720))^tan(0.941)+ln(0.834)/atan((0.46^0.46)^(x*0.46))+log(0.725)-asin(0.600)^ctg((0.729-0.729)*(0.729^0.729))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_119) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.442", ")", "+", "tan", "(", "0.825", ")", "^", "sqrt", "(", "(", "0.708", "+", "0.708", ")", "-", "(", "0.138", "*", "0.708", ")", ")", "+", "ln", "(", "0.611", ")", "*", "tan", "(", "0.794", ")", "^", "tan", "(", "(", "0.529", "+", "0.529", ")", "-", "(", "0.529", "+", "0.529", ")", ")", "^", "tan", "(", "0.4", ")", "^", "atan", "(", "0.532", ")", "^", "tan", "(", "(", "0.458", "-", "0.458", ")", "+", "(", "0.458", "+", "0.458", ")", ")", "/", "ln", "(", "0.673", ")", "*", "log", "(", "0.83", ")", "*", "sqrt", "(", "(", "0.895", "-", "0.895", ")", "*", "(", "x", "/", "0.895", ")", ")", "+", "tan", "(", "0.652", ")", "*", "tan", "(", "0.74", ")", "/", "tan", "(", "(", "0.425", "+", "0.425", ")", "*", "(", "0.425", "^", "0.425", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.442)+tan(0.825)^sqrt((0.708+0.708)-(0.138*0.708))+ln(0.611)*tan(0.794)^tan((0.529+0.529)-(0.529+0.529))^tan(0.4)^atan(0.532)^tan((0.458-0.458)+(0.458+0.458))/ln(0.673)*log(0.83)*sqrt((0.895-0.895)*(x/0.895))+tan(0.652)*tan(0.74)/tan((0.425+0.425)*(0.425^0.425))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_120) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.267", ")", "+", "log", "(", "0.744", ")", "^", "ctg", "(", "(", "0.694", "/", "0.694", ")", "^", "(", "x", "*", "0.694", ")", ")", "*", "log", "(", "0.341", ")", "-", "sin", "(", "0.685", ")", "/", "sin", "(", "(", "0.604", "-", "0.604", ")", "+", "(", "0.604", "*", "0.604", ")", ")", "^", "ctg", "(", "0.677", ")", "-", "log", "(", "0.377", ")", "^", "log", "(", "(", "0.562", "-", "0.562", ")", "-", "(", "0.562", "-", "0.562", ")", ")", "+", "ctg", "(", "0.238", ")", "+", "acos", "(", "0.611", ")", "-", "ctg", "(", "(", "0.476", "-", "0.476", ")", "*", "(", "x", "/", "0.476", ")", ")", "*", "log", "(", "0.262", ")", "*", "0.333"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.267)+log(0.744)^ctg((0.694/0.694)^(x*0.694))*log(0.341)-sin(0.685)/sin((0.604-0.604)+(0.604*0.604))^ctg(0.677)-log(0.377)^log((0.562-0.562)-(0.562-0.562))+ctg(0.238)+acos(0.611)-ctg((0.476-0.476)*(x/0.476))*log(0.262)*0.333"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_121) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.361", ")", "*", "cos", "(", "0.662", ")", "-", "log", "(", "(", "0.392", "/", "0.392", ")", "^", "(", "x", "/", "0.392", ")", ")", "/", "cos", "(", "0.14", ")", "^", "cos", "(", "0.874", ")", "^", "tan", "(", "(", "0.632", "+", "0.632", ")", "*", "(", "x", "^", "0.632", ")", ")", "-", "log", "(", "0.854", ")", "*", "ln", "(", "0.153", ")", "*", "cos", "(", "(", "0.150", "+", "0.150", ")", "-", "(", "0.150", "*", "0.150", ")", ")", "-", "asin", "(", "0.481", ")", "^", "actg", "(", "0.237", ")", "^", "sin", "(", "(", "0.546", "/", "0.546", ")", "/", "(", "0.546", "-", "0.546", ")", ")", "/", "tan", "(", "0.380", ")", "/", "atan", "(", "0.9", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.361)*cos(0.662)-log((0.392/0.392)^(x/0.392))/cos(0.14)^cos(0.874)^tan((0.632+0.632)*(x^0.632))-log(0.854)*ln(0.153)*cos((0.150+0.150)-(0.150*0.150))-asin(0.481)^actg(0.237)^sin((0.546/0.546)/(0.546-0.546))/tan(0.380)/atan(0.9)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_122) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.639", ")", "*", "cos", "(", "0.987", ")", "-", "log", "(", "(", "0.415", "/", "0.415", ")", "*", "(", "0.415", "^", "0.415", ")", ")", "^", "actg", "(", "0.113", ")", "^", "tan", "(", "0.79", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.639)*cos(0.987)-log((0.415/0.415)*(0.415^0.415))^actg(0.113)^tan(0.79)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_123) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.979", ")", "/", "asin", "(", "0.887", ")", "-", "actg", "(", "(", "0.764", "+", "0.764", ")", "+", "(", "0.619", "-", "0.764", ")", ")", "*", "sin", "(", "0.529", ")", "^", "actg", "(", "0.383", ")", "/", "acos", "(", "(", "0.697", "*", "0.697", ")", "^", "(", "0.799", "/", "0.697", ")", ")", "/", "actg", "(", "0.308", ")", "/", "asin", "(", "0.206", ")", "+", "log", "(", "(", "0.822", "*", "0.822", ")", "^", "(", "0.975", "^", "0.822", ")", ")", "-", "ctg", "(", "0.748", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.979)/asin(0.887)-actg((0.764+0.764)+(0.619-0.764))*sin(0.529)^actg(0.383)/acos((0.697*0.697)^(0.799/0.697))/actg(0.308)/asin(0.206)+log((0.822*0.822)^(0.975^0.822))-ctg(0.748)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_124) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.52", ")", "+", "actg", "(", "0.330", ")", "-", "asin", "(", "(", "0.835", "+", "0.835", ")", "-", "(", "0.449", "-", "0.835", ")", ")", "/", "sqrt", "(", "0.106", ")", "+", "actg", "(", "0.621", ")", "/", "actg", "(", "(", "0.901", "+", "0.901", ")", "^", "(", "0.901", "+", "0.901", ")", ")", "/", "ctg", "(", "0.148", ")", "-", "atan", "(", "0.212", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.52)+actg(0.330)-asin((0.835+0.835)-(0.449-0.835))/sqrt(0.106)+actg(0.621)/actg((0.901+0.901)^(0.901+0.901))/ctg(0.148)-atan(0.212)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_125) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.28", ")", "+", "ctg", "(", "0.0", ")", "/", "cos", "(", "(", "0.710", "/", "0.710", ")", "^", "(", "x", "-", "0.710", ")", ")", "+", "log", "(", "0.261", ")", "+", "ln", "(", "0.314", ")", "/", "log", "(", "(", "0.28", "-", "0.28", ")", "+", "(", "0.299", "*", "0.28", ")", ")", "+", "log", "(", "0.168", ")", "/", "actg", "(", "0.75", ")", "*", "log", "(", "(", "0.19", "^", "0.19", ")", "+", "(", "x", "+", "0.19", ")", ")", "/", "sin", "(", "0.915", ")", "/", "0.175"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.28)+ctg(0.0)/cos((0.710/0.710)^(x-0.710))+log(0.261)+ln(0.314)/log((0.28-0.28)+(0.299*0.28))+log(0.168)/actg(0.75)*log((0.19^0.19)+(x+0.19))/sin(0.915)/0.175"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_126) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.585", ")", "+", "cos", "(", "0.857", ")", "-", "ctg", "(", "(", "0.687", "/", "0.687", ")", "+", "(", "x", "-", "0.687", ")", ")", "/", "acos", "(", "0.643", ")", "-", "sqrt", "(", "0.736", ")", "-", "sqrt", "(", "(", "0.225", "-", "0.225", ")", "*", "(", "0.63", "*", "0.225", ")", ")", "*", "ln", "(", "0.909", ")", "*", "log", "(", "0.620", ")", "*", "ln", "(", "(", "0.827", "/", "0.827", ")", "*", "(", "x", "*", "0.827", ")", ")", "/", "sqrt", "(", "0.304", ")", "*", "log", "(", "0.929", ")", "+", "cos", "(", "(", "0.600", "-", "0.600", ")", "^", "(", "x", "^", "0.600", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.585)+cos(0.857)-ctg((0.687/0.687)+(x-0.687))/acos(0.643)-sqrt(0.736)-sqrt((0.225-0.225)*(0.63*0.225))*ln(0.909)*log(0.620)*ln((0.827/0.827)*(x*0.827))/sqrt(0.304)*log(0.929)+cos((0.600-0.600)^(x^0.600))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_127) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.767", ")", "/", "sin", "(", "0.320", ")", "^", "ln", "(", "(", "0.907", "^", "0.907", ")", "-", "(", "0.485", "+", "0.907", ")", ")", "*", "actg", "(", "0.184", ")", "^", "atan", "(", "0.681", ")", "/", "sin", "(", "(", "0.421", "/", "0.421", ")", "^", "(", "x", "^", "0.421", ")", ")", "^", "tan", "(", "0.441", ")", "-", "sin", "(", "0.973", ")", "-", "cos", "(", "(", "0.559", "-", "0.559", ")", "-", "(", "0.565", "*", "0.559", ")", ")", "-", "ctg", "(", "0.939", ")", "-", "cos", "(", "0.863", ")", "-", "sin", "(", "(", "0.259", "/", "0.259", ")", "-", "(", "x", "/", "0.259", ")", ")", "^", "sqrt", "(", "0.631", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.767)/sin(0.320)^ln((0.907^0.907)-(0.485+0.907))*actg(0.184)^atan(0.681)/sin((0.421/0.421)^(x^0.421))^tan(0.441)-sin(0.973)-cos((0.559-0.559)-(0.565*0.559))-ctg(0.939)-cos(0.863)-sin((0.259/0.259)-(x/0.259))^sqrt(0.631)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_128) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.687", ")", "/", "sqrt", "(", "0.512", ")", "-", "cos", "(", "(", "0.504", "*", "0.504", ")", "/", "(", "0.504", "+", "0.504", ")", ")", "*", "sqrt", "(", "0.894", ")", "^", "ctg", "(", "0.113", ")", "*", "ln", "(", "(", "0.386", "^", "0.386", ")", "/", "(", "0.498", "+", "0.386", ")", ")", "+", "sin", "(", "0.354", ")", "^", "ln", "(", "0.753", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.687)/sqrt(0.512)-cos((0.504*0.504)/(0.504+0.504))*sqrt(0.894)^ctg(0.113)*ln((0.386^0.386)/(0.498+0.386))+sin(0.354)^ln(0.753)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_129) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.84", ")", "/", "sqrt", "(", "0.839", ")", "-", "acos", "(", "(", "0.56", "+", "0.56", ")", "*", "(", "x", "*", "0.56", ")", ")", "/", "tan", "(", "0.419", ")", "/", "ctg", "(", "0.905", ")", "+", "sin", "(", "(", "0.517", "*", "0.517", ")", "*", "(", "0.517", "*", "0.517", ")", ")", "+", "ctg", "(", "0.365", ")", "*", "actg", "(", "0.759", ")", "-", "cos", "(", "(", "0.753", "/", "0.753", ")", "^", "(", "0.788", "+", "0.753", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.84)/sqrt(0.839)-acos((0.56+0.56)*(x*0.56))/tan(0.419)/ctg(0.905)+sin((0.517*0.517)*(0.517*0.517))+ctg(0.365)*actg(0.759)-cos((0.753/0.753)^(0.788+0.753))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_130) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.382", ")", "*", "atan", "(", "0.510", ")", "*", "ln", "(", "(", "0.868", "^", "0.868", ")", "-", "(", "x", "+", "0.868", ")", ")", "^", "cos", "(", "0.448", ")", "/", "sqrt", "(", "0.464", ")", "*", "acos", "(", "(", "0.878", "^", "0.878", ")", "-", "(", "x", "*", "0.878", ")", ")", "^", "acos", "(", "0.556", ")", "*", "ctg", "(", "0.339", ")", "^", "actg", "(", "(", "0.330", "/", "0.330", ")", "^", "(", "x", "*", "0.330", ")", ")", "^", "log", "(", "0.902", ")", "/", "ctg", "(", "0.45", ")", "/", "tan", "(", "(", "0.55", "^", "0.55", ")", "+", "(", "x", "^", "0.55", ")", ")", "*", "atan", "(", "0.661", ")", "+", "ln", "(", "0.89", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.382)*atan(0.510)*ln((0.868^0.868)-(x+0.868))^cos(0.448)/sqrt(0.464)*acos((0.878^0.878)-(x*0.878))^acos(0.556)*ctg(0.339)^actg((0.330/0.330)^(x*0.330))^log(0.902)/ctg(0.45)/tan((0.55^0.55)+(x^0.55))*atan(0.661)+ln(0.89)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_131) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.968", ")", "+", "ctg", "(", "0.814", ")", "+", "asin", "(", "(", "0.407", "^", "0.407", ")", "/", "(", "0.761", "*", "0.407", ")", ")", "^", "asin", "(", "0.79", ")", "+", "ctg", "(", "0.785", ")", "^", "ctg", "(", "(", "0.769", "+", "0.769", ")", "/", "(", "0.205", "+", "0.769", ")", ")", "+", "asin", "(", "0.662", ")", "-", "log", "(", "0.82", ")", "+", "atan", "(", "(", "0.748", "/", "0.748", ")", "/", "(", "x", "/", "0.748", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.968)+ctg(0.814)+asin((0.407^0.407)/(0.761*0.407))^asin(0.79)+ctg(0.785)^ctg((0.769+0.769)/(0.205+0.769))+asin(0.662)-log(0.82)+atan((0.748/0.748)/(x/0.748))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_132) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.772", ")", "/", "ctg", "(", "0.851", ")", "*", "log", "(", "(", "0.64", "^", "0.64", ")", "^", "(", "0.422", "+", "0.64", ")", ")", "*", "atan", "(", "0.0", ")", "+", "asin", "(", "0.944", ")", "+", "asin", "(", "(", "0.847", "+", "0.847", ")", "*", "(", "0.565", "-", "0.847", ")", ")", "+", "actg", "(", "0.674", ")", "*", "ln", "(", "0.38", ")", "*", "actg", "(", "(", "0.123", "+", "0.123", ")", "-", "(", "0.350", "*", "0.123", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.772)/ctg(0.851)*log((0.64^0.64)^(0.422+0.64))*atan(0.0)+asin(0.944)+asin((0.847+0.847)*(0.565-0.847))+actg(0.674)*ln(0.38)*actg((0.123+0.123)-(0.350*0.123))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_133) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.530", ")", "+", "ctg", "(", "0.157", ")", "*", "actg", "(", "(", "0.208", "-", "0.208", ")", "^", "(", "0.372", "-", "0.208", ")", ")", "+", "ln", "(", "0.495", ")", "*", "ln", "(", "0.911", ")", "/", "log", "(", "(", "0.752", "-", "0.752", ")", "+", "(", "0.752", "/", "0.752", ")", ")", "*", "actg", "(", "0.774", ")", "+", "ln", "(", "0.559", ")", "^", "actg", "(", "(", "0.619", "+", "0.619", ")", "+", "(", "0.376", "/", "0.619", ")", ")", "^", "sin", "(", "0.737", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.530)+ctg(0.157)*actg((0.208-0.208)^(0.372-0.208))+ln(0.495)*ln(0.911)/log((0.752-0.752)+(0.752/0.752))*actg(0.774)+ln(0.559)^actg((0.619+0.619)+(0.376/0.619))^sin(0.737)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_134) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.451", ")", "^", "tan", "(", "0.859", ")", "^", "actg", "(", "(", "0.748", "/", "0.748", ")", "^", "(", "0.353", "^", "0.748", ")", ")", "-", "sin", "(", "0.453", ")", "-", "actg", "(", "0.663", ")", "*", "ctg", "(", "(", "0.100", "/", "0.100", ")", "/", "(", "0.100", "+", "0.100", ")", ")", "/", "asin", "(", "0.279", ")", "/", "log", "(", "0.83", ")", "/", "tan", "(", "(", "0.929", "/", "0.929", ")", "/", "(", "0.664", "^", "0.929", ")", ")", "-", "sin", "(", "0.353", ")", "*", "acos", "(", "0.130", ")", "^", "sqrt", "(", "(", "0.648", "/", "0.648", ")", "+", "(", "0.39", "/", "0.648", ")", ")", "-", "ctg", "(", "0.471", ")", "/", "0.527"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.451)^tan(0.859)^actg((0.748/0.748)^(0.353^0.748))-sin(0.453)-actg(0.663)*ctg((0.100/0.100)/(0.100+0.100))/asin(0.279)/log(0.83)/tan((0.929/0.929)/(0.664^0.929))-sin(0.353)*acos(0.130)^sqrt((0.648/0.648)+(0.39/0.648))-ctg(0.471)/0.527"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_135) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "203", "%", "407"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+203%407"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_136) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.745", ")", "+", "acos", "(", "0.741", ")", "+", "sqrt", "(", "(", "0.259", "+", "0.259", ")", "*", "(", "0.259", "^", "0.259", ")", ")", "^", "acos", "(", "0.839", ")", "-", "tan", "(", "0.693", ")", "+", "atan", "(", "(", "0.151", "*", "0.151", ")", "/", "(", "0.151", "/", "0.151", ")", ")", "^", "ctg", "(", "0.122", ")", "-", "ln", "(", "0.658", ")", "-", "sin", "(", "(", "0.495", "^", "0.495", ")", "*", "(", "0.195", "-", "0.495", ")", ")", "+", "ln", "(", "0.812", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.745)+acos(0.741)+sqrt((0.259+0.259)*(0.259^0.259))^acos(0.839)-tan(0.693)+atan((0.151*0.151)/(0.151/0.151))^ctg(0.122)-ln(0.658)-sin((0.495^0.495)*(0.195-0.495))+ln(0.812)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_137) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.336", ")", "+", "sin", "(", "0.359", ")", "+", "ctg", "(", "(", "0.100", "/", "0.100", ")", "+", "(", "0.100", "/", "0.100", ")", ")", "^", "actg", "(", "0.817", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.336)+sin(0.359)+ctg((0.100/0.100)+(0.100/0.100))^actg(0.817)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_138) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.138", ")", "/", "ln", "(", "0.541", ")", "+", "tan", "(", "(", "0.891", "+", "0.891", ")", "*", "(", "x", "+", "0.891", ")", ")", "-", "cos", "(", "0.599", ")", "+", "cos", "(", "0.445", ")", "-", "cos", "(", "(", "0.974", "-", "0.974", ")", "+", "(", "0.435", "+", "0.974", ")", ")", "/", "asin", "(", "0.525", ")", "-", "ctg", "(", "0.627", ")", "+", "sqrt", "(", "(", "0.529", "^", "0.529", ")", "^", "(", "0.529", "-", "0.529", ")", ")", "^", "ctg", "(", "0.492", ")", "*", "sin", "(", "0.58", ")", "*", "atan", "(", "(", "0.974", "-", "0.974", ")", "*", "(", "x", "/", "0.974", ")", ")", "^", "log", "(", "0.160", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.138)/ln(0.541)+tan((0.891+0.891)*(x+0.891))-cos(0.599)+cos(0.445)-cos((0.974-0.974)+(0.435+0.974))/asin(0.525)-ctg(0.627)+sqrt((0.529^0.529)^(0.529-0.529))^ctg(0.492)*sin(0.58)*atan((0.974-0.974)*(x/0.974))^log(0.160)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_139) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.720", ")", "/", "atan", "(", "0.67", ")", "/", "acos", "(", "(", "0.723", "-", "0.723", ")", "/", "(", "0.285", "+", "0.723", ")", ")", "*", "ln", "(", "0.448", ")", "^", "asin", "(", "0.861", ")", "-", "actg", "(", "(", "0.489", "*", "0.489", ")", "^", "(", "0.232", "^", "0.489", ")", ")", "+", "asin", "(", "0.188", ")", "+", "ln", "(", "0.907", ")", "/", "log", "(", "(", "0.22", "/", "0.22", ")", "+", "(", "0.22", "+", "0.22", ")", ")", "-", "sin", "(", "0.180", ")", "^", "cos", "(", "0.12", ")", "*", "atan", "(", "(", "0.862", "*", "0.862", ")", "^", "(", "0.862", "*", "0.862", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.720)/atan(0.67)/acos((0.723-0.723)/(0.285+0.723))*ln(0.448)^asin(0.861)-actg((0.489*0.489)^(0.232^0.489))+asin(0.188)+ln(0.907)/log((0.22/0.22)+(0.22+0.22))-sin(0.180)^cos(0.12)*atan((0.862*0.862)^(0.862*0.862))*"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_140) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.844", ")", "^", "sqrt", "(", "0.118", ")", "+", "sqrt", "(", "(", "0.528", "/", "0.528", ")", "-", "(", "0.528", "-", "0.528", ")", ")", "/", "sqrt", "(", "0.137", ")", "/", "ctg", "(", "0.565", ")", "^", "sqrt", "(", "(", "0.830", "+", "0.830", ")", "^", "(", "0.830", "-", "0.830", ")", ")", "*", "sqrt", "(", "0.420", ")", "^", "asin", "(", "0.324", ")", "/", "cos", "(", "(", "0.993", "^", "0.993", ")", "*", "(", "x", "/", "0.993", ")", ")", "+", "sqrt", "(", "0.422", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.844)^sqrt(0.118)+sqrt((0.528/0.528)-(0.528-0.528))/sqrt(0.137)/ctg(0.565)^sqrt((0.830+0.830)^(0.830-0.830))*sqrt(0.420)^asin(0.324)/cos((0.993^0.993)*(x/0.993))+sqrt(0.422)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_141) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.590", ")", "^", "asin", "(", "0.871", ")", "-", "sqrt", "(", "(", "0.784", "/", "0.784", ")", "/", "(", "0.335", "-", "0.784", ")", ")", "^", "sin", "(", "0.446", ")", "+", "0.269"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.590)^asin(0.871)-sqrt((0.784/0.784)/(0.335-0.784))^sin(0.446)+0.269"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_142) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.422", ")", "+", "log", "(", "0.792", ")", "+", "actg", "(", "(", "0.907", "^", "0.907", ")", "/", "(", "0.816", "+", "0.907", ")", ")", "+", "atan", "(", "0.161", ")", "/", "cos", "(", "0.165", ")", "+", "ctg", "(", "(", "0.682", "/", "0.682", ")", "*", "(", "0.352", "*", "0.682", ")", ")", "^", "acos", "(", "0.202", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.422)+log(0.792)+actg((0.907^0.907)/(0.816+0.907))+atan(0.161)/cos(0.165)+ctg((0.682/0.682)*(0.352*0.682))^acos(0.202)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_143) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.286", ")", "+", "sqrt", "(", "0.288", ")", "^", "cos", "(", "(", "0.184", "-", "0.184", ")", "*", "(", "0.121", "+", "0.184", ")", ")", "*", "acos", "(", "0.471", ")", "^", "sqrt", "(", "0.734", ")", "-", "atan", "(", "(", "0.942", "+", "0.942", ")", "-", "(", "x", "-", "0.942", ")", ")", "-", "ctg", "(", "0.537", ")", "^", "ln", "(", "0.312", ")", "/", "tan", "(", "(", "0.989", "-", "0.989", ")", "*", "(", "0.989", "*", "0.989", ")", ")", "/", "ln", "(", "0.213", ")", "+", "asin", "(", "0.720", ")", "/", "cos", "(", "(", "0.14", "^", "0.14", ")", "+", "(", "0.493", "+", "0.14", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.286)+sqrt(0.288)^cos((0.184-0.184)*(0.121+0.184))*acos(0.471)^sqrt(0.734)-atan((0.942+0.942)-(x-0.942))-ctg(0.537)^ln(0.312)/tan((0.989-0.989)*(0.989*0.989))/ln(0.213)+asin(0.720)/cos((0.14^0.14)+(0.493+0.14))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_144) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.846", ")", "^", "atan", "(", "0.945", ")", "/", "sin", "(", "(", "0.262", "+", "0.262", ")", "-", "(", "x", "*", "0.262", ")", ")", "-", "log", "(", "0.962", ")", "-", "sin", "(", "0.749", ")", "-", "tan", "(", "(", "0.606", "^", "0.606", ")", "+", "(", "0.142", "+", "0.606", ")", ")", "^", "ln", "(", "0.407", ")", "-", "sin", "(", "0.504", ")", "^", "acos", "(", "(", "0.998", "-", "0.998", ")", "-", "(", "0.456", "*", "0.998", ")", ")", "/", "cos", "(", "0.305", ")", "/", "0.294"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.846)^atan(0.945)/sin((0.262+0.262)-(x*0.262))-log(0.962)-sin(0.749)-tan((0.606^0.606)+(0.142+0.606))^ln(0.407)-sin(0.504)^acos((0.998-0.998)-(0.456*0.998))/cos(0.305)/0.294"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_145) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.856", ")", "*", "asin", "(", "0.870", ")", "+", "atan", "(", "(", "0.501", "+", "0.501", ")", "/", "(", "x", "-", "0.501", ")", ")", "+", "atan", "(", "0.180", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.856)*asin(0.870)+atan((0.501+0.501)/(x-0.501))+atan(0.180)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_146) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.788", ")", "+", "sqrt", "(", "0.41", ")", "/", "sqrt", "(", "(", "0.511", "^", "0.511", ")", "*", "(", "x", "/", "0.511", ")", ")", "-", "sin", "(", "0.800", ")", "^", "actg", "(", "0.747", ")", "^", "asin", "(", "(", "0.448", "^", "0.448", ")", "-", "(", "x", "^", "0.448", ")", ")", "/", "tan", "(", "0.219", ")", "+", "tan", "(", "0.788", ")", "*", "cos", "(", "(", "0.80", "^", "0.80", ")", "/", "(", "0.730", "*", "0.80", ")", ")", "*", "sqrt", "(", "0.760", ")", "+", "asin", "(", "0.983", ")", "-", "ctg", "(", "(", "0.186", "+", "0.186", ")", "+", "(", "0.169", "^", "0.186", ")", ")", "^", "asin", "(", "0.818", ")", "/", "ln", "(", "0.549", ")", "^", "log", "(", "(", "0.554", "^", "0.554", ")", "^", "(", "0.554", "-", "0.554", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.788)+sqrt(0.41)/sqrt((0.511^0.511)*(x/0.511))-sin(0.800)^actg(0.747)^asin((0.448^0.448)-(x^0.448))/tan(0.219)+tan(0.788)*cos((0.80^0.80)/(0.730*0.80))*sqrt(0.760)+asin(0.983)-ctg((0.186+0.186)+(0.169^0.186))^asin(0.818)/ln(0.549)^log((0.554^0.554)^(0.554-0.554))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_147) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.375", ")", "^", "actg", "(", "0.172", ")", "^", "asin", "(", "(", "0.769", "*", "0.769", ")", "+", "(", "0.769", "/", "0.769", ")", ")", "*", "tan", "(", "0.55", ")", "/", "0.532"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.375)^actg(0.172)^asin((0.769*0.769)+(0.769/0.769))*tan(0.55)/0.532"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_148) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.464", ")", "/", "acos", "(", "0.447", ")", "/", "actg", "(", "(", "0.709", "+", "0.709", ")", "^", "(", "x", "^", "0.709", ")", ")", "^", "log", "(", "0.536", ")", "/", "acos", "(", "0.365", ")", "/", "log", "(", "(", "0.172", "-", "0.172", ")", "*", "(", "0.172", "^", "0.172", ")", ")", "/", "cos", "(", "0.126", ")", "/", "ctg", "(", "0.852", ")", "^", "ctg", "(", "(", "0.235", "+", "0.235", ")", "^", "(", "x", "/", "0.235", ")", ")", "/", "atan", "(", "0.564", ")", "-", "ln", "(", "0.365", ")", "-", "ln", "(", "(", "0.769", "/", "0.769", ")", "/", "(", "x", "^", "0.769", ")", ")", "/", "acos", "(", "0.774", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.464)/acos(0.447)/actg((0.709+0.709)^(x^0.709))^log(0.536)/acos(0.365)/log((0.172-0.172)*(0.172^0.172))/cos(0.126)/ctg(0.852)^ctg((0.235+0.235)^(x/0.235))/atan(0.564)-ln(0.365)-ln((0.769/0.769)/(x^0.769))/acos(0.774)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_149) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.174", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.174)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_150) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.708", ")", "+", "log", "(", "0.607", ")", "-", "sin", "(", "(", "0.264", "*", "0.264", ")", "/", "(", "x", "^", "0.264", ")", ")", "*", "tan", "(", "0.855", ")", "^", "actg", "(", "0.113", ")", "-", "acos", "(", "(", "0.60", "-", "0.60", ")", "*", "(", "x", "-", "0.60", ")", ")", "^", "asin", "(", "0.435", ")", "/", "acos", "(", "0.355", ")", "-", "sqrt", "(", "(", "0.154", "+", "0.154", ")", "/", "(", "x", "^", "0.154", ")", ")", "-", "sqrt", "(", "0.27", ")", "-", "sqrt", "(", "0.903", ")", "^", "actg", "(", "(", "0.672", "*", "0.672", ")", "/", "(", "x", "*", "0.672", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.708)+log(0.607)-sin((0.264*0.264)/(x^0.264))*tan(0.855)^actg(0.113)-acos((0.60-0.60)*(x-0.60))^asin(0.435)/acos(0.355)-sqrt((0.154+0.154)/(x^0.154))-sqrt(0.27)-sqrt(0.903)^actg((0.672*0.672)/(x*0.672))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_151) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.771", ")", "+", "ctg", "(", "0.562", ")", "*", "sin", "(", "(", "0.948", "*", "0.948", ")", "^", "(", "0.948", "*", "0.948", ")", ")", "*", "tan", "(", "0.835", ")", "+", "log", "(", "0.327", ")", "-", "sin", "(", "(", "0.622", "-", "0.622", ")", "-", "(", "0.622", "*", "0.622", ")", ")", "/", "ln", "(", "0.334", ")", "^", "actg", "(", "0.681", ")", "*", "ln", "(", "(", "0.391", "-", "0.391", ")", "-", "(", "0.630", "/", "0.391", ")", ")", "/", "actg", "(", "0.103", ")", "*", "atan", "(", "0.399", ")", "^", "tan", "(", "(", "0.995", "/", "0.995", ")", "^", "(", "x", "+", "0.995", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.771)+ctg(0.562)*sin((0.948*0.948)^(0.948*0.948))*tan(0.835)+log(0.327)-sin((0.622-0.622)-(0.622*0.622))/ln(0.334)^actg(0.681)*ln((0.391-0.391)-(0.630/0.391))/actg(0.103)*atan(0.399)^tan((0.995/0.995)^(x+0.995))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_152) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.795", ")", "/", "tan", "(", "0.146", ")", "*", "sin", "(", "(", "0.619", "^", "0.619", ")", "*", "(", "x", "/", "0.619", ")", ")", "/", "acos", "(", "0.582", ")", "-", "ctg", "(", "0.616", ")", "^", "atan", "(", "(", "0.215", "^", "0.215", ")", "*", "(", "0.215", "/", "0.215", ")", ")", "*", "asin", "(", "0.72", ")", "/", "sin", "(", "0.334", ")", "/", "sqrt", "(", "(", "0.266", "/", "0.266", ")", "^", "(", "x", "^", "0.266", ")", ")", "+", "asin", "(", "0.922", ")", "-", "actg", "(", "0.209", ")", "^", "actg", "(", "(", "0.676", "/", "0.676", ")", "/", "(", "0.409", "/", "0.676", ")", ")", "+", "asin", "(", "0.871", ")", "*", "ctg", "(", "0.295", ")", "^", "log", "(", "(", "0.687", "/", "0.687", ")", "+", "(", "0.378", "^", "0.687", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.795)/tan(0.146)*sin((0.619^0.619)*(x/0.619))/acos(0.582)-ctg(0.616)^atan((0.215^0.215)*(0.215/0.215))*asin(0.72)/sin(0.334)/sqrt((0.266/0.266)^(x^0.266))+asin(0.922)-actg(0.209)^actg((0.676/0.676)/(0.409/0.676))+asin(0.871)*ctg(0.295)^log((0.687/0.687)+(0.378^0.687))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_153) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.978", ")", "^", "asin", "(", "0.667", ")", "+", "ctg", "(", "(", "0.449", "*", "0.449", ")", "+", "(", "0.449", "*", "0.449", ")", ")", "-", "atan", "(", "0.226", ")", "+", "cos", "(", "0.162", ")", "/", "sin", "(", "(", "0.604", "/", "0.604", ")", "/", "(", "x", "*", "0.604", ")", ")", "*", "atan", "(", "0.691", ")", "/", "ln", "(", "0.263", ")", "+", "sin", "(", "(", "0.957", "+", "0.957", ")", "^", "(", "x", "^", "0.957", ")", ")", "*", "acos", "(", "0.680", ")", "-", "tan", "(", "0.801", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.978)^asin(0.667)+ctg((0.449*0.449)+(0.449*0.449))-atan(0.226)+cos(0.162)/sin((0.604/0.604)/(x*0.604))*atan(0.691)/ln(0.263)+sin((0.957+0.957)^(x^0.957))*acos(0.680)-tan(0.801)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_154) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.457", ")", "+", "asin", "(", "0.983", ")", "-", "atan", "(", "(", "0.676", "-", "0.676", ")", "-", "(", "0.676", "+", "0.676", ")", ")", "*", "ln", "(", "0.926", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.457)+asin(0.983)-atan((0.676-0.676)-(0.676+0.676))*ln(0.926)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_155) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.154", ")", "-", "ctg", "(", "0.798", ")", "-", "atan", "(", "(", "0.119", "*", "0.119", ")", "^", "(", "0.977", "^", "0.119", ")", ")", "/", "acos", "(", "0.192", ")", "+", "acos", "(", "0.690", ")", "/", "tan", "(", "(", "0.373", "+", "0.373", ")", "+", "(", "0.81", "/", "0.373", ")", ")", "*", "asin", "(", "0.339", ")", "/", "sin", "(", "0.407", ")", "^", "atan", "(", "(", "0.974", "/", "0.974", ")", "-", "(", "x", "^", "0.974", ")", ")", "/", "log", "(", "0.572", ")", "^", "actg", "(", "0.416", ")", "+", "cos", "(", "(", "0.763", "+", "0.763", ")", "+", "(", "0.763", "+", "0.763", ")", ")", "-", "tan", "(", "0.452", ")", "^", "actg", "(", "0.200", ")", "*", "asin", "(", "(", "0.792", "*", "0.792", ")", "^", "(", "0.6", "^", "0.792", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.154)-ctg(0.798)-atan((0.119*0.119)^(0.977^0.119))/acos(0.192)+acos(0.690)/tan((0.373+0.373)+(0.81/0.373))*asin(0.339)/sin(0.407)^atan((0.974/0.974)-(x^0.974))/log(0.572)^actg(0.416)+cos((0.763+0.763)+(0.763+0.763))-tan(0.452)^actg(0.200)*asin((0.792*0.792)^(0.6^0.792))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_156) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.451", ")", "*", "actg", "(", "0.309", ")", "*", "atan", "(", "(", "0.224", "/", "0.224", ")", "^", "(", "x", "/", "0.224", ")", ")", "*", "acos", "(", "0.59", ")", "+", "tan", "(", "0.172", ")", "^", "actg", "(", "(", "0.443", "-", "0.443", ")", "^", "(", "0.811", "/", "0.443", ")", ")", "+", "tan", "(", "0.346", ")", "+", "sqrt", "(", "0.546", ")", "^", "sin", "(", "(", "0.19", "/", "0.19", ")", "^", "(", "x", "+", "0.19", ")", ")", "*", "atan", "(", "0.24", ")", "-", "0.693"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.451)*actg(0.309)*atan((0.224/0.224)^(x/0.224))*acos(0.59)+tan(0.172)^actg((0.443-0.443)^(0.811/0.443))+tan(0.346)+sqrt(0.546)^sin((0.19/0.19)^(x+0.19))*atan(0.24)-0.693"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_157) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.634", ")", "-", "0.952"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.634)-0.952"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_158) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.881", ")", "+", "ctg", "(", "0.150", ")", "*", "asin", "(", "(", "0.19", "/", "0.19", ")", "/", "(", "x", "-", "0.19", ")", ")", "+", "actg", "(", "0.598", ")", "^", "acos", "(", "0.262", ")", "^", "log", "(", "(", "0.490", "*", "0.490", ")", "^", "(", "x", "*", "0.490", ")", ")", "+", "cos", "(", "0.503", ")", "*", "asin", "(", "0.421", ")", "^", "sqrt", "(", "(", "0.88", "-", "0.88", ")", "+", "(", "0.88", "*", "0.88", ")", ")", "^", "tan", "(", "0.962", ")", "^", "ln", "(", "0.372", ")", "^", "cos", "(", "(", "0.962", "*", "0.962", ")", "^", "(", "0.791", "+", "0.962", ")", ")", "-", "ln", "(", "0.471", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.881)+ctg(0.150)*asin((0.19/0.19)/(x-0.19))+actg(0.598)^acos(0.262)^log((0.490*0.490)^(x*0.490))+cos(0.503)*asin(0.421)^sqrt((0.88-0.88)+(0.88*0.88))^tan(0.962)^ln(0.372)^cos((0.962*0.962)^(0.791+0.962))-ln(0.471)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_159) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.896", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.896)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_160) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.394", ")", "^", "atan", "(", "0.322", ")", "-", "ctg", "(", "(", "0.430", "-", "0.430", ")", "*", "(", "0.430", "+", "0.430", ")", ")", "^", "actg", "(", "0.768", ")", "-", "tan", "(", "0.167", ")", "-", "tan", "(", "(", "0.84", "/", "0.84", ")", "/", "(", "x", "*", "0.84", ")", ")", "*", "asin", "(", "0.166", ")", "*", "sqrt", "(", "0.569", ")", "+", "ln", "(", "(", "0.42", "^", "0.42", ")", "*", "(", "x", "+", "0.42", ")", ")", "-", "sin", "(", "0.142", ")", "*", "ln", "(", "0.836", ")", "^", "tan", "(", "(", "0.241", "+", "0.241", ")", "*", "(", "0.404", "*", "0.241", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.394)^atan(0.322)-ctg((0.430-0.430)*(0.430+0.430))^actg(0.768)-tan(0.167)-tan((0.84/0.84)/(x*0.84))*asin(0.166)*sqrt(0.569)+ln((0.42^0.42)*(x+0.42))-sin(0.142)*ln(0.836)^tan((0.241+0.241)*(0.404*0.241))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_161) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.854", ")", "/", "cos", "(", "0.479", ")", "/", "cos", "(", "(", "0.750", "-", "0.750", ")", "^", "(", "0.500", "-", "0.750", ")", ")", "+", "sqrt", "(", "0.56", ")", "*", "log", "(", "0.146", ")", "-", "tan", "(", "(", "0.384", "+", "0.384", ")", "*", "(", "0.436", "+", "0.384", ")", ")", "-", "actg", "(", "0.741", ")", "*", "sin", "(", "0.498", ")", "/", "acos", "(", "(", "0.697", "/", "0.697", ")", "-", "(", "0.697", "*", "0.697", ")", ")", "-", "atan", "(", "0.505", ")", "^", "actg", "(", "0.36", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.854)/cos(0.479)/cos((0.750-0.750)^(0.500-0.750))+sqrt(0.56)*log(0.146)-tan((0.384+0.384)*(0.436+0.384))-actg(0.741)*sin(0.498)/acos((0.697/0.697)-(0.697*0.697))-atan(0.505)^actg(0.36)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_162) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.727", ")", "^", "acos", "(", "0.979", ")", "*", "atan", "(", "(", "0.904", "*", "0.904", ")", "/", "(", "0.904", "*", "0.904", ")", ")", "+", "ctg", "(", "0.115", ")", "-", "sqrt", "(", "0.171", ")", "+", "acos", "(", "(", "0.841", "^", "0.841", ")", "^", "(", "0.841", "^", "0.841", ")", ")", "-", "atan", "(", "0.247", ")", "/", "ln", "(", "0.288", ")", "/", "log", "(", "(", "0.903", "+", "0.903", ")", "*", "(", "0.344", "^", "0.903", ")", ")", "+", "ln", "(", "0.873", ")", "/", "log", "(", "0.861", ")", "-", "acos", "(", "(", "0.544", "/", "0.544", ")", "*", "(", "0.314", "*", "0.544", ")", ")", "*", "ln", "(", "0.185", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.727)^acos(0.979)*atan((0.904*0.904)/(0.904*0.904))+ctg(0.115)-sqrt(0.171)+acos((0.841^0.841)^(0.841^0.841))-atan(0.247)/ln(0.288)/log((0.903+0.903)*(0.344^0.903))+ln(0.873)/log(0.861)-acos((0.544/0.544)*(0.314*0.544))*ln(0.185)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_163) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.361", ")", "*", "atan", "(", "0.9", ")", "*", "atan", "(", "(", "0.136", "*", "0.136", ")", "^", "(", "0.136", "/", "0.136", ")", ")", "^", "actg", "(", "0.868", ")", "*", "sin", "(", "0.347", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.361)*atan(0.9)*atan((0.136*0.136)^(0.136/0.136))^actg(0.868)*sin(0.347)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_164) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.554", ")", "+", "asin", "(", "0.718", ")", "^", "asin", "(", "(", "0.982", "^", "0.982", ")", "/", "(", "0.822", "-", "0.982", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.554)+asin(0.718)^asin((0.982^0.982)/(0.822-0.982))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_165) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.192", ")", "^", "ln", "(", "0.10", ")", "-", "cos", "(", "(", "0.205", "*", "0.205", ")", "^", "(", "0.205", "^", "0.205", ")", ")", "*", "tan", "(", "0.594", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.192)^ln(0.10)-cos((0.205*0.205)^(0.205^0.205))*tan(0.594)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_166) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.53", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.53)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_167) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.77", ")", "+", "cos", "(", "0.2", ")", "*", "ctg", "(", "(", "0.503", "-", "0.503", ")", "+", "(", "0.762", "*", "0.503", ")", ")", "+", "sin", "(", "0.559", ")", "+", "acos", "(", "0.231", ")", "+", "atan", "(", "(", "0.758", "-", "0.758", ")", "-", "(", "x", "/", "0.758", ")", ")", "+", "ln", "(", "0.968", ")", "^", "sin", "(", "0.587", ")", "-", "acos", "(", "(", "0.202", "-", "0.202", ")", "/", "(", "0.202", "+", "0.202", ")", ")", "/", "log", "(", "0.210", ")", "/", "sin", "(", "0.632", ")", "*", "actg", "(", "(", "0.172", "-", "0.172", ")", "*", "(", "x", "+", "0.172", ")", ")", "*", "acos", "(", "0.966", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.77)+cos(0.2)*ctg((0.503-0.503)+(0.762*0.503))+sin(0.559)+acos(0.231)+atan((0.758-0.758)-(x/0.758))+ln(0.968)^sin(0.587)-acos((0.202-0.202)/(0.202+0.202))/log(0.210)/sin(0.632)*actg((0.172-0.172)*(x+0.172))*acos(0.966)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_168) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.803", ")", "^", "sqrt", "(", "0.501", ")", "+", "asin", "(", "(", "0.588", "^", "0.588", ")", "-", "(", "0.345", "/", "0.588", ")", ")", "^", "atan", "(", "0.981", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.803)^sqrt(0.501)+asin((0.588^0.588)-(0.345/0.588))^atan(0.981)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_169) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.599", ")", "/", "acos", "(", "0.9", ")", "+", "ctg", "(", "(", "0.84", "*", "0.84", ")", "+", "(", "x", "/", "0.84", ")", ")", "+", "atan", "(", "0.684", ")", "*", "sqrt", "(", "0.713", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.599)/acos(0.9)+ctg((0.84*0.84)+(x/0.84))+atan(0.684)*sqrt(0.713)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_170) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.526", ")", "/", "actg", "(", "0.850", ")", "-", "atan", "(", "(", "0.596", "/", "0.596", ")", "*", "(", "0.596", "*", "0.596", ")", ")", "^", "cos", "(", "0.457", ")", "^", "asin", "(", "0.235", ")", "+", "asin", "(", "(", "0.705", "+", "0.705", ")", "+", "(", "0.887", "+", "0.705", ")", ")", "/", "asin", "(", "0.875", ")", "^", "ln", "(", "0.382", ")", "/", "acos", "(", "(", "0.159", "^", "0.159", ")", "^", "(", "x", "+", "0.159", ")", ")", "/", "ctg", "(", "0.138", ")", "+", "acos", "(", "0.256", ")", "*", "ln", "(", "(", "0.377", "^", "0.377", ")", "/", "(", "x", "-", "0.377", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.526)/actg(0.850)-atan((0.596/0.596)*(0.596*0.596))^cos(0.457)^asin(0.235)+asin((0.705+0.705)+(0.887+0.705))/asin(0.875)^ln(0.382)/acos((0.159^0.159)^(x+0.159))/ctg(0.138)+acos(0.256)*ln((0.377^0.377)/(x-0.377))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_171) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.911", ")", "/", "ln", "(", "0.332", ")", "-", "sin", "(", "(", "0.376", "*", "0.376", ")", "^", "(", "0.260", "/", "0.376", ")", ")", "-", "cos", "(", "0.356", ")", "-", "log", "(", "0.824", ")", "+", "acos", "(", "(", "0.723", "/", "0.723", ")", "/", "(", "x", "^", "0.723", ")", ")", "-", "ctg", "(", "0.324", ")", "*", "acos", "(", "0.601", ")", "/", "cos", "(", "(", "0.795", "*", "0.795", ")", "+", "(", "0.795", "^", "0.795", ")", ")", "-", "cos", "(", "0.455", ")", "*", "sin", "(", "0.722", ")", "+", "log", "(", "(", "0.319", "-", "0.319", ")", "-", "(", "0.875", "*", "0.319", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.911)/ln(0.332)-sin((0.376*0.376)^(0.260/0.376))-cos(0.356)-log(0.824)+acos((0.723/0.723)/(x^0.723))-ctg(0.324)*acos(0.601)/cos((0.795*0.795)+(0.795^0.795))-cos(0.455)*sin(0.722)+log((0.319-0.319)-(0.875*0.319))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_172) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.384", ")", "-", "actg", "(", "0.992", ")", "^", "cos", "(", "(", "0.983", "+", "0.983", ")", "-", "(", "x", "^", "0.983", ")", ")", "+", "asin", "(", "0.58", ")", "/", "log", "(", "0.123", ")", "*", "cos", "(", "(", "0.408", "/", "0.408", ")", "^", "(", "0.408", "*", "0.408", ")", ")", "-", "cos", "(", "0.207", ")", "+", "cos", "(", "0.760", ")", "*", "log", "(", "(", "0.846", "+", "0.846", ")", "/", "(", "0.705", "*", "0.846", ")", ")", "+", "ln", "(", "0.18", ")", "-", "sin", "(", "0.216", ")", "^", "actg", "(", "(", "0.918", "*", "0.918", ")", "^", "(", "0.96", "^", "0.918", ")", ")", "/", "log", "(", "0.286", ")", "^", "0.947"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.384)-actg(0.992)^cos((0.983+0.983)-(x^0.983))+asin(0.58)/log(0.123)*cos((0.408/0.408)^(0.408*0.408))-cos(0.207)+cos(0.760)*log((0.846+0.846)/(0.705*0.846))+ln(0.18)-sin(0.216)^actg((0.918*0.918)^(0.96^0.918))/log(0.286)^0.947"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_173) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.78", ")", "-", "ln", "(", "0.371", ")", "*", "tan", "(", "(", "0.99", "+", "0.99", ")", "^", "(", "0.99", "+", "0.99", ")", ")", "/", "atan", "(", "0.926", ")", "/", "sqrt", "(", "0.190", ")", "+", "acos", "(", "(", "0.461", "^", "0.461", ")", "+", "(", "0.461", "*", "0.461", ")", ")", "+", "atan", "(", "0.80", ")", "*", "ln", "(", "0.27", ")", "-", "acos", "(", "(", "0.225", "-", "0.225", ")", "-", "(", "x", "+", "0.225", ")", ")", "/", "cos", "(", "0.816", ")", "*", "0.290"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.78)-ln(0.371)*tan((0.99+0.99)^(0.99+0.99))/atan(0.926)/sqrt(0.190)+acos((0.461^0.461)+(0.461*0.461))+atan(0.80)*ln(0.27)-acos((0.225-0.225)-(x+0.225))/cos(0.816)*0.290"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_174) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.798", ")", "-", "acos", "(", "0.414", ")", "+", "cos", "(", "(", "0.774", "/", "0.774", ")", "^", "(", "0.469", "*", "0.774", ")", ")", "-", "log", "(", "0.913", ")", "-", "sqrt", "(", "0.451", ")", "*", "atan", "(", "(", "0.641", "-", "0.641", ")", "-", "(", "0.918", "-", "0.641", ")", ")", "/", "actg", "(", "0.344", ")", "*", "acos", "(", "0.78", ")", "/", "sqrt", "(", "(", "0.349", "/", "0.349", ")", "+", "(", "x", "-", "0.349", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.798)-acos(0.414)+cos((0.774/0.774)^(0.469*0.774))-log(0.913)-sqrt(0.451)*atan((0.641-0.641)-(0.918-0.641))/actg(0.344)*acos(0.78)/sqrt((0.349/0.349)+(x-0.349))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_175) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.38", ")", "/", "atan", "(", "0.652", ")", "/", "atan", "(", "(", "0.593", "-", "0.593", ")", "+", "(", "0.593", "/", "0.593", ")", ")", "/", "sqrt", "(", "0.100", ")", "+", "tan", "(", "0.137", ")", "/", "ctg", "(", "(", "0.565", "+", "0.565", ")", "^", "(", "0.565", "^", "0.565", ")", ")", "^", "log", "(", "0.489", ")", "^", "acos", "(", "0.179", ")", "/", "sin", "(", "(", "0.25", "*", "0.25", ")", "-", "(", "x", "-", "0.25", ")", ")", "+", "cos", "(", "0.887", ")", "+", "sin", "(", "0.248", ")", "^", "ctg", "(", "(", "0.800", "*", "0.800", ")", "-", "(", "0.800", "*", "0.800", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.38)/atan(0.652)/atan((0.593-0.593)+(0.593/0.593))/sqrt(0.100)+tan(0.137)/ctg((0.565+0.565)^(0.565^0.565))^log(0.489)^acos(0.179)/sin((0.25*0.25)-(x-0.25))+cos(0.887)+sin(0.248)^ctg((0.800*0.800)-(0.800*0.800))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_176) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.368", ")", "*", "log", "(", "0.933", ")", "-", "ln", "(", "(", "0.0", "^", "0.0", ")", "^", "(", "0.380", "/", "0.0", ")", ")", "+", "ln", "(", "0.353", ")", "-", "ln", "(", "0.531", ")", "^", "sqrt", "(", "(", "0.792", "-", "0.792", ")", "+", "(", "0.594", "+", "0.792", ")", ")", "-", "cos", "(", "0.81", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.368)*log(0.933)-ln((0.0^0.0)^(0.380/0.0))+ln(0.353)-ln(0.531)^sqrt((0.792-0.792)+(0.594+0.792))-cos(0.81)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_177) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.236", ")", "*", "tan", "(", "0.499", ")", "*", "acos", "(", "(", "0.504", "-", "0.504", ")", "^", "(", "0.504", "*", "0.504", ")", ")", "-", "actg", "(", "0.635", ")", "/", "atan", "(", "0.649", ")", "-", "sqrt", "(", "(", "0.221", "+", "0.221", ")", "+", "(", "x", "+", "0.221", ")", ")", "-", "ctg", "(", "0.979", ")", "-", "acos", "(", "0.402", ")", "/", "ctg", "(", "(", "0.778", "-", "0.778", ")", "+", "(", "0.778", "/", "0.778", ")", ")", "^", "log", "(", "0.13", ")", "/", "asin", "(", "0.185", ")", "+", "cos", "(", "(", "0.388", "/", "0.388", ")", "+", "(", "0.388", "-", "0.388", ")", ")", "/", "cos", "(", "0.785", ")", "*", "log", "(", "0.424", ")", "/", "ctg", "(", "(", "0.683", "^", "0.683", ")", "-", "(", "0.312", "+", "0.683", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.236)*tan(0.499)*acos((0.504-0.504)^(0.504*0.504))-actg(0.635)/atan(0.649)-sqrt((0.221+0.221)+(x+0.221))-ctg(0.979)-acos(0.402)/ctg((0.778-0.778)+(0.778/0.778))^log(0.13)/asin(0.185)+cos((0.388/0.388)+(0.388-0.388))/cos(0.785)*log(0.424)/ctg((0.683^0.683)-(0.312+0.683))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_178) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.903", ")", "^", "sin", "(", "0.855", ")", "+", "cos", "(", "(", "0.288", "/", "0.288", ")", "+", "(", "x", "^", "0.288", ")", ")", "*", "cos", "(", "0.890", ")", "^", "asin", "(", "0.989", ")", "*", "ln", "(", "(", "0.587", "*", "0.587", ")", "^", "(", "x", "*", "0.587", ")", ")", "/", "actg", "(", "0.760", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.903)^sin(0.855)+cos((0.288/0.288)+(x^0.288))*cos(0.890)^asin(0.989)*ln((0.587*0.587)^(x*0.587))/actg(0.760)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_179) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.751", ")", "+", "0.242"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.751)+0.242"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_180) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.77", ")", "*", "ctg", "(", "0.736", ")", "/", "actg", "(", "(", "0.354", "*", "0.354", ")", "/", "(", "0.869", "/", "0.354", ")", ")", "+", "log", "(", "0.793", ")", "^", "0.741"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.77)*ctg(0.736)/actg((0.354*0.354)/(0.869/0.354))+log(0.793)^0.741"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_181) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.578", ")", "^", "asin", "(", "0.694", ")", "-", "atan", "(", "(", "0.808", "^", "0.808", ")", "/", "(", "x", "+", "0.808", ")", ")", "^", "tan", "(", "0.104", ")", "+", "sqrt", "(", "0.915", ")", "*", "log", "(", "(", "0.534", "/", "0.534", ")", "/", "(", "0.534", "/", "0.534", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.578)^asin(0.694)-atan((0.808^0.808)/(x+0.808))^tan(0.104)+sqrt(0.915)*log((0.534/0.534)/(0.534/0.534))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_182) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.411", ")", "*", "log", "(", "0.206", ")", "^", "sqrt", "(", "(", "0.295", "*", "0.295", ")", "*", "(", "x", "+", "0.295", ")", ")", "^", "ctg", "(", "0.919", ")", "^", "cos", "(", "0.650", ")", "+", "sin", "(", "(", "0.547", "^", "0.547", ")", "+", "(", "x", "^", "0.547", ")", ")", "+", "asin", "(", "0.162", ")", "+", "sqrt", "(", "0.119", ")", "+", "ln", "(", "(", "0.866", "^", "0.866", ")", "*", "(", "0.866", "+", "0.866", ")", ")", "/", "log", "(", "0.607", ")", "+", "ln", "(", "0.535", ")", "^", "ctg", "(", "(", "0.637", "*", "0.637", ")", "+", "(", "0.187", "/", "0.637", ")", ")", "^", "log", "(", "0.349", ")", "*", "ctg", "(", "0.182", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.411)*log(0.206)^sqrt((0.295*0.295)*(x+0.295))^ctg(0.919)^cos(0.650)+sin((0.547^0.547)+(x^0.547))+asin(0.162)+sqrt(0.119)+ln((0.866^0.866)*(0.866+0.866))/log(0.607)+ln(0.535)^ctg((0.637*0.637)+(0.187/0.637))^log(0.349)*ctg(0.182)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_183) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.239", ")", "^", "log", "(", "0.393", ")", "*", "atan", "(", "(", "0.710", "^", "0.710", ")", "*", "(", "0.710", "-", "0.710", ")", ")", "-", "acos", "(", "0.420", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.239)^log(0.393)*atan((0.710^0.710)*(0.710-0.710))-acos(0.420)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_184) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.54", ")", "-", "atan", "(", "0.822", ")", "+", "tan", "(", "(", "0.407", "*", "0.407", ")", "+", "(", "0.55", "^", "0.407", ")", ")", "^", "actg", "(", "0.723", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.54)-atan(0.822)+tan((0.407*0.407)+(0.55^0.407))^actg(0.723)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_185) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.357", ")", "^", "asin", "(", "0.659", ")", "+", "sin", "(", "(", "0.836", "^", "0.836", ")", "-", "(", "0.836", "^", "0.836", ")", ")", "-", "ctg", "(", "0.116", ")", "/", "ctg", "(", "0.513", ")", "^", "sin", "(", "(", "0.463", "/", "0.463", ")", "-", "(", "x", "+", "0.463", ")", ")", "*", "asin", "(", "0.456", ")", "/", "atan", "(", "0.122", ")", "*", "atan", "(", "(", "0.825", "-", "0.825", ")", "^", "(", "0.825", "*", "0.825", ")", ")", "-", "sin", "(", "0.947", ")", "^", "0.497"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.357)^asin(0.659)+sin((0.836^0.836)-(0.836^0.836))-ctg(0.116)/ctg(0.513)^sin((0.463/0.463)-(x+0.463))*asin(0.456)/atan(0.122)*atan((0.825-0.825)^(0.825*0.825))-sin(0.947)^0.497"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_186) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.639", ")", "-", "asin", "(", "0.160", ")", "-", "log", "(", "(", "0.223", "*", "0.223", ")", "*", "(", "x", "+", "0.223", ")", ")", "^", "cos", "(", "0.4", ")", "*", "actg", "(", "0.856", ")", "*", "sqrt", "(", "(", "0.293", "-", "0.293", ")", "*", "(", "x", "/", "0.293", ")", ")", "^", "ln", "(", "0.852", ")", "+", "ln", "(", "0.347", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.639)-asin(0.160)-log((0.223*0.223)*(x+0.223))^cos(0.4)*actg(0.856)*sqrt((0.293-0.293)*(x/0.293))^ln(0.852)+ln(0.347)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_187) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.527", ")", "/", "sqrt", "(", "0.464", ")", "^", "log", "(", "(", "0.812", "^", "0.812", ")", "-", "(", "0.435", "^", "0.812", ")", ")", "*", "acos", "(", "0.770", ")", "/", "sqrt", "(", "0.175", ")", "+", "acos", "(", "(", "0.111", "/", "0.111", ")", "^", "(", "0.442", "/", "0.111", ")", ")", "^", "log", "(", "0.365", ")", "-", "acos", "(", "0.756", ")", "-", "ln", "(", "(", "0.995", "-", "0.995", ")", "-", "(", "0.995", "*", "0.995", ")", ")", "^", "actg", "(", "0.208", ")", "+", "sin", "(", "0.723", ")", "+", "cos", "(", "(", "0.449", "-", "0.449", ")", "+", "(", "0.449", "*", "0.449", ")", ")", "-", "sin", "(", "0.616", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.527)/sqrt(0.464)^log((0.812^0.812)-(0.435^0.812))*acos(0.770)/sqrt(0.175)+acos((0.111/0.111)^(0.442/0.111))^log(0.365)-acos(0.756)-ln((0.995-0.995)-(0.995*0.995))^actg(0.208)+sin(0.723)+cos((0.449-0.449)+(0.449*0.449))-sin(0.616)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_188) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.306", ")", "*", "ln", "(", "0.789", ")", "+", "sin", "(", "(", "0.307", "/", "0.307", ")", "/", "(", "x", "+", "0.307", ")", ")", "+", "atan", "(", "0.935", ")", "^", "ln", "(", "0.844", ")", "*", "sin", "(", "(", "0.489", "+", "0.489", ")", "*", "(", "0.489", "*", "0.489", ")", ")", "+", "log", "(", "0.967", ")", "/", "sin", "(", "0.680", ")", "^", "cos", "(", "(", "0.791", "+", "0.791", ")", "+", "(", "0.791", "/", "0.791", ")", ")", "/", "ctg", "(", "0.669", ")", "+", "sin", "(", "0.30", ")", "-", "acos", "(", "(", "0.346", "^", "0.346", ")", "/", "(", "0.346", "^", "0.346", ")", ")", "*", "ln", "(", "0.729", ")", "+", "atan", "(", "0.843", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.306)*ln(0.789)+sin((0.307/0.307)/(x+0.307))+atan(0.935)^ln(0.844)*sin((0.489+0.489)*(0.489*0.489))+log(0.967)/sin(0.680)^cos((0.791+0.791)+(0.791/0.791))/ctg(0.669)+sin(0.30)-acos((0.346^0.346)/(0.346^0.346))*ln(0.729)+atan(0.843)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_189) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.424", ")", "^", "tan", "(", "0.578", ")", "+", "atan", "(", "(", "0.414", "^", "0.414", ")", "-", "(", "0.35", "^", "0.414", ")", ")", "^", "atan", "(", "0.656", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.424)^tan(0.578)+atan((0.414^0.414)-(0.35^0.414))^atan(0.656)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_190) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.204", ")", "+", "acos", "(", "0.29", ")", "/", "actg", "(", "(", "0.4", "-", "0.4", ")", "-", "(", "0.4", "^", "0.4", ")", ")", "+", "ctg", "(", "0.83", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.204)+acos(0.29)/actg((0.4-0.4)-(0.4^0.4))+ctg(0.83)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_191) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.451", ")", "*", "tan", "(", "0.327", ")", "^", "sqrt", "(", "(", "0.7", "/", "0.7", ")", "/", "(", "x", "-", "0.7", ")", ")", "-", "sin", "(", "0.107", ")", "-", "ln", "(", "0.407", ")", "^", "actg", "(", "(", "0.576", "+", "0.576", ")", "/", "(", "0.576", "+", "0.576", ")", ")", "/", "sin", "(", "0.71", ")", "/", "sqrt", "(", "0.777", ")", "*", "ctg", "(", "(", "0.826", "*", "0.826", ")", "*", "(", "x", "*", "0.826", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.451)*tan(0.327)^sqrt((0.7/0.7)/(x-0.7))-sin(0.107)-ln(0.407)^actg((0.576+0.576)/(0.576+0.576))/sin(0.71)/sqrt(0.777)*ctg((0.826*0.826)*(x*0.826))*"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_192) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.859", ")", "+", "ln", "(", "0.625", ")", "+", "sqrt", "(", "(", "0.94", "^", "0.94", ")", "-", "(", "0.343", "^", "0.94", ")", ")", "^", "sqrt", "(", "0.525", ")", "+", "acos", "(", "0.549", ")", "^", "tan", "(", "(", "0.16", "*", "0.16", ")", "+", "(", "0.31", "*", "0.16", ")", ")", "*", "log", "(", "0.98", ")", "^", "atan", "(", "0.930", ")", "-", "ln", "(", "(", "0.338", "-", "0.338", ")", "^", "(", "x", "+", "0.338", ")", ")", "+", "log", "(", "0.717", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.859)+ln(0.625)+sqrt((0.94^0.94)-(0.343^0.94))^sqrt(0.525)+acos(0.549)^tan((0.16*0.16)+(0.31*0.16))*log(0.98)^atan(0.930)-ln((0.338-0.338)^(x+0.338))+log(0.717)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_193) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.29", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.29)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_194) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.822", ")", "/", "cos", "(", "0.615", ")", "+", "actg", "(", "(", "0.177", "+", "0.177", ")", "/", "(", "0.177", "-", "0.177", ")", ")", "*", "asin", "(", "0.242", ")", "/", "actg", "(", "0.643", ")", "-", "log", "(", "(", "0.208", "+", "0.208", ")", "+", "(", "0.178", "+", "0.208", ")", ")", "+", "ln", "(", "0.772", ")", "+", "atan", "(", "0.392", ")", "+", "atan", "(", "(", "0.879", "*", "0.879", ")", "^", "(", "x", "*", "0.879", ")", ")", "+", "log", "(", "0.326", ")", "*", "0.956"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.822)/cos(0.615)+actg((0.177+0.177)/(0.177-0.177))*asin(0.242)/actg(0.643)-log((0.208+0.208)+(0.178+0.208))+ln(0.772)+atan(0.392)+atan((0.879*0.879)^(x*0.879))+log(0.326)*0.956"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_195) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.129", ")", "*", "acos", "(", "0.798", ")", "+", "cos", "(", "(", "0.437", "/", "0.437", ")", "^", "(", "x", "/", "0.437", ")", ")", "+", "sqrt", "(", "0.961", ")", "-", "atan", "(", "0.263", ")", "^", "asin", "(", "(", "0.442", "*", "0.442", ")", "/", "(", "0.442", "+", "0.442", ")", ")", "/", "actg", "(", "0.282", ")", "-", "sqrt", "(", "0.42", ")", "-", "log", "(", "(", "0.164", "-", "0.164", ")", "+", "(", "0.164", "-", "0.164", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.129)*acos(0.798)+cos((0.437/0.437)^(x/0.437))+sqrt(0.961)-atan(0.263)^asin((0.442*0.442)/(0.442+0.442))/actg(0.282)-sqrt(0.42)-log((0.164-0.164)+(0.164-0.164))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_196) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.551", ")", "*", "ln", "(", "0.810", ")", "*", "atan", "(", "(", "0.725", "-", "0.725", ")", "+", "(", "0.725", "-", "0.725", ")", ")", "+", "log", "(", "0.298", ")", "*", "actg", "(", "0.462", ")", "/", "ln", "(", "(", "0.871", "^", "0.871", ")", "/", "(", "x", "^", "0.871", ")", ")", "+", "tan", "(", "0.237", ")", "-", "ctg", "(", "0.601", ")", "+", "actg", "(", "(", "0.912", "*", "0.912", ")", "-", "(", "0.912", "^", "0.912", ")", ")", "/", "cos", "(", "0.128", ")", "+", "tan", "(", "0.242", ")", "+", "ctg", "(", "(", "0.761", "-", "0.761", ")", "^", "(", "0.761", "/", "0.761", ")", ")", "-", "cos", "(", "0.482", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.551)*ln(0.810)*atan((0.725-0.725)+(0.725-0.725))+log(0.298)*actg(0.462)/ln((0.871^0.871)/(x^0.871))+tan(0.237)-ctg(0.601)+actg((0.912*0.912)-(0.912^0.912))/cos(0.128)+tan(0.242)+ctg((0.761-0.761)^(0.761/0.761))-cos(0.482)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_197) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.390", ")", "/", "tan", "(", "0.865", ")", "/", "ctg", "(", "(", "0.232", "*", "0.232", ")", "*", "(", "x", "*", "0.232", ")", ")", "-", "acos", "(", "0.676", ")", "*", "log", "(", "0.300", ")", "/", "sin", "(", "(", "0.51", "+", "0.51", ")", "^", "(", "x", "/", "0.51", ")", ")", "^", "acos", "(", "0.827", ")", "+", "asin", "(", "0.872", ")", "/", "acos", "(", "(", "0.89", "-", "0.89", ")", "^", "(", "0.89", "^", "0.89", ")", ")", "+", "asin", "(", "0.894", ")", "-", "0.573"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.390)/tan(0.865)/ctg((0.232*0.232)*(x*0.232))-acos(0.676)*log(0.300)/sin((0.51+0.51)^(x/0.51))^acos(0.827)+asin(0.872)/acos((0.89-0.89)^(0.89^0.89))+asin(0.894)-0.573"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_198) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.824", ")", "-", "atan", "(", "0.927", ")", "^", "log", "(", "(", "0.199", "/", "0.199", ")", "*", "(", "0.497", "/", "0.199", ")", ")", "/", "atan", "(", "0.611", ")", "*", "log", "(", "0.781", ")", "-", "cos", "(", "(", "0.434", "^", "0.434", ")", "+", "(", "0.434", "/", "0.434", ")", ")", "^", "tan", "(", "0.752", ")", "-", "ln", "(", "0.7", ")", "/", "sin", "(", "(", "0.425", "^", "0.425", ")", "+", "(", "0.425", "/", "0.425", ")", ")", "+", "sin", "(", "0.573", ")", "^", "actg", "(", "0.579", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.824)-atan(0.927)^log((0.199/0.199)*(0.497/0.199))/atan(0.611)*log(0.781)-cos((0.434^0.434)+(0.434/0.434))^tan(0.752)-ln(0.7)/sin((0.425^0.425)+(0.425/0.425))+sin(0.573)^actg(0.579)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_199) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.584", ")", "-", "ctg", "(", "0.761", ")", "*", "actg", "(", "(", "0.671", "*", "0.671", ")", "*", "(", "0.946", "-", "0.671", ")", ")", "*", "atan", "(", "0.227", ")", "/", "ctg", "(", "0.680", ")", "+", "actg", "(", "(", "0.774", "-", "0.774", ")", "-", "(", "0.959", "+", "0.774", ")", ")", "*", "log", "(", "0.633", ")", "^", "asin", "(", "0.929", ")", "^", "sqrt", "(", "(", "0.981", "/", "0.981", ")", "+", "(", "0.981", "*", "0.981", ")", ")", "+", "cos", "(", "0.34", ")", "-", "0.827"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.584)-ctg(0.761)*actg((0.671*0.671)*(0.946-0.671))*atan(0.227)/ctg(0.680)+actg((0.774-0.774)-(0.959+0.774))*log(0.633)^asin(0.929)^sqrt((0.981/0.981)+(0.981*0.981))+cos(0.34)-0.827"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_200) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.912", ")", "+", "tan", "(", "0.885", ")", "^", "log", "(", "(", "0.146", "-", "0.146", ")", "-", "(", "0.121", "/", "0.146", ")", ")", "-", "atan", "(", "0.256", ")", "*", "ctg", "(", "0.686", ")", "-", "ln", "(", "(", "0.604", "*", "0.604", ")", "/", "(", "0.604", "*", "0.604", ")", ")", "+", "ln", "(", "0.633", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.912)+tan(0.885)^log((0.146-0.146)-(0.121/0.146))-atan(0.256)*ctg(0.686)-ln((0.604*0.604)/(0.604*0.604))+ln(0.633)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_201) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.138", ")", "-", "sin", "(", "0.133", ")", "/", "cos", "(", "(", "0.585", "-", "0.585", ")", "*", "(", "0.585", "/", "0.585", ")", ")", "^", "ln", "(", "0.101", ")", "+", "actg", "(", "0.746", ")", "-", "sqrt", "(", "(", "0.748", "/", "0.748", ")", "^", "(", "x", "^", "0.748", ")", ")", "*", "actg", "(", "0.288", ")", "/", "asin", "(", "0.551", ")", "+", "sqrt", "(", "(", "0.181", "/", "0.181", ")", "-", "(", "0.181", "+", "0.181", ")", ")", "*", "sqrt", "(", "0.52", ")", "+", "actg", "(", "0.201", ")", "*", "ln", "(", "(", "0.882", "^", "0.882", ")", "*", "(", "0.882", "*", "0.882", ")", ")", "*", "ln", "(", "0.529", ")", "^", "0.426"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.138)-sin(0.133)/cos((0.585-0.585)*(0.585/0.585))^ln(0.101)+actg(0.746)-sqrt((0.748/0.748)^(x^0.748))*actg(0.288)/asin(0.551)+sqrt((0.181/0.181)-(0.181+0.181))*sqrt(0.52)+actg(0.201)*ln((0.882^0.882)*(0.882*0.882))*ln(0.529)^0.426"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_202) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.413", ")", "/", "sin", "(", "0.168", ")", "+", "asin", "(", "(", "0.284", "-", "0.284", ")", "+", "(", "x", "^", "0.284", ")", ")", "-", "sqrt", "(", "0.649", ")", "*", "ctg", "(", "0.80", ")", "/", "cos", "(", "(", "0.746", "^", "0.746", ")", "/", "(", "0.746", "*", "0.746", ")", ")", "^", "atan", "(", "0.559", ")", "-", "ctg", "(", "0.825", ")", "^", "log", "(", "(", "0.836", "*", "0.836", ")", "/", "(", "x", "^", "0.836", ")", ")", "*", "actg", "(", "0.108", ")", "/", "tan", "(", "0.976", ")", "*", "asin", "(", "(", "0.842", "/", "0.842", ")", "/", "(", "0.842", "^", "0.842", ")", ")", "/", "sqrt", "(", "0.866", ")", "/", "0.29"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.413)/sin(0.168)+asin((0.284-0.284)+(x^0.284))-sqrt(0.649)*ctg(0.80)/cos((0.746^0.746)/(0.746*0.746))^atan(0.559)-ctg(0.825)^log((0.836*0.836)/(x^0.836))*actg(0.108)/tan(0.976)*asin((0.842/0.842)/(0.842^0.842))/sqrt(0.866)/0.29"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_203) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.51", ")", "/", "acos", "(", "0.373", ")", "+", "sin", "(", "(", "0.88", "+", "0.88", ")", "-", "(", "x", "+", "0.88", ")", ")", "+", "cos", "(", "0.726", ")", "*", "ctg", "(", "0.666", ")", "*", "atan", "(", "(", "0.941", "/", "0.941", ")", "+", "(", "0.941", "+", "0.941", ")", ")", "*", "ctg", "(", "0.518", ")", "-", "ln", "(", "0.502", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.51)/acos(0.373)+sin((0.88+0.88)-(x+0.88))+cos(0.726)*ctg(0.666)*atan((0.941/0.941)+(0.941+0.941))*ctg(0.518)-ln(0.502)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_204) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.293", ")", "^", "cos", "(", "0.411", ")", "-", "asin", "(", "(", "0.255", "/", "0.255", ")", "-", "(", "0.255", "*", "0.255", ")", ")", "*", "cos", "(", "0.600", ")", "+", "sqrt", "(", "0.693", ")", "+", "log", "(", "(", "0.665", "/", "0.665", ")", "*", "(", "0.117", "/", "0.665", ")", ")", "-", "actg", "(", "0.82", ")", "*", "cos", "(", "0.527", ")", "-", "ln", "(", "(", "0.835", "+", "0.835", ")", "/", "(", "x", "+", "0.835", ")", ")", "+", "asin", "(", "0.6", ")", "+", "asin", "(", "0.140", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.293)^cos(0.411)-asin((0.255/0.255)-(0.255*0.255))*cos(0.600)+sqrt(0.693)+log((0.665/0.665)*(0.117/0.665))-actg(0.82)*cos(0.527)-ln((0.835+0.835)/(x+0.835))+asin(0.6)+asin(0.140)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_205) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.637", ")", "/", "actg", "(", "0.35", ")", "+", "ln", "(", "(", "0.680", "/", "0.680", ")", "+", "(", "x", "/", "0.680", ")", ")", "*", "log", "(", "0.172", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.637)/actg(0.35)+ln((0.680/0.680)+(x/0.680))*log(0.172)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_206) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.450", ")", "+", "tan", "(", "0.275", ")", "+", "asin", "(", "(", "0.955", "*", "0.955", ")", "/", "(", "0.955", "*", "0.955", ")", ")", "/", "cos", "(", "0.940", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.450)+tan(0.275)+asin((0.955*0.955)/(0.955*0.955))/cos(0.940)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_207) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.708", ")", "/", "ctg", "(", "0.603", ")", "+", "ctg", "(", "(", "0.367", "/", "0.367", ")", "^", "(", "0.79", "+", "0.367", ")", ")", "/", "atan", "(", "0.804", ")", "^", "atan", "(", "0.110", ")", "^", "actg", "(", "(", "0.228", "^", "0.228", ")", "-", "(", "0.696", "*", "0.228", ")", ")", "/", "actg", "(", "0.0", ")", "-", "asin", "(", "0.739", ")", "/", "sqrt", "(", "(", "0.903", "-", "0.903", ")", "^", "(", "0.903", "/", "0.903", ")", ")", "/", "log", "(", "0.434", ")", "/", "0.754"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.708)/ctg(0.603)+ctg((0.367/0.367)^(0.79+0.367))/atan(0.804)^atan(0.110)^actg((0.228^0.228)-(0.696*0.228))/actg(0.0)-asin(0.739)/sqrt((0.903-0.903)^(0.903/0.903))/log(0.434)/0.754"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_208) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.957", ")", "*", "ln", "(", "0.617", ")", "-", "sqrt", "(", "(", "0.422", "+", "0.422", ")", "-", "(", "0.422", "^", "0.422", ")", ")", "*", "sin", "(", "0.865", ")", "+", "asin", "(", "0.1", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.957)*ln(0.617)-sqrt((0.422+0.422)-(0.422^0.422))*sin(0.865)+asin(0.1)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_209) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.982", ")", "-", "actg", "(", "0.278", ")", "*", "atan", "(", "(", "0.266", "*", "0.266", ")", "-", "(", "x", "/", "0.266", ")", ")", "^", "cos", "(", "0.68", ")", "+", "ctg", "(", "0.802", ")", "-", "asin", "(", "(", "0.588", "*", "0.588", ")", "-", "(", "x", "^", "0.588", ")", ")", "*", "sin", "(", "0.881", ")", "-", "0.643"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.982)-actg(0.278)*atan((0.266*0.266)-(x/0.266))^cos(0.68)+ctg(0.802)-asin((0.588*0.588)-(x^0.588))*sin(0.881)-0.643"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_210) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.951", ")", "+", "tan", "(", "0.730", ")", "*", "ctg", "(", "(", "0.319", "-", "0.319", ")", "*", "(", "0.749", "-", "0.319", ")", ")", "/", "cos", "(", "0.513", ")", "*", "acos", "(", "0.972", ")", "+", "acos", "(", "(", "0.673", "*", "0.673", ")", "^", "(", "0.673", "+", "0.673", ")", ")", "^", "cos", "(", "0.183", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.951)+tan(0.730)*ctg((0.319-0.319)*(0.749-0.319))/cos(0.513)*acos(0.972)+acos((0.673*0.673)^(0.673+0.673))^cos(0.183)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_211) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.441", ")", "*", "log", "(", "0.707", ")", "-", "sqrt", "(", "(", "0.974", "/", "0.974", ")", "/", "(", "0.774", "^", "0.974", ")", ")", "-", "ctg", "(", "0.101", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.441)*log(0.707)-sqrt((0.974/0.974)/(0.774^0.974))-ctg(0.101)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_212) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.662", ")", "+", "sqrt", "(", "0.998", ")", "-", "sqrt", "(", "(", "0.798", "-", "0.798", ")", "-", "(", "0.421", "+", "0.798", ")", ")", "/", "ln", "(", "0.126", ")", "+", "ln", "(", "0.257", ")", "^", "tan", "(", "(", "0.131", "-", "0.131", ")", "*", "(", "0.131", "+", "0.131", ")", ")", "-", "acos", "(", "0.631", ")", "^", "log", "(", "0.276", ")", "/", "cos", "(", "(", "0.316", "/", "0.316", ")", "*", "(", "0.316", "/", "0.316", ")", ")", "^", "ln", "(", "0.173", ")", "^", "0.943"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.662)+sqrt(0.998)-sqrt((0.798-0.798)-(0.421+0.798))/ln(0.126)+ln(0.257)^tan((0.131-0.131)*(0.131+0.131))-acos(0.631)^log(0.276)/cos((0.316/0.316)*(0.316/0.316))^ln(0.173)^0.943"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_213) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.623", ")", "^", "sqrt", "(", "0.650", ")", "/", "acos", "(", "(", "0.449", "*", "0.449", ")", "*", "(", "0.993", "+", "0.449", ")", ")", "*", "acos", "(", "0.273", ")", "+", "cos", "(", "0.572", ")", "*", "atan", "(", "(", "0.197", "/", "0.197", ")", "-", "(", "0.197", "-", "0.197", ")", ")", "-", "log", "(", "0.28", ")", "*", "actg", "(", "0.374", ")", "/", "asin", "(", "(", "0.858", "*", "0.858", ")", "/", "(", "0.277", "^", "0.858", ")", ")", "/", "cos", "(", "0.827", ")", "-", "ln", "(", "0.306", ")", "*", "tan", "(", "(", "0.338", "^", "0.338", ")", "+", "(", "0.338", "+", "0.338", ")", ")", "/", "acos", "(", "0.829", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.623)^sqrt(0.650)/acos((0.449*0.449)*(0.993+0.449))*acos(0.273)+cos(0.572)*atan((0.197/0.197)-(0.197-0.197))-log(0.28)*actg(0.374)/asin((0.858*0.858)/(0.277^0.858))/cos(0.827)-ln(0.306)*tan((0.338^0.338)+(0.338+0.338))/acos(0.829)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_214) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.768", ")", "+", "ctg", "(", "0.495", ")", "^", "log", "(", "(", "0.199", "^", "0.199", ")", "*", "(", "0.199", "^", "0.199", ")", ")", "+", "ctg", "(", "0.180", ")", "-", "sqrt", "(", "0.686", ")", "^", "tan", "(", "(", "0.352", "/", "0.352", ")", "-", "(", "0.429", "-", "0.352", ")", ")", "^", "tan", "(", "0.111", ")", "-", "asin", "(", "0.352", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.768)+ctg(0.495)^log((0.199^0.199)*(0.199^0.199))+ctg(0.180)-sqrt(0.686)^tan((0.352/0.352)-(0.429-0.352))^tan(0.111)-asin(0.352)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_215) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.881", ")", "-", "tan", "(", "0.433", ")", "/", "ctg", "(", "(", "0.271", "/", "0.271", ")", "/", "(", "0.329", "^", "0.271", ")", ")", "*", "acos", "(", "0.916", ")", "*", "ln", "(", "0.551", ")", "^", "ln", "(", "(", "0.93", "+", "0.93", ")", "^", "(", "0.225", "^", "0.93", ")", ")", "-", "sqrt", "(", "0.458", ")", "-", "asin", "(", "0.714", ")", "*", "asin", "(", "(", "0.545", "-", "0.545", ")", "/", "(", "x", "/", "0.545", ")", ")", "*", "acos", "(", "0.618", ")", "+", "0.143"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.881)-tan(0.433)/ctg((0.271/0.271)/(0.329^0.271))*acos(0.916)*ln(0.551)^ln((0.93+0.93)^(0.225^0.93))-sqrt(0.458)-asin(0.714)*asin((0.545-0.545)/(x/0.545))*acos(0.618)+0.143"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_216) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.607", ")", "+", "ln", "(", "0.825", ")", "-", "sin", "(", "(", "0.731", "+", "0.731", ")", "^", "(", "0.731", "-", "0.731", ")", ")", "/", "sin", "(", "0.247", ")", "*", "sqrt", "(", "0.546", ")", "+", "actg", "(", "(", "0.653", "^", "0.653", ")", "+", "(", "0.817", "^", "0.653", ")", ")", "*", "asin", "(", "0.907", ")", "^", "sqrt", "(", "0.759", ")", "-", "cos", "(", "(", "0.211", "^", "0.211", ")", "^", "(", "x", "/", "0.211", ")", ")", "*", "ln", "(", "0.759", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.607)+ln(0.825)-sin((0.731+0.731)^(0.731-0.731))/sin(0.247)*sqrt(0.546)+actg((0.653^0.653)+(0.817^0.653))*asin(0.907)^sqrt(0.759)-cos((0.211^0.211)^(x/0.211))*ln(0.759)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_217) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.888", ")", "^", "acos", "(", "0.760", ")", "^", "asin", "(", "(", "0.530", "*", "0.530", ")", "/", "(", "x", "*", "0.530", ")", ")", "-", "sqrt", "(", "0.332", ")", "*", "sin", "(", "0.614", ")", "-", "atan", "(", "(", "0.408", "-", "0.408", ")", "+", "(", "0.408", "^", "0.408", ")", ")", "-", "actg", "(", "0.674", ")", "*", "tan", "(", "0.638", ")", "^", "actg", "(", "(", "0.289", "+", "0.289", ")", "^", "(", "0.486", "*", "0.289", ")", ")", "-", "actg", "(", "0.688", ")", "-", "acos", "(", "0.735", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.888)^acos(0.760)^asin((0.530*0.530)/(x*0.530))-sqrt(0.332)*sin(0.614)-atan((0.408-0.408)+(0.408^0.408))-actg(0.674)*tan(0.638)^actg((0.289+0.289)^(0.486*0.289))-actg(0.688)-acos(0.735)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_218) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.458", ")", "*", "tan", "(", "0.711", ")", "^", "tan", "(", "(", "0.398", "-", "0.398", ")", "*", "(", "0.532", "+", "0.398", ")", ")", "/", "atan", "(", "0.195", ")", "+", "atan", "(", "0.741", ")", "/", "tan", "(", "(", "0.340", "*", "0.340", ")", "-", "(", "0.248", "/", "0.340", ")", ")", "/", "cos", "(", "0.136", ")", "^", "ctg", "(", "0.668", ")", "/", "cos", "(", "(", "0.522", "/", "0.522", ")", "^", "(", "0.522", "^", "0.522", ")", ")", "/", "sin", "(", "0.331", ")", "/", "ctg", "(", "0.332", ")", "/", "log", "(", "(", "0.594", "-", "0.594", ")", "+", "(", "x", "/", "0.594", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.458)*tan(0.711)^tan((0.398-0.398)*(0.532+0.398))/atan(0.195)+atan(0.741)/tan((0.340*0.340)-(0.248/0.340))/cos(0.136)^ctg(0.668)/cos((0.522/0.522)^(0.522^0.522))/sin(0.331)/ctg(0.332)/log((0.594-0.594)+(x/0.594))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_219) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.900", ")", "+", "ln", "(", "0.568", ")", "^", "cos", "(", "(", "0.633", "*", "0.633", ")", "*", "(", "0.633", "+", "0.633", ")", ")", "+", "cos", "(", "0.227", ")", "/", "atan", "(", "0.161", ")", "*", "sqrt", "(", "(", "0.892", "^", "0.892", ")", "-", "(", "0.753", "-", "0.892", ")", ")", "-", "ctg", "(", "0.144", ")", "^", "0.366"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.900)+ln(0.568)^cos((0.633*0.633)*(0.633+0.633))+cos(0.227)/atan(0.161)*sqrt((0.892^0.892)-(0.753-0.892))-ctg(0.144)^0.366"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_220) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.447", ")", "*", "sqrt", "(", "0.293", ")", "+", "cos", "(", "(", "0.294", "*", "0.294", ")", "/", "(", "0.319", "*", "0.294", ")", ")", "^", "actg", "(", "0.849", ")", "-", "asin", "(", "0.312", ")", "+", "acos", "(", "(", "0.868", "-", "0.868", ")", "^", "(", "x", "/", "0.868", ")", ")", "/", "asin", "(", "0.291", ")", "^", "asin", "(", "0.852", ")", "*", "ln", "(", "(", "0.124", "+", "0.124", ")", "-", "(", "0.124", "-", "0.124", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.447)*sqrt(0.293)+cos((0.294*0.294)/(0.319*0.294))^actg(0.849)-asin(0.312)+acos((0.868-0.868)^(x/0.868))/asin(0.291)^asin(0.852)*ln((0.124+0.124)-(0.124-0.124))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_221) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.32", ")", "^", "cos", "(", "0.165", ")", "-", "asin", "(", "(", "0.108", "*", "0.108", ")", "*", "(", "0.153", "+", "0.108", ")", ")", "+", "ln", "(", "0.362", ")", "^", "ln", "(", "0.865", ")", "/", "sin", "(", "(", "0.288", "^", "0.288", ")", "-", "(", "0.288", "+", "0.288", ")", ")", "^", "ln", "(", "0.185", ")", "*", "ln", "(", "0.623", ")", "*", "asin", "(", "(", "0.972", "^", "0.972", ")", "^", "(", "0.947", "/", "0.972", ")", ")", "/", "ln", "(", "0.495", ")", "/", "0.738"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.32)^cos(0.165)-asin((0.108*0.108)*(0.153+0.108))+ln(0.362)^ln(0.865)/sin((0.288^0.288)-(0.288+0.288))^ln(0.185)*ln(0.623)*asin((0.972^0.972)^(0.947/0.972))/ln(0.495)/0.738"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_222) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.41", ")", "*", "ln", "(", "0.120", ")", "*", "actg", "(", "(", "0.324", "/", "0.324", ")", "^", "(", "x", "-", "0.324", ")", ")", "^", "log", "(", "0.289", ")", "^", "ln", "(", "0.340", ")", "/", "acos", "(", "(", "0.29", "^", "0.29", ")", "^", "(", "x", "-", "0.29", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.41)*ln(0.120)*actg((0.324/0.324)^(x-0.324))^log(0.289)^ln(0.340)/acos((0.29^0.29)^(x-0.29))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_223) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.14", ")", "*", "tan", "(", "0.902", ")", "+", "ln", "(", "(", "0.164", "-", "0.164", ")", "^", "(", "0.112", "*", "0.164", ")", ")", "*", "cos", "(", "0.302", ")", "^", "asin", "(", "0.492", ")", "^", "sin", "(", "(", "0.572", "-", "0.572", ")", "^", "(", "x", "^", "0.572", ")", ")", "+", "tan", "(", "0.40", ")", "^", "ln", "(", "0.212", ")", "/", "ctg", "(", "(", "0.784", "/", "0.784", ")", "*", "(", "x", "^", "0.784", ")", ")", "+", "asin", "(", "0.506", ")", "-", "0.548"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.14)*tan(0.902)+ln((0.164-0.164)^(0.112*0.164))*cos(0.302)^asin(0.492)^sin((0.572-0.572)^(x^0.572))+tan(0.40)^ln(0.212)/ctg((0.784/0.784)*(x^0.784))+asin(0.506)-0.548"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_224) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.699", ")", "^", "atan", "(", "0.416", ")", "+", "log", "(", "(", "0.543", "/", "0.543", ")", "/", "(", "x", "*", "0.543", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.699)^atan(0.416)+log((0.543/0.543)/(x*0.543))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_225) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.384", ")", "/", "ctg", "(", "0.287", ")", "/", "cos", "(", "(", "0.167", "/", "0.167", ")", "/", "(", "x", "-", "0.167", ")", ")", "^", "cos", "(", "0.533", ")", "/", "asin", "(", "0.631", ")", "/", "sin", "(", "(", "0.273", "/", "0.273", ")", "*", "(", "0.273", "^", "0.273", ")", ")", "/", "atan", "(", "0.481", ")", "*", "ln", "(", "0.370", ")", "*", "ln", "(", "(", "0.675", "/", "0.675", ")", "*", "(", "0.987", "/", "0.675", ")", ")", "/", "cos", "(", "0.240", ")", "^", "log", "(", "0.198", ")", "/", "sqrt", "(", "(", "0.449", "^", "0.449", ")", "+", "(", "x", "+", "0.449", ")", ")", "/", "cos", "(", "0.247", ")", "+", "sin", "(", "0.793", ")", "^", "sqrt", "(", "(", "0.164", "/", "0.164", ")", "/", "(", "0.164", "+", "0.164", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.384)/ctg(0.287)/cos((0.167/0.167)/(x-0.167))^cos(0.533)/asin(0.631)/sin((0.273/0.273)*(0.273^0.273))/atan(0.481)*ln(0.370)*ln((0.675/0.675)*(0.987/0.675))/cos(0.240)^log(0.198)/sqrt((0.449^0.449)+(x+0.449))/cos(0.247)+sin(0.793)^sqrt((0.164/0.164)/(0.164+0.164))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_226) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.451", ")", "*", "acos", "(", "0.551", ")", "-", "sin", "(", "(", "0.769", "-", "0.769", ")", "^", "(", "x", "^", "0.769", ")", ")", "+", "asin", "(", "0.983", ")", "-", "atan", "(", "0.778", ")", "-", "atan", "(", "(", "0.116", "/", "0.116", ")", "+", "(", "x", "^", "0.116", ")", ")", "*", "sqrt", "(", "0.711", ")", "-", "tan", "(", "0.537", ")", "*", "cos", "(", "(", "0.111", "+", "0.111", ")", "/", "(", "x", "+", "0.111", ")", ")", "*", "actg", "(", "0.757", ")", "^", "sin", "(", "0.384", ")", "+", "acos", "(", "(", "0.363", "*", "0.363", ")", "-", "(", "0.374", "*", "0.363", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.451)*acos(0.551)-sin((0.769-0.769)^(x^0.769))+asin(0.983)-atan(0.778)-atan((0.116/0.116)+(x^0.116))*sqrt(0.711)-tan(0.537)*cos((0.111+0.111)/(x+0.111))*actg(0.757)^sin(0.384)+acos((0.363*0.363)-(0.374*0.363))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_227) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.77", ")", "^", "actg", "(", "0.342", ")", "^", "sqrt", "(", "(", "0.179", "/", "0.179", ")", "/", "(", "0.179", "/", "0.179", ")", ")", "^", "ctg", "(", "0.831", ")", "^", "acos", "(", "0.201", ")", "-", "ctg", "(", "(", "0.200", "^", "0.200", ")", "/", "(", "0.200", "+", "0.200", ")", ")", "+", "ln", "(", "0.220", ")", "/", "0.985"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.77)^actg(0.342)^sqrt((0.179/0.179)/(0.179/0.179))^ctg(0.831)^acos(0.201)-ctg((0.200^0.200)/(0.200+0.200))+ln(0.220)/0.985"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_228) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.420", ")", "/", "atan", "(", "0.435", ")", "/", "tan", "(", "(", "0.504", "-", "0.504", ")", "*", "(", "0.789", "^", "0.504", ")", ")", "*", "tan", "(", "0.303", ")", "^", "sin", "(", "0.528", ")", "/", "asin", "(", "(", "0.632", "*", "0.632", ")", "+", "(", "0.632", "^", "0.632", ")", ")", "^", "sqrt", "(", "0.542", ")", "/", "sqrt", "(", "0.710", ")", "^", "ln", "(", "(", "0.688", "/", "0.688", ")", "*", "(", "x", "/", "0.688", ")", ")", "^", "atan", "(", "0.801", ")", "-", "acos", "(", "0.188", ")", "+", "ctg", "(", "(", "0.339", "-", "0.339", ")", "-", "(", "0.891", "+", "0.339", ")", ")", "/", "actg", "(", "0.167", ")", "+", "tan", "(", "0.840", ")", "/", "acos", "(", "(", "0.538", "*", "0.538", ")", "+", "(", "x", "-", "0.538", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.420)/atan(0.435)/tan((0.504-0.504)*(0.789^0.504))*tan(0.303)^sin(0.528)/asin((0.632*0.632)+(0.632^0.632))^sqrt(0.542)/sqrt(0.710)^ln((0.688/0.688)*(x/0.688))^atan(0.801)-acos(0.188)+ctg((0.339-0.339)-(0.891+0.339))/actg(0.167)+tan(0.840)/acos((0.538*0.538)+(x-0.538))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_229) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "215", "%", "430"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+215%430"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_230) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.800", ")", "^", "atan", "(", "0.801", ")", "-", "log", "(", "(", "0.900", "*", "0.900", ")", "-", "(", "x", "*", "0.900", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.800)^atan(0.801)-log((0.900*0.900)-(x*0.900))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_231) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.352", ")", "/", "actg", "(", "0.377", ")", "/", "sin", "(", "(", "0.832", "+", "0.832", ")", "^", "(", "0.598", "/", "0.832", ")", ")", "*", "sin", "(", "0.783", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.352)/actg(0.377)/sin((0.832+0.832)^(0.598/0.832))*sin(0.783)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_232) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.832", ")", "+", "sqrt", "(", "0.863", ")", "/", "sqrt", "(", "(", "0.200", "-", "0.200", ")", "+", "(", "x", "*", "0.200", ")", ")", "^", "acos", "(", "0.435", ")", "^", "cos", "(", "0.982", ")", "^", "asin", "(", "(", "0.741", "+", "0.741", ")", "^", "(", "x", "^", "0.741", ")", ")", "*", "tan", "(", "0.303", ")", "+", "acos", "(", "0.549", ")", "/", "sqrt", "(", "(", "0.7", "/", "0.7", ")", "*", "(", "x", "/", "0.7", ")", ")", "+", "sqrt", "(", "0.607", ")", "*", "acos", "(", "0.169", ")", "-", "log", "(", "(", "0.480", "-", "0.480", ")", "*", "(", "0.480", "+", "0.480", ")", ")", "-", "asin", "(", "0.631", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.832)+sqrt(0.863)/sqrt((0.200-0.200)+(x*0.200))^acos(0.435)^cos(0.982)^asin((0.741+0.741)^(x^0.741))*tan(0.303)+acos(0.549)/sqrt((0.7/0.7)*(x/0.7))+sqrt(0.607)*acos(0.169)-log((0.480-0.480)*(0.480+0.480))-asin(0.631)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_233) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.514", ")", "^", "actg", "(", "0.355", ")", "+", "sqrt", "(", "(", "0.826", "*", "0.826", ")", "+", "(", "0.826", "/", "0.826", ")", ")", "/", "ln", "(", "0.363", ")", "-", "ln", "(", "0.355", ")", "+", "atan", "(", "(", "0.13", "/", "0.13", ")", "*", "(", "0.139", "*", "0.13", ")", ")", "*", "ln", "(", "0.179", ")", "-", "asin", "(", "0.423", ")", "+", "asin", "(", "(", "0.998", "-", "0.998", ")", "^", "(", "0.7", "-", "0.998", ")", ")", "*", "log", "(", "0.833", ")", "-", "asin", "(", "0.921", ")", "^", "ln", "(", "(", "0.219", "^", "0.219", ")", "+", "(", "0.364", "+", "0.219", ")", ")", "*", "acos", "(", "0.979", ")", "+", "asin", "(", "0.802", ")", "-", "ctg", "(", "(", "0.675", "*", "0.675", ")", "^", "(", "0.675", "^", "0.675", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.514)^actg(0.355)+sqrt((0.826*0.826)+(0.826/0.826))/ln(0.363)-ln(0.355)+atan((0.13/0.13)*(0.139*0.13))*ln(0.179)-asin(0.423)+asin((0.998-0.998)^(0.7-0.998))*log(0.833)-asin(0.921)^ln((0.219^0.219)+(0.364+0.219))*acos(0.979)+asin(0.802)-ctg((0.675*0.675)^(0.675^0.675))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_234) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.152", ")", "+", "log", "(", "0.265", ")", "^", "log", "(", "(", "0.177", "/", "0.177", ")", "-", "(", "0.567", "*", "0.177", ")", ")", "-", "acos", "(", "0.267", ")", "*", "0.63"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.152)+log(0.265)^log((0.177/0.177)-(0.567*0.177))-acos(0.267)*0.63"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_235) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.445", ")", "*", "asin", "(", "0.966", ")", "^", "log", "(", "(", "0.788", "^", "0.788", ")", "+", "(", "0.224", "+", "0.788", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.445)*asin(0.966)^log((0.788^0.788)+(0.224+0.788))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_236) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.868", ")", "+", "acos", "(", "0.606", ")", "+", "atan", "(", "(", "0.547", "^", "0.547", ")", "*", "(", "0.554", "*", "0.547", ")", ")", "^", "atan", "(", "0.124", ")", "^", "ln", "(", "0.296", ")", "^", "cos", "(", "(", "0.74", "^", "0.74", ")", "-", "(", "x", "*", "0.74", ")", ")", "/", "cos", "(", "0.717", ")", "/", "log", "(", "0.934", ")", "/", "log", "(", "(", "0.545", "/", "0.545", ")", "-", "(", "0.545", "/", "0.545", ")", ")", "*", "sin", "(", "0.420", ")", "-", "ln", "(", "0.338", ")", "/", "log", "(", "(", "0.787", "^", "0.787", ")", "^", "(", "x", "-", "0.787", ")", ")", "-", "asin", "(", "0.457", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.868)+acos(0.606)+atan((0.547^0.547)*(0.554*0.547))^atan(0.124)^ln(0.296)^cos((0.74^0.74)-(x*0.74))/cos(0.717)/log(0.934)/log((0.545/0.545)-(0.545/0.545))*sin(0.420)-ln(0.338)/log((0.787^0.787)^(x-0.787))-asin(0.457)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_237) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.498", ")", "^", "0.205"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.498)^0.205"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_238) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.44", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.44)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_239) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.236", ")", "-", "sqrt", "(", "0.331", ")", "-", "log", "(", "(", "0.107", "+", "0.107", ")", "^", "(", "0.107", "-", "0.107", ")", ")", "+", "asin", "(", "0.381", ")", "-", "sqrt", "(", "0.113", ")", "+", "cos", "(", "(", "0.393", "/", "0.393", ")", "/", "(", "0.393", "*", "0.393", ")", ")", "/", "atan", "(", "0.761", ")", "^", "ln", "(", "0.842", ")", "-", "ln", "(", "(", "0.614", "^", "0.614", ")", "/", "(", "0.614", "-", "0.614", ")", ")", "*", "log", "(", "0.943", ")", "+", "log", "(", "0.130", ")", "*", "ctg", "(", "(", "0.28", "^", "0.28", ")", "-", "(", "0.641", "-", "0.28", ")", ")", "/", "sin", "(", "0.366", ")", "+", "ctg", "(", "0.768", ")", "/", "ln", "(", "(", "0.690", "^", "0.690", ")", "+", "(", "0.690", "^", "0.690", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.236)-sqrt(0.331)-log((0.107+0.107)^(0.107-0.107))+asin(0.381)-sqrt(0.113)+cos((0.393/0.393)/(0.393*0.393))/atan(0.761)^ln(0.842)-ln((0.614^0.614)/(0.614-0.614))*log(0.943)+log(0.130)*ctg((0.28^0.28)-(0.641-0.28))/sin(0.366)+ctg(0.768)/ln((0.690^0.690)+(0.690^0.690))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_240) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.47", ")", "-", "sqrt", "(", "0.173", ")", "+", "actg", "(", "(", "0.150", "^", "0.150", ")", "-", "(", "x", "^", "0.150", ")", ")", "/", "atan", "(", "0.973", ")", "-", "asin", "(", "0.37", ")", "*", "sqrt", "(", "(", "0.554", "^", "0.554", ")", "-", "(", "0.554", "-", "0.554", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.47)-sqrt(0.173)+actg((0.150^0.150)-(x^0.150))/atan(0.973)-asin(0.37)*sqrt((0.554^0.554)-(0.554-0.554))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_241) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "462", "%", "310"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+462%310"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_242) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "973", "%", "452"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+973%452"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_243) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.9", ")", "+", "0.230"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.9)+0.230"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_244) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.848", ")", "^", "sqrt", "(", "0.86", ")", "*", "asin", "(", "(", "0.186", "^", "0.186", ")", "^", "(", "x", "+", "0.186", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.848)^sqrt(0.86)*asin((0.186^0.186)^(x+0.186))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_245) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.79", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.79)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_246) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.160", ")", "+", "sqrt", "(", "0.998", ")", "*", "asin", "(", "(", "0.80", "*", "0.80", ")", "*", "(", "x", "-", "0.80", ")", ")", "/", "asin", "(", "0.678", ")", "-", "sin", "(", "0.483", ")", "/", "tan", "(", "(", "0.934", "^", "0.934", ")", "-", "(", "0.763", "+", "0.934", ")", ")", "*", "acos", "(", "0.205", ")", "/", "cos", "(", "0.468", ")", "*", "ln", "(", "(", "0.456", "-", "0.456", ")", "*", "(", "x", "-", "0.456", ")", ")", "+", "atan", "(", "0.63", ")", "^", "tan", "(", "0.714", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.160)+sqrt(0.998)*asin((0.80*0.80)*(x-0.80))/asin(0.678)-sin(0.483)/tan((0.934^0.934)-(0.763+0.934))*acos(0.205)/cos(0.468)*ln((0.456-0.456)*(x-0.456))+atan(0.63)^tan(0.714)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_247) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.321", ")", "^", "sin", "(", "0.20", ")", "^", "cos", "(", "(", "0.838", "*", "0.838", ")", "/", "(", "0.124", "^", "0.838", ")", ")", "*", "actg", "(", "0.713", ")", "+", "sqrt", "(", "0.725", ")", "^", "cos", "(", "(", "0.477", "/", "0.477", ")", "-", "(", "0.13", "-", "0.477", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.321)^sin(0.20)^cos((0.838*0.838)/(0.124^0.838))*actg(0.713)+sqrt(0.725)^cos((0.477/0.477)-(0.13-0.477))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_248) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.972", ")", "+", "cos", "(", "0.446", ")", "+", "asin", "(", "(", "0.852", "/", "0.852", ")", "^", "(", "x", "-", "0.852", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.972)+cos(0.446)+asin((0.852/0.852)^(x-0.852))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_249) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.125", ")", "*", "sqrt", "(", "0.217", ")", "*", "asin", "(", "(", "0.730", "+", "0.730", ")", "*", "(", "0.730", "-", "0.730", ")", ")", "/", "tan", "(", "0.198", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.125)*sqrt(0.217)*asin((0.730+0.730)*(0.730-0.730))/tan(0.198)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_250) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.336", ")", "-", "acos", "(", "0.170", ")", "/", "acos", "(", "(", "0.731", "^", "0.731", ")", "/", "(", "0.731", "+", "0.731", ")", ")", "/", "acos", "(", "0.567", ")", "+", "sin", "(", "0.174", ")", "^", "asin", "(", "(", "0.643", "*", "0.643", ")", "/", "(", "0.643", "-", "0.643", ")", ")", "*", "acos", "(", "0.958", ")", "*", "log", "(", "0.529", ")", "-", "sin", "(", "(", "0.385", "/", "0.385", ")", "*", "(", "0.385", "/", "0.385", ")", ")", "-", "log", "(", "0.466", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.336)-acos(0.170)/acos((0.731^0.731)/(0.731+0.731))/acos(0.567)+sin(0.174)^asin((0.643*0.643)/(0.643-0.643))*acos(0.958)*log(0.529)-sin((0.385/0.385)*(0.385/0.385))-log(0.466)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_251) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.439", ")", "-", "sin", "(", "0.257", ")", "-", "log", "(", "(", "0.697", "+", "0.697", ")", "+", "(", "0.935", "/", "0.697", ")", ")", "-", "log", "(", "0.918", ")", "/", "acos", "(", "0.758", ")", "^", "asin", "(", "(", "0.66", "+", "0.66", ")", "^", "(", "0.66", "-", "0.66", ")", ")", "^", "atan", "(", "0.404", ")", "/", "asin", "(", "0.159", ")", "+", "asin", "(", "(", "0.335", "*", "0.335", ")", "-", "(", "x", "^", "0.335", ")", ")", "/", "tan", "(", "0.12", ")", "+", "asin", "(", "0.250", ")", "*", "tan", "(", "(", "0.641", "-", "0.641", ")", "/", "(", "0.164", "/", "0.641", ")", ")", "+", "ln", "(", "0.6", ")", "/", "0.12"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.439)-sin(0.257)-log((0.697+0.697)+(0.935/0.697))-log(0.918)/acos(0.758)^asin((0.66+0.66)^(0.66-0.66))^atan(0.404)/asin(0.159)+asin((0.335*0.335)-(x^0.335))/tan(0.12)+asin(0.250)*tan((0.641-0.641)/(0.164/0.641))+ln(0.6)/0.12"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_252) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.157", ")", "+", "0.421"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.157)+0.421"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_253) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.939", ")", "+", "sin", "(", "0.655", ")", "-", "cos", "(", "(", "0.897", "*", "0.897", ")", "*", "(", "0.710", "-", "0.897", ")", ")", "^", "ctg", "(", "0.379", ")", "^", "sqrt", "(", "0.115", ")", "+", "tan", "(", "(", "0.323", "/", "0.323", ")", "*", "(", "0.323", "+", "0.323", ")", ")", "-", "ctg", "(", "0.299", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.939)+sin(0.655)-cos((0.897*0.897)*(0.710-0.897))^ctg(0.379)^sqrt(0.115)+tan((0.323/0.323)*(0.323+0.323))-ctg(0.299)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_254) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.731", ")", "^", "0.466"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.731)^0.466"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_255) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.361", ")", "*", "cos", "(", "0.566", ")", "*", "log", "(", "(", "0.977", "^", "0.977", ")", "^", "(", "0.84", "^", "0.977", ")", ")", "-", "cos", "(", "0.803", ")", "+", "actg", "(", "0.322", ")", "^", "actg", "(", "(", "0.328", "+", "0.328", ")", "+", "(", "x", "/", "0.328", ")", ")", "*", "cos", "(", "0.722", ")", "-", "acos", "(", "0.28", ")", "*", "log", "(", "(", "0.756", "^", "0.756", ")", "/", "(", "0.756", "*", "0.756", ")", ")", "-", "sqrt", "(", "0.0", ")", "*", "ln", "(", "0.899", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.361)*cos(0.566)*log((0.977^0.977)^(0.84^0.977))-cos(0.803)+actg(0.322)^actg((0.328+0.328)+(x/0.328))*cos(0.722)-acos(0.28)*log((0.756^0.756)/(0.756*0.756))-sqrt(0.0)*ln(0.899)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_256) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.118", ")", "-", "ln", "(", "0.331", ")", "/", "acos", "(", "(", "0.736", "*", "0.736", ")", "/", "(", "0.736", "^", "0.736", ")", ")", "*", "sin", "(", "0.409", ")", "^", "atan", "(", "0.520", ")", "-", "ctg", "(", "(", "0.933", "^", "0.933", ")", "*", "(", "0.780", "+", "0.933", ")", ")", "/", "ctg", "(", "0.589", ")", "/", "ctg", "(", "0.997", ")", "/", "ln", "(", "(", "0.91", "*", "0.91", ")", "*", "(", "x", "/", "0.91", ")", ")", "-", "asin", "(", "0.25", ")", "+", "log", "(", "0.711", ")", "*", "tan", "(", "(", "0.311", "*", "0.311", ")", "*", "(", "x", "*", "0.311", ")", ")", "-", "asin", "(", "0.601", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.118)-ln(0.331)/acos((0.736*0.736)/(0.736^0.736))*sin(0.409)^atan(0.520)-ctg((0.933^0.933)*(0.780+0.933))/ctg(0.589)/ctg(0.997)/ln((0.91*0.91)*(x/0.91))-asin(0.25)+log(0.711)*tan((0.311*0.311)*(x*0.311))-asin(0.601)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_257) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.236", ")", "^", "sin", "(", "0.574", ")", "+", "asin", "(", "(", "0.858", "+", "0.858", ")", "*", "(", "x", "*", "0.858", ")", ")", "/", "atan", "(", "0.547", ")", "^", "asin", "(", "0.13", ")", "+", "asin", "(", "(", "0.910", "*", "0.910", ")", "-", "(", "0.910", "-", "0.910", ")", ")", "/", "acos", "(", "0.259", ")", "^", "0.344"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.236)^sin(0.574)+asin((0.858+0.858)*(x*0.858))/atan(0.547)^asin(0.13)+asin((0.910*0.910)-(0.910-0.910))/acos(0.259)^0.344"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_258) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.78", ")", "-", "log", "(", "0.690", ")", "+", "tan", "(", "(", "0.612", "*", "0.612", ")", "/", "(", "0.612", "+", "0.612", ")", ")", "^", "sqrt", "(", "0.500", ")", "+", "tan", "(", "0.875", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.78)-log(0.690)+tan((0.612*0.612)/(0.612+0.612))^sqrt(0.500)+tan(0.875)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_259) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.220", ")", "-", "cos", "(", "0.211", ")", "/", "ctg", "(", "(", "0.591", "^", "0.591", ")", "+", "(", "0.782", "^", "0.591", ")", ")", "/", "sqrt", "(", "0.815", ")", "*", "asin", "(", "0.223", ")", "/", "cos", "(", "(", "0.555", "*", "0.555", ")", "-", "(", "0.762", "*", "0.555", ")", ")", "*", "atan", "(", "0.752", ")", "*", "log", "(", "0.157", ")", "*", "sin", "(", "(", "0.377", "+", "0.377", ")", "/", "(", "0.377", "+", "0.377", ")", ")", "/", "asin", "(", "0.111", ")", "-", "actg", "(", "0.37", ")", "^", "sin", "(", "(", "0.744", "/", "0.744", ")", "^", "(", "0.744", "+", "0.744", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.220)-cos(0.211)/ctg((0.591^0.591)+(0.782^0.591))/sqrt(0.815)*asin(0.223)/cos((0.555*0.555)-(0.762*0.555))*atan(0.752)*log(0.157)*sin((0.377+0.377)/(0.377+0.377))/asin(0.111)-actg(0.37)^sin((0.744/0.744)^(0.744+0.744))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_260) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.878", ")", "+", "ln", "(", "0.518", ")", "^", "atan", "(", "(", "0.920", "^", "0.920", ")", "-", "(", "0.614", "^", "0.920", ")", ")", "*", "ln", "(", "0.94", ")", "-", "ln", "(", "0.723", ")", "+", "actg", "(", "(", "0.597", "^", "0.597", ")", "*", "(", "0.350", "-", "0.597", ")", ")", "-", "log", "(", "0.559", ")", "*", "actg", "(", "0.850", ")", "-", "sqrt", "(", "(", "0.890", "^", "0.890", ")", "^", "(", "x", "+", "0.890", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.878)+ln(0.518)^atan((0.920^0.920)-(0.614^0.920))*ln(0.94)-ln(0.723)+actg((0.597^0.597)*(0.350-0.597))-log(0.559)*actg(0.850)-sqrt((0.890^0.890)^(x+0.890))*"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_261) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.791", ")", "+", "cos", "(", "0.588", ")", "^", "log", "(", "(", "0.161", "*", "0.161", ")", "-", "(", "0.156", "^", "0.161", ")", ")", "^", "tan", "(", "0.114", ")", "/", "ctg", "(", "0.157", ")", "^", "sin", "(", "(", "0.821", "^", "0.821", ")", "-", "(", "0.830", "*", "0.821", ")", ")", "/", "sin", "(", "0.180", ")", "*", "log", "(", "0.621", ")", "^", "ctg", "(", "(", "0.179", "+", "0.179", ")", "^", "(", "0.179", "^", "0.179", ")", ")", "*", "actg", "(", "0.434", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.791)+cos(0.588)^log((0.161*0.161)-(0.156^0.161))^tan(0.114)/ctg(0.157)^sin((0.821^0.821)-(0.830*0.821))/sin(0.180)*log(0.621)^ctg((0.179+0.179)^(0.179^0.179))*actg(0.434)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_262) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.966", ")", "-", "asin", "(", "0.634", ")", "*", "asin", "(", "(", "0.715", "^", "0.715", ")", "^", "(", "0.715", "+", "0.715", ")", ")", "/", "tan", "(", "0.928", ")", "^", "acos", "(", "0.518", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.966)-asin(0.634)*asin((0.715^0.715)^(0.715+0.715))/tan(0.928)^acos(0.518)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_263) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.684", ")", "*", "cos", "(", "0.167", ")", "*", "ln", "(", "(", "0.261", "*", "0.261", ")", "*", "(", "0.261", "/", "0.261", ")", ")", "-", "sqrt", "(", "0.557", ")", "-", "log", "(", "0.945", ")", "^", "sqrt", "(", "(", "0.241", "^", "0.241", ")", "^", "(", "x", "*", "0.241", ")", ")", "+", "asin", "(", "0.509", ")", "*", "asin", "(", "0.385", ")", "/", "sqrt", "(", "(", "0.809", "-", "0.809", ")", "*", "(", "0.809", "/", "0.809", ")", ")", "/", "atan", "(", "0.816", ")", "^", "tan", "(", "0.622", ")", "-", "sin", "(", "(", "0.242", "/", "0.242", ")", "-", "(", "x", "^", "0.242", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.684)*cos(0.167)*ln((0.261*0.261)*(0.261/0.261))-sqrt(0.557)-log(0.945)^sqrt((0.241^0.241)^(x*0.241))+asin(0.509)*asin(0.385)/sqrt((0.809-0.809)*(0.809/0.809))/atan(0.816)^tan(0.622)-sin((0.242/0.242)-(x^0.242))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_264) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.379", ")", "^", "cos", "(", "0.200", ")", "+", "atan", "(", "(", "0.268", "-", "0.268", ")", "*", "(", "x", "/", "0.268", ")", ")", "/", "sin", "(", "0.862", ")", "*", "asin", "(", "0.930", ")", "-", "log", "(", "(", "0.37", "+", "0.37", ")", "*", "(", "0.780", "/", "0.37", ")", ")", "*", "sin", "(", "0.232", ")", "/", "ln", "(", "0.897", ")", "/", "ln", "(", "(", "0.567", "*", "0.567", ")", "*", "(", "x", "*", "0.567", ")", ")", "*", "ctg", "(", "0.540", ")", "/", "0.878"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.379)^cos(0.200)+atan((0.268-0.268)*(x/0.268))/sin(0.862)*asin(0.930)-log((0.37+0.37)*(0.780/0.37))*sin(0.232)/ln(0.897)/ln((0.567*0.567)*(x*0.567))*ctg(0.540)/0.878"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_265) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.699", ")", "*", "cos", "(", "0.377", ")", "+", "ln", "(", "(", "0.8", "^", "0.8", ")", "-", "(", "0.8", "/", "0.8", ")", ")", "+", "sin", "(", "0.971", ")", "/", "atan", "(", "0.696", ")", "*", "acos", "(", "(", "0.455", "*", "0.455", ")", "^", "(", "x", "*", "0.455", ")", ")", "^", "asin", "(", "0.148", ")", "+", "actg", "(", "0.797", ")", "^", "ln", "(", "(", "0.562", "*", "0.562", ")", "/", "(", "0.562", "/", "0.562", ")", ")", "*", "ln", "(", "0.987", ")", "+", "tan", "(", "0.207", ")", "/", "asin", "(", "(", "0.722", "^", "0.722", ")", "^", "(", "0.235", "^", "0.722", ")", ")", "+", "log", "(", "0.387", ")", "^", "log", "(", "0.979", ")", "/", "tan", "(", "(", "0.417", "^", "0.417", ")", "*", "(", "x", "*", "0.417", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.699)*cos(0.377)+ln((0.8^0.8)-(0.8/0.8))+sin(0.971)/atan(0.696)*acos((0.455*0.455)^(x*0.455))^asin(0.148)+actg(0.797)^ln((0.562*0.562)/(0.562/0.562))*ln(0.987)+tan(0.207)/asin((0.722^0.722)^(0.235^0.722))+log(0.387)^log(0.979)/tan((0.417^0.417)*(x*0.417))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_266) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.823", ")", "^", "sin", "(", "0.989", ")", "-", "tan", "(", "(", "0.831", "*", "0.831", ")", "+", "(", "x", "*", "0.831", ")", ")", "^", "acos", "(", "0.368", ")", "+", "sqrt", "(", "0.317", ")", "^", "ctg", "(", "(", "0.636", "-", "0.636", ")", "+", "(", "0.783", "*", "0.636", ")", ")", "^", "actg", "(", "0.216", ")", "*", "0.133"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.823)^sin(0.989)-tan((0.831*0.831)+(x*0.831))^acos(0.368)+sqrt(0.317)^ctg((0.636-0.636)+(0.783*0.636))^actg(0.216)*0.133"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_267) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.651", ")", "+", "cos", "(", "0.151", ")", "/", "tan", "(", "(", "0.268", "-", "0.268", ")", "*", "(", "x", "-", "0.268", ")", ")", "+", "log", "(", "0.571", ")", "-", "sin", "(", "0.784", ")", "+", "tan", "(", "(", "0.883", "^", "0.883", ")", "+", "(", "x", "-", "0.883", ")", ")", "+", "atan", "(", "0.381", ")", "-", "asin", "(", "0.241", ")", "+", "sqrt", "(", "(", "0.743", "-", "0.743", ")", "*", "(", "0.75", "/", "0.743", ")", ")", "/", "tan", "(", "0.508", ")", "*", "acos", "(", "0.554", ")", "*", "actg", "(", "(", "0.192", "*", "0.192", ")", "-", "(", "0.192", "^", "0.192", ")", ")", "^", "tan", "(", "0.41", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.651)+cos(0.151)/tan((0.268-0.268)*(x-0.268))+log(0.571)-sin(0.784)+tan((0.883^0.883)+(x-0.883))+atan(0.381)-asin(0.241)+sqrt((0.743-0.743)*(0.75/0.743))/tan(0.508)*acos(0.554)*actg((0.192*0.192)-(0.192^0.192))^tan(0.41)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_268) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.343", ")", "^", "actg", "(", "0.340", ")", "*", "tan", "(", "(", "0.420", "/", "0.420", ")", "*", "(", "0.420", "*", "0.420", ")", ")", "^", "asin", "(", "0.521", ")", "+", "asin", "(", "0.752", ")", "*", "ctg", "(", "(", "0.283", "^", "0.283", ")", "^", "(", "0.36", "-", "0.283", ")", ")", "*", "sqrt", "(", "0.174", ")", "/", "log", "(", "0.851", ")", "+", "ln", "(", "(", "0.850", "/", "0.850", ")", "/", "(", "x", "*", "0.850", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.343)^actg(0.340)*tan((0.420/0.420)*(0.420*0.420))^asin(0.521)+asin(0.752)*ctg((0.283^0.283)^(0.36-0.283))*sqrt(0.174)/log(0.851)+ln((0.850/0.850)/(x*0.850))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_269) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.510", ")", "^", "ln", "(", "0.471", ")", "^", "acos", "(", "(", "0.372", "*", "0.372", ")", "^", "(", "0.372", "-", "0.372", ")", ")", "/", "cos", "(", "0.388", ")", "/", "log", "(", "0.174", ")", "/", "sin", "(", "(", "0.901", "/", "0.901", ")", "^", "(", "0.901", "/", "0.901", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.510)^ln(0.471)^acos((0.372*0.372)^(0.372-0.372))/cos(0.388)/log(0.174)/sin((0.901/0.901)^(0.901/0.901))*"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_270) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.586", ")", "-", "acos", "(", "0.109", ")", "-", "acos", "(", "(", "0.916", "-", "0.916", ")", "/", "(", "0.190", "^", "0.916", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.586)-acos(0.109)-acos((0.916-0.916)/(0.190^0.916))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_271) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.791", ")", "+", "atan", "(", "0.432", ")", "/", "log", "(", "(", "0.685", "/", "0.685", ")", "+", "(", "0.685", "^", "0.685", ")", ")", "+", "cos", "(", "0.84", ")", "+", "ctg", "(", "0.31", ")", "-", "acos", "(", "(", "0.635", "/", "0.635", ")", "*", "(", "0.635", "*", "0.635", ")", ")", "+", "tan", "(", "0.927", ")", "/", "tan", "(", "0.916", ")", "/", "actg", "(", "(", "0.299", "^", "0.299", ")", "-", "(", "x", "+", "0.299", ")", ")", "/", "actg", "(", "0.469", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.791)+atan(0.432)/log((0.685/0.685)+(0.685^0.685))+cos(0.84)+ctg(0.31)-acos((0.635/0.635)*(0.635*0.635))+tan(0.927)/tan(0.916)/actg((0.299^0.299)-(x+0.299))/actg(0.469)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_272) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.430", ")", "+", "atan", "(", "0.513", ")", "-", "ln", "(", "(", "0.276", "-", "0.276", ")", "+", "(", "0.276", "+", "0.276", ")", ")", "+", "sin", "(", "0.792", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.430)+atan(0.513)-ln((0.276-0.276)+(0.276+0.276))+sin(0.792)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_273) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.478", ")", "+", "cos", "(", "0.337", ")", "/", "sin", "(", "(", "0.120", "/", "0.120", ")", "-", "(", "0.120", "+", "0.120", ")", ")", "*", "tan", "(", "0.758", ")", "^", "ctg", "(", "0.323", ")", "-", "asin", "(", "(", "0.988", "-", "0.988", ")", "^", "(", "0.140", "*", "0.988", ")", ")", "/", "ctg", "(", "0.450", ")", "+", "sin", "(", "0.669", ")", "^", "acos", "(", "(", "0.428", "*", "0.428", ")", "-", "(", "x", "-", "0.428", ")", ")", "/", "acos", "(", "0.313", ")", "*", "ln", "(", "0.659", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.478)+cos(0.337)/sin((0.120/0.120)-(0.120+0.120))*tan(0.758)^ctg(0.323)-asin((0.988-0.988)^(0.140*0.988))/ctg(0.450)+sin(0.669)^acos((0.428*0.428)-(x-0.428))/acos(0.313)*ln(0.659)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_274) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.471", ")", "-", "asin", "(", "0.431", ")", "/", "acos", "(", "(", "0.642", "/", "0.642", ")", "*", "(", "0.288", "*", "0.642", ")", ")", "^", "acos", "(", "0.179", ")", "-", "sqrt", "(", "0.906", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.471)-asin(0.431)/acos((0.642/0.642)*(0.288*0.642))^acos(0.179)-sqrt(0.906)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_275) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.986", ")", "+", "log", "(", "0.437", ")", "/", "actg", "(", "(", "0.275", "/", "0.275", ")", "*", "(", "0.275", "+", "0.275", ")", ")", "^", "tan", "(", "0.622", ")", "-", "0.773"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.986)+log(0.437)/actg((0.275/0.275)*(0.275+0.275))^tan(0.622)-0.773"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_276) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.991", ")", "*", "ln", "(", "0.495", ")", "^", "asin", "(", "(", "0.856", "/", "0.856", ")", "*", "(", "0.887", "+", "0.856", ")", ")", "+", "ln", "(", "0.515", ")", "*", "cos", "(", "0.868", ")", "*", "sin", "(", "(", "0.194", "*", "0.194", ")", "^", "(", "0.918", "*", "0.194", ")", ")", "*", "ln", "(", "0.347", ")", "+", "ln", "(", "0.510", ")", "*", "actg", "(", "(", "0.690", "/", "0.690", ")", "^", "(", "0.690", "^", "0.690", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.991)*ln(0.495)^asin((0.856/0.856)*(0.887+0.856))+ln(0.515)*cos(0.868)*sin((0.194*0.194)^(0.918*0.194))*ln(0.347)+ln(0.510)*actg((0.690/0.690)^(0.690^0.690))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_277) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "413", "%", "451"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+413%451"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_278) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.948", ")", "-", "ctg", "(", "0.465", ")", "+", "atan", "(", "(", "0.862", "^", "0.862", ")", "^", "(", "0.862", "/", "0.862", ")", ")", "+", "sqrt", "(", "0.696", ")", "/", "ln", "(", "0.339", ")", "+", "ctg", "(", "(", "0.624", "^", "0.624", ")", "*", "(", "0.446", "*", "0.624", ")", ")", "-", "tan", "(", "0.501", ")", "*", "ln", "(", "0.255", ")", "^", "asin", "(", "(", "0.842", "-", "0.842", ")", "+", "(", "x", "/", "0.842", ")", ")", "+", "ctg", "(", "0.22", ")", "/", "0.543"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.948)-ctg(0.465)+atan((0.862^0.862)^(0.862/0.862))+sqrt(0.696)/ln(0.339)+ctg((0.624^0.624)*(0.446*0.624))-tan(0.501)*ln(0.255)^asin((0.842-0.842)+(x/0.842))+ctg(0.22)/0.543"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_279) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.246", ")", "^", "sqrt", "(", "0.560", ")", "/", "actg", "(", "(", "0.792", "^", "0.792", ")", "*", "(", "0.655", "/", "0.792", ")", ")", "^", "tan", "(", "0.361", ")", "-", "ln", "(", "0.207", ")", "^", "sqrt", "(", "(", "0.39", "^", "0.39", ")", "+", "(", "x", "^", "0.39", ")", ")", "*", "asin", "(", "0.907", ")", "+", "ln", "(", "0.689", ")", "+", "actg", "(", "(", "0.317", "^", "0.317", ")", "/", "(", "0.805", "+", "0.317", ")", ")", "/", "actg", "(", "0.765", ")", "/", "sqrt", "(", "0.187", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.246)^sqrt(0.560)/actg((0.792^0.792)*(0.655/0.792))^tan(0.361)-ln(0.207)^sqrt((0.39^0.39)+(x^0.39))*asin(0.907)+ln(0.689)+actg((0.317^0.317)/(0.805+0.317))/actg(0.765)/sqrt(0.187)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_280) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.143", ")", "*", "cos", "(", "0.344", ")", "-", "atan", "(", "(", "0.413", "+", "0.413", ")", "+", "(", "0.413", "/", "0.413", ")", ")", "-", "sqrt", "(", "0.89", ")", "/", "log", "(", "0.751", ")", "*", "atan", "(", "(", "0.925", "*", "0.925", ")", "-", "(", "0.925", "-", "0.925", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.143)*cos(0.344)-atan((0.413+0.413)+(0.413/0.413))-sqrt(0.89)/log(0.751)*atan((0.925*0.925)-(0.925-0.925))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_281) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.206", ")", "-", "ctg", "(", "0.829", ")", "/", "sin", "(", "(", "0.519", "/", "0.519", ")", "-", "(", "x", "-", "0.519", ")", ")", "/", "atan", "(", "0.854", ")", "-", "asin", "(", "0.259", ")", "*", "asin", "(", "(", "0.10", "^", "0.10", ")", "+", "(", "x", "^", "0.10", ")", ")", "/", "atan", "(", "0.493", ")", "-", "actg", "(", "0.410", ")", "-", "atan", "(", "(", "0.753", "+", "0.753", ")", "-", "(", "x", "^", "0.753", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.206)-ctg(0.829)/sin((0.519/0.519)-(x-0.519))/atan(0.854)-asin(0.259)*asin((0.10^0.10)+(x^0.10))/atan(0.493)-actg(0.410)-atan((0.753+0.753)-(x^0.753))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_282) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.232", ")", "^", "0.295"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.232)^0.295"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_283) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.891", ")", "+", "acos", "(", "0.345", ")", "*", "cos", "(", "(", "0.953", "-", "0.953", ")", "/", "(", "0.953", "*", "0.953", ")", ")", "*", "sqrt", "(", "0.619", ")", "*", "cos", "(", "0.512", ")", "^", "sqrt", "(", "(", "0.270", "*", "0.270", ")", "+", "(", "0.463", "^", "0.270", ")", ")", "-", "sqrt", "(", "0.467", ")", "*", "asin", "(", "0.630", ")", "^", "cos", "(", "(", "0.577", "^", "0.577", ")", "*", "(", "x", "+", "0.577", ")", ")", "/", "acos", "(", "0.296", ")", "+", "0.788"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.891)+acos(0.345)*cos((0.953-0.953)/(0.953*0.953))*sqrt(0.619)*cos(0.512)^sqrt((0.270*0.270)+(0.463^0.270))-sqrt(0.467)*asin(0.630)^cos((0.577^0.577)*(x+0.577))/acos(0.296)+0.788"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_284) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.790", ")", "+", "sqrt", "(", "0.954", ")", "/", "ln", "(", "(", "0.112", "^", "0.112", ")", "-", "(", "x", "^", "0.112", ")", ")", "/", "tan", "(", "0.643", ")", "+", "asin", "(", "0.744", ")", "-", "ctg", "(", "(", "0.906", "^", "0.906", ")", "-", "(", "0.906", "+", "0.906", ")", ")", "-", "ctg", "(", "0.210", ")", "*", "actg", "(", "0.713", ")", "+", "sqrt", "(", "(", "0.506", "/", "0.506", ")", "^", "(", "0.250", "^", "0.506", ")", ")", "*", "ctg", "(", "0.154", ")", "-", "atan", "(", "0.703", ")", "/", "ctg", "(", "(", "0.64", "/", "0.64", ")", "-", "(", "0.421", "^", "0.64", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.790)+sqrt(0.954)/ln((0.112^0.112)-(x^0.112))/tan(0.643)+asin(0.744)-ctg((0.906^0.906)-(0.906+0.906))-ctg(0.210)*actg(0.713)+sqrt((0.506/0.506)^(0.250^0.506))*ctg(0.154)-atan(0.703)/ctg((0.64/0.64)-(0.421^0.64))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_285) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.49", ")", "+", "atan", "(", "0.287", ")", "/", "cos", "(", "(", "0.287", "^", "0.287", ")", "*", "(", "0.115", "/", "0.287", ")", ")", "^", "ctg", "(", "0.472", ")", "-", "tan", "(", "0.565", ")", "/", "actg", "(", "(", "0.116", "-", "0.116", ")", "^", "(", "0.48", "/", "0.116", ")", ")", "/", "log", "(", "0.613", ")", "+", "ln", "(", "0.437", ")", "+", "atan", "(", "(", "0.715", "/", "0.715", ")", "*", "(", "x", "^", "0.715", ")", ")", "*", "sqrt", "(", "0.556", ")", "*", "acos", "(", "0.524", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.49)+atan(0.287)/cos((0.287^0.287)*(0.115/0.287))^ctg(0.472)-tan(0.565)/actg((0.116-0.116)^(0.48/0.116))/log(0.613)+ln(0.437)+atan((0.715/0.715)*(x^0.715))*sqrt(0.556)*acos(0.524)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_286) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.600", ")", "/", "log", "(", "0.621", ")", "*", "acos", "(", "(", "0.282", "+", "0.282", ")", "*", "(", "x", "^", "0.282", ")", ")", "/", "cos", "(", "0.218", ")", "/", "ln", "(", "0.725", ")", "*", "asin", "(", "(", "0.295", "/", "0.295", ")", "/", "(", "0.923", "-", "0.295", ")", ")", "*", "tan", "(", "0.350", ")", "/", "cos", "(", "0.137", ")", "*", "sin", "(", "(", "0.742", "-", "0.742", ")", "*", "(", "0.491", "+", "0.742", ")", ")", "^", "sqrt", "(", "0.197", ")", "/", "sqrt", "(", "0.789", ")", "-", "ln", "(", "(", "0.362", "*", "0.362", ")", "+", "(", "x", "^", "0.362", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.600)/log(0.621)*acos((0.282+0.282)*(x^0.282))/cos(0.218)/ln(0.725)*asin((0.295/0.295)/(0.923-0.295))*tan(0.350)/cos(0.137)*sin((0.742-0.742)*(0.491+0.742))^sqrt(0.197)/sqrt(0.789)-ln((0.362*0.362)+(x^0.362))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_287) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.754", ")", "*", "asin", "(", "0.133", ")", "/", "atan", "(", "(", "0.236", "/", "0.236", ")", "*", "(", "0.634", "-", "0.236", ")", ")", "*", "sqrt", "(", "0.140", ")", "-", "ctg", "(", "0.600", ")", "*", "sqrt", "(", "(", "0.835", "^", "0.835", ")", "-", "(", "0.907", "*", "0.835", ")", ")", "+", "ln", "(", "0.391", ")", "+", "sqrt", "(", "0.290", ")", "*", "tan", "(", "(", "0.502", "+", "0.502", ")", "/", "(", "x", "+", "0.502", ")", ")", "/", "actg", "(", "0.501", ")", "^", "actg", "(", "0.194", ")", "*", "log", "(", "(", "0.2", "^", "0.2", ")", "+", "(", "0.384", "^", "0.2", ")", ")", "*", "asin", "(", "0.392", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.754)*asin(0.133)/atan((0.236/0.236)*(0.634-0.236))*sqrt(0.140)-ctg(0.600)*sqrt((0.835^0.835)-(0.907*0.835))+ln(0.391)+sqrt(0.290)*tan((0.502+0.502)/(x+0.502))/actg(0.501)^actg(0.194)*log((0.2^0.2)+(0.384^0.2))*asin(0.392)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_288) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.651", ")", "^", "ctg", "(", "0.810", ")", "*", "log", "(", "(", "0.270", "+", "0.270", ")", "-", "(", "x", "^", "0.270", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.651)^ctg(0.810)*log((0.270+0.270)-(x^0.270))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_289) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.185", ")", "/", "cos", "(", "0.95", ")", "-", "ln", "(", "(", "0.698", "-", "0.698", ")", "*", "(", "0.698", "^", "0.698", ")", ")", "*", "atan", "(", "0.588", ")", "/", "sqrt", "(", "0.253", ")", "-", "actg", "(", "(", "0.12", "+", "0.12", ")", "+", "(", "0.12", "+", "0.12", ")", ")", "^", "ln", "(", "0.705", ")", "-", "cos", "(", "0.125", ")", "^", "asin", "(", "(", "0.135", "-", "0.135", ")", "*", "(", "0.149", "/", "0.135", ")", ")", "^", "sin", "(", "0.140", ")", "-", "sin", "(", "0.703", ")", "/", "sin", "(", "(", "0.437", "/", "0.437", ")", "/", "(", "0.562", "*", "0.437", ")", ")", "/", "cos", "(", "0.555", ")", "^", "log", "(", "0.963", ")", "+", "acos", "(", "(", "0.801", "/", "0.801", ")", "^", "(", "0.429", "-", "0.801", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.185)/cos(0.95)-ln((0.698-0.698)*(0.698^0.698))*atan(0.588)/sqrt(0.253)-actg((0.12+0.12)+(0.12+0.12))^ln(0.705)-cos(0.125)^asin((0.135-0.135)*(0.149/0.135))^sin(0.140)-sin(0.703)/sin((0.437/0.437)/(0.562*0.437))/cos(0.555)^log(0.963)+acos((0.801/0.801)^(0.429-0.801))*"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_290) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.812", ")", "*", "sin", "(", "0.21", ")", "+", "sin", "(", "(", "0.103", "*", "0.103", ")", "/", "(", "0.699", "+", "0.103", ")", ")", "^", "actg", "(", "0.259", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.812)*sin(0.21)+sin((0.103*0.103)/(0.699+0.103))^actg(0.259)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_291) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.389", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.389)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_292) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.572", ")", "+", "actg", "(", "0.116", ")", "^", "sqrt", "(", "(", "0.22", "-", "0.22", ")", "*", "(", "0.806", "-", "0.22", ")", ")", "^", "log", "(", "0.819", ")", "/", "0.364"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.572)+actg(0.116)^sqrt((0.22-0.22)*(0.806-0.22))^log(0.819)/0.364"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_293) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.208", ")", "-", "sqrt", "(", "0.963", ")", "/", "tan", "(", "(", "0.372", "-", "0.372", ")", "+", "(", "x", "+", "0.372", ")", ")", "/", "cos", "(", "0.504", ")", "*", "sqrt", "(", "0.910", ")", "^", "tan", "(", "(", "0.381", "/", "0.381", ")", "/", "(", "0.381", "+", "0.381", ")", ")", "/", "asin", "(", "0.7", ")", "*", "actg", "(", "0.399", ")", "+", "log", "(", "(", "0.298", "*", "0.298", ")", "-", "(", "x", "-", "0.298", ")", ")", "-", "log", "(", "0.600", ")", "^", "0.113"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.208)-sqrt(0.963)/tan((0.372-0.372)+(x+0.372))/cos(0.504)*sqrt(0.910)^tan((0.381/0.381)/(0.381+0.381))/asin(0.7)*actg(0.399)+log((0.298*0.298)-(x-0.298))-log(0.600)^0.113"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_294) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.142", ")", "^", "tan", "(", "0.329", ")", "+", "sqrt", "(", "(", "0.82", "*", "0.82", ")", "+", "(", "0.993", "+", "0.82", ")", ")", "*", "sin", "(", "0.769", ")", "-", "atan", "(", "0.486", ")", "/", "atan", "(", "(", "0.10", "*", "0.10", ")", "*", "(", "0.10", "+", "0.10", ")", ")", "*", "sqrt", "(", "0.508", ")", "^", "cos", "(", "0.626", ")", "*", "tan", "(", "(", "0.409", "*", "0.409", ")", "^", "(", "0.409", "+", "0.409", ")", ")", "/", "asin", "(", "0.766", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.142)^tan(0.329)+sqrt((0.82*0.82)+(0.993+0.82))*sin(0.769)-atan(0.486)/atan((0.10*0.10)*(0.10+0.10))*sqrt(0.508)^cos(0.626)*tan((0.409*0.409)^(0.409+0.409))/asin(0.766)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_295) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.56", ")", "+", "tan", "(", "0.181", ")", "*", "log", "(", "(", "0.731", "^", "0.731", ")", "*", "(", "x", "-", "0.731", ")", ")", "/", "atan", "(", "0.570", ")", "/", "tan", "(", "0.945", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.56)+tan(0.181)*log((0.731^0.731)*(x-0.731))/atan(0.570)/tan(0.945)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_296) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.83", ")", "-", "tan", "(", "0.798", ")", "+", "sqrt", "(", "(", "0.402", "/", "0.402", ")", "/", "(", "x", "/", "0.402", ")", ")", "*", "tan", "(", "0.672", ")", "-", "acos", "(", "0.378", ")", "+", "ctg", "(", "(", "0.903", "^", "0.903", ")", "-", "(", "0.381", "+", "0.903", ")", ")", "/", "acos", "(", "0.803", ")", "+", "tan", "(", "0.395", ")", "*", "sin", "(", "(", "0.363", "^", "0.363", ")", "*", "(", "0.975", "/", "0.363", ")", ")", "*", "sqrt", "(", "0.619", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.83)-tan(0.798)+sqrt((0.402/0.402)/(x/0.402))*tan(0.672)-acos(0.378)+ctg((0.903^0.903)-(0.381+0.903))/acos(0.803)+tan(0.395)*sin((0.363^0.363)*(0.975/0.363))*sqrt(0.619)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_297) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.0", ")", "+", "sqrt", "(", "0.313", ")", "^", "sin", "(", "(", "0.828", "^", "0.828", ")", "+", "(", "0.828", "+", "0.828", ")", ")", "+", "log", "(", "0.134", ")", "/", "sin", "(", "0.800", ")", "*", "actg", "(", "(", "0.298", "-", "0.298", ")", "/", "(", "0.312", "^", "0.298", ")", ")", "/", "ln", "(", "0.309", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.0)+sqrt(0.313)^sin((0.828^0.828)+(0.828+0.828))+log(0.134)/sin(0.800)*actg((0.298-0.298)/(0.312^0.298))/ln(0.309)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_298) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.627", ")", "*", "acos", "(", "0.484", ")", "-", "acos", "(", "(", "0.599", "+", "0.599", ")", "^", "(", "0.153", "-", "0.599", ")", ")", "/", "ln", "(", "0.844", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.627)*acos(0.484)-acos((0.599+0.599)^(0.153-0.599))/ln(0.844)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_299) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.636", ")", "+", "ln", "(", "0.928", ")", "/", "ctg", "(", "(", "0.838", "+", "0.838", ")", "+", "(", "0.838", "/", "0.838", ")", ")", "^", "ln", "(", "0.561", ")", "*", "acos", "(", "0.541", ")", "*", "acos", "(", "(", "0.91", "*", "0.91", ")", "+", "(", "0.589", "*", "0.91", ")", ")", "+", "sqrt", "(", "0.562", ")", "*", "ln", "(", "0.98", ")", "^", "sqrt", "(", "(", "0.611", "+", "0.611", ")", "*", "(", "x", "^", "0.611", ")", ")", "+", "asin", "(", "0.215", ")", "/", "sqrt", "(", "0.360", ")", "^", "sin", "(", "(", "0.427", "^", "0.427", ")", "-", "(", "0.511", "+", "0.427", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.636)+ln(0.928)/ctg((0.838+0.838)+(0.838/0.838))^ln(0.561)*acos(0.541)*acos((0.91*0.91)+(0.589*0.91))+sqrt(0.562)*ln(0.98)^sqrt((0.611+0.611)*(x^0.611))+asin(0.215)/sqrt(0.360)^sin((0.427^0.427)-(0.511+0.427))*"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  
  free_stack(&stack);
}
END_TEST

START_TEST(parser_300) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.131", ")", "*", "atan", "(", "0.964", ")", "-", "actg", "(", "(", "0.641", "/", "0.641", ")", "/", "(", "0.641", "-", "0.641", ")", ")", "+", "ctg", "(", "0.641", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.131)*atan(0.964)-actg((0.641/0.641)/(0.641-0.641))+ctg(0.641)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
    tcase_add_test(tc_parser, parser_101);
    tcase_add_test(tc_parser, parser_102);
    tcase_add_test(tc_parser, parser_103);
    tcase_add_test(tc_parser, parser_104);
    tcase_add_test(tc_parser, parser_105);
    tcase_add_test(tc_parser, parser_106);
    tcase_add_test(tc_parser, parser_107);
    tcase_add_test(tc_parser, parser_108);
    tcase_add_test(tc_parser, parser_109);
    tcase_add_test(tc_parser, parser_110);
    tcase_add_test(tc_parser, parser_111);
    tcase_add_test(tc_parser, parser_112);
    tcase_add_test(tc_parser, parser_113);
    tcase_add_test(tc_parser, parser_114);
    tcase_add_test(tc_parser, parser_115);
    tcase_add_test(tc_parser, parser_116);
    tcase_add_test(tc_parser, parser_117);
    tcase_add_test(tc_parser, parser_118);
    tcase_add_test(tc_parser, parser_119);
    tcase_add_test(tc_parser, parser_120);
    tcase_add_test(tc_parser, parser_121);
    tcase_add_test(tc_parser, parser_122);
    tcase_add_test(tc_parser, parser_123);
    tcase_add_test(tc_parser, parser_124);
    tcase_add_test(tc_parser, parser_125);
    tcase_add_test(tc_parser, parser_126);
    tcase_add_test(tc_parser, parser_127);
    tcase_add_test(tc_parser, parser_128);
    tcase_add_test(tc_parser, parser_129);
    tcase_add_test(tc_parser, parser_130);
    tcase_add_test(tc_parser, parser_131);
    tcase_add_test(tc_parser, parser_132);
    tcase_add_test(tc_parser, parser_133);
    tcase_add_test(tc_parser, parser_134);
    tcase_add_test(tc_parser, parser_135);
    tcase_add_test(tc_parser, parser_136);
    tcase_add_test(tc_parser, parser_137);
    tcase_add_test(tc_parser, parser_138);
    tcase_add_test(tc_parser, parser_139);
    tcase_add_test(tc_parser, parser_140);
    tcase_add_test(tc_parser, parser_141);
    tcase_add_test(tc_parser, parser_142);
    tcase_add_test(tc_parser, parser_143);
    tcase_add_test(tc_parser, parser_144);
    tcase_add_test(tc_parser, parser_145);
    tcase_add_test(tc_parser, parser_146);
    tcase_add_test(tc_parser, parser_147);
    tcase_add_test(tc_parser, parser_148);
    tcase_add_test(tc_parser, parser_149);
    tcase_add_test(tc_parser, parser_150);
    tcase_add_test(tc_parser, parser_151);
    tcase_add_test(tc_parser, parser_152);
    tcase_add_test(tc_parser, parser_153);
    tcase_add_test(tc_parser, parser_154);
    tcase_add_test(tc_parser, parser_155);
    tcase_add_test(tc_parser, parser_156);
    tcase_add_test(tc_parser, parser_157);
    tcase_add_test(tc_parser, parser_158);
    tcase_add_test(tc_parser, parser_159);
    tcase_add_test(tc_parser, parser_160);
    tcase_add_test(tc_parser, parser_161);
    tcase_add_test(tc_parser, parser_162);
    tcase_add_test(tc_parser, parser_163);
    tcase_add_test(tc_parser, parser_164);
    tcase_add_test(tc_parser, parser_165);
    tcase_add_test(tc_parser, parser_166);
    tcase_add_test(tc_parser, parser_167);
    tcase_add_test(tc_parser, parser_168);
    tcase_add_test(tc_parser, parser_169);
    tcase_add_test(tc_parser, parser_170);
    tcase_add_test(tc_parser, parser_171);
    tcase_add_test(tc_parser, parser_172);
    tcase_add_test(tc_parser, parser_173);
    tcase_add_test(tc_parser, parser_174);
    tcase_add_test(tc_parser, parser_175);
    tcase_add_test(tc_parser, parser_176);
    tcase_add_test(tc_parser, parser_177);
    tcase_add_test(tc_parser, parser_178);
    tcase_add_test(tc_parser, parser_179);
    tcase_add_test(tc_parser, parser_180);
    tcase_add_test(tc_parser, parser_181);
    tcase_add_test(tc_parser, parser_182);
    tcase_add_test(tc_parser, parser_183);
    tcase_add_test(tc_parser, parser_184);
    tcase_add_test(tc_parser, parser_185);
    tcase_add_test(tc_parser, parser_186);
    tcase_add_test(tc_parser, parser_187);
    tcase_add_test(tc_parser, parser_188);
    tcase_add_test(tc_parser, parser_189);
    tcase_add_test(tc_parser, parser_190);
    tcase_add_test(tc_parser, parser_191);
    tcase_add_test(tc_parser, parser_192);
    tcase_add_test(tc_parser, parser_193);
    tcase_add_test(tc_parser, parser_194);
    tcase_add_test(tc_parser, parser_195);
    tcase_add_test(tc_parser, parser_196);
    tcase_add_test(tc_parser, parser_197);
    tcase_add_test(tc_parser, parser_198);
    tcase_add_test(tc_parser, parser_199);
    tcase_add_test(tc_parser, parser_200);
    tcase_add_test(tc_parser, parser_201);
    tcase_add_test(tc_parser, parser_202);
    tcase_add_test(tc_parser, parser_203);
    tcase_add_test(tc_parser, parser_204);
    tcase_add_test(tc_parser, parser_205);
    tcase_add_test(tc_parser, parser_206);
    tcase_add_test(tc_parser, parser_207);
    tcase_add_test(tc_parser, parser_208);
    tcase_add_test(tc_parser, parser_209);
    tcase_add_test(tc_parser, parser_210);
    tcase_add_test(tc_parser, parser_211);
    tcase_add_test(tc_parser, parser_212);
    tcase_add_test(tc_parser, parser_213);
    tcase_add_test(tc_parser, parser_214);
    tcase_add_test(tc_parser, parser_215);
    tcase_add_test(tc_parser, parser_216);
    tcase_add_test(tc_parser, parser_217);
    tcase_add_test(tc_parser, parser_218);
    tcase_add_test(tc_parser, parser_219);
    tcase_add_test(tc_parser, parser_220);
    tcase_add_test(tc_parser, parser_221);
    tcase_add_test(tc_parser, parser_222);
    tcase_add_test(tc_parser, parser_223);
    tcase_add_test(tc_parser, parser_224);
    tcase_add_test(tc_parser, parser_225);
    tcase_add_test(tc_parser, parser_226);
    tcase_add_test(tc_parser, parser_227);
    tcase_add_test(tc_parser, parser_228);
    tcase_add_test(tc_parser, parser_229);
    tcase_add_test(tc_parser, parser_230);
    tcase_add_test(tc_parser, parser_231);
    tcase_add_test(tc_parser, parser_232);
    tcase_add_test(tc_parser, parser_233);
    tcase_add_test(tc_parser, parser_234);
    tcase_add_test(tc_parser, parser_235);
    tcase_add_test(tc_parser, parser_236);
    tcase_add_test(tc_parser, parser_237);
    tcase_add_test(tc_parser, parser_238);
    tcase_add_test(tc_parser, parser_239);
    tcase_add_test(tc_parser, parser_240);
    tcase_add_test(tc_parser, parser_241);
    tcase_add_test(tc_parser, parser_242);
    tcase_add_test(tc_parser, parser_243);
    tcase_add_test(tc_parser, parser_244);
    tcase_add_test(tc_parser, parser_245);
    tcase_add_test(tc_parser, parser_246);
    tcase_add_test(tc_parser, parser_247);
    tcase_add_test(tc_parser, parser_248);
    tcase_add_test(tc_parser, parser_249);
    tcase_add_test(tc_parser, parser_250);
    tcase_add_test(tc_parser, parser_251);
    tcase_add_test(tc_parser, parser_252);
    tcase_add_test(tc_parser, parser_253);
    tcase_add_test(tc_parser, parser_254);
    tcase_add_test(tc_parser, parser_255);
    tcase_add_test(tc_parser, parser_256);
    tcase_add_test(tc_parser, parser_257);
    tcase_add_test(tc_parser, parser_258);
    tcase_add_test(tc_parser, parser_259);
    tcase_add_test(tc_parser, parser_260);
    tcase_add_test(tc_parser, parser_261);
    tcase_add_test(tc_parser, parser_262);
    tcase_add_test(tc_parser, parser_263);
    tcase_add_test(tc_parser, parser_264);
    tcase_add_test(tc_parser, parser_265);
    tcase_add_test(tc_parser, parser_266);
    tcase_add_test(tc_parser, parser_267);
    tcase_add_test(tc_parser, parser_268);
    tcase_add_test(tc_parser, parser_269);
    tcase_add_test(tc_parser, parser_270);
    tcase_add_test(tc_parser, parser_271);
    tcase_add_test(tc_parser, parser_272);
    tcase_add_test(tc_parser, parser_273);
    tcase_add_test(tc_parser, parser_274);
    tcase_add_test(tc_parser, parser_275);
    tcase_add_test(tc_parser, parser_276);
    tcase_add_test(tc_parser, parser_277);
    tcase_add_test(tc_parser, parser_278);
    tcase_add_test(tc_parser, parser_279);
    tcase_add_test(tc_parser, parser_280);
    tcase_add_test(tc_parser, parser_281);
    tcase_add_test(tc_parser, parser_282);
    tcase_add_test(tc_parser, parser_283);
    tcase_add_test(tc_parser, parser_284);
    tcase_add_test(tc_parser, parser_285);
    tcase_add_test(tc_parser, parser_286);
    tcase_add_test(tc_parser, parser_287);
    tcase_add_test(tc_parser, parser_288);
    tcase_add_test(tc_parser, parser_289);
    tcase_add_test(tc_parser, parser_290);
    tcase_add_test(tc_parser, parser_291);
    tcase_add_test(tc_parser, parser_292);
    tcase_add_test(tc_parser, parser_293);
    tcase_add_test(tc_parser, parser_294);
    tcase_add_test(tc_parser, parser_295);
    tcase_add_test(tc_parser, parser_296);
    tcase_add_test(tc_parser, parser_297);
    tcase_add_test(tc_parser, parser_298);
    tcase_add_test(tc_parser, parser_299);
    tcase_add_test(tc_parser, parser_300);

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
