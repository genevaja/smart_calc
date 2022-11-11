#include "common_fn.h"

char *input_text(char *a) {
  char c;
  int i = 0;
  while ((c = getchar()) != EOF && c != '\n') {
    if (i < MAX_BUF) {
      a[i] = c;
      i++;
    }
  }
  return a;
}

char **mem_alloc(void) {
  char **result = (char**)malloc(MAX_BUF * sizeof(char*));
  for (int i = 0; i < MAX_BUF; i++) {
    result[i] = (char*)malloc(MAX_BUF * sizeof(char));
    for (int j = 0; j < MAX_BUF; j++)
      result[i][j] = '\0';
  }
  return result;
}

int init_stack(stack_t *stack) {
  stack->size = 0;
  stack->data = mem_alloc();
  return (stack->data) ? SUCCESS : FAILURE;
}

void free_stack(stack_t *stack) {
  if (stack->data) {
    for (int i = 0; i < MAX_BUF; i++)
      free(stack->data[i]);
    free(stack->data);
  }
}

int push(stack_t *stack, char *value) {
  if (stack->size >= MAX_BUF || value == NULL)
    return FAILURE;
  strcpy(stack->data[stack->size], value);
  stack->size++;
  return SUCCESS;
}

int pop(stack_t *stack, char *value) {
  stack->size--;
  if (stack->size >= 0) {
    strcpy(value, stack->data[stack->size]);
    return SUCCESS;
  }
  return FAILURE;
}

// Простой парсер только через пробелы
char *simple_pars(const char *string, int *i) {
  char *sub_str = (char*)malloc(MAX_BUF * sizeof(char));
  memset(sub_str, '\0', MAX_BUF);

  char temp[MAX_BUF] = {'\0'};
  int j = 0;
  while (string[*i] != ' ' && string[*i] != '\0' && string[*i] != '\n') {
    temp[j] = string[*i];
    *i += 1; j++;
  }
  *i += 1;
  strcpy(sub_str, temp);
  return sub_str;
}

void stack_output(stack_t *stack) {
  char out[MAX_BUF] = {'\0'};
  int i = 0;
  while ((stack->size - 1) >= 0) {
    pop(stack, out);
    printf("%s ", out);
    memset(out, '\0', MAX_BUF);
    i++;
  }
  putchar('\n');
}
