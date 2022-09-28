#! /bin/bash

fileName=$1

varl=$(wc -l $fileName)
varm=$(wc -m $fileName)

sumline=$(echo $varl | awk 'BEGIN{  } { print $1 } END{  }')
# echo $varl | awk 'BEGIN{  } { print $1 } END{  }'
# echo $varm | awk 'BEGIN{  } { print $1 } END{  }'

awk -v sumline="$sumline" 'BEGIN{
    sum=0
    load1=0
    load2=0
    load3=0
}
{
    sum += length($0)
    # 获取第一行与最后一行的时间戳
    if(NR==1){
        start_time=substr($1, 0, 2) * 3600 + substr($1, 4, 2) * 60 + substr($1, 7, 2)
    }
    else if(NR==sumline){
        end_time=substr($1, 0, 2) * 3600 + substr($1, 4, 2) * 60 + substr($1, 7, 2)
    }

    # 获取系统负载值
    load1+=$(NF-2)
    load2+=$(NF-1)
    load3+=$(NF)
}
END{
    print "文件总行数为："NR
    print "文件总字符数为："sum+NR
    during=end_time - start_time
    seconds=during % 60
    minutes=(during - seconds) / 60
    print "第一行与最后一行输出结果的时间差为："minutes" 分钟 "seconds" 秒"
    printf("过去1、5、15分钟内系统的负载均值为：%.2f %.2f %.2f\n", load1/sumline, load2/sumline, load3/sumline)
}' $fileName

