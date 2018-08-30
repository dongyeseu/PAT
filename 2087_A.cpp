/*
1087 All Roads Lead to Rome（30 分）
Indeed there are many different tourist routes from our city to Rome. You are supposed to find your clients the route with the least cost 
while gaining the most happiness.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (2≤N≤200), the number of cities, and
K, the total number of routes between pairs of cities; followed by the name of the starting city. The next N−1 lines each gives the name 
of a city and an integer that represents the happiness one can gain from that city, except the starting city. Then K lines follow, each 
describes a route between two cities in the format City1 City2 Cost. Here the name of a city is a string of 3 capital English letters, and
the destination is always ROM which represents Rome.

Output Specification:
For each test case, we are supposed to find the route with the least cost. If such a route is not unique, the one with the maximum
happiness will be recommanded. If such a route is still not unique, then we output the one with the maximum average happiness -- it is 
guaranteed by the judge that such a solution exists and is unique.

Hence in the first line of output, you must print 4 numbers: the number of different routes with the least cost, the cost, the happiness, 
and the average happiness (take the integer part only) of the recommanded route. Then in the next line, you are supposed to print the 
route in the format City1->City2->...->ROM.

Sample Input:
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
Sample Output:
3 3 195 97
HZH->PRS->ROM
*/


#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <map>
#define MAXN 223
#define INF 9999999
using namespace std;
vector<int>Happiness;
vector<int>Weight;
int Graph[MAXN][MAXN] = {0};
int Path[MAXN];
int Dist[MAXN];
int Book[MAXN] = {0};

int main()
{
    int N,K;
    string start_city;
    int num = 0;
    cin>>N>>K>>start_city;
    fill(Path,Path+N,-1);
    fill(Dist,Dist+N,INF);
    Happiness.resize(N);
    Weight.resize(N);
    int Way[N] = {0};
    map<string,int>id;
    map<int,string>name;
    id[start_city] = num;
    name[num] = start_city;
    Weight[num] = Happiness[num] = 0;
    num++;
    int i,j,temp;
    string city,city2;
    for(i=0 ; i<N-1 ; i++)
    {
        cin>>city>>temp;
        id[city] = num;
        name[num] = city;
        Weight[num] = Happiness[num] = temp;
        num++;
    }
    for(i=0 ; i<K ; i++)
    {
        cin>>city>>city2>>temp;
        int j = id[city] , k = id[city2];
        Graph[j][k] = Graph[k][j] = temp;
    }
    int root = id[start_city] , ed = id["ROM"];
    fill(Way,Way+N,1);
    Dist[root] = 0;
    Book[root] = 1;
    for(i=0 ; i<N ; i++)
    {
        if(Graph[root][i] != 0)
        {
            Happiness[i] = Happiness[root] + Weight[i];
            Dist[i] = Dist[root] + Graph[root][i];
            Path[i] = root;
        }
    }
    for(i=1 ; i<N ; i++)
    {
        int minindex = 0, minweight = INF;
        for(j=0 ; j<N ; j++)
        {
            if(!Book[j] && Dist[j] < minweight)
            {
                minweight = Dist[j];
                minindex = j;
            }
        }
        Book[minindex] = 1;
        for(j=0 ; j<N ; j++)
        {
            if(!Book[j] && Graph[minindex][j] && Dist[j] > Graph[minindex][j] + Dist[minindex])
            {
                Dist[j] = Graph[minindex][j] + Dist[minindex];
                Path[j] = minindex;
                Way[j] = Way[minindex];
                Happiness[j] = Happiness[minindex] + Weight[j];
            }
            else if(!Book[j] && Graph[minindex][j] && Dist[j] == Graph[minindex][j] + Dist[minindex])
            {
                Way[j] = Way[minindex] + Way[j];
                if(Happiness[j] < Happiness[minindex] + Weight[j])
                {
                    Happiness[j] = Happiness[minindex] + Weight[j];
                    Path[j] = minindex;
                }
            }
        }
    }
    stack<string>Res;
    int z = ed;
    while(z!=-1)
    {
        city = name[z];
        Res.push(city);
        z = Path[z];
    }
    cout<<Way[ed]<<" "<<Dist[ed]<<" "<<Happiness[ed]<<" "<<Happiness[ed]/(Res.size()-1)<<"\n";
    while(true)
    {
        cout<<Res.top();
        Res.pop();
        if(!Res.empty())
        {
            cout<<"->";
        }
        else
        {
            cout<<"\n";
            break;
        }
    }
    return 0;
}

//他山之玉
//柳婼
/*
题目大意：有N个城市，M条无向边，从某个给定的起始城市出发，前往名为ROM的城市。每个城市（除了起始城市）都有一个点权（称为幸福值），和边权（每条边所需的花费）。求从起点到ROM所需要的最少花费，并输出其路径。如果路径有多条，给出幸福值最大的那条。如果仍然不唯一，选择路径上的城市平均幸福值最大的那条路径
分析：Dijkstra+DFS。Dijkstra算出所有最短路径的路线pre二维数组，DFS求最大happiness的路径path，并求出路径条数，最大happiness，最大average～
注意：average是除去起点的average。城市名称可以用m存储字符串所对应的数字，用m2存储数字对应的字符串
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
const int inf = 999999999;
int e[205][205], weight[205], dis[205];
bool visit[205];
vector<int> pre[205], temppath, path;
map<string, int> m;
map<int, string> m2;
int maxvalue = 0, mindepth, cntpath = 0;
double maxavg;
void dfs(int v) {
    temppath.push_back(v);
    if(v == 1) {
        int value = 0;
        for(int i = 0; i < temppath.size(); i++) {
            value += weight[temppath[i]];
        }
        double tempavg = 1.0 * value / (temppath.size() - 1);
        if(value > maxvalue) {
            maxvalue = value;
            maxavg = tempavg;
            path = temppath;
        } else if(value == maxvalue && tempavg > maxavg) {
            maxavg = tempavg;
            path = temppath;
        }
        temppath.pop_back();
        cntpath++;
        return ;
    }
    for(int i = 0; i < pre[v].size(); i++) {
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}
int main() {
    fill(e[0], e[0] + 205 * 205, inf);
    fill(dis, dis + 205, inf);
    scanf("%d %d", &n, &k);
    string s;
    cin >> s;
    m[s] = 1;
    m2[1] = s;
    for(int i = 1; i < n; i++) {
        cin >> s >> weight[i+1];
        m[s] = i+1;
        m2[i+1] = s;
    }
    string sa, sb;
    int temp;
    for(int i = 0; i < k; i++) {
        cin >> sa >> sb >> temp;
        e[m[sa]][m[sb]] = temp;
        e[m[sb]][m[sa]] = temp;
    }
    dis[1] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 1; j <= n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 1; v <= n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    int rom = m["ROM"];
    dfs(rom);
    printf("%d %d %d %d\n", cntpath, dis[rom], maxvalue, (int)maxavg);
    for(int i = path.size() - 1; i >= 1; i--) {
        cout << m2[path[i]] << "->";
    }
    cout << "ROM";
    return 0;
}
