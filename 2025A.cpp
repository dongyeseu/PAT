
/*1105 Spiral Matrix (25)（25 分）
This time your job is to fill a sequence of N positive integers into a spiral matrix in non-increasing order. A spiral matrix is filled in from the first element at the upper-left corner, then move in a clockwise spiral. The matrix has m rows and n columns, where m and n satisfy the following: m*n must be equal to N; m>=n; and m-n is the minimum of all the possible values.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N. Then the next line contains N positive integers to be filled into the spiral matrix. All the numbers are no more than 10^4^. The numbers in a line are separated by spaces.

Output Specification:

For each test case, output the resulting matrix in m lines, each contains n numbers. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.

Sample Input:

12
37 76 20 98 76 42 53 95 60 81 58 93
Sample Output:

98 95 93
42 37 81
53 20 76
58 60 76
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstring>
#include <cstdio>
using namespace std;
void Radix(int &l,int &w,int num)
{
    int i = sqrt(num);
    for(l=i ; l<num ; l++)
    {
        if(num%l == 0)
        {
            w = num/l;
            break;
        }
    }
    if(l<w)
    {
        i = l;
        l = w;
        w = i;
    }
}
int main()
{
    static int N;
    scanf("%d",&N);
    vector<int>num(N);
    int i,j;
    for(i=0 ; i<N ; i++)
    {
        scanf("%d",&num[i]);
    }
    sort(num.begin(),num.end());
    int length,width;
    Radix(length,width,N);
    static int l=0,w=0;
    int res[length][width];
    memset(res,0,sizeof(int)*length*width);
    while(N)
    {
        for(;w<width&&res[l][w]==0;w++)
        {
            res[l][w] = num[--N];
        }

        w--;
        l++;
        for(;l<length&&res[l][w]==0;l++)
        {
            res[l][w] = num[--N];
        }
        w--;
        l--;
        for(;w>=0&&res[l][w]==0;w--)
        {
            res[l][w] = num[--N];
        }

        w++;
        l--;
        for(;l>=0&&res[l][w]==0;l--)
        {
            res[l][w] = num[--N];
        }

        l++;
        w++;
    }
    for(i=0 ; i<length ; i++)
    {
        for(j=0 ; j<width ; j++)
        {
            if(j==0)
                printf("%d",res[i][j]);
            else
                printf(" %d",res[i][j]);
        }
        cout<<"\n";
    }
    return 0;
}
