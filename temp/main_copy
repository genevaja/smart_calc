#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE 1
#define MAX_BUF 1024

typedef struct stack_unit {
  char *data;
  double value;
  int keys;
} stack_t;

typedef struct stack_com {
  stack_t *stack;
  int size;
} math_fn;

int stack_init(math_fn *stack) {
  int exit_code = FAILURE;
  stack->size = 0;
  stack->stack = (stack_t*)malloc(MAX_BUF * sizeof(stack_t));
  if (stack->stack) {
    for (int i = 0; i < MAX_BUF; i++) {
      stack->stack[i].data = (char*)malloc(MAX_BUF * sizeof(char));
      stack->stack[i].value = 0.0;
      stack->stack[i].keys = 0;
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

int main() {
  int exit_code = SUCCESS;
  math_fn stack;
  exit_code = stack_init(&stack);
  free_stack(&stack);
  return exit_code;
}
