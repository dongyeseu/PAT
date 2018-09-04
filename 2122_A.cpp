/*
1122 Hamiltonian Cycle（25 分）
The "Hamilton cycle problem" is to find a simple cycle that contains every vertex in a graph. Such a cycle is called a "Hamiltonian cycle".

In this problem, you are supposed to tell if a given cycle is a Hamiltonian cycle.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (2<N≤200), the number of vertices, and M, the number of edges in an undirected graph. Then M lines follow, each describes an edge in the format Vertex1 Vertex2, where the vertices are numbered from 1 to N. The next line gives a positive integer K which is the number of queries, followed by K lines of queries, each in the format:

where n is the number of vertices in the list, and V
​i
​​ 's are the vertices on a path.

Output Specification:
For each query, print in a line YES if the path does form a Hamiltonian cycle, or NO if not.

Sample Input:
6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
6
7 5 1 4 3 6 2 5
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 3 4 5 2 6
7 6 1 2 5 4 3 1
Sample Output:
YES
NO
NO
NO
YES
NO
*/
//复习时所作
#include <iostream>
#include <vector>
#define MAXN 210
using namespace std;

int Graph[MAXN][MAXN] = {0};
bool Hamiltonian(vector<int>Cycle,int N)
{
    int Size = Cycle.size();
    if(Size<=N)
        return false;
    if(Cycle[0] != Cycle[Size-1])
        return false;
    vector<int>Visited(N+1,0);
    int i;
    for(i=0 ; i<Size-1 ; i++)
    {
        if(!Visited[Cycle[i]] && Graph[Cycle[i]][Cycle[i+1]])
            Visited[Cycle[i]] = 1;
        else
            return false;
    }
    return true;
}
int main()
{
    int N,M,K,i,j,k;
    cin>>N>>M;
    for(i=0 ; i<M ; i++)
    {
        cin>>j>>k;
        Graph[j][k] = Graph[k][j] = 1;
    }
    cin>>K;
    for(i=0 ; i<K; i++)
    {
        vector<int>Cycle;
        int T;
        cin>>T;
        for(j=0 ; j<T ; j++)
        {
            cin>>k;
            Cycle.push_back(k);
        }
        if(Hamiltonian(Cycle,N))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}


#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define MAXN 500
using namespace std;

int Graph[MAXN][MAXN];
int Visited[MAXN];


bool PanDuan(vector<int>num,int N)
{
    int i = 0 , len = num.size();
    if(len!=N+1 || num[len-1]!=num[0])
        return false;
    while(i<len-1 && !Visited[num[i]]  )
    {
        Visited[num[i]] = 1;
        if(Graph[num[i]][num[i+1]]==1)
            i = i+1;
        else
            return false;
    }
    if(i<len-1)
        return false;
    return true;
}


/*  //测试点全部通过
bool PanDuan(vector<int>num,int j,int N)
{
    if(j!=N+1 || num[j-1]!=num[0])
        return false;
    int i;

    for(i=0 ; i<j-1 ; i++)
    {
        if(Graph[num[i]][num[i+1]] != 1)
            return false;
    }

    for(i=0 ; i<j-1 ; i++)
    {
        if(!Visited[num[i]])
            Visited[num[i]] = 1;
        else
            return false;
    }
    return true;
}
*/

int main()
{
    int N,M,K;
    cin>>N>>M;
    memset(Graph,0,sizeof(int)*MAXN*MAXN);
    int i,j,k;
    for(i=0 ; i<M ; i++)
    {
        cin>>j>>k;
        Graph[j][k] = Graph[k][j] = 1;
    }
    vector<int>Num;
    cin>>K;
    for(i=0 ; i<K ; i++)
    {
        cin>>j;
        Num.resize(j);
        int temp;
        memset(Visited,0,sizeof(int)*MAXN);
        for(k=0 ; k<j ; k++)
        {
            cin>>temp;
            Num[k] = temp;
        }
        bool res = false;
        res = PanDuan(Num,N);
        if(res)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;

}

//他山之玉
//柳婼
#include <cstdio>
#include <vector>
using namespace std;
int n, kn;
vector<int> v;
vector<vector<int>> graph;
int isConnected() {
    int pre = v[0];
    for (int i = 1; i < kn; i++) {
        if (graph[pre][v[i]] != 1) return 0;
        pre = v[i];
    }
    return 1;
}
int isHamilt() {
    if (v[0] != v[kn-1]) return 0;
    vector<int> times(kn, 0);
    for (int i = 0; i < kn; i++)
        times[v[i]]++;
    for (int i = 1; i < kn; i++)
        if ((i == v[0] && times[i] != 2) || (i != v[0] && times[i] != 1)) return 0;
    return 1;
}
int main() {
    int m, k, a, b;
    scanf("%d %d", &n, &m);
    graph.resize(n+1, vector<int>(n+1, 0));
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        graph[a][b] = graph[b][a] = 1;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &kn);
        v.resize(kn);
        for (int j = 0; j < kn; j++)
            scanf("%d", &v[j]);
        printf("%s\n", (kn == n + 1 && isConnected() && isHamilt()) ? "YES" : "NO");
    }
    return 0;
}
