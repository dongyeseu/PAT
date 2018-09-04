/*
L3-002 特殊堆栈（30 分）
堆栈是一种经典的后进先出的线性结构，相关的操作主要有“入栈”（在堆栈顶插入一个元素）和“出栈”（将栈顶元素返回并从堆栈中删除）。本题要求你实现另一个附加的操作：“取中值”——即返回所有堆栈中元素键值的中值。给定 N 个元素，如果 N 是偶数，则中值定义为第 N/2 小元；若是奇数，则为第 (N+1)/2 小元。

输入格式：
输入的第一行是正整数 N（≤10
​5
​​ ）。随后 N 行，每行给出一句指令，为以下 3 种之一：

Push key
Pop
PeekMedian
其中 key 是不超过 10
​5
​​  的正整数；Push 表示“入栈”；Pop 表示“出栈”；PeekMedian 表示“取中值”。

输出格式：
对每个 Push 操作，将 key 插入堆栈，无需输出；对每个 Pop 或 PeekMedian 操作，在一行中输出相应的返回值。若操作非法，则对应输出 Invalid。

输入样例：
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop
输出样例：
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid
*/


#include <iostream>
#include <stack>
#include <vector>
#include <string>
#define MAXN 100010
using namespace std;
int TreeArray[MAXN] = {0};
int lowbit(int x)
{
    return x & (-x);
}

int getsum(int x)
{
    int res = 0;
    for(int i = x ; i>0 ; i-=lowbit(i))
        res += TreeArray[i];
    return res;
}

void update(int x,int c)
{
    for(int i = x ; i<MAXN ; i+=lowbit(i))
        TreeArray[i] += c;
}

int FindMedian(int K)
{
    int left = 0,right = MAXN, k = (K+1)/2;
    while(left < right)
    {
        int mid = left + (right - left)/2;
        if(getsum(mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main()
{
    int N;
    cin>>N;
    string condition;
    int temp;
    stack<int>Res;
    for(int i=0 ; i<N ; i++)
    {
        cin>>condition;
        if(condition == "Pop")
        {
            if(Res.empty())
                cout<<"Invalid\n";
            else
            {
                int t = Res.top();
                Res.pop();
                cout<<t<<"\n";
                update(t,-1);
            }
        }
        else if(condition == "Push")
        {
            cin>>temp;
            update(temp,1);
            Res.push(temp);
        }
        else if(condition == "PeekMedian")
        {
            if(Res.empty())
                cout<<"Invalid\n";
            else
            {
                int K = Res.size();
                int r = FindMedian(K);
                cout<<r<<"\n";
            }
        }
    }
    return 0;
}
