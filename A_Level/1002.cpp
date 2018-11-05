#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    float Poly[1024] = {0}; //定义多项式，下标表示系数，值表示指数
    int coef,K;  //定义系数及项
    float index;//定义指数
    for(int i=0 ; i<2 ; i++)
    {
        cin>>K;
        for(int j=0 ; j<K ; j++)
        {
            //scanf("%d%f",&coef,&index);
            cin>>coef>>index;
            Poly[coef] += index;
        }
    }
    int S = 0;
    for(int i=0 ; i<1024; i++)
    {
        if(abs(Poly[i] - 0.0) > 1e-32)
            S++;
    }
    cout<<S;
    for(int i=1024 ; i>=0 ; i--)
    {
        if(abs(Poly[i] - 0.0) > 1e-32)  //判断浮点数是否为0的方法；因为浮点数存储精度不够
        {
            printf(" %d %.1f",i,Poly[i]);  //格式化输出
        }
    }
    cout<<"\n";
    return 0;
}
