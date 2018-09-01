/*
1030 Travel Plan (30)（30 分）
A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.

Input Specification:

Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:

City1 City2 Distance Cost

where the numbers are all integers no more than 500, and are separated by a space.

Output Specification:

For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.

Sample Input

4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output

0 2 3 3 40
*/
//OK，套用1003解题模板
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 510
#define INF 999999
using namespace std;
int Graph[MAXN][MAXN] = {0} ; //weight = distance
int Graph_2[MAXN][MAXN] = {0} ; //weight = cost
int Dist[MAXN] ; //distance
int Cost[MAXN] ; //cost
int visited[MAXN] = {0} ; //whether is visited or not
int Parent[MAXN];  //path
int main()
{

    int N,M,S,D; //vertex road start end
    cin>>N>>M>>S>>D;
    int i,j,k,d,s;
    for(i=0 ; i<M ; i++) //graph
    {
        cin>>j>>k>>d>>s;
        Graph[j][k] = Graph[k][j] = d;
        Graph_2[j][k] = Graph_2[k][j] = s;
    }
    fill(Dist,Dist+N,INF); //initialization
    fill(Cost,Cost+N,INF);//initialization
    fill(Parent,Parent+N,-1);//initialization
    Dist[S] = 0;
    Cost[S] = 0;
    for(i=0 ; i<N ; i++)
    {
        if(Graph[S][i])
        {
            Dist[i] = Dist[S] + Graph[S][i];  //first
            Cost[i] = Cost[S] + Graph_2[S][i]; //first
            Parent[i] = S;
        }
    }
    visited[S] = 1;
    for(i=1 ; i<N ; i++)   //Dijsktra method
    {
        int minindex = -1,minweight = INF;
        for(j=0 ; j<N ; j++)
        {
            if(!visited[j] && Dist[j] < minweight)
            {
                minindex = j;
                minweight = Dist[j];
            }
        }
        if(minindex == -1)
            break;
        visited[minindex] = 1;
        for(j=0 ; j<N ; j++)
        {
            if(!visited[j] && Graph[minindex][j] && Dist[j] > Dist[minindex] + Graph[minindex][j])
            {
                Dist[j] = Dist[minindex] + Graph[minindex][j];
                Parent[j] = minindex;
                Cost[j] = Cost[minindex] + Graph_2[minindex][j];
            }
            else if(!visited[j] && Graph[minindex][j] && Dist[j] == Dist[minindex] + Graph[minindex][j])
            {
                if(Cost[j] > Cost[minindex] + Graph_2[minindex][j])
                {
                    Cost[j] = Cost[minindex] + Graph_2[minindex][j];
                    Parent[j] = minindex;
                }
            }
        }
    }
    int z = D;
    vector<int>Res;
    while(z!=-1)
    {
        Res.push_back(z);
         z = Parent[z];
    }
    for(i=Res.size()-1 ; i>=0 ; i--)
        cout<<Res[i]<<" ";
    cout<<Dist[D]<<" "<<Cost[D]<<"\n";
    return 0;
}



//最后一个测试点出现段错误错误
#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
#include <cstring>
#define INF 99999999
#define MAXN 510
using namespace std;

struct City
{
    int distance;
    int cost;
};

struct City Graph[MAXN][MAXN];
int Parent[MAXN];
int Visited[MAXN];
int Dist[MAXN];
int value[MAXN];

