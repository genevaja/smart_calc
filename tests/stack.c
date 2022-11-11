#include "../common_fn.h"

int main() {
  int exit_code = SUCCESS;
  // String for stdin
  char string[MAX_BUF] = {'\0'};
  // char *example = {"sin(90)/cos(180)*3.1423455*sqrt(16)*-1mod10"};
  char *example = {"sqrt(4)^2+(cos(x^2)*sin(21-7+-1))"};
  // char *example = {"sin(90)"};
  strcpy(string, example);
  // Read stdin
  // input_text(string);

  // Create and init stack 
  stack_t stack;
  if (!init_stack(&stack))
    // Parse and push to stack
    exit_code = parser(&stack, example);

  // Out LIFO
  stack_output(&stack);

  // Remove stack
  if (stack.data)
    free_stack(&stack);
  if (exit_code)
    printf("Error in function\n");
  return exit_code;
}
