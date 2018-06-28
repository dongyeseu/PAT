/*
时间：2018/6/24 11点47分
作者：楼浩然
题目：
1050 螺旋矩阵(25)（25 分）
本题要求将给定的N个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第1个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为m行n列，满足条件：m*n等于N；m>=n；且m-n取所有可能值中的最小值。

输入格式：

输入在第1行中给出一个正整数N，第2行给出N个待填充的正整数。所有数字不超过10^4^，相邻数字以空格分隔。

输出格式：

输出螺旋矩阵。每行n个数字，共m行。相邻数字以1个空格分隔，行末不得有多余空格。

输入样例：

12
37 76 20 98 76 42 53 95 60 81 58 93
输出样例：

98 95 93
42 37 81
53 20 76
58 60 76
*/

//别人的代码直接复制过来的

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {return *(int*)b - *(int*)a;}

int main()
{
    int N, m, n;
    scanf("%d", &N);

    int *array = (int*)malloc(N * sizeof(int));
    int *matrix = (int*)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
        scanf("%d", array + i);

    qsort(array, N, sizeof(int), cmp);

    /* determine m and n */
    for(m = 1; !(m * m >= N && N % m == 0); m++) ;
    n = N / m;

    int x = -1, y = 0, index = 0;
    int horizontal = n, virtical = m;

    while(horizontal > 0 && virtical > 0)
    {
        for(int i = 0; i < horizontal && virtical > 0; i++)  /* toward right */
            matrix[y * n + ++x] = array[index++];
        virtical--;

        for(int i = 0; i < virtical && horizontal > 0; i++)  /* toward bottom */
            matrix[++y * n + x] = array[index++];
        horizontal--;

        for(int i = 0; i < horizontal && virtical > 0; i++)  /* toward left */
            matrix[y * n + --x] = array[index++];
        virtical--;

        for(int i = 0; i < virtical && horizontal > 0; i++)  /* toward top */
            matrix[--y * n + x] = array[index++];
        horizontal--;
    }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            printf("%d%c", matrix[i * n + j], j == n - 1 ? '\n' : ' ');

    return 0;
}



/*
void bubble_sort(int * a, int n); //用于数组排序
void l_w(int z, int * l, int *w); // 求出矩阵的长和宽

int main(void)
{
    int N;//矩阵的元素个数
    int length,width;//矩阵的长和宽
    scanf("%d",&N);
    int num[N]; //存储矩阵元素
    int i,j;
    int d=0; //循环计数
    for(i=0 ; i<N ; i++)
        scanf("%d",&num[i]);
    bubble_sort(num,N);
    for(i=0 ; i<N ; i++)          //数组的输入没有问题
        printf("%d ",num[i]);
    printf("\n");
    l_w(N,&length,&width);
    int screw[width][length];
 //   printf("%d %d\n",length,width); //矩阵的长宽没有问题
    memset(screw,0,sizeof(int)*length*width);
    int n=length,m=width;
    int k;
    while(k<N){     //需要赋值N次
        while(j+1<n&&!screw[i][j+1])    screw[i][++j]=num[k++];//先往右，如果小于边界值并且没有赋值过，则赋值
        while(i+1<m&&!screw[i+1][j])    screw[++i][j]=num[k++];//再往下，如果小于边界值并且没有赋值过，则赋值
        while(i-1>=0&&!screw[i-1][j])   screw[--i][j]=num[k++];//再往左，如果小于边界值并且没有赋值过，则赋值
        while(j-1>=0&&!screw[i][j-1])   screw[i][--j]=num[k++];//再往上，如果小于边界值并且没有赋值过，则赋值
    }
    /*
    while(d<N)
    {
        for(j;j<length&&jz[i][j]==0;j++)
        {
            jz[i][j] = num[d++];
            printf("%d %d %d\n",i,j,jz[i][j]);
        }

        j--;
        printf("%d %d\n",i,j);
        for(i;i<width&&jz[i][j]==0;i++)
        {
            jz[i][j] = num[d++];
            printf("%d %d %d\n",i,j,jz[i][j]);
        }

        i--;
        for(j;j>=0&&jz[i][j]==0 ; j--)
            jz[i][j] = num[d++];
        j++;
        for(i;i--&&jz[i][j]==0 ; i++)
            jz[i][j] = num[d++];
        i++;
    }*/
  //  for(i=0 ; i<width ; i++)                //数组的初始化没有问题
 //   {
 //       for(j=0 ; j<length ; j++)
 //           printf("%d%c",jz[i][j],j!=length-1?' ':'\n');
   // }
