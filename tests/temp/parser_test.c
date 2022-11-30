#include "../header.h"

START_TEST(parser_1) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.572", ")", "-", "atan", "(", "0.719", ")", "^", "sqrt", "(", "(", "0.920", "^", "0.920", ")", "*", "(", "x", "-", "0.920", ")", ")", "-", "cos", "(", "0.579", ")", "/", "sqrt", "(", "0.3", ")", "^", "log", "(", "(", "0.96", "-", "0.96", ")", "^", "(", "x", "-", "0.96", ")", ")", "-", "atan", "(", "0.990", ")", "/", "cos", "(", "0.521", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.572)-atan(0.719)^sqrt((0.920^0.920)*(x-0.920))-cos(0.579)/sqrt(0.3)^log((0.96-0.96)^(x-0.96))-atan(0.990)/cos(0.521)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.563", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.563)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.803", ")", "^", "sqrt", "(", "0.856", ")", "-", "ln", "(", "(", "0.947", "-", "0.947", ")", "*", "(", "x", "/", "0.947", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.803)^sqrt(0.856)-ln((0.947-0.947)*(x/0.947))*"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.591", ")", "-", "tan", "(", "0.249", ")", "^", "ln", "(", "(", "0.42", "+", "0.42", ")", "^", "(", "0.623", "*", "0.42", ")", ")", "/", "atan", "(", "0.619", ")", "*", "cos", "(", "0.57", ")", "/", "sin", "(", "(", "0.326", "-", "0.326", ")", "^", "(", "0.889", "^", "0.326", ")", ")", "+", "ln", "(", "0.495", ")", "^", "tan", "(", "0.869", ")", "/", "atan", "(", "(", "0.714", "/", "0.714", ")", "^", "(", "0.946", "-", "0.714", ")", ")", "+", "asin", "(", "0.963", ")", "/", "acos", "(", "0.547", ")", "*", "asin", "(", "(", "0.474", "-", "0.474", ")", "^", "(", "0.474", "+", "0.474", ")", ")", "^", "cos", "(", "0.734", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.591)-tan(0.249)^ln((0.42+0.42)^(0.623*0.42))/atan(0.619)*cos(0.57)/sin((0.326-0.326)^(0.889^0.326))+ln(0.495)^tan(0.869)/atan((0.714/0.714)^(0.946-0.714))+asin(0.963)/acos(0.547)*asin((0.474-0.474)^(0.474+0.474))^cos(0.734)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.481", ")", "*", "log", "(", "0.782", ")", "/", "sin", "(", "(", "0.92", "-", "0.92", ")", "-", "(", "x", "/", "0.92", ")", ")", "*", "atan", "(", "0.961", ")", "+", "acos", "(", "0.501", ")", "*", "asin", "(", "(", "0.698", "*", "0.698", ")", "/", "(", "0.429", "-", "0.698", ")", ")", "+", "cos", "(", "0.989", ")", "/", "acos", "(", "0.206", ")", "-", "sqrt", "(", "(", "0.80", "/", "0.80", ")", "^", "(", "x", "-", "0.80", ")", ")", "^", "sqrt", "(", "0.284", ")", "+", "asin", "(", "0.606", ")", "/", "sqrt", "(", "(", "0.735", "*", "0.735", ")", "+", "(", "0.735", "-", "0.735", ")", ")", "-", "asin", "(", "0.905", ")", "-", "log", "(", "0.638", ")", "+", "atan", "(", "(", "0.157", "-", "0.157", ")", "-", "(", "0.157", "^", "0.157", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.481)*log(0.782)/sin((0.92-0.92)-(x/0.92))*atan(0.961)+acos(0.501)*asin((0.698*0.698)/(0.429-0.698))+cos(0.989)/acos(0.206)-sqrt((0.80/0.80)^(x-0.80))^sqrt(0.284)+asin(0.606)/sqrt((0.735*0.735)+(0.735-0.735))-asin(0.905)-log(0.638)+atan((0.157-0.157)-(0.157^0.157))^"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.481", ")", "/", "sqrt", "(", "0.575", ")", "-", "atan", "(", "(", "0.859", "/", "0.859", ")", "^", "(", "0.711", "/", "0.859", ")", ")", "^", "log", "(", "0.502", ")", "^", "0.341"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.481)/sqrt(0.575)-atan((0.859/0.859)^(0.711/0.859))^log(0.502)^0.341"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.748", ")", "^", "asin", "(", "0.500", ")", "/", "ln", "(", "(", "0.997", "/", "0.997", ")", "+", "(", "0.310", "+", "0.997", ")", ")", "-", "asin", "(", "0.445", ")", "*", "tan", "(", "0.954", ")", "^", "sqrt", "(", "(", "0.303", "^", "0.303", ")", "-", "(", "0.303", "^", "0.303", ")", ")", "+", "sqrt", "(", "0.300", ")", "/", "atan", "(", "0.352", ")", "/", "acos", "(", "(", "0.192", "^", "0.192", ")", "^", "(", "0.192", "^", "0.192", ")", ")", "+", "asin", "(", "0.473", ")", "+", "tan", "(", "0.979", ")", "*", "sqrt", "(", "(", "0.112", "*", "0.112", ")", "+", "(", "0.369", "^", "0.112", ")", ")", "+", "atan", "(", "0.652", ")", "*", "ln", "(", "0.112", ")", "^", "asin", "(", "(", "0.821", "/", "0.821", ")", "^", "(", "0.497", "-", "0.821", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.748)^asin(0.500)/ln((0.997/0.997)+(0.310+0.997))-asin(0.445)*tan(0.954)^sqrt((0.303^0.303)-(0.303^0.303))+sqrt(0.300)/atan(0.352)/acos((0.192^0.192)^(0.192^0.192))+asin(0.473)+tan(0.979)*sqrt((0.112*0.112)+(0.369^0.112))+atan(0.652)*ln(0.112)^asin((0.821/0.821)^(0.497-0.821))^"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.571", ")", "*", "cos", "(", "0.974", ")", "+", "asin", "(", "(", "0.4", "^", "0.4", ")", "-", "(", "x", "+", "0.4", ")", ")", "/", "log", "(", "0.202", ")", "-", "tan", "(", "0.612", ")", "-", "atan", "(", "(", "0.383", "^", "0.383", ")", "+", "(", "0.383", "^", "0.383", ")", ")", "+", "sqrt", "(", "0.372", ")", "^", "tan", "(", "0.785", ")", "*", "tan", "(", "(", "0.989", "+", "0.989", ")", "+", "(", "0.86", "/", "0.989", ")", ")", "/", "asin", "(", "0.565", ")", "^", "atan", "(", "0.652", ")", "+", "cos", "(", "(", "0.607", "^", "0.607", ")", "/", "(", "x", "-", "0.607", ")", ")", "^", "tan", "(", "0.531", ")", "*", "0.380"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.571)*cos(0.974)+asin((0.4^0.4)-(x+0.4))/log(0.202)-tan(0.612)-atan((0.383^0.383)+(0.383^0.383))+sqrt(0.372)^tan(0.785)*tan((0.989+0.989)+(0.86/0.989))/asin(0.565)^atan(0.652)+cos((0.607^0.607)/(x-0.607))^tan(0.531)*0.380"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.791", ")", "-", "cos", "(", "0.881", ")", "-", "asin", "(", "(", "0.763", "^", "0.763", ")", "^", "(", "0.763", "^", "0.763", ")", ")", "-", "tan", "(", "0.654", ")", "+", "sin", "(", "0.612", ")", "+", "atan", "(", "(", "0.726", "-", "0.726", ")", "/", "(", "0.382", "-", "0.726", ")", ")", "/", "ln", "(", "0.290", ")", "-", "cos", "(", "0.80", ")", "-", "log", "(", "(", "0.81", "*", "0.81", ")", "/", "(", "0.81", "/", "0.81", ")", ")", "/", "ln", "(", "0.923", ")", "*", "0.965"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.791)-cos(0.881)-asin((0.763^0.763)^(0.763^0.763))-tan(0.654)+sin(0.612)+atan((0.726-0.726)/(0.382-0.726))/ln(0.290)-cos(0.80)-log((0.81*0.81)/(0.81/0.81))/ln(0.923)*0.965"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "493", "%", "831"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+493%831"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.418", ")", "*", "sin", "(", "0.89", ")", "/", "sqrt", "(", "(", "0.981", "/", "0.981", ")", "+", "(", "0.607", "*", "0.981", ")", ")", "*", "sin", "(", "0.673", ")", "*", "tan", "(", "0.233", ")", "/", "asin", "(", "(", "0.166", "^", "0.166", ")", "+", "(", "0.166", "^", "0.166", ")", ")", "*", "sqrt", "(", "0.616", ")", "/", "cos", "(", "0.350", ")", "^", "atan", "(", "(", "0.553", "+", "0.553", ")", "*", "(", "0.156", "-", "0.553", ")", ")", "*", "sin", "(", "0.193", ")", "-", "0.679"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.418)*sin(0.89)/sqrt((0.981/0.981)+(0.607*0.981))*sin(0.673)*tan(0.233)/asin((0.166^0.166)+(0.166^0.166))*sqrt(0.616)/cos(0.350)^atan((0.553+0.553)*(0.156-0.553))*sin(0.193)-0.679"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "918", "%", "541"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+918%541"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.73", ")", "*", "asin", "(", "0.48", ")", "+", "cos", "(", "(", "0.235", "+", "0.235", ")", "*", "(", "0.235", "+", "0.235", ")", ")", "+", "asin", "(", "0.702", ")", "*", "acos", "(", "0.336", ")", "^", "cos", "(", "(", "0.716", "^", "0.716", ")", "^", "(", "x", "*", "0.716", ")", ")", "/", "tan", "(", "0.313", ")", "^", "cos", "(", "0.781", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.73)*asin(0.48)+cos((0.235+0.235)*(0.235+0.235))+asin(0.702)*acos(0.336)^cos((0.716^0.716)^(x*0.716))/tan(0.313)^cos(0.781)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.604", ")", "^", "sin", "(", "0.341", ")", "/", "atan", "(", "(", "0.621", "-", "0.621", ")", "*", "(", "x", "+", "0.621", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.604)^sin(0.341)/atan((0.621-0.621)*(x+0.621))*"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.80", ")", "-", "sqrt", "(", "0.34", ")", "-", "sqrt", "(", "(", "0.989", "/", "0.989", ")", "-", "(", "0.989", "/", "0.989", ")", ")", "-", "sqrt", "(", "0.425", ")", "*", "sqrt", "(", "0.985", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.80)-sqrt(0.34)-sqrt((0.989/0.989)-(0.989/0.989))-sqrt(0.425)*sqrt(0.985)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.861", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.861)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.149", ")", "+", "0.381"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.149)+0.381"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.471", ")", "/", "sin", "(", "0.839", ")", "-", "asin", "(", "(", "0.998", "^", "0.998", ")", "-", "(", "x", "-", "0.998", ")", ")", "/", "ln", "(", "0.478", ")", "-", "0.518"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.471)/sin(0.839)-asin((0.998^0.998)-(x-0.998))/ln(0.478)-0.518"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.653", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.653)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.353", ")", "+", "sin", "(", "0.31", ")", "/", "log", "(", "(", "0.23", "/", "0.23", ")", "+", "(", "0.574", "^", "0.23", ")", ")", "+", "acos", "(", "0.986", ")", "^", "asin", "(", "0.679", ")", "*", "cos", "(", "(", "0.630", "*", "0.630", ")", "^", "(", "x", "-", "0.630", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.353)+sin(0.31)/log((0.23/0.23)+(0.574^0.23))+acos(0.986)^asin(0.679)*cos((0.630*0.630)^(x-0.630))*"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.548", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.548)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.790", ")", "-", "sqrt", "(", "0.558", ")", "-", "ln", "(", "(", "0.995", "-", "0.995", ")", "-", "(", "0.740", "+", "0.995", ")", ")", "^", "sqrt", "(", "0.107", ")", "-", "log", "(", "0.380", ")", "-", "log", "(", "(", "0.189", "^", "0.189", ")", "/", "(", "0.189", "/", "0.189", ")", ")", "+", "sin", "(", "0.171", ")", "^", "tan", "(", "0.876", ")", "^", "acos", "(", "(", "0.951", "^", "0.951", ")", "-", "(", "0.951", "-", "0.951", ")", ")", "*", "ln", "(", "0.976", ")", "/", "sqrt", "(", "0.840", ")", "*", "ln", "(", "(", "0.924", "*", "0.924", ")", "^", "(", "0.924", "*", "0.924", ")", ")", "/", "acos", "(", "0.226", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.790)-sqrt(0.558)-ln((0.995-0.995)-(0.740+0.995))^sqrt(0.107)-log(0.380)-log((0.189^0.189)/(0.189/0.189))+sin(0.171)^tan(0.876)^acos((0.951^0.951)-(0.951-0.951))*ln(0.976)/sqrt(0.840)*ln((0.924*0.924)^(0.924*0.924))/acos(0.226)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.492", ")", "*", "asin", "(", "0.877", ")", "*", "cos", "(", "(", "0.207", "-", "0.207", ")", "-", "(", "x", "-", "0.207", ")", ")", "/", "log", "(", "0.479", ")", "+", "cos", "(", "0.584", ")", "*", "sin", "(", "(", "0.736", "*", "0.736", ")", "*", "(", "0.736", "/", "0.736", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.492)*asin(0.877)*cos((0.207-0.207)-(x-0.207))/log(0.479)+cos(0.584)*sin((0.736*0.736)*(0.736/0.736))/"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.743", ")", "*", "log", "(", "0.848", ")", "*", "acos", "(", "(", "0.898", "+", "0.898", ")", "/", "(", "x", "^", "0.898", ")", ")", "/", "tan", "(", "0.163", ")", "+", "acos", "(", "0.703", ")", "^", "atan", "(", "(", "0.350", "-", "0.350", ")", "-", "(", "x", "/", "0.350", ")", ")", "^", "sin", "(", "0.485", ")", "^", "tan", "(", "0.544", ")", "^", "sin", "(", "(", "0.41", "*", "0.41", ")", "^", "(", "0.592", "*", "0.41", ")", ")", "^", "cos", "(", "0.541", ")", "/", "sqrt", "(", "0.676", ")", "+", "asin", "(", "(", "0.335", "+", "0.335", ")", "^", "(", "x", "/", "0.335", ")", ")", "+", "sin", "(", "0.153", ")", "+", "atan", "(", "0.49", ")", "+", "asin", "(", "(", "0.205", "^", "0.205", ")", "+", "(", "x", "/", "0.205", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.743)*log(0.848)*acos((0.898+0.898)/(x^0.898))/tan(0.163)+acos(0.703)^atan((0.350-0.350)-(x/0.350))^sin(0.485)^tan(0.544)^sin((0.41*0.41)^(0.592*0.41))^cos(0.541)/sqrt(0.676)+asin((0.335+0.335)^(x/0.335))+sin(0.153)+atan(0.49)+asin((0.205^0.205)+(x/0.205))+"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.761", ")", "^", "sin", "(", "0.891", ")", "+", "sin", "(", "(", "0.840", "+", "0.840", ")", "^", "(", "0.840", "^", "0.840", ")", ")", "^", "sin", "(", "0.136", ")", "^", "asin", "(", "0.468", ")", "/", "ln", "(", "(", "0.102", "*", "0.102", ")", "/", "(", "0.317", "-", "0.102", ")", ")", "/", "log", "(", "0.601", ")", "^", "cos", "(", "0.465", ")", "/", "log", "(", "(", "0.788", "/", "0.788", ")", "*", "(", "x", "/", "0.788", ")", ")", "-", "cos", "(", "0.754", ")", "^", "cos", "(", "0.218", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.761)^sin(0.891)+sin((0.840+0.840)^(0.840^0.840))^sin(0.136)^asin(0.468)/ln((0.102*0.102)/(0.317-0.102))/log(0.601)^cos(0.465)/log((0.788/0.788)*(x/0.788))-cos(0.754)^cos(0.218)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.7", ")", "*", "ln", "(", "0.855", ")", "+", "sin", "(", "(", "0.187", "/", "0.187", ")", "*", "(", "0.147", "/", "0.187", ")", ")", "-", "log", "(", "0.533", ")", "-", "ln", "(", "0.762", ")", "/", "log", "(", "(", "0.580", "^", "0.580", ")", "/", "(", "0.580", "/", "0.580", ")", ")", "-", "log", "(", "0.410", ")", "/", "asin", "(", "0.168", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.7)*ln(0.855)+sin((0.187/0.187)*(0.147/0.187))-log(0.533)-ln(0.762)/log((0.580^0.580)/(0.580/0.580))-log(0.410)/asin(0.168)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.71", ")", "*", "tan", "(", "0.372", ")", "^", "ln", "(", "(", "0.903", "/", "0.903", ")", "*", "(", "0.903", "-", "0.903", ")", ")", "^", "sin", "(", "0.144", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.71)*tan(0.372)^ln((0.903/0.903)*(0.903-0.903))^sin(0.144)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.796", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.796)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.646", ")", "^", "cos", "(", "0.535", ")", "+", "cos", "(", "(", "0.577", "+", "0.577", ")", "^", "(", "0.577", "+", "0.577", ")", ")", "-", "acos", "(", "0.142", ")", "+", "atan", "(", "0.725", ")", "/", "sqrt", "(", "(", "0.76", "+", "0.76", ")", "^", "(", "0.401", "^", "0.76", ")", ")", "*", "cos", "(", "0.73", ")", "-", "0.273"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.646)^cos(0.535)+cos((0.577+0.577)^(0.577+0.577))-acos(0.142)+atan(0.725)/sqrt((0.76+0.76)^(0.401^0.76))*cos(0.73)-0.273"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.989", ")", "-", "cos", "(", "0.454", ")", "-", "cos", "(", "(", "0.542", "*", "0.542", ")", "-", "(", "0.862", "/", "0.542", ")", ")", "^", "ln", "(", "0.753", ")", "*", "log", "(", "0.66", ")", "-", "cos", "(", "(", "0.630", "+", "0.630", ")", "*", "(", "0.726", "^", "0.630", ")", ")", "+", "acos", "(", "0.958", ")", "-", "atan", "(", "0.314", ")", "+", "asin", "(", "(", "0.517", "^", "0.517", ")", "^", "(", "0.517", "^", "0.517", ")", ")", "*", "tan", "(", "0.144", ")", "+", "0.84"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.989)-cos(0.454)-cos((0.542*0.542)-(0.862/0.542))^ln(0.753)*log(0.66)-cos((0.630+0.630)*(0.726^0.630))+acos(0.958)-atan(0.314)+asin((0.517^0.517)^(0.517^0.517))*tan(0.144)+0.84"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.373", ")", "^", "sin", "(", "0.887", ")", "+", "acos", "(", "(", "0.68", "/", "0.68", ")", "+", "(", "0.419", "-", "0.68", ")", ")", "*", "cos", "(", "0.325", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.373)^sin(0.887)+acos((0.68/0.68)+(0.419-0.68))*cos(0.325)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.739", ")", "^", "acos", "(", "0.41", ")", "^", "asin", "(", "(", "0.150", "-", "0.150", ")", "/", "(", "0.301", "/", "0.150", ")", ")", "^", "cos", "(", "0.994", ")", "*", "atan", "(", "0.896", ")", "+", "log", "(", "(", "0.83", "+", "0.83", ")", "/", "(", "0.83", "^", "0.83", ")", ")", "^", "acos", "(", "0.943", ")", "^", "log", "(", "0.50", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.739)^acos(0.41)^asin((0.150-0.150)/(0.301/0.150))^cos(0.994)*atan(0.896)+log((0.83+0.83)/(0.83^0.83))^acos(0.943)^log(0.50)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.598", ")", "^", "log", "(", "0.954", ")", "-", "log", "(", "(", "0.99", "/", "0.99", ")", "-", "(", "0.514", "-", "0.99", ")", ")", "*", "acos", "(", "0.217", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.598)^log(0.954)-log((0.99/0.99)-(0.514-0.99))*acos(0.217)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.842", ")", "-", "log", "(", "0.552", ")", "/", "tan", "(", "(", "0.635", "^", "0.635", ")", "*", "(", "0.635", "/", "0.635", ")", ")", "/", "sin", "(", "0.761", ")", "-", "sin", "(", "0.310", ")", "/", "cos", "(", "(", "0.313", "/", "0.313", ")", "*", "(", "0.313", "-", "0.313", ")", ")", "-", "asin", "(", "0.834", ")", "^", "0.745"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.842)-log(0.552)/tan((0.635^0.635)*(0.635/0.635))/sin(0.761)-sin(0.310)/cos((0.313/0.313)*(0.313-0.313))-asin(0.834)^0.745"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.758", ")", "-", "0.242"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.758)-0.242"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.405", ")", "*", "sqrt", "(", "0.26", ")", "/", "log", "(", "(", "0.393", "^", "0.393", ")", "+", "(", "0.19", "*", "0.393", ")", ")", "+", "atan", "(", "0.476", ")", "-", "cos", "(", "0.961", ")", "+", "sin", "(", "(", "0.97", "^", "0.97", ")", "^", "(", "x", "*", "0.97", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.405)*sqrt(0.26)/log((0.393^0.393)+(0.19*0.393))+atan(0.476)-cos(0.961)+sin((0.97^0.97)^(x*0.97))-"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.270", ")", "*", "ln", "(", "0.682", ")", "^", "ln", "(", "(", "0.38", "*", "0.38", ")", "/", "(", "0.249", "/", "0.38", ")", ")", "^", "log", "(", "0.122", ")", "^", "0.315"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.270)*ln(0.682)^ln((0.38*0.38)/(0.249/0.38))^log(0.122)^0.315"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.474", ")", "-", "asin", "(", "0.490", ")", "*", "sqrt", "(", "(", "0.976", "/", "0.976", ")", "+", "(", "x", "-", "0.976", ")", ")", "^", "asin", "(", "0.762", ")", "/", "ln", "(", "0.380", ")", "*", "ln", "(", "(", "0.723", "-", "0.723", ")", "*", "(", "0.723", "+", "0.723", ")", ")", "^", "sqrt", "(", "0.479", ")", "-", "tan", "(", "0.184", ")", "/", "atan", "(", "(", "0.79", "-", "0.79", ")", "^", "(", "x", "*", "0.79", ")", ")", "*", "cos", "(", "0.242", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.474)-asin(0.490)*sqrt((0.976/0.976)+(x-0.976))^asin(0.762)/ln(0.380)*ln((0.723-0.723)*(0.723+0.723))^sqrt(0.479)-tan(0.184)/atan((0.79-0.79)^(x*0.79))*cos(0.242)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.507", ")", "^", "sin", "(", "0.591", ")", "-", "log", "(", "(", "0.107", "^", "0.107", ")", "*", "(", "x", "*", "0.107", ")", ")", "+", "ln", "(", "0.767", ")", "/", "sin", "(", "0.512", ")", "/", "sin", "(", "(", "0.51", "+", "0.51", ")", "^", "(", "x", "/", "0.51", ")", ")", "^", "ln", "(", "0.264", ")", "+", "cos", "(", "0.778", ")", "-", "ln", "(", "(", "0.451", "/", "0.451", ")", "*", "(", "0.451", "*", "0.451", ")", ")", "^", "tan", "(", "0.812", ")", "*", "cos", "(", "0.318", ")", "+", "sqrt", "(", "(", "0.981", "*", "0.981", ")", "/", "(", "0.69", "*", "0.981", ")", ")", "+", "sqrt", "(", "0.901", ")", "-", "atan", "(", "0.863", ")", "^", "tan", "(", "(", "0.901", "/", "0.901", ")", "+", "(", "x", "+", "0.901", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.507)^sin(0.591)-log((0.107^0.107)*(x*0.107))+ln(0.767)/sin(0.512)/sin((0.51+0.51)^(x/0.51))^ln(0.264)+cos(0.778)-ln((0.451/0.451)*(0.451*0.451))^tan(0.812)*cos(0.318)+sqrt((0.981*0.981)/(0.69*0.981))+sqrt(0.901)-atan(0.863)^tan((0.901/0.901)+(x+0.901))^"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.760", ")", "/", "asin", "(", "0.981", ")", "*", "tan", "(", "(", "0.157", "-", "0.157", ")", "/", "(", "0.157", "*", "0.157", ")", ")", "*", "acos", "(", "0.418", ")", "+", "sqrt", "(", "0.58", ")", "/", "sqrt", "(", "(", "0.319", "*", "0.319", ")", "*", "(", "0.433", "/", "0.319", ")", ")", "/", "cos", "(", "0.970", ")", "/", "tan", "(", "0.362", ")", "-", "cos", "(", "(", "0.617", "+", "0.617", ")", "+", "(", "x", "+", "0.617", ")", ")", "/", "cos", "(", "0.643", ")", "/", "atan", "(", "0.163", ")", "+", "cos", "(", "(", "0.209", "/", "0.209", ")", "+", "(", "0.209", "-", "0.209", ")", ")", "^", "sin", "(", "0.625", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.760)/asin(0.981)*tan((0.157-0.157)/(0.157*0.157))*acos(0.418)+sqrt(0.58)/sqrt((0.319*0.319)*(0.433/0.319))/cos(0.970)/tan(0.362)-cos((0.617+0.617)+(x+0.617))/cos(0.643)/atan(0.163)+cos((0.209/0.209)+(0.209-0.209))^sin(0.625)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.77", ")", "^", "acos", "(", "0.478", ")", "*", "cos", "(", "(", "0.599", "+", "0.599", ")", "*", "(", "x", "/", "0.599", ")", ")", "+", "atan", "(", "0.246", ")", "+", "ln", "(", "0.703", ")", "*", "asin", "(", "(", "0.197", "/", "0.197", ")", "+", "(", "0.197", "-", "0.197", ")", ")", "-", "sqrt", "(", "0.372", ")", "-", "asin", "(", "0.227", ")", "*", "sin", "(", "(", "0.483", "/", "0.483", ")", "/", "(", "0.483", "+", "0.483", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.77)^acos(0.478)*cos((0.599+0.599)*(x/0.599))+atan(0.246)+ln(0.703)*asin((0.197/0.197)+(0.197-0.197))-sqrt(0.372)-asin(0.227)*sin((0.483/0.483)/(0.483+0.483))-"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.650", ")", "+", "asin", "(", "0.63", ")", "*", "log", "(", "(", "0.580", "^", "0.580", ")", "^", "(", "0.580", "/", "0.580", ")", ")", "/", "acos", "(", "0.249", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.650)+asin(0.63)*log((0.580^0.580)^(0.580/0.580))/acos(0.249)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.770", ")", "/", "ln", "(", "0.344", ")", "^", "acos", "(", "(", "0.532", "/", "0.532", ")", "-", "(", "0.831", "+", "0.532", ")", ")", "-", "ln", "(", "0.204", ")", "-", "atan", "(", "0.178", ")", "-", "ln", "(", "(", "0.491", "/", "0.491", ")", "+", "(", "x", "/", "0.491", ")", ")", "/", "tan", "(", "0.57", ")", "-", "atan", "(", "0.76", ")", "-", "cos", "(", "(", "0.16", "*", "0.16", ")", "+", "(", "0.16", "*", "0.16", ")", ")", "^", "ln", "(", "0.315", ")", "+", "atan", "(", "0.393", ")", "-", "asin", "(", "(", "0.803", "/", "0.803", ")", "+", "(", "0.530", "+", "0.803", ")", ")", "+", "cos", "(", "0.245", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.770)/ln(0.344)^acos((0.532/0.532)-(0.831+0.532))-ln(0.204)-atan(0.178)-ln((0.491/0.491)+(x/0.491))/tan(0.57)-atan(0.76)-cos((0.16*0.16)+(0.16*0.16))^ln(0.315)+atan(0.393)-asin((0.803/0.803)+(0.530+0.803))+cos(0.245)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.2", ")", "-", "acos", "(", "0.975", ")", "^", "sqrt", "(", "(", "0.809", "*", "0.809", ")", "/", "(", "0.506", "*", "0.809", ")", ")", "*", "atan", "(", "0.518", ")", "/", "asin", "(", "0.437", ")", "^", "asin", "(", "(", "0.517", "+", "0.517", ")", "/", "(", "0.940", "*", "0.517", ")", ")", "+", "sin", "(", "0.365", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.2)-acos(0.975)^sqrt((0.809*0.809)/(0.506*0.809))*atan(0.518)/asin(0.437)^asin((0.517+0.517)/(0.940*0.517))+sin(0.365)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.371", ")", "/", "sqrt", "(", "0.353", ")", "*", "ln", "(", "(", "0.402", "/", "0.402", ")", "+", "(", "0.971", "^", "0.402", ")", ")", "*", "log", "(", "0.817", ")", "-", "log", "(", "0.618", ")", "*", "sin", "(", "(", "0.191", "+", "0.191", ")", "-", "(", "0.728", "+", "0.191", ")", ")", "+", "log", "(", "0.250", ")", "^", "sin", "(", "0.697", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.371)/sqrt(0.353)*ln((0.402/0.402)+(0.971^0.402))*log(0.817)-log(0.618)*sin((0.191+0.191)-(0.728+0.191))+log(0.250)^sin(0.697)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.867", ")", "*", "cos", "(", "0.357", ")", "/", "sqrt", "(", "(", "0.852", "-", "0.852", ")", "-", "(", "0.389", "*", "0.852", ")", ")", "+", "tan", "(", "0.968", ")", "*", "sin", "(", "0.294", ")", "*", "asin", "(", "(", "0.437", "*", "0.437", ")", "/", "(", "0.437", "+", "0.437", ")", ")", "/", "acos", "(", "0.236", ")", "^", "tan", "(", "0.995", ")", "*", "ln", "(", "(", "0.16", "-", "0.16", ")", "+", "(", "x", "^", "0.16", ")", ")", "/", "tan", "(", "0.985", ")", "/", "log", "(", "0.763", ")", "-", "atan", "(", "(", "0.223", "+", "0.223", ")", "*", "(", "x", "/", "0.223", ")", ")", "^", "ln", "(", "0.909", ")", "*", "0.964"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.867)*cos(0.357)/sqrt((0.852-0.852)-(0.389*0.852))+tan(0.968)*sin(0.294)*asin((0.437*0.437)/(0.437+0.437))/acos(0.236)^tan(0.995)*ln((0.16-0.16)+(x^0.16))/tan(0.985)/log(0.763)-atan((0.223+0.223)*(x/0.223))^ln(0.909)*0.964"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.249", ")", "*", "asin", "(", "0.637", ")", "*", "sqrt", "(", "(", "0.673", "-", "0.673", ")", "+", "(", "0.153", "^", "0.673", ")", ")", "/", "ln", "(", "0.192", ")", "/", "ln", "(", "0.66", ")", "/", "acos", "(", "(", "0.874", "*", "0.874", ")", "*", "(", "0.677", "-", "0.874", ")", ")", "*", "sin", "(", "0.263", ")", "/", "ln", "(", "0.225", ")", "/", "tan", "(", "(", "0.746", "*", "0.746", ")", "*", "(", "0.746", "/", "0.746", ")", ")", "*", "tan", "(", "0.589", ")", "-", "0.609"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.249)*asin(0.637)*sqrt((0.673-0.673)+(0.153^0.673))/ln(0.192)/ln(0.66)/acos((0.874*0.874)*(0.677-0.874))*sin(0.263)/ln(0.225)/tan((0.746*0.746)*(0.746/0.746))*tan(0.589)-0.609"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.530", ")", "/", "asin", "(", "0.293", ")", "^", "sin", "(", "(", "0.165", "/", "0.165", ")", "/", "(", "x", "^", "0.165", ")", ")", "-", "cos", "(", "0.655", ")", "/", "cos", "(", "0.787", ")", "^", "atan", "(", "(", "0.443", "+", "0.443", ")", "/", "(", "0.535", "/", "0.443", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.530)/asin(0.293)^sin((0.165/0.165)/(x^0.165))-cos(0.655)/cos(0.787)^atan((0.443+0.443)/(0.535/0.443))^"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.726", ")", "+", "atan", "(", "0.269", ")", "/", "cos", "(", "(", "0.491", "/", "0.491", ")", "*", "(", "0.491", "-", "0.491", ")", ")", "-", "log", "(", "0.739", ")", "/", "sqrt", "(", "0.591", ")", "+", "sqrt", "(", "(", "0.93", "+", "0.93", ")", "/", "(", "0.93", "+", "0.93", ")", ")", "-", "acos", "(", "0.440", ")", "+", "acos", "(", "0.230", ")", "/", "cos", "(", "(", "0.354", "^", "0.354", ")", "/", "(", "0.616", "-", "0.354", ")", ")", "/", "log", "(", "0.747", ")", "-", "asin", "(", "0.188", ")", "^", "ln", "(", "(", "0.460", "+", "0.460", ")", "/", "(", "0.460", "*", "0.460", ")", ")", "/", "acos", "(", "0.969", ")", "+", "0.567"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.726)+atan(0.269)/cos((0.491/0.491)*(0.491-0.491))-log(0.739)/sqrt(0.591)+sqrt((0.93+0.93)/(0.93+0.93))-acos(0.440)+acos(0.230)/cos((0.354^0.354)/(0.616-0.354))/log(0.747)-asin(0.188)^ln((0.460+0.460)/(0.460*0.460))/acos(0.969)+0.567"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.857", ")", "-", "cos", "(", "0.242", ")", "^", "tan", "(", "(", "0.161", "^", "0.161", ")", "/", "(", "0.161", "-", "0.161", ")", ")", "/", "tan", "(", "0.211", ")", "-", "sin", "(", "0.987", ")", "-", "log", "(", "(", "0.986", "^", "0.986", ")", "+", "(", "x", "^", "0.986", ")", ")", "-", "log", "(", "0.55", ")", "/", "log", "(", "0.327", ")", "+", "atan", "(", "(", "0.295", "+", "0.295", ")", "/", "(", "0.295", "+", "0.295", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.857)-cos(0.242)^tan((0.161^0.161)/(0.161-0.161))/tan(0.211)-sin(0.987)-log((0.986^0.986)+(x^0.986))-log(0.55)/log(0.327)+atan((0.295+0.295)/(0.295+0.295))-"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.536", ")", "/", "tan", "(", "0.94", ")", "^", "sqrt", "(", "(", "0.140", "/", "0.140", ")", "/", "(", "x", "*", "0.140", ")", ")", "^", "acos", "(", "0.635", ")", "/", "sqrt", "(", "0.303", ")", "^", "cos", "(", "(", "0.485", "+", "0.485", ")", "+", "(", "0.121", "-", "0.485", ")", ")", "/", "sqrt", "(", "0.844", ")", "*", "log", "(", "0.400", ")", "*", "sin", "(", "(", "0.501", "*", "0.501", ")", "^", "(", "0.501", "^", "0.501", ")", ")", "^", "atan", "(", "0.942", ")", "-", "sqrt", "(", "0.348", ")", "*", "sin", "(", "(", "0.165", "-", "0.165", ")", "+", "(", "0.174", "*", "0.165", ")", ")", "+", "ln", "(", "0.197", ")", "*", "cos", "(", "0.665", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.536)/tan(0.94)^sqrt((0.140/0.140)/(x*0.140))^acos(0.635)/sqrt(0.303)^cos((0.485+0.485)+(0.121-0.485))/sqrt(0.844)*log(0.400)*sin((0.501*0.501)^(0.501^0.501))^atan(0.942)-sqrt(0.348)*sin((0.165-0.165)+(0.174*0.165))+ln(0.197)*cos(0.665)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.396", ")", "-", "tan", "(", "0.832", ")", "^", "tan", "(", "(", "0.501", "*", "0.501", ")", "/", "(", "x", "*", "0.501", ")", ")", "-", "sin", "(", "0.607", ")", "+", "atan", "(", "0.393", ")", "+", "tan", "(", "(", "0.767", "/", "0.767", ")", "^", "(", "x", "+", "0.767", ")", ")", "+", "tan", "(", "0.99", ")", "^", "0.894"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.396)-tan(0.832)^tan((0.501*0.501)/(x*0.501))-sin(0.607)+atan(0.393)+tan((0.767/0.767)^(x+0.767))+tan(0.99)^0.894"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.711", ")", "^", "log", "(", "0.700", ")", "/", "sqrt", "(", "(", "0.144", "-", "0.144", ")", "*", "(", "0.144", "-", "0.144", ")", ")", "^", "acos", "(", "0.902", ")", "^", "ln", "(", "0.416", ")", "^", "asin", "(", "(", "0.987", "^", "0.987", ")", "-", "(", "0.269", "/", "0.987", ")", ")", "^", "tan", "(", "0.629", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.711)^log(0.700)/sqrt((0.144-0.144)*(0.144-0.144))^acos(0.902)^ln(0.416)^asin((0.987^0.987)-(0.269/0.987))^tan(0.629)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.687", ")", "+", "atan", "(", "0.838", ")", "-", "acos", "(", "(", "0.549", "*", "0.549", ")", "*", "(", "x", "^", "0.549", ")", ")", "/", "asin", "(", "0.598", ")", "*", "sin", "(", "0.48", ")", "^", "sqrt", "(", "(", "0.386", "*", "0.386", ")", "-", "(", "0.386", "+", "0.386", ")", ")", "+", "asin", "(", "0.854", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.687)+atan(0.838)-acos((0.549*0.549)*(x^0.549))/asin(0.598)*sin(0.48)^sqrt((0.386*0.386)-(0.386+0.386))+asin(0.854)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.788", ")", "/", "ln", "(", "0.381", ")", "+", "sqrt", "(", "(", "0.813", "^", "0.813", ")", "+", "(", "0.813", "^", "0.813", ")", ")", "-", "acos", "(", "0.18", ")", "+", "sin", "(", "0.398", ")", "^", "ln", "(", "(", "0.703", "/", "0.703", ")", "-", "(", "0.944", "*", "0.703", ")", ")", "*", "tan", "(", "0.421", ")", "-", "atan", "(", "0.527", ")", "*", "log", "(", "(", "0.975", "-", "0.975", ")", "/", "(", "0.850", "-", "0.975", ")", ")", "^", "cos", "(", "0.317", ")", "*", "0.906"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.788)/ln(0.381)+sqrt((0.813^0.813)+(0.813^0.813))-acos(0.18)+sin(0.398)^ln((0.703/0.703)-(0.944*0.703))*tan(0.421)-atan(0.527)*log((0.975-0.975)/(0.850-0.975))^cos(0.317)*0.906"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.685", ")", "/", "sqrt", "(", "0.230", ")", "+", "tan", "(", "(", "0.73", "^", "0.73", ")", "/", "(", "x", "^", "0.73", ")", ")", "*", "cos", "(", "0.253", ")", "^", "asin", "(", "0.861", ")", "*", "sqrt", "(", "(", "0.764", "/", "0.764", ")", "/", "(", "0.405", "+", "0.764", ")", ")", "-", "ln", "(", "0.327", ")", "/", "0.898"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.685)/sqrt(0.230)+tan((0.73^0.73)/(x^0.73))*cos(0.253)^asin(0.861)*sqrt((0.764/0.764)/(0.405+0.764))-ln(0.327)/0.898"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.284", ")", "-", "0.219"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.284)-0.219"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.139", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.139)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.401", ")", "+", "sqrt", "(", "0.900", ")", "-", "tan", "(", "(", "0.413", "^", "0.413", ")", "+", "(", "0.414", "*", "0.413", ")", ")", "+", "sqrt", "(", "0.678", ")", "+", "atan", "(", "0.501", ")", "*", "acos", "(", "(", "0.476", "-", "0.476", ")", "+", "(", "0.476", "-", "0.476", ")", ")", "-", "acos", "(", "0.550", ")", "*", "cos", "(", "0.533", ")", "-", "tan", "(", "(", "0.395", "-", "0.395", ")", "*", "(", "x", "-", "0.395", ")", ")", "+", "tan", "(", "0.619", ")", "+", "atan", "(", "0.452", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.401)+sqrt(0.900)-tan((0.413^0.413)+(0.414*0.413))+sqrt(0.678)+atan(0.501)*acos((0.476-0.476)+(0.476-0.476))-acos(0.550)*cos(0.533)-tan((0.395-0.395)*(x-0.395))+tan(0.619)+atan(0.452)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.332", ")", "/", "sin", "(", "0.375", ")", "+", "cos", "(", "(", "0.784", "/", "0.784", ")", "+", "(", "0.784", "*", "0.784", ")", ")", "+", "acos", "(", "0.529", ")", "+", "sqrt", "(", "0.190", ")", "+", "cos", "(", "(", "0.977", "^", "0.977", ")", "-", "(", "0.271", "/", "0.977", ")", ")", "-", "sqrt", "(", "0.360", ")", "^", "acos", "(", "0.211", ")", "^", "tan", "(", "(", "0.356", "/", "0.356", ")", "+", "(", "0.356", "/", "0.356", ")", ")", "*", "asin", "(", "0.551", ")", "*", "cos", "(", "0.994", ")", "+", "acos", "(", "(", "0.32", "/", "0.32", ")", "+", "(", "0.828", "^", "0.32", ")", ")", "+", "acos", "(", "0.726", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.332)/sin(0.375)+cos((0.784/0.784)+(0.784*0.784))+acos(0.529)+sqrt(0.190)+cos((0.977^0.977)-(0.271/0.977))-sqrt(0.360)^acos(0.211)^tan((0.356/0.356)+(0.356/0.356))*asin(0.551)*cos(0.994)+acos((0.32/0.32)+(0.828^0.32))+acos(0.726)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.74", ")", "/", "sin", "(", "0.254", ")", "-", "atan", "(", "(", "0.859", "/", "0.859", ")", "*", "(", "0.781", "^", "0.859", ")", ")", "-", "acos", "(", "0.809", ")", "-", "asin", "(", "0.193", ")", "*", "log", "(", "(", "0.173", "+", "0.173", ")", "-", "(", "x", "^", "0.173", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.74)/sin(0.254)-atan((0.859/0.859)*(0.781^0.859))-acos(0.809)-asin(0.193)*log((0.173+0.173)-(x^0.173))^"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.386", ")", "*", "sqrt", "(", "0.482", ")", "*", "acos", "(", "(", "0.360", "*", "0.360", ")", "+", "(", "0.397", "*", "0.360", ")", ")", "/", "tan", "(", "0.218", ")", "+", "sin", "(", "0.200", ")", "*", "log", "(", "(", "0.417", "+", "0.417", ")", "^", "(", "0.417", "+", "0.417", ")", ")", "-", "tan", "(", "0.849", ")", "^", "asin", "(", "0.223", ")", "-", "ln", "(", "(", "0.67", "^", "0.67", ")", "^", "(", "x", "/", "0.67", ")", ")", "+", "cos", "(", "0.606", ")", "/", "cos", "(", "0.167", ")", "*", "asin", "(", "(", "0.5", "*", "0.5", ")", "-", "(", "x", "/", "0.5", ")", ")", "^", "atan", "(", "0.510", ")", "/", "tan", "(", "0.858", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.386)*sqrt(0.482)*acos((0.360*0.360)+(0.397*0.360))/tan(0.218)+sin(0.200)*log((0.417+0.417)^(0.417+0.417))-tan(0.849)^asin(0.223)-ln((0.67^0.67)^(x/0.67))+cos(0.606)/cos(0.167)*asin((0.5*0.5)-(x/0.5))^atan(0.510)/tan(0.858)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.977", ")", "-", "cos", "(", "0.156", ")", "/", "sin", "(", "(", "0.198", "^", "0.198", ")", "-", "(", "x", "^", "0.198", ")", ")", "-", "atan", "(", "0.47", ")", "-", "acos", "(", "0.927", ")", "-", "asin", "(", "(", "0.805", "^", "0.805", ")", "/", "(", "x", "+", "0.805", ")", ")", "^", "log", "(", "0.891", ")", "/", "log", "(", "0.686", ")", "*", "tan", "(", "(", "0.811", "*", "0.811", ")", "*", "(", "0.247", "*", "0.811", ")", ")", "^", "sin", "(", "0.441", ")", "+", "sqrt", "(", "0.756", ")", "/", "acos", "(", "(", "0.640", "/", "0.640", ")", "/", "(", "x", "^", "0.640", ")", ")", "/", "ln", "(", "0.436", ")", "*", "tan", "(", "0.652", ")", "/", "acos", "(", "(", "0.962", "+", "0.962", ")", "/", "(", "x", "+", "0.962", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.977)-cos(0.156)/sin((0.198^0.198)-(x^0.198))-atan(0.47)-acos(0.927)-asin((0.805^0.805)/(x+0.805))^log(0.891)/log(0.686)*tan((0.811*0.811)*(0.247*0.811))^sin(0.441)+sqrt(0.756)/acos((0.640/0.640)/(x^0.640))/ln(0.436)*tan(0.652)/acos((0.962+0.962)/(x+0.962))+"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.423", ")", "^", "ln", "(", "0.315", ")", "+", "tan", "(", "(", "0.552", "/", "0.552", ")", "+", "(", "0.552", "-", "0.552", ")", ")", "*", "acos", "(", "0.319", ")", "*", "asin", "(", "0.112", ")", "*", "tan", "(", "(", "0.179", "+", "0.179", ")", "+", "(", "x", "^", "0.179", ")", ")", "*", "sin", "(", "0.854", ")", "^", "sqrt", "(", "0.716", ")", "/", "sin", "(", "(", "0.179", "+", "0.179", ")", "+", "(", "0.556", "+", "0.179", ")", ")", "+", "cos", "(", "0.493", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.423)^ln(0.315)+tan((0.552/0.552)+(0.552-0.552))*acos(0.319)*asin(0.112)*tan((0.179+0.179)+(x^0.179))*sin(0.854)^sqrt(0.716)/sin((0.179+0.179)+(0.556+0.179))+cos(0.493)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.190", ")", "^", "acos", "(", "0.947", ")", "*", "acos", "(", "(", "0.948", "/", "0.948", ")", "/", "(", "x", "-", "0.948", ")", ")", "/", "sin", "(", "0.69", ")", "-", "sqrt", "(", "0.694", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.190)^acos(0.947)*acos((0.948/0.948)/(x-0.948))/sin(0.69)-sqrt(0.694)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.480", ")", "*", "cos", "(", "0.698", ")", "^", "log", "(", "(", "0.966", "+", "0.966", ")", "/", "(", "x", "*", "0.966", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.480)*cos(0.698)^log((0.966+0.966)/(x*0.966))/"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.759", ")", "+", "ln", "(", "0.539", ")", "*", "tan", "(", "(", "0.332", "-", "0.332", ")", "+", "(", "0.332", "*", "0.332", ")", ")", "*", "sqrt", "(", "0.15", ")", "/", "atan", "(", "0.592", ")", "*", "ln", "(", "(", "0.639", "+", "0.639", ")", "-", "(", "0.430", "+", "0.639", ")", ")", "/", "cos", "(", "0.802", ")", "*", "log", "(", "0.478", ")", "*", "asin", "(", "(", "0.238", "+", "0.238", ")", "/", "(", "0.873", "-", "0.238", ")", ")", "^", "acos", "(", "0.136", ")", "/", "acos", "(", "0.733", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.759)+ln(0.539)*tan((0.332-0.332)+(0.332*0.332))*sqrt(0.15)/atan(0.592)*ln((0.639+0.639)-(0.430+0.639))/cos(0.802)*log(0.478)*asin((0.238+0.238)/(0.873-0.238))^acos(0.136)/acos(0.733)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.870", ")", "^", "sin", "(", "0.324", ")", "/", "acos", "(", "(", "0.551", "+", "0.551", ")", "^", "(", "x", "^", "0.551", ")", ")", "/", "sqrt", "(", "0.861", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.870)^sin(0.324)/acos((0.551+0.551)^(x^0.551))/sqrt(0.861)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.237", ")", "*", "cos", "(", "0.584", ")", "*", "sqrt", "(", "(", "0.373", "^", "0.373", ")", "-", "(", "0.502", "-", "0.373", ")", ")", "/", "sqrt", "(", "0.227", ")", "*", "atan", "(", "0.480", ")", "/", "log", "(", "(", "0.996", "*", "0.996", ")", "*", "(", "0.286", "*", "0.996", ")", ")", "/", "log", "(", "0.546", ")", "/", "sqrt", "(", "0.902", ")", "/", "log", "(", "(", "0.439", "-", "0.439", ")", "-", "(", "0.439", "/", "0.439", ")", ")", "/", "cos", "(", "0.660", ")", "^", "ln", "(", "0.59", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.237)*cos(0.584)*sqrt((0.373^0.373)-(0.502-0.373))/sqrt(0.227)*atan(0.480)/log((0.996*0.996)*(0.286*0.996))/log(0.546)/sqrt(0.902)/log((0.439-0.439)-(0.439/0.439))/cos(0.660)^ln(0.59)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.201", ")", "-", "tan", "(", "0.492", ")", "*", "cos", "(", "(", "0.365", "-", "0.365", ")", "-", "(", "0.359", "^", "0.365", ")", ")", "-", "sin", "(", "0.886", ")", "-", "sin", "(", "0.694", ")", "^", "ln", "(", "(", "0.181", "+", "0.181", ")", "*", "(", "0.522", "+", "0.181", ")", ")", "*", "ln", "(", "0.461", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.201)-tan(0.492)*cos((0.365-0.365)-(0.359^0.365))-sin(0.886)-sin(0.694)^ln((0.181+0.181)*(0.522+0.181))*ln(0.461)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.594", ")", "/", "asin", "(", "0.328", ")", "+", "atan", "(", "(", "0.94", "*", "0.94", ")", "^", "(", "x", "*", "0.94", ")", ")", "/", "sin", "(", "0.782", ")", "/", "cos", "(", "0.809", ")", "*", "ln", "(", "(", "0.618", "-", "0.618", ")", "-", "(", "0.618", "+", "0.618", ")", ")", "*", "sqrt", "(", "0.121", ")", "+", "sqrt", "(", "0.182", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.594)/asin(0.328)+atan((0.94*0.94)^(x*0.94))/sin(0.782)/cos(0.809)*ln((0.618-0.618)-(0.618+0.618))*sqrt(0.121)+sqrt(0.182)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.402", ")", "+", "sqrt", "(", "0.796", ")", "*", "atan", "(", "(", "0.456", "-", "0.456", ")", "+", "(", "0.456", "*", "0.456", ")", ")", "*", "tan", "(", "0.346", ")", "^", "ln", "(", "0.930", ")", "*", "sqrt", "(", "(", "0.540", "/", "0.540", ")", "*", "(", "0.595", "/", "0.540", ")", ")", "-", "log", "(", "0.636", ")", "/", "acos", "(", "0.832", ")", "/", "tan", "(", "(", "0.38", "+", "0.38", ")", "^", "(", "0.361", "+", "0.38", ")", ")", "*", "log", "(", "0.300", ")", "+", "ln", "(", "0.277", ")", "*", "log", "(", "(", "0.254", "*", "0.254", ")", "/", "(", "0.254", "^", "0.254", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.402)+sqrt(0.796)*atan((0.456-0.456)+(0.456*0.456))*tan(0.346)^ln(0.930)*sqrt((0.540/0.540)*(0.595/0.540))-log(0.636)/acos(0.832)/tan((0.38+0.38)^(0.361+0.38))*log(0.300)+ln(0.277)*log((0.254*0.254)/(0.254^0.254))*"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.929", ")", "*", "ln", "(", "0.176", ")", "^", "sqrt", "(", "(", "0.588", "+", "0.588", ")", "/", "(", "0.588", "^", "0.588", ")", ")", "^", "tan", "(", "0.787", ")", "^", "sqrt", "(", "0.171", ")", "*", "tan", "(", "(", "0.759", "-", "0.759", ")", "^", "(", "0.759", "+", "0.759", ")", ")", "^", "log", "(", "0.145", ")", "*", "ln", "(", "0.810", ")", "+", "cos", "(", "(", "0.488", "*", "0.488", ")", "/", "(", "0.488", "+", "0.488", ")", ")", "*", "sin", "(", "0.933", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.929)*ln(0.176)^sqrt((0.588+0.588)/(0.588^0.588))^tan(0.787)^sqrt(0.171)*tan((0.759-0.759)^(0.759+0.759))^log(0.145)*ln(0.810)+cos((0.488*0.488)/(0.488+0.488))*sin(0.933)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.413", ")", "*", "asin", "(", "0.875", ")", "-", "log", "(", "(", "0.214", "*", "0.214", ")", "/", "(", "0.756", "/", "0.214", ")", ")", "-", "atan", "(", "0.511", ")", "/", "atan", "(", "0.810", ")", "+", "log", "(", "(", "0.573", "^", "0.573", ")", "/", "(", "0.581", "/", "0.573", ")", ")", "-", "acos", "(", "0.688", ")", "-", "cos", "(", "0.220", ")", "-", "sin", "(", "(", "0.60", "^", "0.60", ")", "^", "(", "0.91", "+", "0.60", ")", ")", "^", "sin", "(", "0.311", ")", "/", "0.928"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.413)*asin(0.875)-log((0.214*0.214)/(0.756/0.214))-atan(0.511)/atan(0.810)+log((0.573^0.573)/(0.581/0.573))-acos(0.688)-cos(0.220)-sin((0.60^0.60)^(0.91+0.60))^sin(0.311)/0.928"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.512", ")", "*", "tan", "(", "0.799", ")", "^", "ln", "(", "(", "0.514", "^", "0.514", ")", "-", "(", "x", "+", "0.514", ")", ")", "/", "sqrt", "(", "0.192", ")", "*", "sin", "(", "0.213", ")", "-", "sqrt", "(", "(", "0.272", "^", "0.272", ")", "^", "(", "x", "+", "0.272", ")", ")", "+", "acos", "(", "0.415", ")", "/", "tan", "(", "0.561", ")", "/", "tan", "(", "(", "0.92", "+", "0.92", ")", "/", "(", "0.474", "^", "0.92", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.512)*tan(0.799)^ln((0.514^0.514)-(x+0.514))/sqrt(0.192)*sin(0.213)-sqrt((0.272^0.272)^(x+0.272))+acos(0.415)/tan(0.561)/tan((0.92+0.92)/(0.474^0.92))/"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.403", ")", "*", "asin", "(", "0.372", ")", "+", "sqrt", "(", "(", "0.309", "-", "0.309", ")", "^", "(", "0.497", "^", "0.309", ")", ")", "*", "tan", "(", "0.349", ")", "-", "atan", "(", "0.271", ")", "+", "sqrt", "(", "(", "0.650", "^", "0.650", ")", "+", "(", "0.650", "-", "0.650", ")", ")", "+", "ln", "(", "0.340", ")", "^", "atan", "(", "0.935", ")", "/", "sqrt", "(", "(", "0.182", "*", "0.182", ")", "^", "(", "x", "^", "0.182", ")", ")", "+", "cos", "(", "0.916", ")", "*", "atan", "(", "0.270", ")", "^", "log", "(", "(", "0.536", "+", "0.536", ")", "^", "(", "0.536", "-", "0.536", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.403)*asin(0.372)+sqrt((0.309-0.309)^(0.497^0.309))*tan(0.349)-atan(0.271)+sqrt((0.650^0.650)+(0.650-0.650))+ln(0.340)^atan(0.935)/sqrt((0.182*0.182)^(x^0.182))+cos(0.916)*atan(0.270)^log((0.536+0.536)^(0.536-0.536))*"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "84", "%", "888"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+84%888"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.310", ")", "*", "ln", "(", "0.93", ")", "*", "asin", "(", "(", "0.12", "+", "0.12", ")", "-", "(", "x", "-", "0.12", ")", ")", "-", "atan", "(", "0.975", ")", "*", "asin", "(", "0.495", ")", "*", "acos", "(", "(", "0.696", "*", "0.696", ")", "^", "(", "x", "+", "0.696", ")", ")", "/", "asin", "(", "0.131", ")", "+", "sqrt", "(", "0.431", ")", "+", "sqrt", "(", "(", "0.377", "-", "0.377", ")", "*", "(", "x", "*", "0.377", ")", ")", "-", "atan", "(", "0.488", ")", "*", "sin", "(", "0.135", ")", "-", "ln", "(", "(", "0.740", "^", "0.740", ")", "/", "(", "x", "+", "0.740", ")", ")", "+", "acos", "(", "0.960", ")", "-", "cos", "(", "0.715", ")", "/", "log", "(", "(", "0.188", "^", "0.188", ")", "+", "(", "x", "+", "0.188", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.310)*ln(0.93)*asin((0.12+0.12)-(x-0.12))-atan(0.975)*asin(0.495)*acos((0.696*0.696)^(x+0.696))/asin(0.131)+sqrt(0.431)+sqrt((0.377-0.377)*(x*0.377))-atan(0.488)*sin(0.135)-ln((0.740^0.740)/(x+0.740))+acos(0.960)-cos(0.715)/log((0.188^0.188)+(x+0.188))^"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.339", ")", "*", "sin", "(", "0.262", ")", "/", "acos", "(", "(", "0.868", "-", "0.868", ")", "-", "(", "0.223", "*", "0.868", ")", ")", "-", "log", "(", "0.342", ")", "*", "acos", "(", "0.419", ")", "-", "tan", "(", "(", "0.633", "/", "0.633", ")", "+", "(", "0.898", "*", "0.633", ")", ")", "^", "ln", "(", "0.644", ")", "-", "sqrt", "(", "0.417", ")", "^", "sin", "(", "(", "0.652", "+", "0.652", ")", "^", "(", "0.948", "^", "0.652", ")", ")", "/", "tan", "(", "0.950", ")", "^", "log", "(", "0.873", ")", "+", "asin", "(", "(", "0.776", "/", "0.776", ")", "/", "(", "0.797", "/", "0.776", ")", ")", "^", "sqrt", "(", "0.168", ")", "+", "0.864"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.339)*sin(0.262)/acos((0.868-0.868)-(0.223*0.868))-log(0.342)*acos(0.419)-tan((0.633/0.633)+(0.898*0.633))^ln(0.644)-sqrt(0.417)^sin((0.652+0.652)^(0.948^0.652))/tan(0.950)^log(0.873)+asin((0.776/0.776)/(0.797/0.776))^sqrt(0.168)+0.864"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.255", ")", "+", "sin", "(", "0.572", ")", "*", "ln", "(", "(", "0.595", "^", "0.595", ")", "^", "(", "0.595", "*", "0.595", ")", ")", "^", "ln", "(", "0.703", ")", "-", "sin", "(", "0.387", ")", "*", "sqrt", "(", "(", "0.876", "-", "0.876", ")", "/", "(", "x", "*", "0.876", ")", ")", "/", "tan", "(", "0.385", ")", "+", "tan", "(", "0.298", ")", "^", "acos", "(", "(", "0.592", "-", "0.592", ")", "/", "(", "x", "-", "0.592", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.255)+sin(0.572)*ln((0.595^0.595)^(0.595*0.595))^ln(0.703)-sin(0.387)*sqrt((0.876-0.876)/(x*0.876))/tan(0.385)+tan(0.298)^acos((0.592-0.592)/(x-0.592))+"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.675", ")", "*", "acos", "(", "0.298", ")", "-", "cos", "(", "(", "0.933", "^", "0.933", ")", "-", "(", "x", "/", "0.933", ")", ")", "*", "log", "(", "0.846", ")", "^", "cos", "(", "0.877", ")", "^", "atan", "(", "(", "0.105", "-", "0.105", ")", "-", "(", "x", "*", "0.105", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.675)*acos(0.298)-cos((0.933^0.933)-(x/0.933))*log(0.846)^cos(0.877)^atan((0.105-0.105)-(x*0.105))-"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "685", "%", "211"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+685%211"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.490", ")", "+", "acos", "(", "0.947", ")", "*", "tan", "(", "(", "0.551", "+", "0.551", ")", "^", "(", "x", "+", "0.551", ")", ")", "-", "sin", "(", "0.322", ")", "+", "cos", "(", "0.148", ")", "^", "ln", "(", "(", "0.873", "-", "0.873", ")", "^", "(", "0.873", "-", "0.873", ")", ")", "^", "sqrt", "(", "0.536", ")", "-", "acos", "(", "0.78", ")", "-", "cos", "(", "(", "0.771", "*", "0.771", ")", "+", "(", "0.685", "+", "0.771", ")", ")", "-", "asin", "(", "0.506", ")", "*", "sqrt", "(", "0.309", ")", "+", "sin", "(", "(", "0.849", "^", "0.849", ")", "+", "(", "x", "-", "0.849", ")", ")", "^", "sqrt", "(", "0.510", ")", "/", "acos", "(", "0.291", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.490)+acos(0.947)*tan((0.551+0.551)^(x+0.551))-sin(0.322)+cos(0.148)^ln((0.873-0.873)^(0.873-0.873))^sqrt(0.536)-acos(0.78)-cos((0.771*0.771)+(0.685+0.771))-asin(0.506)*sqrt(0.309)+sin((0.849^0.849)+(x-0.849))^sqrt(0.510)/acos(0.291)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.605", ")", "-", "tan", "(", "0.485", ")", "+", "cos", "(", "(", "0.855", "*", "0.855", ")", "+", "(", "0.855", "^", "0.855", ")", ")", "/", "sqrt", "(", "0.353", ")", "+", "asin", "(", "0.22", ")", "*", "asin", "(", "(", "0.950", "/", "0.950", ")", "^", "(", "0.950", "-", "0.950", ")", ")", "/", "acos", "(", "0.464", ")", "*", "log", "(", "0.264", ")", "-", "log", "(", "(", "0.738", "/", "0.738", ")", "+", "(", "0.738", "^", "0.738", ")", ")", "*", "sqrt", "(", "0.711", ")", "-", "cos", "(", "0.564", ")", "-", "sqrt", "(", "(", "0.79", "-", "0.79", ")", "-", "(", "0.135", "+", "0.79", ")", ")", "^", "tan", "(", "0.404", ")", "^", "0.469"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.605)-tan(0.485)+cos((0.855*0.855)+(0.855^0.855))/sqrt(0.353)+asin(0.22)*asin((0.950/0.950)^(0.950-0.950))/acos(0.464)*log(0.264)-log((0.738/0.738)+(0.738^0.738))*sqrt(0.711)-cos(0.564)-sqrt((0.79-0.79)-(0.135+0.79))^tan(0.404)^0.469"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.193", ")", "/", "log", "(", "0.855", ")", "-", "acos", "(", "(", "0.926", "+", "0.926", ")", "+", "(", "0.926", "-", "0.926", ")", ")", "/", "acos", "(", "0.329", ")", "/", "0.645"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.193)/log(0.855)-acos((0.926+0.926)+(0.926-0.926))/acos(0.329)/0.645"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.549", ")", "+", "atan", "(", "0.204", ")", "-", "ln", "(", "(", "0.664", "*", "0.664", ")", "/", "(", "0.341", "-", "0.664", ")", ")", "-", "log", "(", "0.278", ")", "*", "log", "(", "0.402", ")", "-", "sin", "(", "(", "0.69", "-", "0.69", ")", "*", "(", "0.893", "+", "0.69", ")", ")", "/", "asin", "(", "0.197", ")", "-", "tan", "(", "0.38", ")", "+", "sqrt", "(", "(", "0.609", "^", "0.609", ")", "+", "(", "0.215", "/", "0.609", ")", ")", "+", "cos", "(", "0.851", ")", "^", "atan", "(", "0.923", ")", "+", "cos", "(", "(", "0.909", "+", "0.909", ")", "^", "(", "0.909", "/", "0.909", ")", ")", "*", "ln", "(", "0.579", ")", "+", "acos", "(", "0.585", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.549)+atan(0.204)-ln((0.664*0.664)/(0.341-0.664))-log(0.278)*log(0.402)-sin((0.69-0.69)*(0.893+0.69))/asin(0.197)-tan(0.38)+sqrt((0.609^0.609)+(0.215/0.609))+cos(0.851)^atan(0.923)+cos((0.909+0.909)^(0.909/0.909))*ln(0.579)+acos(0.585)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.227", ")", "*", "sqrt", "(", "0.213", ")", "/", "sin", "(", "(", "0.127", "*", "0.127", ")", "^", "(", "0.218", "+", "0.127", ")", ")", "^", "sqrt", "(", "0.3", ")", "-", "cos", "(", "0.245", ")", "*", "tan", "(", "(", "0.781", "*", "0.781", ")", "-", "(", "x", "+", "0.781", ")", ")", "+", "asin", "(", "0.925", ")", "/", "acos", "(", "0.408", ")", "*", "cos", "(", "(", "0.757", "*", "0.757", ")", "/", "(", "0.757", "-", "0.757", ")", ")", "*", "atan", "(", "0.673", ")", "/", "ln", "(", "0.150", ")", "/", "acos", "(", "(", "0.414", "-", "0.414", ")", "/", "(", "0.590", "/", "0.414", ")", ")", "-", "sqrt", "(", "0.537", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.227)*sqrt(0.213)/sin((0.127*0.127)^(0.218+0.127))^sqrt(0.3)-cos(0.245)*tan((0.781*0.781)-(x+0.781))+asin(0.925)/acos(0.408)*cos((0.757*0.757)/(0.757-0.757))*atan(0.673)/ln(0.150)/acos((0.414-0.414)/(0.590/0.414))-sqrt(0.537)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.184", ")", "-", "ln", "(", "0.866", ")", "*", "cos", "(", "(", "0.300", "*", "0.300", ")", "+", "(", "0.582", "^", "0.300", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.184)-ln(0.866)*cos((0.300*0.300)+(0.582^0.300))-"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.811", ")", "^", "log", "(", "0.781", ")", "-", "tan", "(", "(", "0.936", "^", "0.936", ")", "^", "(", "0.936", "*", "0.936", ")", ")", "*", "ln", "(", "0.557", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.811)^log(0.781)-tan((0.936^0.936)^(0.936*0.936))*ln(0.557)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.504", ")", "/", "acos", "(", "0.381", ")", "-", "log", "(", "(", "0.935", "-", "0.935", ")", "*", "(", "x", "/", "0.935", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.504)/acos(0.381)-log((0.935-0.935)*(x/0.935))+"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.366", ")", "-", "sin", "(", "0.357", ")", "-", "ln", "(", "(", "0.278", "-", "0.278", ")", "*", "(", "x", "-", "0.278", ")", ")", "*", "tan", "(", "0.709", ")", "+", "acos", "(", "0.782", ")", "^", "acos", "(", "(", "0.492", "-", "0.492", ")", "/", "(", "0.492", "/", "0.492", ")", ")", "*", "sqrt", "(", "0.115", ")", "+", "cos", "(", "0.531", ")", "*", "tan", "(", "(", "0.957", "+", "0.957", ")", "^", "(", "0.616", "-", "0.957", ")", ")", "^", "atan", "(", "0.359", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.366)-sin(0.357)-ln((0.278-0.278)*(x-0.278))*tan(0.709)+acos(0.782)^acos((0.492-0.492)/(0.492/0.492))*sqrt(0.115)+cos(0.531)*tan((0.957+0.957)^(0.616-0.957))^atan(0.359)"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.413", ")", "-", "asin", "(", "0.774", ")", "*", "tan", "(", "(", "0.118", "^", "0.118", ")", "/", "(", "x", "-", "0.118", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.413)-asin(0.774)*tan((0.118^0.118)/(x-0.118))^"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.59", ")", "+", "atan", "(", "0.95", ")", "*", "ln", "(", "(", "0.423", "+", "0.423", ")", "*", "(", "x", "^", "0.423", ")", ")", "+", "acos", "(", "0.443", ")", "/", "acos", "(", "0.422", ")", "-", "cos", "(", "(", "0.15", "+", "0.15", ")", "-", "(", "0.662", "*", "0.15", ")", ")", "-", "sin", "(", "0.561", ")", "*", "log", "(", "0.134", ")", "^", "ln", "(", "(", "0.127", "-", "0.127", ")", "^", "(", "x", "/", "0.127", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.59)+atan(0.95)*ln((0.423+0.423)*(x^0.423))+acos(0.443)/acos(0.422)-cos((0.15+0.15)-(0.662*0.15))-sin(0.561)*log(0.134)^ln((0.127-0.127)^(x/0.127))^"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.167", ")", "*", "atan", "(", "0.544", ")", "*", "acos", "(", "(", "0.819", "^", "0.819", ")", "^", "(", "0.819", "^", "0.819", ")", ")", "+", "asin", "(", "0.624", ")", "+", "cos", "(", "0.671", ")", "*", "cos", "(", "(", "0.248", "^", "0.248", ")", "-", "(", "0.248", "^", "0.248", ")", ")", "/", "atan", "(", "0.321", ")", "+", "0.447"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.167)*atan(0.544)*acos((0.819^0.819)^(0.819^0.819))+asin(0.624)+cos(0.671)*cos((0.248^0.248)-(0.248^0.248))/atan(0.321)+0.447"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.217", ")", "^", "sin", "(", "0.449", ")", "^", "asin", "(", "(", "0.585", "*", "0.585", ")", "+", "(", "0.585", "*", "0.585", ")", ")", "/", "sin", "(", "0.134", ")", "^", "log", "(", "0.842", ")", "/", "log", "(", "(", "0.340", "*", "0.340", ")", "/", "(", "x", "+", "0.340", ")", ")", "^", "acos", "(", "0.293", ")", "+", "asin", "(", "0.62", ")", "+", "acos", "(", "(", "0.678", "/", "0.678", ")", "*", "(", "0.678", "/", "0.678", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.217)^sin(0.449)^asin((0.585*0.585)+(0.585*0.585))/sin(0.134)^log(0.842)/log((0.340*0.340)/(x+0.340))^acos(0.293)+asin(0.62)+acos((0.678/0.678)*(0.678/0.678))+"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.585", ")", "/", "atan", "(", "0.68", ")", "^", "atan", "(", "(", "0.15", "^", "0.15", ")", "^", "(", "0.819", "^", "0.15", ")", ")", "+", "asin", "(", "0.704", ")", "/", "ln", "(", "0.465", ")", "*", "cos", "(", "(", "0.398", "^", "0.398", ")", "/", "(", "0.398", "+", "0.398", ")", ")", "/", "log", "(", "0.0", ")", "^", "acos", "(", "0.872", ")", "-", "atan", "(", "(", "0.334", "*", "0.334", ")", "+", "(", "x", "/", "0.334", ")", ")", "*", "sin", "(", "0.649", ")", "^", "0.302"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.585)/atan(0.68)^atan((0.15^0.15)^(0.819^0.15))+asin(0.704)/ln(0.465)*cos((0.398^0.398)/(0.398+0.398))/log(0.0)^acos(0.872)-atan((0.334*0.334)+(x/0.334))*sin(0.649)^0.302"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.247", ")", "^", "asin", "(", "0.166", ")", "-", "asin", "(", "(", "0.75", "/", "0.75", ")", "+", "(", "0.75", "*", "0.75", ")", ")", "-", "acos", "(", "0.560", ")", "+", "tan", "(", "0.379", ")", "/", "sqrt", "(", "(", "0.564", "+", "0.564", ")", "^", "(", "0.564", "*", "0.564", ")", ")", "-", "cos", "(", "0.382", ")", "*", "asin", "(", "0.177", ")", "/", "sqrt", "(", "(", "0.656", "+", "0.656", ")", "/", "(", "0.656", "*", "0.656", ")", ")", "-", "sqrt", "(", "0.319", ")", "/", "atan", "(", "0.294", ")", "^", "log", "(", "(", "0.719", "+", "0.719", ")", "^", "(", "0.719", "-", "0.719", ")", ")", "*", "acos", "(", "0.406", ")", "+", "sin", "(", "0.537", ")", "+", "log", "(", "(", "0.862", "+", "0.862", ")", "/", "(", "0.862", "/", "0.862", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.247)^asin(0.166)-asin((0.75/0.75)+(0.75*0.75))-acos(0.560)+tan(0.379)/sqrt((0.564+0.564)^(0.564*0.564))-cos(0.382)*asin(0.177)/sqrt((0.656+0.656)/(0.656*0.656))-sqrt(0.319)/atan(0.294)^log((0.719+0.719)^(0.719-0.719))*acos(0.406)+sin(0.537)+log((0.862+0.862)/(0.862/0.862))^"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.111", ")", "*", "cos", "(", "0.218", ")", "/", "atan", "(", "(", "0.513", "^", "0.513", ")", "*", "(", "0.513", "*", "0.513", ")", ")", "-", "tan", "(", "0.208", ")", "+", "sqrt", "(", "0.254", ")", "*", "log", "(", "(", "0.271", "+", "0.271", ")", "-", "(", "0.879", "-", "0.271", ")", ")", "-", "cos", "(", "0.753", ")", "+", "tan", "(", "0.537", ")", "^", "sqrt", "(", "(", "0.798", "-", "0.798", ")", "-", "(", "0.600", "/", "0.798", ")", ")", "-", "cos", "(", "0.642", ")", "+", "sin", "(", "0.328", ")", "^", "cos", "(", "(", "0.942", "/", "0.942", ")", "-", "(", "0.942", "*", "0.942", ")", ")", "*", "atan", "(", "0.195", ")", "-", "ln", "(", "0.684", ")", "/", "log", "(", "(", "0.72", "^", "0.72", ")", "*", "(", "0.890", "*", "0.72", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.111)*cos(0.218)/atan((0.513^0.513)*(0.513*0.513))-tan(0.208)+sqrt(0.254)*log((0.271+0.271)-(0.879-0.271))-cos(0.753)+tan(0.537)^sqrt((0.798-0.798)-(0.600/0.798))-cos(0.642)+sin(0.328)^cos((0.942/0.942)-(0.942*0.942))*atan(0.195)-ln(0.684)/log((0.72^0.72)*(0.890*0.72))*"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.466", ")", "/", "ln", "(", "0.509", ")", "-", "sqrt", "(", "(", "0.983", "*", "0.983", ")", "/", "(", "0.142", "+", "0.983", ")", ")", "-", "cos", "(", "0.70", ")", "-", "asin", "(", "0.258", ")", "^", "log", "(", "(", "0.36", "-", "0.36", ")", "-", "(", "0.36", "^", "0.36", ")", ")", "-", "acos", "(", "0.776", ")", "-", "tan", "(", "0.696", ")", "/", "acos", "(", "(", "0.535", "-", "0.535", ")", "-", "(", "0.956", "-", "0.535", ")", ")", "+", "atan", "(", "0.852", ")", "^", "sqrt", "(", "0.514", ")", "-", "atan", "(", "(", "0.150", "-", "0.150", ")", "-", "(", "x", "*", "0.150", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.466)/ln(0.509)-sqrt((0.983*0.983)/(0.142+0.983))-cos(0.70)-asin(0.258)^log((0.36-0.36)-(0.36^0.36))-acos(0.776)-tan(0.696)/acos((0.535-0.535)-(0.956-0.535))+atan(0.852)^sqrt(0.514)-atan((0.150-0.150)-(x*0.150))/"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.36", ")", "/", "log", "(", "0.28", ")", "^", "atan", "(", "(", "0.826", "/", "0.826", ")", "/", "(", "0.634", "^", "0.826", ")", ")", "*", "log", "(", "0.773", ")", "^", "sqrt", "(", "0.326", ")", "-", "acos", "(", "(", "0.335", "^", "0.335", ")", "/", "(", "0.335", "-", "0.335", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.36)/log(0.28)^atan((0.826/0.826)/(0.634^0.826))*log(0.773)^sqrt(0.326)-acos((0.335^0.335)/(0.335-0.335))^"};
  char *empty = "0.362";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
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
