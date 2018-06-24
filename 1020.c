/*
时间：2018/6/24 08点26分
作者：楼浩然
题目：
1020 月饼 (25)（25 分）
月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。

注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有3种月饼，其库存量分别为18、15、10万吨，总售价分别为75、72、45亿元。如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部15万吨第2种月饼、以及5万吨第3种月饼，获得 72 + 45/2 = 94.5（亿元）。

输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、以及不超过500（以万吨为单位）的正整数D表示市场最大需求量。随后一行给出N个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。

输出格式：

对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。

输入样例：

3 20
18 15 10
75 72 45
输出样例：

94.50
*/

#include <stdio.h>
//妈蛋，为什么思路都是一样的，别人写的比我简单，能够通过，我要么运行超时要么答案错误
int main(void)
{
    int N,P; //N代表月饼种类数，P代表市场最大需求量
    scanf("%d %d",&N,&P);
    float n[N];//代表每种月饼的库存量
    float p[N];//代表每种月饼的总售价
    double dan_jia[N];//分别代表每种月饼的单价
//    int xu_qiu[N];//分别代表每种月饼的需求量
    int i,j;//循环计数
    double res=0;//最大售价期望值
    for(i=0 ; i<N ; i++)
        scanf("%f",&n[i]);
    for(i=0 ; i<N ; i++)
    {
        scanf("%f",&p[i]);
    }

    for(i=0 ; i<N ; i++)
        dan_jia[i] = p[i]*1.0/n[i];
//    int sorting[N];//存储单价从高到低的下标值
    float change = 1;
    double t;
    /*  选择排序法还是太慢了
    for(i=0 ; i<N-1 ; i++)
    {
        for(j=i+1; j<N ;j++)
        {
            if(dan_jia[j]>dan_jia[i])
            {
                change = n[i];
                n[i] = n[j];
                n[j] = change;
                t = dan_jia[i];
                dan_jia[i] = dan_jia[j];
                dan_jia[j] = t;
            }
        }
    }
    */
    int flag = 1;
    for(i=N-1;i>=1&&flag==1;i--)
    {
        flag = 0;
        for(j=0 ; j<N-1 ; j++)
        {
            if(dan_jia[j+1]>dan_jia[j]);
            {
                flag = 1;
                change = n[j+1];
                n[j+1] = n[j];
                n[j] = change;
                t = dan_jia[j+1];
                dan_jia[j+1] = dan_jia[j];
                dan_jia[j] = t;
            }
        }
    }

//    for(i=0 ; i<N ; i++)
//        printf("%d %f\n",n[i],dan_jia[i]);
    i = 0;
    while(P!=0)
    {

        if(n[i] < P)
        {
            res += n[i]*dan_jia[i];
 //           printf("%.2f",n[i]*1.0*dan_jia[i]);
            P -= n[i];
            i++;
        }
        else if (P>0)
        {
 //           printf("%d %f\n",n[i],dan_jia[i]);
            res += P*dan_jia[i];
//            printf("%.2f",P*dan_jia[i]);
//            printf("%f",res);
            P = 0;
        }

    }
    printf("%.2lf",res);
    return 0;
}

/*
反省：
1）合理考虑精度问题
2）合理使用排序算法
*/

/*  结构体思路
#include <stdio.h>
struct cake{
    double kucun;
    double price;
    double danjia;
}cake[1001];
int main()
{
    int n,d,i,j;
    struct cake temp;
    double tprice=0.0;
    scanf("%d %d",&n,&d);
    for(i=0;i<n;i++)
    {
        scanf("%lf",&cake[i].kucun);
    }
    for(i=0;i<n;i++)
    {
        scanf("%lf",&cake[i].price);
        cake[i].danjia=cake[i].price/cake[i].kucun;
    }
    for(i=0;i<n-1;i++)//将结构体按单价大小排序
    {
        for(j=i+1;j<n;j++)
        {
            if(cake[i].danjia<cake[j].danjia)
            {
                temp=cake[i];
                cake[i]=cake[j];
                cake[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(cake[i].kucun<d)
        {
            tprice+=cake[i].price;
            d=d-cake[i].kucun;
        }else if(d>0)
        {
            tprice=tprice+d*cake[i].danjia;
            d=0;
            break;
        }
    }
    printf("%.2lf\n",tprice);
    return 0;
}
*/

/*  寻找最大值，用完后赋值0
#include <stdio.h>
int main()
{
    int N, max;
    float D, Storage[1000], Total = 0, Price[1000];
    scanf("%d %f", &N, &D);
    for(int i = 0; i < N; i++) scanf("%f", Storage + i);
    for(int i = 0; i < N; i++) scanf("%f", Price + i);

    while(D > 0)
    {
        max = 0;
        for(int i = 0; i < N; i++)
            if(Price[i] / Storage[i] > Price[max] / Storage[max])
                max = i;

        if(Storage[max] < D)
        {
            Total += Price[max];
            D -= Storage[max];
            Price[max] = 0;
        }
        else
        {
            Total += Price[max] * D / Storage[max];
            D = 0;
        }
    }
    printf("%.2f", Total);

    return 0;
}
*/
