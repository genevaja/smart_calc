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

void clean_var(char *data, double *value, int *keys) {
  memset(data, '\0', MAX_BUF);
  *value = 0.0;
  *keys = 0;
}

int push_math(math_fn *calif, int keys) {
  int exit_code = FAILURE;
  switch (keys) {
    case SUM: {
      char temp_data[MAX_BUF] = {'\0'}; double temp_value = 0.0; int temp_keys = 0;
      char temp_data2[MAX_BUF] = {'\0'}; double temp_value2 = 0.0; int temp_keys2 = 0; 
      pop(calif, temp_data, &temp_value, &temp_keys);
      pop(calif, temp_data2, &temp_value2, &temp_keys2);
      push(calif, "\0", temp_value + temp_value2, temp_keys);
      clean_var(temp_data, &temp_value, &temp_keys);
      clean_var(temp_data2, &temp_value2, &temp_keys2);
      exit_code = SUCCESS;
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


int push_tex(math_fn *texas, math_fn *calif, char *data, double value, int keys) {
  double temp_value = 0.0;
  int temp_keys = 0;
  if (texas->size == 0) {
    push(texas, data, value, keys);
    // printf("PUSH_TEX VALUE: %s\tKEYS: %d\n", data, keys);
  }
  else {
    while (priority(keys) <= priority(texas->stack[texas->size].keys)) {
      char temp_data[MAX_BUF] = {'\0'};
      pop(texas, temp_data, &temp_value, &temp_keys);
      push_math(calif, temp_keys);
      clean_var(temp_data, &temp_value, &temp_keys);
    }
    push(texas, data, value, keys);
  }
  return SUCCESS;
}


int sort_station(math_fn *stack) {
  printf("HERE\n");
  math_fn texas;
  math_fn calif;
  stack_init(&texas);
  stack_init(&calif);
  int queue = 0, breket_flag = OFF;
  char data[MAX_BUF] = {'\0'}; double value = 0.0; int keys = 0;
  printf("IN SORT_ST STACK SIZE: %d\n", stack->size);
  for (; queue < stack->size;) {
    // printf("HERE\n");
    fifo_out(&queue, stack, data, &value, &keys);
    switch (keys) {
      case NUMBER: {
        push(&calif, data, value, keys);
        printf("DATA: %s\tKEYS: %d\n", data, keys);
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
            push_math(&calif, keys);
            clean_var(data, &value, &keys);
          } else {
            free_stack(&calif);
            free_stack(&texas);
            return WRONG_EXPRESSION; 
          }
        }
        pop(&texas, data, &value, &keys);
        clean_var(data, &value, &keys);
        break;
      }
      default: {
        // printf("DEFAULT\n");
        push_tex(&texas, &calif, data, value, keys);
      }
    }
    // printf("TEXAS:\n");
    // output(&texas);
    // printf("CALIFORNIA:\n");
    // output(&calif);
  }
  while (texas.size > 0) {
    pop(&texas, data, &value, &keys);
    // printf("DATA: %s\tKEYS: %d\n", data, keys);
    push_math(&calif, keys);
    clean_var(data, &value, &keys);
  }
  if (calif.size > 1) {
    printf("Somewhere you are fucked\n");
    free_stack(&calif);
    free_stack(&texas);
    return FAILURE;
  }

  stack->size = calif.size;
  for (int i = 0; i < MAX_BUF; i++) {
    strcpy(stack->stack[i].data, calif.stack[i].data);
    stack->stack[i].value = calif.stack[i].value;
    stack->stack[i].keys = calif.stack[i].keys;
  }

  free_stack(&texas);
  free_stack(&calif);

  return SUCCESS;
}
