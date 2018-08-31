/*
1013 Battle Over Cities (25)（25 分）
It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.

For example, if we have 3 cities and 2 highways connecting city~1~-city~2~ and city~1~-city~3~. Then if city~1~ is occupied by the enemy, we must have 1 highway repaired, that is the highway city~2~-city~3~.

Input

Each input file contains one test case. Each case starts with a line containing 3 numbers N (&lt1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.

Output

For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.

Sample Input

3 2 3
1 2
1 3
1 2 3
Sample Output

1
0
0
*/


// 思路 ： DFS & 连通分量
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#define MAXN 1010
using namespace std;

int Graph[MAXN][MAXN];  //图存储结构
int Graph_2[MAXN][MAXN];
vector<int>Visited; //记录结点是否走过

void Initialize(vector<int>&V)
{
    int len = V.size();
    int i;
    for(i=0 ; i<len ; i++)
        V[i] = 0;
}

void DFS(int st,int N)         //深度优先搜索
{
    int i;
    for(i=1 ; i<=N ; i++)
    {
        if(!Visited[i] && Graph_2[st][i]==1)
        {
            Visited[i] = 1;
            DFS(i,N);
        }
    }
}

int main()
{
    int N,M,K ; //the total number of cities, the number of remaining highways, and the number of cities to be checked
    cin>>N>>M>>K;
    int check[K];
    Visited.resize(N+1);
    memset(Graph,0,sizeof(int)*MAXN*MAXN);
    Initialize(Visited);
    int i,j,k;
    for(i=0 ; i<M ; i++)
    {
        scanf("%d %d",&j,&k);
        Graph[j][k] = Graph[k][j] = 1;
    }
    for(i=0 ; i<K ; i++)
    {
        scanf("%d",&j);
        check[i] = j;
    }
    int cnt;
    for(j=0 ; j<K ; j++)
    {
        cnt = 0;
        memcpy(Graph_2,Graph,sizeof(Graph));      //数组的复制
        int temp = check[j];
        for(i=1 ; i<=N ; i++)
            Graph_2[temp][i] = Graph_2[i][temp] = 0;
        for(i=1 ; i<=N ; i++)
        {
            if(!Visited[i])       //连通分支数量
            {
                Visited[i] = 1;
                DFS(i,N);
                cnt++;
            }
        }
        cout<<cnt-2<<"\n";    //确实要减2，第一需要减去temp需要占的那个连通分支，其次剩下的n个连通分支数量之间需要n-1条路
        Initialize(Visited);
    }
    return 0;

}



//他山之玉
//柳婼
/*
题目大意：给出n个城市之间有相互连接的m条道路，当删除一个城市和其连接的道路的时候，问其他几个剩余的城市至少要添加多少个路线才能让它们重新变为连通图
分析：添加的最少的路线，就是他们的连通分量数-1，因为当a个互相分立的连通分量需要变为连通图的时候，只需要添加a-1个路线，就能让他们相连。所以这道题就是求去除了某个结点之后其他的图所拥有的连通分量数
使用邻接矩阵存储，对于每一个被占领的城市，去除这个城市结点，就是把它标记为已经访问过，这样在深度优先遍历的时候，对于所有未访问的结点进行遍历，就能求到所有的连通分量的个数~~~记得因为有很多个要判断的数据，每一次输入被占领的城市之前要把visit数组置为false~~~~
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int v[1010][1010];
bool visit[1010];
int n;
void dfs(int node) {
    visit[node] = true;
    for(int i = 1; i <= n; i++) {
        if(visit[i] == false && v[node][i] == 1)
            dfs(i);
    }
}
int main() {
    int m, k, a, b;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a][b] = v[b][a] = 1;
    }
    for(int i = 0; i < k; i++) {
        fill(visit, visit + 1010, false);
        scanf("%d", &a);
        int cnt = 0;
        visit[a] = true;
        for(int j = 1; j <= n; j++) {
            if(visit[j] == false) {
                dfs(j);
                cnt++;
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}

//他山之玉
//思路：并查集
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<unordered_map>
#include<cstring>

using namespace std;

const int maxn = 1005;
int mapx[maxn * maxn][2];
int pre[maxn];

int Find(int x)
{
    return pre[x] == x ? x : pre[x] = Find(pre[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y) return;
    pre[y] = x;
}

int main()
{
    int n, m, k, sum;
    cin >> n >> m >> k;
    memset(mapx, 0, sizeof(mapx));
    for (int i = 0; i < m; i++)
    {
        cin >> mapx[i][0] >> mapx[i][1];
    }

    int city;
    while (k--)
    {
        cin >> city;
        for (int i = 0; i <= n; i++)
        {
            pre[i] = i;
        }

        for (int i = 0; i < m; i++)
        {
            if (mapx[i][0] != city && mapx[i][1] != city)
                Union(mapx[i][0], mapx[i][1]);
        }

        sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (pre[i] == i && i != city)
                sum++;
        }

        cout << sum - 1 << endl;
    }
    return 0;
}
