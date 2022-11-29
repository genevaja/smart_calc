#include "common_fn.h"

#define LETTER 1
#define DIGIT 2
#define DEFAULT 0

int check_unary(char *sub_string, math_fn *stack) {
  int check_result = -1;
  if (stack->size == 0) {
    if (!strcmp(sub_string, "-"))
      check_result = MINUS;
    else if (!strcmp(sub_string, "+"))
      check_result = PLUS;
  } else if (!strcmp(stack->stack[stack->size - 1].data, "(")) {
    if (!strcmp(sub_string, "-"))
      check_result = MINUS;
    else if (!strcmp(sub_string, "+"))
      check_result = PLUS;
  } else if (strcmp(stack->stack[stack->size].data, ")")) {
    if (!strcmp(sub_string, "-"))
      check_result = SUB;
    else if (!strcmp(sub_string, "+"))
      check_result = SUM;
  } else if (stack->stack[stack->size].keys == NUMBER) {
    if (!strcmp(sub_string, "-"))
      check_result = SUB;
    else if (!strcmp(sub_string, "+"))
      check_result = SUM;
  }
  return check_result;
}


int key_return(char *string) {
  int key_code = -1;
  if (!strcmp(string, "log"))
    key_code = LOG;
  if (!strcmp(string, "ln"))
    key_code = LN;
  if (!strcmp(string, "sin"))
    key_code = SIN;
  if (!strcmp(string, "cos"))
    key_code = COS;
  if (!strcmp(string, "tan"))
    key_code = TAN;
  if (!strcmp(string, "ctg"))
    key_code = CTG;
  if (!strcmp(string, "acos"))
    key_code = ACOS;
  if (!strcmp(string, "asin"))
    key_code = ASIN;
  if (!strcmp(string, "atan"))
    key_code = ATAN;
  if (!strcmp(string, "actg"))
    key_code = ACTG;
  if (!strcmp(string, "("))
    key_code = BRO;
  if (!strcmp(string, ")"))
    key_code = BRC;
  if (!strcmp(string, "/"))
    key_code = DIV;
  if (!strcmp(string, "*"))
    key_code = MUL;
  if (!strcmp(string, "+"))
    key_code = SUM;
  if (!strcmp(string, "-"))
    key_code = MINUS;
  if (!strcmp(string, "sqrt"))
    key_code = SQRT;
  if (!strcmp(string, "mod"))
    key_code = MOD;
  if (!strcmp(string, "%"))
    key_code = MOD;
  if (!strcmp(string, "^"))
    key_code = POW;
  if (!strcmp(string, "x"))
    key_code = VAR;
  if (!strcmp(string, "y"))
    key_code = VAR;
  if (!strcmp(string, "z"))
    key_code = VAR;
  return key_code;
}


int letter_check(char letter) {
  int exit_code = FAILURE;
  int L_start = 65, L_end = 90;
  int l_start = 97, l_end = 122;
  if ((letter >= L_start && letter <= L_end) ||
      (letter >= l_start && letter <= l_end)) {
    exit_code = SUCCESS;
  } else {
    int spec_symbol[] = {37, 40, 41, 42, 43, 45, 47, 94};
    for (int i = 0; i < (int)(sizeof(spec_symbol)/4); i++) {
      if (letter == spec_symbol[i]) {
        exit_code = SUCCESS;
        break;
      }
    }
  }
  return exit_code;
}

int check_dot(char *sub_string) {
  int summ = 0;
  for (int i = 0; i < (int)strlen(sub_string); i++) {
    if (sub_string[i] == '.')
      summ++;
  }
  return (summ <= 1) ? SUCCESS : WRONG_EXPRESSION;
}


int parser(math_fn *stack, char *string, char *x_var) {
  int exit_code = SUCCESS;
  char *lexemes[] = LEXEME;
  // Сначала сбрасываем счётчик стека
  // if (stack->size != 0)
  //   stack->size = 0;
  // Объявляем массив для извлечённой подстроки
  char sub_string[MAX_BUF] = {'\0'};
  size_t start = 0, i = 0;
  double default_val = 0.0;
  // Пока есть что парсить
  int sub_str_flag = DEFAULT;
  while (start < strlen(string)) {
    // printf("SUB_STR_FLAG: %d\n", sub_str_flag);
    int push_res = FAILURE;

    // Если в текущей позиции в строкe буква или специальный символ
    if (!letter_check(string[start])) {
      sub_str_flag = LETTER;
      // Копируем символ в sub_str
      sub_string[i] = string[start];
      // И проверяем sub_str со всеми элементами LEXEME
      for (int j = 0; j < (int)(sizeof(lexemes)/8); j++) {
        // Если соответствие найдено, заталкиваем слово в стек
        // и обнуляем подстроку cо счётчиком подстроки
        if (!strcmp(sub_string, lexemes[j])) {
          int key_code = key_return(sub_string);
          if (key_code == VAR) {
            if (x_var != NULL) {
              default_val = atof(x_var);
              key_code = NUMBER;
            } else {
              exit_code = VAR_NOT_DEFINED;
              break;
            }
          }

          // Check unary minus and plus
          if (!strcmp(sub_string, "-") || !strcmp(sub_string, "+"))
            key_code = check_unary(sub_string, stack);
          push(stack, sub_string, default_val, key_code);
          memset(sub_string, '\0', MAX_BUF);
          i = DEFAULT; sub_str_flag = DEFAULT;
          push_res = SUCCESS;
          break;
        }
      }
      // Если в стек ничего не пушили, то двигаем указатель для sub_string
      if (push_res != SUCCESS)
        i++;
      // Cмещаем указатель по string и проходим на новую итерацию while 
      start++;
      continue;
    } else if ((string[start] >= 48 && string[start] <= 57) || string[start] == 46) {
        // Если до встречи с цифрой не было push, значит, выражение некорректно
        if (sub_str_flag == LETTER) {
          exit_code = WRONG_EXPRESSION;
          break;
        }
        // Если в текущей позиции цифра или точка, копируем значение в подстроку
        sub_string[i] = string[start];
        // Если следующий элемент string не цифра, заталкиваем подстроку в стек
        // И обнуляем подстроку с счётчиком подстроки
        if ((string[start + 1] < 48 || string[start + 1] > 57) && string[start + 1] != 46) {
          // Если в числе несколько точек, прерываем программу
          if (check_dot(sub_string)) {
            exit_code = WRONG_EXPRESSION;
            break;
          }
          push(stack, sub_string, atof(sub_string), NUMBER);
          memset(sub_string, '\0', MAX_BUF);
          push_res = SUCCESS;
          i = 0;
        }
        if (push_res != SUCCESS)
          i++;
        start++;
        continue;
    } else {
      // Если ни один символ не попадает в проверяемые диапазоны, возвращаем ошибку
      // printf("Sub_string: %s\n", sub_string);
      exit_code = WRONG_EXPRESSION;
      break;
    }
  }
  // printf("Sub_string: %s\n", sub_string);
  return exit_code; 
}
