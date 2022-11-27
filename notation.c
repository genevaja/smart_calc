#include "common_fn.h"

int priority(int operation) {
  int priority = 0;
  if (operation == BRO || operation == BRC)
    priority = 1;
  else if (operation == SUM || operation == SUB)
    priority = 2;
  else if (operation == MUL || operation == DIV || operation == MOD)
    priority = 3;
  else if (operation == POW)
    priority = 4;
  else if (operation == SQRT || operation == COS || operation == SIN ||
           operation == TAN || operation == CTG || operation == LN ||
           operation == ACOS || operation == ASIN || operation == ATAN ||
           operation == LOG)
    priority = 5;
  else if (operation == PLUS || operation == MINUS) {
    // printf("Unaric operation\n");
    priority = 6;
  } else
    priority = -1;
  return priority;
}

int push_math(math_fn *calif, char *data, double value, int keys) {
  int exit_code = 0;
  switch (keys) {
    case SUM: {
      break;
    }
    case SUB: {
      break;
    }
    case MUL: {
      break;
    }
    case DIV: {
      break;
    }
    case MOD: {
      break;
                // Предусмотреть, чтобы числа были целые
    }
    case POW: {
      break;
    }
    case SQRT: {
      break;
    }
    case MINUS: {
      break;
    }
    case PLUS: {
      break;
    }
    case LOG: {
      break;
    }
    case LN: {
      break;
    }
    case SIN: {
      break;
    }
    case COS: {
      break;
    }
    case TAN: {
      break;
    }
    case CTG: {
      break;
    }
    case ACOS: {
      break;
    }
    case ASIN: {
      break;
    }
    case ATAN: {
      break;
    }
    case ACTG: {
      break;
    }
    default: {
    }

  }
  return exit_code;
}

void clean_var(char *data, double *value, int *keys) {
  memset(data, '\0', MAX_BUF);
  *value = 0.0;
  *keys = 0;
}

int push_tex(math_fn *texas, math_fn *calif, char *data, double value, int keys) {
  char temp_data[MAX_BUF] = {'\0'};
  double temp_value = 0.0;
  int temp_keys = 0;
    while (priority(keys) <= priority(texas->stack[texas->size].keys)) {
      pop(texas, temp_data, &temp_value, &temp_keys);
      push_math(calif, temp_data, temp_value, temp_keys);
      clean_var(temp_data, &temp_value, &temp_keys);
    }
    push(texas, data, value, keys);
  return SUCCESS;
}


math_fn *sort_station(math_fn *stack) {
  math_fn texas;
  math_fn calif;
  stack_init(&texas);
  stack_init(&calif);
  int queue = 0, breket_flag = OFF;
  char data[MAX_BUF] = {'\0'}; double value = 0.0; int keys = 0;
  for (; queue < stack->size;) {
    fifo_out(&queue, stack, data, &value, &keys);
    switch (keys) {
      case NUMBER: {
        push(&calif, data, value, keys);
        clean_var(data, &value, &keys);
        break;
      }
      case BRO: {
        push(&texas, data, value, keys);
        clean_var(data, &value, &keys);
        breket_flag = ON;
        break;
      }
      case BRC: {
        while (texas.stack[stack->size].keys != BRO) {
          if (texas.size > 0 && breket_flag == ON) {
            pop(&texas, data, &value, &keys);
            push_math(&calif, data, value, keys);
            clean_var(data, &value, &keys);
          } else {
            return WRONG_EXPRESSION; 
          }
        }
        pop(&texas, data, &value, &keys);
        clean_var(data, &value, &keys);
        break;
      }
      default: {
        push_tex(&texas, &calif, data, value, keys);
      }
    }
  }
  while (texas.size > 0) {
    pop(&texas, data, &value, &keys);
    push_math(&calif, data, value, keys);
    clean_var(data, &value, &keys);
  }
  if (calif.size > 1) {
    printf("Somewhere you are fucked\n");
    return FAILURE;
  }

  stack->size = calif.size;
  for (int i = 0; i < MAX_BUF; i++) {
    stack->stack[i].data = calif.stack[i].data;
    stack->stack[i].value = calif.stack[i].value;
    stack->stack[i].keys = calif.stack[i].keys;
  }

  free_stack(&texas);
  free_stack(&calif);

  return stack;
}
