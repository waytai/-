/*************************************************************************
    > File Name: palindrome_number.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月21日 星期二 14时44分32秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    int num = 34543;
    int compare = num;
    int tmp = 0, des=0;
    while(num)
    {
        tmp = num%10;
        num = num/10;
        des = des*10 + tmp;
    }
    printf("%d\n", des);
    printf("%d\n", compare);
    printf("num is %d\n", num);
    if(des == compare)
    {
        printf("num is palindrome number\n");
    }

    return 0;
}
