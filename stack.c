#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 1024
#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101
#define SUCCESS 0
#define FAILURE 1

typedef struct stack_tag {
  char **data;
  size_t size;
} stack_t;


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

void init_stack(stack_t *stack) {
  stack->size = 0;
  stack->data = mem_alloc();
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
  free(value);
  return SUCCESS;
}

char *simple_pars(char *string, int *i) {
  char *sub_str = (char*)malloc(MAX_BUF * sizeof(char));
  int j = 0;
  while (string[*i] != ' ' && string[*i] != '\0') {
    sub_str[j] = string[*i];
    j++;
    *i += 1;
  }
  return sub_str;
}


int main() {
  char string[MAX_BUF] = {'\0'};
  stack_t stack;
  init_stack(&stack);
  input_text(string);

  int counter = 0;
  while (counter < (int)strlen(string)) {
    push(&stack, simple_pars(string, &counter));
  }

  for (size_t i = 0; i < stack.size; i++) {
    printf("Sub_str: %s\n", stack.data[i]);
  }

  free_stack(&stack);
  return 0;
}
