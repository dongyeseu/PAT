/*
时间：2018/6/25 19点28分
作者：楼浩然
题目：
1054 求平均值 (20)（20 分）
本题的基本要求非常简单：给定N个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。一个“合法”的输入是[-1000，1000]区间内的实数，并且最多精确到小数点后2位。当你计算平均值的时候，不能把那些非法的数据算在内。

输入格式：

输入第一行给出正整数N（<=100）。随后一行给出N个实数，数字间以一个空格分隔。

输出格式：

对每个非法输入，在一行中输出“ERROR: X is not a legal number”，其中X是输入。最后在一行中输出结果：“The average of K numbers is Y”，其中K是合法输入的个数，Y是它们的平均值，精确到小数点后2位。如果平均值无法计算，则用“Undefined”替换Y。如果K为1，则输出“The average of 1 number is Y”。

输入样例1：

7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
输出样例1：

ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
输入样例2：

2
aaa -9999
输出样例2：

ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
*/
#include<stdio.h>
#include<stdlib.h>
int legal(char a[]){
    int dot = 0, i = 0, n1 = 0, n2 = 0;
    if(a[0]=='-') i=1;//跳过逗号计算数值
    for(;a[i]!='\0';i++){//下面四句判断的顺序不能改变！！！
        if((a[i]<48||a[i]>57)&&a[i]!='.') return 0;
        if(dot==1&&a[i]=='.') return 0;
        if(dot>0) n1++;
        if(a[i]=='.') dot=1;
    }
    if (n1 > 2) return 0;
    if (atof(a) < -1000.0 || atof(a) > 1000.0) return 0;

    return 1;
}
int main(){
    int N,c=0,i;
    char select[101]={0};
    double sum=0.0f,ev;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%s",select);
        if(legal(select)){
            sum+=atof(select);    //关键在于atof函数能够将字符串数组直接转化为数字
            c++;
        }else
            printf("ERROR: %s is not a legal number\n",select);
    }
    ev=sum/c;
    printf("The average of %d",c);
    if(c==0) printf(" numbers is Undefined");
    if(c==1) printf(" number is %.2lf",ev);
    if(c>=2) printf(" numbers is %.2lf",ev);
    return 0;
}


/*  有两个测试点没有通过
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
float IsNum(char * n)
{
    int len = strlen(n);
    int i;
    int num_dot = 0;
    int fuhao_weizhi = -1;
    int fuhao_num = 0;
    float res_zhengshu = 0.0;
    float res_fushu = 0.0;
    float res;
    int z = 1;//复数楚的10的倍数
    int flag = 1;
    for(i = 0 ; i<len ; i++)
    {
        if(n[i]=='.' ||n[i]=='-'||(n[i]>='0'&&n[i]<='9'))
        {
            if(n[i]=='.')
            {
                num_dot += 1;
                flag = 0;
            }

            else if (n[i] == '-')
            {
                fuhao_num++;
                fuhao_weizhi = i;
            }
            else
            {
                if(flag)
                    res_zhengshu = res_zhengshu*10 + (n[i]-'0');
                else
                {
                    res_fushu = res_fushu+(n[i]-'0')/pow(10,z);
                    z++;
                    if(z>3)
                    return 0;
                }
            }

        }
        else
            return 0;
    }

    res = res_zhengshu + res_fushu;
 //   printf("%.2f + %.2f = %.2f\n",res_zhengshu,res_fushu,res);
    if(num_dot>1)
        return 0;
    else if(fuhao_weizhi == 0 && fuhao_num == 1)
        return res*(-1);
    else
        return res;

}

int main(void)
{
    int N;//输入数量
    scanf("%d",&N);
    while(getchar()!='\n')
        continue;
    char ex[N][100];
    char ch;
    int i = 0;
    int j = 0;
    while((ch = getchar())&&ch!='\n')
    {
        if(ch==' ')
        {
            ex[i][j] = '\0';
            i++;
            j=0;
            continue;
        }
        else
        {
            ex[i][j] = ch;
            j++;
        }
    }
    ex[i][j]='\0';
    float sum = 0.0;
    int num_sum = 0;
    for(i=0 ; i<N ; i++)
    {
        float r= IsNum(ex[i]);
        if(r<=1000 && r>=-1000 && r!=0)
        {
            sum+=r;
            num_sum+=1;
        }
        else
            printf("ERROR: %s is not a legal number\n",ex[i]);

 //       printf("sum = %.2f\n",sum);
  //      printf("%r =%.2f\n",r);
    }
    if(num_sum==0)
        printf("The average of 0 numbers is Undefined\n");
    else
        printf("The average of %d numbers is %.2f\n",num_sum,sum/(float)num_sum);
 //   printf("%d",num_sum);
  //  printf("%.2f",sum);
    return 0;
}

*/
