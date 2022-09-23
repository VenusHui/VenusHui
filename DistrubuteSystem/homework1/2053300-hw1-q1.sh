#! /bin/bash

# 埃拉托色尼筛法 复杂度O(NlogN)

ans=0
n=100
for((i=0;i<=n;i++))
do
    array[$i]=1
done
array[0]=0
array[1]=0
for((i=2;$(expr $i \* $i)<n;i++))
do
    if [ ${array[$i]} == 1 ];
    then
        for((j=$(expr $i \* $i);j<=n;j=$(expr $j + $i)))
        do
            array[$j]=0
        done
    fi
done

for((i=0;i<n;i++))
do
    if [ ${array[$i]} == 1 ];
    then
        ans=$(expr $ans + $i)
    fi
done

echo $ans

