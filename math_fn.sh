#!/bin/bash


declare -a trig_fn=( "log" "ln" "sin" "cos" "tan" "ctg" "acos" "asin" "atan" "actg" "sqrt" )

declare -a math_fn=( "*" "-" "+" "/" "^" )


declare -a rand_fn=( "trig_fn" "math_fn" "variables" )



for lines in {1..100}; do
    done_expr=""
    # Поменял на время 20 на 10
    memb_of_expr=$(( $RANDOM % 20 + 1))
    for (( j=0; j<$memb_of_expr; j++ )); do
        rand_float="$(echo $(( $RANDOM % 10 )).$(( $RANDOM % 999 )))"
        rand_float2="$(echo $(( $RANDOM % 10 )).$(( $RANDOM % 999 )))"
        rand_int="$(echo $(( $RANDOM % 2000)))"
        rand_int2="$(echo $(( $RANDOM % 1000)))"
        declare -a variables=( "$rand_float" "x" "$rand_float2" )
        if [[ $memb_of_expr -eq 1 ]]; then 
            done_expr=$(printf "\"%s\", \"(\", \"%s\", \")\"" "${trig_fn[$RANDOM % ${#trig_fn[@]}]}" "$rand_float")
        elif [[ $memb_of_expr -eq 3 ]]; then
            done_expr=$(printf "\"%s\", \"%s\", \"%s\"" $rand_int "%" $rand_int2)
            break
        else
            if [[ $(($j % 2)) -eq 0 ]]; then
                done_expr=$(printf "\"%s\", \"(\", \"%s\", \")\", " "${trig_fn[$RANDOM % ${#trig_fn[@]}]}" "$rand_float")
            elif [[ $(($j % 4)) -eq 3 ]]; then
                done_expr=$done_expr$(printf "\"%s\", \"%s\", \"(\", \"(\", \"%s\", \"%s\", \"%s\", \")\", `
                                             `\"%s\", \"(\", \"%s\", \"%s\", \"%s\", \")\", \")\", " `
                `"${math_fn[$RANDOM % ${#math_fn[@]}]}" `
                `"${trig_fn[$RANDOM % ${#trig_fn[@]}]}" `
                `"$rand_float" `
                `"${math_fn[$RANDOM % ${#math_fn[@]}]}" `
                `"$rand_float" `
                `"${math_fn[$RANDOM % ${#math_fn[@]}]}" `
                `"${variables[$RANDOM % ${#variables[@]}]}" `
                `"${math_fn[$RANDOM % ${#math_fn[@]}]}" `
                `"$rand_float")
                # "${math_fn[$RANDOM % ${#math_fn[@]}]}" 
            else
                done_expr=$done_expr$(printf "\"%s\", " "${math_fn[$RANDOM % ${#math_fn[@]}]}")
                if [[ $(($j + 1)) -eq $memb_of_expr ]]; then
                    done_expr=$done_expr$(printf "\"%s\"" $rand_float)
                fi
            fi
        fi 
    done
    echo "$done_expr" | sed 's/ $//' | sed 's/,$//' >> fn.txt
    echo "$done_expr" | tr -d , | tr -d \" | tr -d ' ' >> fn_str.txt
done
