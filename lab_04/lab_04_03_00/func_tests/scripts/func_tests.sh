#!/bin/bash

index_1=0
index_2=0
counter_pos=0
counter_neg=0
counter_pos_memory=0
total_pos_memory=0
counter_neg_memory=0
total_neg_memory=0

ls ../data > files.txt

while read -r line;do array_pos_in+=("$line"); done < <(grep "pos_[0][0-9]_in.txt" files.txt )
while read -r line;do array_pos_out+=("$line"); done < <(grep "pos_[0][0-9]_out.txt" files.txt)
while read -r line;do array_neg_in+=("$line"); done < <(grep "neg_[0][0-9]_in.txt" files.txt)
while read -r line;do array_args_pos+=("$line"); done < <(grep "pos_[0][0-9]_args.txt" files.txt)
while read -r line;do array_args_neg+=("$line"); done < <(grep "neg_[0][0-9])args.txt" files.txt)

while [ $index_1 -ne ${#array_pos_in[*]} ]; do
    ./pos_case.sh "../data/${array_pos_in[$index_1]}" "../data/${array_pos_out[$index_1]}" "${array_args_pos[$index_1]}" 
    return=$?
    if [ $return -eq 0 ]; then
        counter_pos=$((counter_pos+1))
        echo TEST: PASSED
    else
        echo TEST: FAILED
    fi
    index_1=$((index_1+1))
done

#while [ $index_2 -ne ${#array_neg_in[*]} ]; do
    #./neg_case.sh "../data/${array_neg_in[$index_2]}" "${array_args_neg[$index_2]}"
    #return=$?
    #if [ $return -eq 0 ]; then
        #counter_neg=$((counter_neg+1))
        #echo TEST: PASSED
    #else
        #echo TEST: FAILED
   #fi
   #index_2=$((index_2+1))
#done

if [ -v USE_VALGRIND ]; then
    index_1=0
    index_2=0
    while [ $index_1 -ne ${#array_pos_in[*]} ]; do
        ./pos_case.sh "../data/${array_pos_in[$index_1]}" "../data/${array_pos_out[$index_1]}" "${array_args_pos[$index_1]}"
        return=$?
        if [ $return -eq 2 ]; then
            total_pos_memory=$((total_pos_memory+1))
        else
            counter_pos_memory=$((counter_pos_memory+1))
            total_pos_memory=$((total_pos_memory+1))
        fi
        index_1=$((index_1+1))
    done

    while [ $index_2 -ne ${#array_neg_in[*]} ]; do
        ./neg_case.sh "../data/${array_neg_in[$index_2]}" "${array_args_neg[$index_2]}"
        return=$?
        if [ $return -eq 2 ]; then
            total_neg_memory=$((total_neg_memory+1))
        else
            counter_neg_memory=$((counter_neg_memory+1))
            total_neg_memory=$((total_neg_memory+1))
        fi
        index_2=$((index_2+1))
    done
    
    echo "Positive tests: correct $counter_pos of ${#array_pos_in[*]}; memory passed $counter_pos_memory of $total_pos_memory"
    echo "Negative tests: correct $counter_neg" of "${#array_neg_in[*]}; memory passed $counter_neg_memory of $total_neg_memory"
else
    echo "Positive tests: correct $counter_pos of ${#array_pos_in[*]}"
    echo "Negative tests: correct $counter_neg" of "${#array_neg_in[*]}"
fi

