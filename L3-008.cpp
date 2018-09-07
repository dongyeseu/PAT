/*
输入格式：
输入第一行给出3个正整数n、m和k，其中n（≤10000）是总的山头数（于是假设每个山头从1到n编号）。接下来的m行，每行给出2个不超过n的正整数，数字
间用空格分开，分别代表可以听到彼此的两个山头的编号。这里保证每一对山头只被输入一次，不会有重复的关系输入。最后一行给出k（≤10）个不超过n的
正整数，数字间用空格分开，代表需要查询的山头的编号。

输出格式：
依次对于输入中的每个被查询的山头，在一行中输出其发出的呼喊能够连锁传达到的最远的那个山头。注意：被输出的首先必须是被查询的个山头能连锁传到
的。若这样的山头不只一个，则输出编号最小的那个。若此山头的呼喊无法传到任何其他山头，则输出0。

输入样例：
7 5 4
1 2
2 3
3 1
4 5
5 6
1 4 5 7
输出样例：
2
6
4
0
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;

vector<vector<int>>Graph;
vector<int>Visited;
int maxdepth = 0;
bool cmp(int a,int b)
{
    return a < b;
}
void Init()
{
    int len = Visited.size();
    for(int i=0 ; i<len ; i++)
        Visited[i] = 0;
}
map<int,vector<int>>Depth;
int DFS(int root)
{
    queue<int>Tree;
    Tree.push(root);
    Visited[root] = 1;
    int depth = 0;
    while(!Tree.empty())
    {
        int S = Tree.size();
        depth++;
        for(int i=0 ; i<S ; i++)
        {
            int node = Tree.front();
            Tree.pop();
            Depth[depth].push_back(node);
            for(auto c:Graph[node])
            {
                if(!Visited[c])
                {
                    Visited[c] = 1;
                    Tree.push(c);

                }
            }
        }
        if(depth > maxdepth)
            maxdepth = depth;
    }
    if(maxdepth==1)
        return 0;
    else
    {
        vector<int>Temp = Depth[maxdepth];
        sort(Temp.begin(),Temp.end());
        return Temp[0];
    }

}
int main()
{
    int N,M,K,j,k;
    cin>>N>>M>>K;
    Graph.resize(N+1);
    Visited.resize(N+1);
    for(int i=0 ; i<M ; i++)
    {
        cin>>j>>k;
        Graph[j].push_back(k);
        Graph[k].push_back(j);
    }
    for(int i=0 ; i<K ; i++)
    {

        Init();
        Depth.clear();
        maxdepth = 0;
        cin>>j;
        int res = DFS(j);
        cout<<res<<"\n";
    }
    return 0;
}
