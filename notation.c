#include "common_fn.h"

int priority_op(int operation) {
  int priority = 0;
  if (operation == BRO || operation == BRC)
    priority = 1;
  else if (operation == SUM || operation == SUB)
    priority = 2;
  else if (operation == MUL || operation == DIV || operation == MOD)
    priority = 3;
  else if (operation == POW || operation == SQRT || operation == COS ||
           operation == SIN || operation == TAN || operation == CTG ||
           operation == LN || operation == ACOS || operation == ASIN ||
           operation == ATAN || operation == LOG)
    priority = 4;
  else if (operation == PLUS || operation == MINUS) {
    printf("Unaric operation\n");
    priority = 5;
  } else
      printf("Error in priority: %d\n", operation);
  return priority;
}

int notation(stack_t *stack) {

}
