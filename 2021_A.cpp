/*
1021 Deepest Root (25)（25 分）
A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N-1 lines follow, each describes an edge by given the two adjacent nodes' numbers.

Output Specification:

For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print "Error: K components" where K is the number of connected components in the graph.

Sample Input 1:

Sample Output 1:

3
4
5
Sample Input 2:

5
1 3
1 4
2 5
3 4
Sample Output 2:

Error: 2 components
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
vector<int>visited;
int N;
int max_depth = 0;
vector<int>temp;
void DFS(int i , vector<vector<int>>Graph , int depth)
{
    if(depth > max_depth)
    {
        temp.clear();
        temp.push_back(i);
        max_depth = depth;
    }
    else if(depth == max_depth)
        temp.push_back(i);
    visited[i] = 1;
    int j;
    for(j=0 ; j<Graph[i].size() ; j++)
    {
        if(!visited[Graph[i][j]])
            DFS(Graph[i][j],Graph,depth+1);
    }
}
int Initislize(vector<int>&v,int N)
{
    int i;
    for(i=0 ; i<N ; i++)
        v[i] = 0;
}
int main()
{
    int i,j,k;
    cin>>N;
    visited.resize(N+1);
    Initislize(visited,N+1);
    vector<vector<int>>Graph(N+1);
    for(i=0 ; i<N-1 ; i++)
    {
        scanf("%d %d",&j,&k);
        Graph[j].push_back(k);
        Graph[k].push_back(j);
    }
    map<int,vector<int>>Max_num;
    int flag = 0;
    int cnt = 0;
    int s1;
    set<int>s;
    for(i=1 ; i<=N ; i++)
    {
        if(!visited[i])
        {
            DFS(i,Graph,i);
            if(i==1)
            {
                if(temp.size()!=0)
                    s1 = temp[0];
                int z;
                for(z=0 ; z<temp.size() ; z++)
                    s.insert(temp[z]);
            }
            cnt++;
        }

    }
    if(cnt==1)
    {
        max_depth = 0;
        temp.clear();
        Initislize(visited,N+1);
        DFS(s1,Graph,1);
        for(i=0 ; i<temp.size() ; i++)
            s.insert(temp[i]);
        auto k = s.begin();
        for( k; k!=s.end() ; k++)
            cout<<*k<<"\n";

    }
    else
    {
        printf("Error: %d components",cnt);
    }

    return 0;
}


/*某一个测试点内存超限
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;
int visited[10003];
int N;
int max_depth = 0;
vector<int>Temp;
void DFS(int i , vector<vector<int>>Graph , int depth)
{
    if(depth > max_depth)
    {
        max_depth = depth;
    }
    visited[i] = 1;
    Temp.push_back(i);
    int j;
    for(j=1 ; j<=N ; j++)
    {
        if(!visited[j] && Graph[i][j]==1)
            DFS(j,Graph,depth+1);
    }
}

int main()
{
    int i,j,k;
    cin>>N;
    vector<vector<int>>Graph(N+1,vector<int>(N+1));
    for(i=0 ; i<=N ;i++)
    {
        for(j=0 ; j<=N ; j++)
            Graph[i][j] = 0;
    }
    memset(visited,0,sizeof(visited));
    for(i=0 ; i<N-1 ; i++)
    {
        cin>>j>>k;
        Graph[j][k] = Graph[k][j] = 1;
    }
    map<int,vector<int>>Max_num;
    int flag = 0;
    int cnt = 0;
    for(i=1 ; i<=N ; i++)
    {
        if(!visited[i])
        {
            DFS(i,Graph,i);
            cnt++;
        }
    }
    if(cnt==1)
    {
        for(i=1 ; i<=N ; i++)
        {
            memset(visited,0,sizeof(visited));
            DFS(i,Graph,1);
            Max_num[max_depth].push_back(i);
            max_depth = 0;
        }
        auto t = Max_num.rbegin();
        int len = t->second.size();
        for(i= 0 ; i<len ; i++)
            cout<<t->second[i]<<"\n";
    }
    else
    {
        printf("Error: %d components",cnt);
    }

    return 0;
}
*/
/*
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
int Graph[100][100];
int visited[100];
int N;
int max_depth = 0;
vector<int>Temp;
void DFS(int i,int depth)
{
    if(depth > max_depth)
    {
        max_depth = depth;
    }
    visited[i] = 1;
    Temp.push_back(i);
    int j;
    for(j=1 ; j<=N ; j++)
    {
        if(!visited[j] && Graph[i][j]==1)
            DFS(j,depth+1);
    }
}

int main()
{
    int i,j,k;
    cin>>N;
    memset(Graph,0,sizeof(Graph));
    memset(visited,0,sizeof(visited));
    for(i=0 ; i<N-1 ; i++)
    {
        cin>>j>>k;
        Graph[j][k] = Graph[k][j] = 1;
    }
    map<int,vector<int>>Max_num;
    int flag = 0;
    for(i=1 ; i<=N ; i++)
    {
        DFS(i,1);
        memset(visited,0,sizeof(visited));
        Max_num[max_depth].push_back(i);
        max_depth = 0;
    }
    auto t = Max_num.rbegin();
    int len = t->second.size();
    for(i= 0 ; i<len ; i++)
        cout<<t->second[i]<<"\n";
    return 0;
}
*/


//他山之玉
//柳婼
/*
题目大意：给出n个结点（1~n）之间的n条边，问是否能构成一棵树，如果不能构成则输出它有的连通分量个数，如果能构成一棵树，输出能构成最深的树的高度时，
树的根结点。如果有多个，按照从小到大输出。
分析：首先深度优先搜索判断它有几个连通分量。如果有多个，那就输出Error: x components，如果只有一个，就两次深度优先搜索，先从一个结点dfs后保留最高高
度拥有的结点们，然后从这些结点中的其中任意一个开始dfs得到最高高度的结点们，这两个结点集合的并集就是所求
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n, maxheight = 0;
vector<vector<int>> v;
bool visit[10010];
set<int> s;
vector<int> temp;
void dfs(int node, int height) {
    if(height > maxheight) {
        temp.clear();
        temp.push_back(node);
        maxheight = height;
    } else if(height == maxheight){
        temp.push_back(node);
    }
    visit[node] = true;
    for(int i = 0; i < v[node].size(); i++) {
        if(visit[v[node][i]] == false)
            dfs(v[node][i], height + 1);
    }
}
int main() {
    scanf("%d", &n);
    v.resize(n + 1);
    int a, b, cnt = 0, s1 = 0;
    for(int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        if(visit[i] == false) {
            dfs(i, 1);
            if(i == 1) {
                if (temp.size() != 0) s1 = temp[0];
                for(int j = 0; j < temp.size(); j++)
                    s.insert(temp[j]);
            }
            cnt++;
        }
    }
    if(cnt >= 2) {
        printf("Error: %d components", cnt);
    } else {
        temp.clear();
        maxheight = 0;
        fill(visit, visit + 10010, false);
        dfs(s1, 1);
        for(int i = 0; i < temp.size(); i++)
            s.insert(temp[i]);
        for(auto it = s.begin(); it != s.end(); it++)
            printf("%d\n", *it);
    }
    return 0;
}
