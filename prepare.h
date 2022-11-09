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
  int size;
} stack_t;

char *input_text(char *a);
char **mem_alloc(void);
int init_stack(stack_t *stack);
void free_stack(stack_t *stack);
int push(stack_t *stack, char *value);
int pop(stack_t *stack, char *value);
char *simple_pars(const char *string, int *i);
void stack_output(stack_t *stack);
int parse_push(stack_t *stack, const char *string);
