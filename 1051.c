/*
时间：2018/6/19 20点21分
作者：楼浩然
题目：
1051 复数乘法 (15)（15 分）
复数可以写成(A + Bi)的常规形式，其中A是实部，B是虚部，i是虚数单位，满足i^2^ = -1；也可以写成极坐标下的指数形式(R*e^(Pi)^)，其中R是复数模，P是辐角，i是虚数单位，其等价于三角形式 R(cos(P) + isin(P))。

现给定两个复数的R和P，要求输出两数乘积的常规形式。

输入格式：

输入在一行中依次给出两个复数的R1, P1, R2, P2，数字间以空格分隔。

输出格式：

在一行中按照“A+Bi”的格式输出两数乘积的常规形式，实部和虚部均保留2位小数。注意：如果B是负数，则应该写成“A-|B|i”的形式。

输入样例：

2.3 3.5 5.2 0.4
输出样例：

-8.68-8.23i
*/

//重点在于精度，float并不能很准确地存储数字，因此最好使用double类型

#include <stdio.h>
#include <math.h>

int main(void)
{
    double r1,p1,r2,p2;
    double a1,b1,a2,b2;
    scanf("%lf %lf %lf %lf",&r1,&p1,&r2,&p2);
    a1 = r1*(cos(p1));
    b1 = r1*(sin(p1));
    a2 = r2*(cos(p2));
    b2 = r2*(sin(p2));
    double f1,f2;
    f1 = a1*a2 - b1*b2;
    f2 = a1*b2 + a2*b1;
    if(f1<0 && f1>-0.005)f1=0;
    if(f2<0 && f2>-0.005)f2=0;
    if(f2 >= 0.0)
    {
        printf("%.2lf+%.2lfi",f1,f2);
    }
    else if(f2 < 0.0){
        printf("%.2lf-%.2lfi",f1,-f2);
    }
    return 0;
}
