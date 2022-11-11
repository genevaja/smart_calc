#include "common_fn.h"

// L: 65-90
// l: 97-122
// d: 40-57
// .: 46    /: 47   +: 43   -: 45   *: 42   (: 40   ): 41   %: 37   ^: 94

// sin(90)/cos(180)*3.1423455*sqrt(16)*-1mod10


int letter_check(char letter) {
  int exit_code = FAILURE;
  int spec_symbol[] = {40, 41, 42, 43, 45, 47, 94};
  int L_start = 65, L_end = 90;
  int l_start = 97, l_end = 122;
  if ((letter >= L_start && letter <= L_end) ||
      (letter >= l_start && letter <= l_end)) {
    exit_code = SUCCESS;
  } else {
    for (int i = 0; i < (int)(sizeof(spec_symbol)/4); i++) {
      if (letter == spec_symbol[i]) {
        exit_code = SUCCESS;
        break;
      }
    }
  }
  return exit_code;
}


int parser(stack_t *stack, char *string) {
  char *lexemes[] = LEXEME;
  // Сначала сбрасываем счётчик стека
  if (stack->size != 0)
    stack->size = 0;
  // Объявляем массив для извлечённой подстроки
  char sub_string[MAX_BUF] = {'\0'};
  size_t start = 0, i = 0;
  // Пока есть что парсить
  while (start < strlen(string)) {
    int push_res = FAILURE;
    // Если в текущей позиции в строкe буква или специальный символ
    if (!letter_check(string[start])) {
      // Копируем символ в sub_str
      sub_string[i] = string[start];
      // И проверяем sub_str со всеми элементами LEXEME
      for (int j = 0; j < (int)(sizeof(lexemes)/8); j++) {
        // Если соответствие найдено, заталкиваем слово в стек
        // и обнуляем подстроку cо счётчиком подстроки
        if (!strcmp(sub_string, lexemes[j])) {
          push(stack, sub_string);
          memset(sub_string, '\0', MAX_BUF);
          i = 0;
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
        // Если в текущей позиции цифра или точка, копируем значение в подстроку
        sub_string[i] = string[start];
        // Если следующий элемент string не цифра, заталкиваем подстроку в стек
        // И обнуляем подстроку с счётчиком подстроки
        if ((string[start + 1] < 48 || string[start + 1] > 57) && string[start + 1] != 46) {
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
      return FAILURE;
    }
  }
  return SUCCESS;; 
}
