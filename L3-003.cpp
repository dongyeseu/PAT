/*
L3-003 社交集群（30 分）
当你在社交网络平台注册时，一般总是被要求填写你的个人兴趣爱好，以便找到具有相同兴趣爱好的潜在的朋友。一个“社交集群”是指部分兴趣爱好相同的人的集合。你需要找出所有的社交集群。

输入格式：
输入在第一行给出一个正整数 N（≤1000），为社交网络平台注册的所有用户的人数。于是这些人从 1 到 N 编号。随后 N 行，每行按以下格式给出一个人的兴趣爱好列表：

K
​i
​​ : h
​i
​​ [1] h
​i
​​ [2] ... h
​i
​​ [K
​i
​​ ]

其中K
​i
​​ (>0)是兴趣爱好的个数，h
​i
​​ [j]是第j个兴趣爱好的编号，为区间 [1, 1000] 内的整数。

输出格式：
首先在一行中输出不同的社交集群的个数。随后第二行按非增序输出每个集群中的人数。数字间以一个空格分隔，行末不得有多余空格。

输入样例：
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
输出样例：
3
4 3 1
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int Father[10010];
void Init()
{
    for(int i=0 ; i<10010 ; i++)
        Father[i] = i;
}

int FindFather(int x)
{
    int i = x;
    while(i != Father[i])
        i = Father[i];
    int t = x,a;
    while(t!=Father[t])
    {
        a = Father[t];
        Father[t] = i;
        t = a;
    }
    return i;
}

void Union(int x,int y)
{
    int a = FindFather(x);
    int b = FindFather(y);
    if(a!=b)
        Father[a] = b;
}
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int N;
    cin>>N;
    Init();
    for(int i=0 ; i<N ; i++)
    {
        int K;
        scanf("%d:",&K);
        vector<int>Picture(K);
        for(int j=0 ; j<K ; j++)
        {
            cin>>Picture[j];
            Union(i,Picture[j]+N+1);
        }
    }
    map<int,int>Res;
    for(int i=0 ; i<N ; i++)
    {
        int t= FindFather(i);
        Res[t]++;
    }
    vector<int>People;
    for(auto z = Res.begin() ; z!=Res.end() ; z++)
    {
        People.push_back(z->second);
    }
    sort(People.begin(),People.end(),cmp);
    cout<<Res.size()<<"\n"
    for(int i =0 ;i<People.size() ; i++)
    {
        if(i!=0)
            cout<<" ";
        cout<<People[i];
    }
    return 0;

}
