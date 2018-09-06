/*
本题给定一个庞大家族的家谱，要请你给出最小一辈的名单。

输入格式：
输入在第一行给出家族人口总数 N（不超过 100 000 的正整数） —— 简单起见，我们把家族成员从 1 到 N 编号。随后第二行给出 N 个编号，其中第 i 个编号对应第 i 位成员的父/母。家谱中辈分最高的老祖宗对应的父/母编号为 -1。一行中的数字间以空格分隔。

输出格式：
首先输出最小的辈分（老祖宗的辈分为 1，以下逐级递增）。然后在第二行按递增顺序输出辈分最小的成员的编号。编号间以一个空格分隔，行首尾不得有多余空格。

输入样例：
9
2 6 5 5 -1 5 6 4 7
输出样例：
4
1 9
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>>Graph;
map<int,vector<int>>Depth;
int maxdepth = 0;
void DFS(int root,int depth)
{
    if(depth > maxdepth)
        maxdepth = depth;
    Depth[depth].push_back(root);
    for(auto c : Graph[root])
        DFS(c,depth+1);
}
int main()
{
    int N,root,temp;
    cin>>N;
    Graph.resize(N+1);
    for(int i=1 ; i<=N ; i++)
    {
        cin>>temp;
        if(temp != -1)
            Graph[temp].push_back(i);
        else
            root = i;
    }
    DFS(root,1);
    cout<<maxdepth<<"\n";
    vector<int>Res = Depth[maxdepth];
    for(int i=0 ; i<Res.size() ; i++)
    {
        if(i!=0)
            cout<<" ";
        cout<<Res[i];
    }
    cout<<"\n";
    return 0;
}
