#include <iostream>
#include <cstring>
#define MAXN 510
#define INF 99999999
using namespace std;
int Graph[MAXN][MAXN];
int Dist[MAXN],Visited[MAXN],value[MAXN];
int u[MAXN],v[MAXN];

void Dijkstra(int st,int N)
{
    int i,j,k,totalweight = 0;
    for(i=0 ; i<N ; i++)
    {
        Dist[i] = Graph[st][i];
        Visited[i] = 0;
        u[i] = 1;
        if(Graph[st][i]==INF || st == i)
            v[i] = value[i];
        else
            v[i] = value[i] + value[st];
    }
    Visited[st] = 1;
    for(k=1 ; k<=N-1 ; k++)
    {
        int minindex,minweight = INF;
        for(i=0 ; i<N ; i++)
        {
            if(!Visited[i] && Dist[i] < minweight)
            {
                minweight = Dist[i];
                minindex = i;
            }
        }
        Visited[minindex] = 1;
        for(i=0 ; i<N ; i++)
        {
            if(!Visited[i] && Graph[minindex][i]!=INF && Graph[minindex][i]!=0 && Dist[i] > Dist[minindex] + Graph[minindex][i])
            {
                Dist[i] = Dist[minindex] + Graph[minindex][i];
                u[i] = u[minindex];
                if(v[i] < v[minindex] + value[i])
                {
                    v[i] = v[minindex] + value[i];
                }

            }
            else if (!Visited[i] && Graph[minindex][i]!=INF && Dist[i] == Dist[minindex] + Graph[minindex][i])
            {
                u[i] = u[minindex] + u[i];
                if(v[i] < v[minindex] + value[i])
                {
                    v[i] = v[minindex] + value[i];
                }
            }
        }
    }
}

int main()
{
    int N,M,C1,C2;
    cin>>N>>M>>C1>>C2;
    memset(Dist,0,sizeof(Dist));
    int i,j;
    for(i=0 ; i<N ; i++)
    {
        cin>>value[i];
        for(j=0 ; j<N ; j++)
            Graph[i][j] = INF;
        Graph[i][i] = 0;
    }
    int k,temp;
    for(i=0 ; i<M ; i++)
    {
        cin>>j>>k>>temp;
        Graph[j][k] = Graph[k][j] = temp;
    }
    Dijkstra(C1,N);
    cout<<u[C2]<<" "<<v[C2]<<"\n";
    return 0;
}


//他山之玉
//柳婼
/*
题目大意：n个城市m条路，每个城市有救援小组，所有的边的边权已知。给定起点和终点，求从起点到终点的最短路径条数以及最短路径上的救援小组数目之和。如果有多条就输出点权（城市救援小组数目）最大的那个~
分析：用一遍dijkstra算法。救援小组个数相当于点权，用Dijkstra求边权最小的最短路径的条数，以及这些最短路径中点权最大的值～
dis[i]：从出发点到i结点最短路径的路径长度
num[i]：从出发点到i结点最短路径的条数
w[i]：从出发点到i点救援队的数目之和
当判定dis[u] + e[u][v] < dis[v]的时候，不仅仅要更新dis[v]，还要更新num[v] = num[u], w[v] = weight[v] + w[u]; 如果dis[u] + e[u][v] == dis[v]，还要更新num[v] += num[u]，而且判断一下是否权重w[v]更小，如果更小了就更新w[v] = weight[v] + w[u];
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, c1, c2;
int e[510][510], weight[510], dis[510], num[510], w[510];
bool visit[510];
const int inf = 99999999;
int main() {
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for(int i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    int a, b, c;
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = e[b][a] = c;
    }
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;
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
                if(dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                } else if(dis[u] + e[u][v] == dis[v]) {
                    num[v] = num[v] + num[u];
                    if(w[u] + weight[v] > w[v])
                        w[v] = w[u] + weight[v];
                }
            }
        }
    }
    printf("%d %d", num[c2], w[c2]);
    return 0;
}
