#!/bin/bash


declare -a trig_fn=( "log" "ln" "sin" "cos" "tan" "ctg" "acos" "asin" "atan" "actg" "sqrt" )

declare -a math_fn=( "*" "-" "+" "/" "^")

declare -a variables=( "x" "y" "z" "$rand_float" )

declare -a rand_fn=( "trig_fn" "math_fn" "variables" )


for lines in {0..100}; do
    memb_of_expr=$(( $RANDOM % 20 + 1))
    for (( j=0; j<$memb_of_expr; j++ )); do
    rand_float="$(echo $(( $RANDOM % 10 )).$(( $RANDOM % 999 )))"
    rand_int="$(echo $(( $RANDOM % 2000)))"
        if [[ $memb_of_expr -eq 1 ]]; then 
            printf "%s(%s)" "${trig_fn[$RANDOM % ${#trig_fn[@]}]}" "$rand_float"
        elif [[ $memb_of_expr -eq 3 ]]; then
            printf "%s%s%s" $rand_int "%" $rand_int
            break
        else
            if [[ $(($j % 2)) -eq 0 ]]; then
                printf "%s(%s)" "${trig_fn[$RANDOM % ${#trig_fn[@]}]}" "$rand_float"
            elif [[ $(($j % 4)) -eq 3 ]]; then
                printf "%s((%s %s %s)%s(%s%s%s))" "${trig_fn[$RANDOM % ${#trig_fn[@]}]}" "$rand_float" "${math_fn[$RANDOM % ${#math_fn[@]}]}" "$rand_float" "${math_fn[$RANDOM % ${#math_fn[@]}]}" "${variables[$RANDOM % ${#variables[@]}]}" "${math_fn[$RANDOM % ${#math_fn[@]}]}" "$rand_float"
            else
                printf "%s" "${math_fn[$RANDOM % ${#math_fn[@]}]}"
                if [[ $(($j + 1)) -eq $memb_of_expr ]]; then
                    printf "%s" $rand_float
                fi
            fi
        fi 
    done
    echo
done
