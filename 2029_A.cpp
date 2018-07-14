/*
1029 Median（25 分）
Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1 = { 11, 12, 13, 14 } is 12, and the median of S2 = { 9, 10, 15, 16, 17 } is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.

Given two increasing sequences of integers, you are asked to find their median.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.

Output Specification:
For each test case you should output the median of the two given sequences in a line.

Sample Input:
4 11 12 13 14
5 9 10 15 16 17
Sample Output:
13
*/
//内存超限
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

vector<int>Num;
void InsertNum(long long int x)
{
    Num.insert(lower_bound(Num.begin(),Num.end(),x),x);
}

int main()
{
    int N,K;
    cin>>N;
    int i;
    long long int temp;
    for(i=0 ; i<N ; i++)
    {
        scanf("%lld",&temp);
        Num.push_back(temp);
    }
    cin>>K;
    for(i=0 ; i<K ; i++)
    {
        scanf("%lld",&temp);
        InsertNum(temp);
    }
    int cnt = (N+K-1)/2 ;
    cout<<Num[cnt];
    return 0;
}

/* 内存超限
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N1,N2;
    vector<int>num1;
    vector<int>num2;
    cin>>N1;
    int i,temp;
    for(i=0 ; i<N1 ; i++)
    {
        cin>>temp;
        num1.push_back(temp);
    }
    cin>>N2;
    for(i=0 ; i<N2 ; i++)
    {
        cin>>temp;
        num2.push_back(temp);
    }
    int j=0;
    i=0;
    vector<int>res;
    while(!(i>=N1 && j>=N2))
    {
        if(j==N2)
            res.push_back(num1[i++]);
        else if(i==N1)
            res.push_back(num2[j++]);
        else
        {
            if(num1[i]<=num2[j])
                res.push_back(num1[i++]);
            else
                res.push_back(num2[j++]);
        }
    }
    int Res = res[(N1+N2-1)/2];
    cout<<Res;
    return 0;
}
*/


/*内存超限，运行超时，原因是由于数据过多
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cmp(int a,int b)
{
    return a<b;
}
int main()
{
    int N1,N2;
    vector<int>num;
    cin>>N1;
    int i,temp;
    for(i=0 ; i<N1 ; i++)
    {
        cin>>temp;
        num.push_back(temp);
    }
    cin>>N2;
    for(i=0 ; i<N2 ; i++)
    {
        cin>>temp;
        num.push_back(temp);
    }
    sort(num.begin(),num.end(),cmp);
    int res = num[(N1+N2-1)/2];
    cout<<res;
    return 0;
}
*/


//他山之玉
//柳婼
题目大意：给出两个已排序序列，求这两个序列合并后的中间数
题解：
1.合并排序，超时超内存（舍）
2.维护两个队列，比较对头大小,循环出队:原先的测试点可以通过的，后来新版PAT加了内存限制，超内存（舍）
3.在2的基础上优化，第一个队列存好后，把第二个队列边读，边和第一个队列比较，选择出队。这样可以不用一次存完第二个队列，解决超内存的问题。
思路：第一、二个序列分别有n, m个元素，所以需要从队头剔除（n + m – 1） / 2个元素，最后答案就是两个队头的最小值。对于最终答案在第一第二个队列中的情
况要分开处理。若答案在第二个队列中，在输入数据时就可以提前得出答案并退出，若答案在第一个队列中，要二次出队才能找到答案。
注意：在所有元素入队列完毕后，把INT_MAX入队列，一是这样队列永不为空，方便处理。二是，题目的long int因为内存限制原因，并不会为最终答案
，只是干扰数据，所以每次遇到这样的干扰数据把他设为INT_MAX即可～
*/
#include <iostream>
#include <climits>
#include <queue>
using namespace std;
int main() {
    queue<int> a, b;
    long long tnum;
    int n, m, num, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &tnum);
        num = min((long long)INT_MAX, tnum);
        a.push(num);
    }
    a.push(INT_MAX);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%lld", &tnum);
        int num = min((long long)INT_MAX, tnum);
        b.push(num);
        if(cnt == (n + m - 1) / 2) {
            printf("%d", min(a.front(), b.front()));
            return 0;
        }
        if(a.front() < b.front())   
            a.pop();
        else                        
            b.pop();
        cnt++;
    }
    b.push(INT_MAX);
    for(; cnt < (n + m - 1) / 2; cnt++) {
        if(a.front() < b.front())    
            a.pop();
        else                         
            b.pop();
    }
    printf("%d", min(a.front(), b.front()));
    return 0;
}
