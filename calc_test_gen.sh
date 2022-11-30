#!/bin/bash


if [[ $2 =~ "on" ]]; then
    rm tests/calc_test.c 2>/dev/null
fi

if [ -f tests/calc_test.c ]; then
    echo "Files exist";
    exit 155;
fi


./math_fn.sh $1 $2

test_file="calc_test.c"

qty_fn=$(wc -l fn_str.txt | awk '{printf $1}')

printf "#include \"../header.h\"\n" >> "$test_file"


for (( i=1; i<=$qty_fn; i++)); do
    py_string=$(head -$i fn_str.txt | tail +$i  | sed -e 's/log/log10/g' |
             sed -e 's/ln/log1p/g' | sed -e 's/\^/\*\*/g' | sed -e 's/x/0.1522/g' )
    example=$(head -$i fn_str.txt | tail +$i)
    python_res=$(python3 main.py "$py_string")
    if [[ $python_res == "unexpected EOF while parsing (<string>, line 1)" ]]; then
        python_res=$(echo $python_res | sed -e 's/unexpected EOF while parsing (<string>, line 1)/Wrong expression/g')
    elif [[ $(expr length "$python_res") -gt 30 ]]; then
        python_res="Unexpected result"
    fi
    if [[ "$python_res" =~ ^[-]{1}[0-9]*[.,]?[0-9]+$ ]]; then
        python_res=$(echo ${python_res:0:10})
    fi
    if [[ "$python_res" =~ ^[0-9]*[.,]?[0-9]+$ ]]; then
        python_res=$(echo ${python_res:0:9})
    fi
    # echo $py_string $python_res



    echo  "
START_TEST(calc_$i) {
  int exit_code = FAILURE;
  math_fn stack;
  stack_init(&stack);
  char *expression = {\"$example\"};
  char *py_result = {\"$(echo $python_res)\"};
  char *x_var = {\"0.1522\"};
  exit_code = parser(&stack, expression, x_var);
  char exit_msg[50] = {"\'"\0"\'"}; 
  if (exit_code > 0) {
    char *error[] = ERRORS;
    sprintf(exit_msg, \"%s\", error[exit_code]);
    ck_assert_str_eq(exit_msg, py_result);
  } else {
      char my_result[50] = {"\'"\0"\'"};
      double result = 0.0;
      exit_code = calc(expression, x_var, &result);
      if (exit_code > 0) {
        char *error[] = ERRORS;
        sprintf(exit_msg, \"%s\", error[exit_code]);
        ck_assert_str_eq(exit_msg, py_result);
      } else {
          sprintf(my_result, \"%.7f\", stack.stack[0].value);
          ck_assert_str_eq_tol(my_result, py_result);
      }
  }

  free_stack(&stack);
}
END_TEST" >> "$test_file"
done

echo "
Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_calc;

    s = suite_create(\"calc\");

    tc_calc = tcase_create(\"calc\");" >> "$test_file"

for (( i=1; i<=$qty_fn; i++)); do
    echo "    tcase_add_test(tc_calc, calc_$i);" >> "$test_file"
done

echo -e "
    suite_add_tcase(s, tc_calc);
    
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

if [[ $3 =~ "show" ]]; then
    cat tests/calc_test.c
fi
