/*
本题是一部战争大片 —— 你需要从己方大本营出发，一路攻城略地杀到敌方大本营。首先时间就是生命，所以你必须选择合适的路径，以最快的速度占领敌方大本营。当这样的路径不唯一时，要求选择可以沿途解放最多城镇的路径。若这样的路径也不唯一，则选择可以有效杀伤最多敌军的路径。

输入格式：
输入第一行给出 2 个正整数 N（2 ≤ N ≤ 200，城镇总数）和 K（城镇间道路条数），以及己方大本营和敌方大本营的代号。随后 N-1 行，每行给出除了己方大本营外的一个城镇的代号和驻守的敌军数量，其间以空格分隔。再后面有 K 行，每行按格式城镇1 城镇2 距离给出两个城镇之间道路的长度。这里设每个城镇（包括双方大本营）的代号是由 3 个大写英文字母组成的字符串。

输出格式：
按照题目要求找到最合适的进攻路径（题目保证速度最快、解放最多、杀伤最强的路径是唯一的），并在第一行按照格式己方大本营->城镇1->...->敌方大本营输出。第二行顺序输出最快进攻路径的条数、最短进攻距离、歼敌总数，其间以 1 个空格分隔，行首尾不得有多余空格。

输入样例：
10 12 PAT DBY
DBY 100
PTA 20
PDS 90
PMS 40
TAP 50
ATP 200
LNN 80
LAO 30
LON 70
PAT PTA 10
PAT PMS 10
PAT ATP 20
PAT LNN 10
LNN LAO 10
LAO LON 10
LON DBY 10
PMS TAP 10
TAP DBY 10
DBY PDS 10
PDS PTA 10
DBY ATP 10
输出样例：
PAT->PTA->PDS->DBY
3 30 210
*/
#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <stack>
#define MAXN 210
#define INF 9999999
using namespace std;

int Graph[MAXN][MAXN] = {0};
int Dist[MAXN];
int Path[MAXN];
int Weight[MAXN];
int Enemy[MAXN];
int view[MAXN];
int Num[MAXN];
int Visited[MAXN] = {0};
vector<vector<int>>Pre;
int main()
{
    int N,K;
    string start,ed;
    cin>>N>>K>>start>>ed;
    fill(Path,Path+N,-1);
    fill(view,view+N,1);
    fill(Dist,Dist+N,INF);
    fill(Num,Num+N,1);
    map<string,int>ID;
    map<int,string>Name;
    int num = 0;
    ID[start] = num;
    Name[num++] = start;
    ID[ed] = num;
    Name[num++] = ed;
    string city;
    int T;
    for(int i=1 ; i<N ; i++)
    {
        cin>>city>>T;
        if(ID.count(city) == 0)\
        {
            ID[city] = num;
            Name[num++] = city;
        }
        Weight[ID[city]] = T;
    }
    string city_1,city_2;
    int d;
    for(int i=0 ; i<K ; i++)
    {
        cin>>city_1>>city_2>>d;
        int t1 = ID[city_1] , t2 = ID[city_2];
        Graph[t1][t2] = Graph[t2][t1] = d;
    }
    int root = ID[start];
    Dist[root] = 0;
    Weight[root] = 0;
    Enemy[root] = 0;
    Visited[root] = 1;
    Num[root] = 1;
    for(int i=0 ; i<N ; i++)
    {
        if(Graph[root][i] != 0)
        {
            Dist[i] = Dist[root] + Graph[root][i];
            Path[i] = root;
            Enemy[i] = Enemy[root] + Weight[i];
        }
    }
    for(int i=1 ; i<N ; i++)
    {
        int minindex = -1, mindist = INF;
        for(int j=0 ; j<N ; j++)
        {
            if(!Visited[j] && Dist[j] < mindist)
            {
                minindex = j;
                mindist = Dist[j];
            }
        }
        if(minindex == -1)
            break;
        Visited[minindex] = 1;
        for(int j=0 ; j<N ; j++)
        {
            if(!Visited[j] && Graph[minindex][j]!=0 && Dist[j] > Dist[minindex]+Graph[minindex][j])
            {
                Dist[j] = Dist[minindex] + Graph[minindex][j];
                Enemy[j]= Enemy[minindex] + Weight[j];
                Num[j] = Num[minindex];
                view[j] = view[minindex] + 1;
                Path[j] = minindex;
            }
            else if(!Visited[j] && Graph[minindex][j] != 0 && Dist[j] == Dist[minindex] + Graph[minindex][j])
            {
                Num[j] = Num[minindex] + Num[j];
                if(view[j] < view[minindex] + 1)
                {
                    view[j] = view[minindex] + 1;
                    Path[j] = minindex;
                    Enemy[j] = Enemy[minindex] + Weight[j];
                }
                else if(view[j] == view[minindex] + 1)
                {
                    if(Enemy[j] < Enemy[minindex] + Weight[j])
                    {
                        Enemy[j] = Enemy[minindex] + Weight[j];
                        Path[j] = minindex;
                    }
                }
            }
        }
    }
    int over = ID[ed];
    stack<int>Res;
    int z = over;
    while(z!=-1)
    {
        Res.push(z);
        z = Path[z];
    }
    while(true)
    {
        z = Res.top();
        Res.pop();
        cout<<Name[z];
        if(!Res.empty())
            cout<<"->";
        else
        {
            cout<<"\n";
            break;
        }
    }
    cout<<Num[over]<<" "<<Dist[over]<<" "<<Enemy[over]<<"\n";
    return 0;
}




总结：
1.关于城市名称和结点数字的一一对应可以通过map来实现
2.初始化问题，对于所有的Dist初始化为无穷大，所有的Path初始化为-1（方便最后遍历找到根节点)，最短路径数目Num【】全部初始化为1,经过城
市的权值和初始化为0，然后在Dijkstra之前再初始化一次，将第一次能够达到的城市的值赋值上去，经过的城市数量初始化为1，Graph初始化为0
3.在Dijkstra过程中对所有的判断条件进行判断
根据条件的优先级一一进行判断
首先是Dist
其后是经过的城市数量
最后是消灭的敌人数量
在判断过程中不断更新
4.最后通过stack找到最优路径









