/*
L2-023 图着色问题（25 分）
图着色问题是一个著名的NP完全问题。给定无向图G=(V,E)，问可否用K种颜色为V中的每一个顶点分配一种颜色，使得不会有两个相邻顶点具有同一种颜色？

但本题并不是要你解决这个着色问题，而是对给定的一种颜色分配，请你判断这是否是图着色问题的一个解。

输入格式：
输入在第一行给出3个整数V（0<V≤500）、E（≥0）和K（0<K≤V），分别是无向图的顶点数、边数、以及颜色数。顶点和颜色都从1到V编号。随后E行，每行给
出一条边的两个端点的编号。在图的信息给出之后，给出了一个正整数N（≤20），是待检查的颜色分配方案的个数。随后N行，每行顺次给出V个顶点的颜色
（第i个数字表示第i个顶点的颜色），数字间以空格分隔。题目保证给定的无向图是合法的（即不存在自回路和重边）。

输出格式：
对每种颜色分配方案，如果是图着色问题的一个解则输出Yes，否则输出No，每句占一行。

输入样例：
6 8 3
2 1
1 3
4 6
2 5
2 4
5 4
5 6
3 6
4
1 2 3 3 1 2
4 5 6 6 4 5
1 2 3 4 5 6
2 3 4 2 3 4
输出样例：
Yes
Yes
No
No
*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<vector<int>>Graph;
vector<int>Visited;
vector<int>Color;
bool flag = true;
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
        int t = Graph[root][i];
        if(Color[root] == Color[t])
        {
            flag = false;
            return;
        }
        if(!Visited[t])
        {
            DFS(t);
        }
    }
}
int main()
{
    int N,M,K,Z;
    cin>>N>>M>>K;
    int i,j,k;
    Graph.resize(N+1);
    Visited.resize(N+1);
    Color.resize(N+1);
    for(i=0 ; i<M ; i++)
    {
        cin>>j>>k;
        Graph[j].push_back(k);
//        Graph[k].push_back(j);
    }

    cin>>Z;
    for(i=0 ; i<Z ; i++)
    {
        set<int>color;
        for(j=1 ; j<=N ; j++)
        {
            cin>>k;
            if(k>N || k<1)
            {
                cout<<"No\n";
                continue;
            }
            color.insert(k);
            Color[j] = k;

        }
        if(color.size() != K)
        {
            cout<<"No\n";
            continue;
        }
        flag = true;
        Init(N);
        for(j=1 ; j<=N ; j++)
        {
            if(!Visited[j])
            {
                DFS(j);
                if(!flag)
                    break;
            }
        }
        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
