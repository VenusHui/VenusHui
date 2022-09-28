#! /bin/bash

time=$1

for((i=0;i<time;i++))
do
    if [ $(expr $i % 10) == 0 ]
    then
        echo "还剩余 $(expr $time - $i) 秒"
    fi
    sleep 1
done