void Dijkstra(int st,int N)
{
    memset(Parent,-1,sizeof(int)*MAXN);
    memset(Visited,0,sizeof(int)*MAXN);
    memset(Dist,INF,sizeof(int)*MAXN);
    memset(value,INF,sizeof(int)*MAXN);
    int i,j;
    for(i=0 ; i<N ; i++)
    {
        if(Graph[st][i].distance!=INF)
        {
            Parent[i] = st;
            Dist[i] = Graph[st][i].distance;
            value[i] = Graph[st][i].cost;
        }
    }
    Visited[st] = 1;
    for(i=0 ; i<N-1 ; i++)
    {
        int minindex,minweight = INF;
        for(j=0 ; j<N ; j++)
        {
            if(!Visited[j] && Dist[j] < minweight)
            {
                minindex = j;
                minweight = Dist[j];
            }
        }
        Visited[minindex] = 1;
        for(j=0 ; j<N ; j++)
        {
            if(!Visited[j] && Graph[minindex][j].distance!=INF && Dist[j] > Dist[minindex] + Graph[minindex][j].distance)
            {
                Dist[j] = Dist[minindex] + Graph[minindex][j].distance;
                Parent[j] = minindex;
                value[j] = value[minindex] + Graph[minindex][j].cost;
            }
            else if(!Visited[j] && Graph[minindex][j].distance!=INF && Dist[j] == Dist[minindex] + Graph[minindex][j].distance)
            {
                if(value[j] > value[minindex] + Graph[minindex][j].cost)
                {
                    Parent[j] = minindex;
                    value[j] = value[minindex] + Graph[minindex][j].cost;
                }
            }
        }
    }

}

void DFS(int v,int s)
{
    if(v == s)
        cout<<v;
    else
    {
        DFS(Parent[v],s);
        cout<<" "<<v;
    }
}

int main()
{
    int N,M,S,D;//N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively
    cin>>N>>M>>S>>D;
    int i,j,k,d,s;
    for(i=0 ; i<N ; i++)
    {
        for(j=0 ; j<N ; j++)
        {
            Graph[i][j].distance = INF;
            Graph[i][j].cost = INF ;
        }
    }
    for(i=0 ; i<M ; i++)
    {
        cin>>j>>k>>d>>s;
        Graph[j][k].distance = Graph[k][j].distance = d;
        Graph[j][k].cost = Graph[k][j].cost = s;
    }
    Dijkstra(S,N);
    /*
    stack<int>Res;
    int temp = D;
    while(Parent[temp]!=-1)
    {
        Res.push(temp);
        temp = Parent[temp];
    }
    Res.push(S);
    while(!Res.empty())
    {
        cout<<Res.top()<<" ";
        Res.pop();
    }
    */
    DFS(D,S);
    cout<<" "<<Dist[D]<<" "<<value[D]<<"\n";
    return 0;
}


//他山之玉
//柳婼
/*
题目大意：求起点到终点的最短路径最短距离和花费，要求首先路径最短，其次花费最少，要输出完整路径
分析：Dijksta + DFS。 Dijkstra记录路径pre数组，然后用dfs求最短的一条mincost以及它的路径path，最后输出path数组和mincost
注意路径path因为是从末端一直压入push_back到path里面的，所以要输出路径的时候倒着输出
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, s, d;
int e[510][510], dis[510], cost[510][510];
vector<int> pre[510];
bool visit[510];
const int inf = 99999999;
vector<int> path, temppath;
int mincost = inf;
void dfs(int v) { //DFS + 回溯过程得出最优答案
    temppath.push_back(v);
    if(v == s) {
        int tempcost = 0;
        for(int i = temppath.size() - 1; i > 0; i--) {
            int id = temppath[i], nextid = temppath[i-1];
            tempcost += cost[id][nextid];
        }
        if(tempcost < mincost) {
            mincost = tempcost;
            path = temppath;
        }
        temppath.pop_back(); //这一步必须
        return ; //缺少后会导致段错误
    }
    for(int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    temppath.pop_back();  //必须
}
int main() {
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%d", &e[a][b]);
        e[b][a] = e[a][b];
        scanf("%d", &cost[a][b]);
        cost[b][a] = cost[a][b];
    }
    pre[s].push_back(s);
    dis[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(d);
    for(int i = path.size() - 1; i >= 0; i--)
        printf("%d ", path[i]);
    printf("%d %d", dis[d], mincost);
    return 0;
}
