#! /bin/bash

touch 2053300-hw1-q2.log

num=20

for((i=0;i<num;i++))
do
    uptime >> 2053300-hw1-q2.log
    sleep 10
done
