/*
时间： 2018/6/14 23点43分
作者：楼浩然
题目：
1012 数字分类 (20)（20 分）
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。
输入格式：
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。
输格式：
对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
若其中某一类数字不存在，则在相应位置输出“N”。
输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：
30 11 2 9.7 9
输入样例2：
8 1 2 4 5 6 7 9 16
输出样例2：
N 11 2 N 9
*/

#include <stdio.h>
#include <string.h>


// 最后一个测试点一直过不去
int main(void)
{
    int num;
    scanf("%d",&num);
    int a[num];
    memset(a,5,sizeof(int)*num);
    int i;
    int r[5] = { 0 , 0 , 0 , 0 , 0};
    int flag0=0,flag1=0,flag3=0,flag2=0,flag4=0;  //判断条件的问题
    int flag = 1;
    int total = 0;
    for(i=0 ; i<num ; i++)
        scanf("%d",&a[i]);
    for(i=0 ; i<num ; i++)
    {
        /*  switch语句也没有问题
        if(a[i]%5==0 && a[i]%2==0)
        {
            r[0]+=a[i];
            continue;
        }
        if(a[i]%5 == 1)
        {
            a[i]*=flag;
            r[1]+=a[i];
            flag*=(-1);
            continue;
        }
        if(a[i]%5 == 2)
        {
            r[2]+=1;
            continue;
        }
        if(a[i]%5 == 3)
        {
            r[3]+=a[i];
            total+=1;
            continue;
        }
        if(a[i]%5 == 3)
        {
            if(a[i]>r[4])
                r[4] = a[i];
        }
        */

        switch (a[i]%5){
        case 0:
            if (a[i]%2==0)
            {
                r[0]+=a[i];
                flag0 = 1;
            }
            break;
        case 1:
            a[i]*=flag;
            r[1]+=a[i];
            flag*=(-1);
            flag1 = 1;
            break;
        case 2:
            r[2]+=1;
            flag2 = 1;
            break;
        case 3:
            r[3]+=a[i];
            total+=1;
            flag3 = 1;
            break;
        case 4:
            if(a[i]>r[4])
            {
                r[4] = a[i];
                flag4 = 1;
            }
            break;
        }

    }
    //与输出方式无关
    if(flag0)
        printf("%d ",r[0]);
    else
        printf("%c ",'N');
    if(flag1)
        printf("%d ",r[1]);
    else
        printf("%c ",'N');
    if(flag2)
        printf("%d ",r[2]);
    else
        printf("%c ",'N');
    if(flag3)
        printf("%.1f ",1.0*r[3]/total);
    else
        printf("%c ",'N');
    if(flag4)
        printf("%d",r[4]);
    else
        printf("%c",'N');
    /*
    for (i=0 ; i<4 ; i++)
    {
        if(r[i]!=0 && i!=3 )
            printf("%d ",r[i]);
        else if(r[i]!=0 && i==3)
            printf("%.1f ",r[i]*1.0/total);
        else
            printf("%c ",'N');
    }
    if(r[4]!=0)
        printf("%d",r[4]);
    else
        printf("%c",'N');
*/
    return 0;
}

/*  正确的
#include <stdio.h>
#include <stdlib.h>
int main()
{
   // freopen("data1.txt","r",stdin);
    int cnt;
    scanf("%d",&cnt);

    int array[5] = {0};

    int i;
    int num,temp,temp1=1,cnt3=0,max = 0;
    int flag1 = 0, flag2 = 0, flag3= 0,flag4 = 0, flag5 = 0;
    for(i = 1; i <= cnt; i++){
        scanf("%d",&num);
        temp = num % 5;
        if(temp == 0 && num % 2 == 0)
            {flag1 = 1; array[0] += num;}
        if(temp == 1) {
            flag2 = 1;
            array[1] += ((temp1 % 2 != 0)? num:(-1*num));
            temp1++;
        }
        if( temp == 2){
            flag3 = 1;
            array[2]++;
        }
        if( temp == 3){
            flag4 = 1;
            cnt3++;
            array[3]+=num;
        }
        if( temp == 4){
            flag5 = 1;
            if(num > max) max = num;
        }
    }

    int h;
    if(flag1) printf("%d ",array[0]); else printf("%c ",'N');
    if(flag2) printf("%d ",array[1]); else printf("%c ",'N');
    if(flag3) printf("%d ",array[2]); else printf("%c ",'N');
    if(flag4) printf("%.1f ",1.0*array[3]/cnt3); else printf("%c ",'N');
    if(flag5) printf("%d",max);else printf("%c",'N');


    return 0;
}
*/
