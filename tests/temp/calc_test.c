#include "../header.h"

START_TEST(calc_1) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.452)/tan(0.396)/cos((0.100^0.100)/(0.353^0.100))-sin(0.22)"};
  char *py_result = {"2.3101974"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_2) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.426)*sqrt(0.538)^cos((0.299-0.299)^(0.107*0.299))/tan(0.186)/log(0.388)*cos((0.710/0.710)-(0.710-0.710))+sqrt(0.965)/atan(0.817)+log((0.638^0.638)^(x-0.638))/atan(0.892)"};
  char *py_result = {"-0.5456625"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_3) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.998)-sin(0.943)-tan((0.761+0.761)+(0.604^0.761))+sqrt(0.244)^0.61"};
  char *py_result = {"2.0456247"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_4) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.249)/log(0.789)*atan((0.865/0.865)^(0.865^0.865))*cos(0.420)/sqrt(0.921)+atan((0.296/0.296)+(0.296-0.296))-atan(0.826)^acos(0.249)*atan((0.513^0.513)-(0.513-0.513))*atan(0.278)/atan(0.629)/acos((0.255+0.255)*(0.958+0.255))/ln(0.889)-0.983"};
  char *py_result = {"-2.3049945"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_5) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.555)*log(0.101)^log((0.855/0.855)*(0.717+0.855))*acos(0.934)^0.921"};
  char *py_result = {"(0.1423054922616728+0.10098724360090026j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_6) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.120)/cos(0.821)^tan((0.791*0.791)-(0.903^0.791))+log(0.554)-sin(0.473)+atan((0.587-0.587)+(x*0.587))+tan(0.201)^log(0.539)+log((0.536+0.536)+(0.536-0.536))*cos(0.477)+asin(0.624)*atan((0.29*0.29)*(0.516/0.29))+log(0.991)*asin(0.207)*sqrt((0.482^0.482)-(x/0.482))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_7) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.213)^ln(0.470)^acos((0.530*0.530)/(0.530-0.530))/cos(0.866)+acos(0.225)/tan((0.172^0.172)*(x^0.172))-sqrt(0.546)-atan(0.610)/asin((0.287^0.287)-(0.287*0.287))*acos(0.778)-log(0.992)^cos((0.954+0.954)-(x-0.954))^atan(0.904)/0.116"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_8) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.489)*ln(0.811)+cos((0.564+0.564)^(x+0.564))^ln(0.899)"};
  char *py_result = {"1.0250640"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_9) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.955)+sqrt(0.723)+cos((0.530-0.530)^(x*0.530))^ln(0.148)-tan(0.555)+ln((0.401-0.401)-(0.401*0.401))/sqrt(0.808)"};
  char *py_result = {"2.3049209"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_10) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.839)/asin(0.711)+acos((0.278/0.278)-(0.559^0.278))/sin(0.311)*sqrt(0.846)-log((0.950+0.950)^(0.950-0.950))/cos(0.718)*log(0.60)+sqrt((0.637-0.637)-(0.800/0.637))/sqrt(0.445)*log(0.868)+log((0.524/0.524)-(0.524+0.524))+atan(0.15)*log(0.194)-log((0.879+0.879)*(0.250^0.879))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_11) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.964)^sqrt(0.324)+cos((0.679+0.679)*(0.232+0.679))-sqrt(0.6)*ln(0.100)^log((0.503/0.503)*(x^0.503))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_12) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.437)-tan(0.818)*atan((0.247-0.247)/(x-0.247))^tan(0.409)"};
  char *py_result = {"0.4232232"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_13) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.717)+ln(0.917)/sqrt((0.379-0.379)/(0.379-0.379))*asin(0.37)/log(0.319)+cos((0.338+0.338)*(0.338/0.338))-sin(0.658)+0.23"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_14) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.182)*acos(0.537)-tan((0.16/0.16)*(0.105*0.16))-asin(0.591)-asin(0.656)"};
  char *py_result = {"-1.1828999"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_15) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.178)-asin(0.134)*ln((0.150^0.150)-(0.992^0.150))+sqrt(0.623)-ln(0.378)/ln((0.726/0.726)^(x-0.726))^cos(0.395)"};
  char *py_result = {"1.3618322"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_16) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.812)-atan(0.702)+sin((0.312+0.312)/(0.312/0.312))*atan(0.62)^log(0.317)/cos((0.149/0.149)-(0.149/0.149))^asin(0.740)-sqrt(0.518)^asin((0.155-0.155)^(0.325-0.155))+asin(0.838)+atan(0.807)*ln((0.235/0.235)+(0.153^0.235))+sin(0.58)/sin(0.909)"};
  char *py_result = {"2.2456889"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_17) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.662)-sin(0.477)-sin((0.817/0.817)*(x/0.817))+ln(0.664)"};
  char *py_result = {"0.3729142"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_18) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.481)-atan(0.533)-log((0.336/0.336)+(0.336-0.336))+atan(0.30)*log(0.788)/tan((0.867^0.867)/(0.867/0.867))*cos(0.289)-sin(0.430)-acos((0.526*0.526)*(0.266-0.526))^acos(0.670)^tan(0.118)^sin((0.842/0.842)-(x*0.842))*atan(0.222)"};
  char *py_result = {"-0.8347840"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_19) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.499)*tan(0.819)/sqrt((0.548+0.548)*(x*0.548))*cos(0.84)-sin(0.816)+acos((0.778/0.778)+(0.778*0.778))/asin(0.865)+sqrt(0.348)^asin((0.591+0.591)+(0.591/0.591))-cos(0.190)-tan(0.128)-acos((0.788-0.788)+(0.202-0.788))-atan(0.558)/0.699"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_20) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.332)/cos(0.464)^tan((0.525+0.525)^(0.667*0.525))+log(0.817)+cos(0.870)^log((0.278/0.278)/(0.595*0.278))*log(0.992)+tan(0.666)+tan((0.77+0.77)*(0.77^0.77))*asin(0.288)/atan(0.732)-tan((0.386^0.386)*(0.386/0.386))*log(0.336)/sqrt(0.790)"};
  char *py_result = {"2.9864331"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_21) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.851)-acos(0.462)+asin((0.890-0.890)/(0.890+0.890))+asin(0.606)^0.816"};
  char *py_result = {"0.7546053"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_22) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.710)^0.404"};
  char *py_result = {"0.8229824"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_23) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.749)"};
  char *py_result = {"0.6809067"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_24) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.210)^atan(0.621)^acos((0.139^0.139)*(0.695+0.139))*cos(0.908)/atan(0.375)^acos((0.733/0.733)/(0.428^0.733))^sqrt(0.985)*sin(0.471)-sqrt((0.307^0.307)+(x+0.307))+sqrt(0.532)-0.220"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_25) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.134)^sqrt(0.957)*log((0.935*0.935)/(x*0.935))-cos(0.335)"};
  char *py_result = {"0.1791578"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_26) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.165)/sqrt(0.659)*tan((0.899*0.899)^(0.899*0.899))^ln(0.91)*cos(0.470)^log((0.824-0.824)/(0.824*0.824))/tan(0.581)+asin(0.522)/sin((0.798-0.798)+(0.798-0.798))^ln(0.973)*cos(0.862)*log((0.46-0.46)-(x+0.46))^acos(0.951)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_27) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.608)+acos(0.161)+asin((0.410*0.410)-(x/0.410))*ln(0.556)/sqrt(0.435)/atan((0.679*0.679)/(0.679*0.679))+acos(0.895)*log(0.683)/cos((0.876/0.876)+(x^0.876))*log(0.935)*acos(0.961)-acos((0.759+0.759)^(0.21+0.759))/sin(0.671)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_28) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.858)-tan(0.213)*atan((0.62^0.62)*(0.572*0.62))*sin(0.959)/tan(0.466)^asin((0.349-0.349)-(0.349*0.349))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_29) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.714)*sin(0.160)-cos((0.854*0.854)*(x+0.854))/cos(0.602)*0.463"};
  char *py_result = {"-0.3183767"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_30) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.617)*cos(0.988)^asin((0.753*0.753)/(x+0.753))/cos(0.553)-log(0.927)*log((0.205+0.205)*(0.205*0.205))-tan(0.530)+sqrt(0.272)*asin((0.640^0.640)/(0.640^0.640))*asin(0.888)+tan(0.387)-asin((0.150/0.150)/(x^0.150))/sqrt(0.918)+tan(0.29)+sqrt((0.141+0.141)*(x+0.141))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_31) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.411)*sqrt(0.194)/cos((0.710*0.710)-(x^0.710))*tan(0.620)+log(0.596)*atan((0.722*0.722)-(0.923/0.722))-sin(0.741)*acos(0.157)+tan((0.101-0.101)*(x^0.101))*acos(0.418)/tan(0.328)*log((0.75-0.75)-(x/0.75))-cos(0.479)-log(0.853)/acos((0.551*0.551)/(0.212/0.551))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_32) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.52)-acos(0.606)/atan((0.391^0.391)/(0.391+0.391))+atan(0.768)/tan(0.652)^cos((0.113*0.113)/(0.113/0.113))+acos(0.508)*sqrt(0.170)+atan((0.20^0.20)+(x-0.20))-log(0.786)*0.160"};
  char *py_result = {"1.2014695"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_33) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.662)*sqrt(0.78)+acos((0.126/0.126)-(x^0.126))^ln(0.686)^asin(0.515)+cos((0.453^0.453)^(x+0.453))^sin(0.152)+acos(0.808)^acos((0.982-0.982)+(0.962^0.982))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_34) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.309)*tan(0.535)^acos((0.896-0.896)^(x/0.896))*tan(0.943)*cos(0.122)+sqrt((0.206/0.206)/(x*0.206))/cos(0.559)"};
  char *py_result = {"6.3548245"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_35) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.292)*0.114"};
  char *py_result = {"0.0337801"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_36) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.675)/tan(0.496)*sin((0.337+0.337)-(0.443*0.337))*log(0.289)^cos(0.339)+atan((0.55/0.55)*(x+0.55))/acos(0.152)-sqrt(0.99)+sqrt((0.839+0.839)*(0.839+0.839))*acos(0.666)+log(0.464)-tan((0.278^0.278)*(0.278/0.278))*sin(0.875)"};
  char *py_result = {"(-0.5491603096884069+0.07553433975910036j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_37) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.729)-log(0.360)/ln((0.469-0.469)/(x^0.469))*sin(0.819)-asin(0.175)+tan((0.927+0.927)*(x*0.927))-sin(0.978)/log(0.802)^atan((0.204/0.204)*(0.204*0.204))^sin(0.742)/asin(0.619)^asin((0.410/0.410)^(0.410+0.410))/tan(0.496)"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_38) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.630)-ln(0.103)+cos((0.212*0.212)^(x/0.212))/cos(0.599)*ln(0.127)/cos((0.107/0.107)+(x+0.107))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_39) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"405%525"};
  char *py_result = {"405"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_40) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.968)/log(0.505)-cos((0.964*0.964)/(x*0.964))/ln(0.813)/atan(0.396)^acos((0.997+0.997)^(0.155^0.997))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_41) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.410)*tan(0.379)+acos((0.474/0.474)+(x^0.474))*atan(0.474)/acos(0.891)/tan((0.225*0.225)/(x^0.225))*cos(0.279)*cos(0.523)*asin((0.157^0.157)+(0.157-0.157))+cos(0.997)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_42) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.510)-log(0.398)/asin((0.486+0.486)/(x-0.486))-tan(0.224)+tan(0.528)^ln((0.582+0.582)-(x-0.582))-cos(0.143)/tan(0.105)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_43) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.537)+tan(0.145)^tan((0.857-0.857)-(0.857*0.857))-atan(0.247)^acos(0.140)"};
  char *py_result = {"5.9801592"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_44) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.669)^log(0.672)/log((0.1*0.1)*(x+0.1))/ln(0.940)/cos(0.865)"};
  char *py_result = {"-0.9337000"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_45) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.819)/acos(0.722)^tan((0.834+0.834)+(0.506+0.834))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_46) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.776)^atan(0.960)/sin((0.143^0.143)-(0.143-0.143))+tan(0.49)*acos(0.39)/atan((0.531-0.531)/(x^0.531))-acos(0.156)/atan(0.317)*tan((0.139*0.139)^(x*0.139))^sin(0.265)^sqrt(0.803)^log((0.624-0.624)/(0.624^0.624))/asin(0.980)^0.995"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_47) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.179)^acos(0.745)^asin((0.775/0.775)*(x^0.775))+tan(0.214)/atan(0.379)*log((0.379+0.379)/(x-0.379))^log(0.272)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_48) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.400)"};
  char *py_result = {"0.4115168"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_49) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.241)/atan(0.528)+acos((0.71+0.71)/(0.16/0.71))+ln(0.371)*ln(0.914)^tan((0.649^0.649)+(0.946^0.649))^asin(0.29)/asin(0.792)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_50) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.193)-acos(0.84)+atan((0.732+0.732)-(x-0.732))*cos(0.168)"};
  char *py_result = {"-0.1879066"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_51) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.706)+sin(0.108)^asin((0.523/0.523)^(x/0.523))*log(0.163)/cos(0.442)*sin((0.701^0.701)/(x+0.701))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_52) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.428)^cos(0.275)*log((0.954-0.954)*(0.954/0.954))*ln(0.261)-log(0.429)^sqrt((0.927/0.927)+(0.927^0.927))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_53) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.904)-0.381"};
  char *py_result = {"0.2629569"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_54) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.526)^sin(0.14)*acos((0.822^0.822)/(x^0.822))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_55) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"477%768"};
  char *py_result = {"477"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_56) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.570)+log(0.755)*acos((0.236-0.236)*(x*0.236))*tan(0.62)/asin(0.151)+acos((0.72-0.72)*(0.668/0.72))/log(0.392)-cos(0.736)-sqrt((0.347+0.347)/(0.347^0.347))-log(0.147)"};
  char *py_result = {"-5.1349698"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_57) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.187)^acos(0.749)*sqrt((0.251^0.251)/(0.251/0.251))/sqrt(0.459)*sqrt(0.853)^sin((0.616+0.616)-(x-0.616))*cos(0.733)*sqrt(0.68)*ln((0.711/0.711)-(0.711/0.711))/asin(0.384)-sqrt(0.574)+sin((0.39/0.39)-(0.39-0.39))-acos(0.839)"};
  char *py_result = {"-0.4915104"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_58) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.6)-sin(0.612)-asin((0.319^0.319)/(0.319-0.319))/sin(0.119)^atan(0.474)^asin((0.113/0.113)-(x+0.113))/sqrt(0.46)/sqrt(0.765)/atan((0.205*0.205)*(0.205^0.205))*sqrt(0.799)*atan(0.132)+sqrt((0.63+0.63)*(0.267*0.63))/atan(0.404)*0.502"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_59) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.71)/asin(0.774)*cos((0.288/0.288)+(x-0.288))/sin(0.809)+log(0.979)*sqrt((0.0^0.0)-(0.793*0.0))/acos(0.757)+log(0.491)/acos((0.90+0.90)-(0.461/0.90))*cos(0.266)/tan(0.17)+asin((0.502/0.502)^(x/0.502))/asin(0.482)/tan(0.384)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_60) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.789)/0.207"};
  char *py_result = {"3.4282563"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_61) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.450)+sin(0.850)+acos((0.381/0.381)^(0.830*0.381))^cos(0.382)*ln(0.989)+sqrt((0.12-0.12)/(x-0.12))+cos(0.119)^ln(0.889)*acos((0.937/0.937)/(x*0.937))+sqrt(0.60)*acos(0.708)/tan((0.349*0.349)*(0.319-0.349))+cos(0.69)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_62) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.664)+atan(0.426)*ln((0.51/0.51)+(0.51*0.51))+acos(0.161)/acos(0.647)/acos((0.958*0.958)+(0.958*0.958))/log(0.878)/tan(0.867)+atan((0.0-0.0)-(0.324+0.0))-atan(0.804)+sqrt(0.529)*asin((0.431*0.431)/(x*0.431))*log(0.897)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_63) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.263)-log(0.380)-sin((0.289-0.289)/(0.258*0.289))+atan(0.130)/log(0.864)"};
  char *py_result = {"-1.3825612"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_64) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.596)^0.330"};
  char *py_result = {"0.8147375"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_65) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.67)/ln(0.105)+acos((0.990^0.990)/(0.990-0.990))-tan(0.338)*log(0.345)*ln((0.437*0.437)+(0.437*0.437))-log(0.627)"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_66) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.483)-sin(0.25)/cos((0.609+0.609)+(0.349^0.609))*tan(0.202)/cos(0.829)"};
  char *py_result = {"0.8274323"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_67) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.540)"};
  char *py_result = {"0.4951332"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_68) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.94)^sqrt(0.695)^sqrt((0.907-0.907)/(0.389/0.907))^ln(0.808)"};
  char *py_result = {"0.7544801"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_69) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.39)*sqrt(0.39)*ln((0.892+0.892)-(0.242^0.892))*sqrt(0.750)/tan(0.473)+sqrt((0.550+0.550)+(0.957*0.550))-tan(0.850)+log(0.191)+cos((0.571*0.571)^(0.571+0.571))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_70) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.438)*log(0.361)^atan((0.939*0.939)-(0.939/0.939))*sin(0.808)-asin(0.662)/asin((0.504+0.504)-(0.307+0.504))-asin(0.132)"};
  char *py_result = {"(-2.9518261077666157-0.32142910843732453j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_71) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.921)^acos(0.758)^sin((0.294^0.294)+(x/0.294))*cos(0.132)^sin(0.828)"};
  char *py_result = {"0.8420945"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_72) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.723)-tan(0.758)+asin((0.570-0.570)/(0.570/0.570))^sqrt(0.949)"};
  char *py_result = {"-0.3206559"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_73) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.258)*sin(0.517)^ln((0.49^0.49)-(0.957+0.49))^acos(0.854)*0.76"};
  char *py_result = {"(-0.3438712108209705+0.3706791088803703j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_74) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.598)+tan(0.338)*log((0.638^0.638)/(0.638+0.638))/acos(0.114)^log(0.223)-asin((0.230^0.230)*(0.230+0.230))+log(0.904)/cos(0.473)-cos((0.975^0.975)-(x+0.975))+sin(0.309)/asin(0.349)-atan((0.784^0.784)^(x^0.784))-asin(0.456)"};
  char *py_result = {"-1.0330948"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_75) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.0)^atan(0.321)-log((0.418/0.418)-(0.181/0.418))^log(0.805)+acos(0.989)^sqrt((0.65/0.65)/(x^0.65))/acos(0.379)/sin(0.700)+sqrt((0.305/0.305)*(0.305/0.305))+asin(0.406)*tan(0.643)-atan((0.26-0.26)+(0.26/0.26))+acos(0.390)^0.856"};
  char *py_result = {"(0.6193550815917157+0.33278727536178093j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_76) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.370)"};
  char *py_result = {"0.3148107"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_77) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.839)*ln(0.519)-ln((0.304+0.304)/(0.304+0.304))-cos(0.823)+atan(0.113)*acos((0.549+0.549)-(0.205-0.549))/tan(0.20)+tan(0.816)+asin((0.941^0.941)/(0.941^0.941))/log(0.668)*ln(0.490)-tan((0.840/0.840)-(x^0.840))-acos(0.453)/0.190"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_78) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.984)^cos(0.688)^log((0.874*0.874)-(0.874*0.874))-tan(0.228)/log(0.22)/tan((0.896+0.896)/(0.896*0.896))*log(0.171)/sqrt(0.104)-acos((0.623^0.623)^(0.623^0.623))+sqrt(0.395)*asin(0.706)/asin((0.636/0.636)*(0.636^0.636))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_79) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"388%587"};
  char *py_result = {"388"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_80) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.344)*asin(0.935)/atan((0.888*0.888)/(x*0.888))/sin(0.764)*tan(0.903)^asin((0.778-0.778)/(0.778^0.778))+log(0.277)+0.109"};
  char *py_result = {"0.7250167"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_81) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.895)"};
  char *py_result = {"-0.0481769"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_82) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.430)"};
  char *py_result = {"0.4444927"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_83) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.192)-acos(0.20)+acos((0.974-0.974)+(0.974^0.974))-atan(0.156)^tan(0.55)*sqrt((0.985*0.985)^(0.701+0.985))^sin(0.323)/sin(0.492)^asin((0.956-0.956)^(0.956+0.956))^acos(0.649)+ln(0.80)*asin((0.393*0.393)+(0.393/0.393))+log(0.187)/0.614"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_84) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.92)/cos(0.722)-sqrt((0.351*0.351)^(x*0.351))^tan(0.365)-cos(0.533)-tan((0.807-0.807)+(0.807+0.807))-ln(0.470)^0.434"};
  char *py_result = {"21.621643"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_85) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.195)/log(0.19)/cos((0.382*0.382)^(0.428/0.382))-tan(0.229)/atan(0.839)+atan((0.910+0.910)-(0.910*0.910))/acos(0.569)-cos(0.713)-atan((0.3/0.3)+(x-0.3))^ln(0.482)"};
  char *py_result = {"-0.1619693"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_86) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.147)^sqrt(0.512)*sin((0.253/0.253)*(0.253+0.253))*sqrt(0.736)-acos(0.372)-cos((0.170^0.170)-(0.170-0.170))/tan(0.364)/log(0.571)-cos((0.111*0.111)^(0.797*0.111))*asin(0.595)*ln(0.50)"};
  char *py_result = {"6.6798131"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_87) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.386)/asin(0.687)-log((0.835+0.835)*(0.501^0.835))-cos(0.302)^acos(0.692)"};
  char *py_result = {"-0.4490128"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_88) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.174)*0.659"};
  char *py_result = {"0.9199021"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_89) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.902)^sin(0.766)-cos((0.358*0.358)+(0.358/0.358))*cos(0.515)-sin(0.351)/ln((0.765*0.765)/(0.765*0.765))^log(0.855)+cos(0.668)"};
  char *py_result = {"0.9221147"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_90) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.114)-sqrt(0.429)*asin((0.850-0.850)+(0.133^0.850))^sqrt(0.87)+0.29"};
  char *py_result = {"0.4946521"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_91) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.345)-tan(0.137)+asin((0.102+0.102)*(0.102^0.102))-log(0.976)-asin(0.315)^sin((0.754/0.754)+(0.372*0.754))^sqrt(0.266)"};
  char *py_result = {"0.6475907"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_92) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.927)/sin(0.974)^ln((0.726^0.726)*(0.627^0.726))-log(0.591)+log(0.404)"};
  char *py_result = {"1.1263363"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_93) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.571)^ln(0.428)^ln((0.94^0.94)/(0.94*0.94))/sin(0.568)+sqrt(0.316)+atan((0.1-0.1)/(0.1^0.1))^sin(0.955)^sqrt(0.4)+log((0.860*0.860)*(0.860/0.860))-cos(0.178)"};
  char *py_result = {"(-0.4707316640303605+0.949849055631552j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_94) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.483)+atan(0.757)/acos((0.449*0.449)/(0.449+0.449))+log(0.63)-tan(0.84)"};
  char *py_result = {"-0.3843502"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_95) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.124)^atan(0.874)*ln((0.837*0.837)-(0.837*0.837))+log(0.115)^sqrt(0.813)-tan((0.952^0.952)+(0.952/0.952))-atan(0.175)*log(0.536)/asin((0.685-0.685)*(0.685^0.685))/log(0.307)+0.986"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_96) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.874)*tan(0.9)*cos((0.54*0.54)+(0.21/0.54))^atan(0.990)^asin(0.36)*cos((0.686^0.686)/(x+0.686))*tan(0.693)+0.72"};
  char *py_result = {"1.1901347"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_97) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.177)+acos(0.420)-tan((0.986/0.986)/(0.986/0.986))+acos(0.574)-0.74"};
  char *py_result = {"1.1922160"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_98) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.133)-log(0.460)^sin((0.783+0.783)^(0.783+0.783))*acos(0.693)-atan(0.718)*sin((0.243/0.243)^(x-0.243))^cos(0.425)+atan(0.446)^asin((0.572+0.572)-(x+0.572))+log(0.13)*0.674"};
  char *py_result = {"(-0.021258284402123517-0.09212195700342754j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_99) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.910)/tan(0.385)+log((0.99/0.99)*(x/0.99))+log(0.430)/log(0.250)/acos((0.993*0.993)/(0.962^0.993))+log(0.851)*0.98"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_100) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.686)*log(0.579)/sin((0.962+0.962)^(0.702+0.962))/atan(0.718)"};
  char *py_result = {"-1.1733391"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_101) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.55)-atan(0.297)*tan((0.867-0.867)*(0.867^0.867))*asin(0.218)*sin(0.526)+acos((0.486*0.486)*(x+0.486))-asin(0.300)+acos(0.179)^asin((0.295^0.295)+(0.101*0.295))^asin(0.230)*asin(0.877)+sqrt((0.193/0.193)+(0.193+0.193))*acos(0.976)"};
  char *py_result = {"3.4512969"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_102) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.778)+cos(0.705)^ln((0.834+0.834)-(0.834+0.834))/tan(0.23)^0.582"};
  char *py_result = {"3.2099283"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_103) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.513)*asin(0.83)/sqrt((0.8-0.8)-(0.91^0.8))^ln(0.248)+log(0.874)*acos((0.762-0.762)^(0.762/0.762))+atan(0.775)/sqrt(0.77)-ln((0.692/0.692)+(x*0.692))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_104) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.678)+atan(0.100)^tan((0.985/0.985)-(0.985*0.985))*ln(0.670)/asin(0.72)+asin((0.911-0.911)+(x+0.911))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_105) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.185)-atan(0.676)/tan((0.899-0.899)^(x+0.899))-acos(0.863)*tan(0.633)+sqrt((0.606-0.606)^(0.87^0.606))-sqrt(0.877)-cos(0.605)+tan((0.506+0.506)^(0.488*0.506))+log(0.466)+cos(0.760)*ln((0.818*0.818)/(0.185^0.818))*asin(0.589)+sqrt(0.36)"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_106) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.766)*sin(0.400)/sqrt((0.929/0.929)*(x/0.929))*tan(0.455)+0.849"};
  char *py_result = {"1.1776369"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_107) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.435)+cos(0.448)^sqrt((0.272/0.272)+(0.272*0.272))*log(0.542)^acos(0.831)/log((0.582-0.582)*(0.223/0.582))+asin(0.985)/sqrt(0.95)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_108) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.269)^0.977"};
  char *py_result = {"0.9648495"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_109) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.778)-sqrt(0.666)/sin((0.55+0.55)-(0.55^0.55))-ln(0.160)+sqrt(0.737)/atan((0.795/0.795)^(0.795*0.795))*atan(0.948)^log(0.974)/sin((0.669*0.669)^(0.124-0.669))+asin(0.583)/0.49"};
  char *py_result = {"0.9110961"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_110) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.121)-ln(0.208)+acos((0.464*0.464)+(0.464+0.464))+tan(0.879)*sqrt(0.645)*asin((0.130*0.130)+(0.145*0.130))^cos(0.720)*sqrt(0.738)-cos((0.685-0.685)+(0.685-0.685))*acos(0.530)^sqrt(0.891)-sqrt((0.226^0.226)+(0.851+0.226))-log(0.406)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_111) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.689)+log(0.737)^asin((0.570+0.570)^(x/0.570))^ln(0.623)-log(0.351)-cos((0.71-0.71)^(x-0.71))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_112) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.863)+atan(0.267)*tan((0.205-0.205)-(x-0.205))/log(0.335)^cos(0.979)^acos((0.509/0.509)*(x^0.509))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_113) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.759)+tan(0.41)-acos((0.581+0.581)+(0.783*0.581))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_114) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"559%915"};
  char *py_result = {"559"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_115) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.18)-ln(0.682)*sin((0.614*0.614)+(0.456-0.614))+cos(0.380)-tan(0.181)/ln((0.359^0.359)+(x/0.359))+atan(0.254)*asin(0.267)-cos((0.297-0.297)-(x+0.297))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_116) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.866)+asin(0.372)*cos((0.671+0.671)-(0.107^0.671))+sin(0.561)*acos(0.981)+sin((0.673-0.673)^(0.420/0.673))/acos(0.572)^cos(0.146)"};
  char *py_result = {"0.9840685"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_117) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.519)/acos(0.432)*sin((0.85*0.85)-(x-0.85))*acos(0.366)*sqrt(0.647)/acos((0.619+0.619)-(0.619/0.619))^ln(0.82)^sqrt(0.556)^cos((0.313^0.313)/(x*0.313))-cos(0.28)-0.166"};
  char *py_result = {"-0.7816099"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_118) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.140)^cos(0.701)/sin((0.998/0.998)-(0.998-0.998))-atan(0.782)"};
  char *py_result = {"0.5158307"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_119) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.684)+acos(0.823)+atan((0.814-0.814)+(x*0.814))+cos(0.65)/sin(0.279)/sin((0.701+0.701)-(0.410-0.701))*atan(0.762)^tan(0.19)"};
  char *py_result = {"3.9303193"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_120) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.542)/sqrt(0.611)^tan((0.157*0.157)*(0.770/0.157))/sqrt(0.601)/sqrt(0.102)/atan((0.398/0.398)*(x+0.398))*ln(0.314)+ln(0.336)*log((0.301+0.301)-(0.301^0.301))+sin(0.346)^sqrt(0.643)*sqrt((0.875+0.875)+(0.875/0.875))+cos(0.381)^sqrt(0.556)+sin((0.860/0.860)^(x+0.860))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_121) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.118)-cos(0.907)-cos((0.959*0.959)+(0.561^0.959))+acos(0.697)+cos(0.403)+sin((0.957+0.957)*(0.957*0.957))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_122) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.86)/sqrt(0.392)/asin((0.69+0.69)*(x-0.69))+ln(0.724)-cos(0.788)^sin((0.689+0.689)^(0.689+0.689))^sin(0.303)-ln(0.528)/atan((0.301*0.301)-(x/0.301))*tan(0.179)-sin(0.223)^asin((0.839+0.839)+(0.839-0.839))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_123) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.264)-acos(0.58)-sqrt((0.241-0.241)+(0.27*0.241))/acos(0.948)/0.749"};
  char *py_result = {"-1.7454141"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_124) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.548)"};
  char *py_result = {"0.5209811"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_125) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.254)+sin(0.122)+cos((0.2/0.2)*(0.2*0.2))*tan(0.979)*asin(0.235)/sin((0.748^0.748)/(0.757*0.748))^ln(0.363)-sin(0.242)*ln((0.740/0.740)+(0.740/0.740))-acos(0.945)"};
  char *py_result = {"-0.7160825"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_126) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.98)-tan(0.831)+sqrt((0.84+0.84)^(0.84-0.84))-log(0.312)*ln(0.126)/sin((0.777*0.777)/(0.82^0.777))*acos(0.58)*cos(0.710)^acos((0.941/0.941)+(0.941-0.941))^cos(0.68)*acos(0.704)-atan((0.107+0.107)^(0.107*0.107))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_127) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.106)/log(0.282)^asin((0.823+0.823)^(0.823*0.823))^sqrt(0.192)-log(0.678)*atan((0.582/0.582)+(0.742*0.582))*acos(0.117)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_128) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.366)/asin(0.430)+cos((0.770*0.770)-(0.367/0.770))+cos(0.24)"};
  char *py_result = {"2.7697351"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_129) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.137)/asin(0.839)/acos((0.20/0.20)*(x+0.20))*sin(0.385)-tan(0.217)+tan((0.683+0.683)-(x-0.683))/cos(0.893)-cos(0.805)^atan((0.10+0.10)-(x+0.10))^acos(0.751)+tan(0.524)+sin((0.101/0.101)/(0.739+0.101))+tan(0.574)/tan(0.148)"};
  char *py_result = {"(-0.0817170579573494+0.03439154516667004j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_130) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.496)^acos(0.5)-cos((0.499+0.499)+(0.499+0.499))+sin(0.806)/tan(0.325)/sqrt((0.856/0.856)*(0.312-0.856))^acos(0.440)*acos(0.806)/log((0.624^0.624)-(0.466*0.624))^acos(0.670)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_131) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.633)/cos(0.210)/cos((0.31+0.31)^(0.304/0.31))*ln(0.374)^atan(0.551)-ln((0.950*0.950)-(0.950-0.950))^log(0.797)/tan(0.83)-acos((0.681/0.681)+(0.681/0.681))*cos(0.284)-acos(0.708)-atan((0.322^0.322)-(0.322^0.322))^log(0.636)^atan(0.394)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_132) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.815)+asin(0.128)+acos((0.481+0.481)*(0.469^0.481))-ln(0.644)-acos(0.568)/ln((0.19*0.19)*(0.866-0.19))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_133) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.388)+ln(0.54)+ln((0.171^0.171)/(x-0.171))^sin(0.923)-0.721"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_134) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.983)+acos(0.513)-asin((0.189-0.189)/(x^0.189))+log(0.608)*0.770"};
  char *py_result = {"1.8571895"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_135) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.400)/ln(0.495)/acos((0.177-0.177)*(0.266/0.177))-cos(0.110)*sin(0.610)-ln((0.274-0.274)+(0.519^0.274))^ln(0.758)/0.578"};
  char *py_result = {"-1.2728348"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_136) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.604)/log(0.189)*cos((0.806+0.806)^(0.891/0.806))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_137) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.429)^log(0.105)^tan((0.569^0.569)+(0.569*0.569))*atan(0.475)*tan(0.801)-asin((0.628^0.628)^(0.633+0.628))^sin(0.429)/asin(0.32)*asin((0.65^0.65)^(x/0.65))/ln(0.834)"};
  char *py_result = {"(-5.27869552321003+0.14791134705550008j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_138) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.611)+asin(0.126)/sin((0.908*0.908)+(x^0.908))/ln(0.944)+ln(0.265)+acos((0.419+0.419)-(0.419*0.419))+log(0.228)*asin(0.987)*asin((0.246/0.246)*(0.832*0.246))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_139) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.151)/acos(0.863)+sqrt((0.137^0.137)^(x+0.137))*tan(0.178)-atan(0.182)*atan((0.432*0.432)-(0.432-0.432))+log(0.209)+atan(0.395)-asin((0.758/0.758)-(x-0.758))-sin(0.577)*sqrt(0.771)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_140) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.693)^atan(0.213)+tan((0.893*0.893)*(x-0.893))^sqrt(0.903)^log(0.760)*sin((0.930/0.930)*(0.930-0.930))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_141) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.597)/tan(0.473)+tan((0.600-0.600)^(x-0.600))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_142) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.245)"};
  char *py_result = {"0.4949747"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_143) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.530)*atan(0.368)-asin((0.711*0.711)/(0.666-0.711))^sin(0.755)+cos(0.76)/log((0.9/0.9)+(0.796^0.9))-atan(0.828)+asin(0.504)+atan((0.900+0.900)/(x^0.900))/atan(0.168)-ln(0.678)+tan((0.604+0.604)*(0.797+0.604))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_144) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.807)*acos(0.295)^asin((0.794/0.794)-(0.794^0.794))+cos(0.58)/tan(0.954)-asin((0.920/0.920)^(x/0.920))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_145) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.689)/atan(0.309)/asin((0.616/0.616)^(0.616/0.616))+ln(0.346)-acos(0.890)+sin((0.338^0.338)*(0.925*0.338))-atan(0.660)+acos(0.324)/acos((0.586^0.586)-(x/0.586))/atan(0.815)"};
  char *py_result = {"2.7752418"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_146) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.263)-log(0.36)/asin((0.786^0.786)+(x*0.786))^tan(0.801)*0.257"};
  char *py_result = {"0.3571344"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_147) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.597)+asin(0.213)/log((0.226+0.226)^(0.226^0.226))/sin(0.233)/sin(0.18)"};
  char *py_result = {"-20.509666"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_148) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.554)/acos(0.548)*tan((0.548^0.548)*(0.486^0.548))-acos(0.536)*sin(0.507)*asin((0.103-0.103)^(0.818*0.103))/asin(0.528)+acos(0.397)+tan((0.426/0.426)*(x+0.426))*sqrt(0.893)-0.416"};
  char *py_result = {"1.6750187"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_149) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.92)-acos(0.114)/asin((0.799^0.799)+(x-0.799))-ln(0.392)*tan(0.903)*asin((0.539-0.539)/(x+0.539))^log(0.407)+log(0.21)-cos((0.252-0.252)+(0.591*0.252))/acos(0.644)-tan(0.482)*acos((0.103+0.103)+(x/0.103))^sqrt(0.596)+0.809"};
  char *py_result = {"0.0 cannot be raised to a negative power"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_150) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.615)+tan(0.200)*cos((0.220*0.220)+(0.220^0.220))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_151) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"945%746"};
  char *py_result = {"199"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_152) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.369)/ln(0.762)-acos((0.693-0.693)-(x-0.693))/sin(0.527)-acos(0.752)-sin((0.668^0.668)*(0.784/0.668))/tan(0.285)+sqrt(0.395)+atan((0.431+0.431)+(0.431/0.431))^tan(0.546)-asin(0.357)+atan((0.305/0.305)^(0.305^0.305))-asin(0.914)*atan(0.403)^sin((0.340+0.340)^(0.340/0.340))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_153) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.930)+atan(0.398)+sqrt((0.684^0.684)+(0.684/0.684))^cos(0.347)-tan(0.150)/cos((0.444*0.444)+(0.444^0.444))^sin(0.730)"};
  char *py_result = {"2.8214818"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_154) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.173)/sqrt(0.768)-acos((0.670/0.670)*(x/0.670))+atan(0.563)*log(0.759)^acos((0.383-0.383)+(x/0.383))-atan(0.242)+sin(0.919)+sqrt((0.421*0.421)+(x/0.421))/acos(0.309)"};
  char *py_result = {"(-1.1074405185586274-0.021225469893570954j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_155) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.250)^sin(0.395)/ln((0.408^0.408)-(0.408*0.408))-cos(0.596)/tan(0.12)"};
  char *py_result = {"-4.5303232"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_156) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.915)-atan(0.377)+sin((0.37+0.37)+(0.37-0.37))-log(0.833)/cos(0.832)-tan((0.541+0.541)-(0.939+0.541))^ln(0.514)*tan(0.929)/sqrt((0.173-0.173)/(0.173*0.173))*cos(0.323)+sqrt(0.408)"};
  char *py_result = {"complex division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_157) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.98)+log(0.615)+log((0.797+0.797)/(0.22-0.797))/sqrt(0.870)^ln(0.59)/atan((0.580*0.580)+(0.580*0.580))-acos(0.467)^ln(0.247)*sqrt((0.493/0.493)/(x-0.493))*asin(0.847)^sin(0.491)^log((0.568-0.568)-(0.568/0.568))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_158) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.24)"};
  char *py_result = {"0.2423658"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_159) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.819)/sin(0.428)/sqrt((0.307^0.307)-(x+0.307))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_160) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.618)*cos(0.519)-log((0.476/0.476)*(x+0.476))+tan(0.610)*cos(0.607)/atan((0.772*0.772)-(x/0.772))*asin(0.708)+0.552"};
  char *py_result = {"2.4469841"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_161) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.652)*0.62"};
  char *py_result = {"0.3112317"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_162) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.920)+tan(0.579)^atan((0.203^0.203)-(0.203*0.203))^acos(0.687)/cos(0.725)+atan((0.239+0.239)+(0.239^0.239))*asin(0.498)/atan(0.758)+ln((0.865/0.865)*(0.214*0.865))/sin(0.567)^log(0.870)"};
  char *py_result = {"2.2761989"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_163) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.355)*atan(0.705)*log((0.936/0.936)+(x-0.936))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_164) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.779)^sqrt(0.164)+sqrt((0.328*0.328)^(0.63+0.328))*ln(0.453)-atan(0.455)"};
  char *py_result = {"(-0.17894322412295804+0.3887487288905847j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_165) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"838%520"};
  char *py_result = {"318"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_166) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.712)-atan(0.417)*tan((0.195-0.195)*(0.711-0.195))-cos(0.193)/0.852"};
  char *py_result = {"-0.4985677"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_167) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.543)^ln(0.851)-atan((0.327-0.327)*(x+0.327))*tan(0.563)^ln(0.967)"};
  char *py_result = {"0.6659428"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_168) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.70)-0.579"};
  char *py_result = {"0.0317259"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_169) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.813)^cos(0.130)*sqrt((0.965+0.965)+(x*0.965))-asin(0.267)/sqrt(0.427)*asin((0.809/0.809)+(x*0.809))*cos(0.566)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_170) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.824)*acos(0.612)^sqrt((0.465^0.465)+(0.465^0.465))/ln(0.347)-tan(0.558)-cos((0.441/0.441)^(0.441/0.441))^tan(0.398)"};
  char *py_result = {"1.8569246"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_171) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.733)+asin(0.539)*sqrt((0.757/0.757)-(0.757*0.757))^acos(0.419)*cos(0.118)*tan((0.368-0.368)^(x*0.368))*tan(0.470)+acos(0.384)/asin((0.739-0.739)-(0.976+0.739))^atan(0.95)/sin(0.740)*log((0.47+0.47)^(x^0.47))+sqrt(0.272)+ln(0.322)/acos((0.257*0.257)/(0.257+0.257))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_172) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.737)*asin(0.2)^asin((0.842+0.842)+(0.50/0.842))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_173) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.317)/atan(0.573)+sin((0.527/0.527)+(0.371+0.527))+sqrt(0.569)-cos(0.27)+atan((0.422/0.422)^(0.382-0.422))-atan(0.773)/0.362"};
  char *py_result = {"0.2342452"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_174) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.709)"};
  char *py_result = {"0.8420213"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_175) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.409)^cos(0.415)/cos((0.616*0.616)-(0.616/0.616))+acos(0.781)*tan(0.231)/atan((0.906^0.906)^(0.354*0.906))/atan(0.365)-tan(0.556)-asin((0.812+0.812)/(0.812^0.812))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_176) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.705)"};
  char *py_result = {"0.6480338"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_177) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.995)-tan(0.299)/acos((0.429-0.429)-(x/0.429))^sin(0.373)*sin(0.875)^sqrt((0.436*0.436)/(x-0.436))^cos(0.866)-sqrt(0.690)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_178) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.584)-cos(0.434)+sqrt((0.162+0.162)*(0.162/0.162))/sqrt(0.937)-atan(0.429)*sqrt((0.967/0.967)/(x-0.967))^tan(0.499)/atan(0.269)+asin((0.54^0.54)-(0.54*0.54))-ln(0.539)-0.895"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_179) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.293)-tan(0.724)-cos((0.280^0.280)/(0.789/0.280))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_180) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.828)+log(0.514)*tan((0.391^0.391)-(0.449+0.391))+sqrt(0.761)*cos(0.842)-sqrt((0.46^0.46)/(x-0.46))-acos(0.598)-acos(0.67)^tan((0.476/0.476)*(x/0.476))^ln(0.729)/sin(0.619)/atan((0.985-0.985)/(x/0.985))/log(0.973)-0.361"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_181) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.136)^sin(0.418)/atan((0.18/0.18)/(0.18-0.18))+log(0.143)^sin(0.72)/asin((0.820/0.820)-(x*0.820))*ln(0.729)/log(0.846)/acos((0.55^0.55)/(x/0.55))*asin(0.356)/asin(0.737)^atan((0.420-0.420)^(0.321+0.420))/sin(0.59)-asin(0.527)/acos((0.702/0.702)*(0.702^0.702))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_182) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.743)^cos(0.285)^acos((0.802*0.802)+(0.428+0.802))/log(0.630)*log(0.617)-ln((0.166-0.166)+(x-0.166))*tan(0.766)^asin(0.51)^tan((0.391+0.391)-(x/0.391))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_183) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.121)^0.86"};
  char *py_result = {"0.1633143"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_184) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.404)-cos(0.156)*sin((0.618-0.618)^(x^0.618))-log(0.765)^acos(0.317)^tan((0.15-0.15)/(0.20/0.15))+cos(0.569)-acos(0.416)+sin((0.211+0.211)^(x/0.211))^atan(0.80)*log(0.52)^asin((0.724*0.724)-(0.56*0.724))/asin(0.235)"};
  char *py_result = {"(1.5718526900617174+0.8429629915522461j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_185) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.794)^ln(0.492)*atan((0.917+0.917)+(0.900/0.917))^atan(0.139)^sin(0.313)+acos((0.530-0.530)*(0.530/0.530))+sin(0.583)^asin(0.202)/acos((0.931^0.931)*(x-0.931))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_186) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.509)+sqrt(0.869)^atan((0.578^0.578)^(0.9/0.578))*cos(0.22)-log(0.58)-asin((0.293+0.293)*(0.994^0.293))+atan(0.766)-atan(0.393)+ln((0.739+0.739)+(0.792/0.739))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_187) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.76)-log(0.435)+log((0.38+0.38)^(0.892*0.38))-asin(0.912)-sin(0.496)^cos((0.703+0.703)+(0.644*0.703))/ln(0.469)/sqrt(0.312)-sin((0.778/0.778)/(0.523^0.778))*atan(0.719)^asin(0.348)+atan((0.431-0.431)*(0.431+0.431))^cos(0.994)*atan(0.973)*tan((0.950*0.950)^(x+0.950))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_188) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"488%860"};
  char *py_result = {"488"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_189) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.764)^sin(0.678)+asin((0.522^0.522)-(0.512-0.522))-atan(0.703)*log(0.221)*atan((0.432+0.432)^(0.808^0.432))/asin(0.744)-sqrt(0.971)-sin((0.209^0.209)-(x-0.209))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_190) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.992)-acos(0.442)-sin((0.989+0.989)+(0.989+0.989))*acos(0.860)*tan(0.483)"};
  char *py_result = {"0.0872874"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_191) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.645)*sqrt(0.323)^ln((0.732/0.732)^(x-0.732))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_192) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"40%489"};
  char *py_result = {"40"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_193) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.417)+log(0.377)*asin((0.168*0.168)+(x+0.168))*ln(0.469)*atan(0.261)/atan((0.718/0.718)+(0.159*0.718))*tan(0.850)/cos(0.865)/cos((0.105/0.105)/(0.105*0.105))+tan(0.165)*ln(0.848)+asin((0.493^0.493)*(0.493+0.493))-cos(0.181)/0.635"};
  char *py_result = {"0.0020442"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_194) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.912)+sin(0.917)/atan((0.536-0.536)-(0.71-0.536))/cos(0.203)^atan(0.894)+asin((0.662^0.662)*(0.662^0.662))/sin(0.154)*sin(0.500)*asin((0.887*0.887)-(0.887*0.887))/acos(0.476)^ln(0.233)+sqrt((0.601-0.601)^(0.601-0.601))^log(0.527)"};
  char *py_result = {"-3.2552357"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_195) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.377)/sin(0.258)*sin((0.72^0.72)*(x*0.72))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_196) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.702)*asin(0.197)-atan((0.594/0.594)-(0.594+0.594))/atan(0.867)-asin(0.69)*log((0.584-0.584)/(0.27-0.584))-sin(0.66)-acos(0.648)+log((0.410/0.410)-(0.489+0.410))*sin(0.2)/atan(0.332)*atan((0.819*0.819)*(0.819/0.819))*atan(0.343)+0.156"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_197) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.458)+log(0.594)-ln((0.348/0.348)+(x^0.348))-sin(0.268)+asin(0.65)*sqrt((0.924*0.924)-(0.924/0.924))*log(0.494)/asin(0.628)^tan((0.892-0.892)*(0.56^0.892))-ln(0.458)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_198) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.567)^cos(0.676)/tan((0.536+0.536)*(0.536+0.536))+tan(0.957)*ln(0.134)*log((0.343-0.343)+(0.343*0.343))-asin(0.546)*log(0.930)^log((0.666*0.666)-(0.666^0.666))-asin(0.291)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_199) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.485)*sqrt(0.684)-asin((0.354^0.354)*(0.104^0.354))+asin(0.869)*sqrt(0.275)-sin((0.337*0.337)/(0.337-0.337))/log(0.985)^sqrt(0.3)-log((0.307^0.307)^(0.307-0.307))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_200) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.296)/log(0.152)+atan((0.699-0.699)+(0.731*0.699))*log(0.728)-sqrt(0.222)*atan((0.214*0.214)*(x/0.214))^atan(0.668)*sqrt(0.976)*asin((0.414+0.414)+(0.414-0.414))^atan(0.196)+asin(0.623)*sin((0.161^0.161)^(0.161/0.161))/asin(0.177)"};
  char *py_result = {"1.7715401"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_201) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.653)*acos(0.324)+cos((0.731/0.731)+(0.731*0.731))*tan(0.299)^acos(0.984)-asin((0.764-0.764)*(0.461/0.764))/cos(0.62)*asin(0.31)^atan((0.530/0.530)+(x+0.530))/acos(0.666)*atan(0.4)"};
  char *py_result = {"0.6531404"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_202) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.180)-tan(0.629)+sin((0.187-0.187)^(0.187/0.187))-asin(0.603)+log(0.645)+sin((0.51-0.51)-(x/0.51))*log(0.967)+atan(0.276)^sqrt((0.970-0.970)^(0.970^0.970))+tan(0.787)^cos(0.538)^sin((0.0/0.0)^(x^0.0))/asin(0.970)"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_203) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.162)/asin(0.134)/log((0.300-0.300)/(x^0.300))-acos(0.223)/ln(0.358)-asin((0.340/0.340)^(x+0.340))^tan(0.444)/sin(0.723)+acos((0.946-0.946)/(0.946-0.946))/ln(0.822)-tan(0.17)-sin((0.868^0.868)/(0.868+0.868))/asin(0.541)-atan(0.27)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_204) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.523)"};
  char *py_result = {"0.7231873"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_205) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.928)+cos(0.349)/atan((0.579-0.579)+(x*0.579))^ln(0.138)-atan(0.237)+log((0.925/0.925)*(0.925+0.925))-atan(0.477)^asin(0.684)*asin((0.831/0.831)-(x+0.831))-atan(0.794)*sin(0.799)/tan((0.746+0.746)*(0.746*0.746))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_206) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.982)^asin(0.262)/asin((0.114*0.114)*(0.598/0.114))^log(0.785)*sqrt(0.498)-tan((0.58*0.58)*(x^0.58))^sin(0.866)^sqrt(0.559)/sqrt((0.902/0.902)+(0.895*0.902))*asin(0.920)-asin(0.761)-log((0.387+0.387)-(0.387/0.387))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_207) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"267%649"};
  char *py_result = {"267"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_208) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.32)+sqrt(0.101)*acos((0.299/0.299)/(x/0.299))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_209) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.165)*cos(0.948)/ln((0.75-0.75)^(x*0.75))+tan(0.616)*cos(0.624)/sqrt((0.867/0.867)^(x/0.867))*cos(0.146)-0.47"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_210) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.894)*sqrt(0.31)^log((0.839*0.839)*(0.839+0.839))-ln(0.414)^0.674"};
  char *py_result = {"0.4168769"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_211) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.46)^cos(0.72)^cos((0.755/0.755)-(0.653+0.755))^asin(0.675)-sqrt(0.28)/cos((0.998+0.998)/(0.347/0.998))^sqrt(0.351)/asin(0.537)*ln((0.907^0.907)+(0.907-0.907))-atan(0.779)+asin(0.992)*atan((0.566-0.566)/(0.566^0.566))^sqrt(0.800)-0.886"};
  char *py_result = {"-1.7372969"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_212) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.397)-atan(0.280)*tan((0.449*0.449)^(x^0.449))*asin(0.968)-acos(0.380)^sqrt((0.650^0.650)+(0.650*0.650))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_213) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.476)+sin(0.704)+log((0.853*0.853)/(x^0.853))*sqrt(0.251)/cos(0.949)"};
  char *py_result = {"1.8182461"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_214) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"36%849"};
  char *py_result = {"36"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_215) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.558)/0.732"};
  char *py_result = {"0.8526870"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_216) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.638)-sqrt(0.802)/sin((0.499^0.499)*(0.664-0.499))+asin(0.478)*atan(0.163)*acos((0.144/0.144)-(0.258-0.144))*sin(0.938)^ln(0.39)-ln((0.402/0.402)/(x+0.402))^asin(0.607)/tan(0.147)*tan((0.585/0.585)^(0.585+0.585))+log(0.408)/asin(0.764)"};
  char *py_result = {"-18.242543"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_217) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.973)^log(0.625)/tan((0.161*0.161)-(0.161-0.161))-atan(0.522)*ln(0.575)*log((0.474-0.474)-(x/0.474))/cos(0.116)^ln(0.252)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_218) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.691)*cos(0.857)*log((0.71*0.71)-(0.71^0.71))-asin(0.786)*asin(0.204)/atan((0.710*0.710)+(x-0.710))^cos(0.433)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_219) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.586)^tan(0.324)*atan((0.262*0.262)/(x*0.262))*sqrt(0.434)^log(0.380)-acos((0.561-0.561)/(0.561/0.561))*cos(0.407)-ln(0.114)+log((0.650/0.650)-(x/0.650))+sin(0.27)/0.488"};
  char *py_result = {"(-0.743823558849856+0.663044346351194j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_220) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.199)^asin(0.556)^sqrt((0.375*0.375)+(0.375^0.375))-tan(0.767)+log(0.572)/tan((0.365*0.365)+(x*0.365))+cos(0.889)*atan(0.410)/sin((0.208-0.208)-(0.208-0.208))+sqrt(0.617)-cos(0.464)*atan((0.449-0.449)*(0.191/0.449))/cos(0.17)/asin(0.970)"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_221) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.621)-sqrt(0.340)^ln((0.84*0.84)*(x+0.84))^sqrt(0.930)*log(0.941)*asin((0.222/0.222)-(x^0.222))-acos(0.288)*0.140"};
  char *py_result = {"0.3835755"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_222) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.828)^tan(0.565)/ln((0.284-0.284)*(0.284/0.284))+sqrt(0.812)+tan(0.533)-cos((0.262-0.262)^(x*0.262))^atan(0.727)^acos(0.664)*asin((0.1+0.1)/(x^0.1))*cos(0.429)+log(0.986)^log((0.485+0.485)^(0.36/0.485))/log(0.757)*sin(0.748)"};
  char *py_result = {"complex division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_223) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.120)*atan(0.472)^tan((0.987+0.987)+(0.466+0.987))+ln(0.500)^ln(0.981)"};
  char *py_result = {"0.6343356"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_224) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.862)+log(0.207)*asin((0.747/0.747)/(0.747*0.747))*log(0.290)/atan(0.572)^tan((0.747^0.747)+(0.747*0.747))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_225) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"349%310"};
  char *py_result = {"39"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_226) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.256)-asin(0.960)/asin((0.574/0.574)+(0.574/0.574))/atan(0.245)-sin(0.433)+sqrt((0.183*0.183)/(x+0.183))^sin(0.245)+tan(0.313)-asin((0.666*0.666)^(0.666*0.666))+acos(0.543)/tan(0.396)+atan((0.267+0.267)^(0.16+0.267))-sqrt(0.425)/atan(0.624)+log((0.958^0.958)-(0.129*0.958))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_227) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.440)/acos(0.34)-acos((0.435-0.435)-(0.435-0.435))^tan(0.764)^ln(0.616)"};
  char *py_result = {"-0.8171874"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_228) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.540)-asin(0.494)*sqrt((0.78/0.78)+(0.78/0.78))-ln(0.812)+sin(0.584)/acos((0.980/0.980)-(x-0.980))*sqrt(0.957)-acos(0.287)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_229) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.717)+tan(0.607)-sin((0.683^0.683)/(0.683*0.683))^sin(0.142)"};
  char *py_result = {"0.5667063"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_230) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.772)+ln(0.988)*sin((0.913/0.913)*(x/0.913))^atan(0.479)-asin(0.875)+sqrt((0.684/0.684)-(0.684^0.684))^ln(0.800)+cos(0.9)^asin((0.600/0.600)-(0.600^0.600))^log(0.69)"};
  char *py_result = {"1.4197414"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_231) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.924)-acos(0.421)+acos((0.371*0.371)-(x*0.371))+acos(0.44)^0.751"};
  char *py_result = {"1.4042838"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_232) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.565)*sqrt(0.38)+ln((0.780+0.780)^(0.856/0.780))-atan(0.378)*cos(0.20)-atan((0.6+0.6)^(0.907-0.6))/sqrt(0.109)^sqrt(0.954)-sin((0.419*0.419)+(x*0.419))-sqrt(0.879)+sin(0.447)+sin((0.715/0.715)^(x/0.715))-ln(0.942)-acos(0.642)"};
  char *py_result = {"-3.3795955"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_233) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.437)*tan(0.51)-atan((0.607*0.607)^(0.607*0.607))/sin(0.870)/atan(0.11)-log((0.820*0.820)^(0.820*0.820))/sin(0.485)/ln(0.200)-acos((0.719*0.719)-(0.221/0.719))*tan(0.648)-sin(0.548)"};
  char *py_result = {"-7.1867098"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_234) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.395)/cos(0.21)+ln((0.397-0.397)/(0.255+0.397))-atan(0.105)-ln(0.568)/tan((0.180-0.180)*(0.14*0.180))*sqrt(0.215)/asin(0.634)^tan((0.48/0.48)-(x/0.48))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_235) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.390)*cos(0.446)-cos((0.789*0.789)+(0.390*0.789))*log(0.522)-sqrt(0.401)*sin((0.382^0.382)^(0.529-0.382))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_236) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.565)/asin(0.172)-sqrt((0.860/0.860)^(0.860^0.860))^log(0.228)*log(0.963)*acos((0.960-0.960)^(0.183+0.960))-cos(0.162)"};
  char *py_result = {"1.6298517"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_237) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.985)*asin(0.884)*tan((0.58^0.58)-(0.58^0.58))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_238) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.877)*0.521"};
  char *py_result = {"-0.0296972"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_239) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.366)+acos(0.731)+tan((0.149+0.149)-(0.149+0.149))*asin(0.387)^log(0.992)*atan((0.152-0.152)^(0.720*0.152))-tan(0.919)/log(0.343)/ln((0.882+0.882)/(0.882+0.882))+ln(0.465)+0.547"};
  char *py_result = {"6.9445781"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_240) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.202)/0.512"};
  char *py_result = {"0.8778205"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_241) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.271)-atan(0.537)-log((0.789-0.789)-(x^0.789))-sqrt(0.682)*asin(0.449)*acos((0.508/0.508)-(0.508-0.508))+ln(0.58)^ln(0.614)-ln((0.638+0.638)/(x^0.638))-tan(0.951)+cos(0.33)/tan((0.177/0.177)-(0.177-0.177))/acos(0.901)^sin(0.835)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_242) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.233)^log(0.391)/cos((0.26-0.26)/(0.26*0.26))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_243) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.972)*asin(0.562)/asin((0.228+0.228)/(0.700-0.228))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_244) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.35)"};
  char *py_result = {"0.3428978"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_245) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.585)*atan(0.24)*ln((0.398-0.398)/(0.398+0.398))+ln(0.176)/sin(0.601)"};
  char *py_result = {"0.2866987"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_246) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.112)-log(0.460)^sqrt((0.649+0.649)/(x*0.649))/sqrt(0.427)*cos(0.244)/ln((0.965^0.965)^(0.230-0.965))/cos(0.670)-tan(0.937)^acos((0.844/0.844)-(0.439/0.844))/acos(0.652)+asin(0.52)+sin((0.877-0.877)/(0.229-0.877))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_247) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.81)/log(0.620)/atan((0.600*0.600)+(0.600*0.600))-acos(0.157)+atan(0.666)-sin((0.987-0.987)-(0.607*0.987))/ln(0.124)*tan(0.894)"};
  char *py_result = {"-1.7678216"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_248) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.814)+log(0.512)^acos((0.470-0.470)+(x/0.470))-sin(0.9)*sqrt(0.342)^tan((0.110-0.110)+(0.718*0.110))^atan(0.918)*sin(0.115)*tan((0.125^0.125)^(0.889-0.125))+sqrt(0.287)/0.679"};
  char *py_result = {"(0.45396503406034316-0.14827310020310672j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_249) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.315)*atan(0.966)/ln((0.946*0.946)+(x+0.946))*sin(0.468)^tan(0.418)^tan((0.296-0.296)*(x+0.296))*sin(0.703)+sin(0.339)*cos((0.502^0.502)+(x/0.502))-acos(0.320)*cos(0.496)*log((0.683+0.683)/(0.683/0.683))^cos(0.755)-0.664"};
  char *py_result = {"-0.6803290"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_250) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.843)+acos(0.83)*tan((0.923^0.923)-(x^0.923))/asin(0.817)-sqrt(0.344)^log((0.366/0.366)+(0.366/0.366))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_251) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.270)^sqrt(0.848)*sqrt((0.483-0.483)*(0.181/0.483))*cos(0.598)"};
  char *py_result = {"0.0"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_252) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.286)^0.310"};
  char *py_result = {"0.6813441"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_253) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.958)-sin(0.240)*tan((0.508+0.508)/(0.508+0.508))*acos(0.512)+cos(0.782)-sqrt((0.507/0.507)-(0.623+0.507))*asin(0.904)+cos(0.382)/asin((0.328*0.328)^(0.328^0.328))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_254) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.349)^sin(0.397)*tan((0.962^0.962)+(0.602-0.962))*log(0.956)^ln(0.70)"};
  char *py_result = {"(-0.005506432314223189+0.057049916752787776j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_255) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.10)-cos(0.359)+ln((0.308+0.308)*(0.308-0.308))*log(0.333)*asin(0.573)"};
  char *py_result = {"-0.8360812"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_256) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.927)+cos(0.666)+atan((0.854^0.854)^(x*0.854))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_257) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.587)*sin(0.220)-atan((0.498^0.498)*(x^0.498))*sqrt(0.250)+sin(0.979)/acos((0.370-0.370)/(x*0.370))+cos(0.416)-tan(0.253)/cos((0.541^0.541)/(0.541/0.541))^tan(0.436)-tan(0.369)+sin((0.656*0.656)*(0.656-0.656))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_258) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.793)/log(0.559)/tan((0.737+0.737)+(0.737/0.737))+atan(0.961)/cos(0.822)/sqrt((0.539-0.539)+(0.369*0.539))/tan(0.24)-sin(0.538)-sqrt((0.502/0.502)^(x*0.502))+tan(0.380)"};
  char *py_result = {"12.480357"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_259) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.49)-acos(0.986)*cos((0.986/0.986)*(x*0.986))-acos(0.990)+log(0.579)-cos((0.614*0.614)^(0.614^0.614))-log(0.76)/0.400"};
  char *py_result = {"-0.6604643"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_260) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.616)"};
  char *py_result = {"0.7848566"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_261) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.95)*sqrt(0.424)^asin((0.748^0.748)-(0.81+0.748))-cos(0.965)^acos(0.131)^tan((0.757^0.757)/(0.98^0.757))/log(0.311)/sqrt(0.181)/ln((0.552^0.552)*(0.552*0.552))/ln(0.730)"};
  char *py_result = {"19.472223"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_262) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.433)+0.186"};
  char *py_result = {"0.6055958"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_263) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.419)*tan(0.668)+acos((0.337+0.337)-(x+0.337))/cos(0.659)+0.60"};
  char *py_result = {"2.0536573"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_264) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.967)*log(0.381)-ln((0.533^0.533)*(x/0.533))/tan(0.922)-cos(0.595)/tan((0.846/0.846)/(0.846-0.846))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_265) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.509)^atan(0.913)^asin((0.391-0.391)*(0.391+0.391))^acos(0.225)-sqrt(0.96)"};
  char *py_result = {"-0.4457732"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_266) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.470)/sqrt(0.950)+log((0.196+0.196)*(0.577*0.196))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_267) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.470)-sin(0.392)^log((0.671+0.671)+(x-0.671))-sin(0.410)-asin(0.911)/ln((0.904*0.904)+(0.904*0.904))*atan(0.825)^log(0.621)"};
  char *py_result = {"-2.3076459"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_268) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.568)+asin(0.185)^ln((0.24*0.24)*(0.453^0.24))*tan(0.412)-asin(0.756)+sin((0.433+0.433)^(0.433/0.433))-log(0.710)/log(0.546)+ln((0.202-0.202)-(0.137-0.202))^sqrt(0.248)"};
  char *py_result = {"0.4448535"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_269) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.928)-tan(0.408)/cos((0.619^0.619)+(0.820-0.619))-asin(0.345)-0.575"};
  char *py_result = {"-0.3290055"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_270) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.566)+asin(0.478)^sin((0.824*0.824)*(0.969/0.824))+tan(0.911)*ln(0.618)"};
  char *py_result = {"1.8628564"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_271) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.465)^asin(0.564)+tan((0.30-0.30)*(x+0.30))^log(0.118)+tan(0.32)-cos((0.98^0.98)^(0.679^0.98))+sin(0.842)^tan(0.554)/sin((0.299-0.299)+(0.299/0.299))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_272) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.983)^ln(0.198)/ln((0.147+0.147)+(x/0.147))*tan(0.883)^ln(0.375)*tan((0.370+0.370)*(0.370+0.370))/acos(0.51)/acos(0.261)*tan((0.934/0.934)^(x+0.934))-atan(0.293)-tan(0.265)-atan((0.270*0.270)^(0.270+0.270))*asin(0.899)^ln(0.395)"};
  char *py_result = {"-0.0096656"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_273) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.873)+ln(0.944)-tan((0.572-0.572)^(0.244-0.572))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_274) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.271)/acos(0.389)^ln((0.263+0.263)*(0.985*0.263))^acos(0.483)^log(0.675)^sin((0.629-0.629)*(x+0.629))-tan(0.612)+tan(0.894)+cos((0.195-0.195)/(0.78+0.195))*tan(0.807)+ln(0.440)"};
  char *py_result = {"2.2246414"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_275) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.965)/asin(0.950)-atan((0.742*0.742)*(x/0.742))-sin(0.259)-sqrt(0.665)-acos((0.549*0.549)*(0.693*0.549))/sqrt(0.839)+atan(0.614)/log((0.99-0.99)*(0.646^0.99))/tan(0.265)/acos(0.177)^asin((0.991-0.991)^(0.991/0.991))*tan(0.930)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_276) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.441)^asin(0.305)*acos((0.368*0.368)^(0.368*0.368))+sqrt(0.370)*log(0.197)/log((0.363^0.363)^(0.363*0.363))-log(0.285)+ln(0.621)-ln((0.206^0.206)-(x-0.206))-sin(0.491)*ln(0.758)+sin((0.833/0.833)/(x^0.833))-sqrt(0.102)"};
  char *py_result = {"19.816313"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_277) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.164)"};
  char *py_result = {"-0.7851561"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_278) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.534)*tan(0.567)*log((0.655/0.655)+(0.325-0.655))^acos(0.337)^sin(0.323)"};
  char *py_result = {"(-0.07037157370778317-0.015059736850765202j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_279) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.321)^sin(0.62)+asin((0.719*0.719)-(0.848/0.719))+ln(0.437)*atan(0.764)^acos((0.900*0.900)+(x+0.900))-atan(0.27)/ln(0.0)-sin((0.162^0.162)/(x-0.162))-log(0.121)+0.366"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_280) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.796)-atan(0.709)*log((0.557+0.557)^(0.177+0.557))*atan(0.121)^tan(0.481)*tan((0.330/0.330)+(0.190-0.330))-sin(0.106)+sin(0.292)+tan((0.876-0.876)*(0.876-0.876))-acos(0.278)+atan(0.29)-tan((0.555+0.555)+(0.768^0.555))^atan(0.38)+acos(0.550)"};
  char *py_result = {"(-0.5116871229166642-1.2389294863927582j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_281) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.311)^log(0.99)-asin((0.183/0.183)-(x*0.183))^ln(0.323)/0.880"};
  char *py_result = {"-0.2293301"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_282) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.162)-asin(0.790)^acos((0.347/0.347)+(x-0.347))^sin(0.973)+cos(0.537)-sqrt((0.650/0.650)/(0.20-0.650))/ln(0.532)-log(0.538)-acos((0.242-0.242)-(x*0.242))^sqrt(0.476)-asin(0.924)^ln((0.42*0.42)*(0.967*0.42))^cos(0.968)-asin(0.277)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_283) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.193)*0.126"};
  char *py_result = {"0.0222353"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_284) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.936)*0.567"};
  char *py_result = {"0.3745738"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_285) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.207)+ln(0.528)-atan((0.540/0.540)+(0.146*0.540))/acos(0.909)-log(0.959)*atan((0.288/0.288)^(x*0.288))+acos(0.130)*atan(0.94)/atan((0.612^0.612)+(x-0.612))^log(0.873)+ln(0.881)"};
  char *py_result = {"-0.5222286"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_286) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.130)^cos(0.572)+cos((0.281*0.281)-(x^0.281))*atan(0.127)/atan(0.976)/cos((0.667-0.667)^(0.967*0.667))+ln(0.504)*cos(0.866)"};
  char *py_result = {"1.7661116"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_287) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.306)^ln(0.769)/acos((0.615^0.615)*(0.615+0.615))-log(0.883)^sin(0.419)*asin((0.626-0.626)*(x^0.626))+ln(0.768)-sqrt(0.491)^cos((0.75/0.75)/(0.351+0.75))-cos(0.617)^asin(0.649)"};
  char *py_result = {"(0.01524334053015275+0j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_288) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.398)/cos(0.791)*asin((0.489-0.489)/(0.489*0.489))+tan(0.824)^sin(0.430)/cos((0.670-0.670)^(0.167/0.670))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_289) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.799)*cos(0.249)/sqrt((0.259*0.259)^(0.259^0.259))/cos(0.901)-ln(0.744)-asin((0.968*0.968)*(0.968-0.968))^sin(0.857)+tan(0.651)+ln((0.501^0.501)+(x*0.501))+log(0.18)"};
  char *py_result = {"2.6491472"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_290) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.686)-ln(0.490)-atan((0.152+0.152)+(0.152^0.152))*sqrt(0.89)/atan(0.336)/asin((0.521*0.521)/(0.521/0.521))*sqrt(0.902)*acos(0.202)/sqrt((0.856^0.856)+(x^0.856))+log(0.745)*atan(0.542)-asin((0.815/0.815)+(0.906/0.815))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_291) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.972)*sqrt(0.229)*asin((0.257/0.257)-(x+0.257))/ln(0.351)/acos(0.65)"};
  char *py_result = {"0.2762622"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_292) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.938)/atan(0.404)^acos((0.136+0.136)-(x+0.136))-cos(0.996)-asin(0.793)*sqrt((0.548*0.548)+(0.548+0.548))^cos(0.531)/asin(0.252)*tan((0.311+0.311)/(0.272+0.311))+acos(0.146)^asin(0.901)+sqrt((0.757/0.757)/(0.76^0.757))^log(0.871)/0.248"};
  char *py_result = {"0.4447446"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_293) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.512)"};
  char *py_result = {"1.0332848"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_294) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.798)^0.977"};
  char *py_result = {"0.7039338"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_295) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.886)*asin(0.895)+sin((0.624-0.624)-(0.624^0.624))^acos(0.911)-0.11"};
  char *py_result = {"(1.1309970068839192+0.8243748146757061j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_296) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.709)"};
  char *py_result = {"0.7590133"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_297) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.281)+tan(0.506)^atan((0.228/0.228)^(x/0.228))*cos(0.198)-sin(0.12)"};
  char *py_result = {"-0.0543299"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_298) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.944)/ln(0.688)/atan((0.392*0.392)/(0.392/0.392))-sqrt(0.297)^atan(0.525)*ln((0.912-0.912)*(x+0.912))-sqrt(0.207)"};
  char *py_result = {"9.6910385"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_299) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.829)/cos(0.170)/sqrt((0.488*0.488)/(x/0.488))+sqrt(0.561)+0.218"};
  char *py_result = {"1.7707101"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_300) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"680%823"};
  char *py_result = {"680"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_301) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.517)-acos(0.407)^ln((0.546-0.546)+(0.88+0.546))+ln(0.581)/cos(0.658)"};
  char *py_result = {"-0.8408633"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_302) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.199)+atan(0.819)+sin((0.187/0.187)*(0.433^0.187))^atan(0.914)-atan(0.380)-atan((0.525/0.525)+(0.525-0.525))+tan(0.612)/0.904"};
  char *py_result = {"2.1062139"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_303) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.885)+sqrt(0.291)+cos((0.371*0.371)*(0.492/0.371))+sin(0.109)*0.328"};
  char *py_result = {"1.5054559"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_304) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.645)/acos(0.272)-sin((0.619/0.619)-(x+0.619))-asin(0.28)*cos(0.756)^sin((0.374+0.374)/(0.193*0.374))^sin(0.332)+sin(0.658)/log((0.603^0.603)*(x+0.603))-ln(0.537)*acos(0.86)*sin((0.818*0.818)/(0.973*0.818))+cos(0.173)/0.795"};
  char *py_result = {"(-1.217685262141992+0.06094397167596449j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_305) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.706)/tan(0.546)*sqrt((0.777*0.777)*(0.2+0.777))+log(0.518)^atan(0.964)^sin((0.684*0.684)^(0.684+0.684))/log(0.924)+sqrt(0.678)+atan((0.389^0.389)+(0.867/0.389))^asin(0.316)*asin(0.592)+asin((0.436*0.436)^(0.291-0.436))-sqrt(0.258)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_306) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.3)^tan(0.894)^log((0.731*0.731)*(x*0.731))/sqrt(0.372)+asin(0.685)+sin((0.977-0.977)+(0.977^0.977))^sqrt(0.560)+atan(0.178)*log((0.77+0.77)+(0.122^0.77))-acos(0.590)-atan(0.88)^asin((0.850+0.850)*(0.571+0.850))*asin(0.297)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_307) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.852)/ln(0.3)-log((0.314+0.314)-(0.314+0.314))+asin(0.318)*log(0.987)^log((0.766-0.766)-(0.516+0.766))+sqrt(0.389)-tan(0.893)^tan((0.827*0.827)/(x^0.827))*cos(0.764)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_308) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"730%777"};
  char *py_result = {"730"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_309) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.477)*tan(0.296)/tan((0.399/0.399)*(x-0.399))^ln(0.628)/log(0.518)+sqrt((0.885^0.885)*(0.351^0.885))^tan(0.695)/acos(0.181)-sqrt((0.254-0.254)/(0.186/0.254))/sin(0.12)"};
  char *py_result = {"(0.4308150336388533+0.9295074812193524j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_310) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.687)*sin(0.527)-atan((0.436^0.436)*(0.77/0.436))^cos(0.479)*sin(0.63)^sin((0.322*0.322)+(0.322/0.322))/sqrt(0.753)+sqrt(0.892)*sqrt((0.581*0.581)/(0.581^0.581))+sin(0.932)^sqrt(0.374)*tan((0.735*0.735)*(0.338-0.735))-sqrt(0.511)+sin(0.730)"};
  char *py_result = {"0.1665039"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_311) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.923)*sqrt(0.242)+sqrt((0.662*0.662)/(0.263^0.662))/sin(0.779)*sqrt(0.190)/atan((0.315/0.315)-(0.315/0.315))*ln(0.891)-tan(0.80)^cos((0.967/0.967)/(0.967*0.967))^sin(0.355)/atan(0.666)+acos((0.239*0.239)+(0.239-0.239))+asin(0.182)*atan(0.929)"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_312) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.907)+sin(0.73)*sqrt((0.417*0.417)-(x*0.417))*asin(0.738)*log(0.355)+acos((0.821/0.821)+(x/0.821))*tan(0.465)+sin(0.887)*atan((0.662+0.662)-(0.662-0.662))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_313) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.623)+tan(0.224)-acos((0.558-0.558)^(0.558-0.558))+cos(0.411)/sqrt(0.741)/sin((0.263*0.263)*(0.503-0.263))/asin(0.520)/0.527"};
  char *py_result = {"223.73675"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_314) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.995)-log(0.528)+log((0.278*0.278)+(0.993/0.278))+cos(0.698)*log(0.730)-asin((0.609+0.609)*(x-0.609))-acos(0.995)+cos(0.308)-atan((0.722^0.722)+(0.917-0.722))/cos(0.241)*atan(0.294)+ln((0.283^0.283)*(x-0.283))-atan(0.681)+asin(0.100)-tan((0.297*0.297)^(x/0.297))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_315) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.813)/ln(0.418)+log((0.49^0.49)-(0.49-0.49))^asin(0.149)/sin(0.494)*atan((0.572^0.572)-(0.997/0.572))*log(0.336)*asin(0.633)/atan((0.636+0.636)-(x^0.636))+log(0.217)^asin(0.97)^atan((0.871*0.871)^(0.871*0.871))*sqrt(0.534)-0.2"};
  char *py_result = {"(2.004292504840552-0.03320333889689783j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_316) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.130)+sin(0.345)*asin((0.905-0.905)^(0.940*0.905))+sin(0.65)/0.74"};
  char *py_result = {"0.9474536"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_317) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.674)^atan(0.458)^cos((0.173+0.173)*(x*0.173))*atan(0.743)/atan(0.266)^log((0.555-0.555)*(x-0.555))^acos(0.774)+cos(0.510)*cos((0.82+0.82)^(0.82*0.82))^sqrt(0.401)+0.932"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_318) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.272)/log(0.160)*sqrt((0.695+0.695)-(0.695+0.695))+sin(0.340)-0.63"};
  char *py_result = {"-0.2965129"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_319) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.930)-ln(0.290)+acos((0.570-0.570)*(x-0.570))^acos(0.583)^sin(0.871)+sqrt((0.853^0.853)+(0.853*0.853))*acos(0.408)-cos(0.553)+sqrt((0.461/0.461)-(0.461*0.461))+atan(0.709)+ln(0.343)/acos((0.576+0.576)+(x-0.576))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_320) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.517)+tan(0.638)-ln((0.823+0.823)/(x^0.823))*sin(0.678)/0.532"};
  char *py_result = {"-0.9466058"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_321) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.554)^log(0.540)+asin((0.789/0.789)/(0.396^0.789))+sin(0.723)^log(0.544)^acos((0.226-0.226)-(0.226-0.226))/sin(0.852)^ln(0.818)*sin((0.924^0.924)+(0.924-0.924))+asin(0.754)-atan(0.381)/atan((0.57+0.57)-(x-0.57))/ln(0.996)^0.124"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_322) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.551)/cos(0.868)-tan((0.41^0.41)*(0.41/0.41))-asin(0.234)^ln(0.46)/log((0.752^0.752)/(x*0.752))/sin(0.673)^ln(0.991)/tan((0.138/0.138)/(x+0.138))^log(0.344)/asin(0.602)*sin((0.27^0.27)^(x-0.27))/cos(0.912)*asin(0.854)"};
  char *py_result = {"-0.9190695"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_323) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.652)+acos(0.575)+log((0.711+0.711)/(x-0.711))-sqrt(0.182)-cos(0.695)+atan((0.634/0.634)^(x^0.634))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_324) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.860)/log(0.189)+tan((0.463*0.463)-(0.203-0.463))*acos(0.474)+acos(0.816)*tan((0.227*0.227)/(0.227+0.227))*ln(0.441)^sin(0.743)^asin((0.358*0.358)^(x^0.358))+tan(0.704)^tan(0.308)"};
  char *py_result = {"-0.0737973"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_325) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.587)+sin(0.799)*tan((0.412+0.412)^(x/0.412))-asin(0.129)/tan(0.77)+sin((0.210/0.210)/(x/0.210))^asin(0.382)/sqrt(0.956)-tan((0.499*0.499)/(0.499*0.499))-cos(0.351)/sqrt(0.35)^asin((0.509-0.509)/(0.915/0.509))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_326) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.967)*sin(0.913)+ln((0.868/0.868)/(x/0.868))-atan(0.846)*atan(0.962)+asin((0.699-0.699)*(0.21-0.699))+atan(0.884)"};
  char *py_result = {"2.2924427"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_327) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.880)*sin(0.584)-acos((0.661^0.661)/(0.661/0.661))*asin(0.266)^sin(0.374)+ln((0.191-0.191)-(x-0.191))*asin(0.149)+atan(0.519)*sin((0.852/0.852)^(0.119*0.852))^sqrt(0.625)+0.787"};
  char *py_result = {"1.3660709"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_328) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"239%626"};
  char *py_result = {"239"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_329) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.239)-cos(0.862)+tan((0.760+0.760)/(x^0.760))-cos(0.769)+log(0.536)/asin((0.931^0.931)-(x-0.931))-sin(0.845)-log(0.569)/sin((0.351*0.351)-(x/0.351))^sin(0.195)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_330) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.55)/tan(0.164)-tan((0.874/0.874)-(x+0.874))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_331) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.852)-acos(0.844)-log((0.538-0.538)/(0.538*0.538))*sqrt(0.171)*ln(0.458)+tan((0.73*0.73)/(x^0.73))-sin(0.64)+tan(0.325)+acos((0.897+0.897)-(0.112+0.897))-ln(0.67)+ln(0.265)*sqrt((0.565*0.565)*(x*0.565))+ln(0.425)-sqrt(0.833)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_332) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.731)+log(0.417)-tan((0.640+0.640)/(0.76-0.640))^log(0.94)-sqrt(0.860)*log((0.743-0.743)^(0.743+0.743))-atan(0.607)^log(0.304)/acos((0.56+0.56)*(0.56-0.56))^sin(0.246)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_333) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.985)/cos(0.173)*log((0.979-0.979)+(0.979/0.979))^acos(0.148)/asin(0.148)/atan((0.56+0.56)-(0.56/0.56))*atan(0.374)+cos(0.332)^log((0.627*0.627)+(0.669*0.627))^log(0.482)*asin(0.635)-ln((0.4-0.4)^(0.172+0.4))+ln(0.878)+0.183"};
  char *py_result = {"(1.4543170007680073+0.06499949256702942j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_334) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.479)/ln(0.218)*sqrt((0.484/0.484)-(0.484+0.484))/asin(0.153)*sin(0.338)/asin((0.988^0.988)^(x+0.988))+cos(0.597)-atan(0.279)/tan((0.824*0.824)^(0.824-0.824))^asin(0.375)"};
  char *py_result = {"1.8333439"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_335) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.734)-ln(0.804)^atan((0.137*0.137)-(x*0.137))*sqrt(0.60)+0.308"};
  char *py_result = {"0.4346987"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_336) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.802)*log(0.615)-cos((0.820/0.820)^(0.820^0.820))*cos(0.926)*asin(0.797)*asin((0.407/0.407)*(0.407^0.407))-acos(0.627)*sin(0.314)"};
  char *py_result = {"-0.7236677"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_337) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.947)+sin(0.109)*sqrt((0.211/0.211)^(0.722+0.211))*atan(0.225)-ln(0.417)^log((0.693/0.693)^(0.733*0.693))*acos(0.380)/tan(0.860)/acos((0.984^0.984)*(0.844*0.984))+tan(0.992)"};
  char *py_result = {"0.8713040"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_338) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"916%724"};
  char *py_result = {"192"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_339) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.878)*sqrt(0.590)/asin((0.630*0.630)-(0.843^0.630))/atan(0.382)^asin(0.625)+tan((0.210/0.210)*(x^0.210))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_340) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.632)^asin(0.192)+atan((0.60*0.60)^(x+0.60))+tan(0.242)"};
  char *py_result = {"(1.2824976185306733+0.41765099736698696j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_341) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.897)-atan(0.810)^asin((0.927-0.927)+(0.196^0.927))-asin(0.930)/asin(0.939)^asin((0.25^0.25)+(0.25*0.25))*atan(0.959)*tan(0.193)+asin((0.319*0.319)*(x*0.319))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_342) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.706)+atan(0.688)+cos((0.447+0.447)*(x/0.447))^sqrt(0.680)/atan(0.893)-tan((0.777/0.777)/(0.840^0.777))^acos(0.213)+atan(0.189)*atan((0.89+0.89)*(0.89+0.89))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_343) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.112)^ln(0.403)*atan((0.749/0.749)*(0.673-0.749))*sqrt(0.511)*asin(0.224)*asin((0.637*0.637)/(x-0.637))^tan(0.227)/0.921"};
  char *py_result = {"(-0.006855130537980219-0.006081264695410374j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_344) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.76)+atan(0.974)-atan((0.330-0.330)-(0.330-0.330))^atan(0.671)^0.700"};
  char *py_result = {"0.6530412"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_345) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.720)^tan(0.784)^ln((0.51/0.51)*(x/0.51))+atan(0.471)-log(0.190)*acos((0.277+0.277)+(0.277*0.277))/asin(0.954)*0.417"};
  char *py_result = {"1.5283121"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_346) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.244)-sqrt(0.647)/log((0.255/0.255)-(0.255-0.255))/acos(0.467)"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_347) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"760%178"};
  char *py_result = {"48"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_348) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.696)+asin(0.681)-sqrt((0.889-0.889)+(0.889+0.889))*log(0.542)+tan(0.38)"};
  char *py_result = {"1.3458391"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_349) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.378)"};
  char *py_result = {"0.3970955"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_350) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.527)*sin(0.182)^cos((0.463-0.463)/(0.463+0.463))+sqrt(0.826)+acos(0.379)+log((0.370/0.370)*(0.370-0.370))*ln(0.24)^ln(0.512)-acos((0.575^0.575)/(0.998+0.575))^acos(0.535)^sin(0.211)*log((0.354*0.354)^(0.354-0.354))/log(0.450)-sin(0.30)-acos((0.768-0.768)*(0.768/0.768))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_351) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.443)*asin(0.501)+acos((0.669+0.669)-(x+0.669))+sin(0.405)+ln(0.127)+tan((0.292/0.292)+(0.507+0.292))*asin(0.20)+sqrt(0.806)/log((0.424+0.424)-(0.905^0.424))*atan(0.543)^acos(0.583)+asin((0.38*0.38)/(0.379/0.38))/asin(0.12)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_352) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.260)+atan(0.6)+sqrt((0.322/0.322)/(0.322+0.322))*acos(0.469)-ln(0.465)-sqrt((0.858-0.858)/(0.858*0.858))^sqrt(0.949)^0.190"};
  char *py_result = {"1.7647331"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_353) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.938)^atan(0.849)/atan((0.383*0.383)/(0.383/0.383))-cos(0.770)+0.262"};
  char *py_result = {"8.0844153"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_354) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.612)-asin(0.714)+asin((0.994+0.994)/(x-0.994))*asin(0.114)/cos(0.539)+acos((0.870+0.870)^(0.515^0.870))+acos(0.858)-atan(0.942)*atan((0.415*0.415)+(x*0.415))^ln(0.399)-sin(0.271)+tan((0.440/0.440)-(0.613+0.440))^asin(0.714)*acos(0.110)*acos((0.540-0.540)-(0.391+0.540))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_355) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.691)/acos(0.569)-tan((0.870/0.870)+(0.870^0.870))/atan(0.862)/cos(0.715)/log((0.561^0.561)/(0.961-0.561))*log(0.440)-asin(0.69)+ln((0.247*0.247)^(0.395^0.247))*atan(0.431)^sin(0.453)*log((0.819/0.819)/(x-0.819))^sqrt(0.988)/0.285"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_356) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.62)-cos(0.174)*ln((0.872+0.872)+(0.499^0.872))/cos(0.672)*ln(0.753)*atan((0.988-0.988)-(0.988-0.988))/ln(0.532)*tan(0.831)+sqrt((0.147*0.147)+(0.108+0.147))+atan(0.64)/0.238"};
  char *py_result = {"3.4004346"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_357) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.395)"};
  char *py_result = {"0.4060678"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_358) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.119)*atan(0.666)^sqrt((0.63-0.63)+(x*0.63))+tan(0.597)*asin(0.489)+sqrt((0.743^0.743)/(0.743/0.743))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_359) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.59)/ln(0.869)/ln((0.357-0.357)+(x-0.357))-log(0.463)^atan(0.657)^asin((0.622-0.622)+(x-0.622))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_360) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.105)"};
  char *py_result = {"0.3240370"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_361) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.403)/log(0.658)/log((0.357-0.357)/(0.913/0.357))/sqrt(0.437)+ln(0.757)^sqrt((0.426^0.426)+(0.426-0.426))/acos(0.867)^asin(0.151)-asin((0.662*0.662)^(0.662*0.662))*cos(0.402)^0.661"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_362) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.820)/sin(0.800)^log((0.438*0.438)*(0.438+0.438))+ln(0.30)/ln(0.147)^cos((0.116*0.116)-(x^0.116))/acos(0.286)+sqrt(0.854)-ln((0.951-0.951)+(x/0.951))^tan(0.331)/sqrt(0.723)"};
  char *py_result = {"1.6135550"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_363) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.212)-atan(0.124)-ln((0.484+0.484)^(0.754+0.484))/sqrt(0.576)+cos(0.477)^acos((0.194*0.194)^(x*0.194))/asin(0.373)/ln(0.127)*atan((0.41-0.41)^(x^0.41))-sqrt(0.516)*0.622"};
  char *py_result = {"-0.4796028"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_364) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.268)+asin(0.392)/sin((0.586^0.586)+(0.586-0.586))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_365) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.305)-cos(0.608)+cos((0.30*0.30)/(0.30/0.30))-atan(0.239)-sqrt(0.286)-sqrt((0.821^0.821)*(x/0.821))^atan(0.901)+cos(0.188)*ln((0.42-0.42)+(x/0.42))+sin(0.721)^sin(0.989)^asin((0.651+0.651)/(0.739+0.651))+tan(0.55)^0.623"};
  char *py_result = {"0.9552700"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_366) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.210)*sqrt(0.319)-ln((0.725/0.725)^(0.484/0.725))*ln(0.835)^log(0.189)*acos((0.407^0.407)^(x/0.407))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_367) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.259)-log(0.705)^atan((0.953+0.953)+(0.789^0.953))*log(0.560)+sin(0.212)/asin((0.52-0.52)-(0.757-0.52))+sin(0.454)+log(0.610)/asin((0.799/0.799)*(x+0.799))^sqrt(0.372)^0.39"};
  char *py_result = {"(-1.2250325533636472-0.015987044477326507j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_368) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.546)+atan(0.755)*sin((0.338^0.338)+(x+0.338))/sqrt(0.452)-asin(0.872)+ln((0.806^0.806)*(0.804+0.806))-asin(0.516)/atan(0.233)-atan((0.724*0.724)^(0.777/0.724))/tan(0.835)-0.108"};
  char *py_result = {"-1.3545736"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_369) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.803)*tan(0.984)*log((0.212+0.212)*(0.212*0.212))*atan(0.175)*sqrt(0.416)/sqrt((0.115*0.115)*(x+0.115))-log(0.469)^atan(0.797)^sqrt((0.17-0.17)^(x^0.17))*cos(0.964)-tan(0.96)"};
  char *py_result = {"-6.2773698"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_370) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.374)^cos(0.676)+sqrt((0.753^0.753)+(x-0.753))*tan(0.239)+sin(0.47)-sin((0.964/0.964)-(x/0.964))-tan(0.835)"};
  char *py_result = {"-0.3411664"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_371) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.692)*asin(0.785)^tan((0.916-0.916)/(0.435/0.916))*tan(0.940)-log(0.300)/atan((0.966^0.966)*(x-0.966))^tan(0.788)/atan(0.568)^sin((0.392*0.392)-(0.191+0.392))/log(0.97)"};
  char *py_result = {"(45.94627843452381-0.7395636521948429j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_372) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.689)"};
  char *py_result = {"0.5241366"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_373) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.6)+0.709"};
  char *py_result = {"1.5343356"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_374) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.583)*sin(0.279)*sqrt((0.308-0.308)+(0.214+0.308))*sin(0.198)-log(0.478)+sin((0.238^0.238)-(0.238^0.238))-asin(0.71)*cos(0.186)/log((0.795/0.795)*(0.15*0.795))+log(0.501)*acos(0.747)-acos((0.130^0.130)^(0.130/0.130))+atan(0.259)^sqrt(0.158)^ln((0.322^0.322)^(0.322/0.322))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_375) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.868)*atan(0.418)^asin((0.412^0.412)*(0.412+0.412))+sin(0.360)*atan(0.532)-cos((0.238-0.238)/(0.238/0.238))*tan(0.862)*tan(0.731)^sin((0.643^0.643)/(x*0.643))^sqrt(0.272)/sqrt(0.454)+tan((0.198/0.198)/(0.957/0.198))^atan(0.244)"};
  char *py_result = {"-0.7277805"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_376) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.540)-sqrt(0.117)+cos((0.73^0.73)-(0.73+0.73))^cos(0.582)+0.863"};
  char *py_result = {"2.3397504"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_377) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.840)-sin(0.288)*sqrt((0.843^0.843)*(x*0.843))-acos(0.529)*tan(0.998)-sqrt((0.67+0.67)-(0.587^0.67))+tan(0.531)-sqrt(0.770)*atan((0.536*0.536)+(0.536-0.536))*ln(0.588)*cos(0.505)+ln((0.789*0.789)^(x+0.789))+log(0.482)*sqrt(0.802)/tan((0.586/0.586)*(0.586+0.586))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_378) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.4)+ln(0.30)/asin((0.854^0.854)/(0.557^0.854))/log(0.81)-acos(0.102)^log((0.689*0.689)-(0.553-0.689))-ln(0.544)/log(0.464)*ln((0.761+0.761)-(0.291+0.761))^atan(0.106)/sqrt(0.364)/sqrt((0.873-0.873)+(0.873+0.873))*sin(0.708)-sin(0.185)*acos((0.87/0.87)*(0.87-0.87))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_379) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.901)*asin(0.580)-cos((0.480/0.480)+(0.173^0.480))+log(0.888)"};
  char *py_result = {"0.5031165"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_380) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.325)/sin(0.385)^acos((0.783+0.783)+(0.783/0.783))/ln(0.848)+sin(0.664)^sin((0.712^0.712)-(0.535*0.712))/ln(0.529)+0.550"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_381) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.432)*sqrt(0.781)^atan((0.181*0.181)*(x^0.181))*sin(0.414)+ln(0.313)^acos((0.819/0.819)-(x^0.819))^acos(0.145)+acos(0.510)+sqrt((0.551-0.551)*(0.551*0.551))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_382) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.64)/cos(0.273)*sqrt((0.261*0.261)+(0.116-0.261))^sin(0.149)^cos(0.252)^ln((0.375*0.375)^(x*0.375))*atan(0.577)+ln(0.206)/sqrt((0.502/0.502)*(0.897^0.502))^sin(0.56)+cos(0.26)+sqrt((0.473-0.473)*(x/0.473))/sqrt(0.565)-0.499"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_383) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.71)+0.882"};
  char *py_result = {"1.4184933"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_384) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.145)/acos(0.48)^cos((0.637^0.637)*(0.467+0.637))/asin(0.374)*tan(0.225)^acos((0.389/0.389)^(0.389-0.389))*sqrt(0.602)^log(0.90)/acos((0.125/0.125)^(x-0.125))/log(0.9)+ln(0.561)+asin((0.413/0.413)*(0.413*0.413))+cos(0.442)*sqrt(0.992)/acos((0.19*0.19)*(0.368^0.19))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_385) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.148)^log(0.837)*acos((0.771*0.771)*(0.771/0.771))^tan(0.120)/tan(0.142)-log((0.910/0.910)*(0.151^0.910))-cos(0.855)^cos(0.931)^acos((0.442+0.442)^(x*0.442))/sqrt(0.868)^asin(0.133)"};
  char *py_result = {"8.1102360"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_386) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.868)/ln(0.404)+asin((0.167^0.167)-(x/0.167))/tan(0.687)-log(0.481)*ln((0.264/0.264)^(0.759-0.264))-atan(0.35)*sqrt(0.406)/cos((0.983/0.983)/(0.983*0.983))^atan(0.713)^sqrt(0.340)^cos((0.133/0.133)*(0.901+0.133))^log(0.490)/0.838"};
  char *py_result = {"-0.6016379"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_387) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.437)^0.211"};
  char *py_result = {"0.8340770"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_388) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"822%106"};
  char *py_result = {"80"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_389) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.369)-sin(0.788)-cos((0.486/0.486)+(0.125-0.486))-ln(0.40)^cos(0.627)^sin((0.842+0.842)^(x^0.842))+ln(0.748)-asin(0.595)/sin((0.294/0.294)*(0.468-0.294))+sin(0.881)*cos(0.684)+sqrt((0.517*0.517)/(0.438/0.517))^ln(0.161)+tan(0.213)"};
  char *py_result = {"-2.9305696"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_390) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.110)/acos(0.395)*acos((0.674/0.674)-(0.637-0.674))/atan(0.343)^ln(0.816)/sqrt((0.749+0.749)*(0.716/0.749))-tan(0.655)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_391) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.353)/cos(0.666)+acos((0.975^0.975)+(0.975*0.975))+log(0.919)/cos(0.169)*sqrt((0.758/0.758)*(x*0.758))*atan(0.125)-cos(0.466)^asin((0.82-0.82)+(0.727*0.82))-asin(0.593)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_392) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.666)*asin(0.459)^sqrt((0.894+0.894)-(0.448-0.894))*asin(0.645)/cos(0.893)^acos((0.279+0.279)-(0.158*0.279))+acos(0.498)*0.564"};
  char *py_result = {"0.8865759"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_393) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.269)+sin(0.741)+asin((0.121/0.121)^(0.121/0.121))+atan(0.37)^0.782"};
  char *py_result = {"3.6541682"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_394) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.687)^ln(0.505)^asin((0.707*0.707)+(0.707/0.707))-tan(0.143)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_395) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.356)-ln(0.471)*sin((0.344*0.344)+(0.339^0.344))/asin(0.316)*asin(0.332)^cos((0.259^0.259)/(0.16+0.259))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_396) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.761)+ln(0.665)+sin((0.357/0.357)*(0.68^0.357))*sqrt(0.858)+0.62"};
  char *py_result = {"1.7200159"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_397) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.877)^sqrt(0.346)*tan((0.661+0.661)*(x*0.661))*acos(0.227)*atan(0.382)*log((0.575/0.575)/(x/0.575))*tan(0.549)"};
  char *py_result = {"0.0257788"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_398) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.787)^acos(0.748)*asin((0.42-0.42)-(x-0.42))+ln(0.233)+atan(0.641)+acos((0.373+0.373)*(0.373*0.373))*tan(0.656)"};
  char *py_result = {"2.1190778"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_399) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.281)"};
  char *py_result = {"0.2739357"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_400) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.331)/asin(0.590)-atan((0.807/0.807)+(0.98^0.807))*tan(0.163)^asin(0.813)-sin((0.580+0.580)+(x/0.580))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_401) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"771%303"};
  char *py_result = {"165"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_402) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.73)/ln(0.299)/ln((0.475-0.475)*(0.975/0.475))-asin(0.628)*atan(0.100)/tan((0.210^0.210)*(0.938+0.210))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_403) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.63)-asin(0.365)-acos((0.251/0.251)+(0.251-0.251))/ln(0.13)-log(0.173)^sin((0.221^0.221)*(0.987+0.221))-sqrt(0.215)*tan(0.672)"};
  char *py_result = {"(-0.3482017222995201-0.5541315644347607j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_404) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.655)-cos(0.314)-atan((0.876^0.876)*(0.366/0.876))^ln(0.589)-0.606"};
  char *py_result = {"-1.3840424"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_405) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.631)-sin(0.227)/tan((0.561-0.561)^(0.261-0.561))/log(0.86)-sin(0.718)/sin((0.67-0.67)-(x/0.67))/tan(0.587)-tan(0.42)*ln((0.87+0.87)*(0.545*0.87))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_406) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.829)+asin(0.884)/asin((0.489+0.489)-(x/0.489))*atan(0.554)+cos(0.237)+tan((0.189-0.189)-(0.189+0.189))/sin(0.299)/0.48"};
  char *py_result = {"-0.4913199"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_407) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.629)-tan(0.700)^sin((0.539^0.539)*(0.144-0.539))*ln(0.379)/log(0.989)^acos((0.25/0.25)/(x-0.25))-sin(0.350)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_408) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.844)-atan(0.175)^sin((0.455^0.455)/(0.455+0.455))^sqrt(0.680)-ln(0.10)-sqrt((0.491*0.491)*(x^0.491))-log(0.854)/sqrt(0.309)^cos((0.303*0.303)*(0.303^0.303))+cos(0.33)/ln(0.828)^acos((0.961*0.961)^(x/0.961))*acos(0.802)"};
  char *py_result = {"1.2262841"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_409) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.953)/acos(0.563)-sin((0.403*0.403)*(0.403^0.403))+log(0.364)/tan(0.245)*sqrt((0.586^0.586)-(0.586*0.586))-sqrt(0.719)^sqrt(0.121)"};
  char *py_result = {"-1.1461385"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_410) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.472)-atan(0.463)+atan((0.742-0.742)+(0.742+0.742))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_411) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.154)^sqrt(0.941)^acos((0.598^0.598)-(0.364+0.598))-acos(0.589)/tan(0.34)+tan((0.300-0.300)/(0.859+0.300))*sqrt(0.366)+tan(0.351)"};
  char *py_result = {"-2.1225224"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_412) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.918)+acos(0.897)^sqrt((0.11/0.11)^(0.4^0.11))-sqrt(0.920)*log(0.452)-sqrt((0.250+0.250)-(0.250+0.250))/cos(0.930)-ln(0.43)/atan((0.392^0.392)/(0.268*0.392))*cos(0.28)/tan(0.944)-sin((0.521^0.521)*(0.793/0.521))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_413) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.116)/cos(0.570)*sqrt((0.421^0.421)^(x^0.421))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_414) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.643)*sin(0.971)+asin((0.154^0.154)/(0.531^0.154))+ln(0.649)+0.247"};
  char *py_result = {"2.1297877"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_415) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.438)-ln(0.207)+asin((0.548^0.548)*(x-0.548))*acos(0.489)"};
  char *py_result = {"-0.1308139"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_416) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.93)^ln(0.709)*tan((0.139-0.139)-(0.139^0.139))+log(0.164)*tan(0.959)+asin((0.863*0.863)-(0.863^0.863))+cos(0.481)"};
  char *py_result = {"-1.2132503"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_417) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.186)/tan(0.383)*tan((0.335/0.335)^(0.79*0.335))+sqrt(0.205)+atan(0.11)/acos((0.869-0.869)/(0.106*0.869))-acos(0.918)/0.244"};
  char *py_result = {"-0.4893406"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_418) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.278)*tan(0.565)/log((0.744/0.744)*(0.989^0.744))+cos(0.633)^log(0.749)*ln((0.88+0.88)+(0.3^0.88))/sin(0.84)"};
  char *py_result = {"-49.057584"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_419) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.541)*sqrt(0.358)-log((0.450*0.450)-(0.450-0.450))-atan(0.651)-cos(0.769)/ln((0.641-0.641)+(x^0.641))+atan(0.722)/ln(0.431)*sin((0.335/0.335)*(0.898^0.335))+acos(0.388)+atan(0.517)^sin((0.289-0.289)+(x^0.289))*log(0.791)"};
  char *py_result = {"0.3494892"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_420) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.279)-asin(0.451)*asin((0.735^0.735)/(0.359+0.735))*asin(0.644)+sqrt(0.107)*acos((0.369*0.369)-(x*0.369))-atan(0.196)-log(0.827)+sqrt((0.695/0.695)-(x*0.695))*sqrt(0.43)"};
  char *py_result = {"0.9753337"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_421) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.795)^tan(0.699)*ln((0.210^0.210)*(0.210^0.210))-acos(0.608)+log(0.379)+sqrt((0.548-0.548)/(0.548^0.548))^asin(0.173)+atan(0.665)/sqrt((0.421-0.421)+(x-0.421))-ln(0.599)*ln(0.424)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_422) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.953)*atan(0.414)-atan((0.790+0.790)^(0.86+0.790))^log(0.81)*asin(0.134)"};
  char *py_result = {"0.4194884"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_423) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.378)+sqrt(0.41)-atan((0.587-0.587)^(x-0.587))*acos(0.586)/cos(0.788)+acos((0.885-0.885)/(0.741+0.885))+sin(0.981)+sqrt(0.307)*sqrt((0.382^0.382)-(0.382+0.382))*sin(0.413)*acos(0.269)"};
  char *py_result = {"0.0 cannot be raised to a negative power"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_424) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.169)+sqrt(0.113)/acos((0.529-0.529)-(0.529+0.529))+acos(0.734)+atan(0.606)+sin((0.665^0.665)+(0.665^0.665))^cos(0.509)*0.511"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_425) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.148)+cos(0.563)+asin((0.998^0.998)+(0.964^0.998))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_426) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.865)+acos(0.585)/log((0.823-0.823)+(x^0.823))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_427) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.951)"};
  char *py_result = {"1.4013422"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_428) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.404)-atan(0.516)+ln((0.782/0.782)+(x/0.782))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_429) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.400)/log(0.258)*atan((0.952-0.952)-(0.573+0.952))/cos(0.694)/ln(0.159)-acos((0.740-0.740)^(x*0.740))-sqrt(0.673)"};
  char *py_result = {"3.7157900"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_430) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.556)"};
  char *py_result = {"0.9812307"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_431) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.936)+0.362"};
  char *py_result = {"1.7197978"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_432) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.356)^tan(0.777)^asin((0.413^0.413)*(0.379^0.413))^ln(0.111)+acos(0.399)/cos((0.930+0.930)-(x/0.930))^ln(0.76)+tan(0.257)/sin((0.946*0.946)^(x-0.946))+ln(0.796)"};
  char *py_result = {"(-0.3371973769060368-3.6549521604495374j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_433) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"334%651"};
  char *py_result = {"334"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_434) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.835)+sin(0.670)+tan((0.993*0.993)+(0.993*0.993))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_435) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.453)/sqrt(0.487)-log((0.815-0.815)^(0.815*0.815))-ln(0.154)/asin(0.744)-log((0.642/0.642)*(x*0.642))/acos(0.661)+sin(0.185)^atan((0.55/0.55)-(0.55-0.55))/sqrt(0.99)*log(0.950)*asin((0.195*0.195)^(x^0.195))-tan(0.744)-0.931"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_436) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"373%695"};
  char *py_result = {"373"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_437) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.203)/sin(0.407)^sqrt((0.390/0.390)/(0.574-0.390))/asin(0.206)*sqrt(0.457)/asin((0.776-0.776)/(x+0.776))-ln(0.233)^acos(0.480)+cos((0.834^0.834)^(0.951+0.834))/atan(0.193)^0.731"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_438) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.614)-atan(0.150)/sin((0.232+0.232)-(x/0.232))/acos(0.451)/atan(0.286)-ln((0.774*0.774)^(x+0.774))*tan(0.275)+atan(0.170)^sqrt((0.36^0.36)-(x/0.36))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_439) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.207)*cos(0.781)/sin((0.6^0.6)*(x-0.6))/sin(0.869)+sin(0.303)^acos((0.844*0.844)+(x+0.844))/asin(0.783)*sqrt(0.691)+sqrt((0.482^0.482)^(0.482^0.482))-tan(0.882)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_440) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.510)/sqrt(0.607)^cos((0.904*0.904)/(x+0.904))+asin(0.782)-sqrt(0.799)-log((0.644+0.644)*(0.245+0.644))^sqrt(0.851)^atan(0.895)*tan((0.482+0.482)*(0.990-0.482))^ln(0.456)"};
  char *py_result = {"-0.4001983"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_441) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.949)-ln(0.601)-sin((0.295/0.295)-(0.295*0.295))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_442) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.949)^acos(0.499)^cos((0.496^0.496)-(x*0.496))+log(0.739)^asin(0.836)"};
  char *py_result = {"(0.8391805208725169+0.004230919692870945j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_443) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.942)^acos(0.545)+ln((0.720+0.720)/(x*0.720))+ln(0.101)/cos(0.206)/acos((0.696^0.696)-(x*0.696))/tan(0.765)/sqrt(0.917)*acos((0.148*0.148)^(0.148/0.148))-asin(0.734)*asin(0.467)*sqrt((0.525-0.525)/(0.826^0.525))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_444) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.227)*0.727"};
  char *py_result = {"0.9754887"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_445) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.587)/tan(0.781)-cos((0.300-0.300)-(0.885-0.300))*cos(0.280)/cos(0.349)^atan((0.846+0.846)/(x-0.846))+atan(0.182)+sin(0.770)+sqrt((0.656+0.656)/(x-0.656))^tan(0.154)-cos(0.248)/ln((0.662-0.662)/(0.662/0.662))*atan(0.576)/asin(0.651)-sin((0.462^0.462)-(0.462*0.462))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_446) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.755)^cos(0.749)+log((0.942-0.942)*(x-0.942))^cos(0.800)^sqrt(0.626)*asin((0.539-0.539)*(0.895^0.539))*asin(0.67)*0.365"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_447) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.179)+ln(0.895)+atan((0.482*0.482)+(0.103*0.482))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_448) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.429)-cos(0.945)-acos((0.859-0.859)*(0.201*0.859))/cos(0.238)*log(0.458)-cos((0.424/0.424)-(x-0.424))*sin(0.969)^atan(0.868)*acos((0.296+0.296)*(x*0.296))+sin(0.167)+cos(0.896)^sqrt((0.667+0.667)*(0.667*0.667))^sin(0.77)/0.250"};
  char *py_result = {"3.3438654"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_449) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.252)-asin(0.649)*ln((0.110*0.110)/(0.110^0.110))+ln(0.690)^tan(0.396)/sqrt((0.31^0.31)*(0.690/0.31))*cos(0.135)/log(0.357)^atan((0.154/0.154)^(0.395*0.154))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_450) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.81)-sqrt(0.0)-sin((0.902-0.902)/(0.902/0.902))-asin(0.439)+ln(0.664)+tan((0.273*0.273)/(0.273^0.273))+acos(0.270)*sin(0.365)-tan((0.104-0.104)/(0.453/0.104))*log(0.96)^acos(0.208)"};
  char *py_result = {"(1.3487661392013781+0j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_451) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.123)*atan(0.203)^log((0.672-0.672)*(x^0.672))+atan(0.918)^sqrt(0.406)-cos((0.138^0.138)*(0.138+0.138))-sin(0.726)+atan(0.64)*ln((0.113-0.113)/(0.113^0.113))+sqrt(0.32)*sqrt(0.352)/asin((0.747-0.747)*(x/0.747))/acos(0.884)/0.774"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_452) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.770)-log(0.496)*log((0.109-0.109)-(x-0.109))*log(0.356)+log(0.537)^sin((0.800*0.800)/(x/0.800))/acos(0.463)*acos(0.484)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_453) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.75)-tan(0.771)*tan((0.106-0.106)+(x+0.106))^log(0.12)*ln(0.252)*log((0.374-0.374)*(0.374^0.374))-acos(0.186)*log(0.786)/cos((0.834/0.834)^(0.834^0.834))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_454) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.706)/sin(0.172)-ln((0.745/0.745)/(0.82*0.745))-acos(0.869)+asin(0.697)*sin((0.646^0.646)^(x+0.646))/sqrt(0.593)*atan(0.423)+asin((0.984/0.984)+(x*0.984))+tan(0.796)-acos(0.643)+log((0.894-0.894)/(0.105/0.894))+asin(0.714)/ln(0.784)*atan((0.576^0.576)+(0.334-0.576))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_455) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.591)-atan(0.480)^sqrt((0.27/0.27)-(0.804-0.27))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_456) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.193)/ln(0.112)/atan((0.295+0.295)-(0.295-0.295))^acos(0.426)^asin(0.653)+asin((0.157^0.157)/(0.506-0.157))^ln(0.153)/sin(0.379)+sin((0.677+0.677)/(x-0.677))^acos(0.658)+cos(0.515)*acos((0.716/0.716)+(0.716-0.716))-log(0.962)+ln(0.609)/atan((0.2^0.2)+(0.553-0.2))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_457) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.456)*tan(0.470)^ln((0.466^0.466)*(x^0.466))+sin(0.722)^cos(0.23)*ln((0.553^0.553)/(0.673+0.553))+atan(0.462)^tan(0.687)-log((0.845^0.845)^(0.845-0.845))/acos(0.113)^0.4"};
  char *py_result = {"1.5670267"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_458) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.802)*sqrt(0.452)^cos((0.249+0.249)*(x*0.249))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_459) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.679)/sqrt(0.609)^cos((0.82-0.82)/(0.82+0.82))*log(0.542)/atan(0.498)/log((0.453/0.453)+(x*0.453))/ln(0.879)+tan(0.16)"};
  char *py_result = {"6.9525638"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_460) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.317)^asin(0.833)+tan((0.775^0.775)/(0.775+0.775))^sqrt(0.718)/sin(0.111)-tan((0.511-0.511)+(x+0.511))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_461) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.625)"};
  char *py_result = {"0.8956647"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_462) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"550%277"};
  char *py_result = {"273"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_463) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.80)/cos(0.438)*ln((0.241^0.241)^(0.241*0.241))+sqrt(0.874)-ln(0.218)+log((0.202+0.202)*(0.135+0.202))-log(0.578)-atan(0.618)-atan((0.380-0.380)*(x+0.380))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_464) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.327)*asin(0.298)*sin((0.315-0.315)*(x^0.315))/ln(0.36)"};
  char *py_result = {"0.0"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_465) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.430)^asin(0.331)/ln((0.483-0.483)/(0.483*0.483))-tan(0.274)-log(0.24)^ln((0.730*0.730)/(x+0.730))*tan(0.802)-sqrt(0.947)+asin((0.148^0.148)+(x*0.148))+tan(0.813)+0.934"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_466) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.482)^cos(0.811)+asin((0.690^0.690)^(0.124/0.690))/acos(0.178)^sqrt(0.81)+tan((0.260/0.260)+(0.260^0.260))+acos(0.0)*cos(0.188)-asin((0.440/0.440)*(0.440^0.440))^log(0.507)"};
  char *py_result = {"-5.5012567"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_467) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"941%484"};
  char *py_result = {"457"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_468) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.143)-sqrt(0.255)*log((0.26^0.26)^(0.160/0.26))/ln(0.682)-cos(0.757)+sqrt((0.8^0.8)^(x*0.8))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_469) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.794)*sin(0.179)-ln((0.996+0.996)*(0.130+0.996))+ln(0.328)+cos(0.153)+log((0.690^0.690)-(0.880/0.690))-asin(0.610)-asin(0.2)*sqrt((0.78+0.78)*(0.78*0.78))+sin(0.742)*ln(0.545)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_470) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.570)*sqrt(0.727)/sin((0.993+0.993)/(x^0.993))*asin(0.764)*log(0.548)^ln((0.147-0.147)-(x^0.147))-tan(0.215)-atan(0.476)*sqrt((0.123+0.123)-(0.397-0.123))^log(0.213)/sqrt(0.77)-log((0.57^0.57)/(0.57+0.57))-tan(0.559)^ln(0.35)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_471) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.534)+log(0.95)/tan((0.922*0.922)*(0.922^0.922))/cos(0.6)*cos(0.487)-tan((0.90-0.90)/(x/0.90))*acos(0.656)*log(0.823)-asin((0.419+0.419)+(0.419+0.419))/sin(0.220)+tan(0.332)/cos((0.212*0.212)*(0.123/0.212))-sin(0.775)-0.760"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_472) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.637)"};
  char *py_result = {"0.7981227"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_473) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.598)-acos(0.130)^sqrt((0.292*0.292)+(0.292*0.292))/atan(0.259)-asin(0.795)/acos((0.85/0.85)+(x+0.85))*tan(0.438)*log(0.899)/sqrt((0.523/0.523)/(0.523+0.523))+log(0.338)+log(0.875)*tan((0.214+0.214)+(0.967*0.214))-log(0.367)+0.15"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_474) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.107)+0.93"};
  char *py_result = {"1.9242809"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_475) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"908%216"};
  char *py_result = {"44"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_476) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.334)^asin(0.848)-acos((0.468-0.468)*(0.529-0.468))/log(0.261)/tan(0.665)-atan((0.723/0.723)-(x-0.723))-tan(0.359)*atan(0.361)^cos((0.318+0.318)*(x*0.318))+sqrt(0.700)*sqrt(0.937)*ln((0.304^0.304)*(x*0.304))^sin(0.137)-0.292"};
  char *py_result = {"2.8368222"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_477) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.505)+ln(0.430)/tan((0.228+0.228)-(0.470/0.228))+tan(0.222)^0.532"};
  char *py_result = {"0.9330241"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_478) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.657)-ln(0.37)/asin((0.712+0.712)-(x/0.712))-atan(0.435)+asin(0.405)/sqrt((0.465/0.465)+(x*0.465))-asin(0.388)+acos(0.646)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_479) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.576)+acos(0.417)*sin((0.870/0.870)^(0.870/0.870))*sqrt(0.725)-sqrt(0.653)-sqrt((0.242*0.242)*(x+0.242))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_480) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.239)*asin(0.495)-log((0.828/0.828)/(0.828+0.828))*sin(0.531)^tan(0.923)/asin((0.105-0.105)-(0.50-0.105))-ln(0.873)+cos(0.3)-cos((0.944/0.944)^(x+0.944))+log(0.669)+0.492"};
  char *py_result = {"0.0103792"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_481) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.56)"};
  char *py_result = {"0.5311861"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_482) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.48)^tan(0.417)-atan((0.39^0.39)^(0.39^0.39))^sqrt(0.847)/asin(0.66)*atan((0.302*0.302)-(x^0.302))^atan(0.357)+sqrt(0.438)"};
  char *py_result = {"(1.2709761942423994-0.630353750693926j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_483) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.491)*acos(0.869)^tan((0.95*0.95)+(x+0.95))^sin(0.330)-tan(0.964)+sqrt((0.42-0.42)*(x+0.42))^log(0.788)/log(0.747)^acos((0.7*0.7)+(0.889+0.7))*cos(0.100)*0.949"};
  char *py_result = {"0.0 cannot be raised to a negative power"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_484) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.433)*sin(0.797)+acos((0.727*0.727)/(x*0.727))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_485) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.165)/sin(0.638)+atan((0.920^0.920)^(0.857/0.920))*acos(0.136)-acos(0.30)+acos((0.615-0.615)-(0.819+0.615))^cos(0.443)*ln(0.141)/atan((0.962+0.962)/(0.962+0.962))-log(0.195)-log(0.525)*sqrt((0.633^0.633)/(0.633*0.633))/ln(0.717)-atan(0.7)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_486) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.31)"};
  char *py_result = {"0.3006056"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_487) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.159)/cos(0.113)*cos((0.735+0.735)*(x/0.735))*cos(0.484)^atan(0.350)/sin((0.607*0.607)-(0.551*0.607))/atan(0.591)/tan(0.103)-tan((0.766/0.766)*(x+0.766))*cos(0.81)/sin(0.226)/cos((0.287*0.287)-(x*0.287))^ln(0.792)^0.628"};
  char *py_result = {"74.776257"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_488) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.588)+asin(0.672)^cos((0.912^0.912)/(0.912+0.912))/atan(0.3)-sin(0.701)+atan((0.157^0.157)-(0.157^0.157))/ln(0.96)"};
  char *py_result = {"2.6098073"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_489) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.746)/atan(0.592)^asin((0.41^0.41)*(0.41^0.41))*acos(0.158)+ln(0.947)/log((0.556*0.556)^(0.408/0.556))+sin(0.488)+atan(0.20)^sin((0.3+0.3)^(x^0.3))^sqrt(0.206)+asin(0.894)"};
  char *py_result = {"1.4598489"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_490) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.894)-0.465"};
  char *py_result = {"0.2644902"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_491) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.837)*sqrt(0.667)-sin((0.449*0.449)^(0.206^0.449))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_492) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.996)/log(0.38)*atan((0.423*0.423)-(0.8-0.423))/acos(0.369)^ln(0.192)+tan((0.381-0.381)-(0.381-0.381))+cos(0.292)/sqrt(0.419)"};
  char *py_result = {"1.8328994"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_493) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.954)-sqrt(0.849)^acos((0.850*0.850)*(x*0.850))*cos(0.821)*acos(0.103)-acos((0.397/0.397)-(x+0.397))+ln(0.254)^ln(0.82)^sin((0.704/0.704)-(x^0.704))/sqrt(0.537)/sqrt(0.519)+acos((0.261+0.261)/(0.261+0.261))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_494) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.30)+cos(0.674)-atan((0.730-0.730)-(0.730-0.730))*asin(0.507)+tan(0.930)-atan((0.244-0.244)+(x/0.244))-acos(0.564)^ln(0.925)+atan((0.136^0.136)+(x*0.136))-asin(0.865)-asin(0.868)/log((0.657^0.657)/(0.33/0.657))+sin(0.270)"};
  char *py_result = {"-5.9198873"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_495) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.239)^cos(0.706)/asin((0.958-0.958)^(0.998+0.958))-sqrt(0.432)^tan(0.448)/sqrt((0.491*0.491)-(x^0.491))^log(0.870)^ln(0.72)*log((0.14^0.14)/(0.50/0.14))^asin(0.661)-tan(0.120)/asin((0.815+0.815)^(0.815^0.815))-log(0.613)^sqrt(0.201)"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_496) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.409)*log(0.833)-sin((0.17/0.17)+(0.39*0.17))/cos(0.941)*sin(0.965)/acos((0.352/0.352)^(x*0.352))^log(0.729)+log(0.826)+ln((0.370-0.370)-(0.468/0.370))^atan(0.542)+cos(0.168)^log((0.170*0.170)*(0.949^0.170))*sin(0.795)-ln(0.256)/sqrt((0.639^0.639)-(0.639^0.639))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_497) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.449)^log(0.811)^asin((0.488/0.488)-(0.488*0.488))^ln(0.753)"};
  char *py_result = {"(1.09251937182978-0.02407697562537851j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_498) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.965)^asin(0.544)*asin((0.313*0.313)/(0.313/0.313))-ln(0.743)^atan(0.175)*sqrt((0.977^0.977)+(0.580^0.977))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_499) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.596)*sqrt(0.131)*log((0.44^0.44)+(0.44-0.44))*log(0.746)-asin(0.809)+tan((0.544-0.544)/(0.619+0.544))^asin(0.69)^log(0.879)-ln((0.230+0.230)-(0.38/0.230))/atan(0.192)-0.91"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_500) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.724)/atan(0.377)/acos((0.316/0.316)^(x*0.316))+sin(0.917)+asin(0.179)*sin((0.954*0.954)+(0.869^0.954))*ln(0.71)/sqrt(0.673)*tan((0.445+0.445)*(0.445-0.445))/sqrt(0.739)/ln(0.229)/ln((0.297/0.297)/(0.818+0.297))+sin(0.205)/0.990"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_501) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.134)"};
  char *py_result = {"0.1257512"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_502) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.841)*atan(0.781)-sin((0.710*0.710)^(x^0.710))*sqrt(0.576)/acos(0.593)/asin((0.345/0.345)+(0.720-0.345))^sqrt(0.53)+cos(0.118)^log((0.406^0.406)^(x/0.406))^log(0.261)*cos(0.66)*cos((0.764*0.764)+(0.764*0.764))-atan(0.362)*tan(0.156)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_503) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.917)/tan(0.613)-sin((0.824+0.824)+(x^0.824))^sqrt(0.505)^atan(0.776)+sin((0.312^0.312)^(0.312+0.312))*cos(0.845)*log(0.242)-tan((0.718*0.718)^(0.859-0.718))*log(0.13)-asin(0.333)+tan((0.524/0.524)+(0.524-0.524))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_504) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.176)-sqrt(0.258)+cos((0.253^0.253)+(x^0.253))^cos(0.129)^atan(0.603)^cos((0.789+0.789)*(0.789-0.789))-sin(0.640)+log(0.360)-tan((0.447*0.447)+(0.44/0.447))-sin(0.259)^sqrt(0.24)-cos((0.332*0.332)-(x/0.332))-asin(0.493)"};
  char *py_result = {"-5.5540994"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_505) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.54)-sqrt(0.990)+sqrt((0.263-0.263)/(0.346/0.263))+sqrt(0.200)+ln(0.699)*acos((0.60*0.60)^(0.60-0.60))-sin(0.650)*sin(0.945)-sqrt((0.340*0.340)*(x/0.340))^ln(0.949)*0.904"};
  char *py_result = {"-0.9430422"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_506) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.844)-0.265"};
  char *py_result = {"0.8596511"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_507) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.748)-tan(0.275)-tan((0.557^0.557)/(0.742+0.557))+sqrt(0.190)/acos(0.303)*atan((0.150-0.150)+(0.401+0.150))-atan(0.971)*atan(0.652)+acos((0.724/0.724)+(0.123/0.724))+acos(0.981)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_508) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.45)^ln(0.570)*sqrt((0.84+0.84)/(0.198-0.84))-acos(0.443)/atan(0.566)^ln((0.358*0.358)/(0.358/0.358))+sqrt(0.326)*ln(0.674)+acos((0.933-0.933)^(0.933^0.933))/cos(0.574)^asin(0.471)*sqrt((0.44*0.44)^(0.947*0.44))+ln(0.831)^cos(0.641)/tan((0.413+0.413)/(0.536^0.413))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_509) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.36)^cos(0.981)/tan((0.157*0.157)/(x*0.157))/sin(0.628)^asin(0.66)+sqrt((0.670+0.670)^(x^0.670))+sin(0.225)^atan(0.11)*cos((0.693*0.693)^(0.86*0.693))*sin(0.867)-asin(0.898)+sin((0.627+0.627)/(0.627/0.627))+asin(0.107)/sqrt(0.391)+log((0.543*0.543)+(0.543*0.543))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_510) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.670)"};
  char *py_result = {"-0.1739251"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_511) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.217)/sqrt(0.530)^acos((0.752*0.752)/(x/0.752))*cos(0.508)+tan(0.646)+acos((0.595^0.595)/(0.671^0.595))*atan(0.595)-asin(0.319)-sin((0.459-0.459)^(0.459-0.459))/atan(0.523)*ln(0.788)*log((0.81-0.81)^(x/0.81))*asin(0.86)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_512) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.611)/sqrt(0.289)+cos((0.88^0.88)^(0.88-0.88))/atan(0.887)^sqrt(0.99)*atan((0.375^0.375)*(0.695+0.375))/asin(0.263)*0.970"};
  char *py_result = {"1.3295281"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_513) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.488)"};
  char *py_result = {"0.8832723"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_514) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.800)/sin(0.205)*cos((0.359-0.359)^(0.879*0.359))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_515) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.230)+asin(0.21)^log((0.99^0.99)/(0.99/0.99))+cos(0.253)/sin(0.430)^ln((0.888*0.888)-(0.888/0.888))*ln(0.928)^cos(0.567)*sqrt((0.564/0.564)/(0.334/0.564))/cos(0.143)+acos(0.636)-cos((0.663/0.663)-(0.663^0.663))^cos(0.350)/asin(0.411)^asin((0.756+0.756)*(0.366*0.756))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_516) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.610)/sqrt(0.792)^asin((0.230*0.230)^(0.170/0.230))-acos(0.339)*ln(0.464)^acos((0.984-0.984)/(0.984^0.984))-acos(0.134)-ln(0.299)*cos((0.702/0.702)*(0.702^0.702))/acos(0.51)^0.22"};
  char *py_result = {"-1.0986800"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_517) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"801%717"};
  char *py_result = {"84"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_518) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.125)^log(0.300)*sqrt((0.790/0.790)-(0.354/0.790))+ln(0.11)/sqrt(0.221)^ln((0.375*0.375)+(0.375*0.375))+sin(0.374)-tan(0.243)^tan((0.279-0.279)/(0.41*0.279))-tan(0.359)"};
  char *py_result = {"1.3225297"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_519) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.822)/acos(0.254)*sin((0.508^0.508)*(x/0.508))/atan(0.161)/tan(0.178)-atan((0.754^0.754)/(x*0.754))^acos(0.430)^cos(0.734)+ln((0.260^0.260)*(0.260-0.260))-atan(0.509)/acos(0.794)+tan((0.361/0.361)-(x/0.361))*log(0.81)+asin(0.540)-acos((0.421+0.421)*(0.849+0.421))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_520) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.922)-sqrt(0.994)/tan((0.541+0.541)/(0.313+0.541))/ln(0.871)-atan(0.516)^ln((0.319-0.319)+(0.75-0.319))+ln(0.933)/sin(0.642)^sqrt((0.77^0.77)-(x/0.77))-asin(0.660)^log(0.842)+log((0.562-0.562)+(0.562*0.562))^tan(0.701)+0.937"};
  char *py_result = {"(-0.20494086624891938+0.262462339543703j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_521) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.985)*asin(0.402)^log((0.379*0.379)+(0.379*0.379))^tan(0.619)+acos(0.100)^acos((0.19^0.19)+(0.19+0.19))^ln(0.202)^cos(0.702)/log((0.22-0.22)^(0.22*0.22))/sin(0.713)/0.668"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_522) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.592)*acos(0.718)^log((0.556/0.556)/(0.556*0.556))^ln(0.171)-acos(0.253)/ln((0.101*0.101)*(0.101^0.101))*ln(0.198)^sqrt(0.360)-asin((0.93+0.93)/(x-0.93))/asin(0.750)+cos(0.48)/cos((0.628/0.628)^(0.628/0.628))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_523) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.459)*asin(0.534)*tan((0.434/0.434)+(0.434/0.434))*acos(0.34)+asin(0.431)-atan((0.354/0.354)^(0.354-0.354))+ln(0.219)*sqrt(0.817)+asin((0.657-0.657)+(x+0.657))^tan(0.112)"};
  char *py_result = {"0.2635287"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_524) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.719)*cos(0.79)/tan((0.514^0.514)*(0.514/0.514))-atan(0.973)+atan(0.70)-cos((0.229^0.229)^(0.229+0.229))^asin(0.520)^log(0.56)/atan((0.170*0.170)*(x+0.170))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_525) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.106)*cos(0.890)+atan((0.405*0.405)/(0.405-0.405))*ln(0.63)-tan(0.289)-sin((0.951^0.951)/(0.689+0.951))*sqrt(0.420)"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_526) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.917)-ln(0.688)^cos((0.553+0.553)^(0.357-0.553))*cos(0.496)/cos(0.555)*tan((0.482-0.482)^(0.352^0.482))-acos(0.796)+atan(0.912)+tan((0.786+0.786)-(x^0.786))*sin(0.972)-acos(0.39)^atan((0.76+0.76)*(0.76-0.76))/acos(0.246)^0.85"};
  char *py_result = {"3.4930380"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_527) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.901)-cos(0.318)^log((0.804-0.804)+(0.724/0.804))/sin(0.710)/asin(0.517)^cos((0.614-0.614)/(0.614/0.614))*cos(0.110)/sin(0.164)-sin((0.258-0.258)*(x/0.258))*ln(0.379)/acos(0.433)+cos((0.688*0.688)^(x+0.688))*sqrt(0.15)+ln(0.367)^acos((0.125/0.125)^(0.234+0.125))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_528) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.99)-cos(0.318)/sqrt((0.747/0.747)^(0.747^0.747))+sqrt(0.738)-0.585"};
  char *py_result = {"-0.5342539"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_529) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.71)/tan(0.148)+sin((0.560/0.560)^(0.560/0.560))*atan(0.393)^0.436"};
  char *py_result = {"5.7887716"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_530) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.845)^asin(0.60)+cos((0.380^0.380)+(0.121+0.380))*sin(0.567)/sqrt(0.25)-acos((0.923^0.923)+(0.923*0.923))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_531) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.708)^sqrt(0.303)^atan((0.334^0.334)-(x+0.334))+acos(0.217)/asin(0.647)^tan((0.532^0.532)+(0.532^0.532))*sqrt(0.787)/asin(0.544)^log((0.669*0.669)^(0.669+0.669))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_532) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.42)/sin(0.310)/cos((0.520+0.520)^(x*0.520))^sqrt(0.640)-acos(0.371)/atan((0.822*0.822)+(x+0.822))+tan(0.991)^log(0.485)-acos((0.708*0.708)-(x+0.708))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_533) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.6)^asin(0.800)*tan((0.159*0.159)-(x+0.159))-sqrt(0.246)^sqrt(0.389)-atan((0.903+0.903)+(0.48*0.903))*cos(0.937)+log(0.718)-atan((0.117+0.117)*(0.117*0.117))/sin(0.27)*sqrt(0.211)-atan((0.821+0.821)/(x-0.821))-log(0.856)-sqrt(0.152)-tan((0.362*0.362)/(0.362-0.362))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_534) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.374)^asin(0.306)^asin((0.190^0.190)-(0.190-0.190))+cos(0.652)*0.55"};
  char *py_result = {"1.4099848"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_535) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.718)+0.214"};
  char *py_result = {"0.8367046"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_536) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.187)+log(0.85)+sqrt((0.136^0.136)^(x*0.136))-ln(0.931)+sin(0.768)*cos((0.84^0.84)+(0.474+0.84))^sqrt(0.426)*atan(0.117)"};
  char *py_result = {"(0.4275576489516978+0.049757253584897194j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_537) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.332)+cos(0.840)+sin((0.466/0.466)^(0.466^0.466))+sqrt(0.985)*log(0.621)+ln((0.197+0.197)+(0.810/0.197))/sqrt(0.940)-asin(0.152)+ln((0.49/0.49)^(0.617^0.49))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_538) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"271%129"};
  char *py_result = {"13"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_539) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.745)^log(0.233)^acos((0.919/0.919)-(x/0.919))/asin(0.196)+cos(0.966)+asin((0.667^0.667)/(0.115*0.667))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_540) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.922)-0.220"};
  char *py_result = {"0.4333663"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_541) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.289)^sin(0.602)+tan((0.55*0.55)+(0.55+0.55))/log(0.46)+asin(0.944)*sqrt((0.357+0.357)*(0.931-0.357))/cos(0.638)*ln(0.218)"};
  char *py_result = {"-16.798319"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_542) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.54)-0.385"};
  char *py_result = {"-0.6526062"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_543) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.20)^cos(0.841)+atan((0.669*0.669)+(0.669-0.669))-asin(0.280)^tan(0.608)/ln((0.256/0.256)+(0.796-0.256))-atan(0.946)+ln(0.139)*atan((0.24*0.24)+(0.24+0.24))-cos(0.332)^sqrt(0.601)-atan((0.498/0.498)+(0.401/0.498))*log(0.511)^cos(0.10)*atan((0.471-0.471)*(0.517-0.471))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_544) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.795)"};
  char *py_result = {"0.9190075"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_545) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.238)-log(0.263)*atan((0.889-0.889)+(x^0.889))+acos(0.215)-log(0.862)/asin((0.870*0.870)/(0.504+0.870))+asin(0.49)+0.459"};
  char *py_result = {"3.8737788"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_546) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.378)-cos(0.123)^sqrt((0.606*0.606)^(0.606+0.606))-cos(0.997)+acos(0.461)"};
  char *py_result = {"0.7361357"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_547) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.289)+ln(0.492)/ln((0.846^0.846)+(0.123^0.846))*asin(0.817)*cos(0.943)*sqrt((0.770-0.770)-(0.798*0.770))+sqrt(0.228)^atan(0.622)+sin((0.778-0.778)/(x/0.778))/ln(0.369)*acos(0.3)+log((0.899-0.899)*(0.491+0.899))-sqrt(0.734)*0.424"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_548) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.10)-cos(0.293)+cos((0.38/0.38)^(0.647*0.38))/cos(0.335)*acos(0.289)^acos((0.569^0.569)+(0.117^0.569))-sin(0.595)-0.760"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_549) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.27)+sqrt(0.134)^tan((0.965+0.965)*(0.929^0.965))-atan(0.587)-tan(0.443)+sqrt((0.504*0.504)-(0.7^0.504))/cos(0.9)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_550) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.905)+cos(0.998)*tan((0.715+0.715)^(0.29*0.715))/tan(0.513)/ln(0.776)/asin((0.355-0.355)*(0.531^0.355))-log(0.484)/ln(0.878)-atan((0.229*0.229)^(0.229^0.229))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_551) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"140%433"};
  char *py_result = {"140"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_552) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.694)*sin(0.826)+log((0.22^0.22)-(x+0.22))-asin(0.449)^sqrt(0.130)"};
  char *py_result = {"-0.6101802"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_553) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"897%215"};
  char *py_result = {"37"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_554) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.600)+acos(0.492)^acos((0.330^0.330)/(0.665/0.330))*sin(0.3)-cos(0.379)"};
  char *py_result = {"-0.0484200"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_555) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.446)*sin(0.181)-ln((0.394*0.394)/(0.107^0.394))/acos(0.107)/sqrt(0.177)/ln((0.966^0.966)-(0.966^0.966))+cos(0.437)+atan(0.989)^sin((0.965-0.965)-(0.965^0.965))-ln(0.56)*acos(0.928)^log((0.360+0.360)+(0.360^0.360))+asin(0.529)+0.20"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_556) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.905)^atan(0.660)/acos((0.792*0.792)*(x+0.792))+cos(0.427)^acos(0.992)^ln((0.826/0.826)^(0.826/0.826))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_557) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.388)*sqrt(0.979)*cos((0.291+0.291)^(0.291/0.291))*cos(0.209)^sqrt(0.131)/tan((0.929+0.929)+(0.221^0.929))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_558) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.969)^acos(0.119)-sqrt((0.534-0.534)+(x/0.534))^sqrt(0.834)^ln(0.968)*acos((0.814+0.814)*(0.814+0.814))^sin(0.301)-acos(0.357)/tan((0.567*0.567)+(0.567/0.567))^asin(0.454)-acos(0.796)*cos((0.753*0.753)-(0.144*0.753))-ln(0.620)+acos(0.641)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_559) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.257)*atan(0.951)-tan((0.659+0.659)+(0.624-0.659))-sin(0.389)/acos(0.706)/acos((0.274^0.274)*(0.389-0.274))*ln(0.738)+ln(0.330)"};
  char *py_result = {"-3.0979086"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_560) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.131)^acos(0.242)+atan((0.168-0.168)+(x+0.168))+tan(0.933)"};
  char *py_result = {"3.2803040"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_561) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.791)^tan(0.742)^acos((0.779^0.779)*(0.779/0.779))/log(0.250)"};
  char *py_result = {"-1.4861100"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_562) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.415)^sin(0.358)^sqrt((0.598*0.598)*(0.148+0.598))+sin(0.480)/asin(0.997)"};
  char *py_result = {"(0.16405585646610304+0.552480820837518j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_563) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.364)/sin(0.762)/sin((0.262/0.262)+(x-0.262))^tan(0.781)^acos(0.83)+asin((0.777-0.777)^(0.777+0.777))*ln(0.1)-atan(0.637)*atan((0.299^0.299)+(0.299/0.299))*asin(0.851)+atan(0.621)-acos((0.985+0.985)+(0.985^0.985))-log(0.64)+0.692"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_564) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.725)*log(0.686)/log((0.10+0.10)-(0.500+0.10))/tan(0.350)^cos(0.641)-sin((0.831^0.831)*(0.831-0.831))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_565) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.222)+atan(0.914)^sin((0.884-0.884)^(x-0.884))+tan(0.370)+sin(0.351)"};
  char *py_result = {"0.0 cannot be raised to a negative power"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_566) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.582)^sin(0.489)-asin((0.666*0.666)-(0.970/0.666))-sin(0.979)^sin(0.199)/cos((0.357^0.357)*(0.357*0.357))/atan(0.154)-cos(0.457)^asin((0.258^0.258)*(0.258+0.258))-atan(0.535)-cos(0.651)*atan((0.341/0.341)/(0.341+0.341))^acos(0.685)-atan(0.537)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_567) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.621)-ln(0.456)+tan((0.896^0.896)-(0.896+0.896))/log(0.932)"};
  char *py_result = {"40.221191"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_568) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.850)/log(0.767)*tan((0.978^0.978)^(x/0.978))^cos(0.155)/log(0.448)-asin((0.46/0.46)/(0.46*0.46))/cos(0.762)^cos(0.417)^tan((0.573/0.573)^(0.271+0.573))*cos(0.734)^tan(0.966)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_569) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.771)-0.734"};
  char *py_result = {"-0.8469456"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_570) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.336)*tan(0.768)*tan((0.733*0.733)-(0.733^0.733))^sqrt(0.688)-log(0.568)-atan((0.468+0.468)*(0.847+0.468))^sqrt(0.658)-sin(0.499)"};
  char *py_result = {"(-1.236054635583983+0.05616089452543053j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_571) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.923)/ln(0.453)*acos((0.723+0.723)*(0.723-0.723))*sqrt(0.771)^asin(0.37)*sin((0.729/0.729)-(0.729/0.729))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_572) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.986)*cos(0.613)-atan((0.748+0.748)/(0.175-0.748))-log(0.19)/cos(0.272)^atan((0.506+0.506)/(0.506/0.506))^ln(0.762)-sqrt(0.208)/tan((0.194-0.194)-(0.194-0.194))/log(0.169)"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_573) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.6)/sin(0.234)*atan((0.504*0.504)*(0.97-0.504))/cos(0.784)*acos(0.722)/tan((0.491/0.491)+(0.491-0.491))-asin(0.688)+acos(0.45)-atan((0.887^0.887)/(0.887*0.887))^sin(0.375)+0.507"};
  char *py_result = {"-0.1688022"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_574) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.573)^sqrt(0.810)*acos((0.75+0.75)*(0.20^0.75))+tan(0.751)+log(0.800)*cos((0.896^0.896)^(x-0.896))*log(0.926)*cos(0.85)*asin((0.262*0.262)/(0.176*0.262))+asin(0.419)^sqrt(0.141)*cos((0.442^0.442)*(0.489+0.442))^atan(0.36)^cos(0.504)^atan((0.887^0.887)^(x+0.887))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_575) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.5)^acos(0.486)/sin((0.136-0.136)-(0.136^0.136))-sqrt(0.531)-atan(0.929)/sin((0.931/0.931)+(0.811*0.931))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_576) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.402)/ln(0.501)/atan((0.605/0.605)+(0.605/0.605))/sin(0.468)-tan(0.101)^acos((0.307-0.307)*(0.307/0.307))-cos(0.679)/sqrt(0.857)*cos((0.246*0.246)+(0.246+0.246))*ln(0.256)+tan(0.837)^ln((0.604/0.604)^(x/0.604))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_577) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.612)^sqrt(0.866)-atan((0.654/0.654)*(0.654+0.654))^cos(0.283)-cos(0.574)+log((0.600*0.600)+(x^0.600))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_578) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.674)+sqrt(0.344)^sin((0.799/0.799)+(x^0.799))-tan(0.431)^ln(0.197)-cos((0.675^0.675)^(0.427+0.675))*asin(0.78)"};
  char *py_result = {"-0.1219408"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_579) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.451)*log(0.260)*log((0.197+0.197)/(0.681-0.197))+atan(0.323)/sin(0.587)/ln((0.395+0.395)-(0.395*0.395))*cos(0.372)*ln(0.675)^atan((0.98-0.98)+(0.111*0.98))^sin(0.768)^ln(0.115)/log((0.896*0.896)+(0.896+0.896))/sin(0.889)+cos(0.455)"};
  char *py_result = {"3.9583160"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_580) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.605)-0.615"};
  char *py_result = {"-0.0709121"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_581) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.921)*sin(0.379)+tan((0.673-0.673)+(0.454-0.673))+asin(0.319)"};
  char *py_result = {"0.5890105"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_582) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.124)-sin(0.365)/atan((0.640^0.640)^(x*0.640))^log(0.170)/tan(0.648)/cos((0.819*0.819)-(x/0.819))^log(0.413)/atan(0.798)^acos((0.982+0.982)-(0.982+0.982))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_583) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.284)^log(0.183)^tan((0.499^0.499)-(0.776^0.499))^acos(0.912)^acos(0.952)*acos((0.473*0.473)-(0.473*0.473))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_584) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.317)/asin(0.142)+acos((0.88/0.88)-(x/0.88))+acos(0.723)+sqrt(0.641)+tan((0.895-0.895)-(0.895-0.895))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_585) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.959)-sin(0.639)+ln((0.352/0.352)-(x-0.352))-ln(0.961)^atan(0.536)-asin((0.14/0.14)/(0.14+0.14))+ln(0.479)^sqrt(0.302)+cos((0.419+0.419)+(x^0.419))*acos(0.349)-cos(0.134)^atan((0.405*0.405)^(0.765-0.405))-acos(0.483)-sqrt(0.197)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_586) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.213)*asin(0.967)/acos((0.867+0.867)+(0.879+0.867))*sqrt(0.273)+asin(0.973)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_587) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.33)*acos(0.401)^acos((0.36/0.36)+(0.36^0.36))*cos(0.157)*atan(0.599)^asin((0.892+0.892)+(0.892/0.892))+asin(0.949)/sqrt(0.118)-sin((0.747/0.747)^(0.747-0.747))*log(0.108)/atan(0.507)/ln((0.706^0.706)*(0.297+0.706))-sin(0.853)/cos(0.301)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_588) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.501)/asin(0.580)^tan((0.47/0.47)^(x/0.47))-asin(0.535)"};
  char *py_result = {"-1.1984872"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_589) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.355)-sin(0.986)*cos((0.41-0.41)+(x/0.41))*log(0.710)-log(0.201)^ln((0.964-0.964)/(0.964-0.964))^ln(0.995)^sin(0.56)"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_590) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"281%229"};
  char *py_result = {"52"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_591) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.948)/tan(0.131)-tan((0.1+0.1)^(0.458*0.1))+log(0.326)*0.641"};
  char *py_result = {"7.8138123"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_592) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.149)+log(0.823)*acos((0.481+0.481)*(x/0.481))^asin(0.939)*acos(0.850)/atan((0.157+0.157)+(x+0.157))/ln(0.139)^sqrt(0.346)/atan((0.852*0.852)+(x^0.852))^asin(0.234)-atan(0.549)"};
  char *py_result = {"-0.7493529"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_593) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.969)-ln(0.115)-cos((0.447^0.447)^(0.447^0.447))+tan(0.947)"};
  char *py_result = {"1.8894759"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_594) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.967)/log(0.63)-ln((0.495^0.495)+(0.495-0.495))+acos(0.697)^tan(0.947)"};
  char *py_result = {"-2.6308288"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_595) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.692)^asin(0.305)/log((0.426+0.426)-(0.426/0.426))/cos(0.224)+asin(0.688)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_596) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.70)+acos(0.264)+sqrt((0.743*0.743)-(0.84-0.743))*sqrt(0.397)/atan(0.951)/cos((0.991-0.991)*(x+0.991))/acos(0.137)+cos(0.875)*asin((0.722-0.722)*(0.645/0.722))+acos(0.347)-sin(0.76)+tan((0.969-0.969)-(x^0.969))^acos(0.822)/0.20"};
  char *py_result = {"(2.3218767931372537+1.5731835662123674j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_597) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.772)-0.203"};
  char *py_result = {"-0.3153826"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_598) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.106)"};
  char *py_result = {"0.1063987"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_599) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.104)*sin(0.474)+ln((0.194*0.194)*(0.194+0.194))+acos(0.64)^asin(0.795)^atan((0.171*0.171)-(0.165^0.171))+acos(0.336)^asin(0.831)^sin((0.692^0.692)+(0.404*0.692))/sin(0.102)+atan(0.847)"};
  char *py_result = {"14.277076"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_600) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"396%578"};
  char *py_result = {"396"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_601) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.912)^atan(0.868)/sin((0.87*0.87)*(0.87*0.87))*atan(0.449)"};
  char *py_result = {"0.6582418"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_602) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.274)-sqrt(0.738)-asin((0.457*0.457)-(0.457-0.457))/acos(0.926)-atan(0.252)*cos((0.321/0.321)*(0.321*0.321))+acos(0.789)*log(0.134)+tan((0.519^0.519)*(0.519/0.519))/asin(0.314)-atan(0.466)+log((0.500+0.500)+(0.500+0.500))/sqrt(0.412)"};
  char *py_result = {"0.7770505"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_603) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.576)/log(0.619)^acos((0.394^0.394)^(x+0.394))+sqrt(0.150)/sin(0.445)*sin((0.229/0.229)^(0.306*0.229))*ln(0.641)*sin(0.896)^sqrt((0.745+0.745)^(0.61*0.745))+sin(0.216)^ln(0.542)^ln((0.483/0.483)^(x/0.483))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_604) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.770)^ln(0.796)+acos((0.539-0.539)/(x*0.539))-atan(0.872)*atan(0.435)+sqrt((0.380/0.380)+(0.380+0.380))+asin(0.319)-acos(0.387)"};
  char *py_result = {"2.6816178"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_605) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.726)/sin(0.791)^asin((0.745-0.745)-(0.745-0.745))*tan(0.577)-sqrt(0.779)*sqrt((0.918/0.918)*(0.918*0.918))^sin(0.7)+asin(0.367)^log((0.973*0.973)-(0.973^0.973))/sin(0.203)-0.229"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_606) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.692)*log(0.918)/cos((0.26/0.26)+(0.660*0.26))^acos(0.351)"};
  char *py_result = {"-0.0892821"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_607) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.940)-tan(0.640)/sqrt((0.455-0.455)+(x^0.455))^cos(0.922)^sqrt(0.684)+sin((0.0^0.0)*(x/0.0))*log(0.30)^0.569"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_608) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.540)-log(0.525)-tan((0.50/0.50)*(x*0.50))+sqrt(0.623)-asin(0.433)/ln((0.12-0.12)/(x-0.12))+cos(0.282)-log(0.7)*tan((0.933*0.933)/(x*0.933))+asin(0.292)/tan(0.166)+cos((0.43/0.43)+(0.201^0.43))-tan(0.280)-0.188"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_609) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.164)/asin(0.429)-sqrt((0.667*0.667)/(0.962^0.667))+sin(0.146)-sin(0.447)/asin((0.610+0.610)^(0.565-0.610))-tan(0.579)^sqrt(0.804)+tan((0.684/0.684)-(0.102/0.684))*log(0.209)-acos(0.822)-sqrt((0.379^0.379)+(0.393^0.379))-acos(0.100)^log(0.667)"};
  char *py_result = {"-6.7812086"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_610) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.742)/acos(0.267)/acos((0.148/0.148)-(0.148-0.148))^acos(0.966)+cos(0.117)*atan((0.336+0.336)+(0.515/0.336))^log(0.49)*ln(0.102)"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_611) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.122)"};
  char *py_result = {"0.1226089"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_612) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"890%368"};
  char *py_result = {"154"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_613) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.678)^sqrt(0.461)+sin((0.623/0.623)-(x/0.623))*asin(0.768)^acos(0.115)-ln((0.823+0.823)+(0.219^0.823))^cos(0.381)/sqrt(0.527)*ln((0.298/0.298)-(0.298-0.298))-sqrt(0.55)-sqrt(0.490)*atan((0.756/0.756)+(0.223*0.756))+sqrt(0.767)"};
  char *py_result = {"-0.0483769"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_614) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.827)^acos(0.395)+ln((0.693-0.693)-(0.697*0.693))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_615) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.199)/cos(0.769)+sin((0.727+0.727)^(0.852/0.727))^atan(0.524)*acos(0.415)*ln((0.783*0.783)+(0.783^0.783))-log(0.861)-atan(0.71)*tan((0.691/0.691)+(x/0.691))^sin(0.570)-ln(0.738)*acos((0.632/0.632)/(0.632^0.632))*atan(0.102)*0.123"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_616) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.61)^ln(0.794)-acos((0.182/0.182)-(0.182^0.182))*asin(0.824)^sin(0.859)+log((0.584/0.584)^(x/0.584))^asin(0.732)"};
  char *py_result = {"-0.6215142"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_617) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.480)*ln(0.543)-cos((0.342+0.342)-(0.342+0.342))*cos(0.121)-cos(0.197)-ln((0.132+0.132)*(x*0.132))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_618) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"140%824"};
  char *py_result = {"140"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_619) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.150)/sqrt(0.862)*tan((0.712-0.712)-(0.461-0.712))-ln(0.9)*tan(0.51)-asin((0.578^0.578)+(x*0.578))*asin(0.335)*sin(0.395)+ln((0.61*0.61)+(0.61*0.61))-acos(0.223)^atan(0.741)/acos((0.340-0.340)/(0.340+0.340))-asin(0.793)-acos(0.841)^ln((0.445-0.445)-(0.906/0.445))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_620) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.465)-acos(0.394)-log((0.13^0.13)+(x/0.13))*atan(0.677)/acos(0.932)*cos((0.322-0.322)*(0.648*0.322))^acos(0.736)-atan(0.957)/sqrt((0.280*0.280)^(0.172+0.280))^asin(0.466)+atan(0.943)"};
  char *py_result = {"-0.7926065"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_621) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.91)-ln(0.62)+atan((0.296/0.296)/(0.296/0.296))-log(0.677)+tan(0.297)+tan((0.604-0.604)*(x+0.604))-asin(0.360)/sin(0.968)/log((0.711+0.711)/(0.711-0.711))/log(0.728)+0.491"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_622) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.194)/ln(0.261)^tan((0.474/0.474)-(0.655*0.474))-tan(0.39)"};
  char *py_result = {"1.0586560"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_623) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.478)*log(0.787)*ln((0.614^0.614)^(x*0.614))*asin(0.135)/ln(0.908)*asin((0.778+0.778)+(0.778-0.778))/cos(0.581)^sin(0.398)*log((0.757/0.757)+(x*0.757))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_624) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.486)-atan(0.333)+sqrt((0.238*0.238)^(x+0.238))^log(0.684)/asin(0.854)"};
  char *py_result = {"1.2782878"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_625) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.895)+atan(0.735)^ln((0.780+0.780)*(0.780*0.780))-acos(0.633)-asin(0.730)^tan((0.884+0.884)^(0.611/0.884))/cos(0.692)*asin(0.668)+log((0.327/0.327)-(0.327/0.327))+asin(0.367)/sin(0.807)-tan((0.46^0.46)^(0.46^0.46))-tan(0.690)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_626) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.422)*acos(0.195)^log((0.695+0.695)*(0.695^0.695))^cos(0.398)^asin(0.335)-atan((0.482+0.482)/(x^0.482))-asin(0.223)+cos(0.26)-sqrt((0.746*0.746)/(x^0.746))*sin(0.39)"};
  char *py_result = {"0.1431651"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_627) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.469)/tan(0.342)/ln((0.357+0.357)^(0.190^0.357))*sqrt(0.88)^atan(0.722)*asin((0.542-0.542)/(x^0.542))*acos(0.371)-tan(0.657)/atan((0.925/0.925)+(x*0.925))*cos(0.800)^atan(0.951)*asin((0.255*0.255)^(x/0.255))^asin(0.565)"};
  char *py_result = {"-0.2595744"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_628) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.444)^log(0.242)*log((0.763+0.763)-(0.763*0.763))^tan(0.914)-0.461"};
  char *py_result = {"(-0.46907093288354523-0.010894430542870847j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_629) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.230)^acos(0.406)+tan((0.790-0.790)/(0.644-0.790))-log(0.986)+cos(0.829)"};
  char *py_result = {"(0.15305608226250222-0.27509904241457234j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_630) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.983)^cos(0.747)*sqrt((0.31-0.31)-(0.31*0.31))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_631) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.288)-cos(0.486)^acos((0.536*0.536)-(x/0.536))/sqrt(0.778)"};
  char *py_result = {"0.3438194"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_632) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.16)/asin(0.747)/ln((0.104^0.104)^(x/0.104))-cos(0.87)^log(0.272)*sin((0.22*0.22)/(0.22^0.22))^ln(0.831)-cos(0.137)*atan((0.282/0.282)/(0.543/0.282))*sin(0.403)/sqrt(0.929)"};
  char *py_result = {"-0.0883848"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_633) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.554)*0.761"};
  char *py_result = {"0.5664212"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_634) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.503)/log(0.680)/acos((0.269*0.269)-(x+0.269))-sin(0.394)+sin(0.77)-sin((0.83+0.83)/(0.83+0.83))+sin(0.692)^acos(0.763)-tan((0.932^0.932)+(0.401+0.932))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_635) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.734)*atan(0.238)^sin((0.977^0.977)^(x+0.977))-cos(0.722)-acos(0.296)-sin((0.308-0.308)/(0.139^0.308))/asin(0.221)-sqrt(0.239)+cos((0.324/0.324)^(x/0.324))/log(0.572)*ln(0.970)"};
  char *py_result = {"-3.7967633"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_636) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.292)*cos(0.346)^sin((0.160^0.160)/(0.437+0.160))/asin(0.672)-tan(0.171)/atan((0.544/0.544)+(0.607*0.544))/tan(0.119)+cos(0.178)*sin((0.711+0.711)+(0.435/0.711))^asin(0.360)*atan(0.222)*acos((0.110-0.110)^(0.431^0.110))*sqrt(0.102)-tan(0.408)"};
  char *py_result = {"-1.5032089"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_637) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.632)/acos(0.900)-tan((0.731/0.731)+(0.731/0.731))*acos(0.876)/ln(0.137)^acos((0.23-0.23)+(x-0.23))+ln(0.445)-sqrt(0.707)-atan((0.776+0.776)*(0.776/0.776))*sqrt(0.870)"};
  char *py_result = {"32.547030"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_638) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"596%513"};
  char *py_result = {"83"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_639) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.359)-asin(0.14)-ln((0.720+0.720)^(0.720*0.720))+atan(0.281)*atan(0.450)^sqrt((0.500/0.500)^(0.26*0.500))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_640) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.422)*sqrt(0.301)/acos((0.875-0.875)-(x*0.875))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_641) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.143)^tan(0.431)-sqrt((0.181*0.181)+(0.591-0.181))*log(0.481)^atan(0.990)/sqrt((0.40+0.40)-(0.459+0.40))*asin(0.175)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_642) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.74)-acos(0.266)^sqrt((0.863^0.863)*(0.691/0.863))-log(0.672)"};
  char *py_result = {"-0.4007918"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_643) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.520)-log(0.694)/ln((0.604/0.604)*(x^0.604))*sqrt(0.428)^acos(0.447)-tan((0.410*0.410)*(0.410+0.410))^sqrt(0.815)^acos(0.773)*sin((0.104/0.104)/(0.778/0.104))^ln(0.297)-ln(0.744)-ln((0.423+0.423)/(0.860-0.423))-log(0.426)+ln(0.931)"};
  char *py_result = {"0.0766471"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_644) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.607)+0.747"};
  char *py_result = {"1.3174059"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_645) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.60)-log(0.135)/ln((0.456/0.456)/(x/0.456))/sin(0.321)^sqrt(0.507)^sqrt((0.97+0.97)+(0.97+0.97))*log(0.575)*log(0.845)-log((0.490-0.490)/(0.119^0.490))/acos(0.278)*asin(0.689)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_646) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"124%925"};
  char *py_result = {"124"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_647) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.540)-acos(0.780)+asin((0.828/0.828)*(0.828*0.828))*tan(0.107)*tan(0.820)^acos((0.248+0.248)*(x/0.248))^log(0.635)^acos(0.383)+ln((0.271+0.271)+(0.707+0.271))^acos(0.362)/0.222"};
  char *py_result = {"(3.2411816478024877-0.00010618882022656383j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_648) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.44)+ln(0.748)^sqrt((0.296+0.296)/(0.149^0.296))/tan(0.535)/sqrt(0.385)-asin((0.360+0.360)^(0.825+0.360))-ln(0.39)"};
  char *py_result = {"0.8420306"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_649) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.535)^atan(0.300)/log((0.231^0.231)+(0.231/0.231))^cos(0.540)^acos(0.547)/sin((0.205/0.205)+(0.205/0.205))*acos(0.193)*tan(0.327)"};
  char *py_result = {"1.4702541"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_650) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.694)*ln(0.673)+atan((0.381*0.381)*(0.381/0.381))*cos(0.408)-atan(0.831)-cos((0.175^0.175)/(0.175+0.175))/ln(0.93)/0.835"};
  char *py_result = {"0.7635274"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_651) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.258)/atan(0.87)/log((0.67^0.67)-(0.67^0.67))*log(0.998)-log(0.9)+acos((0.447^0.447)/(0.581/0.447))/asin(0.289)*sqrt(0.440)+asin((0.483/0.483)^(0.483+0.483))+log(0.200)^atan(0.301)/cos((0.522+0.522)+(0.865^0.522))*atan(0.939)^asin(0.693)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_652) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.988)*log(0.393)/log((0.973-0.973)+(x+0.973))/ln(0.718)"};
  char *py_result = {"-11.402413"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_653) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.168)+asin(0.74)-cos((0.308-0.308)*(0.308*0.308))*tan(0.131)*asin(0.138)*tan((0.827/0.827)^(x/0.827))+acos(0.710)+atan(0.771)^tan((0.782*0.782)/(0.782^0.782))-sin(0.784)-atan(0.814)+sin((0.90/0.90)^(0.137^0.90))*acos(0.196)*cos(0.639)"};
  char *py_result = {"1.9721919"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_654) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.200)*sqrt(0.86)-tan((0.491^0.491)^(x-0.491))^sin(0.614)-0.77"};
  char *py_result = {"-2.9498187"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_655) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.454)/sin(0.404)/ln((0.391^0.391)^(0.391/0.391))*atan(0.657)-cos(0.266)^atan((0.827/0.827)-(0.827+0.827))*ln(0.566)-acos(0.939)+tan((0.74*0.74)+(x-0.74))+ln(0.677)/tan(0.300)"};
  char *py_result = {"3.3470297"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_656) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.285)*ln(0.356)*cos((0.595+0.595)/(0.185/0.595))/atan(0.57)*cos(0.318)-log((0.1-0.1)-(0.1^0.1))^tan(0.521)/log(0.862)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_657) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.173)-tan(0.185)+sqrt((0.176/0.176)*(0.879/0.176))^log(0.528)*atan(0.370)*log((0.906*0.906)*(0.906+0.906))*ln(0.884)*sqrt(0.358)-sqrt((0.993-0.993)^(0.681^0.993))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_658) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.94)/tan(0.116)*log((0.11+0.11)^(0.11-0.11))^ln(0.651)/asin(0.843)+sqrt((0.829+0.829)^(x+0.829))*ln(0.54)-sin(0.976)-sin((0.918-0.918)/(x^0.918))+sqrt(0.540)^tan(0.875)^asin((0.237+0.237)-(0.913*0.237))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_659) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.696)-sqrt(0.580)*ln((0.401^0.401)*(0.401-0.401))-ln(0.986)/ln(0.520)+cos((0.230^0.230)+(0.230+0.230))^ln(0.218)*tan(0.857)+ln((0.808/0.808)^(0.779*0.808))/cos(0.584)+asin(0.529)^log((0.971^0.971)+(0.971/0.971))+acos(0.220)*acos(0.665)"};
  char *py_result = {"2.8988245"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_660) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.777)*atan(0.170)+sin((0.811*0.811)-(0.811+0.811))-atan(0.298)*acos(0.911)/log((0.748/0.748)+(0.333-0.748))/acos(0.1)/acos(0.990)-asin((0.913-0.913)*(0.913/0.913))^cos(0.538)+sin(0.568)-asin((0.138-0.138)+(0.138^0.138))+atan(0.592)"};
  char *py_result = {"2.0762455"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_661) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.930)/0.171"};
  char *py_result = {"2.2010729"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_662) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"123%853"};
  char *py_result = {"123"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_663) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.3)+log(0.86)*sin((0.417+0.417)+(0.804/0.417))^sin(0.365)+cos(0.720)+sin((0.81+0.81)+(x-0.81))/tan(0.653)^tan(0.186)/sin((0.367+0.367)*(0.367+0.367))-ln(0.66)^log(0.481)/tan((0.804-0.804)*(x+0.804))-cos(0.235)"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_664) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.259)-atan(0.33)-log((0.827-0.827)/(x+0.827))+sin(0.698)-acos(0.559)/acos((0.959/0.959)/(x^0.959))/tan(0.789)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_665) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.325)+cos(0.911)^sin((0.348*0.348)/(0.348-0.348))*acos(0.152)-sqrt(0.685)^tan((0.581+0.581)^(0.996/0.581))+tan(0.376)-atan(0.380)+cos((0.193+0.193)+(x-0.193))*tan(0.53)+acos(0.243)+ln((0.909/0.909)/(x+0.909))-acos(0.345)*0.586"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_666) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.347)/sqrt(0.405)^asin((0.497^0.497)*(x^0.497))*acos(0.906)+asin(0.427)*tan((0.741/0.741)*(x*0.741))^tan(0.701)^tan(0.504)"};
  char *py_result = {"0.3529953"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_667) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.906)+ln(0.412)/log((0.687-0.687)+(0.54+0.687))^cos(0.816)/sqrt(0.732)*asin((0.89+0.89)*(0.683^0.89))+acos(0.565)/ln(0.613)+sqrt((0.649^0.649)/(0.415+0.649))/sin(0.618)/cos(0.895)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_668) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.378)*ln(0.639)^atan((0.36/0.36)-(x^0.36))-log(0.708)*log(0.136)+ln((0.81/0.81)^(x+0.81))/cos(0.115)-acos(0.801)+sin((0.485-0.485)-(0.861-0.485))-acos(0.451)+sin(0.422)"};
  char *py_result = {"-0.4613401"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_669) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.433)"};
  char *py_result = {"0.4086271"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_670) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.901)/cos(0.801)-log((0.15-0.15)/(x^0.15))/cos(0.431)+ln(0.74)+sin((0.837/0.837)*(0.837*0.837))-sqrt(0.869)-ln(0.1)/acos((0.951^0.951)/(0.951+0.951))/asin(0.769)*tan(0.738)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_671) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.327)^acos(0.440)*log((0.885*0.885)/(0.885+0.885))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_672) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.112)*asin(0.769)-log((0.528/0.528)/(x*0.528))-log(0.305)/atan(0.504)"};
  char *py_result = {"0.1083719"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_673) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.894)*sin(0.28)*cos((0.119^0.119)/(x*0.119))^sqrt(0.749)+cos(0.402)+asin((0.806+0.806)^(x^0.806))-sin(0.537)+sin(0.158)^cos((0.729^0.729)-(x^0.729))*cos(0.128)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_674) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.958)"};
  char *py_result = {"-0.0186344"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_675) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.369)*ln(0.520)^cos((0.887-0.887)^(0.887-0.887))*cos(0.218)"};
  char *py_result = {"0.2358878"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_676) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.248)*log(0.245)+sin((0.712^0.712)/(0.354^0.712))*sqrt(0.374)^tan(0.779)^atan((0.701-0.701)-(0.701*0.701))+log(0.706)-0.787"};
  char *py_result = {"-0.9222084"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_677) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.655)^sqrt(0.779)*acos((0.71*0.71)-(0.36^0.71))^ln(0.43)-sin(0.919)+atan((0.156/0.156)^(0.440*0.156))+sin(0.524)/ln(0.502)+sqrt((0.130+0.130)-(0.221*0.130))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_678) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.605)^atan(0.168)/sin((0.819-0.819)-(x-0.819))*atan(0.199)+acos(0.438)+sqrt((0.839^0.839)^(0.839/0.839))-cos(0.723)+sin(0.223)"};
  char *py_result = {"1.8164565"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_679) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.789)+acos(0.853)/ln((0.707*0.707)+(0.707-0.707))/log(0.46)/atan(0.376)+tan((0.293-0.293)+(0.293/0.293))+sqrt(0.859)^sqrt(0.570)*acos((0.24/0.24)*(0.24/0.24))^ln(0.834)*ln(0.298)-tan((0.291+0.291)+(x-0.291))+sin(0.566)-cos(0.677)*acos((0.876^0.876)*(0.876/0.876))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_680) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.371)-ln(0.994)*acos((0.207/0.207)-(0.453/0.207))+asin(0.763)-sqrt(0.57)+acos((0.960-0.960)-(0.960*0.960))+log(0.314)^0.453"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_681) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.697)/log(0.25)+sqrt((0.175+0.175)-(x+0.175))^sin(0.353)*asin(0.954)/atan((0.468+0.468)+(0.468+0.468))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_682) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.621)^sin(0.62)/sin((0.119^0.119)+(0.108^0.119))*ln(0.21)+acos(0.472)*cos((0.282*0.282)^(0.282-0.282))/log(0.385)-atan(0.781)/ln((0.170^0.170)-(0.766+0.170))+sin(0.637)-asin(0.389)^tan((0.702-0.702)/(0.702-0.702))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_683) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.603)+cos(0.45)/sqrt((0.208*0.208)+(0.663/0.208))-sin(0.118)-tan(0.170)*cos((0.489/0.489)-(x+0.489))*cos(0.962)*sin(0.423)-cos((0.458^0.458)^(x*0.458))^atan(0.179)+0.698"};
  char *py_result = {"1.0644034"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_684) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.882)+sin(0.647)^acos((0.469/0.469)+(0.213^0.469))-asin(0.532)*log(0.551)/cos((0.574*0.574)*(x^0.574))*sin(0.732)^0.646"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_685) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.583)+tan(0.401)+log((0.167+0.167)-(0.905/0.167))/tan(0.451)^asin(0.604)+ln((0.444-0.444)^(0.14^0.444))*sin(0.820)+sin(0.169)+sqrt((0.369-0.369)-(0.747-0.369))-tan(0.429)*sqrt(0.396)^sqrt((0.919^0.919)^(0.247/0.919))^asin(0.466)^tan(0.38)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_686) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.224)^asin(0.874)+tan((0.134*0.134)+(0.134-0.134))*asin(0.118)*ln(0.523)*cos((0.959/0.959)/(x*0.959))+sqrt(0.191)"};
  char *py_result = {"0.6380096"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_687) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.848)/0.410"};
  char *py_result = {"1.6133765"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_688) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.585)-acos(0.270)-asin((0.797-0.797)/(0.588*0.797))-atan(0.601)+sqrt(0.31)*acos((0.152-0.152)/(0.152/0.152))+sqrt(0.67)-sin(0.668)/log((0.148/0.148)/(x/0.148))*log(0.341)*0.860"};
  char *py_result = {"-19.680263"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_689) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"392%354"};
  char *py_result = {"38"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_690) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.316)-log(0.315)-tan((0.519*0.519)^(x*0.519))-asin(0.432)+atan(0.514)^sin((0.646^0.646)*(x+0.646))/asin(0.286)/ln(0.673)-sin((0.735+0.735)-(0.524*0.735))-sin(0.22)/sin(0.747)+log((0.754^0.754)/(0.754^0.754))+tan(0.229)-0.125"};
  char *py_result = {"1.5872133"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_691) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"576%671"};
  char *py_result = {"576"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_692) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.313)"};
  char *py_result = {"-0.5044556"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_693) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.132)+ln(0.502)^sqrt((0.968*0.968)+(0.968^0.968))-atan(0.656)-ln(0.655)*acos((0.418+0.418)/(x-0.418))*sin(0.2)^tan(0.374)*tan((0.164^0.164)/(0.164-0.164))^tan(0.377)-log(0.106)-log((0.973/0.973)^(x/0.973))+tan(0.490)^0.674"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_694) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.398)-tan(0.565)/cos((0.748^0.748)^(0.774+0.748))+cos(0.389)-log(0.670)-acos((0.437^0.437)-(0.437/0.437))+acos(0.944)-atan(0.429)^ln((0.655^0.655)*(x+0.655))/tan(0.978)*0.335"};
  char *py_result = {"-1.8326224"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_695) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.810)/ln(0.819)/sqrt((0.805^0.805)+(0.805+0.805))^sqrt(0.953)+atan(0.821)*tan((0.135*0.135)/(0.11^0.135))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_696) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.681)*sin(0.998)-atan((0.914-0.914)+(x+0.914))/atan(0.25)^acos(0.571)/log((0.857*0.857)-(0.325-0.857))^ln(0.271)*ln(0.714)/sqrt((0.288+0.288)^(0.288-0.288))*ln(0.18)*0.751"};
  char *py_result = {"0.1361377"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_697) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.787)+sqrt(0.755)*cos((0.20*0.20)^(0.20-0.20))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_698) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.205)*ln(0.774)^log((0.70*0.70)-(0.70^0.70))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_699) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.776)/sin(0.470)+sin((0.685-0.685)/(x^0.685))+asin(0.105)^atan(0.173)-sqrt((0.604*0.604)*(0.604-0.604))*ln(0.368)/cos(0.568)^atan((0.135^0.135)^(0.106-0.135))^asin(0.710)+sin(0.582)*ln((0.2/0.2)-(0.264*0.2))^ln(0.77)^0.160"};
  char *py_result = {"2.5163909"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_700) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.337)"};
  char *py_result = {"0.3250469"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_701) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.309)+acos(0.709)/ln((0.137-0.137)*(0.308*0.137))-acos(0.557)-asin(0.28)-atan((0.429+0.429)^(0.429/0.429))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_702) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.971)/atan(0.560)-log((0.206/0.206)-(x+0.206))^ln(0.934)+acos(0.115)/tan((0.567^0.567)+(x/0.567))^sin(0.857)^tan(0.431)*log((0.772+0.772)-(0.770/0.772))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_703) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.680)+asin(0.127)*sqrt((0.102/0.102)^(0.102-0.102))/sqrt(0.967)*atan(0.152)/sqrt((0.491^0.491)+(x-0.491))*cos(0.94)-atan(0.661)+asin((0.287^0.287)+(x*0.287))+ln(0.426)*acos(0.384)+acos((0.775-0.775)+(0.509^0.775))*tan(0.853)^log(0.468)^log((0.39-0.39)-(0.613+0.39))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_704) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.539)^sqrt(0.41)^acos((0.925-0.925)^(0.925*0.925))+asin(0.965)*log(0.866)*sqrt((0.269*0.269)+(0.269+0.269))+sqrt(0.956)*atan(0.226)^sqrt((0.87*0.87)^(0.87*0.87))*cos(0.424)*0.960"};
  char *py_result = {"0.8158706"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_705) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.397)-acos(0.660)+sqrt((0.690-0.690)*(0.303+0.690))*tan(0.893)+cos(0.688)-atan((0.173-0.173)+(0.173+0.173))^tan(0.889)-log(0.810)-atan((0.384-0.384)^(x-0.384))^tan(0.685)^tan(0.103)/sin((0.241*0.241)/(0.792-0.241))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_706) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.600)+ln(0.367)-sqrt((0.686^0.686)*(0.686^0.686))*atan(0.528)*atan(0.659)-asin((0.507^0.507)+(x/0.507))/sin(0.288)-ln(0.773)-asin((0.966*0.966)*(0.966*0.966))+ln(0.715)*asin(0.349)+sin((0.489-0.489)/(x-0.489))-sqrt(0.216)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_707) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.422)"};
  char *py_result = {"1.1351460"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_708) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.163)/log(0.998)+sin((0.452*0.452)^(0.373^0.452))-ln(0.962)^sin(0.923)*sin((0.928/0.928)/(x^0.928))^sqrt(0.980)/ln(0.790)^ln((0.347^0.347)-(x*0.347))/sin(0.174)+acos(0.801)+ln((0.989^0.989)/(x^0.989))*asin(0.683)+atan(0.306)*ln((0.893-0.893)*(x/0.893))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_709) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.78)-cos(0.181)^log((0.345+0.345)+(0.855/0.345))/asin(0.879)/tan(0.311)/sin((0.80/0.80)+(x+0.80))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_710) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.831)-cos(0.749)^tan((0.844/0.844)^(x+0.844))+ln(0.911)/atan(0.597)^ln((0.132^0.132)-(x^0.132))+ln(0.677)"};
  char *py_result = {"1.4547369"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_711) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.490)/atan(0.907)+asin((0.93-0.93)-(x-0.93))/sin(0.98)"};
  char *py_result = {"2.0232643"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_712) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.44)+sqrt(0.589)^asin((0.177-0.177)*(0.177-0.177))/acos(0.8)"};
  char *py_result = {"1.9186419"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_713) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.834)*cos(0.838)*ln((0.665*0.665)/(0.348^0.665))*tan(0.771)^sqrt(0.479)/acos((0.713-0.713)+(0.690^0.713))/log(0.953)+0.852"};
  char *py_result = {"-18.464956"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_714) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.863)/cos(0.507)-sqrt((0.989^0.989)/(0.989^0.989))^tan(0.302)^asin(0.621)+cos((0.19^0.19)+(x^0.19))^sin(0.407)/log(0.592)*sin((0.513+0.513)^(0.513-0.513))^cos(0.709)+log(0.938)^ln((0.258/0.258)*(0.258-0.258))^atan(0.981)+0.84"};
  char *py_result = {"-1.0105030"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_715) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.854)*log(0.10)^atan((0.741^0.741)-(x+0.741))-ln(0.831)-atan(0.942)*cos((0.931/0.931)*(0.931-0.931))-asin(0.92)*sin(0.727)+ln((0.747/0.747)-(0.716+0.747))*sin(0.519)+0.668"};
  char *py_result = {"(-1.0545811912581966-0.21514763358508976j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_716) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.578)*0.142"};
  char *py_result = {"0.0875111"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_717) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.848)+sin(0.858)*sqrt((0.785/0.785)+(0.785+0.785))^sqrt(0.211)*sin(0.411)*atan((0.406*0.406)^(x^0.406))*log(0.169)-ln(0.977)/ln((0.970-0.970)^(0.854-0.970))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_718) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.238)/acos(0.343)*tan((0.175/0.175)/(0.744+0.175))-asin(0.643)+tan(0.347)+asin((0.765^0.765)^(x^0.765))-acos(0.832)*ln(0.128)*sin((0.935+0.935)/(x/0.935))+log(0.904)-sin(0.536)-atan((0.213*0.213)^(0.207/0.213))-sqrt(0.817)/atan(0.505)"};
  char *py_result = {"-2.5241446"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_719) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.83)/log(0.62)/sqrt((0.116-0.116)^(0.330^0.116))+sin(0.543)*sqrt(0.297)/cos((0.311+0.311)^(0.460/0.311))/cos(0.917)/cos(0.558)^tan((0.259/0.259)/(0.259-0.259))-sin(0.1)/acos(0.956)*log((0.683-0.683)-(0.479*0.683))+tan(0.873)-0.1"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_720) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"85%584"};
  char *py_result = {"85"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_721) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.197)*cos(0.873)*acos((0.153/0.153)+(0.823^0.153))+log(0.328)*atan(0.85)^log((0.599/0.599)/(x-0.599))-tan(0.183)/ln(0.780)-log((0.722*0.722)-(0.386-0.722))/atan(0.59)^sin(0.844)*atan((0.513*0.513)*(x+0.513))-ln(0.731)^log(0.666)-ln((0.701*0.701)/(x^0.701))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_722) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.532)^0.238"};
  char *py_result = {"0.8164670"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_723) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.248)"};
  char *py_result = {"1.3201811"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_724) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"324%736"};
  char *py_result = {"324"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_725) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.935)/0.990"};
  char *py_result = {"0.9767211"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_726) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.959)^tan(0.66)^atan((0.13^0.13)*(0.861*0.13))^atan(0.536)*0.594"};
  char *py_result = {"0.5825833"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_727) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"761%681"};
  char *py_result = {"80"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_728) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.866)*atan(0.149)-atan((0.932+0.932)^(x/0.932))/tan(0.413)+tan(0.284)-log((0.162*0.162)+(x-0.162))*tan(0.401)"};
  char *py_result = {"-0.7640705"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_729) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.91)/atan(0.370)-sin((0.620^0.620)^(0.620+0.620))+tan(0.693)-asin(0.894)/asin((0.774+0.774)-(0.774^0.774))/log(0.737)/log(0.407)^atan((0.416/0.416)/(x^0.416))/asin(0.57)/0.842"};
  char *py_result = {"(-51.02004193034237+25.354570868662865j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_730) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.841)^sqrt(0.398)+atan((0.854*0.854)/(0.854*0.854))^sin(0.271)/cos(0.264)^atan((0.156-0.156)*(0.156/0.156))^log(0.23)^ln(0.779)"};
  char *py_result = {"0.0 to a negative or complex power"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_731) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.486)"};
  char *py_result = {"0.4670928"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_732) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.180)-ln(0.832)+cos((0.295*0.295)-(x+0.295))+log(0.144)*asin(0.233)"};
  char *py_result = {"0.3144757"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_733) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.91)^cos(0.195)/asin((0.420/0.420)^(0.420/0.420))*tan(0.933)/acos(0.980)*tan((0.945-0.945)*(x-0.945))/ln(0.749)+tan(0.982)+acos((0.482+0.482)^(0.255/0.482))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_734) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.510)^log(0.965)^sqrt((0.613*0.613)+(0.54*0.613))^atan(0.105)/log(0.443)^atan((0.3-0.3)^(0.3^0.3))^acos(0.415)+ln(0.378)*cos((0.897^0.897)*(x-0.897))+cos(0.687)"};
  char *py_result = {"(2.0338143355626226-0.0005950383328189383j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_735) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.395)/tan(0.177)-sin((0.754-0.754)-(0.536*0.754))+asin(0.212)+asin(0.117)/sqrt((0.650*0.650)^(0.650+0.650))^cos(0.530)*tan(0.483)*sin((0.401+0.401)/(0.401/0.401))+acos(0.344)^acos(0.772)^cos((0.797+0.797)+(0.797+0.797))/cos(0.179)+acos(0.550)"};
  char *py_result = {"5.2926855"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_736) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.308)^cos(0.574)+log((0.332^0.332)^(0.602/0.332))^sin(0.745)^sqrt(0.932)/ln((0.81+0.81)/(0.81^0.81))+sqrt(0.514)*atan(0.878)-ln((0.840^0.840)^(0.550*0.840))^sqrt(0.994)*log(0.146)-atan((0.827-0.827)+(0.77-0.827))^cos(0.801)*0.735"};
  char *py_result = {"(1.2689763755797865+0.24852121720337444j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_737) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"253%613"};
  char *py_result = {"253"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_738) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.560)^log(0.848)-cos((0.201-0.201)+(0.650/0.201))+tan(0.856)+sqrt(0.835)+asin((0.508/0.508)+(0.508*0.508))/tan(0.455)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_739) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.746)^cos(0.12)+acos((0.925-0.925)^(0.925^0.925))-asin(0.49)"};
  char *py_result = {"1.7393074"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_740) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.164)-ln(0.466)/cos((0.48+0.48)+(0.536/0.48))^atan(0.939)+atan(0.89)"};
  char *py_result = {"(1.364838640899588+0.4612428290836302j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_741) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.542)-asin(0.161)/acos((0.854-0.854)*(x+0.854))*sin(0.163)-atan(0.875)+tan((0.584/0.584)-(0.887*0.584))-log(0.570)*sin(0.804)-log((0.602^0.602)*(0.136-0.602))*sin(0.607)-asin(0.951)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_742) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.734)-tan(0.853)*cos((0.343-0.343)-(0.461+0.343))-asin(0.761)^sin(0.160)"};
  char *py_result = {"-0.9475465"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_743) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.711)^acos(0.125)/tan((0.244-0.244)*(0.227+0.244))+tan(0.471)-log(0.823)-atan((0.697^0.697)^(x+0.697))+atan(0.915)-0.247"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_744) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.415)/0.929"};
  char *py_result = {"0.6934391"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_745) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.295)+atan(0.290)/sin((0.295-0.295)-(0.921*0.295))^log(0.135)-0.943"};
  char *py_result = {"(0.24585935757920352+0.03579564052177986j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_746) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.161)^asin(0.615)*sqrt((0.966*0.966)+(0.966-0.966))+tan(0.627)/tan(0.296)+sin((0.640+0.640)/(x-0.640))+tan(0.311)/ln(0.409)*ln((0.395-0.395)*(0.182-0.395))+tan(0.792)"};
  char *py_result = {"3.1833175"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_747) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.302)"};
  char *py_result = {"0.3115289"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_748) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.353)^acos(0.558)+sqrt((0.16/0.16)^(x+0.16))*asin(0.447)/sin(0.339)/atan((0.924/0.924)-(x*0.924))^cos(0.869)-ln(0.281)"};
  char *py_result = {"2.0915967"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_749) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.959)+asin(0.648)+asin((0.325+0.325)/(0.325/0.325))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_750) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.601)+cos(0.453)-ln((0.58*0.58)-(x*0.58))^tan(0.447)^sqrt(0.523)+acos((0.917*0.917)+(0.917^0.917))+cos(0.654)^log(0.359)+sqrt((0.873/0.873)/(0.802^0.873))*ln(0.18)/sqrt(0.793)/log((0.783/0.783)^(0.783/0.783))*tan(0.466)^0.341"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_751) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.969)-log(0.527)*ln((0.469*0.469)-(0.469+0.469))+tan(0.750)-cos(0.949)/asin((0.777^0.777)*(x-0.777))*sin(0.161)+acos(0.496)/sin((0.464/0.464)-(x/0.464))*tan(0.977)"};
  char *py_result = {"3.5049755"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_752) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.424)/atan(0.396)+sqrt((0.256-0.256)*(x/0.256))*acos(0.611)+cos(0.135)-log((0.443^0.443)/(0.443^0.443))^tan(0.569)+atan(0.734)/asin((0.39+0.39)^(0.245/0.39))/asin(0.841)"};
  char *py_result = {"4.0255799"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_753) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.370)+tan(0.141)+log((0.350^0.350)^(0.242-0.350))-log(0.225)/sin(0.44)+tan((0.696-0.696)+(0.946-0.696))*ln(0.841)+asin(0.305)*log((0.740-0.740)/(0.740*0.740))+acos(0.988)-atan(0.353)+log((0.511+0.511)-(0.498^0.511))*cos(0.337)^atan(0.54)+cos((0.629^0.629)^(x-0.629))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_754) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.955)+sqrt(0.188)+log((0.733*0.733)^(0.355/0.733))-cos(0.615)*tan(0.691)/sin((0.55/0.55)^(x/0.55))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_755) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.406)*sqrt(0.348)-sqrt((0.948/0.948)-(0.489+0.948))^acos(0.228)-sqrt(0.262)/cos((0.154*0.154)^(x+0.154))*log(0.820)/tan(0.897)*asin((0.49*0.49)*(0.629^0.49))/sin(0.195)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_756) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.886)^acos(0.153)-tan((0.926*0.926)-(0.392/0.926))*log(0.53)/tan(0.874)/sqrt((0.270*0.270)/(x*0.270))*atan(0.662)+log(0.303)+tan((0.726+0.726)-(0.868+0.726))/asin(0.192)/cos(0.401)/sin((0.544/0.544)*(0.544/0.544))*acos(0.509)^tan(0.18)"};
  char *py_result = {"-0.9105436"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_757) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.928)^tan(0.419)-ln((0.463^0.463)-(x*0.463))/asin(0.48)*asin(0.412)*sin((0.645/0.645)^(x-0.645))+sqrt(0.655)/atan(0.621)*asin((0.436+0.436)/(0.436^0.436))^sin(0.159)/acos(0.523)+asin((0.648^0.648)/(0.648-0.648))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_758) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.649)/log(0.848)*asin((0.551+0.551)-(x-0.551))^tan(0.787)+log(0.757)*cos((0.81/0.81)*(x^0.81))/log(0.699)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_759) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.163)*acos(0.525)^acos((0.455+0.455)-(x^0.455))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_760) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.551)*sqrt(0.462)+cos((0.582*0.582)+(x*0.582))/log(0.153)-cos(0.818)*sin((0.176+0.176)/(0.176/0.176))-tan(0.241)/sin(0.242)-cos((0.34^0.34)*(x-0.34))*atan(0.757)*0.199"};
  char *py_result = {"-1.8343786"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_761) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.312)/asin(0.517)/acos((0.124+0.124)-(0.124/0.124))*sin(0.324)"};
  char *py_result = {"0.1351355"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_762) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.458)*asin(0.127)^ln((0.736-0.736)-(0.24+0.736))*asin(0.471)+ln(0.501)+ln((0.562^0.562)*(0.562-0.562))*sin(0.818)^tan(0.614)*sqrt((0.410*0.410)-(x^0.410))*tan(0.974)+sqrt(0.424)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_763) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.749)^asin(0.974)*sqrt((0.459/0.459)/(x-0.459))-acos(0.760)+atan(0.736)/log((0.628*0.628)/(0.47/0.628))/sin(0.579)+tan(0.804)/atan((0.825-0.825)-(x*0.825))*sin(0.769)+sqrt(0.12)+asin((0.632-0.632)^(0.632*0.632))*tan(0.963)+0.973"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_764) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.752)*sin(0.882)*cos((0.284*0.284)-(x/0.284))/asin(0.134)+atan(0.481)*acos((0.392+0.392)/(0.885-0.392))-log(0.945)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_765) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.511)/atan(0.65)-cos((0.205^0.205)^(x*0.205))/cos(0.494)/log(0.967)^log((0.232-0.232)^(0.822/0.232))-sin(0.612)^atan(0.713)+cos((0.209^0.209)-(0.209^0.209))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_766) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.449)*tan(0.214)+cos((0.820+0.820)-(x-0.820))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_767) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.596)*asin(0.707)+atan((0.472+0.472)*(0.66+0.472))-sin(0.431)/log(0.918)^sqrt((0.155^0.155)*(x+0.155))/asin(0.666)-acos(0.829)"};
  char *py_result = {"(0.41483725623861+2.775688122894768j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_768) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.287)-sin(0.931)-sin((0.622+0.622)+(0.239+0.622))*sqrt(0.246)/acos(0.67)-sqrt((0.298^0.298)^(0.298/0.298))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_769) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.180)*sin(0.80)-asin((0.634-0.634)*(0.634*0.634))-sqrt(0.389)*ln(0.211)/sqrt((0.627/0.627)/(x/0.627))*sqrt(0.889)-sqrt(0.575)*sqrt((0.138+0.138)+(0.122*0.138))^asin(0.527)*0.336"};
  char *py_result = {"0.0676859"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_770) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"872%121"};
  char *py_result = {"25"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_771) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.228)+atan(0.995)*sqrt((0.470^0.470)-(0.156^0.470))*atan(0.906)^acos(0.378)^acos((0.274*0.274)/(x*0.274))^ln(0.870)*asin(0.529)*log((0.914/0.914)/(x^0.914))-cos(0.881)^atan(0.432)^sin((0.928^0.928)*(x/0.928))-tan(0.768)-sin(0.260)/asin((0.499/0.499)-(0.296*0.499))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_772) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.383)*0.585"};
  char *py_result = {"0.2299294"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_773) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.203)+atan(0.526)*sin((0.553/0.553)+(x^0.553))/asin(0.662)*atan(0.194)-cos((0.835+0.835)^(0.64-0.835))/tan(0.883)^log(0.500)*cos((0.152+0.152)^(x+0.152))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_774) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.982)*ln(0.718)-log((0.112-0.112)*(0.112*0.112))-ln(0.487)*atan(0.894)/sin((0.997^0.997)/(0.131+0.997))*sqrt(0.683)*0.7"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_775) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.139)/sqrt(0.401)+cos((0.531^0.531)-(0.567^0.531))+tan(0.555)^ln(0.363)/sin((0.9^0.9)^(x^0.9))^sqrt(0.667)-asin(0.368)^cos((0.526/0.526)+(0.526/0.526))*cos(0.287)/sin(0.282)"};
  char *py_result = {"-4.5246660"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_776) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.326)+log(0.518)-atan((0.200+0.200)+(0.200^0.200))/tan(0.3)^0.109"};
  char *py_result = {"-0.9627155"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_777) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.973)-0.756"};
  char *py_result = {"0.7126302"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_778) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.37)+tan(0.891)/sqrt((0.288-0.288)+(0.157+0.288))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_779) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.390)*asin(0.959)-ln((0.687^0.687)*(x+0.687))^sin(0.344)+acos(0.468)/log((0.543-0.543)^(0.490*0.543))/acos(0.997)/acos(0.530)^asin((0.717^0.717)*(0.717+0.717))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_780) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.112)*log(0.677)^acos((0.545^0.545)/(x-0.545))*ln(0.469)+sin(0.169)^cos((0.597-0.597)/(0.136/0.597))*cos(0.883)^sqrt(0.76)*cos((0.54+0.54)+(0.54+0.54))+sqrt(0.507)^cos(0.106)/log((0.921+0.921)*(x/0.921))-ln(0.405)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_781) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.303)^acos(0.170)-atan((0.666+0.666)^(x/0.666))+cos(0.784)+ln(0.455)"};
  char *py_result = {"0.6984977"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_782) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.219)+atan(0.222)/log((0.930-0.930)^(x^0.930))+cos(0.789)+sin(0.668)-acos((0.39^0.39)/(0.299-0.39))*acos(0.923)/tan(0.60)-acos((0.727-0.727)/(x/0.727))+ln(0.108)-atan(0.947)-acos((0.919-0.919)+(0.622*0.919))^cos(0.809)+tan(0.550)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_783) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.582)"};
  char *py_result = {"0.4586898"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_784) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"812%434"};
  char *py_result = {"378"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_785) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.50)"};
  char *py_result = {"0.4636476"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_786) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.531)^acos(0.295)-sin((0.255+0.255)/(0.255*0.255))+asin(0.710)-0.762"};
  char *py_result = {"-0.4641598"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_787) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.800)/asin(0.218)^atan((0.545*0.545)+(x^0.545))*sin(0.708)/sin(0.881)*acos((0.908/0.908)*(x/0.908))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_788) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.422)^asin(0.632)-tan((0.511+0.511)^(0.511^0.511))/sin(0.769)+sqrt(0.969)/tan((0.226/0.226)+(0.226-0.226))/cos(0.759)"};
  char *py_result = {"-0.7024708"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_789) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.593)*sin(0.933)/ln((0.98^0.98)+(0.296-0.98))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_790) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.689)"};
  char *py_result = {"-0.1617807"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_791) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.911)/0.179"};
  char *py_result = {"7.2012712"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_792) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.862)/acos(0.334)*tan((0.505+0.505)*(0.505^0.505))-sqrt(0.95)^cos(0.127)*asin((0.818^0.818)*(0.159+0.818))^tan(0.635)*asin(0.824)+ln((0.623^0.623)-(0.863*0.623))*sqrt(0.786)^0.266"};
  char *py_result = {"0.0775986"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_793) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.238)/sin(0.848)^log((0.331*0.331)+(0.331^0.331))-sin(0.303)*log(0.925)*asin((0.207+0.207)*(0.53+0.207))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_794) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.417)/asin(0.814)*log((0.928+0.928)/(0.928/0.928))*tan(0.197)/sin(0.276)*atan((0.803/0.803)^(0.172^0.803))+sin(0.597)-asin(0.884)+acos((0.634^0.634)^(x-0.634))+cos(0.781)+sqrt(0.433)+acos((0.998/0.998)^(0.998/0.998))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_795) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.786)+log(0.705)/acos((0.531-0.531)*(0.531*0.531))-log(0.637)/0.500"};
  char *py_result = {"1.0017564"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_796) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.222)*tan(0.647)*asin((0.254+0.254)/(x*0.254))-atan(0.373)^asin(0.712)+log((0.622^0.622)*(0.622*0.622))^sin(0.183)^asin(0.987)-acos((0.945*0.945)*(x+0.945))+asin(0.856)^log(0.709)*log((0.192^0.192)*(0.192/0.192))*log(0.242)^0.710"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_797) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.678)/asin(0.562)/ln((0.342/0.342)+(0.342/0.342))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_798) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.346)^ln(0.212)*atan((0.558/0.558)-(0.2*0.558))+ln(0.478)*tan(0.760)*cos((0.137/0.137)-(0.137*0.137))^atan(0.613)+cos(0.907)+tan((0.969*0.969)-(0.969-0.969))+acos(0.898)+asin(0.519)+tan((0.744-0.744)^(0.499+0.744))/ln(0.399)^0.790"};
  char *py_result = {"3.9084389"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_799) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"407%581"};
  char *py_result = {"407"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_800) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.57)-sqrt(0.433)-acos((0.8-0.8)-(0.8+0.8))/asin(0.265)/tan(0.661)*atan((0.626*0.626)/(0.99*0.626))+acos(0.306)+0.173"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_801) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.138)+acos(0.373)^cos((0.758+0.758)/(0.758-0.758))-atan(0.336)+asin(0.636)*acos((0.356/0.356)^(0.292-0.356))*cos(0.570)/sqrt(0.119)*tan((0.228^0.228)/(0.392+0.228))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_802) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.6)/sqrt(0.326)+log((0.491-0.491)+(0.491-0.491))/ln(0.525)/atan(0.2)/acos((0.712*0.712)^(0.552-0.712))-cos(0.621)-ln(0.738)^log((0.134+0.134)-(0.134^0.134))/sin(0.648)-atan(0.504)^ln((0.859-0.859)*(x/0.859))-acos(0.551)*cos(0.581)-sin((0.532/0.532)/(0.532*0.532))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_803) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.130)+sin(0.66)*ln((0.162+0.162)+(0.517+0.162))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_804) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.337)^atan(0.203)^log((0.617*0.617)/(0.617+0.617))^tan(0.330)/acos(0.92)+cos((0.707-0.707)*(0.707-0.707))-sin(0.695)+asin(0.504)/sin((0.190-0.190)+(0.190-0.190))^log(0.963)-asin(0.673)/log((0.519^0.519)^(x+0.519))-asin(0.350)"};
  char *py_result = {"0.0 cannot be raised to a negative power"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_805) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.399)+tan(0.240)/sin((0.249^0.249)+(0.249/0.249))*tan(0.112)^sin(0.197)+asin((0.296^0.296)*(0.540+0.296))/ln(0.976)+sin(0.573)/atan((0.864+0.864)-(0.864-0.864))*atan(0.669)*log(0.137)-sqrt((0.914*0.914)^(0.761+0.914))-cos(0.368)^acos(0.659)-log((0.19/0.19)-(0.36+0.19))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_806) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.179)*acos(0.367)+atan((0.816-0.816)/(0.816+0.816))-acos(0.861)-cos(0.872)*atan((0.438+0.438)^(x-0.438))-atan(0.368)"};
  char *py_result = {"-1.1873727"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_807) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.128)^acos(0.136)^log((0.257^0.257)*(0.606/0.257))-sin(0.344)+sin(0.29)+acos((0.784+0.784)/(x-0.784))*log(0.600)^ln(0.552)*log((0.570+0.570)^(0.725-0.570))^atan(0.46)/acos(0.776)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_808) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.461)*cos(0.166)/cos((0.151+0.151)-(0.151*0.151))+sqrt(0.350)+acos(0.70)/asin((0.754^0.754)^(x*0.754))-cos(0.62)"};
  char *py_result = {"0.7556058"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_809) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.405)*cos(0.65)-cos((0.780/0.780)/(x-0.780))*tan(0.762)^sin(0.403)^sin((0.898-0.898)-(0.703-0.898))-log(0.376)^0.287"};
  char *py_result = {"(0.04265411809947234-0.6134777521406217j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_810) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.565)*cos(0.756)/sqrt((0.177/0.177)^(0.177+0.177))/atan(0.131)+sqrt(0.932)*asin((0.494^0.494)*(0.494-0.494))/ln(0.34)-sqrt(0.253)^ln((0.709/0.709)+(0.21^0.709))-atan(0.841)-cos(0.487)"};
  char *py_result = {"0.8486230"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_811) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.595)*asin(0.188)^tan((0.401/0.401)/(0.401+0.401))^atan(0.324)/tan(0.879)*cos((0.875^0.875)/(0.566*0.875))-atan(0.856)+tan(0.76)/log((0.69/0.69)-(x*0.69))^cos(0.315)^tan(0.329)/atan((0.145/0.145)^(0.145^0.145))/ln(0.182)^ln(0.11)"};
  char *py_result = {"(-29.415076795422202-1.54126175615361j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_812) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.218)/tan(0.234)/asin((0.259/0.259)^(0.24*0.259))/asin(0.967)*sqrt(0.875)+sqrt((0.468*0.468)/(x*0.468))/tan(0.585)-acos(0.780)-asin((0.18+0.18)-(x-0.18))/sin(0.921)/sqrt(0.917)-acos((0.569/0.569)+(x^0.569))/atan(0.763)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_813) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.278)"};
  char *py_result = {"0.2711531"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_814) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.68)"};
  char *py_result = {"0.5971766"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_815) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.79)^ln(0.479)/cos((0.571^0.571)/(0.331+0.571))-sin(0.909)*cos(0.241)/atan((0.148/0.148)+(x*0.148))-cos(0.649)*tan(0.811)*sqrt((0.116/0.116)-(x*0.116))*ln(0.149)-0.260"};
  char *py_result = {"(-1.139291513350249+0.5572485233667458j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_816) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.188)*asin(0.853)+sqrt((0.608^0.608)+(0.608-0.608))^sin(0.37)/cos(0.764)/ln((0.714-0.714)/(0.264+0.714))-atan(0.32)-ln(0.541)*ln((0.947+0.947)-(x*0.947))^sqrt(0.841)/0.217"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_817) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.954)-log(0.511)+sin((0.442-0.442)-(0.48-0.442))*sqrt(0.959)/ln(0.599)-acos((0.906^0.906)*(0.138+0.906))+atan(0.204)"};
  char *py_result = {"1.3776547"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_818) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.506)*sin(0.186)-acos((0.683*0.683)/(0.66-0.683))/cos(0.637)*ln(0.811)-atan((0.894*0.894)+(0.894*0.894))^cos(0.561)/sin(0.488)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_819) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.938)-sin(0.819)/sqrt((0.460^0.460)/(0.899*0.460))/atan(0.984)"};
  char *py_result = {"-0.1310604"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_820) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.911)*sqrt(0.266)/acos((0.465*0.465)^(x-0.465))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_821) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"251%960"};
  char *py_result = {"251"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_822) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.656)^tan(0.335)/log((0.198+0.198)-(0.806/0.198))*log(0.107)*cos(0.135)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_823) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.773)-acos(0.420)^acos((0.582^0.582)^(0.488^0.582))/sin(0.439)/tan(0.140)*acos((0.876^0.876)+(0.876+0.876))-sin(0.765)^tan(0.929)^ln((0.142-0.142)+(0.142^0.142))-atan(0.331)+ln(0.818)*sqrt((0.371+0.371)-(x+0.371))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_824) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.142)*tan(0.987)/asin((0.506-0.506)-(x^0.506))*atan(0.617)"};
  char *py_result = {"-0.2990604"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_825) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.211)/asin(0.893)/cos((0.100^0.100)^(0.100*0.100))+ln(0.544)/sqrt(0.60)*acos((0.596*0.596)/(0.596*0.596))/sin(0.943)-sin(0.161)^sin((0.612/0.612)/(0.612-0.612))-log(0.662)-0.752"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_826) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.542)^atan(0.756)/log((0.622^0.622)/(0.26^0.622))^atan(0.491)-sin(0.835)-ln((0.575-0.575)^(0.575^0.575))^asin(0.780)-asin(0.840)"};
  char *py_result = {"-0.1520896"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_827) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.194)*asin(0.89)*log((0.341+0.341)^(x/0.341))/ln(0.724)+asin(0.98)/cos((0.493^0.493)^(0.493^0.493))-cos(0.288)/log(0.533)+atan((0.70*0.70)+(0.70-0.70))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_828) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.789)*cos(0.877)+tan((0.567*0.567)/(x*0.567))^cos(0.769)/sin(0.296)*sin((0.591^0.591)*(x/0.591))/sin(0.965)^ln(0.653)^sin((0.43^0.43)+(x^0.43))*tan(0.127)+asin(0.33)/atan((0.523-0.523)^(x+0.523))^tan(0.816)+atan(0.624)"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_829) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.284)+0.764"};
  char *py_result = {"1.0441976"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_830) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"483%742"};
  char *py_result = {"483"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_831) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.80)/acos(0.15)+sqrt((0.935*0.935)+(0.293-0.935))+asin(0.644)-sin(0.514)+ln((0.125+0.125)*(0.778+0.125))/sqrt(0.941)+asin(0.733)-sin((0.601^0.601)+(0.601+0.601))^asin(0.330)^cos(0.484)+atan((0.246^0.246)^(0.246^0.246))-atan(0.629)"};
  char *py_result = {"1.5043931"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_832) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.765)-atan(0.535)+atan((0.849*0.849)/(x*0.849))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_833) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.287)/tan(0.515)/cos((0.397^0.397)-(x+0.397))-tan(0.901)-atan(0.454)+sin((0.421*0.421)+(0.358-0.421))/tan(0.509)+tan(0.260)^ln((0.431^0.431)/(x-0.431))^cos(0.677)+log(0.942)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_834) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.953)+asin(0.67)-cos((0.721^0.721)*(0.94^0.721))*sqrt(0.207)-atan(0.2)+log((0.646*0.646)+(0.134*0.646))-tan(0.696)-sqrt(0.799)"};
  char *py_result = {"-1.1520427"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_835) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.946)^cos(0.761)+log((0.934/0.934)/(0.934*0.934))+asin(0.281)*cos(0.230)*cos((0.466^0.466)/(0.307^0.466))+cos(0.578)"};
  char *py_result = {"1.4417385"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_836) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.104)*sin(0.903)-acos((0.440+0.440)^(x*0.440))/ln(0.746)^asin(0.5)*cos((0.439*0.439)/(0.825-0.439))-asin(0.704)"};
  char *py_result = {"-0.8548513"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_837) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.280)+tan(0.507)*log((0.428*0.428)^(x/0.428))*sin(0.122)+tan(0.645)-sin((0.883+0.883)^(x^0.883))^sqrt(0.669)/atan(0.11)/acos((0.195-0.195)/(x/0.195))^asin(0.485)+0.391"};
  char *py_result = {"-6.0738563"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_838) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.163)^asin(0.77)*acos((0.71/0.71)*(0.71+0.71))-cos(0.834)/asin(0.659)-sqrt((0.827*0.827)+(x*0.827))^sqrt(0.877)/tan(0.325)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_839) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.459)*cos(0.152)-cos((0.220/0.220)+(0.220/0.220))+atan(0.114)^0.470"};
  char *py_result = {"0.4414970"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_840) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.420)*ln(0.792)*cos((0.447^0.447)*(0.346-0.447))^sin(0.65)*cos(0.375)+ln((0.747^0.747)-(0.747^0.747))*sin(0.618)*atan(0.774)/sin((0.889/0.889)*(0.762+0.889))-sqrt(0.815)*ln(0.690)*sqrt((0.585/0.585)+(0.585+0.585))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_841) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.603)+atan(0.39)+cos((0.217*0.217)+(0.544^0.217))^log(0.65)*cos(0.2)/asin((0.34*0.34)/(0.34+0.34))+tan(0.430)"};
  char *py_result = {"7.9603437"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_842) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.146)"};
  char *py_result = {"1.4242725"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_843) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.921)/sqrt(0.822)+acos((0.770^0.770)^(0.662+0.770))^tan(0.275)+sin(0.260)+atan((0.267^0.267)/(x+0.267))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_844) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.732)+ln(0.757)^ln((0.593/0.593)^(x+0.593))-sin(0.146)-ln(0.662)*sin((0.523*0.523)-(0.523/0.523))*acos(0.176)+acos(0.705)-acos((0.382^0.382)^(x+0.382))/log(0.54)"};
  char *py_result = {"4.8725745"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_845) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.675)/atan(0.121)/log((0.453+0.453)^(0.608+0.453))^log(0.49)*tan(0.206)/asin((0.949+0.949)^(0.625-0.949))/log(0.288)+cos(0.641)^tan((0.693-0.693)*(0.153/0.693))^asin(0.106)^0.808"};
  char *py_result = {"(0.42933125549200235-0.8386018965613994j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_846) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"969%55"};
  char *py_result = {"34"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_847) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.761)*cos(0.120)*ln((0.332/0.332)/(0.332+0.332))-log(0.332)*sin(0.526)/ln((0.743/0.743)^(x+0.743))+atan(0.477)-asin(0.115)+log((0.156^0.156)-(x+0.156))+log(0.667)-atan(0.279)*ln((0.538/0.538)+(0.538/0.538))-sqrt(0.432)+atan(0.125)"};
  char *py_result = {"0.1082919"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_848) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.79)*log(0.800)-sin((0.155*0.155)-(0.936/0.155))^tan(0.914)/tan(0.729)-cos((0.520/0.520)+(0.461-0.520))*atan(0.541)/0.495"};
  char *py_result = {"-0.8585428"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_849) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.200)-tan(0.219)/atan((0.125-0.125)/(0.125*0.125))+tan(0.122)^ln(0.741)+acos((0.1/0.1)-(0.1^0.1))-atan(0.558)+sqrt(0.791)"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_850) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.471)*atan(0.68)-sqrt((0.29+0.29)-(0.296*0.29))/log(0.801)/log(0.728)^cos((0.462-0.462)*(0.576/0.462))*log(0.61)/acos(0.162)+atan((0.597/0.597)^(0.597/0.597))/asin(0.140)^cos(0.614)/log((0.686+0.686)-(0.273*0.686))*acos(0.377)+sin(0.239)"};
  char *py_result = {"71.415194"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_851) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.523)*asin(0.674)^tan((0.898^0.898)+(0.898*0.898))/acos(0.849)*log(0.302)*ln((0.92^0.92)^(x-0.92))-log(0.412)-tan(0.112)+sin((0.550*0.550)*(0.550^0.550))+acos(0.572)^sin(0.687)+log((0.76*0.76)/(x/0.76))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_852) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.750)/ln(0.371)^atan((0.623/0.623)/(0.187-0.623))/atan(0.248)*asin(0.711)+asin((0.21+0.21)/(0.21+0.21))^ln(0.989)-tan(0.661)+tan((0.381+0.381)/(0.381^0.381))*ln(0.839)^sin(0.911)"};
  char *py_result = {"2.7120695"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_853) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.283)*log(0.957)-sqrt((0.274+0.274)*(0.481^0.274))/ln(0.706)*sqrt(0.126)/log((0.562-0.562)/(0.562/0.562))-atan(0.863)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_854) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.18)+0.166"};
  char *py_result = {"-0.5787274"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_855) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.366)"};
  char *py_result = {"0.3578832"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_856) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.694)"};
  char *py_result = {"0.6396170"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_857) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.439)+ln(0.291)+log((0.40/0.40)*(0.40*0.40))/asin(0.759)^ln(0.200)+log((0.211*0.211)/(x/0.211))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_858) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.799)+cos(0.644)+asin((0.357+0.357)^(0.347+0.357))-acos(0.333)/ln(0.329)/atan((0.587/0.587)/(0.59-0.587))/ln(0.132)-asin(0.223)-log((0.34*0.34)*(x-0.34))^cos(0.164)^0.664"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_859) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.319)-0.335"};
  char *py_result = {"-0.0047200"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_860) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.449)^ln(0.733)^cos((0.760/0.760)/(x/0.760))-atan(0.703)/acos(0.193)+cos((0.948^0.948)+(0.540+0.948))/cos(0.554)^0.280"};
  char *py_result = {"-0.8118654"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_861) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.116)*asin(0.981)+ln((0.203+0.203)-(0.203^0.203))-sin(0.79)/tan(0.817)/ln((0.264+0.264)/(0.264*0.264))-cos(0.927)+sqrt(0.952)-cos((0.625/0.625)+(0.400^0.625))^cos(0.475)*cos(0.634)-ln((0.809*0.809)/(x*0.809))+ln(0.857)^cos(0.48)/sin((0.862/0.862)-(0.377*0.862))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_862) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.617)*acos(0.380)/asin((0.578+0.578)^(0.578*0.578))*log(0.241)-acos(0.402)*atan((0.855^0.855)*(x+0.855))/atan(0.296)+sqrt(0.498)-sin((0.358^0.358)+(x-0.358))+ln(0.866)+sin(0.373)-sin((0.61-0.61)/(x*0.61))-tan(0.450)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_863) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.50)/sqrt(0.514)*ln((0.35/0.35)+(0.940+0.35))/sqrt(0.353)*tan(0.23)^tan((0.390+0.390)-(0.390/0.390))+asin(0.914)-asin(0.636)/ln((0.784*0.784)+(x-0.784))/ln(0.129)^cos(0.891)"};
  char *py_result = {"153.05072"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_864) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.301)+ln(0.837)/ln((0.466^0.466)+(0.355+0.466))*asin(0.260)/asin(0.718)"};
  char *py_result = {"0.5216690"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_865) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.425)/log(0.208)^atan((0.179/0.179)*(x/0.179))-tan(0.93)-log(0.429)+ln((0.279^0.279)*(0.279^0.279))+cos(0.600)-0.963"};
  char *py_result = {"(-1.600600003462523-1.1863333769950115j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_866) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.54)-sqrt(0.316)*sqrt((0.429/0.429)+(0.429-0.429))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_867) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.752)/log(0.708)-atan((0.404/0.404)*(0.424^0.404))/log(0.603)*cos(0.507)-sqrt((0.271*0.271)^(0.900*0.271))/acos(0.89)^ln(0.175)*atan((0.635-0.635)^(x^0.635))-atan(0.956)*0.942"};
  char *py_result = {"-4.0520227"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_868) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.965)"};
  char *py_result = {"1.4436679"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_869) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.247)*acos(0.246)/tan((0.840/0.840)+(0.840*0.840))-sin(0.435)^ln(0.29)*ln((0.974+0.974)^(0.974^0.974))+atan(0.994)-asin(0.258)+atan((0.799/0.799)/(x-0.799))*asin(0.524)-sin(0.853)/asin((0.729/0.729)-(0.113*0.729))^atan(0.633)*tan(0.200)"};
  char *py_result = {"-1.0724217"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_870) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.515)*ln(0.241)+tan((0.685*0.685)/(0.801*0.685))+acos(0.449)/cos(0.189)-acos((0.235-0.235)-(x^0.235))/tan(0.178)*cos(0.297)*sqrt((0.327/0.327)^(0.327-0.327))*ln(0.912)"};
  char *py_result = {"-5.4333387"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_871) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.389)+sqrt(0.24)^atan((0.675/0.675)+(0.228^0.675))+sin(0.693)-atan(0.736)-acos((0.942+0.942)*(0.96+0.942))+atan(0.663)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_872) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.786)-atan(0.149)*cos((0.733^0.733)^(x^0.733))+ln(0.536)-acos(0.655)^atan((0.623^0.623)^(0.140^0.623))*asin(0.980)-sqrt(0.679)/sqrt((0.281+0.281)/(x^0.281))+atan(0.238)^log(0.698)-acos((0.950/0.950)/(x-0.950))^asin(0.226)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_873) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.56)/sqrt(0.967)/ln((0.697+0.697)/(0.697+0.697))^tan(0.157)-sqrt(0.135)^log((0.915/0.915)+(0.915^0.915))^cos(0.548)-acos(0.711)-ln((0.136+0.136)-(x+0.136))+log(0.614)^sin(0.138)*asin((0.667*0.667)/(0.206^0.667))+log(0.381)/0.650"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_874) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.415)*0.460"};
  char *py_result = {"0.2963342"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_875) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.123)*asin(0.498)/acos((0.443^0.443)-(x^0.443))^cos(0.955)+sin(0.740)/cos((0.402/0.402)*(x*0.402))*acos(0.133)*acos(0.255)/tan((0.691-0.691)+(0.594*0.691))+acos(0.553)/sin(0.563)+ln((0.195*0.195)^(0.195/0.195))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_876) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.520)-acos(0.411)-acos((0.550-0.550)+(0.550/0.550))^sin(0.862)/cos(0.699)+acos((0.523*0.523)/(0.523+0.523))*acos(0.396)-cos(0.937)-tan((0.465^0.465)/(x^0.465))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_877) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.792)*cos(0.340)-sin((0.159/0.159)*(x^0.159))-log(0.309)/ln(0.588)*log((0.692+0.692)+(x/0.692))+atan(0.916)+ln(0.329)*log((0.441^0.441)/(0.473-0.441))-acos(0.671)-log(0.676)+acos((0.565*0.565)-(0.565-0.565))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_878) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.593)+atan(0.686)+sin((0.711+0.711)*(x/0.711))*cos(0.82)/ln(0.370)+acos((0.544/0.544)-(x^0.544))*asin(0.883)*sqrt(0.241)^ln((0.50-0.50)+(0.504-0.50))*acos(0.907)/atan(0.805)-sqrt((0.379+0.379)+(x/0.379))*acos(0.490)+cos(0.686)"};
  char *py_result = {"1.9558279"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_879) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.899)^acos(0.546)/asin((0.950^0.950)+(0.950*0.950))-ln(0.620)^acos(0.265)^acos((0.234/0.234)-(x/0.234))+asin(0.300)+atan(0.735)*cos((0.310*0.310)-(0.16+0.310))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_880) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.481)*log(0.768)/cos((0.237-0.237)*(x*0.237))^acos(0.410)"};
  char *py_result = {"-0.0575251"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_881) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.734)+tan(0.596)*acos((0.697/0.697)+(0.311+0.697))+acos(0.328)^asin(0.222)+cos((0.837^0.837)+(0.837+0.837))-log(0.106)+atan(0.235)/log((0.790-0.790)*(0.210+0.790))+cos(0.957)^atan(0.646)+sin((0.352/0.352)-(0.854^0.352))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_882) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.565)/acos(0.563)+tan((0.449^0.449)/(x+0.449))*sin(0.329)^cos(0.29)+log((0.291/0.291)*(0.291^0.291))*log(0.567)/atan(0.836)"};
  char *py_result = {"1.6076715"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_883) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.319)-cos(0.326)/log((0.86+0.86)*(0.86^0.86))/asin(0.198)/sin(0.848)+atan((0.66-0.66)*(x-0.66))*sqrt(0.963)+asin(0.159)+sin((0.223*0.223)*(x+0.223))^sqrt(0.5)/log(0.661)+asin((0.508^0.508)*(x-0.508))-tan(0.66)^tan(0.119)"};
  char *py_result = {"-36.434445"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_884) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.424)*sqrt(0.426)^sin((0.493/0.493)^(0.347+0.493))/cos(0.886)"};
  char *py_result = {"0.4427699"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_885) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.488)^acos(0.852)^acos((0.381^0.381)*(0.176/0.381))/ln(0.750)*0.222"};
  char *py_result = {"0.2934396"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_886) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.203)*ln(0.807)-asin((0.221+0.221)/(0.221*0.221))^sqrt(0.583)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_887) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.614)+sqrt(0.14)*atan((0.374/0.374)-(0.774-0.374))+log(0.583)-sqrt(0.775)/cos((0.219^0.219)+(0.531*0.219))^cos(0.154)+tan(0.678)+sqrt((0.480+0.480)-(0.480+0.480))^sqrt(0.548)+acos(0.669)^log((0.893+0.893)+(0.237*0.893))+asin(0.893)/sqrt(0.544)/atan((0.122-0.122)*(x*0.122))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_888) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.287)-cos(0.807)*acos((0.325+0.325)*(0.325+0.325))+sin(0.716)*ln(0.905)/sqrt((0.690^0.690)/(0.690-0.690))+acos(0.739)*sqrt(0.549)+cos((0.683-0.683)^(0.224+0.683))+sqrt(0.639)"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_889) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.504)-sin(0.845)^sqrt((0.30-0.30)+(0.30/0.30))-tan(0.913)-acos(0.388)-log((0.351*0.351)-(x^0.351))+sqrt(0.277)-atan(0.126)-asin((0.91-0.91)^(0.21^0.91))^tan(0.935)/sin(0.251)/acos((0.853*0.853)-(x+0.853))/log(0.238)^cos(0.264)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_890) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.604)-log(0.217)/log((0.110-0.110)*(0.110^0.110))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_891) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.318)-log(0.620)*sin((0.936^0.936)-(0.497^0.936))/ln(0.376)*cos(0.454)*atan((0.564/0.564)+(0.564/0.564))/acos(0.129)-acos(0.268)+acos((0.192^0.192)/(x^0.192))-sin(0.505)+0.167"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_892) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.954)+log(0.189)^atan((0.913-0.913)/(0.637*0.913))*sqrt(0.914)-log(0.786)^log((0.246/0.246)^(x+0.246))*sin(0.652)+asin(0.632)*asin((0.209^0.209)/(x^0.209))-acos(0.270)^asin(0.905)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_893) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.505)^cos(0.374)^log((0.317*0.317)+(0.800^0.317))/cos(0.20)^log(0.490)/log((0.111-0.111)*(0.913*0.111))^cos(0.399)+sqrt(0.674)-atan((0.402*0.402)-(x/0.402))+sin(0.283)-atan(0.281)+ln((0.314+0.314)^(0.314*0.314))*tan(0.527)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_894) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.372)*cos(0.154)/tan((0.10^0.10)/(0.63*0.10))-sin(0.696)^tan(0.290)"};
  char *py_result = {"27.087785"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_895) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.585)*acos(0.529)*log((0.671^0.671)+(0.671-0.671))+log(0.243)*ln(0.421)/acos((0.664+0.664)+(0.664^0.664))-asin(0.961)^ln(0.317)+cos((0.73+0.73)^(0.776-0.73))*sin(0.800)+0.288"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_896) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.484)^sin(0.185)-sqrt((0.623^0.623)^(0.623/0.623))^acos(0.294)"};
  char *py_result = {"0.1488239"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_897) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.476)/log(0.24)-log((0.967+0.967)-(x/0.967))/asin(0.269)*cos(0.1)-acos((0.796+0.796)/(0.796^0.796))*sin(0.289)/log(0.125)^atan((0.644^0.644)^(0.529*0.644))*atan(0.262)*log(0.811)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_898) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.875)/acos(0.638)^atan((0.861/0.861)/(x*0.861))/log(0.221)+ln(0.714)^sqrt((0.789/0.789)/(0.280+0.789))+sin(0.198)*sin(0.346)"};
  char *py_result = {"-1.3406338"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_899) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.992)+asin(0.287)-tan((0.843+0.843)*(0.346+0.843))^sin(0.27)^acos(0.175)-sin((0.219/0.219)*(0.219-0.219))-sin(0.568)/0.784"};
  char *py_result = {"(-0.6986380815234586-0.5387993755924438j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_900) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.752)*asin(0.158)^log((0.251/0.251)*(0.251/0.251))^acos(0.108)*ln(0.620)*ln((0.681-0.681)/(x/0.681))/sin(0.182)*ln(0.822)-tan((0.721*0.721)*(x-0.721))*ln(0.683)"};
  char *py_result = {"0.1585759"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_901) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.528)/sin(0.513)*acos((0.647*0.647)/(x-0.647))+sqrt(0.292)+atan(0.626)*asin((0.475+0.475)*(0.988+0.475))+atan(0.499)-acos(0.617)/sqrt((0.614*0.614)*(x/0.614))^log(0.21)-log(0.512)*asin((0.340/0.340)-(x*0.340))-sin(0.572)^0.479"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_902) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.171)-sqrt(0.558)^log((0.519*0.519)/(x/0.519))/log(0.598)-sin(0.465)^acos((0.751/0.751)*(0.751^0.751))*cos(0.585)"};
  char *py_result = {"4.1949802"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_903) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.433)-log(0.551)/cos((0.75^0.75)*(x^0.75))/atan(0.155)^0.133"};
  char *py_result = {"1.4615244"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_904) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.882)*sqrt(0.459)+tan((0.235*0.235)+(0.435^0.235))^log(0.915)^acos(0.691)*acos((0.426+0.426)-(x+0.426))+log(0.990)-log(0.218)^acos((0.711+0.711)*(0.757*0.711))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_905) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.254)/asin(0.614)/tan((0.487-0.487)-(0.487*0.487))-log(0.236)+log(0.121)*acos((0.634^0.634)+(0.634-0.634))/tan(0.301)*log(0.258)-atan((0.215-0.215)+(0.215/0.215))-asin(0.974)-sin(0.533)*atan((0.836^0.836)+(0.836*0.836))*acos(0.359)+asin(0.601)-asin((0.347+0.347)^(0.373+0.347))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_906) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.937)*asin(0.288)/tan((0.373/0.373)/(0.373-0.373))/log(0.144)/ln(0.770)+ln((0.250/0.250)+(0.250/0.250))-log(0.674)-cos(0.617)/atan((0.671/0.671)/(0.462-0.671))-sqrt(0.20)/ln(0.604)^asin((0.784+0.784)-(0.274+0.784))*asin(0.135)*0.524"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_907) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.153)+atan(0.444)-ln((0.213+0.213)/(x*0.213))/asin(0.22)/log(0.746)*cos((0.46+0.46)+(x/0.46))*ln(0.364)^sqrt(0.446)/sqrt((0.151*0.151)-(0.151/0.151))+ln(0.220)-acos(0.226)+sin((0.251*0.251)^(0.415-0.251))*atan(0.451)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_908) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.42)+ln(0.219)+cos((0.320-0.320)*(0.320-0.320))^atan(0.591)"};
  char *py_result = {"2.3353818"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_909) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.370)^sqrt(0.237)*ln((0.560^0.560)/(0.560*0.560))^asin(0.857)*atan(0.156)+acos((0.781^0.781)^(x/0.781))^sqrt(0.747)"};
  char *py_result = {"0.5277062"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_910) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.595)-asin(0.642)-atan((0.482^0.482)+(0.482^0.482))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_911) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.372)*ln(0.725)/log((0.458/0.458)*(0.458*0.458))/asin(0.894)+log(0.437)/cos((0.58*0.58)*(x*0.58))*sin(0.291)*acos(0.959)^atan((0.981-0.981)/(0.122/0.981))*acos(0.323)+sqrt(0.223)+atan((0.611/0.611)^(0.33-0.611))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_912) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.826)/atan(0.128)-atan((0.668^0.668)+(x+0.668))+asin(0.880)-cos(0.363)+cos((0.462-0.462)^(0.462/0.462))^atan(0.617)-log(0.106)-sin((0.386+0.386)-(x^0.386))^ln(0.859)+asin(0.219)*tan((0.814+0.814)*(0.764*0.814))^sin(0.529)"};
  char *py_result = {"9.4495685"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_913) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.688)/atan(0.544)+atan((0.648/0.648)+(0.648-0.648))^tan(0.89)+ln(0.64)*sqrt((0.41/0.41)+(0.41*0.41))+acos(0.875)^log(0.539)*ln((0.377+0.377)*(x^0.377))/log(0.546)+ln(0.519)^tan((0.160^0.160)/(0.160+0.160))*cos(0.816)-cos(0.948)-asin((0.33-0.33)^(0.33-0.33))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_914) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.745)+ln(0.687)-asin((0.230*0.230)/(0.804/0.230))*atan(0.913)/sqrt(0.775)+tan((0.550+0.550)/(0.550/0.550))-log(0.2)^sin(0.559)/tan((0.242+0.242)+(0.242-0.242))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_915) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.860)^acos(0.518)*atan((0.420+0.420)*(x^0.420))+acos(0.970)+ln(0.893)/sin((0.923-0.923)/(0.455-0.923))/tan(0.558)*sqrt(0.596)^cos((0.76^0.76)-(x/0.76))^cos(0.755)"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_916) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.574)*tan(0.151)+sqrt((0.113/0.113)*(x+0.113))/tan(0.185)*asin(0.96)+cos((0.550-0.550)*(0.550*0.550))/atan(0.596)*cos(0.305)-sin((0.751/0.751)*(0.336*0.751))-sqrt(0.101)^tan(0.786)"};
  char *py_result = {"4.8422837"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_917) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.555)+cos(0.257)/sin((0.357/0.357)*(0.267*0.357))-sqrt(0.884)+cos(0.859)-log((0.416^0.416)-(x-0.416))-atan(0.63)-atan(0.891)/sin((0.429+0.429)/(x^0.429))^tan(0.303)+sin(0.983)^cos((0.519+0.519)/(0.596*0.519))/log(0.219)"};
  char *py_result = {"7.2159645"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_918) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.831)*sin(0.307)+sqrt((0.47-0.47)-(0.484+0.47))+acos(0.448)-cos(0.465)-sin((0.957*0.957)-(0.612^0.957))*cos(0.423)-sin(0.311)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_919) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.430)*acos(0.591)/atan((0.183^0.183)+(x+0.183))-log(0.612)+atan(0.971)-log((0.800+0.800)-(0.800+0.800))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_920) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.465)/atan(0.373)*asin((0.765+0.765)^(0.765^0.765))+ln(0.169)-0.931"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_921) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.463)^log(0.976)^log((0.755+0.755)-(0.331^0.755))-ln(0.383)+log(0.571)/atan((0.868^0.868)/(0.868/0.868))-sqrt(0.740)+sqrt(0.843)*cos((0.513+0.513)*(x/0.513))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_922) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.380)-asin(0.70)^log((0.112*0.112)+(0.807+0.112))*sqrt(0.203)/ln(0.65)+sqrt((0.271^0.271)+(0.271-0.271))-sqrt(0.270)+acos(0.921)-atan((0.585^0.585)^(x+0.585))^log(0.315)*0.25"};
  char *py_result = {"-0.1229236"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_923) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.985)+ln(0.24)/log((0.687^0.687)+(0.508^0.687))^acos(0.751)^sqrt(0.17)-atan((0.445*0.445)*(0.691+0.445))*ln(0.906)-cos(0.964)/acos((0.727*0.727)/(x*0.727))+sqrt(0.365)/atan(0.804)/cos((0.666^0.666)^(0.220^0.666))^asin(0.874)+log(0.885)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_924) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.476)/sqrt(0.18)-asin((0.10+0.10)+(0.10-0.10))+atan(0.381)/cos(0.720)-sqrt((0.492-0.492)-(0.333-0.492))*log(0.474)+tan(0.865)+acos((0.547/0.547)-(x/0.547))+tan(0.207)-sin(0.99)"};
  char *py_result = {"3.3501091"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_925) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.449)-cos(0.667)-log((0.954-0.954)-(0.954+0.954))-sin(0.288)*asin(0.862)-log((0.811-0.811)*(x*0.811))^cos(0.467)-sin(0.502)/sin((0.287+0.287)-(0.287^0.287))+cos(0.67)-acos(0.945)+log((0.178/0.178)^(x*0.178))^sin(0.391)-ln(0.447)/atan((0.145+0.145)^(x+0.145))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_926) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.537)-atan(0.13)-tan((0.191^0.191)*(0.347-0.191))+asin(0.493)+asin(0.698)-sin((0.998+0.998)+(0.998-0.998))-atan(0.183)-acos(0.652)*acos((0.359/0.359)+(0.1-0.359))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_927) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.276)"};
  char *py_result = {"-0.5590909"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_928) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"713%900"};
  char *py_result = {"713"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_929) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.50)/sqrt(0.226)/log((0.504-0.504)^(0.643+0.504))/sqrt(0.551)/ln(0.629)^atan((0.773-0.773)-(x*0.773))-cos(0.116)/ln(0.942)^sin((0.829^0.829)/(0.829*0.829))-sin(0.267)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_930) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"973%525"};
  char *py_result = {"448"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_931) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.945)/sqrt(0.858)+atan((0.450*0.450)^(0.450/0.450))^tan(0.604)*log(0.31)*atan((0.822^0.822)^(0.666/0.822))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_932) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.605)+asin(0.195)*sqrt((0.314*0.314)+(0.837-0.314))/atan(0.835)/log(0.164)-sqrt((0.80/0.80)*(0.114^0.80))+ln(0.631)^ln(0.784)+sin((0.395^0.395)/(0.395+0.395))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_933) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.723)/ln(0.393)-sin((0.596+0.596)/(x/0.596))+sqrt(0.601)*sin(0.740)-acos((0.70*0.70)/(x+0.70))+cos(0.131)*acos(0.850)/cos((0.663-0.663)/(0.663-0.663))^sin(0.21)^tan(0.591)+atan((0.673-0.673)/(x-0.673))*ln(0.688)*atan(0.715)"};
  char *py_result = {"float division by zero"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_934) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.416)+cos(0.225)*sqrt((0.851*0.851)^(0.851^0.851))+asin(0.395)"};
  char *py_result = {"1.8979483"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_935) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.539)+sin(0.73)*sin((0.516*0.516)-(0.516*0.516))*acos(0.147)^ln(0.385)-cos((0.201^0.201)*(x-0.201))+acos(0.891)^sin(0.595)*atan((0.184+0.184)-(0.184-0.184))*asin(0.61)-log(0.869)-log((0.734*0.734)-(0.306/0.734))-tan(0.224)*sqrt(0.599)/asin((0.361*0.361)/(x-0.361))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_936) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.19)^ln(0.491)/log((0.797/0.797)+(0.325^0.797))+tan(0.468)-log(0.83)*ln((0.766*0.766)^(0.767^0.766))+cos(0.190)/sin(0.172)-atan((0.333/0.333)+(0.333+0.333))+sin(0.638)-sqrt(0.390)-log((0.499*0.499)*(0.525-0.499))-tan(0.18)-0.762"};
  char *py_result = {"14.116993"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_937) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.30)^cos(0.433)^cos((0.708/0.708)+(x/0.708))-cos(0.649)^acos(0.180)^cos((0.625*0.625)*(x-0.625))+sin(0.625)^tan(0.317)"};
  char *py_result = {"0.3826021"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_938) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.715)"};
  char *py_result = {"0.7966241"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_939) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.861)/cos(0.142)+tan((0.871*0.871)+(0.884*0.871))*log(0.137)+ln(0.702)+tan((0.582-0.582)-(0.950*0.582))-tan(0.224)+cos(0.170)/ln((0.561/0.561)+(x*0.561))-atan(0.654)-acos(0.356)*ln((0.865/0.865)-(0.865^0.865))-cos(0.206)+0.236"};
  char *py_result = {"-20.111357"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_940) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"129%735"};
  char *py_result = {"129"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_941) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.52)*sin(0.382)-sin((0.222*0.222)*(x-0.222))*tan(0.345)-asin(0.253)^atan((0.769^0.769)^(x*0.769))/cos(0.421)*cos(0.479)*log((0.900^0.900)^(x+0.900))+acos(0.71)^sin(0.968)+ln((0.913*0.913)-(x^0.913))-atan(0.111)/ln(0.11)^asin((0.234^0.234)-(x+0.234))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_942) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.717)^0.354"};
  char *py_result = {"0.9238375"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_943) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.81)/atan(0.729)-atan((0.506*0.506)*(0.683+0.506))/asin(0.37)-tan(0.589)"};
  char *py_result = {"-0.2980088"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_944) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.456)"};
  char *py_result = {"0.8978211"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_945) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.589)+tan(0.617)-ln((0.975+0.975)*(0.975/0.975))^log(0.599)*log(0.755)+ln((0.473/0.473)/(x+0.473))-tan(0.409)^cos(0.658)^atan((0.657/0.657)^(0.657^0.657))^sin(0.905)/sin(0.3)+log((0.360/0.360)-(0.990-0.360))^acos(0.546)"};
  char *py_result = {"(0.183469704738569+0.009257279032717483j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_946) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.142)-tan(0.202)+asin((0.528+0.528)-(x^0.528))+asin(0.798)*cos(0.632)+sqrt((0.77^0.77)^(x/0.77))+tan(0.395)-asin(0.86)+cos((0.589*0.589)*(0.589*0.589))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_947) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.235)+log(0.796)/acos((0.61*0.61)-(0.61+0.61))*cos(0.314)+log(0.689)/asin((0.828/0.828)+(0.792/0.828))/ln(0.743)/0.633"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_948) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.825)-acos(0.887)-log((0.936+0.936)-(0.936^0.936))+tan(0.222)/asin(0.180)/sin((0.302*0.302)/(0.302/0.302))+tan(0.982)^ln(0.45)^cos((0.15+0.15)*(x/0.15))*acos(0.104)/0.541"};
  char *py_result = {"17.016406"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_949) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.435)-log(0.391)-acos((0.929+0.929)*(0.929*0.929))+atan(0.90)+ln(0.402)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_950) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"601%268"};
  char *py_result = {"65"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_951) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.430)/sqrt(0.50)+tan((0.155+0.155)-(x-0.155))+cos(0.58)+sqrt(0.512)+sqrt((0.988/0.988)-(x+0.988))^ln(0.577)^acos(0.165)/tan((0.776+0.776)+(x/0.776))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_952) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.440)*cos(0.878)*ln((0.493^0.493)*(x-0.493))*acos(0.191)/sin(0.464)*log((0.690*0.690)^(0.690/0.690))-cos(0.247)/cos(0.722)*acos((0.927^0.927)^(0.927*0.927))/sin(0.798)/log(0.699)*acos((0.314^0.314)^(0.395/0.314))*"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_953) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.182)^sin(0.438)-sin((0.786/0.786)+(0.786+0.786))^cos(0.786)*tan(0.85)/acos((0.450^0.450)^(x*0.450))+tan(0.747)^0.839"};
  char *py_result = {"(-2.1847985630170874+0.855192974741743j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_954) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.262)-asin(0.112)*asin((0.541+0.541)+(x^0.541))-asin(0.164)/asin(0.271)/log((0.607+0.607)/(0.684^0.607))-tan(0.510)+cos(0.203)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_955) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.371)/ln(0.549)-asin((0.365*0.365)/(0.365^0.365))*asin(0.143)-atan(0.526)-sqrt((0.301^0.301)-(0.335*0.301))^tan(0.667)*sin(0.542)^atan((0.421/0.421)+(0.421^0.421))^asin(0.568)+acos(0.201)^sqrt((0.989*0.989)-(0.780^0.989))+atan(0.495)"};
  char *py_result = {"2.0739747"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_956) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.520)-tan(0.51)/asin((0.867^0.867)*(x+0.867))+log(0.547)"};
  char *py_result = {"0.2629954"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_957) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"518%853"};
  char *py_result = {"518"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_958) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.165)^log(0.296)*atan((0.27^0.27)+(x-0.27))-tan(0.282)/0.122"};
  char *py_result = {"-1.9329145"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_959) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.628)/cos(0.495)+asin((0.887^0.887)+(0.898^0.887))^sin(0.646)*0.750"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_960) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.340)*tan(0.977)^ln((0.178/0.178)-(x^0.178))+tan(0.27)+sin(0.828)*cos((0.825^0.825)^(0.212/0.825))-tan(0.931)/log(0.72)-tan((0.866+0.866)^(x/0.866))^sqrt(0.388)*log(0.488)^tan((0.543-0.543)^(0.543+0.543))+tan(0.707)-asin(0.571)"};
  char *py_result = {"9.1994815"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_961) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.71)*tan(0.68)-asin((0.220^0.220)+(0.538-0.220))^ln(0.144)^ln(0.675)*cos((0.80^0.80)/(0.933/0.80))*tan(0.633)^tan(0.266)*log((0.628+0.628)+(x^0.628))-sin(0.809)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_962) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.777)^ln(0.659)*atan((0.400^0.400)*(0.400-0.400))^tan(0.549)+tan(0.889)-atan((0.53+0.53)-(0.53-0.53))+atan(0.360)/sin(0.378)^sqrt((0.502-0.502)^(0.502-0.502))-sqrt(0.364)^acos(0.216)^log((0.705^0.705)/(0.537*0.705))-ln(0.458)*sin(0.323)"};
  char *py_result = {"0.6605506"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_963) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.904)^atan(0.523)-log((0.157/0.157)^(0.770+0.157))^log(0.694)+atan(0.591)^sin((0.539+0.539)*(0.436*0.539))-asin(0.452)-tan(0.515)^log((0.947^0.947)/(x+0.947))^asin(0.167)-sin(0.451)/ln((0.261-0.261)/(0.537^0.261))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_964) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.948)-sin(0.853)/asin((0.570-0.570)+(0.257*0.570))/log(0.694)+atan(0.834)+sqrt((0.218/0.218)^(0.406/0.218))-sin(0.772)*cos(0.943)"};
  char *py_result = {"34.555552"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_965) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.571)^log(0.671)*sin((0.963-0.963)/(0.963^0.963))+ln(0.352)*atan(0.378)-sqrt((0.741^0.741)*(0.741-0.741))-sqrt(0.128)"};
  char *py_result = {"-0.2487786"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_966) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.466)-acos(0.48)^sqrt((0.311/0.311)+(0.229*0.311))*acos(0.451)/sqrt(0.760)-sqrt((0.547-0.547)+(x*0.547))-ln(0.727)^atan(0.542)+ln((0.108*0.108)/(0.108-0.108))-acos(0.471)^log(0.359)*sin((0.304^0.304)^(0.304-0.304))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_967) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.533)+sqrt(0.974)*sin((0.426^0.426)/(0.426/0.426))*log(0.793)/0.689"};
  char *py_result = {"0.3348064"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_968) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.138)+asin(0.670)/acos((0.62^0.62)-(0.220-0.62))+sin(0.370)+acos(0.182)*acos((0.491-0.491)-(0.491/0.491))-asin(0.665)^sqrt(0.681)-asin((0.695/0.695)-(0.574^0.695))*log(0.254)-acos(0.347)*cos((0.802+0.802)-(0.802-0.802))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_969) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.501)-sqrt(0.742)+asin((0.126/0.126)+(x^0.126))-sqrt(0.722)^cos(0.759)*ln((0.678+0.678)-(0.620+0.678))*atan(0.846)/tan(0.772)+sin((0.505+0.505)*(x/0.505))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_970) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.570)/asin(0.994)+sqrt((0.723*0.723)/(0.965*0.723))-asin(0.278)*tan(0.259)*sin((0.414^0.414)^(0.592/0.414))*cos(0.554)+asin(0.208)/ln((0.692^0.692)/(x*0.692))+atan(0.128)*acos(0.423)"};
  char *py_result = {"1.6493107"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_971) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.858)^sin(0.977)/log((0.182/0.182)+(0.182/0.182))/sin(0.72)^log(0.510)^acos((0.611*0.611)^(0.611/0.611))/log(0.889)^sin(0.204)*log((0.993*0.993)-(x-0.993))^tan(0.501)-0.356"};
  char *py_result = {"(1.7701872511796712-1.7559244775133247j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_972) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.502)-log(0.0)*tan((0.929^0.929)*(0.56-0.929))^ln(0.725)-sqrt(0.23)*asin((0.731/0.731)*(0.731^0.731))+atan(0.545)*cos(0.877)/ln((0.719*0.719)*(0.719^0.719))/tan(0.678)-sqrt(0.995)*sin((0.191+0.191)/(0.191+0.191))+acos(0.123)*sqrt(0.690)-tan((0.673-0.673)/(0.654+0.673))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_973) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.751)*cos(0.460)/atan((0.67+0.67)+(x+0.67))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_974) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.938)*atan(0.395)-log((0.895^0.895)-(0.895^0.895))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_975) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.131)+log(0.544)+ln((0.841/0.841)-(0.50*0.841))/acos(0.821)*log(0.13)^log((0.290+0.290)/(x^0.290))-sin(0.432)"};
  char *py_result = {"(1.0605670408627623+0.0012471572450095832j)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_976) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.907)+sqrt(0.716)-cos((0.801*0.801)^(0.801^0.801))^acos(0.623)^atan(0.829)-acos((0.137/0.137)-(0.286*0.137))^log(0.355)*atan(0.258)*tan((0.542+0.542)/(0.542+0.542))/atan(0.971)"};
  char *py_result = {"-0.1063754"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_977) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.78)^atan(0.451)-log((0.901+0.901)^(0.901^0.901))^ln(0.956)^atan(0.54)*acos((0.621^0.621)-(0.621^0.621))/cos(0.383)-cos(0.231)-sqrt((0.799+0.799)+(x-0.799))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_978) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.797)^atan(0.196)*cos((0.922-0.922)^(0.922*0.922))*tan(0.270)*sqrt(0.774)-log((0.332-0.332)-(0.332-0.332))-atan(0.371)^sin(0.771)^atan((0.700-0.700)*(0.175*0.700))^acos(0.3)/asin(0.424)-acos((0.794-0.794)+(0.794/0.794))*tan(0.490)^atan(0.481)*sqrt((0.495+0.495)+(0.495*0.495))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_979) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.66)^ln(0.687)/sqrt((0.547^0.547)-(x*0.547))^sqrt(0.861)*sin(0.796)+asin((0.832*0.832)/(0.843/0.832))/asin(0.389)/ln(0.295)/tan((0.3-0.3)/(0.3*0.3))-"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_980) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.651)+sqrt(0.636)-cos((0.711^0.711)/(0.711/0.711))^log(0.939)+sin(0.780)+sin((0.214/0.214)-(0.214+0.214))-tan(0.345)-cos(0.264)+asin((0.440+0.440)^(0.232*0.440))/cos(0.277)/sqrt(0.95)-asin((0.737/0.737)+(0.440+0.737))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_981) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.959)"};
  char *py_result = {"0.2873439"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_982) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.943)+ln(0.957)^acos((0.534^0.534)/(0.213^0.534))*sin(0.838)*asin(0.384)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_983) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.390)+acos(0.311)+ln((0.108+0.108)-(0.108^0.108))/log(0.816)*log(0.901)+sin((0.196^0.196)-(0.451*0.196))^atan(0.76)^0.105"};
  char *py_result = {"2.3559107"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_984) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.358)/0.54"};
  char *py_result = {"0.6928170"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_985) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"asin(0.981)/tan(0.783)+tan((0.559+0.559)^(0.559/0.559))^ln(0.87)+cos(0.312)"};
  char *py_result = {"3.9037496"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_986) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.508)+asin(0.309)/acos((0.915*0.915)+(x-0.915))^atan(0.647)*sqrt(0.692)-sqrt((0.491+0.491)*(0.491/0.491))*acos(0.124)/tan(0.976)^acos((0.527/0.527)*(0.527-0.527))^acos(0.332)"};
  char *py_result = {"-0.0311413"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_987) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.222)/tan(0.864)+ln((0.926/0.926)*(0.926*0.926))*tan(0.109)/tan(0.641)-sin((0.669-0.669)*(0.979+0.669))*sqrt(0.235)*asin(0.134)/cos((0.761+0.761)/(x/0.761))/tan(0.334)"};
  char *py_result = {"0.2773801"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_988) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.753)"};
  char *py_result = {"0.6838307"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_989) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"tan(0.723)/log(0.644)*atan((0.907/0.907)+(x-0.907))/asin(0.596)"};
  char *py_result = {"-1.7387419"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_990) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"atan(0.149)*cos(0.44)-asin((0.407^0.407)/(0.414^0.407))-ln(0.414)*log(0.113)*acos((0.620-0.620)/(0.620/0.620))^"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_991) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.725)/acos(0.484)^acos((0.268^0.268)+(x*0.268))+ln(0.422)/asin(0.533)+sqrt((0.644+0.644)^(0.644+0.644))/acos(0.848)/sin(0.131)-log((0.224^0.224)^(x+0.224))+cos(0.935)/0.127"};
  char *py_result = {"22.202181"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_992) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.487)*cos(0.686)^tan((0.90*0.90)*(0.90/0.90))-cos(0.983)+atan(0.538)+sqrt((0.873/0.873)^(0.873^0.873))+"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_993) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sin(0.474)^cos(0.776)+log((0.945+0.945)*(0.606/0.945))/sin(0.255)-sqrt(0.167)-tan((0.45^0.45)/(0.45*0.45))*cos(0.202)/ln(0.235)"};
  char *py_result = {"-0.9727866"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_994) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"sqrt(0.323)-sin(0.758)/ln((0.680*0.680)^(x/0.680))^asin(0.305)"};
  char *py_result = {"-0.2327340"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_995) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.868)^sin(0.332)*cos((0.979^0.979)^(0.195^0.979))-sin(0.916)/asin(0.151)/acos((0.50*0.50)-(x/0.50))-asin(0.530)/tan(0.155)^acos((0.984^0.984)-(0.74+0.984))+sqrt(0.211)-log(0.29)*asin((0.154/0.154)+(0.154+0.154))-ln(0.447)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_996) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"acos(0.475)-log(0.959)+atan((0.496^0.496)/(0.361/0.496))/atan(0.80)+tan(0.929)^tan((0.105*0.105)^(x/0.105))*atan(0.957)-acos(0.26)+tan((0.440^0.440)+(0.300*0.440))+asin(0.967)/sqrt(0.727)+sqrt((0.189*0.189)+(0.308-0.189))+asin(0.892)^0.676"};
  char *py_result = {"5.7837124"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_997) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"ln(0.150)*asin(0.869)*cos((0.848+0.848)^(x+0.848))/sqrt(0.402)/acos(0.243)+sqrt((0.689^0.689)-(0.689*0.689))-sin(0.283)^ln(0.414)/atan((0.801-0.801)+(0.966*0.801))*atan(0.909)-cos(0.84)^cos((0.516/0.516)*(x*0.516))*asin(0.767)+0.187"};
  char *py_result = {"-0.5925000"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_998) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.658)-asin(0.841)+acos((0.298^0.298)+(0.238^0.298))^tan(0.600)-acos(0.520)*log((0.735+0.735)/(0.963-0.735))/sin(0.326)^sin(0.621)*cos((0.378*0.378)-(0.378-0.378))^acos(0.489)*acos(0.760)+ln((0.169+0.169)^(0.169*0.169))*acos(0.967)"};
  char *py_result = {"math domain error"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_999) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"log(0.366)-ln(0.680)-atan((0.714/0.714)*(0.816/0.714))^sqrt(0.994)*asin(0.226)*cos((0.996/0.996)+(x+0.996))+tan(0.681)/cos(0.904)"};
  char *py_result = {"0.4609466"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

START_TEST(calc_1000) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {"cos(0.332)-sqrt(0.347)*asin((0.442^0.442)+(0.442^0.442))*log(0.181)^log(0.3)+cos((0.232/0.232)/(0.232+0.232))/"};
  char *py_result = {"invalid syntax (<string>, line 1)"};
  char *x_var = {"0.1522"};
  double result = 0.0;
  char exit_msg[100] = {'\0'}; 
  exit_code = calc(expression, x_var, &result);
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, "%s", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[100] = {'\0'};
      sprintf(my_result, "%.7f", result);
      ck_assert_double_eq_tol(result, atof(py_result), 1e-7);
  }

  free_stack(&stack);
}
END_TEST

Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_calc;

    s = suite_create("calc");

    tc_calc = tcase_create("calc");
    tcase_add_test(tc_calc, calc_1);
    tcase_add_test(tc_calc, calc_2);
    tcase_add_test(tc_calc, calc_3);
    tcase_add_test(tc_calc, calc_4);
    tcase_add_test(tc_calc, calc_5);
    tcase_add_test(tc_calc, calc_6);
    tcase_add_test(tc_calc, calc_7);
    tcase_add_test(tc_calc, calc_8);
    tcase_add_test(tc_calc, calc_9);
    tcase_add_test(tc_calc, calc_10);
    tcase_add_test(tc_calc, calc_11);
    tcase_add_test(tc_calc, calc_12);
    tcase_add_test(tc_calc, calc_13);
    tcase_add_test(tc_calc, calc_14);
    tcase_add_test(tc_calc, calc_15);
    tcase_add_test(tc_calc, calc_16);
    tcase_add_test(tc_calc, calc_17);
    tcase_add_test(tc_calc, calc_18);
    tcase_add_test(tc_calc, calc_19);
    tcase_add_test(tc_calc, calc_20);
    tcase_add_test(tc_calc, calc_21);
    tcase_add_test(tc_calc, calc_22);
    tcase_add_test(tc_calc, calc_23);
    tcase_add_test(tc_calc, calc_24);
    tcase_add_test(tc_calc, calc_25);
    tcase_add_test(tc_calc, calc_26);
    tcase_add_test(tc_calc, calc_27);
    tcase_add_test(tc_calc, calc_28);
    tcase_add_test(tc_calc, calc_29);
    tcase_add_test(tc_calc, calc_30);
    tcase_add_test(tc_calc, calc_31);
    tcase_add_test(tc_calc, calc_32);
    tcase_add_test(tc_calc, calc_33);
    tcase_add_test(tc_calc, calc_34);
    tcase_add_test(tc_calc, calc_35);
    tcase_add_test(tc_calc, calc_36);
    tcase_add_test(tc_calc, calc_37);
    tcase_add_test(tc_calc, calc_38);
    tcase_add_test(tc_calc, calc_39);
    tcase_add_test(tc_calc, calc_40);
    tcase_add_test(tc_calc, calc_41);
    tcase_add_test(tc_calc, calc_42);
    tcase_add_test(tc_calc, calc_43);
    tcase_add_test(tc_calc, calc_44);
    tcase_add_test(tc_calc, calc_45);
    tcase_add_test(tc_calc, calc_46);
    tcase_add_test(tc_calc, calc_47);
    tcase_add_test(tc_calc, calc_48);
    tcase_add_test(tc_calc, calc_49);
    tcase_add_test(tc_calc, calc_50);
    tcase_add_test(tc_calc, calc_51);
    tcase_add_test(tc_calc, calc_52);
    tcase_add_test(tc_calc, calc_53);
    tcase_add_test(tc_calc, calc_54);
    tcase_add_test(tc_calc, calc_55);
    tcase_add_test(tc_calc, calc_56);
    tcase_add_test(tc_calc, calc_57);
    tcase_add_test(tc_calc, calc_58);
    tcase_add_test(tc_calc, calc_59);
    tcase_add_test(tc_calc, calc_60);
    tcase_add_test(tc_calc, calc_61);
    tcase_add_test(tc_calc, calc_62);
    tcase_add_test(tc_calc, calc_63);
    tcase_add_test(tc_calc, calc_64);
    tcase_add_test(tc_calc, calc_65);
    tcase_add_test(tc_calc, calc_66);
    tcase_add_test(tc_calc, calc_67);
    tcase_add_test(tc_calc, calc_68);
    tcase_add_test(tc_calc, calc_69);
    tcase_add_test(tc_calc, calc_70);
    tcase_add_test(tc_calc, calc_71);
    tcase_add_test(tc_calc, calc_72);
    tcase_add_test(tc_calc, calc_73);
    tcase_add_test(tc_calc, calc_74);
    tcase_add_test(tc_calc, calc_75);
    tcase_add_test(tc_calc, calc_76);
    tcase_add_test(tc_calc, calc_77);
    tcase_add_test(tc_calc, calc_78);
    tcase_add_test(tc_calc, calc_79);
    tcase_add_test(tc_calc, calc_80);
    tcase_add_test(tc_calc, calc_81);
    tcase_add_test(tc_calc, calc_82);
    tcase_add_test(tc_calc, calc_83);
    tcase_add_test(tc_calc, calc_84);
    tcase_add_test(tc_calc, calc_85);
    tcase_add_test(tc_calc, calc_86);
    tcase_add_test(tc_calc, calc_87);
    tcase_add_test(tc_calc, calc_88);
    tcase_add_test(tc_calc, calc_89);
    tcase_add_test(tc_calc, calc_90);
    tcase_add_test(tc_calc, calc_91);
    tcase_add_test(tc_calc, calc_92);
    tcase_add_test(tc_calc, calc_93);
    tcase_add_test(tc_calc, calc_94);
    tcase_add_test(tc_calc, calc_95);
    tcase_add_test(tc_calc, calc_96);
    tcase_add_test(tc_calc, calc_97);
    tcase_add_test(tc_calc, calc_98);
    tcase_add_test(tc_calc, calc_99);
    tcase_add_test(tc_calc, calc_100);
    tcase_add_test(tc_calc, calc_101);
    tcase_add_test(tc_calc, calc_102);
    tcase_add_test(tc_calc, calc_103);
    tcase_add_test(tc_calc, calc_104);
    tcase_add_test(tc_calc, calc_105);
    tcase_add_test(tc_calc, calc_106);
    tcase_add_test(tc_calc, calc_107);
    tcase_add_test(tc_calc, calc_108);
    tcase_add_test(tc_calc, calc_109);
    tcase_add_test(tc_calc, calc_110);
    tcase_add_test(tc_calc, calc_111);
    tcase_add_test(tc_calc, calc_112);
    tcase_add_test(tc_calc, calc_113);
    tcase_add_test(tc_calc, calc_114);
    tcase_add_test(tc_calc, calc_115);
    tcase_add_test(tc_calc, calc_116);
    tcase_add_test(tc_calc, calc_117);
    tcase_add_test(tc_calc, calc_118);
    tcase_add_test(tc_calc, calc_119);
    tcase_add_test(tc_calc, calc_120);
    tcase_add_test(tc_calc, calc_121);
    tcase_add_test(tc_calc, calc_122);
    tcase_add_test(tc_calc, calc_123);
    tcase_add_test(tc_calc, calc_124);
    tcase_add_test(tc_calc, calc_125);
    tcase_add_test(tc_calc, calc_126);
    tcase_add_test(tc_calc, calc_127);
    tcase_add_test(tc_calc, calc_128);
    tcase_add_test(tc_calc, calc_129);
    tcase_add_test(tc_calc, calc_130);
    tcase_add_test(tc_calc, calc_131);
    tcase_add_test(tc_calc, calc_132);
    tcase_add_test(tc_calc, calc_133);
    tcase_add_test(tc_calc, calc_134);
    tcase_add_test(tc_calc, calc_135);
    tcase_add_test(tc_calc, calc_136);
    tcase_add_test(tc_calc, calc_137);
    tcase_add_test(tc_calc, calc_138);
    tcase_add_test(tc_calc, calc_139);
    tcase_add_test(tc_calc, calc_140);
    tcase_add_test(tc_calc, calc_141);
    tcase_add_test(tc_calc, calc_142);
    tcase_add_test(tc_calc, calc_143);
    tcase_add_test(tc_calc, calc_144);
    tcase_add_test(tc_calc, calc_145);
    tcase_add_test(tc_calc, calc_146);
    tcase_add_test(tc_calc, calc_147);
    tcase_add_test(tc_calc, calc_148);
    tcase_add_test(tc_calc, calc_149);
    tcase_add_test(tc_calc, calc_150);
    tcase_add_test(tc_calc, calc_151);
    tcase_add_test(tc_calc, calc_152);
    tcase_add_test(tc_calc, calc_153);
    tcase_add_test(tc_calc, calc_154);
    tcase_add_test(tc_calc, calc_155);
    tcase_add_test(tc_calc, calc_156);
    tcase_add_test(tc_calc, calc_157);
    tcase_add_test(tc_calc, calc_158);
    tcase_add_test(tc_calc, calc_159);
    tcase_add_test(tc_calc, calc_160);
    tcase_add_test(tc_calc, calc_161);
    tcase_add_test(tc_calc, calc_162);
    tcase_add_test(tc_calc, calc_163);
    tcase_add_test(tc_calc, calc_164);
    tcase_add_test(tc_calc, calc_165);
    tcase_add_test(tc_calc, calc_166);
    tcase_add_test(tc_calc, calc_167);
    tcase_add_test(tc_calc, calc_168);
    tcase_add_test(tc_calc, calc_169);
    tcase_add_test(tc_calc, calc_170);
    tcase_add_test(tc_calc, calc_171);
    tcase_add_test(tc_calc, calc_172);
    tcase_add_test(tc_calc, calc_173);
    tcase_add_test(tc_calc, calc_174);
    tcase_add_test(tc_calc, calc_175);
    tcase_add_test(tc_calc, calc_176);
    tcase_add_test(tc_calc, calc_177);
    tcase_add_test(tc_calc, calc_178);
    tcase_add_test(tc_calc, calc_179);
    tcase_add_test(tc_calc, calc_180);
    tcase_add_test(tc_calc, calc_181);
    tcase_add_test(tc_calc, calc_182);
    tcase_add_test(tc_calc, calc_183);
    tcase_add_test(tc_calc, calc_184);
    tcase_add_test(tc_calc, calc_185);
    tcase_add_test(tc_calc, calc_186);
    tcase_add_test(tc_calc, calc_187);
    tcase_add_test(tc_calc, calc_188);
    tcase_add_test(tc_calc, calc_189);
    tcase_add_test(tc_calc, calc_190);
    tcase_add_test(tc_calc, calc_191);
    tcase_add_test(tc_calc, calc_192);
    tcase_add_test(tc_calc, calc_193);
    tcase_add_test(tc_calc, calc_194);
    tcase_add_test(tc_calc, calc_195);
    tcase_add_test(tc_calc, calc_196);
    tcase_add_test(tc_calc, calc_197);
    tcase_add_test(tc_calc, calc_198);
    tcase_add_test(tc_calc, calc_199);
    tcase_add_test(tc_calc, calc_200);
    tcase_add_test(tc_calc, calc_201);
    tcase_add_test(tc_calc, calc_202);
    tcase_add_test(tc_calc, calc_203);
    tcase_add_test(tc_calc, calc_204);
    tcase_add_test(tc_calc, calc_205);
    tcase_add_test(tc_calc, calc_206);
    tcase_add_test(tc_calc, calc_207);
    tcase_add_test(tc_calc, calc_208);
    tcase_add_test(tc_calc, calc_209);
    tcase_add_test(tc_calc, calc_210);
    tcase_add_test(tc_calc, calc_211);
    tcase_add_test(tc_calc, calc_212);
    tcase_add_test(tc_calc, calc_213);
    tcase_add_test(tc_calc, calc_214);
    tcase_add_test(tc_calc, calc_215);
    tcase_add_test(tc_calc, calc_216);
    tcase_add_test(tc_calc, calc_217);
    tcase_add_test(tc_calc, calc_218);
    tcase_add_test(tc_calc, calc_219);
    tcase_add_test(tc_calc, calc_220);
    tcase_add_test(tc_calc, calc_221);
    tcase_add_test(tc_calc, calc_222);
    tcase_add_test(tc_calc, calc_223);
    tcase_add_test(tc_calc, calc_224);
    tcase_add_test(tc_calc, calc_225);
    tcase_add_test(tc_calc, calc_226);
    tcase_add_test(tc_calc, calc_227);
    tcase_add_test(tc_calc, calc_228);
    tcase_add_test(tc_calc, calc_229);
    tcase_add_test(tc_calc, calc_230);
    tcase_add_test(tc_calc, calc_231);
    tcase_add_test(tc_calc, calc_232);
    tcase_add_test(tc_calc, calc_233);
    tcase_add_test(tc_calc, calc_234);
    tcase_add_test(tc_calc, calc_235);
    tcase_add_test(tc_calc, calc_236);
    tcase_add_test(tc_calc, calc_237);
    tcase_add_test(tc_calc, calc_238);
    tcase_add_test(tc_calc, calc_239);
    tcase_add_test(tc_calc, calc_240);
    tcase_add_test(tc_calc, calc_241);
    tcase_add_test(tc_calc, calc_242);
    tcase_add_test(tc_calc, calc_243);
    tcase_add_test(tc_calc, calc_244);
    tcase_add_test(tc_calc, calc_245);
    tcase_add_test(tc_calc, calc_246);
    tcase_add_test(tc_calc, calc_247);
    tcase_add_test(tc_calc, calc_248);
    tcase_add_test(tc_calc, calc_249);
    tcase_add_test(tc_calc, calc_250);
    tcase_add_test(tc_calc, calc_251);
    tcase_add_test(tc_calc, calc_252);
    tcase_add_test(tc_calc, calc_253);
    tcase_add_test(tc_calc, calc_254);
    tcase_add_test(tc_calc, calc_255);
    tcase_add_test(tc_calc, calc_256);
    tcase_add_test(tc_calc, calc_257);
    tcase_add_test(tc_calc, calc_258);
    tcase_add_test(tc_calc, calc_259);
    tcase_add_test(tc_calc, calc_260);
    tcase_add_test(tc_calc, calc_261);
    tcase_add_test(tc_calc, calc_262);
    tcase_add_test(tc_calc, calc_263);
    tcase_add_test(tc_calc, calc_264);
    tcase_add_test(tc_calc, calc_265);
    tcase_add_test(tc_calc, calc_266);
    tcase_add_test(tc_calc, calc_267);
    tcase_add_test(tc_calc, calc_268);
    tcase_add_test(tc_calc, calc_269);
    tcase_add_test(tc_calc, calc_270);
    tcase_add_test(tc_calc, calc_271);
    tcase_add_test(tc_calc, calc_272);
    tcase_add_test(tc_calc, calc_273);
    tcase_add_test(tc_calc, calc_274);
    tcase_add_test(tc_calc, calc_275);
    tcase_add_test(tc_calc, calc_276);
    tcase_add_test(tc_calc, calc_277);
    tcase_add_test(tc_calc, calc_278);
    tcase_add_test(tc_calc, calc_279);
    tcase_add_test(tc_calc, calc_280);
    tcase_add_test(tc_calc, calc_281);
    tcase_add_test(tc_calc, calc_282);
    tcase_add_test(tc_calc, calc_283);
    tcase_add_test(tc_calc, calc_284);
    tcase_add_test(tc_calc, calc_285);
    tcase_add_test(tc_calc, calc_286);
    tcase_add_test(tc_calc, calc_287);
    tcase_add_test(tc_calc, calc_288);
    tcase_add_test(tc_calc, calc_289);
    tcase_add_test(tc_calc, calc_290);
    tcase_add_test(tc_calc, calc_291);
    tcase_add_test(tc_calc, calc_292);
    tcase_add_test(tc_calc, calc_293);
    tcase_add_test(tc_calc, calc_294);
    tcase_add_test(tc_calc, calc_295);
    tcase_add_test(tc_calc, calc_296);
    tcase_add_test(tc_calc, calc_297);
    tcase_add_test(tc_calc, calc_298);
    tcase_add_test(tc_calc, calc_299);
    tcase_add_test(tc_calc, calc_300);
    tcase_add_test(tc_calc, calc_301);
    tcase_add_test(tc_calc, calc_302);
    tcase_add_test(tc_calc, calc_303);
    tcase_add_test(tc_calc, calc_304);
    tcase_add_test(tc_calc, calc_305);
    tcase_add_test(tc_calc, calc_306);
    tcase_add_test(tc_calc, calc_307);
    tcase_add_test(tc_calc, calc_308);
    tcase_add_test(tc_calc, calc_309);
    tcase_add_test(tc_calc, calc_310);
    tcase_add_test(tc_calc, calc_311);
    tcase_add_test(tc_calc, calc_312);
    tcase_add_test(tc_calc, calc_313);
    tcase_add_test(tc_calc, calc_314);
    tcase_add_test(tc_calc, calc_315);
    tcase_add_test(tc_calc, calc_316);
    tcase_add_test(tc_calc, calc_317);
    tcase_add_test(tc_calc, calc_318);
    tcase_add_test(tc_calc, calc_319);
    tcase_add_test(tc_calc, calc_320);
    tcase_add_test(tc_calc, calc_321);
    tcase_add_test(tc_calc, calc_322);
    tcase_add_test(tc_calc, calc_323);
    tcase_add_test(tc_calc, calc_324);
    tcase_add_test(tc_calc, calc_325);
    tcase_add_test(tc_calc, calc_326);
    tcase_add_test(tc_calc, calc_327);
    tcase_add_test(tc_calc, calc_328);
    tcase_add_test(tc_calc, calc_329);
    tcase_add_test(tc_calc, calc_330);
    tcase_add_test(tc_calc, calc_331);
    tcase_add_test(tc_calc, calc_332);
    tcase_add_test(tc_calc, calc_333);
    tcase_add_test(tc_calc, calc_334);
    tcase_add_test(tc_calc, calc_335);
    tcase_add_test(tc_calc, calc_336);
    tcase_add_test(tc_calc, calc_337);
    tcase_add_test(tc_calc, calc_338);
    tcase_add_test(tc_calc, calc_339);
    tcase_add_test(tc_calc, calc_340);
    tcase_add_test(tc_calc, calc_341);
    tcase_add_test(tc_calc, calc_342);
    tcase_add_test(tc_calc, calc_343);
    tcase_add_test(tc_calc, calc_344);
    tcase_add_test(tc_calc, calc_345);
    tcase_add_test(tc_calc, calc_346);
    tcase_add_test(tc_calc, calc_347);
    tcase_add_test(tc_calc, calc_348);
    tcase_add_test(tc_calc, calc_349);
    tcase_add_test(tc_calc, calc_350);
    tcase_add_test(tc_calc, calc_351);
    tcase_add_test(tc_calc, calc_352);
    tcase_add_test(tc_calc, calc_353);
    tcase_add_test(tc_calc, calc_354);
    tcase_add_test(tc_calc, calc_355);
    tcase_add_test(tc_calc, calc_356);
    tcase_add_test(tc_calc, calc_357);
    tcase_add_test(tc_calc, calc_358);
    tcase_add_test(tc_calc, calc_359);
    tcase_add_test(tc_calc, calc_360);
    tcase_add_test(tc_calc, calc_361);
    tcase_add_test(tc_calc, calc_362);
    tcase_add_test(tc_calc, calc_363);
    tcase_add_test(tc_calc, calc_364);
    tcase_add_test(tc_calc, calc_365);
    tcase_add_test(tc_calc, calc_366);
    tcase_add_test(tc_calc, calc_367);
    tcase_add_test(tc_calc, calc_368);
    tcase_add_test(tc_calc, calc_369);
    tcase_add_test(tc_calc, calc_370);
    tcase_add_test(tc_calc, calc_371);
    tcase_add_test(tc_calc, calc_372);
    tcase_add_test(tc_calc, calc_373);
    tcase_add_test(tc_calc, calc_374);
    tcase_add_test(tc_calc, calc_375);
    tcase_add_test(tc_calc, calc_376);
    tcase_add_test(tc_calc, calc_377);
    tcase_add_test(tc_calc, calc_378);
    tcase_add_test(tc_calc, calc_379);
    tcase_add_test(tc_calc, calc_380);
    tcase_add_test(tc_calc, calc_381);
    tcase_add_test(tc_calc, calc_382);
    tcase_add_test(tc_calc, calc_383);
    tcase_add_test(tc_calc, calc_384);
    tcase_add_test(tc_calc, calc_385);
    tcase_add_test(tc_calc, calc_386);
    tcase_add_test(tc_calc, calc_387);
    tcase_add_test(tc_calc, calc_388);
    tcase_add_test(tc_calc, calc_389);
    tcase_add_test(tc_calc, calc_390);
    tcase_add_test(tc_calc, calc_391);
    tcase_add_test(tc_calc, calc_392);
    tcase_add_test(tc_calc, calc_393);
    tcase_add_test(tc_calc, calc_394);
    tcase_add_test(tc_calc, calc_395);
    tcase_add_test(tc_calc, calc_396);
    tcase_add_test(tc_calc, calc_397);
    tcase_add_test(tc_calc, calc_398);
    tcase_add_test(tc_calc, calc_399);
    tcase_add_test(tc_calc, calc_400);
    tcase_add_test(tc_calc, calc_401);
    tcase_add_test(tc_calc, calc_402);
    tcase_add_test(tc_calc, calc_403);
    tcase_add_test(tc_calc, calc_404);
    tcase_add_test(tc_calc, calc_405);
    tcase_add_test(tc_calc, calc_406);
    tcase_add_test(tc_calc, calc_407);
    tcase_add_test(tc_calc, calc_408);
    tcase_add_test(tc_calc, calc_409);
    tcase_add_test(tc_calc, calc_410);
    tcase_add_test(tc_calc, calc_411);
    tcase_add_test(tc_calc, calc_412);
    tcase_add_test(tc_calc, calc_413);
    tcase_add_test(tc_calc, calc_414);
    tcase_add_test(tc_calc, calc_415);
    tcase_add_test(tc_calc, calc_416);
    tcase_add_test(tc_calc, calc_417);
    tcase_add_test(tc_calc, calc_418);
    tcase_add_test(tc_calc, calc_419);
    tcase_add_test(tc_calc, calc_420);
    tcase_add_test(tc_calc, calc_421);
    tcase_add_test(tc_calc, calc_422);
    tcase_add_test(tc_calc, calc_423);
    tcase_add_test(tc_calc, calc_424);
    tcase_add_test(tc_calc, calc_425);
    tcase_add_test(tc_calc, calc_426);
    tcase_add_test(tc_calc, calc_427);
    tcase_add_test(tc_calc, calc_428);
    tcase_add_test(tc_calc, calc_429);
    tcase_add_test(tc_calc, calc_430);
    tcase_add_test(tc_calc, calc_431);
    tcase_add_test(tc_calc, calc_432);
    tcase_add_test(tc_calc, calc_433);
    tcase_add_test(tc_calc, calc_434);
    tcase_add_test(tc_calc, calc_435);
    tcase_add_test(tc_calc, calc_436);
    tcase_add_test(tc_calc, calc_437);
    tcase_add_test(tc_calc, calc_438);
    tcase_add_test(tc_calc, calc_439);
    tcase_add_test(tc_calc, calc_440);
    tcase_add_test(tc_calc, calc_441);
    tcase_add_test(tc_calc, calc_442);
    tcase_add_test(tc_calc, calc_443);
    tcase_add_test(tc_calc, calc_444);
    tcase_add_test(tc_calc, calc_445);
    tcase_add_test(tc_calc, calc_446);
    tcase_add_test(tc_calc, calc_447);
    tcase_add_test(tc_calc, calc_448);
    tcase_add_test(tc_calc, calc_449);
    tcase_add_test(tc_calc, calc_450);
    tcase_add_test(tc_calc, calc_451);
    tcase_add_test(tc_calc, calc_452);
    tcase_add_test(tc_calc, calc_453);
    tcase_add_test(tc_calc, calc_454);
    tcase_add_test(tc_calc, calc_455);
    tcase_add_test(tc_calc, calc_456);
    tcase_add_test(tc_calc, calc_457);
    tcase_add_test(tc_calc, calc_458);
    tcase_add_test(tc_calc, calc_459);
    tcase_add_test(tc_calc, calc_460);
    tcase_add_test(tc_calc, calc_461);
    tcase_add_test(tc_calc, calc_462);
    tcase_add_test(tc_calc, calc_463);
    tcase_add_test(tc_calc, calc_464);
    tcase_add_test(tc_calc, calc_465);
    tcase_add_test(tc_calc, calc_466);
    tcase_add_test(tc_calc, calc_467);
    tcase_add_test(tc_calc, calc_468);
    tcase_add_test(tc_calc, calc_469);
    tcase_add_test(tc_calc, calc_470);
    tcase_add_test(tc_calc, calc_471);
    tcase_add_test(tc_calc, calc_472);
    tcase_add_test(tc_calc, calc_473);
    tcase_add_test(tc_calc, calc_474);
    tcase_add_test(tc_calc, calc_475);
    tcase_add_test(tc_calc, calc_476);
    tcase_add_test(tc_calc, calc_477);
    tcase_add_test(tc_calc, calc_478);
    tcase_add_test(tc_calc, calc_479);
    tcase_add_test(tc_calc, calc_480);
    tcase_add_test(tc_calc, calc_481);
    tcase_add_test(tc_calc, calc_482);
    tcase_add_test(tc_calc, calc_483);
    tcase_add_test(tc_calc, calc_484);
    tcase_add_test(tc_calc, calc_485);
    tcase_add_test(tc_calc, calc_486);
    tcase_add_test(tc_calc, calc_487);
    tcase_add_test(tc_calc, calc_488);
    tcase_add_test(tc_calc, calc_489);
    tcase_add_test(tc_calc, calc_490);
    tcase_add_test(tc_calc, calc_491);
    tcase_add_test(tc_calc, calc_492);
    tcase_add_test(tc_calc, calc_493);
    tcase_add_test(tc_calc, calc_494);
    tcase_add_test(tc_calc, calc_495);
    tcase_add_test(tc_calc, calc_496);
    tcase_add_test(tc_calc, calc_497);
    tcase_add_test(tc_calc, calc_498);
    tcase_add_test(tc_calc, calc_499);
    tcase_add_test(tc_calc, calc_500);
    tcase_add_test(tc_calc, calc_501);
    tcase_add_test(tc_calc, calc_502);
    tcase_add_test(tc_calc, calc_503);
    tcase_add_test(tc_calc, calc_504);
    tcase_add_test(tc_calc, calc_505);
    tcase_add_test(tc_calc, calc_506);
    tcase_add_test(tc_calc, calc_507);
    tcase_add_test(tc_calc, calc_508);
    tcase_add_test(tc_calc, calc_509);
    tcase_add_test(tc_calc, calc_510);
    tcase_add_test(tc_calc, calc_511);
    tcase_add_test(tc_calc, calc_512);
    tcase_add_test(tc_calc, calc_513);
    tcase_add_test(tc_calc, calc_514);
    tcase_add_test(tc_calc, calc_515);
    tcase_add_test(tc_calc, calc_516);
    tcase_add_test(tc_calc, calc_517);
    tcase_add_test(tc_calc, calc_518);
    tcase_add_test(tc_calc, calc_519);
    tcase_add_test(tc_calc, calc_520);
    tcase_add_test(tc_calc, calc_521);
    tcase_add_test(tc_calc, calc_522);
    tcase_add_test(tc_calc, calc_523);
    tcase_add_test(tc_calc, calc_524);
    tcase_add_test(tc_calc, calc_525);
    tcase_add_test(tc_calc, calc_526);
    tcase_add_test(tc_calc, calc_527);
    tcase_add_test(tc_calc, calc_528);
    tcase_add_test(tc_calc, calc_529);
    tcase_add_test(tc_calc, calc_530);
    tcase_add_test(tc_calc, calc_531);
    tcase_add_test(tc_calc, calc_532);
    tcase_add_test(tc_calc, calc_533);
    tcase_add_test(tc_calc, calc_534);
    tcase_add_test(tc_calc, calc_535);
    tcase_add_test(tc_calc, calc_536);
    tcase_add_test(tc_calc, calc_537);
    tcase_add_test(tc_calc, calc_538);
    tcase_add_test(tc_calc, calc_539);
    tcase_add_test(tc_calc, calc_540);
    tcase_add_test(tc_calc, calc_541);
    tcase_add_test(tc_calc, calc_542);
    tcase_add_test(tc_calc, calc_543);
    tcase_add_test(tc_calc, calc_544);
    tcase_add_test(tc_calc, calc_545);
    tcase_add_test(tc_calc, calc_546);
    tcase_add_test(tc_calc, calc_547);
    tcase_add_test(tc_calc, calc_548);
    tcase_add_test(tc_calc, calc_549);
    tcase_add_test(tc_calc, calc_550);
    tcase_add_test(tc_calc, calc_551);
    tcase_add_test(tc_calc, calc_552);
    tcase_add_test(tc_calc, calc_553);
    tcase_add_test(tc_calc, calc_554);
    tcase_add_test(tc_calc, calc_555);
    tcase_add_test(tc_calc, calc_556);
    tcase_add_test(tc_calc, calc_557);
    tcase_add_test(tc_calc, calc_558);
    tcase_add_test(tc_calc, calc_559);
    tcase_add_test(tc_calc, calc_560);
    tcase_add_test(tc_calc, calc_561);
    tcase_add_test(tc_calc, calc_562);
    tcase_add_test(tc_calc, calc_563);
    tcase_add_test(tc_calc, calc_564);
    tcase_add_test(tc_calc, calc_565);
    tcase_add_test(tc_calc, calc_566);
    tcase_add_test(tc_calc, calc_567);
    tcase_add_test(tc_calc, calc_568);
    tcase_add_test(tc_calc, calc_569);
    tcase_add_test(tc_calc, calc_570);
    tcase_add_test(tc_calc, calc_571);
    tcase_add_test(tc_calc, calc_572);
    tcase_add_test(tc_calc, calc_573);
    tcase_add_test(tc_calc, calc_574);
    tcase_add_test(tc_calc, calc_575);
    tcase_add_test(tc_calc, calc_576);
    tcase_add_test(tc_calc, calc_577);
    tcase_add_test(tc_calc, calc_578);
    tcase_add_test(tc_calc, calc_579);
    tcase_add_test(tc_calc, calc_580);
    tcase_add_test(tc_calc, calc_581);
    tcase_add_test(tc_calc, calc_582);
    tcase_add_test(tc_calc, calc_583);
    tcase_add_test(tc_calc, calc_584);
    tcase_add_test(tc_calc, calc_585);
    tcase_add_test(tc_calc, calc_586);
    tcase_add_test(tc_calc, calc_587);
    tcase_add_test(tc_calc, calc_588);
    tcase_add_test(tc_calc, calc_589);
    tcase_add_test(tc_calc, calc_590);
    tcase_add_test(tc_calc, calc_591);
    tcase_add_test(tc_calc, calc_592);
    tcase_add_test(tc_calc, calc_593);
    tcase_add_test(tc_calc, calc_594);
    tcase_add_test(tc_calc, calc_595);
    tcase_add_test(tc_calc, calc_596);
    tcase_add_test(tc_calc, calc_597);
    tcase_add_test(tc_calc, calc_598);
    tcase_add_test(tc_calc, calc_599);
    tcase_add_test(tc_calc, calc_600);
    tcase_add_test(tc_calc, calc_601);
    tcase_add_test(tc_calc, calc_602);
    tcase_add_test(tc_calc, calc_603);
    tcase_add_test(tc_calc, calc_604);
    tcase_add_test(tc_calc, calc_605);
    tcase_add_test(tc_calc, calc_606);
    tcase_add_test(tc_calc, calc_607);
    tcase_add_test(tc_calc, calc_608);
    tcase_add_test(tc_calc, calc_609);
    tcase_add_test(tc_calc, calc_610);
    tcase_add_test(tc_calc, calc_611);
    tcase_add_test(tc_calc, calc_612);
    tcase_add_test(tc_calc, calc_613);
    tcase_add_test(tc_calc, calc_614);
    tcase_add_test(tc_calc, calc_615);
    tcase_add_test(tc_calc, calc_616);
    tcase_add_test(tc_calc, calc_617);
    tcase_add_test(tc_calc, calc_618);
    tcase_add_test(tc_calc, calc_619);
    tcase_add_test(tc_calc, calc_620);
    tcase_add_test(tc_calc, calc_621);
    tcase_add_test(tc_calc, calc_622);
    tcase_add_test(tc_calc, calc_623);
    tcase_add_test(tc_calc, calc_624);
    tcase_add_test(tc_calc, calc_625);
    tcase_add_test(tc_calc, calc_626);
    tcase_add_test(tc_calc, calc_627);
    tcase_add_test(tc_calc, calc_628);
    tcase_add_test(tc_calc, calc_629);
    tcase_add_test(tc_calc, calc_630);
    tcase_add_test(tc_calc, calc_631);
    tcase_add_test(tc_calc, calc_632);
    tcase_add_test(tc_calc, calc_633);
    tcase_add_test(tc_calc, calc_634);
    tcase_add_test(tc_calc, calc_635);
    tcase_add_test(tc_calc, calc_636);
    tcase_add_test(tc_calc, calc_637);
    tcase_add_test(tc_calc, calc_638);
    tcase_add_test(tc_calc, calc_639);
    tcase_add_test(tc_calc, calc_640);
    tcase_add_test(tc_calc, calc_641);
    tcase_add_test(tc_calc, calc_642);
    tcase_add_test(tc_calc, calc_643);
    tcase_add_test(tc_calc, calc_644);
    tcase_add_test(tc_calc, calc_645);
    tcase_add_test(tc_calc, calc_646);
    tcase_add_test(tc_calc, calc_647);
    tcase_add_test(tc_calc, calc_648);
    tcase_add_test(tc_calc, calc_649);
    tcase_add_test(tc_calc, calc_650);
    tcase_add_test(tc_calc, calc_651);
    tcase_add_test(tc_calc, calc_652);
    tcase_add_test(tc_calc, calc_653);
    tcase_add_test(tc_calc, calc_654);
    tcase_add_test(tc_calc, calc_655);
    tcase_add_test(tc_calc, calc_656);
    tcase_add_test(tc_calc, calc_657);
    tcase_add_test(tc_calc, calc_658);
    tcase_add_test(tc_calc, calc_659);
    tcase_add_test(tc_calc, calc_660);
    tcase_add_test(tc_calc, calc_661);
    tcase_add_test(tc_calc, calc_662);
    tcase_add_test(tc_calc, calc_663);
    tcase_add_test(tc_calc, calc_664);
    tcase_add_test(tc_calc, calc_665);
    tcase_add_test(tc_calc, calc_666);
    tcase_add_test(tc_calc, calc_667);
    tcase_add_test(tc_calc, calc_668);
    tcase_add_test(tc_calc, calc_669);
    tcase_add_test(tc_calc, calc_670);
    tcase_add_test(tc_calc, calc_671);
    tcase_add_test(tc_calc, calc_672);
    tcase_add_test(tc_calc, calc_673);
    tcase_add_test(tc_calc, calc_674);
    tcase_add_test(tc_calc, calc_675);
    tcase_add_test(tc_calc, calc_676);
    tcase_add_test(tc_calc, calc_677);
    tcase_add_test(tc_calc, calc_678);
    tcase_add_test(tc_calc, calc_679);
    tcase_add_test(tc_calc, calc_680);
    tcase_add_test(tc_calc, calc_681);
    tcase_add_test(tc_calc, calc_682);
    tcase_add_test(tc_calc, calc_683);
    tcase_add_test(tc_calc, calc_684);
    tcase_add_test(tc_calc, calc_685);
    tcase_add_test(tc_calc, calc_686);
    tcase_add_test(tc_calc, calc_687);
    tcase_add_test(tc_calc, calc_688);
    tcase_add_test(tc_calc, calc_689);
    tcase_add_test(tc_calc, calc_690);
    tcase_add_test(tc_calc, calc_691);
    tcase_add_test(tc_calc, calc_692);
    tcase_add_test(tc_calc, calc_693);
    tcase_add_test(tc_calc, calc_694);
    tcase_add_test(tc_calc, calc_695);
    tcase_add_test(tc_calc, calc_696);
    tcase_add_test(tc_calc, calc_697);
    tcase_add_test(tc_calc, calc_698);
    tcase_add_test(tc_calc, calc_699);
    tcase_add_test(tc_calc, calc_700);
    tcase_add_test(tc_calc, calc_701);
    tcase_add_test(tc_calc, calc_702);
    tcase_add_test(tc_calc, calc_703);
    tcase_add_test(tc_calc, calc_704);
    tcase_add_test(tc_calc, calc_705);
    tcase_add_test(tc_calc, calc_706);
    tcase_add_test(tc_calc, calc_707);
    tcase_add_test(tc_calc, calc_708);
    tcase_add_test(tc_calc, calc_709);
    tcase_add_test(tc_calc, calc_710);
    tcase_add_test(tc_calc, calc_711);
    tcase_add_test(tc_calc, calc_712);
    tcase_add_test(tc_calc, calc_713);
    tcase_add_test(tc_calc, calc_714);
    tcase_add_test(tc_calc, calc_715);
    tcase_add_test(tc_calc, calc_716);
    tcase_add_test(tc_calc, calc_717);
    tcase_add_test(tc_calc, calc_718);
    tcase_add_test(tc_calc, calc_719);
    tcase_add_test(tc_calc, calc_720);
    tcase_add_test(tc_calc, calc_721);
    tcase_add_test(tc_calc, calc_722);
    tcase_add_test(tc_calc, calc_723);
    tcase_add_test(tc_calc, calc_724);
    tcase_add_test(tc_calc, calc_725);
    tcase_add_test(tc_calc, calc_726);
    tcase_add_test(tc_calc, calc_727);
    tcase_add_test(tc_calc, calc_728);
    tcase_add_test(tc_calc, calc_729);
    tcase_add_test(tc_calc, calc_730);
    tcase_add_test(tc_calc, calc_731);
    tcase_add_test(tc_calc, calc_732);
    tcase_add_test(tc_calc, calc_733);
    tcase_add_test(tc_calc, calc_734);
    tcase_add_test(tc_calc, calc_735);
    tcase_add_test(tc_calc, calc_736);
    tcase_add_test(tc_calc, calc_737);
    tcase_add_test(tc_calc, calc_738);
    tcase_add_test(tc_calc, calc_739);
    tcase_add_test(tc_calc, calc_740);
    tcase_add_test(tc_calc, calc_741);
    tcase_add_test(tc_calc, calc_742);
    tcase_add_test(tc_calc, calc_743);
    tcase_add_test(tc_calc, calc_744);
    tcase_add_test(tc_calc, calc_745);
    tcase_add_test(tc_calc, calc_746);
    tcase_add_test(tc_calc, calc_747);
    tcase_add_test(tc_calc, calc_748);
    tcase_add_test(tc_calc, calc_749);
    tcase_add_test(tc_calc, calc_750);
    tcase_add_test(tc_calc, calc_751);
    tcase_add_test(tc_calc, calc_752);
    tcase_add_test(tc_calc, calc_753);
    tcase_add_test(tc_calc, calc_754);
    tcase_add_test(tc_calc, calc_755);
    tcase_add_test(tc_calc, calc_756);
    tcase_add_test(tc_calc, calc_757);
    tcase_add_test(tc_calc, calc_758);
    tcase_add_test(tc_calc, calc_759);
    tcase_add_test(tc_calc, calc_760);
    tcase_add_test(tc_calc, calc_761);
    tcase_add_test(tc_calc, calc_762);
    tcase_add_test(tc_calc, calc_763);
    tcase_add_test(tc_calc, calc_764);
    tcase_add_test(tc_calc, calc_765);
    tcase_add_test(tc_calc, calc_766);
    tcase_add_test(tc_calc, calc_767);
    tcase_add_test(tc_calc, calc_768);
    tcase_add_test(tc_calc, calc_769);
    tcase_add_test(tc_calc, calc_770);
    tcase_add_test(tc_calc, calc_771);
    tcase_add_test(tc_calc, calc_772);
    tcase_add_test(tc_calc, calc_773);
    tcase_add_test(tc_calc, calc_774);
    tcase_add_test(tc_calc, calc_775);
    tcase_add_test(tc_calc, calc_776);
    tcase_add_test(tc_calc, calc_777);
    tcase_add_test(tc_calc, calc_778);
    tcase_add_test(tc_calc, calc_779);
    tcase_add_test(tc_calc, calc_780);
    tcase_add_test(tc_calc, calc_781);
    tcase_add_test(tc_calc, calc_782);
    tcase_add_test(tc_calc, calc_783);
    tcase_add_test(tc_calc, calc_784);
    tcase_add_test(tc_calc, calc_785);
    tcase_add_test(tc_calc, calc_786);
    tcase_add_test(tc_calc, calc_787);
    tcase_add_test(tc_calc, calc_788);
    tcase_add_test(tc_calc, calc_789);
    tcase_add_test(tc_calc, calc_790);
    tcase_add_test(tc_calc, calc_791);
    tcase_add_test(tc_calc, calc_792);
    tcase_add_test(tc_calc, calc_793);
    tcase_add_test(tc_calc, calc_794);
    tcase_add_test(tc_calc, calc_795);
    tcase_add_test(tc_calc, calc_796);
    tcase_add_test(tc_calc, calc_797);
    tcase_add_test(tc_calc, calc_798);
    tcase_add_test(tc_calc, calc_799);
    tcase_add_test(tc_calc, calc_800);
    tcase_add_test(tc_calc, calc_801);
    tcase_add_test(tc_calc, calc_802);
    tcase_add_test(tc_calc, calc_803);
    tcase_add_test(tc_calc, calc_804);
    tcase_add_test(tc_calc, calc_805);
    tcase_add_test(tc_calc, calc_806);
    tcase_add_test(tc_calc, calc_807);
    tcase_add_test(tc_calc, calc_808);
    tcase_add_test(tc_calc, calc_809);
    tcase_add_test(tc_calc, calc_810);
    tcase_add_test(tc_calc, calc_811);
    tcase_add_test(tc_calc, calc_812);
    tcase_add_test(tc_calc, calc_813);
    tcase_add_test(tc_calc, calc_814);
    tcase_add_test(tc_calc, calc_815);
    tcase_add_test(tc_calc, calc_816);
    tcase_add_test(tc_calc, calc_817);
    tcase_add_test(tc_calc, calc_818);
    tcase_add_test(tc_calc, calc_819);
    tcase_add_test(tc_calc, calc_820);
    tcase_add_test(tc_calc, calc_821);
    tcase_add_test(tc_calc, calc_822);
    tcase_add_test(tc_calc, calc_823);
    tcase_add_test(tc_calc, calc_824);
    tcase_add_test(tc_calc, calc_825);
    tcase_add_test(tc_calc, calc_826);
    tcase_add_test(tc_calc, calc_827);
    tcase_add_test(tc_calc, calc_828);
    tcase_add_test(tc_calc, calc_829);
    tcase_add_test(tc_calc, calc_830);
    tcase_add_test(tc_calc, calc_831);
    tcase_add_test(tc_calc, calc_832);
    tcase_add_test(tc_calc, calc_833);
    tcase_add_test(tc_calc, calc_834);
    tcase_add_test(tc_calc, calc_835);
    tcase_add_test(tc_calc, calc_836);
    tcase_add_test(tc_calc, calc_837);
    tcase_add_test(tc_calc, calc_838);
    tcase_add_test(tc_calc, calc_839);
    tcase_add_test(tc_calc, calc_840);
    tcase_add_test(tc_calc, calc_841);
    tcase_add_test(tc_calc, calc_842);
    tcase_add_test(tc_calc, calc_843);
    tcase_add_test(tc_calc, calc_844);
    tcase_add_test(tc_calc, calc_845);
    tcase_add_test(tc_calc, calc_846);
    tcase_add_test(tc_calc, calc_847);
    tcase_add_test(tc_calc, calc_848);
    tcase_add_test(tc_calc, calc_849);
    tcase_add_test(tc_calc, calc_850);
    tcase_add_test(tc_calc, calc_851);
    tcase_add_test(tc_calc, calc_852);
    tcase_add_test(tc_calc, calc_853);
    tcase_add_test(tc_calc, calc_854);
    tcase_add_test(tc_calc, calc_855);
    tcase_add_test(tc_calc, calc_856);
    tcase_add_test(tc_calc, calc_857);
    tcase_add_test(tc_calc, calc_858);
    tcase_add_test(tc_calc, calc_859);
    tcase_add_test(tc_calc, calc_860);
    tcase_add_test(tc_calc, calc_861);
    tcase_add_test(tc_calc, calc_862);
    tcase_add_test(tc_calc, calc_863);
    tcase_add_test(tc_calc, calc_864);
    tcase_add_test(tc_calc, calc_865);
    tcase_add_test(tc_calc, calc_866);
    tcase_add_test(tc_calc, calc_867);
    tcase_add_test(tc_calc, calc_868);
    tcase_add_test(tc_calc, calc_869);
    tcase_add_test(tc_calc, calc_870);
    tcase_add_test(tc_calc, calc_871);
    tcase_add_test(tc_calc, calc_872);
    tcase_add_test(tc_calc, calc_873);
    tcase_add_test(tc_calc, calc_874);
    tcase_add_test(tc_calc, calc_875);
    tcase_add_test(tc_calc, calc_876);
    tcase_add_test(tc_calc, calc_877);
    tcase_add_test(tc_calc, calc_878);
    tcase_add_test(tc_calc, calc_879);
    tcase_add_test(tc_calc, calc_880);
    tcase_add_test(tc_calc, calc_881);
    tcase_add_test(tc_calc, calc_882);
    tcase_add_test(tc_calc, calc_883);
    tcase_add_test(tc_calc, calc_884);
    tcase_add_test(tc_calc, calc_885);
    tcase_add_test(tc_calc, calc_886);
    tcase_add_test(tc_calc, calc_887);
    tcase_add_test(tc_calc, calc_888);
    tcase_add_test(tc_calc, calc_889);
    tcase_add_test(tc_calc, calc_890);
    tcase_add_test(tc_calc, calc_891);
    tcase_add_test(tc_calc, calc_892);
    tcase_add_test(tc_calc, calc_893);
    tcase_add_test(tc_calc, calc_894);
    tcase_add_test(tc_calc, calc_895);
    tcase_add_test(tc_calc, calc_896);
    tcase_add_test(tc_calc, calc_897);
    tcase_add_test(tc_calc, calc_898);
    tcase_add_test(tc_calc, calc_899);
    tcase_add_test(tc_calc, calc_900);
    tcase_add_test(tc_calc, calc_901);
    tcase_add_test(tc_calc, calc_902);
    tcase_add_test(tc_calc, calc_903);
    tcase_add_test(tc_calc, calc_904);
    tcase_add_test(tc_calc, calc_905);
    tcase_add_test(tc_calc, calc_906);
    tcase_add_test(tc_calc, calc_907);
    tcase_add_test(tc_calc, calc_908);
    tcase_add_test(tc_calc, calc_909);
    tcase_add_test(tc_calc, calc_910);
    tcase_add_test(tc_calc, calc_911);
    tcase_add_test(tc_calc, calc_912);
    tcase_add_test(tc_calc, calc_913);
    tcase_add_test(tc_calc, calc_914);
    tcase_add_test(tc_calc, calc_915);
    tcase_add_test(tc_calc, calc_916);
    tcase_add_test(tc_calc, calc_917);
    tcase_add_test(tc_calc, calc_918);
    tcase_add_test(tc_calc, calc_919);
    tcase_add_test(tc_calc, calc_920);
    tcase_add_test(tc_calc, calc_921);
    tcase_add_test(tc_calc, calc_922);
    tcase_add_test(tc_calc, calc_923);
    tcase_add_test(tc_calc, calc_924);
    tcase_add_test(tc_calc, calc_925);
    tcase_add_test(tc_calc, calc_926);
    tcase_add_test(tc_calc, calc_927);
    tcase_add_test(tc_calc, calc_928);
    tcase_add_test(tc_calc, calc_929);
    tcase_add_test(tc_calc, calc_930);
    tcase_add_test(tc_calc, calc_931);
    tcase_add_test(tc_calc, calc_932);
    tcase_add_test(tc_calc, calc_933);
    tcase_add_test(tc_calc, calc_934);
    tcase_add_test(tc_calc, calc_935);
    tcase_add_test(tc_calc, calc_936);
    tcase_add_test(tc_calc, calc_937);
    tcase_add_test(tc_calc, calc_938);
    tcase_add_test(tc_calc, calc_939);
    tcase_add_test(tc_calc, calc_940);
    tcase_add_test(tc_calc, calc_941);
    tcase_add_test(tc_calc, calc_942);
    tcase_add_test(tc_calc, calc_943);
    tcase_add_test(tc_calc, calc_944);
    tcase_add_test(tc_calc, calc_945);
    tcase_add_test(tc_calc, calc_946);
    tcase_add_test(tc_calc, calc_947);
    tcase_add_test(tc_calc, calc_948);
    tcase_add_test(tc_calc, calc_949);
    tcase_add_test(tc_calc, calc_950);
    tcase_add_test(tc_calc, calc_951);
    tcase_add_test(tc_calc, calc_952);
    tcase_add_test(tc_calc, calc_953);
    tcase_add_test(tc_calc, calc_954);
    tcase_add_test(tc_calc, calc_955);
    tcase_add_test(tc_calc, calc_956);
    tcase_add_test(tc_calc, calc_957);
    tcase_add_test(tc_calc, calc_958);
    tcase_add_test(tc_calc, calc_959);
    tcase_add_test(tc_calc, calc_960);
    tcase_add_test(tc_calc, calc_961);
    tcase_add_test(tc_calc, calc_962);
    tcase_add_test(tc_calc, calc_963);
    tcase_add_test(tc_calc, calc_964);
    tcase_add_test(tc_calc, calc_965);
    tcase_add_test(tc_calc, calc_966);
    tcase_add_test(tc_calc, calc_967);
    tcase_add_test(tc_calc, calc_968);
    tcase_add_test(tc_calc, calc_969);
    tcase_add_test(tc_calc, calc_970);
    tcase_add_test(tc_calc, calc_971);
    tcase_add_test(tc_calc, calc_972);
    tcase_add_test(tc_calc, calc_973);
    tcase_add_test(tc_calc, calc_974);
    tcase_add_test(tc_calc, calc_975);
    tcase_add_test(tc_calc, calc_976);
    tcase_add_test(tc_calc, calc_977);
    tcase_add_test(tc_calc, calc_978);
    tcase_add_test(tc_calc, calc_979);
    tcase_add_test(tc_calc, calc_980);
    tcase_add_test(tc_calc, calc_981);
    tcase_add_test(tc_calc, calc_982);
    tcase_add_test(tc_calc, calc_983);
    tcase_add_test(tc_calc, calc_984);
    tcase_add_test(tc_calc, calc_985);
    tcase_add_test(tc_calc, calc_986);
    tcase_add_test(tc_calc, calc_987);
    tcase_add_test(tc_calc, calc_988);
    tcase_add_test(tc_calc, calc_989);
    tcase_add_test(tc_calc, calc_990);
    tcase_add_test(tc_calc, calc_991);
    tcase_add_test(tc_calc, calc_992);
    tcase_add_test(tc_calc, calc_993);
    tcase_add_test(tc_calc, calc_994);
    tcase_add_test(tc_calc, calc_995);
    tcase_add_test(tc_calc, calc_996);
    tcase_add_test(tc_calc, calc_997);
    tcase_add_test(tc_calc, calc_998);
    tcase_add_test(tc_calc, calc_999);
    tcase_add_test(tc_calc, calc_1000);

    suite_add_tcase(s, tc_calc);
    
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
