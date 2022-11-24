#ifndef SRC_COMMON_FN_H_
#define SRC_COMMON_FN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUF 1024
#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101
#define SUCCESS 0
#define FAILURE 1
#define WRONG_EXPRESSION 2



#define LEXEME {"log", "ln", "sin", "cos", "tan", "ctg", "acos", "asin", "atan", \
                "actg", "(", ")", "/", "*", "+", "-", "sqrt", "mod", "%", "^", "x", "y", "z" }

// MEM_ALLOC_FUNCTION(mem_alloc_char, char);

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
  ACTG, // 20
  NUMBER // 21
};


typedef struct stack_unit {
  char *data;
  double value;
  int keys;
} stack_t;

typedef struct stack_com {
  stack_t *stack;
  int size;
} math_fn;

char *input_text(char *a);
char **mem_alloc(void);


int stack_init(math_fn *stack);
void free_stack(math_fn *stack);
int push(math_fn *stack, char *data, double value, int keys);
int pop(math_fn *stack, char *data, double *value, int *keys);
// int pop(math_fn *stack, char *data, double value, int keys);
char *simple_pars(const char *string, int *i);
void stack_output(math_fn *stack);
int parse_push(math_fn *stack, const char *string);

// Приоритеты для лексем
int priority_op(int operation);

// Парсер математических выражений
int parser(math_fn *stack, char *string);

int notation(math_fn *stack);

#endif
