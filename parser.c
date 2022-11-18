#include "common_fn.h"

// L: 65-90
// l: 97-122
// d: 40-57
// .: 46    /: 47   +: 43   -: 45   *: 42   (: 40   ): 41   %: 37   ^: 94

// sin(90)/cos(180)*3.1423455*sqrt(16)*-1mod10

#define LETTER 1
#define DIGIT 2
#define DEFAULT 0


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


int parser(stack_t *stack, char *string) {
  int exit_code = SUCCESS;
  char *lexemes[] = LEXEME;
  // Сначала сбрасываем счётчик стека
  // if (stack->size != 0)
  //   stack->size = 0;
  // Объявляем массив для извлечённой подстроки
  char sub_string[MAX_BUF] = {'\0'};
  size_t start = 0, i = 0;
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
          push(stack, sub_string);
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
          push(stack, sub_string);
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
