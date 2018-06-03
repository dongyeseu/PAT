/*
时间：2018/6/3 22点16分
作者：少年人
功能：根据卡拉兹猜想，对给定的任一不超过1000的正整数n，简单地数一下，需要多少步（砍几下）才能得到n=1
*/

#include <stdio.h>

int Callatz(int i){
    int n = 0;
    while (i!=1){
        if (i%2==0)
            i = i/2;
        else
            i = (3*i+1)/2;
        n++;
    }
    return n;
}

int main(void)
{
    int i;
    scanf("%d",&i);
    int n;
    n = Callatz(i);
    printf("%d",n);
    return 0;
}

/*
输出结果：
---------------------
输入值：
3
输出值：
5
--------------------
*/