//    i=0, j=0;
/* 错误
    for(d=0 ; d<N ;d++)
    {
        jz[i][j] = num[d];
        printf("%d %d %d\n",i,j,jz[i][j]);
        if(j<length-1 && j>=0 && jz[i][j+1]==0)
            j++;
        else if(i<width-1 && i>=0 &&jz[i+1][j]==0)
            i++;
        else if(j<=length-1 && j>0 &&jz[i][j-1]==0)
            j--;
        else if(i<=width-1 && i>0 &&jz[i-1][j]==0)
            i--;
    }
*/
    /*  错误，死循环*
    while(d<N)
    {
        while(j<length&&jz[i][j+1]!=0)
        {
            jz[i][j] = num[d];
            printf("%d %d %d",i,j,jz[i][j]);
            j++;
            d++;
        }
        j--;
        while(i<width && jz[i][j]!=0)
        {
            jz[i][j] = num[d];
            printf("%d %d %d",i,j,jz[i][j]);
            i++;
            d++;
        }
        i--;
        while(j>=0 && jz[i][j]!=0)
        {
            jz[i][j] = num[d];
            printf("%d %d %d",i,j,jz[i][j]);
            d++;
            j--;
        }
        j++;
        while(i>0 && jz[i][j] != 0)
        {
            jz[i][j] = num[d];
            printf("%d %d %d",i,j,jz[i][j]);
            d++;
            i--;
        }
        i++;
    }
    */
/*
    for(i=0 ; i<width ; i++)
    {
        for(j=0 ; j<length ; j++)
            printf("%d%c",screw[i][j],j!=length-1?' ':'\n');
    }
    return 0;

}


void bubble_sort(int * a, int n)
{
    int i,j; //用于循环计数
    int change; //y用于判断第二个循环中是否存在元素互换过程
    int k; //用于元素互换
    for(i = n-1 , change = 1 ; i>=1 && change ; i--)
    {
        change = 0;
        for (j=0 ; j<n-1 ; j++)
        {
            if(a[j]<a[j+1])
            {
                k = a[j];
                a[j] = a[j+1];
                a[j+1] = k;
                change = 1;
            }
        }
    }
}

void l_w(int z, int * l, int *w)
{

    int m = sqrt(z);
    int i = m;
    while(z % i)
        i--;
    *l = i;
    *w = z/i ;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {return *(int*)b - *(int*)a;}

int main()
{
    int N, m, n;
    scanf("%d", &N);

    int *array = (int*)malloc(N * sizeof(int));
    int *matrix = (int*)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
        scanf("%d", array + i);

    qsort(array, N, sizeof(int), cmp);

    // determine m and n
    for(m = 1; !(m * m >= N && N % m == 0); m++) ;
    n = N / m;

    int x = -1, y = 0, index = 0;
    int horizontal = n, virtical = m;

    while(horizontal > 0 && virtical > 0)
    {
        for(int i = 0; i < horizontal && virtical > 0; i++)  // toward right
            matrix[y * n + ++x] = array[index++];
        virtical--;

        for(int i = 0; i < virtical && horizontal > 0; i++)  //toward bottom
            matrix[++y * n + x] = array[index++];
        horizontal--;

        for(int i = 0; i < horizontal && virtical > 0; i++)  //toward left
            matrix[y * n + --x] = array[index++];
        virtical--;

        for(int i = 0; i < virtical && horizontal > 0; i++)  // toward top
            matrix[--y * n + x] = array[index++];
        horizontal--;
    }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            printf("%d%c", matrix[i * n + j], j == n - 1 ? '\n' : ' ');

    return 0;
}

*/
