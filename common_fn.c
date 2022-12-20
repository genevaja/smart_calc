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

int stack_init(math_fn *stack) {
  int exit_code = FAILURE;
  stack->size = 0;
  stack->stack = (my_stack_t*)malloc(MAX_BUF * sizeof(my_stack_t));
  if (stack->stack != NULL) {
    for (int i = 0; i < MAX_BUF; i++) {
      stack->stack[i].data = (char*)malloc(MAX_BUF * sizeof(char));
      memset(stack->stack[i].data, '\0', MAX_BUF);
      stack->stack[i].value = 0.0;
      stack->stack[i].keys = -1;
      if (!stack->stack[i].data)
        exit_code = FAILURE;
      else
        exit_code = SUCCESS;
    }
  }
  return exit_code;
}

void free_stack(math_fn *stack) {
  if (stack->stack) {
    for (int i = 0; i < MAX_BUF; i++) {
      if (stack->stack[i].data)
        free(stack->stack[i].data);
    }
    free(stack->stack);
  }
}

int push(math_fn *stack, char *data, double value, int keys) {
  if (stack->size >= MAX_BUF || data == NULL)
    return FAILURE;
  // memset(stack->stack[stack->size].data, '\0', MAX_BUF);
  strcpy(stack->stack[stack->size].data, data);
  // printf("VALUE: %.6f\n", value);
  stack->stack[stack->size].value = value;
  // printf("KEYS: %d\n", keys);
  stack->stack[stack->size].keys = keys;
  stack->size++;
  return SUCCESS;
}

int pop(math_fn *stack, char *data, double *value, int *keys) {
  stack->size--;
  if (stack->size >= 0) {
    strcpy(data, stack->stack[stack->size].data);
    *value = stack->stack[stack->size].value;
    *keys = stack->stack[stack->size].keys;
    return SUCCESS;
  }
  return FAILURE;
}

int fifo_out(int *queue, math_fn *stack, char *data, double *value, int *keys) {
  memset(data, '\0', MAX_BUF);
  if (*queue < stack->size) {
    strcpy(data, stack->stack[*queue].data);
    *value = stack->stack[*queue].value;
    *keys = stack->stack[*queue].keys;
    *queue += 1;
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

void stack_output(math_fn *stack) {
  char out[MAX_BUF] = {'\0'};
  double value = 0.0;
  int keys = 0;
  while ((stack->size - 1) >= 0) {
    pop(stack, out, &value, &keys);
    printf("%6s: %6s%8s: %10.6f%10s: %3d\n", "data", out, "value", value, "keys", keys);
    memset(out, '\0', MAX_BUF);
  }
}

void output(math_fn *stack) {
  for (int i = 0; i < stack->size; i++) {
    printf("%6s: %6s%8s: %10.6f%10s: %3d\n", "data", stack->stack[i].data, "value", stack->stack[i].value, "keys", stack->stack[i].keys);
    // memset(out, '\0', MAX_BUF);
  }
}
