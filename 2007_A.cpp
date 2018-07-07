/*
1007 Maximum Subsequence Sum (25)（25 分）
Given a sequence of K integers { N~1~, N~2~, ..., N~K~ }. A continuous subsequence is defined to be { N~i~, N~i+1~, ..., N~j~ } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:

10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:

10 1 4
*/

#include <iostream>
#include <climits>
using namespace std;
int MaxSubSequenceSum(const int A[],int N,int &i,int &j)
{
    i = j = A[0];
    int temp = A[0];
    int ThisSum,MaxSum,k;
    ThisSum = 0;
    MaxSum =  INT_MIN;
    for(k=0 ; k<N ; k++)
    {
        ThisSum += A[k];
        if(ThisSum > MaxSum && ThisSum >=0)
        {
            MaxSum = ThisSum;
            j = A[k];
            i = temp ;
        }
        else if(ThisSum < 0)
        {
            ThisSum = 0;
            if(k+1< N)temp = A[k+1];
        }
    }
    return MaxSum;
}
int main()
{
    int N;
    cin>>N;
    int num[N];
    int i,cnt=0;
    for(i=0 ; i<N ; i++)
    {
        cin>>num[i];
        if(num[i]<0)cnt++;
    }

    int Min,Max,Sum;
    Sum = MaxSubSequenceSum(num,N,Min,Max);
    if(cnt!=N)
        cout<<Sum<<" "<<Min<<" "<<Max<<"\n";
    else
        cout<<0<<" "<<num[0]<<" "<<num[N-1]<<"\n";
    return 0;
}

//他山之玉
柳婼
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    int leftindex = 0, rightindex = n - 1, sum = -1, temp = 0, tempindex = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        temp = temp + v[i];
        if (temp < 0) {
            temp = 0;
            tempindex = i + 1;
        } else if (temp > sum) {
            sum = temp;
            leftindex = tempindex;
            rightindex = i;
        }
    }
    if (sum < 0) sum = 0;
    printf("%d %d %d", sum, v[leftindex], v[rightindex]);
    return 0;
}
