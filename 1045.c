/*
时间：2018/6/27 14点27分
作者：楼浩然
题目：
1045 快速排序(25)（25 分）
著名的快速排序算法里有一个经典的划分过程：我们通常采用某种方法取一个元素作为主元，通过交换，把比主元小的元素放到它的左边，比主元大的元素放到它的右边。 给定划分后的N个互不相同的正整数的排列，请问有多少个元素可能是划分前选取的主元？

例如给定N = 5, 排列是1、3、2、4、5。则：

1的左边没有元素，右边的元素都比它大，所以它可能是主元；\

尽管3的左边元素都比它小，但是它右边的2它小，所以它不能是主元；\

尽管2的右边元素都比它大，但其左边的3比它大，所以它不能是主元；\

类似原因，4和5都可能是主元。

因此，有3个元素可能是主元。

输入格式：

输入在第1行中给出一个正整数N（<= 10^5^）； 第2行是空格分隔的N个不同的正整数，每个数不超过10^9^。

输出格式：

在第1行中输出有可能是主元的元素个数；在第2行中按递增顺序输出这些元素，其间以1个空格分隔，行末不得有多余空格。

输入样例：

5
1 3 2 4 5
输出样例：

3
1 4 5
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a,const void * b){return (*(int *)a - *(int *)b);}

int main(void)
{
    int N;
    scanf("%d",&N);
    int num[N];
    int i;
    for(i=0 ; i<N ; i++)
        scanf("%d",&num[i]);
    int sum = 0;
    int res1[N],res2[N];
    int max = num[0];
    for(i=0;i<N;i++)
    {
        if(num[i]>max)
        {
            max = num[i];
            res1[i] = max;
        }
        else
        {
            res1[i] = max;
        }
    }
    int min = num[N-1];
    for(i=N-1 ; i>=0 ; i--)
    {
        if(num[i]<min)
        {
            min = num[i];
            res2[i] = min;
        }
        else
        {
            res2[i] = min;
        }
    }
    sum = 0;
    int res[N];
    for(i=0 ; i<N ; i++)
    {
        if(num[i]==res1[i] && num[i]==res2[i])
        {
            res[sum] = num[i];
            sum++;
        }
    }
    qsort(res,sum,sizeof(int),cmp);
    if(sum==0)
    {
        printf("%d\n",sum);
        printf("\n")
    }
    else
    {
        printf("%d\n",sum);
        for(i=0 ; i<sum ; i++)
        {
            if(res[i])
                printf("%d%c",res[i],i!=sum-1?' ':'\n');
        }
    }
    return 0;

}


/*  更简洁的写法
#include <stdio.h>
int main()
{
    int N, count = 0;
    int array[100000], lmax[100000], rmin[100000];
 
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", array + i);
 
    /* find the largest on one's left and the smallest on the right */
    for(int i = 0, max = i; i < N; i++)
        lmax[i] = array[i] >= array[max] ? array[max = i] : array[max];
    for(int i = N - 1, min = i; i >= 0; i--)
        rmin[i] = array[i] <= array[min] ? array[min = i] : array[min];
 
    /* a element is the largest on its left and the smallest on its right, 
     * it is probably a pivot */
    for(int i = 0; i < N; i++)
    {
        if(array[i] == lmax[i] && array[i] == rmin[i])
            count++;
        else
            array[i] = 0;
    }
 
    printf("%d\n", count);
    for(int i = 0; i < N && count; i++) if(array[i])
        printf("%d%c", array[i], --count ? ' ' : '\0');
    printf("\n");
 
    return 0;
*/


/*  有测试点通不过
int main(void)
{
    int N;
    scanf("%d",&N);
    int num[N];
    int i;
    for(i=0 ; i<N ; i++)
        scanf("%d",&num[i]);
    int sum = 0;
    int res[N];
    int flag = 1;
    for(i=0 ; i<N ; i++)
    {
        int j;
        if(flag==1)
        {
            for(j=i-1 ; j>=0 ;j--)
            {
                if(num[j] >= num[i])
                {
                    flag = 0;
                    break;
                }

            }
            if(flag==1)
            {
                for(j=i+1 ; j<N ; j++)
                {
                    if(num[j]<=num[i])
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag == 1)
            {
                res[sum] = num[i];
                sum++;
            }
        }
        else
        {
            flag = 1;
            continue;
        }


    }
    printf("%d\n",sum);
    if(sum!=0)
    {
        for(i=0 ; i<sum ; i++)
        {
            printf("%d%c",res[i],i!=sum-1?' ':'\n');
        }
    }

    return 0;
}
*/
