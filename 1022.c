/*
时间：2018/6/15 10点29分
作者：楼浩然
题目：
1022 D进制的A+B (20)（20 分）
输入两个非负10进制整数A和B(<=2^30^-1)，输出A+B的D (1 < D <= 10)进制数。
输入格式：
输入在一行中依次给出3个整数A、B和D。
输出格式：
输出A+B的D进制数。
输入样例：
123 456 8
输出样例：
1103
*/

#include <stdio.h>
void jin_zhi_zhuan_huan(int num, int d); //将数字num按照D进制输出
int main(void)
{
    int a,b,d;
    scanf("%d %d %d",&a,&b,&d);
    int num = a+b ;
    jin_zhi_zhuan_huan(num , d);
    return 0;

}
void jin_zhi_zhuan_huan(int num, int d)  //递归法
{
    if (num>=d)
        jin_zhi_zhuan_huan(num/d,d);
    printf("%d",num%d);
}
