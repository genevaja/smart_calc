#include "common_fn.h"

#define POP_UNARY \
      char temp_data[MAX_BUF] = {'\0'}; double temp_value = 0.0; int temp_keys = 0;\
      pop(calif, temp_data, &temp_value, &temp_keys);\

#define POP_BINARY \
      char temp_data[MAX_BUF] = {'\0'}; double temp_value = 0.0; int temp_keys = 0;\
      char temp_data2[MAX_BUF] = {'\0'}; double temp_value2 = 0.0; int temp_keys2 = 0;\
      pop(calif, temp_data2, &temp_value2, &temp_keys2);\
      pop(calif, temp_data, &temp_value, &temp_keys);\

#define SUM_SUB(SIGN) \
      POP_BINARY;\
      push(calif, "\0", temp_value SIGN temp_value2, temp_keys);\
      clean_var(temp_data, &temp_value, &temp_keys);\
      clean_var(temp_data2, &temp_value2, &temp_keys2);\
      exit_code = SUCCESS;\


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
      SUM_SUB(+);
      break;
    }
    case SUB: {
      SUM_SUB(-);
      break;
    }
    case MUL: {
      SUM_SUB(*);
      break;
    }
    case DIV: {
      POP_BINARY;
      if (temp_value2 != 0) {
        push(calif, "\0", temp_value / temp_value2, temp_keys);
        exit_code = SUCCESS;
      } else
        return DIVISION_BY_ZERO;
        // exit_code = DIVISION_BY_ZERO;
      // SUM_SUB(/);
      clean_var(temp_data, &temp_value, &temp_keys);
      clean_var(temp_data2, &temp_value2, &temp_keys2);
      break;
    }
    case MOD: {
      POP_BINARY;
      double fmod_result = fmod(temp_value, temp_value2);
      if (!__builtin_isnan(fmod_result)) {
        push(calif, "\0", fmod(temp_value, temp_value2), temp_keys);
        exit_code = SUCCESS;
      } else
          return NOT_A_NUMBER;
      clean_var(temp_data, &temp_value, &temp_keys);\
      clean_var(temp_data2, &temp_value2, &temp_keys2);\
      break;
    }
    case POW: {
      POP_BINARY;
      push(calif, "\0", pow(temp_value, temp_value2), temp_keys);
      exit_code = SUCCESS;
      break;
    }
    case SQRT: {
      POP_UNARY;
      push(calif, "\0", sqrt(temp_value), temp_keys);
      exit_code = SUCCESS;
      break;
    }
    case MINUS: {
      POP_UNARY;
      push(calif, "\0", temp_value * -1, temp_keys);
      exit_code = SUCCESS;
      break;
    }
    case PLUS: {
      POP_UNARY;
      push(calif, "\0", fabs(temp_value), temp_keys);
      exit_code = SUCCESS;
      break;
    }
    case LOG: {
      POP_UNARY;
      push(calif, "\0", log10(temp_value), temp_keys);
      exit_code = SUCCESS;
      break;
    }
    case LN: {
      POP_UNARY;
      push(calif, "\0", log(temp_value), temp_keys);
      exit_code = SUCCESS;
      break;
    }
    case SIN: {
      POP_UNARY;
      push(calif, "\0", sin(temp_value), temp_keys);
      exit_code = SUCCESS;
      break;
    }
    case COS: {
      POP_UNARY;
      push(calif, "\0", cos(temp_value), temp_keys);
      exit_code = SUCCESS;
      break;
    }
    case TAN: {
      POP_UNARY;
      push(calif, "\0", tan(temp_value), temp_keys);
      exit_code = SUCCESS;
      break;
    }
    case CTG: {
      POP_UNARY;
      double cos_value = cos(temp_value);
      double sin_value = sin(temp_value);
      if (fabs(sin_value) != 0) {
        push(calif, "\0", cos_value / sin_value, temp_keys);
        exit_code = SUCCESS;
      } else
        return CALCULATION_ERROR;
      break;
    }
    case ACOS: {
      POP_UNARY;
      push(calif, "\0", acos(temp_value), temp_keys);
      exit_code = SUCCESS;
      break;
    }
    case ASIN: {
      POP_UNARY;
      push(calif, "\0", asin(temp_value), temp_keys);
      exit_code = SUCCESS;
      break;
    }
    case ATAN: {
      POP_UNARY;
      push(calif, "\0", atan(temp_value), temp_keys);
      exit_code = SUCCESS;
      break;
    }
    case ACTG: {
      POP_UNARY;
      if (fabs(temp_value) != 0) {
        push(calif, "\0", atan(1/temp_value), temp_keys);
        exit_code = SUCCESS;
      } else
        return CALCULATION_ERROR;
      break;
    }
    default: {
    }

  }
  return exit_code;
}


int push_tex(math_fn *texas, math_fn *calif, char *data, double value, int keys) {
  int exit_code = WRONG_EXPRESSION;
  double temp_value = 0.0;
  int temp_keys = 0;
  if (texas->size == 0) {
    push(texas, data, value, keys);
  }
  else {
    while (priority(keys) <= priority(texas->stack[texas->size - 1].keys) && texas->size > 0) {
      char temp_data[MAX_BUF] = {'\0'};
      pop(texas, temp_data, &temp_value, &temp_keys);
      if((exit_code = push_math(calif, temp_keys)) > 0) {
        return exit_code;
      }
      clean_var(temp_data, &temp_value, &temp_keys);
    }
    push(texas, data, value, keys);
  }
  return exit_code;
}


int sort_station(math_fn *stack) {
  int exit_code = WRONG_EXPRESSION;
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
        while (texas.stack[texas.size - 1].keys != BRO) {
          if (texas.size > 0 && breket_flag == ON) {
            pop(&texas, data, &value, &keys);
            if ((exit_code = push_math(&calif, keys)) > 0) {
              break;
            }
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
        push_tex(&texas, &calif, data, value, keys);
      }
    }
  }
  while (texas.size > 0) {
    pop(&texas, data, &value, &keys);
    if((exit_code = push_math(&calif, keys)) > 0) {
      break;
    }
    clean_var(data, &value, &keys);
  }
  if (calif.size > 1) {
    exit_code = WRONG_EXPRESSION;
  }

  if (!exit_code) {
    stack->size = calif.size;
    for (int i = 0; i < MAX_BUF; i++) {
      strcpy(stack->stack[i].data, calif.stack[i].data);
      stack->stack[i].value = calif.stack[i].value;
      stack->stack[i].keys = calif.stack[i].keys;
    }
  }

  free_stack(&texas);
  free_stack(&calif);

  return exit_code;
}
