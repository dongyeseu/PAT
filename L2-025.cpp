/*
分而治之，各个击破是兵家常用的策略之一。在战争中，我们希望首先攻下敌方的部分城市，使其剩余的城市变成孤立无援，然后再分头各个击破。为此
参谋部提供了若干打击方案。本题就请你编写程序，判断每个方案的可行性。

输入格式：
输入在第一行给出两个正整数 N 和 M（均不超过10 000），分别为敌方城市个数（于是默认城市从 1 到 N 编号）和连接两城市的通路条数。随后 M
行，每行给出一条通路所连接的两个城市的编号，其间以一个空格分隔。在城市信息之后给出参谋部的系列方案，即一个正整数 K （≤ 100）和随后的 
K 行方案，每行按以下格式给出：

Np v[1] v[2] ... v[Np]
其中 Np 是该方案中计划攻下的城市数量，后面的系列 v[i] 是计划攻下的城市编号。

输出格式：
对每一套方案，如果可行就输出YES，否则输出NO。

输入样例：
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 10
2 4
5
4 10 3 8 4
6 6 1 7 5 4 9
3 1 8 4
2 2 8
7 9 8 7 6 5 4 2
输出样例：
NO
YES
YES
NO
NO
*/

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>>Graph;
vector<int>Visited;

void Init(int N)
{
    for(int i=0 ; i<=N ; i++)
        Visited[i] = 0;
}
void DFS(int root)
{
    Visited[root] = 1;
    int len = Graph[root].size();
    for(int i=0 ; i<len ; i++)
    {
        if(!Visited[Graph[root][i]])
            DFS(Graph[root][i]);
    }
}
int main()
{
    int N,M,K,Z;
    cin>>N>>M;
    Graph.resize(N+1);
    Visited.resize(N+1);
    int i,j,k;
    for(i=0 ; i<M ; i++)
    {
        cin>>j>>k;
        Graph[j].push_back(k);
        Graph[k].push_back(j);
    }
    cin>>K;
    for(i=0 ; i<K ; i++)
    {
        cin>>Z;
        Init(N);
        for(j=0 ; j<Z ; j++)
        {
            cin>>k;
            Visited[k] = 1;
        }
        int cnt = 0;
        for( j=1 ; j<=N ; j++)
        {
            if(!Visited[j])
            {
                DFS(j);
                cnt++;
            }
        }
        if(cnt == N - Z)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;

}
