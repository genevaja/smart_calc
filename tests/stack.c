#include "../prepare.h"

int main() {
  int exit_code = SUCCESS;
  // String for stdin
  char string[MAX_BUF] = {'\0'};

  // Read stdin
  input_text(string);

  // Create and init stack 
  stack_t stack;
  if (!init_stack(&stack))
    // Parse and push to stack
    exit_code = parse_push(&stack, string);

  // Out LIFO
  stack_output(&stack);

  // Remove stack
  if (stack.data)
    free_stack(&stack);
  return exit_code;
}
