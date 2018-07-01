/*
时间：2018/6/28 13点33分
作者：楼浩然
题目：
1068 万绿丛中一点红（20 分）
对于计算机而言，颜色不过是像素点对应的一个 24 位的数值。现给定一幅分辨率为 M×N 的画，要求你找出万绿丛中的一点红，即有独一无二颜色的那个像素点，并且该点的颜色与其周围 8 个相邻像素的颜色差充分大。

输入格式：
输入第一行给出三个正整数，分别是 M 和 N（≤ 1000），即图像的分辨率；以及 TOL，是所求像素点与相邻点的颜色差阈值，色差超过 TOL 的点才被考虑。随后 N 行，每行给出 M 个像素的颜色值，范围在 [0,2
​24
​​ ) 内。所有同行数字间用空格或 TAB 分开。

输出格式：
在一行中按照 (x, y): color 的格式输出所求像素点的位置以及颜色值，其中位置 x 和 y 分别是该像素在图像矩阵中的列、行编号（从 1 开始编号）。如果这样的点不唯一，则输出 Not Unique；如果这样的点不存在，则输出 Not Exist。

输入样例 1：
8 6 200
0 	 0 	  0 	   0	    0 	     0 	      0        0
65280 	 65280    65280    16711479 65280    65280    65280    65280
16711479 65280    65280    65280    16711680 65280    65280    65280
65280 	 65280    65280    65280    65280    65280    165280   165280
65280 	 65280 	  16777015 65280    65280    165280   65480    165280
16777215 16777215 16777215 16777215 16777215 16777215 16777215 16777215
输出样例 1：
(5, 3): 16711680
输入样例 2：
4 5 2
0 0 0 0
0 0 3 0
0 0 0 0
0 5 0 0
0 0 0 0
输出样例 2：
Not Unique
输入样例 3：
3 3 5
1 2 3
3 4 5
5 6 7
输出样例 3：
Not Exist
*/

#include <stdio.h>

#define SQR(X) ((X)*(X))
#define R(COLOR) ((COLOR & 0XFF0000) >> 16)
#define G(COLOR) ((COLOR & 0X00FF00) >> 8)
#define B(COLOR) (COLOR & 0X0000FF)
#define D(C1, C2) (SQR(R(C1) - R(C2)) + SQR(G(C1) - G(C2)) +  SQR(B(C1) - B(C2)))

int iUnique(int array[][1000], int x, int y, int x0, int y0)
{
    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            if(array[i][j] == array[x0][y0] && i != x0 && j != y0)
                return 0;
    return 1;
}

int main()
{
    int M, N, TOL;
    scanf("%d %d %d", &M, &N, &TOL);

    int fig[1000][1000];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &fig[i][j]);

    int count = 0, M0, N0;
    for(int i = 0; i < N; i ++)
        for (int j = 0; j < M; j++)
            if((i ==   0   ? 1 : D(fig[i][j], fig[i - 1][j - 1]) > SQR(TOL))
            && (i ==   0   ? 1 : D(fig[i][j], fig[i - 1][j    ]) > SQR(TOL))
            && (i ==   0   ? 1 : D(fig[i][j], fig[i - 1][j + 1]) > SQR(TOL))
            && (j ==   0   ? 1 : D(fig[i][j], fig[i    ][j - 1]) > SQR(TOL))
            && (j == M - 1 ? 1 : D(fig[i][j], fig[i    ][j + 1]) > SQR(TOL))
            && (i == N - 1 ? 1 : D(fig[i][j], fig[i + 1][j - 1]) > SQR(TOL))
            && (i == N - 1 ? 1 : D(fig[i][j], fig[i + 1][j    ]) > SQR(TOL))
            && (i == N - 1 ? 1 : D(fig[i][j], fig[i + 1][j + 1]) > SQR(TOL))
            && iUnique(fig, N, M, i, j))
            {
                count++;
                N0 = i;
                M0 = j;
            }

    if(count == 0)  printf("Not Exist");
    if(count == 1)  printf("(%d, %d): %d", M0 + 1, N0 + 1, fig[N0][M0]);
    if(count >= 2)  printf("Not Unique");

    return 0;
}


/* 比较方式错误
#include <stdio.h>

int main(void)
{
    int M,N,TOF; //分别代表列，行，阈值；
    scanf("%d %d %d",&M,&N,&TOF);
    int color[N][M];
    int i,j;
    for(i=0 ; i<N ; i++)
    {
        for(j=0 ;j<M ; j++)
            scanf("%d",&color[i][j]);
    }
    for(i=0 ; i<N ; i++)
    {
        for(j=0 ;j<M ; j++)
            printf("%d ",color[i][j]);
        printf("\n");
    }
    int count = 0;
    int max_i,max_j;
    for(i=1 ; i<N-1 ; i++)
    {
        for(j=1 ; j<M-1 ; j++)
        {
            if(color[i][j]-color[i-1][j]>TOF &&color[i][j]-color[i+1][j]>TOF &&color[i][j]-color[i-1][j-1]>TOF &&color[i][j]-color[i-1][j+1]>TOF &&color[i][j]-color[i+1][j-1]>TOF &&color[i][j]-color[i+1][j+1]>TOF &&color[i][j]-color[i][j-1]>TOF &&color[i][j]-color[i][j+1]>TOF)
            {
                count++;
                max_i = i;
                max_j = j;
            }
        }
        if(count>1)
            {
                printf("Not Unique\n");
                break;
            }
    }
    if(count==0)
        printf("Not Exist\n");
    else if(count == 1)
        printf("(%d, %d): %d",max_j,max_i+1,color[max_i,max_j]);
    return 0;
}
*/
