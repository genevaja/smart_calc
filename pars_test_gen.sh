#!/bin/bash
if [ -f tests/parser_test.c ]; then
    echo "Files exist";
    exit 155;
fi

./math_fn.sh $1

rm tests/parser_test.c 2>/dev/null

test_file="parser_test.c"

qty_fn=$(wc -l fn.txt | awk '{printf $1}')

printf "#include \"../header.h\"\n" >> "$test_file"

if [[ $1 -eq 1 ]]; then
  stack_output="stack_output(&stack);"
else
  stack_outpu=""
fi


for (( i=1; i<=$qty_fn; i++)); do
string=$(head -$i fn.txt | tail +$i)
example=$(head -$i fn_str.txt | tail +$i)
    echo -e "
START_TEST(parser_$i) {
  int exit_code = SUCCESS;
  math_fn stack;
  stack_init(&stack);
  char *string[] = {$string};
  char *example = {\"$example\"};
  char *empty = \"0.362\";
  exit_code = parser(&stack, example, empty);
  ck_assert_int_eq(exit_code, 0);
  ck_assert((int)sizeof(string)/8 == stack.size);
  if (((int)sizeof(string)/8) == stack.size) {
    for (int i = 0; i < stack.size; i++) {
      ck_assert_int_eq(strcmp(string[i], stack.stack[i].data), 0);
    }
  }
  $stack_output
  free_stack(&stack);
}
END_TEST" >> "$test_file"
done

echo "
Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_parser;

    s = suite_create(\"parser\");

    tc_parser = tcase_create(\"parser\");" >> "$test_file"

for (( i=1; i<=$qty_fn; i++)); do
    echo "    tcase_add_test(tc_parser, parser_$i);" >> "$test_file"
done

echo -e "
    suite_add_tcase(s, tc_parser);
    
    return s;
}" >> "$test_file"

echo "
int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;
    s = sprintf_test();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}" >> "$test_file"

# string=$(head -$number $current_path/result.txt | tail +$number)

if [ ! -d "tests" ]; then
  mkdir tests
fi
mv "$test_file" tests
