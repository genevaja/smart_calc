#!/bin/bash

declare -a lexemes=( "log" "ln" "sin" "cos" "tan" "ctg" "acos" "asin" "atan" "actg" "/" \
    "*" "+" "-" "sqrt" "mod" "%" "^" "x" "y" "z" )


rand_num=0

# echo ${#lexemes[@]}
for i in {0..10}; do
    rand_num2=$(( $RANDOM % 20))
    for (( i=0; i < $rand_num2; i++))
    do
        rand_num=$(( $RANDOM % 20))
        printf "%s(%s)" ${lexemes[$rand_num]} "$(echo $(( RANDOM % 10)).$((RANDOM%999)))"
    done
    echo $rand_num
done
