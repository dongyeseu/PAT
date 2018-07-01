/*
时间：2018/6/23 18点00分
作者：楼浩然
题目：
1010 一元多项式求导 (25)（25 分）
设计函数求一元多项式的导数。（注：x^n^（n为整数）的一阶导数为n*x^n-1^。）

输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是0，但是表示为“0 0”。

输入样例：

3 4 -5 2 6 1 -2 0
输出样例：

12 3 -10 1 6 0
*/
#include <stdio.h>

int main(void)
{
    int index,coef,count = 0;
    int res[1000];
    int i=0;
    while(scanf("%d %d",&index,&coef)!=EOF && coef!=0)   //记住这种输入方式
    {
        if(coef)
        {
            res[i] = coef*index;
            res[i+1] = coef - 1;
            i+=2;
            //printf("%d %d%c",index*coef,coef-1,coef?' ':'\n');   //从右向左执行
            count++;
        }
    }
    int j;
    if(count==0)
        printf("0 0\n");
    else
    {
        for(j=0 ; j<i ; j++)
            printf("%d%c",res[j],j!=i-1?' ':'\n');
    }

    return 0;
}


/*  别人写的，思路特别好，但是在PAT中格式通不过
#include <stdio.h>
int main()
{
    int coef, index, count = 0;

    while(scanf("%d %d", &coef, &index) != EOF) if(index)
    {   //constant terms results in zero term, so no output for index = 0
        printf("%c%d %d", count++ ? ' ' : '\0', coef * index, index - 1);
    }
    // zero polynomial or constant, the result is zero polynomial
    if(count == 0) puts("0 0");

    return 0;
}
*/
