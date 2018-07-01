/*
时间：2018/7/1
作者；楼浩然
题目：
1075 链表元素分类（25 分）
给定一个单链表，请编写程序将链表元素进行分类排列，使得所有负值元素都排在非负值元素的前面，而 [0, K] 区间内的元素都排在大于 K 的元素前面。但每一类内部元素的顺序是不能改变的。例如：给定链表为 18→7→-4→0→5→-6→10→11→-2，K 为 10，则输出应该为 -4→-6→-2→7→0→5→10→18→11。

输入格式：

输出格式：
对每个测试用例，按链表从头到尾的顺序输出重排后的结果链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
输出样例：
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1
*/

#include <stdio.h>
#include <stdlib.h>

#define SWAP(A,B) {Node temp = A; A = B; B = temp;}

struct node{
    int address;
    int data;
    int next;
};

typedef struct node * Node;

int main(void)
{
    Node *list,*p;
    int addre,N,K;
    scanf("%d %d %d",&addre,&N,&K);
    list = (Node *)malloc(sizeof(Node)*N);
    int i,j;
    for(i=0 ; i<N ; i++)
    {
        list[i] = malloc(sizeof(struct node));
        scanf("%d %d %d",&list[i]->address,&list[i]->data,&list[i]->next);
    }
    for(i=0 ; i<N ; i++)
    {
        for(j=i ; j<N ; j++)
        {
            if(list[j]->address==(i?list[i-1]->next:addre)){
                SWAP(list[i],list[j]);
                break;
            }
        }
        if(list[i]->next == -1)
        {
            N = i+1;
        }
    }
    //依然运行超时，应该是由于上面的分类问题
    int zero[N],xiaoyu[N],dayu[N],dengyu[N];
    int f=0,x=0,d=0,k = 0;
    for(i=0 ; i<N ; i++)
    {
        if(list[i]->data<0)
            zero[f++] = i;
        else if(list[i]->data < K)
            xiaoyu[x++] = i;
        else if(list[i]->data == K)
            dengyu[k++] = i;
        else
            dayu[d++] = i;
    }
    int lst[N];
    int f_1 = 0, x_1 = 0 ,d_1 = 0,k_1 = 0;
    for(i=0 ; i<N ; i++)
    {
        if(f_1<f)
            lst[i] = zero[f_1++];
        else if(x_1 < x)
            lst[i] = xiaoyu[x_1++];
        else if(k_1 < k)
            lst[i] = dengyu[k_1++];
        else if(d_1 < d)
            lst[i] = dayu[d_1++];
    }
    // 可行，但是会存在运行超时的问题
    /*
    for(i=1 ; i<N ;)
    {
        if(list[i]->data <0 && i-1>=0 &&list[i-1]->data >=0)
        {
            SWAP(list[i],list[i-1]);
            i--;
        }
        else
            i++;
    }
    for(i=1 ; i<N ;)
    {
        if(list[i]->data <K && i-1>=0 &&list[i-1]->data >=K)
        {
            SWAP(list[i],list[i-1]);
            i--;
        }
        else
            i++;
    }
    for(i=1 ; i<N ;)
    {
        if(list[i]->data == K && i-1>=0 &&list[i-1]->data >K)
        {
            SWAP(list[i],list[i-1]);
            i--;
        }
        else
            i++;
    }
    */
    for(i=0 ; i<N-1 ; i++)
        printf("%05d %d %05d\n",list[lst[i]]->address,list[lst[i]]->data,list[lst[i+1]]->address);
    printf("%05d %d -1\n",list[lst[N-1]]->address,list[lst[N-1]]->data);


    return 0;
}


#include <stdio.h>

int main()
{
    int data[100000] = {0}, next[100000] = {0},
        firstaddr, addr, lastaddr = -1, N, K;

    /* Read */
    scanf("%d %d %d", &firstaddr, &N, &K);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &addr);
        scanf("%d %d", data + addr, next + addr);
    }

    /* Scan three times */
    for(int i = 0; i < 3; i++)
    {
        /* Scan along the linked list */
        for(addr = firstaddr; addr != -1; addr = next[addr])
        {
            /* If the number fits the condition */
            if((i == 0 && data[addr] < 0)
            || (i == 1 && 0 <= data[addr] && data[addr] <= K)
            || (i == 2 && data[addr] > K))
            {
                /* Print */
                if(lastaddr != -1) printf(" %05d\n", addr);
                printf("%05d %d", addr, data[addr]);
                lastaddr = addr;
            }
        }
    }
    printf(" -1");

    return 0;
}
