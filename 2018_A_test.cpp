/*
There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. One may rent 
a bike at any station and return it to any other stations in the city.

The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. A station is said to be in perfect
condition if it is exactly half-full. If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that 
station to perfect. And more, all the stations on the way will be adjusted as well.

When a problem station is reported, PBMC will always choose the shortest path to reach that station. If there are more than one shortest
path, the one that requires the least number of bikes sent from PBMC will be chosen.
Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. The 
judge's data guarantee that such a path is unique.

Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
Sample Output:
3 0->2->3 0
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#define MAXN 510
#define INF 999999
using namespace std;
vector<int>BikeNum;
int Graph[MAXN][MAXN];
int Dist[MAXN];
int Book[MAXN] = {0};
vector<vector<int>>Path;
vector<int>Res,temppath;
int minneed = INF,need,minback = INF ,bck;
void DFS(int ed)
{
    temppath.push_back(ed);
    int i;
    if(ed == 0)
    {
       int need = 0 , bck = 0;
       for(i=temppath.size()-1 ; i>=0 ; i--)
       {
           int id = temppath[i];
           if(BikeNum[id] > 0)
           {
               bck += BikeNum[id];
           }
           else if(BikeNum[id] < 0)
           {
               if(bck > (0 - BikeNum[id]))
                    bck += BikeNum[id];
               else
               {
                    need += (0 - BikeNum[id] - bck);
                    bck = 0;
               }
           }
       }
       if(need < minneed)
       {
           minneed = need;
           minback = bck;
           Res = temppath;
       }
       else if(need == minneed && bck < minback)
       {
           minback = bck;
           Res = temppath;
       }
       temppath.pop_back();
       return;
    }
    for(i=0 ; i<Path[ed].size() ; i++)
        DFS(Path[ed][i]);
    temppath.pop_back();
}

int main()
{
    int Cmax,N,Sp,M; // Camx: is the maximum capacity of each station ;  N :the number of stations ; Sp : the index of the problem station ; M : the number of station
    cin>>Cmax>>N>>Sp>>M;
    BikeNum.resize(N+1);
    Path.resize(N+1);
    fill(Dist,Dist+N+1,INF);//Initialization
    BikeNum[0] = 0;
    int i,j,k,temp;
    for(i=1 ; i<=N ; i++)
    {
        cin>>BikeNum[i];
        BikeNum[i] = BikeNum[i] - (Cmax/2);
    }
    for(i=0 ; i<M ; i++)
    {
        cin>>j>>k>>temp;
        Graph[j][k] = Graph[k][j] = temp;
    }
    Dist[0] = 0;
    Book[0] = 1;
    for(i=0 ; i<=N ; i++)
    {
        if(Graph[0][i])
        {
            Dist[i] = Graph[0][i] + Dist[0];
            Path[i].push_back(0);
        }
    }
    for(i=0 ; i<N ; i++)
    {
        int minindex = -1,minweight = INF;
        for(j=0 ; j<=N ; j++)
        {
            if(!Book[j] && Dist[j] < minweight)
            {
                minweight = Dist[j];
                minindex = j;
            }
        }
        if(minindex == -1)
            break;
        Book[minindex] = 1;
        for(j=0 ; j<=N ; j++)
        {
            if(!Book[j] && Graph[minindex][j] && Dist[j] > Dist[minindex] + Graph[minindex][j])
            {
                Dist[j] = Dist[minindex] + Graph[minindex][j];
                Path[j].clear();
                Path[j].push_back(minindex);
            }
            else if(!Book[j] && Graph[minindex][j] && Dist[j] == Dist[minindex] + Graph[minindex][j])
            {
                Path[j].push_back(minindex);
            }
        }
    }
    DFS(Sp);
    cout<<minneed<<" ";
    for(i=Res.size()-1 ; i>=0 ; i--)
    {
        if(i==0)
            cout<<Res[i]<<" ";
        else
            cout<<Res[i]<<"->";
    }
    cout<<minback<<"\n";
    return 0;

}

