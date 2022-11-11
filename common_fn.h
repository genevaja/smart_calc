#ifndef SRC_COMMON_FN_H_
#define SRC_COMMON_FN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 1024
#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101
#define SUCCESS 0
#define FAILURE 1
#define WRONG_EXPRESSION 2

#define LEXEME {"log", "ln", "sin", "cos", "tan", "ctg", "acos", "asin", "atan", \
                "actg", "(", ")", "/", "*", "+", "-", "sqrt", "mod", "%", "^", "x", "y", "z" }

enum operations {
  SUM = 0,
  SUB, // binary minus 1
  MUL, // 2
  DIV, // 3
  MOD, // 4
  POW, // 5
  SQRT, // 6
  BRO, // 7
  BRC, // 8
  MINUS, // undefined minus // 9
  PLUS, // unary plus 10
  LOG, // 11
  LN, // 12
  SIN, // 13
  COS, // 14
  TAN, // 15
  CTG, // 16
  ACOS, // 17
  ASIN, // 18
  ATAN, // 19
  ACTG // 20
};


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

// Приоритеты для лексем
int priority_op(int operation);

int parser(stack_t *stack, char *string);

#endif
