#include "../header.h"

START_TEST(parser_1) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.11", ")", "^", "ln", "(", "0.122", ")", "*", "tan", "(", "(", "0.898", "*", "0.898", ")", "/", "(", "0.814", "*", "0.898", ")", ")", "/", "acos", "(", "0.997", ")", "/", "atan", "(", "0.651", ")", "+", "tan", "(", "(", "0.932", "+", "0.932", ")", "^", "(", "x", "+", "0.932", ")", ")", "^", "actg", "(", "0.883", ")", "^", "sqrt", "(", "0.846", ")", "-", "acos", "(", "(", "0.552", "-", "0.552", ")", "*", "(", "0.552", "/", "0.552", ")", ")", "*", "acos", "(", "0.133", ")", "-", "log", "(", "0.444", ")", "-", "sqrt", "(", "(", "0.796", "+", "0.796", ")", "/", "(", "0.618", "^", "0.796", ")", ")", "/", "actg", "(", "0.525", ")", "^", "log", "(", "0.683", ")", "*", "tan", "(", "(", "0.718", "*", "0.718", ")", "/", "(", "x", "-", "0.718", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.11)^ln(0.122)*tan((0.898*0.898)/(0.814*0.898))/acos(0.997)/atan(0.651)+tan((0.932+0.932)^(x+0.932))^actg(0.883)^sqrt(0.846)-acos((0.552-0.552)*(0.552/0.552))*acos(0.133)-log(0.444)-sqrt((0.796+0.796)/(0.618^0.796))/actg(0.525)^log(0.683)*tan((0.718*0.718)/(x-0.718))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.412", ")", "*", "acos", "(", "0.440", ")", "^", "acos", "(", "(", "0.323", "+", "0.323", ")", "/", "(", "0.323", "*", "0.323", ")", ")", "^", "acos", "(", "0.711", ")", "*", "ctg", "(", "0.191", ")", "*", "ctg", "(", "(", "0.511", "^", "0.511", ")", "*", "(", "x", "+", "0.511", ")", ")", "^", "tan", "(", "0.736", ")", "*", "asin", "(", "0.920", ")", "+", "ctg", "(", "(", "0.2", "-", "0.2", ")", "*", "(", "0.2", "^", "0.2", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.412)*acos(0.440)^acos((0.323+0.323)/(0.323*0.323))^acos(0.711)*ctg(0.191)*ctg((0.511^0.511)*(x+0.511))^tan(0.736)*asin(0.920)+ctg((0.2-0.2)*(0.2^0.2))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.517", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.517)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.27", ")", "-", "sin", "(", "0.408", ")", "/", "atan", "(", "(", "0.227", "^", "0.227", ")", "/", "(", "0.440", "/", "0.227", ")", ")", "-", "asin", "(", "0.259", ")", "-", "sqrt", "(", "0.581", ")", "^", "tan", "(", "(", "0.699", "-", "0.699", ")", "*", "(", "0.326", "-", "0.699", ")", ")", "/", "asin", "(", "0.889", ")", "/", "ctg", "(", "0.645", ")", "*", "acos", "(", "(", "0.384", "/", "0.384", ")", "^", "(", "0.384", "*", "0.384", ")", ")", "-", "sqrt", "(", "0.29", ")", "/", "tan", "(", "0.406", ")", "+", "cos", "(", "(", "0.613", "^", "0.613", ")", "*", "(", "0.613", "+", "0.613", ")", ")", "*", "cos", "(", "0.267", ")", "^", "tan", "(", "0.195", ")", "^", "acos", "(", "(", "0.791", "/", "0.791", ")", "-", "(", "0.512", "+", "0.791", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.27)-sin(0.408)/atan((0.227^0.227)/(0.440/0.227))-asin(0.259)-sqrt(0.581)^tan((0.699-0.699)*(0.326-0.699))/asin(0.889)/ctg(0.645)*acos((0.384/0.384)^(0.384*0.384))-sqrt(0.29)/tan(0.406)+cos((0.613^0.613)*(0.613+0.613))*cos(0.267)^tan(0.195)^acos((0.791/0.791)-(0.512+0.791))*"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.391", ")", "-", "ctg", "(", "0.13", ")", "/", "sqrt", "(", "(", "0.392", "*", "0.392", ")", "/", "(", "0.553", "^", "0.392", ")", ")", "^", "asin", "(", "0.398", ")", "+", "asin", "(", "0.415", ")", "+", "log", "(", "(", "0.254", "-", "0.254", ")", "+", "(", "0.254", "^", "0.254", ")", ")", "-", "actg", "(", "0.644", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.391)-ctg(0.13)/sqrt((0.392*0.392)/(0.553^0.392))^asin(0.398)+asin(0.415)+log((0.254-0.254)+(0.254^0.254))-actg(0.644)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.660", ")", "/", "cos", "(", "0.740", ")", "/", "actg", "(", "(", "0.454", "^", "0.454", ")", "*", "(", "x", "+", "0.454", ")", ")", "*", "cos", "(", "0.383", ")", "/", "tan", "(", "0.808", ")", "+", "cos", "(", "(", "0.879", "-", "0.879", ")", "*", "(", "x", "*", "0.879", ")", ")", "/", "log", "(", "0.794", ")", "+", "cos", "(", "0.526", ")", "^", "sqrt", "(", "(", "0.905", "*", "0.905", ")", "^", "(", "0.905", "/", "0.905", ")", ")", "/", "ctg", "(", "0.340", ")", "-", "log", "(", "0.859", ")", "/", "log", "(", "(", "0.801", "-", "0.801", ")", "+", "(", "0.801", "^", "0.801", ")", ")", "-", "ln", "(", "0.720", ")", "*", "acos", "(", "0.583", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.660)/cos(0.740)/actg((0.454^0.454)*(x+0.454))*cos(0.383)/tan(0.808)+cos((0.879-0.879)*(x*0.879))/log(0.794)+cos(0.526)^sqrt((0.905*0.905)^(0.905/0.905))/ctg(0.340)-log(0.859)/log((0.801-0.801)+(0.801^0.801))-ln(0.720)*acos(0.583)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.303", ")", "/", "acos", "(", "0.68", ")", "^", "acos", "(", "(", "0.571", "*", "0.571", ")", "-", "(", "0.571", "+", "0.571", ")", ")", "+", "actg", "(", "0.584", ")", "/", "actg", "(", "0.723", ")", "/", "ctg", "(", "(", "0.323", "+", "0.323", ")", "-", "(", "0.323", "^", "0.323", ")", ")", "*", "actg", "(", "0.56", ")", "/", "tan", "(", "0.529", ")", "*", "ln", "(", "(", "0.845", "/", "0.845", ")", "*", "(", "0.845", "*", "0.845", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.303)/acos(0.68)^acos((0.571*0.571)-(0.571+0.571))+actg(0.584)/actg(0.723)/ctg((0.323+0.323)-(0.323^0.323))*actg(0.56)/tan(0.529)*ln((0.845/0.845)*(0.845*0.845))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.104", ")", "+", "cos", "(", "0.354", ")", "/", "actg", "(", "(", "0.660", "/", "0.660", ")", "-", "(", "x", "-", "0.660", ")", ")", "+", "ln", "(", "0.730", ")", "+", "0.563"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.104)+cos(0.354)/actg((0.660/0.660)-(x-0.660))+ln(0.730)+0.563"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.619", ")", "*", "actg", "(", "0.979", ")", "-", "acos", "(", "(", "0.717", "/", "0.717", ")", "-", "(", "0.708", "^", "0.717", ")", ")", "/", "log", "(", "0.706", ")", "^", "sin", "(", "0.309", ")", "/", "sin", "(", "(", "0.355", "+", "0.355", ")", "^", "(", "0.5", "^", "0.355", ")", ")", "^", "acos", "(", "0.259", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.619)*actg(0.979)-acos((0.717/0.717)-(0.708^0.717))/log(0.706)^sin(0.309)/sin((0.355+0.355)^(0.5^0.355))^acos(0.259)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.59", ")", "+", "0.901"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.59)+0.901"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.91", ")", "+", "tan", "(", "0.344", ")", "/", "cos", "(", "(", "0.886", "+", "0.886", ")", "^", "(", "0.378", "+", "0.886", ")", ")", "^", "ln", "(", "0.510", ")", "*", "sin", "(", "0.242", ")", "+", "atan", "(", "(", "0.84", "^", "0.84", ")", "-", "(", "0.736", "-", "0.84", ")", ")", "^", "ln", "(", "0.44", ")", "^", "0.464"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.91)+tan(0.344)/cos((0.886+0.886)^(0.378+0.886))^ln(0.510)*sin(0.242)+atan((0.84^0.84)-(0.736-0.84))^ln(0.44)^0.464"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.43", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.43)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.749", ")", "*", "log", "(", "0.290", ")", "-", "acos", "(", "(", "0.97", "^", "0.97", ")", "-", "(", "0.851", "-", "0.97", ")", ")", "^", "sin", "(", "0.807", ")", "+", "cos", "(", "0.847", ")", "*", "asin", "(", "(", "0.797", "*", "0.797", ")", "/", "(", "0.514", "+", "0.797", ")", ")", "-", "atan", "(", "0.730", ")", "*", "asin", "(", "0.127", ")", "+", "sqrt", "(", "(", "0.111", "+", "0.111", ")", "+", "(", "x", "*", "0.111", ")", ")", "^", "tan", "(", "0.721", ")", "-", "atan", "(", "0.967", ")", "-", "tan", "(", "(", "0.669", "-", "0.669", ")", "-", "(", "x", "^", "0.669", ")", ")", "^", "asin", "(", "0.450", ")", "^", "0.119"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.749)*log(0.290)-acos((0.97^0.97)-(0.851-0.97))^sin(0.807)+cos(0.847)*asin((0.797*0.797)/(0.514+0.797))-atan(0.730)*asin(0.127)+sqrt((0.111+0.111)+(x*0.111))^tan(0.721)-atan(0.967)-tan((0.669-0.669)-(x^0.669))^asin(0.450)^0.119"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.90", ")", "^", "atan", "(", "0.686", ")", "*", "actg", "(", "(", "0.663", "+", "0.663", ")", "*", "(", "0.663", "^", "0.663", ")", ")", "-", "acos", "(", "0.750", ")", "+", "ctg", "(", "0.631", ")", "*", "sin", "(", "(", "0.47", "+", "0.47", ")", "*", "(", "x", "/", "0.47", ")", ")", "/", "sqrt", "(", "0.779", ")", "^", "tan", "(", "0.175", ")", "^", "asin", "(", "(", "0.256", "/", "0.256", ")", "*", "(", "x", "/", "0.256", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.90)^atan(0.686)*actg((0.663+0.663)*(0.663^0.663))-acos(0.750)+ctg(0.631)*sin((0.47+0.47)*(x/0.47))/sqrt(0.779)^tan(0.175)^asin((0.256/0.256)*(x/0.256))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.435", ")", "*", "sin", "(", "0.851", ")", "/", "log", "(", "(", "0.237", "/", "0.237", ")", "*", "(", "x", "/", "0.237", ")", ")", "-", "actg", "(", "0.624", ")", "+", "ln", "(", "0.685", ")", "+", "sqrt", "(", "(", "0.988", "-", "0.988", ")", "^", "(", "x", "+", "0.988", ")", ")", "-", "atan", "(", "0.651", ")", "^", "actg", "(", "0.645", ")", "^", "tan", "(", "(", "0.713", "^", "0.713", ")", "-", "(", "0.713", "*", "0.713", ")", ")", "-", "sin", "(", "0.711", ")", "-", "atan", "(", "0.444", ")", "-", "acos", "(", "(", "0.985", "+", "0.985", ")", "+", "(", "0.985", "-", "0.985", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.435)*sin(0.851)/log((0.237/0.237)*(x/0.237))-actg(0.624)+ln(0.685)+sqrt((0.988-0.988)^(x+0.988))-atan(0.651)^actg(0.645)^tan((0.713^0.713)-(0.713*0.713))-sin(0.711)-atan(0.444)-acos((0.985+0.985)+(0.985-0.985))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.466", ")", "+", "asin", "(", "0.762", ")", "*", "sqrt", "(", "(", "0.564", "-", "0.564", ")", "*", "(", "0.947", "-", "0.564", ")", ")", "*", "tan", "(", "0.357", ")", "*", "atan", "(", "0.35", ")", "-", "acos", "(", "(", "0.195", "+", "0.195", ")", "+", "(", "0.357", "*", "0.195", ")", ")", "^", "sqrt", "(", "0.937", ")", "^", "tan", "(", "0.973", ")", "*", "log", "(", "(", "0.556", "*", "0.556", ")", "+", "(", "x", "*", "0.556", ")", ")", "-", "log", "(", "0.15", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.466)+asin(0.762)*sqrt((0.564-0.564)*(0.947-0.564))*tan(0.357)*atan(0.35)-acos((0.195+0.195)+(0.357*0.195))^sqrt(0.937)^tan(0.973)*log((0.556*0.556)+(x*0.556))-log(0.15)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.497", ")", "/", "acos", "(", "0.995", ")", "*", "ln", "(", "(", "0.709", "/", "0.709", ")", "+", "(", "0.709", "+", "0.709", ")", ")", "-", "atan", "(", "0.803", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.497)/acos(0.995)*ln((0.709/0.709)+(0.709+0.709))-atan(0.803)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.20", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.20)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.73", ")", "*", "ctg", "(", "0.212", ")", "^", "sqrt", "(", "(", "0.739", "^", "0.739", ")", "-", "(", "0.739", "/", "0.739", ")", ")", "-", "log", "(", "0.163", ")", "*", "0.574"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.73)*ctg(0.212)^sqrt((0.739^0.739)-(0.739/0.739))-log(0.163)*0.574"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.298", ")", "-", "acos", "(", "0.429", ")", "^", "sqrt", "(", "(", "0.481", "/", "0.481", ")", "^", "(", "0.481", "-", "0.481", ")", ")", "^", "sqrt", "(", "0.130", ")", "-", "acos", "(", "0.99", ")", "*", "cos", "(", "(", "0.924", "/", "0.924", ")", "+", "(", "0.199", "-", "0.924", ")", ")", "*", "atan", "(", "0.733", ")", "*", "actg", "(", "0.198", ")", "-", "atan", "(", "(", "0.378", "^", "0.378", ")", "^", "(", "x", "*", "0.378", ")", ")", "^", "asin", "(", "0.227", ")", "/", "cos", "(", "0.120", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.298)-acos(0.429)^sqrt((0.481/0.481)^(0.481-0.481))^sqrt(0.130)-acos(0.99)*cos((0.924/0.924)+(0.199-0.924))*atan(0.733)*actg(0.198)-atan((0.378^0.378)^(x*0.378))^asin(0.227)/cos(0.120)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.480", ")", "/", "actg", "(", "0.662", ")", "+", "sqrt", "(", "(", "0.792", "^", "0.792", ")", "/", "(", "x", "^", "0.792", ")", ")", "^", "cos", "(", "0.469", ")", "*", "sin", "(", "0.787", ")", "/", "acos", "(", "(", "0.406", "+", "0.406", ")", "*", "(", "0.573", "*", "0.406", ")", ")", "^", "log", "(", "0.722", ")", "/", "0.559"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.480)/actg(0.662)+sqrt((0.792^0.792)/(x^0.792))^cos(0.469)*sin(0.787)/acos((0.406+0.406)*(0.573*0.406))^log(0.722)/0.559"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.718", ")", "*", "ctg", "(", "0.438", ")", "*", "actg", "(", "(", "0.101", "+", "0.101", ")", "^", "(", "0.665", "^", "0.101", ")", ")", "-", "sin", "(", "0.956", ")", "-", "sin", "(", "0.113", ")", "+", "sqrt", "(", "(", "0.167", "^", "0.167", ")", "^", "(", "0.339", "+", "0.167", ")", ")", "-", "asin", "(", "0.286", ")", "/", "asin", "(", "0.147", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.718)*ctg(0.438)*actg((0.101+0.101)^(0.665^0.101))-sin(0.956)-sin(0.113)+sqrt((0.167^0.167)^(0.339+0.167))-asin(0.286)/asin(0.147)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.755", ")", "^", "cos", "(", "0.674", ")", "^", "log", "(", "(", "0.614", "+", "0.614", ")", "+", "(", "x", "+", "0.614", ")", ")", "+", "atan", "(", "0.401", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.755)^cos(0.674)^log((0.614+0.614)+(x+0.614))+atan(0.401)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.522", ")", "/", "cos", "(", "0.106", ")", "/", "ctg", "(", "(", "0.428", "^", "0.428", ")", "+", "(", "x", "*", "0.428", ")", ")", "+", "log", "(", "0.554", ")", "-", "acos", "(", "0.219", ")", "^", "ctg", "(", "(", "0.902", "-", "0.902", ")", "/", "(", "0.0", "/", "0.902", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.522)/cos(0.106)/ctg((0.428^0.428)+(x*0.428))+log(0.554)-acos(0.219)^ctg((0.902-0.902)/(0.0/0.902))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.454", ")", "+", "sin", "(", "0.794", ")", "^", "log", "(", "(", "0.137", "/", "0.137", ")", "+", "(", "0.137", "/", "0.137", ")", ")", "/", "sin", "(", "0.459", ")", "/", "tan", "(", "0.802", ")", "+", "actg", "(", "(", "0.779", "-", "0.779", ")", "-", "(", "0.739", "-", "0.779", ")", ")", "+", "sqrt", "(", "0.613", ")", "+", "sqrt", "(", "0.578", ")", "^", "asin", "(", "(", "0.777", "*", "0.777", ")", "-", "(", "x", "*", "0.777", ")", ")", "*", "atan", "(", "0.657", ")", "^", "cos", "(", "0.156", ")", "/", "ctg", "(", "(", "0.49", "/", "0.49", ")", "-", "(", "0.49", "^", "0.49", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.454)+sin(0.794)^log((0.137/0.137)+(0.137/0.137))/sin(0.459)/tan(0.802)+actg((0.779-0.779)-(0.739-0.779))+sqrt(0.613)+sqrt(0.578)^asin((0.777*0.777)-(x*0.777))*atan(0.657)^cos(0.156)/ctg((0.49/0.49)-(0.49^0.49))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.460", ")", "-", "actg", "(", "0.517", ")", "-", "cos", "(", "(", "0.502", "*", "0.502", ")", "+", "(", "0.502", "+", "0.502", ")", ")", "+", "cos", "(", "0.529", ")", "/", "asin", "(", "0.261", ")", "+", "cos", "(", "(", "0.371", "*", "0.371", ")", "-", "(", "x", "+", "0.371", ")", ")", "^", "actg", "(", "0.89", ")", "+", "ctg", "(", "0.936", ")", "/", "log", "(", "(", "0.332", "+", "0.332", ")", "+", "(", "0.678", "-", "0.332", ")", ")", "*", "sin", "(", "0.361", ")", "+", "cos", "(", "0.468", ")", "/", "sin", "(", "(", "0.105", "+", "0.105", ")", "*", "(", "0.105", "*", "0.105", ")", ")", "/", "actg", "(", "0.534", ")", "/", "atan", "(", "0.780", ")", "-", "actg", "(", "(", "0.80", "/", "0.80", ")", "*", "(", "x", "/", "0.80", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.460)-actg(0.517)-cos((0.502*0.502)+(0.502+0.502))+cos(0.529)/asin(0.261)+cos((0.371*0.371)-(x+0.371))^actg(0.89)+ctg(0.936)/log((0.332+0.332)+(0.678-0.332))*sin(0.361)+cos(0.468)/sin((0.105+0.105)*(0.105*0.105))/actg(0.534)/atan(0.780)-actg((0.80/0.80)*(x/0.80))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.256", ")", "+", "sqrt", "(", "0.286", ")", "^", "log", "(", "(", "0.85", "^", "0.85", ")", "/", "(", "0.68", "/", "0.85", ")", ")", "^", "log", "(", "0.364", ")", "^", "sqrt", "(", "0.111", ")", "+", "ln", "(", "(", "0.699", "*", "0.699", ")", "-", "(", "x", "+", "0.699", ")", ")", "*", "asin", "(", "0.647", ")", "/", "ln", "(", "0.743", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.256)+sqrt(0.286)^log((0.85^0.85)/(0.68/0.85))^log(0.364)^sqrt(0.111)+ln((0.699*0.699)-(x+0.699))*asin(0.647)/ln(0.743)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.741", ")", "-", "acos", "(", "0.916", ")", "^", "sin", "(", "(", "0.159", "/", "0.159", ")", "+", "(", "x", "/", "0.159", ")", ")", "+", "sqrt", "(", "0.872", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.741)-acos(0.916)^sin((0.159/0.159)+(x/0.159))+sqrt(0.872)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.447", ")", "*", "cos", "(", "0.910", ")", "+", "sin", "(", "(", "0.556", "/", "0.556", ")", "/", "(", "0.556", "*", "0.556", ")", ")", "*", "log", "(", "0.684", ")", "+", "sqrt", "(", "0.500", ")", "/", "log", "(", "(", "0.275", "/", "0.275", ")", "-", "(", "0.275", "/", "0.275", ")", ")", "+", "cos", "(", "0.511", ")", "+", "log", "(", "0.217", ")", "-", "ctg", "(", "(", "0.382", "/", "0.382", ")", "+", "(", "x", "+", "0.382", ")", ")", "+", "acos", "(", "0.134", ")", "^", "sqrt", "(", "0.885", ")", "-", "cos", "(", "(", "0.467", "*", "0.467", ")", "+", "(", "0.641", "-", "0.467", ")", ")", "^", "atan", "(", "0.232", ")", "+", "acos", "(", "0.656", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.447)*cos(0.910)+sin((0.556/0.556)/(0.556*0.556))*log(0.684)+sqrt(0.500)/log((0.275/0.275)-(0.275/0.275))+cos(0.511)+log(0.217)-ctg((0.382/0.382)+(x+0.382))+acos(0.134)^sqrt(0.885)-cos((0.467*0.467)+(0.641-0.467))^atan(0.232)+acos(0.656)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.179", ")", "/", "0.479"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.179)/0.479"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.514", ")", "/", "sqrt", "(", "0.860", ")", "-", "atan", "(", "(", "0.133", "/", "0.133", ")", "^", "(", "0.740", "-", "0.133", ")", ")", "*", "ln", "(", "0.978", ")", "*", "asin", "(", "0.36", ")", "/", "actg", "(", "(", "0.31", "-", "0.31", ")", "*", "(", "x", "*", "0.31", ")", ")", "+", "sin", "(", "0.257", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.514)/sqrt(0.860)-atan((0.133/0.133)^(0.740-0.133))*ln(0.978)*asin(0.36)/actg((0.31-0.31)*(x*0.31))+sin(0.257)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.712", ")", "^", "actg", "(", "0.918", ")", "^", "ctg", "(", "(", "0.974", "*", "0.974", ")", "^", "(", "0.974", "/", "0.974", ")", ")", "*", "acos", "(", "0.153", ")", "-", "actg", "(", "0.240", ")", "+", "ln", "(", "(", "0.13", "*", "0.13", ")", "*", "(", "0.13", "-", "0.13", ")", ")", "^", "tan", "(", "0.121", ")", "*", "tan", "(", "0.258", ")", "+", "atan", "(", "(", "0.482", "-", "0.482", ")", "/", "(", "0.482", "+", "0.482", ")", ")", "+", "sin", "(", "0.516", ")", "^", "tan", "(", "0.151", ")", "^", "asin", "(", "(", "0.54", "^", "0.54", ")", "+", "(", "x", "^", "0.54", ")", ")", "/", "cos", "(", "0.285", ")", "^", "actg", "(", "0.857", ")", "+", "ctg", "(", "(", "0.579", "-", "0.579", ")", "^", "(", "x", "-", "0.579", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.712)^actg(0.918)^ctg((0.974*0.974)^(0.974/0.974))*acos(0.153)-actg(0.240)+ln((0.13*0.13)*(0.13-0.13))^tan(0.121)*tan(0.258)+atan((0.482-0.482)/(0.482+0.482))+sin(0.516)^tan(0.151)^asin((0.54^0.54)+(x^0.54))/cos(0.285)^actg(0.857)+ctg((0.579-0.579)^(x-0.579))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.796", ")", "-", "asin", "(", "0.503", ")", "-", "log", "(", "(", "0.528", "*", "0.528", ")", "^", "(", "x", "+", "0.528", ")", ")", "+", "asin", "(", "0.57", ")", "/", "ctg", "(", "0.814", ")", "/", "atan", "(", "(", "0.203", "^", "0.203", ")", "*", "(", "x", "/", "0.203", ")", ")", "/", "sqrt", "(", "0.280", ")", "^", "ln", "(", "0.21", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.796)-asin(0.503)-log((0.528*0.528)^(x+0.528))+asin(0.57)/ctg(0.814)/atan((0.203^0.203)*(x/0.203))/sqrt(0.280)^ln(0.21)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.934", ")", "^", "tan", "(", "0.867", ")", "^", "sqrt", "(", "(", "0.254", "^", "0.254", ")", "*", "(", "0.314", "*", "0.254", ")", ")", "/", "sin", "(", "0.682", ")", "^", "log", "(", "0.107", ")", "*", "tan", "(", "(", "0.821", "*", "0.821", ")", "^", "(", "0.574", "-", "0.821", ")", ")", "^", "acos", "(", "0.109", ")", "*", "log", "(", "0.289", ")", "+", "ctg", "(", "(", "0.611", "^", "0.611", ")", "^", "(", "0.611", "/", "0.611", ")", ")", "/", "acos", "(", "0.433", ")", "^", "actg", "(", "0.610", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.934)^tan(0.867)^sqrt((0.254^0.254)*(0.314*0.254))/sin(0.682)^log(0.107)*tan((0.821*0.821)^(0.574-0.821))^acos(0.109)*log(0.289)+ctg((0.611^0.611)^(0.611/0.611))/acos(0.433)^actg(0.610)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.50", ")", "+", "0.286"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.50)+0.286"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.252", ")", "*", "acos", "(", "0.239", ")", "+", "log", "(", "(", "0.820", "/", "0.820", ")", "/", "(", "0.820", "+", "0.820", ")", ")", "*", "atan", "(", "0.46", ")", "-", "ln", "(", "0.778", ")", "+", "log", "(", "(", "0.777", "/", "0.777", ")", "^", "(", "0.523", "/", "0.777", ")", ")", "/", "cos", "(", "0.24", ")", "^", "sin", "(", "0.187", ")", "/", "ctg", "(", "(", "0.909", "-", "0.909", ")", "^", "(", "x", "-", "0.909", ")", ")", "+", "asin", "(", "0.741", ")", "+", "sqrt", "(", "0.475", ")", "/", "ctg", "(", "(", "0.464", "^", "0.464", ")", "^", "(", "0.689", "^", "0.464", ")", ")", "^", "sin", "(", "0.598", ")", "/", "cos", "(", "0.289", ")", "-", "actg", "(", "(", "0.104", "/", "0.104", ")", "*", "(", "x", "*", "0.104", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.252)*acos(0.239)+log((0.820/0.820)/(0.820+0.820))*atan(0.46)-ln(0.778)+log((0.777/0.777)^(0.523/0.777))/cos(0.24)^sin(0.187)/ctg((0.909-0.909)^(x-0.909))+asin(0.741)+sqrt(0.475)/ctg((0.464^0.464)^(0.689^0.464))^sin(0.598)/cos(0.289)-actg((0.104/0.104)*(x*0.104))*"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.406", ")", "^", "0.64"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.406)^0.64"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.606", ")", "*", "ctg", "(", "0.844", ")", "+", "log", "(", "(", "0.325", "-", "0.325", ")", "-", "(", "0.325", "*", "0.325", ")", ")", "-", "atan", "(", "0.660", ")", "-", "ctg", "(", "0.685", ")", "-", "tan", "(", "(", "0.507", "/", "0.507", ")", "-", "(", "0.507", "/", "0.507", ")", ")", "-", "sqrt", "(", "0.135", ")", "+", "atan", "(", "0.318", ")", "-", "tan", "(", "(", "0.872", "*", "0.872", ")", "+", "(", "0.872", "/", "0.872", ")", ")", "/", "actg", "(", "0.129", ")", "^", "ctg", "(", "0.518", ")", "^", "sqrt", "(", "(", "0.254", "*", "0.254", ")", "^", "(", "0.565", "+", "0.254", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.606)*ctg(0.844)+log((0.325-0.325)-(0.325*0.325))-atan(0.660)-ctg(0.685)-tan((0.507/0.507)-(0.507/0.507))-sqrt(0.135)+atan(0.318)-tan((0.872*0.872)+(0.872/0.872))/actg(0.129)^ctg(0.518)^sqrt((0.254*0.254)^(0.565+0.254))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.911", ")", "/", "ctg", "(", "0.169", ")", "-", "actg", "(", "(", "0.943", "+", "0.943", ")", "+", "(", "0.108", "/", "0.943", ")", ")", "+", "sqrt", "(", "0.836", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.911)/ctg(0.169)-actg((0.943+0.943)+(0.108/0.943))+sqrt(0.836)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.233", ")", "+", "sin", "(", "0.17", ")", "+", "actg", "(", "(", "0.508", "^", "0.508", ")", "^", "(", "0.508", "/", "0.508", ")", ")", "/", "acos", "(", "0.29", ")", "+", "sin", "(", "0.540", ")", "-", "actg", "(", "(", "0.20", "-", "0.20", ")", "/", "(", "0.20", "+", "0.20", ")", ")", "^"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.233)+sin(0.17)+actg((0.508^0.508)^(0.508/0.508))/acos(0.29)+sin(0.540)-actg((0.20-0.20)/(0.20+0.20))^"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.673", ")", "/", "atan", "(", "0.397", ")", "/", "actg", "(", "(", "0.117", "/", "0.117", ")", "+", "(", "0.117", "^", "0.117", ")", ")", "^", "atan", "(", "0.238", ")", "+", "asin", "(", "0.50", ")", "+", "sqrt", "(", "(", "0.175", "/", "0.175", ")", "-", "(", "0.447", "^", "0.175", ")", ")", "/", "log", "(", "0.690", ")", "-", "0.767"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.673)/atan(0.397)/actg((0.117/0.117)+(0.117^0.117))^atan(0.238)+asin(0.50)+sqrt((0.175/0.175)-(0.447^0.175))/log(0.690)-0.767"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.704", ")", "*", "tan", "(", "0.534", ")", "/", "asin", "(", "(", "0.442", "/", "0.442", ")", "+", "(", "0.442", "-", "0.442", ")", ")", "/", "sqrt", "(", "0.795", ")", "^", "asin", "(", "0.974", ")", "*", "atan", "(", "(", "0.372", "-", "0.372", ")", "+", "(", "x", "+", "0.372", ")", ")", "-", "actg", "(", "0.12", ")", "*", "tan", "(", "0.84", ")", "-", "log", "(", "(", "0.313", "/", "0.313", ")", "/", "(", "x", "^", "0.313", ")", ")", "-", "ln", "(", "0.656", ")", "/", "ln", "(", "0.736", ")", "^", "acos", "(", "(", "0.458", "+", "0.458", ")", "*", "(", "x", "*", "0.458", ")", ")", "+", "actg", "(", "0.323", ")", "/", "acos", "(", "0.504", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.704)*tan(0.534)/asin((0.442/0.442)+(0.442-0.442))/sqrt(0.795)^asin(0.974)*atan((0.372-0.372)+(x+0.372))-actg(0.12)*tan(0.84)-log((0.313/0.313)/(x^0.313))-ln(0.656)/ln(0.736)^acos((0.458+0.458)*(x*0.458))+actg(0.323)/acos(0.504)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.338", ")", "+", "sin", "(", "0.829", ")", "/", "tan", "(", "(", "0.144", "+", "0.144", ")", "-", "(", "0.26", "+", "0.144", ")", ")", "-", "acos", "(", "0.134", ")", "^", "atan", "(", "0.705", ")", "/", "sqrt", "(", "(", "0.410", "/", "0.410", ")", "-", "(", "0.316", "^", "0.410", ")", ")", "*", "tan", "(", "0.399", ")", "*", "ln", "(", "0.415", ")", "+", "sin", "(", "(", "0.48", "*", "0.48", ")", "^", "(", "0.142", "*", "0.48", ")", ")", "/", "cos", "(", "0.45", ")", "*", "asin", "(", "0.178", ")", "/", "cos", "(", "(", "0.179", "-", "0.179", ")", "*", "(", "x", "/", "0.179", ")", ")", "/", "atan", "(", "0.888", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.338)+sin(0.829)/tan((0.144+0.144)-(0.26+0.144))-acos(0.134)^atan(0.705)/sqrt((0.410/0.410)-(0.316^0.410))*tan(0.399)*ln(0.415)+sin((0.48*0.48)^(0.142*0.48))/cos(0.45)*asin(0.178)/cos((0.179-0.179)*(x/0.179))/atan(0.888)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.336", ")", "+", "acos", "(", "0.919", ")", "^", "atan", "(", "(", "0.424", "-", "0.424", ")", "^", "(", "0.424", "-", "0.424", ")", ")", "-", "sqrt", "(", "0.577", ")", "^", "cos", "(", "0.378", ")", "/", "sin", "(", "(", "0.716", "/", "0.716", ")", "+", "(", "x", "-", "0.716", ")", ")", "+", "atan", "(", "0.45", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.336)+acos(0.919)^atan((0.424-0.424)^(0.424-0.424))-sqrt(0.577)^cos(0.378)/sin((0.716/0.716)+(x-0.716))+atan(0.45)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "734", "%", "718"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+734%718"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.635", ")", "-", "acos", "(", "0.344", ")", "*", "sqrt", "(", "(", "0.799", "*", "0.799", ")", "^", "(", "x", "-", "0.799", ")", ")", "-", "sin", "(", "0.622", ")", "-", "0.822"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.635)-acos(0.344)*sqrt((0.799*0.799)^(x-0.799))-sin(0.622)-0.822"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.79", ")", "*", "ctg", "(", "0.677", ")", "/", "sin", "(", "(", "0.440", "+", "0.440", ")", "+", "(", "0.213", "/", "0.440", ")", ")", "/", "ln", "(", "0.135", ")", "-", "sqrt", "(", "0.302", ")", "*", "asin", "(", "(", "0.138", "/", "0.138", ")", "^", "(", "0.251", "-", "0.138", ")", ")", "/", "sin", "(", "0.4", ")", "-", "atan", "(", "0.952", ")", "+", "tan", "(", "(", "0.302", "/", "0.302", ")", "*", "(", "0.302", "/", "0.302", ")", ")", "+", "asin", "(", "0.232", ")", "-", "ctg", "(", "0.560", ")", "-", "ln", "(", "(", "0.794", "-", "0.794", ")", "-", "(", "x", "+", "0.794", ")", ")", "*", "acos", "(", "0.266", ")", "+", "actg", "(", "0.535", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.79)*ctg(0.677)/sin((0.440+0.440)+(0.213/0.440))/ln(0.135)-sqrt(0.302)*asin((0.138/0.138)^(0.251-0.138))/sin(0.4)-atan(0.952)+tan((0.302/0.302)*(0.302/0.302))+asin(0.232)-ctg(0.560)-ln((0.794-0.794)-(x+0.794))*acos(0.266)+actg(0.535)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.907", ")", "^", "ctg", "(", "0.844", ")", "*", "ln", "(", "(", "0.879", "*", "0.879", ")", "+", "(", "x", "*", "0.879", ")", ")", "^", "log", "(", "0.531", ")", "^", "tan", "(", "0.355", ")", "+", "ln", "(", "(", "0.100", "-", "0.100", ")", "/", "(", "0.100", "^", "0.100", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.907)^ctg(0.844)*ln((0.879*0.879)+(x*0.879))^log(0.531)^tan(0.355)+ln((0.100-0.100)/(0.100^0.100))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.132", ")", "*", "sin", "(", "0.694", ")", "-", "asin", "(", "(", "0.156", "-", "0.156", ")", "^", "(", "x", "*", "0.156", ")", ")", "*", "sqrt", "(", "0.518", ")", "^", "actg", "(", "0.757", ")", "/", "tan", "(", "(", "0.594", "*", "0.594", ")", "/", "(", "x", "*", "0.594", ")", ")", "/", "tan", "(", "0.701", ")", "/", "actg", "(", "0.225", ")", "*", "actg", "(", "(", "0.477", "/", "0.477", ")", "^", "(", "0.449", "*", "0.477", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.132)*sin(0.694)-asin((0.156-0.156)^(x*0.156))*sqrt(0.518)^actg(0.757)/tan((0.594*0.594)/(x*0.594))/tan(0.701)/actg(0.225)*actg((0.477/0.477)^(0.449*0.477))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "253", "%", "568"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+253%568"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.877", ")", "-", "sqrt", "(", "0.471", ")", "+", "sqrt", "(", "(", "0.435", "+", "0.435", ")", "*", "(", "0.435", "-", "0.435", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.877)-sqrt(0.471)+sqrt((0.435+0.435)*(0.435-0.435))*"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.481", ")", "/", "log", "(", "0.190", ")", "^", "sin", "(", "(", "0.988", "/", "0.988", ")", "-", "(", "x", "*", "0.988", ")", ")", "^", "sin", "(", "0.452", ")", "*", "ln", "(", "0.828", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.481)/log(0.190)^sin((0.988/0.988)-(x*0.988))^sin(0.452)*ln(0.828)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.841", ")", "+", "cos", "(", "0.166", ")", "/", "asin", "(", "(", "0.942", "-", "0.942", ")", "-", "(", "0.430", "-", "0.942", ")", ")", "^", "tan", "(", "0.267", ")", "^", "actg", "(", "0.528", ")", "/", "atan", "(", "(", "0.303", "/", "0.303", ")", "^", "(", "x", "+", "0.303", ")", ")", "-", "sin", "(", "0.532", ")", "*", "tan", "(", "0.304", ")", "/", "actg", "(", "(", "0.104", "/", "0.104", ")", "^", "(", "0.104", "*", "0.104", ")", ")", "/", "atan", "(", "0.921", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.841)+cos(0.166)/asin((0.942-0.942)-(0.430-0.942))^tan(0.267)^actg(0.528)/atan((0.303/0.303)^(x+0.303))-sin(0.532)*tan(0.304)/actg((0.104/0.104)^(0.104*0.104))/atan(0.921)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.633", ")", "+", "log", "(", "0.546", ")", "+", "acos", "(", "(", "0.676", "-", "0.676", ")", "-", "(", "0.676", "^", "0.676", ")", ")", "*", "cos", "(", "0.490", ")", "*", "sqrt", "(", "0.319", ")", "*", "acos", "(", "(", "0.474", "-", "0.474", ")", "+", "(", "0.919", "^", "0.474", ")", ")", "/", "atan", "(", "0.859", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.633)+log(0.546)+acos((0.676-0.676)-(0.676^0.676))*cos(0.490)*sqrt(0.319)*acos((0.474-0.474)+(0.919^0.474))/atan(0.859)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.687", ")", "/", "ln", "(", "0.540", ")", "^", "acos", "(", "(", "0.803", "^", "0.803", ")", "/", "(", "0.699", "/", "0.803", ")", ")", "*", "ln", "(", "0.493", ")", "+", "ln", "(", "0.507", ")", "/", "actg", "(", "(", "0.37", "*", "0.37", ")", "/", "(", "0.37", "+", "0.37", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.687)/ln(0.540)^acos((0.803^0.803)/(0.699/0.803))*ln(0.493)+ln(0.507)/actg((0.37*0.37)/(0.37+0.37))*"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.639", ")", "*", "0.852"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.639)*0.852"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.613", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.613)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.433", ")", "*", "log", "(", "0.384", ")", "-", "ctg", "(", "(", "0.981", "+", "0.981", ")", "-", "(", "0.981", "^", "0.981", ")", ")", "/", "atan", "(", "0.903", ")", "/", "atan", "(", "0.380", ")", "*", "asin", "(", "(", "0.323", "-", "0.323", ")", "+", "(", "0.352", "*", "0.323", ")", ")", "+", "actg", "(", "0.736", ")", "/", "cos", "(", "0.37", ")", "*", "tan", "(", "(", "0.301", "-", "0.301", ")", "+", "(", "0.301", "^", "0.301", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.433)*log(0.384)-ctg((0.981+0.981)-(0.981^0.981))/atan(0.903)/atan(0.380)*asin((0.323-0.323)+(0.352*0.323))+actg(0.736)/cos(0.37)*tan((0.301-0.301)+(0.301^0.301))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.46", ")", "+", "cos", "(", "0.644", ")", "/", "actg", "(", "(", "0.419", "^", "0.419", ")", "+", "(", "0.419", "+", "0.419", ")", ")", "/", "atan", "(", "0.806", ")", "/", "actg", "(", "0.316", ")", "*", "tan", "(", "(", "0.872", "+", "0.872", ")", "/", "(", "0.872", "^", "0.872", ")", ")", "+", "ln", "(", "0.710", ")", "-", "cos", "(", "0.358", ")", "*", "ln", "(", "(", "0.688", "*", "0.688", ")", "+", "(", "0.688", "^", "0.688", ")", ")", "*", "sin", "(", "0.462", ")", "-", "ctg", "(", "0.836", ")", "*", "atan", "(", "(", "0.211", "^", "0.211", ")", "*", "(", "x", "*", "0.211", ")", ")", "*", "cos", "(", "0.67", ")", "+", "0.750"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.46)+cos(0.644)/actg((0.419^0.419)+(0.419+0.419))/atan(0.806)/actg(0.316)*tan((0.872+0.872)/(0.872^0.872))+ln(0.710)-cos(0.358)*ln((0.688*0.688)+(0.688^0.688))*sin(0.462)-ctg(0.836)*atan((0.211^0.211)*(x*0.211))*cos(0.67)+0.750"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.979", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.979)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.701", ")", "*", "sin", "(", "0.551", ")", "-", "atan", "(", "(", "0.793", "/", "0.793", ")", "/", "(", "0.313", "/", "0.793", ")", ")", "+", "tan", "(", "0.838", ")", "/", "sqrt", "(", "0.917", ")", "*", "log", "(", "(", "0.182", "/", "0.182", ")", "^", "(", "0.182", "-", "0.182", ")", ")", "*", "ln", "(", "0.593", ")", "-", "ln", "(", "0.418", ")", "/", "cos", "(", "(", "0.81", "/", "0.81", ")", "-", "(", "0.742", "/", "0.81", ")", ")", "^", "cos", "(", "0.83", ")", "-", "0.223"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.701)*sin(0.551)-atan((0.793/0.793)/(0.313/0.793))+tan(0.838)/sqrt(0.917)*log((0.182/0.182)^(0.182-0.182))*ln(0.593)-ln(0.418)/cos((0.81/0.81)-(0.742/0.81))^cos(0.83)-0.223"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.852", ")", "-", "log", "(", "0.288", ")", "+", "acos", "(", "(", "0.473", "+", "0.473", ")", "^", "(", "0.473", "-", "0.473", ")", ")", "-", "ctg", "(", "0.246", ")", "/", "ctg", "(", "0.667", ")", "/", "asin", "(", "(", "0.478", "^", "0.478", ")", "*", "(", "0.478", "^", "0.478", ")", ")", "/", "ctg", "(", "0.202", ")", "-", "atan", "(", "0.577", ")", "^", "log", "(", "(", "0.7", "*", "0.7", ")", "^", "(", "0.13", "*", "0.7", ")", ")", "+", "tan", "(", "0.360", ")", "-", "0.948"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.852)-log(0.288)+acos((0.473+0.473)^(0.473-0.473))-ctg(0.246)/ctg(0.667)/asin((0.478^0.478)*(0.478^0.478))/ctg(0.202)-atan(0.577)^log((0.7*0.7)^(0.13*0.7))+tan(0.360)-0.948"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.253", ")", "+", "tan", "(", "0.215", ")", "+", "atan", "(", "(", "0.541", "^", "0.541", ")", "/", "(", "0.692", "*", "0.541", ")", ")", "*", "actg", "(", "0.953", ")", "+", "ctg", "(", "0.905", ")", "/", "asin", "(", "(", "0.358", "+", "0.358", ")", "/", "(", "x", "^", "0.358", ")", ")", "*", "actg", "(", "0.766", ")", "^", "0.109"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.253)+tan(0.215)+atan((0.541^0.541)/(0.692*0.541))*actg(0.953)+ctg(0.905)/asin((0.358+0.358)/(x^0.358))*actg(0.766)^0.109"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.350", ")", "^", "sqrt", "(", "0.566", ")", "-", "cos", "(", "(", "0.238", "+", "0.238", ")", "+", "(", "0.710", "+", "0.238", ")", ")", "*", "ln", "(", "0.430", ")", "*", "acos", "(", "0.411", ")", "-", "ln", "(", "(", "0.843", "-", "0.843", ")", "*", "(", "x", "-", "0.843", ")", ")", "-", "log", "(", "0.234", ")", "^", "sin", "(", "0.941", ")", "/", "sqrt", "(", "(", "0.646", "*", "0.646", ")", "^", "(", "0.334", "+", "0.646", ")", ")", "/", "ctg", "(", "0.1", ")", "-", "cos", "(", "0.531", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.350)^sqrt(0.566)-cos((0.238+0.238)+(0.710+0.238))*ln(0.430)*acos(0.411)-ln((0.843-0.843)*(x-0.843))-log(0.234)^sin(0.941)/sqrt((0.646*0.646)^(0.334+0.646))/ctg(0.1)-cos(0.531)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.955", ")", "/", "actg", "(", "0.790", ")", "^", "ctg", "(", "(", "0.393", "*", "0.393", ")", "/", "(", "0.170", "^", "0.393", ")", ")", "-", "cos", "(", "0.118", ")", "*", "cos", "(", "0.78", ")", "-", "log", "(", "(", "0.989", "-", "0.989", ")", "+", "(", "0.989", "/", "0.989", ")", ")", "-", "atan", "(", "0.781", ")", "+", "sin", "(", "0.401", ")", "/", "ln", "(", "(", "0.180", "*", "0.180", ")", "-", "(", "0.180", "/", "0.180", ")", ")", "*", "log", "(", "0.822", ")", "-", "atan", "(", "0.945", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.955)/actg(0.790)^ctg((0.393*0.393)/(0.170^0.393))-cos(0.118)*cos(0.78)-log((0.989-0.989)+(0.989/0.989))-atan(0.781)+sin(0.401)/ln((0.180*0.180)-(0.180/0.180))*log(0.822)-atan(0.945)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.134", ")", "+", "ln", "(", "0.747", ")", "*", "ln", "(", "(", "0.789", "*", "0.789", ")", "-", "(", "x", "+", "0.789", ")", ")", "-", "acos", "(", "0.386", ")", "-", "cos", "(", "0.930", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.134)+ln(0.747)*ln((0.789*0.789)-(x+0.789))-acos(0.386)-cos(0.930)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.707", ")", "+", "tan", "(", "0.997", ")", "+", "atan", "(", "(", "0.755", "-", "0.755", ")", "+", "(", "x", "/", "0.755", ")", ")", "+", "sqrt", "(", "0.386", ")", "-", "atan", "(", "0.202", ")", "*", "sin", "(", "(", "0.460", "+", "0.460", ")", "-", "(", "0.325", "*", "0.460", ")", ")", "/", "ln", "(", "0.597", ")", "-", "atan", "(", "0.191", ")", "/", "cos", "(", "(", "0.681", "^", "0.681", ")", "+", "(", "x", "/", "0.681", ")", ")", "/", "actg", "(", "0.198", ")", "^", "log", "(", "0.761", ")", "+", "sin", "(", "(", "0.229", "*", "0.229", ")", "^", "(", "0.254", "-", "0.229", ")", ")", "-", "log", "(", "0.755", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.707)+tan(0.997)+atan((0.755-0.755)+(x/0.755))+sqrt(0.386)-atan(0.202)*sin((0.460+0.460)-(0.325*0.460))/ln(0.597)-atan(0.191)/cos((0.681^0.681)+(x/0.681))/actg(0.198)^log(0.761)+sin((0.229*0.229)^(0.254-0.229))-log(0.755)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.959", ")", "*", "tan", "(", "0.354", ")", "*", "actg", "(", "(", "0.30", "-", "0.30", ")", "+", "(", "0.517", "*", "0.30", ")", ")", "*", "actg", "(", "0.694", ")", "/", "sin", "(", "0.851", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.959)*tan(0.354)*actg((0.30-0.30)+(0.517*0.30))*actg(0.694)/sin(0.851)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "asin", "(", "0.671", ")", "^", "asin", "(", "0.497", ")", "-", "tan", "(", "(", "0.973", "*", "0.973", ")", "+", "(", "0.701", "/", "0.973", ")", ")", "^", "sqrt", "(", "0.189", ")", "-", "cos", "(", "0.478", ")", "^", "sin", "(", "(", "0.538", "-", "0.538", ")", "+", "(", "x", "/", "0.538", ")", ")", "-", "sqrt", "(", "0.738", ")", "*", "0.596"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+asin(0.671)^asin(0.497)-tan((0.973*0.973)+(0.701/0.973))^sqrt(0.189)-cos(0.478)^sin((0.538-0.538)+(x/0.538))-sqrt(0.738)*0.596"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.515", ")", "/", "actg", "(", "0.677", ")", "^", "sqrt", "(", "(", "0.364", "^", "0.364", ")", "*", "(", "0.364", "/", "0.364", ")", ")", "+", "cos", "(", "0.389", ")", "+", "acos", "(", "0.469", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.515)/actg(0.677)^sqrt((0.364^0.364)*(0.364/0.364))+cos(0.389)+acos(0.469)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ctg", "(", "0.683", ")", "/", "ctg", "(", "0.870", ")", "*", "actg", "(", "(", "0.948", "/", "0.948", ")", "+", "(", "x", "/", "0.948", ")", ")", "^", "sqrt", "(", "0.883", ")", "-", "asin", "(", "0.409", ")", "/", "cos", "(", "(", "0.590", "*", "0.590", ")", "/", "(", "0.367", "+", "0.590", ")", ")", "-", "tan", "(", "0.962", ")", "-", "actg", "(", "0.977", ")", "-", "acos", "(", "(", "0.350", "-", "0.350", ")", "+", "(", "0.350", "*", "0.350", ")", ")", "-", "ctg", "(", "0.225", ")", "/", "0.655"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ctg(0.683)/ctg(0.870)*actg((0.948/0.948)+(x/0.948))^sqrt(0.883)-asin(0.409)/cos((0.590*0.590)/(0.367+0.590))-tan(0.962)-actg(0.977)-acos((0.350-0.350)+(0.350*0.350))-ctg(0.225)/0.655"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.950", ")", "+", "cos", "(", "0.476", ")", "+", "actg", "(", "(", "0.868", "+", "0.868", ")", "+", "(", "x", "*", "0.868", ")", ")", "+", "ln", "(", "0.497", ")", "*", "0.148"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.950)+cos(0.476)+actg((0.868+0.868)+(x*0.868))+ln(0.497)*0.148"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.216", ")", "/", "sin", "(", "0.584", ")", "^", "cos", "(", "(", "0.464", "*", "0.464", ")", "*", "(", "0.464", "^", "0.464", ")", ")", "^", "sin", "(", "0.374", ")", "-", "atan", "(", "0.678", ")", "-", "actg", "(", "(", "0.134", "^", "0.134", ")", "/", "(", "x", "+", "0.134", ")", ")", "^", "atan", "(", "0.252", ")", "/", "cos", "(", "0.912", ")", "^", "log", "(", "(", "0.58", "/", "0.58", ")", "/", "(", "x", "*", "0.58", ")", ")", "*", "sqrt", "(", "0.854", ")", "^", "sqrt", "(", "0.165", ")", "^", "actg", "(", "(", "0.125", "+", "0.125", ")", "/", "(", "x", "^", "0.125", ")", ")", "+", "cos", "(", "0.774", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.216)/sin(0.584)^cos((0.464*0.464)*(0.464^0.464))^sin(0.374)-atan(0.678)-actg((0.134^0.134)/(x+0.134))^atan(0.252)/cos(0.912)^log((0.58/0.58)/(x*0.58))*sqrt(0.854)^sqrt(0.165)^actg((0.125+0.125)/(x^0.125))+cos(0.774)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.242", ")", "/", "sin", "(", "0.755", ")", "^", "tan", "(", "(", "0.221", "*", "0.221", ")", "+", "(", "0.907", "*", "0.221", ")", ")", "*", "asin", "(", "0.233", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.242)/sin(0.755)^tan((0.221*0.221)+(0.907*0.221))*asin(0.233)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "135", "%", "781"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+135%781"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "257", "%", "43"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+257%43"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.301", ")", "*", "ln", "(", "0.782", ")", "+", "actg", "(", "(", "0.414", "/", "0.414", ")", "/", "(", "0.495", "-", "0.414", ")", ")", "*", "acos", "(", "0.367", ")", "/", "ln", "(", "0.835", ")", "-", "actg", "(", "(", "0.45", "/", "0.45", ")", "+", "(", "x", "/", "0.45", ")", ")", "/", "atan", "(", "0.627", ")", "-", "sin", "(", "0.763", ")", "*", "acos", "(", "(", "0.57", "*", "0.57", ")", "*", "(", "0.57", "-", "0.57", ")", ")", "-", "atan", "(", "0.325", ")", "-", "asin", "(", "0.822", ")", "-", "tan", "(", "(", "0.531", "*", "0.531", ")", "/", "(", "0.572", "-", "0.531", ")", ")", "^", "cos", "(", "0.35", ")", "-", "0.209"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.301)*ln(0.782)+actg((0.414/0.414)/(0.495-0.414))*acos(0.367)/ln(0.835)-actg((0.45/0.45)+(x/0.45))/atan(0.627)-sin(0.763)*acos((0.57*0.57)*(0.57-0.57))-atan(0.325)-asin(0.822)-tan((0.531*0.531)/(0.572-0.531))^cos(0.35)-0.209"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.946", ")", "/", "sin", "(", "0.360", ")", "-", "asin", "(", "(", "0.321", "+", "0.321", ")", "/", "(", "0.263", "/", "0.321", ")", ")", "-", "acos", "(", "0.706", ")", "^", "asin", "(", "0.773", ")", "^", "sin", "(", "(", "0.925", "/", "0.925", ")", "+", "(", "0.568", "^", "0.925", ")", ")", "^", "acos", "(", "0.886", ")", "-", "tan", "(", "0.0", ")", "/", "sqrt", "(", "(", "0.374", "*", "0.374", ")", "-", "(", "0.327", "+", "0.374", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.946)/sin(0.360)-asin((0.321+0.321)/(0.263/0.321))-acos(0.706)^asin(0.773)^sin((0.925/0.925)+(0.568^0.925))^acos(0.886)-tan(0.0)/sqrt((0.374*0.374)-(0.327+0.374))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.884", ")", "+", "actg", "(", "0.56", ")", "*", "log", "(", "(", "0.257", "*", "0.257", ")", "*", "(", "0.257", "/", "0.257", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.884)+actg(0.56)*log((0.257*0.257)*(0.257/0.257))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.681", ")", "*", "atan", "(", "0.729", ")", "+", "acos", "(", "(", "0.509", "^", "0.509", ")", "/", "(", "0.509", "-", "0.509", ")", ")", "^", "sqrt", "(", "0.186", ")", "+", "ln", "(", "0.400", ")", "^", "cos", "(", "(", "0.788", "-", "0.788", ")", "-", "(", "0.788", "/", "0.788", ")", ")", "/", "log", "(", "0.940", ")", "/", "asin", "(", "0.600", ")", "+", "log", "(", "(", "0.517", "/", "0.517", ")", "+", "(", "0.906", "^", "0.517", ")", ")", "+", "ctg", "(", "0.989", ")", "*", "ln", "(", "0.969", ")", "^", "actg", "(", "(", "0.561", "/", "0.561", ")", "+", "(", "0.561", "+", "0.561", ")", ")", "/", "actg", "(", "0.400", ")", "/", "0.139"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.681)*atan(0.729)+acos((0.509^0.509)/(0.509-0.509))^sqrt(0.186)+ln(0.400)^cos((0.788-0.788)-(0.788/0.788))/log(0.940)/asin(0.600)+log((0.517/0.517)+(0.906^0.517))+ctg(0.989)*ln(0.969)^actg((0.561/0.561)+(0.561+0.561))/actg(0.400)/0.139"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.677", ")", "*", "atan", "(", "0.48", ")", "*", "ctg", "(", "(", "0.798", "^", "0.798", ")", "^", "(", "0.530", "+", "0.798", ")", ")", "^", "sin", "(", "0.898", ")", "/", "ctg", "(", "0.932", ")", "/", "tan", "(", "(", "0.331", "-", "0.331", ")", "/", "(", "0.331", "-", "0.331", ")", ")", "/", "ln", "(", "0.429", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.677)*atan(0.48)*ctg((0.798^0.798)^(0.530+0.798))^sin(0.898)/ctg(0.932)/tan((0.331-0.331)/(0.331-0.331))/ln(0.429)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.823", ")", "+", "ln", "(", "0.156", ")", "*", "sin", "(", "(", "0.168", "^", "0.168", ")", "-", "(", "0.338", "/", "0.168", ")", ")", "^", "log", "(", "0.209", ")", "+", "acos", "(", "0.312", ")", "+", "asin", "(", "(", "0.862", "*", "0.862", ")", "+", "(", "0.302", "/", "0.862", ")", ")", "-", "log", "(", "0.413", ")", "-", "actg", "(", "0.1", ")", "-", "ctg", "(", "(", "0.907", "-", "0.907", ")", "*", "(", "0.907", "+", "0.907", ")", ")", "^", "acos", "(", "0.358", ")", "-", "sin", "(", "0.795", ")", "/", "sqrt", "(", "(", "0.427", "-", "0.427", ")", "+", "(", "x", "*", "0.427", ")", ")", "+", "log", "(", "0.532", ")", "*", "sqrt", "(", "0.102", ")", "+", "ctg", "(", "(", "0.901", "-", "0.901", ")", "/", "(", "0.901", "+", "0.901", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.823)+ln(0.156)*sin((0.168^0.168)-(0.338/0.168))^log(0.209)+acos(0.312)+asin((0.862*0.862)+(0.302/0.862))-log(0.413)-actg(0.1)-ctg((0.907-0.907)*(0.907+0.907))^acos(0.358)-sin(0.795)/sqrt((0.427-0.427)+(x*0.427))+log(0.532)*sqrt(0.102)+ctg((0.901-0.901)/(0.901+0.901))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.255", ")", "*", "acos", "(", "0.19", ")", "^", "atan", "(", "(", "0.863", "*", "0.863", ")", "+", "(", "0.863", "-", "0.863", ")", ")", "/", "cos", "(", "0.401", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.255)*acos(0.19)^atan((0.863*0.863)+(0.863-0.863))/cos(0.401)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.590", ")", "/", "ctg", "(", "0.753", ")", "+", "ctg", "(", "(", "0.569", "+", "0.569", ")", "-", "(", "x", "*", "0.569", ")", ")", "/", "asin", "(", "0.751", ")", "*", "sqrt", "(", "0.138", ")", "-", "ctg", "(", "(", "0.18", "-", "0.18", ")", "*", "(", "0.284", "^", "0.18", ")", ")", "/", "tan", "(", "0.338", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.590)/ctg(0.753)+ctg((0.569+0.569)-(x*0.569))/asin(0.751)*sqrt(0.138)-ctg((0.18-0.18)*(0.284^0.18))/tan(0.338)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.0", ")", "+", "asin", "(", "0.344", ")", "^", "actg", "(", "(", "0.130", "*", "0.130", ")", "^", "(", "0.130", "^", "0.130", ")", ")", "^", "sin", "(", "0.881", ")", "*", "sin", "(", "0.804", ")", "^", "atan", "(", "(", "0.641", "*", "0.641", ")", "/", "(", "0.451", "*", "0.641", ")", ")", "/", "sqrt", "(", "0.449", ")", "/", "sin", "(", "0.777", ")", "*", "ctg", "(", "(", "0.89", "/", "0.89", ")", "/", "(", "x", "^", "0.89", ")", ")", "*"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.0)+asin(0.344)^actg((0.130*0.130)^(0.130^0.130))^sin(0.881)*sin(0.804)^atan((0.641*0.641)/(0.451*0.641))/sqrt(0.449)/sin(0.777)*ctg((0.89/0.89)/(x^0.89))*"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.713", ")", "/", "cos", "(", "0.184", ")", "-", "asin", "(", "(", "0.457", "-", "0.457", ")", "*", "(", "x", "*", "0.457", ")", ")", "^", "actg", "(", "0.513", ")", "^", "ln", "(", "0.491", ")", "-", "ln", "(", "(", "0.72", "^", "0.72", ")", "/", "(", "0.940", "/", "0.72", ")", ")", "/", "ln", "(", "0.543", ")", "/", "cos", "(", "0.170", ")", "-", "tan", "(", "(", "0.38", "/", "0.38", ")", "-", "(", "0.479", "^", "0.38", ")", ")", "-", "log", "(", "0.548", ")", "*", "cos", "(", "0.761", ")", "-", "tan", "(", "(", "0.635", "+", "0.635", ")", "*", "(", "0.635", "-", "0.635", ")", ")", "-", "tan", "(", "0.115", ")", "+", "sqrt", "(", "0.540", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.713)/cos(0.184)-asin((0.457-0.457)*(x*0.457))^actg(0.513)^ln(0.491)-ln((0.72^0.72)/(0.940/0.72))/ln(0.543)/cos(0.170)-tan((0.38/0.38)-(0.479^0.38))-log(0.548)*cos(0.761)-tan((0.635+0.635)*(0.635-0.635))-tan(0.115)+sqrt(0.540)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "log", "(", "0.58", ")", "-", "ctg", "(", "0.685", ")", "-", "sqrt", "(", "(", "0.753", "*", "0.753", ")", "-", "(", "x", "+", "0.753", ")", ")", "-", "asin", "(", "0.255", ")", "/", "cos", "(", "0.536", ")", "+", "actg", "(", "(", "0.323", "*", "0.323", ")", "^", "(", "x", "-", "0.323", ")", ")", "^", "atan", "(", "0.555", ")", "-", "actg", "(", "0.171", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+log(0.58)-ctg(0.685)-sqrt((0.753*0.753)-(x+0.753))-asin(0.255)/cos(0.536)+actg((0.323*0.323)^(x-0.323))^atan(0.555)-actg(0.171)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.454", ")", "/", "log", "(", "0.372", ")", "/", "atan", "(", "(", "0.531", "*", "0.531", ")", "*", "(", "x", "+", "0.531", ")", ")", "^", "cos", "(", "0.989", ")", "^", "tan", "(", "0.994", ")", "*", "log", "(", "(", "0.444", "-", "0.444", ")", "+", "(", "x", "/", "0.444", ")", ")", "^", "log", "(", "0.41", ")", "/", "ln", "(", "0.641", ")", "/", "log", "(", "(", "0.466", "*", "0.466", ")", "*", "(", "0.466", "^", "0.466", ")", ")", "/", "acos", "(", "0.582", ")", "-", "actg", "(", "0.596", ")", "-", "acos", "(", "(", "0.57", "+", "0.57", ")", "/", "(", "x", "^", "0.57", ")", ")", "-"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.454)/log(0.372)/atan((0.531*0.531)*(x+0.531))^cos(0.989)^tan(0.994)*log((0.444-0.444)+(x/0.444))^log(0.41)/ln(0.641)/log((0.466*0.466)*(0.466^0.466))/acos(0.582)-actg(0.596)-acos((0.57+0.57)/(x^0.57))-"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.701", ")", "*", "sqrt", "(", "0.248", ")", "-", "acos", "(", "(", "0.749", "-", "0.749", ")", "^", "(", "x", "/", "0.749", ")", ")", "+", "acos", "(", "0.861", ")", "*", "asin", "(", "0.103", ")", "+", "actg", "(", "(", "0.97", "-", "0.97", ")", "/", "(", "x", "/", "0.97", ")", ")", "-", "log", "(", "0.750", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.701)*sqrt(0.248)-acos((0.749-0.749)^(x/0.749))+acos(0.861)*asin(0.103)+actg((0.97-0.97)/(x/0.97))-log(0.750)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.824", ")", "*", "ctg", "(", "0.328", ")", "/", "atan", "(", "(", "0.337", "-", "0.337", ")", "-", "(", "x", "/", "0.337", ")", ")", "+", "tan", "(", "0.914", ")", "-", "asin", "(", "0.422", ")", "^", "acos", "(", "(", "0.132", "/", "0.132", ")", "^", "(", "0.132", "+", "0.132", ")", ")", "-", "tan", "(", "0.545", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.824)*ctg(0.328)/atan((0.337-0.337)-(x/0.337))+tan(0.914)-asin(0.422)^acos((0.132/0.132)^(0.132+0.132))-tan(0.545)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.956", ")", "^", "sqrt", "(", "0.952", ")", "-", "sin", "(", "(", "0.466", "/", "0.466", ")", "*", "(", "0.466", "*", "0.466", ")", ")", "-", "cos", "(", "0.0", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.956)^sqrt(0.952)-sin((0.466/0.466)*(0.466*0.466))-cos(0.0)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sqrt", "(", "0.497", ")", "*", "acos", "(", "0.124", ")", "+", "tan", "(", "(", "0.285", "^", "0.285", ")", "+", "(", "0.285", "-", "0.285", ")", ")", "*", "asin", "(", "0.792", ")", "-", "acos", "(", "0.435", ")", "/", "atan", "(", "(", "0.59", "/", "0.59", ")", "^", "(", "0.490", "-", "0.59", ")", ")", "/", "actg", "(", "0.241", ")", "-", "acos", "(", "0.631", ")", "-", "ln", "(", "(", "0.600", "^", "0.600", ")", "-", "(", "0.899", "^", "0.600", ")", ")", "/", "sqrt", "(", "0.314", ")", "*", "ctg", "(", "0.155", ")", "+", "sqrt", "(", "(", "0.991", "/", "0.991", ")", "*", "(", "x", "*", "0.991", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sqrt(0.497)*acos(0.124)+tan((0.285^0.285)+(0.285-0.285))*asin(0.792)-acos(0.435)/atan((0.59/0.59)^(0.490-0.59))/actg(0.241)-acos(0.631)-ln((0.600^0.600)-(0.899^0.600))/sqrt(0.314)*ctg(0.155)+sqrt((0.991/0.991)*(x*0.991))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "tan", "(", "0.863", ")", "*", "asin", "(", "0.381", ")", "/", "sqrt", "(", "(", "0.768", "*", "0.768", ")", "^", "(", "0.539", "+", "0.768", ")", ")", "^", "log", "(", "0.150", ")", "/", "cos", "(", "0.112", ")", "/", "acos", "(", "(", "0.854", "/", "0.854", ")", "-", "(", "0.821", "/", "0.854", ")", ")", "^", "sin", "(", "0.677", ")", "*", "ln", "(", "0.984", ")", "^", "ctg", "(", "(", "0.497", "*", "0.497", ")", "/", "(", "0.497", "-", "0.497", ")", ")", "^", "cos", "(", "0.645", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+tan(0.863)*asin(0.381)/sqrt((0.768*0.768)^(0.539+0.768))^log(0.150)/cos(0.112)/acos((0.854/0.854)-(0.821/0.854))^sin(0.677)*ln(0.984)^ctg((0.497*0.497)/(0.497-0.497))^cos(0.645)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "actg", "(", "0.396", ")", "-", "cos", "(", "0.518", ")", "-", "ctg", "(", "(", "0.160", "+", "0.160", ")", "+", "(", "0.160", "*", "0.160", ")", ")", "+", "acos", "(", "0.920", ")", "^", "cos", "(", "0.627", ")", "/", "asin", "(", "(", "0.525", "*", "0.525", ")", "/", "(", "0.525", "/", "0.525", ")", ")", "/", "tan", "(", "0.201", ")", "/", "tan", "(", "0.263", ")", "/", "sin", "(", "(", "0.543", "-", "0.543", ")", "*", "(", "0.543", "-", "0.543", ")", ")", "+", "sin", "(", "0.413", ")", "+", "asin", "(", "0.947", ")", "/", "sin", "(", "(", "0.426", "/", "0.426", ")", "*", "(", "0.790", "-", "0.426", ")", ")", "*", "tan", "(", "0.279", ")", "*", "0.91"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+actg(0.396)-cos(0.518)-ctg((0.160+0.160)+(0.160*0.160))+acos(0.920)^cos(0.627)/asin((0.525*0.525)/(0.525/0.525))/tan(0.201)/tan(0.263)/sin((0.543-0.543)*(0.543-0.543))+sin(0.413)+asin(0.947)/sin((0.426/0.426)*(0.790-0.426))*tan(0.279)*0.91"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "acos", "(", "0.71", ")", "-", "ln", "(", "0.966", ")", "^", "acos", "(", "(", "0.401", "/", "0.401", ")", "/", "(", "0.149", "/", "0.401", ")", ")", "+"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+acos(0.71)-ln(0.966)^acos((0.401/0.401)/(0.149/0.401))+"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "atan", "(", "0.627", ")", "^", "atan", "(", "0.25", ")", "*", "tan", "(", "(", "0.892", "*", "0.892", ")", "+", "(", "0.183", "-", "0.892", ")", ")", "+", "ctg", "(", "0.633", ")", "/", "cos", "(", "0.183", ")", "-", "atan", "(", "(", "0.559", "/", "0.559", ")", "+", "(", "x", "/", "0.559", ")", ")", "/", "actg", "(", "0.452", ")", "/", "ln", "(", "0.698", ")", "*", "cos", "(", "(", "0.250", "+", "0.250", ")", "/", "(", "x", "/", "0.250", ")", ")", "/", "tan", "(", "0.718", ")", "^", "sin", "(", "0.396", ")", "/", "actg", "(", "(", "0.406", "/", "0.406", ")", "^", "(", "x", "^", "0.406", ")", ")", "*", "ctg", "(", "0.226", ")", "*", "sin", "(", "0.175", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+atan(0.627)^atan(0.25)*tan((0.892*0.892)+(0.183-0.892))+ctg(0.633)/cos(0.183)-atan((0.559/0.559)+(x/0.559))/actg(0.452)/ln(0.698)*cos((0.250+0.250)/(x/0.250))/tan(0.718)^sin(0.396)/actg((0.406/0.406)^(x^0.406))*ctg(0.226)*sin(0.175)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "ln", "(", "0.764", ")", "^", "tan", "(", "0.453", ")", "*", "asin", "(", "(", "0.196", "^", "0.196", ")", "^", "(", "x", "+", "0.196", ")", ")", "^", "sin", "(", "0.347", ")", "-", "tan", "(", "0.902", ")", "^", "atan", "(", "(", "0.825", "*", "0.825", ")", "/", "(", "x", "-", "0.825", ")", ")", "/", "asin", "(", "0.360", ")", "*", "acos", "(", "0.901", ")", "/", "tan", "(", "(", "0.498", "/", "0.498", ")", "*", "(", "0.767", "/", "0.498", ")", ")", "+", "asin", "(", "0.383", ")"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+ln(0.764)^tan(0.453)*asin((0.196^0.196)^(x+0.196))^sin(0.347)-tan(0.902)^atan((0.825*0.825)/(x-0.825))/asin(0.360)*acos(0.901)/tan((0.498/0.498)*(0.767/0.498))+asin(0.383)"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "405", "%", "377"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+405%377"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "sin", "(", "0.20", ")", "*", "cos", "(", "0.460", ")", "*", "log", "(", "(", "0.153", "-", "0.153", ")", "/", "(", "0.423", "/", "0.153", ")", ")", "/", "sin", "(", "0.2", ")", "*", "sin", "(", "0.957", ")", "-", "ln", "(", "(", "0.647", "*", "0.647", ")", "+", "(", "x", "-", "0.647", ")", ")", "-", "tan", "(", "0.853", ")", "/", "ctg", "(", "0.63", ")", "+", "atan", "(", "(", "0.226", "-", "0.226", ")", "*", "(", "0.226", "+", "0.226", ")", ")", "-", "cos", "(", "0.48", ")", "^", "tan", "(", "0.659", ")", "+", "tan", "(", "(", "0.862", "^", "0.862", ")", "-", "(", "0.862", "/", "0.862", ")", ")", "-", "cos", "(", "0.772", ")", "*", "atan", "(", "0.605", ")", "/", "atan", "(", "(", "0.981", "/", "0.981", ")", "+", "(", "0.981", "/", "0.981", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+sin(0.20)*cos(0.460)*log((0.153-0.153)/(0.423/0.153))/sin(0.2)*sin(0.957)-ln((0.647*0.647)+(x-0.647))-tan(0.853)/ctg(0.63)+atan((0.226-0.226)*(0.226+0.226))-cos(0.48)^tan(0.659)+tan((0.862^0.862)-(0.862/0.862))-cos(0.772)*atan(0.605)/atan((0.981/0.981)+(0.981/0.981))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
  char *string[] = {"-", "0.345", "+", "0.345", "+", "(", "-", "0.345", ")", "+", "0.345", "+", "cos", "(", "0.273", ")", "*", "sin", "(", "0.220", ")", "+", "tan", "(", "(", "0.200", "+", "0.200", ")", "-", "(", "0.176", "+", "0.200", ")", ")", "*", "atan", "(", "0.419", ")", "^", "ln", "(", "0.513", ")", "+", "asin", "(", "(", "0.741", "*", "0.741", ")", "+", "(", "0.741", "-", "0.741", ")", ")", "/", "log", "(", "0.833", ")", "-", "acos", "(", "0.526", ")", "+", "cos", "(", "(", "0.966", "*", "0.966", ")", "+", "(", "0.966", "+", "0.966", ")", ")", "+", "cos", "(", "0.671", ")", "^", "atan", "(", "0.596", ")", "^", "sqrt", "(", "(", "0.824", "*", "0.824", ")", "+", "(", "0.824", "^", "0.824", ")", ")", "+", "actg", "(", "0.292", ")", "-", "cos", "(", "0.260", ")", "/", "tan", "(", "(", "0.168", "^", "0.168", ")", "-", "(", "x", "-", "0.168", ")", ")", "/"};
  char *example = {"-0.345+0.345+(-0.345)+0.345+cos(0.273)*sin(0.220)+tan((0.200+0.200)-(0.176+0.200))*atan(0.419)^ln(0.513)+asin((0.741*0.741)+(0.741-0.741))/log(0.833)-acos(0.526)+cos((0.966*0.966)+(0.966+0.966))+cos(0.671)^atan(0.596)^sqrt((0.824*0.824)+(0.824^0.824))+actg(0.292)-cos(0.260)/tan((0.168^0.168)-(x-0.168))/"};
  exit_code = parser(&stack, example);
  ck_assert_int_eq(exit_code, 0);
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
