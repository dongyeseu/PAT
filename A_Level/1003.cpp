#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int N,M,C1,C2;
int Graph[510][510],weight[510],dist[510],num[510],w[510];
bool visit[510];
const int INF = 999999;

int main()
{
    scanf("%d %d %d %d",&N,&M,&C1,&C2);
    for(int i=0 ; i<N ; i++)
        scanf("%d",&weight[i]); //每个城市中的救护车数量
    memset(Graph,INF,sizeof(Graph)) ; //初始化图
    fill(dist,dist+510,INF) ; //初始化每个城市的初始距离
    int a,b,c;
    for(int i=0 ; i<M ; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        Graph[a][b] = Graph[b][a] = c;
    }
    num[C1] = 1;
    dist[C1] = 0;
    w[C1] = weight[C1];
    for(int i=0 ; i<N ; i++)
    {
        int minweight = INF,minnum = -1;
        for(int j = 0 ; j <N ; j++)
        {
            if(!visit[j] && dist[j] < minweight)
            {
                minweight = dist[j];
                minnum = j;
            }
        }
        if(minnum == -1)
            break;
        visit[minnum] = true;
        for(int j = 0; j < N; j++)
        {
            if(Graph[minnum][j] != INF && !visit[j] && dist[j] > dist[minnum] + Graph[minnum][j])
            {
                dist[j] = dist[minnum] + Graph[minnum][j];
                w[j] = w[minnum] + weight[j];
                num[j] = num[minnum];
            }
            else if(Graph[minnum][j] != INF && !visit[j] && dist[j] == dist[minnum] + Graph[minnum][j])
            {
                num[j] = num[minnum] + num[j];
                if(w[j] < w[minnum] + weight[j])
                    w[j] = w[minnum] + weight[j];
            }
        }

    }
    printf("%d %d\n",num[C2],w[C2]);
    return 0;
}
