/*
时间：2018/6/21 20点18分
作者：楼浩然
题目：
1065 单身狗(25)（25 分）
“单身狗”是中文对于单身人士的一种爱称。本题请你从上万人的大型派对中找出落单的客人，以便给予特殊关爱。

输入格式：

输入第一行给出一个正整数N（<=50000），是已知夫妻/伴侣的对数；随后N行，每行给出一对夫妻/伴侣——为方便起见，每人对应一个ID号，为5位数字（从00000到99999），ID间以空格分隔；之后给出一个正整数M（<=10000），为参加派对的总人数；随后一行给出这M位客人的ID，以空格分隔。题目保证无人重婚或脚踩两条船。

输出格式：

首先第一行输出落单客人的总人数；随后第二行按ID递增顺序列出落单的客人。ID间用1个空格分隔，行的首尾不得有多余空格。

输入样例：

3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
输出样例：

5
10000 23333 44444 55555 88888
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ID[100000];
    int N,ID1,ID2;
    scanf("%d",&N);
    int i;
    for(i=0 ; i<100000 ; i++)
        ID[i] = -1;
    for(i=0 ; i<N ; i++)
    {
        scanf("%d %d",&ID1,&ID2);
        ID[ID1] = ID2;
        ID[ID2] = ID1;
    }
    int M;
    scanf("%d",&M);
    int count = 0; //记录单身人数
    for(i=0 ; i<M ; i++)
    {
        scanf("%d",&ID1);
        if(ID[ID1]<0)
        {
            ID[ID1] = -2; //-2代表单身
            count++;
         //   printf("%05d\n",ID1);
        }
        else
        {
            ID[ID1] = -3;
        }
    }
    for(i=0 ; i<100000 ; i++)
    {
        if(ID[i]>=0 && ID[ID[i]] == -3)
            ID[ID[i]] = -2 , count++;
    }
    printf("%d\n",count);
    for(i=0 ; i<100000 ; i++)
    {
        if(ID[i]==-2)
            printf("%05d%c",i,--count?' ':'\n');
    }
    return 0;
}

/*
总结：
1.用一个大型数组的下标来记录ID值
2.对夫妻的ID值进行关联
*/








/*  答案不正确
#include <stdio.h>
//思路：将成对的已婚人士剔除出去，所有ID用char来存储，用strstr()函数来判断是否最后一行输入中是否同时包含夫妻ID
#include <stdlib.h>
#include <string.h>

int cmp(const void * a,const void * b)
{
    return *(char *)a - *(char *)b;
}

int main(void)
{
    int N;//夫妻对数
    scanf("%d",&N);
    char couple[N*2][6];//存储夫妻ID
    char Couple[N*2*7];//将夫妻的ID合并在一起
    Couple[0] = '\0';
    int i;
    for(i=0 ; i<N*2 ; i++)
    {
        scanf("%s",couple[i]);
        strcat(Couple,couple[i]);
        strcat(Couple," ");
    }
 //   printf("%s\n",Couple);
    int K;//参会人数
    scanf("%d",&K);
    while(getchar()!='\n')
        continue;
    char all[K*6+1];//保存为同一个字符串
    all[0] = '\0';
    char All[K][7];//分开保存ID
    char singal[K][7];//落单者ID
 //   scanf("%[^\n]",all);
    for(i=0 ; i<K ; i++)
    {
        scanf("%s",All[i]);
        strcat(all,All[i]);
        strcat(all," ");
    }
    int j = 0;
    for(i=0 ; i<N*2 ; i+=2)
    {
        if(strstr(all,couple[i])!=0 && strstr(all,couple[i+1])==0)
            strcpy(singal[j++],couple[i]);
        else if(strstr(all,couple[i])==0 && strstr(all,couple[i+1])!=0)
            strcpy(singal[j++],couple[i+1]);
        else
            continue;
    }
//    for(i=0 ; i<j ; i++)
  //     printf("%s\n",All[i]);
    for(i=0 ; i<K ; i++)
    {
        if(strstr(Couple,All[i])==0)
            strcpy(singal[j++],All[i]);
    }
  //  printf("%s\n",all);
  //  printf("%s\n",all);

    qsort(All,j,sizeof(char)*5,cmp);
    printf("%d\n",j);
    for(i=0 ; i<j ; i++)
       printf("%s%c",All[i],i==j-1?'\n':' ');
//    printf("%s",all);
    return 0;

}
*/

