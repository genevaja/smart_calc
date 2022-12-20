#ifndef SRC_COMMON_FN_H_
#define SRC_COMMON_FN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ON 1
#define OFF 0
#define MAX_BUF 1024
#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101
#define SUCCESS 0
#define FAILURE 1
#define WRONG_EXPRESSION 2
#define CALCULATION_ERROR 3
#define NOT_A_NUMBER 4
#define DIVISION_BY_ZERO 5
#define VAR_NOT_DEFINED 6
#define TOO_LONG 7
#define MATH_DOMAIN_ERROR 8
#define WRONG_EXPRESSION_PARSER 9

#define ERRORS {"", "Failure", "Wrong expression", "Calculation error",\
                "NaN", "float division by zero", "Variable isn't defined",\
                "math domain error", "math domain error",\
                "invalid syntax (<string>, line 1)"}



#define LEXEME {"log", "ln", "sin", "cos", "tan", "acos", "asin", "atan", \
                "(", ")", "/", "*", "+", "-", "sqrt", "mod", "%", "^", "x", "y", "z" }

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
  NUMBER, // 21
  VAR //22 variables
};


typedef struct stack_unit {
  char *data;
  double value;
  int keys;
} my_stack_t;

typedef struct stack_com {
  my_stack_t *stack;
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
void output(math_fn *stack);
int parse_push(math_fn *stack, const char *string);

// Приоритеты для лексем
int priority_op(int operation);

// Парсер математических выражений
int parser(math_fn *stack, char *string, char *x_var);

int sort_station(math_fn *stack);
int fifo_out(int *queue, math_fn *stack, char *data, double *value, int *keys);

int calc(char *expr, char *variables, double *result);

#endif
