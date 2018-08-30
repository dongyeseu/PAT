/*
In the big cities, the subway systems always look so complex to the visitors. To give you some sense, the following figure shows the map of Beijing subway. Now you are supposed to help people with your computer skills! Given the starting position of your user, your task is to
find the quickest way to his/her destination.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤ 100), the number of subway lines.
Then N lines follow, with the i-th (i=1,⋯,N) line describes the i-th subway line in the format:
M S[1] S[2] ... S[M]
where M (≤ 100) is the number of stops, and S[i]'s (i=1,⋯,M) are the indices of the stations (the indices are 4-digit numbers from 0000
to 9999) along the line. It is guaranteed that the stations are given in the correct order -- that is, the train travels between S[i] 
and S[i+1] (i=1,⋯,M−1) without any stop.

Note: It is possible to have loops, but not self-loop (no train starts from S and stops at S without passing through another station).
Each station interval belongs to a unique subway line. Although the lines may cross each other at some stations (so called "transfer
stations"), no station can be the conjunction of more than 5 lines.

After the description of the subway, another positive integer K (≤ 10) is given. Then K lines follow, each gives a query from your 
user: the two indices as the starting station and the destination, respectively.
The following figure shows the sample map.
Note: It is guaranteed that all the stations are reachable, and all the queries consist of legal station numbers.

Output Specification:
For each query, first print in a line the minimum number of stops. Then you are supposed to show the optimal path in a friendly format 
as the following:
Take Line#X1 from S1 to S2.
Take Line#X2 from S2 to S3.
......
where Xi's are the line numbers and Si's are the station indices. Note: Besides the starting and ending stations, only the transfer 
stations shall be printed.

If the quickest path is not unique, output the one with the minimum number of transfers, which is guaranteed to be unique.

Sample Input:
4
7 1001 3212 1003 1204 1005 1306 7797
9 9988 2333 1204 2006 2005 2004 2003 2302 2001
13 3011 3812 3013 3001 1306 3003 2333 3066 3212 3008 2302 3010 3011
4 6666 8432 4011 1306
3
3011 3013
6666 2001
2004 3001
Sample Output:
2
Take Line#3 from 3011 to 3013.
10
Take Line#4 from 6666 to 1306.
Take Line#3 from 1306 to 2302.
Take Line#2 from 2302 to 2001.
6
Take Line#2 from 2004 to 1204.
Take Line#1 from 1204 to 1306.
Take Line#3 from 1306 to 3001.
*/



#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cstdio>
using namespace std;
vector<vector<int>>Graph(10000);
vector<int>Book;
vector<int>Path,temppath;
map<string,int>id;
map<int,string>name;
set<string>stations;
map<int,vector<int>>transfers;
set<int>R;
int minans = 99999,ans = 0;
int minway = 99999,way = 0;
void DFS(int start,int ed)
{
    int i,j;
    if(ed == start)
    {
        way = 0 , ans = 0;
        for(i=0 ; i<temppath.size() ; i++)
        {
            way++;
            if(transfers[temppath[i]].size() == 2)
                ans++;
        }
        if(way < minway)
        {
            minway = way;
            minans = ans;
            Path = temppath;
        }
        else if(way == minway && ans < minans)
        {
            minans = ans;
            Path = temppath;
        }
    }
    if(ed == start)
        return;
    for(i=0 ; i<Graph[start].size() ; i++)
    {
        if(!Book[Graph[start][i]])
        {
            Book[Graph[start][i]] = 1;
            temppath.push_back(Graph[start][i]);
            DFS(Graph[start][i],ed);
            Book[Graph[start][i]] = 0;
            temppath.pop_back();
        }
    }
}

void Initialization(vector<int>&Book)
{
    int len = Book.size();
    int i;
    for(i=0 ; i<len ; i++)
        Book[i] = 0;
}

int main()
{
    int N;
    cin>>N;
    int K,i,j,num = 0;
    string temp;
    for(i=0 ; i<N ; i++)
    {
        cin>>K;
        vector<int>lines;
        for(j=0 ; j<K ; j++)
        {
            cin>>temp;
            if(stations.count(temp) == 0)
            {
                id[temp] = num;
                name[num] = temp;
                stations.insert(temp);
                num++;
            }
            transfers[id[temp]].push_back(i+1);
            lines.push_back(id[temp]);
        }
        for(j=1 ; j<K ; j++)
        {
            int m = lines[j] , n = lines[j-1];
            Graph[m].push_back(n);
            Graph[n].push_back(m);
        }
    }
    int M = stations.size();
    Book.resize(M);
    cin>>K;
    for(i=0 ; i<K ; i++)
    {
        string start_station,destination;
        cin>>start_station>>destination;
        Path.clear();
        temppath.clear();
        R.clear();
        int start = id[start_station] , ed = id[destination];
        Initialization(Book);
        minans =999999,minway = 999999;
        temppath.push_back(start);
        Book[start] = 1;
        DFS(start,ed);
        cout<<Path.size()-1<<"\n";
        int before=start;
        for(j=0 ; j<Path.size() ; j++)
        {
            cout<<name[Path[j]]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}


//他山之玉
//柳婼
/*
分析：【很简单的，别跑^_^】一遍DFS即可～DFS过程中要维护两个变量：minCnt-中途经停的最少的站; minTransfer-需要换乘的最小次数～
0.可以这样计算出一条线路的换乘次数：在line[10000][10000]的数组中保存每两个相邻站中间的线路是几号线～从头到尾遍历最终保存的路径，preLine为前一小段的
线路编号，如果当前的结点和前一个结点组成的这条路的线路编号和preLine不同，说明有一个换乘，就将cnt+1，最后遍历完累加的cnt即是换乘的次数～
update：由于新的PAT系统中会显示原解法有一个测试用例内存超限，考虑到line[10000][10000]存储的方式太暴力了，所以将line换成了unordered_map<int, int>
line存储的方式，第一个int用来存储线路，每次将前四位存储第一个线路，后四位存储第二个线路，使用a[i-1]*10000+a[i]的方式存储，第二个int用来保存两个相邻
中间的线路是几号线～
1.可以这样计算出一条线路中途停站的次数：在dfs的时候有个变量cnt，表示当前路线是所需乘的第几个站，每次dfs时候将cnt+1表示向下遍历一层～cnt就是当前中
途停站的次数～
2.可以这样输出结果：和计算线路换乘次数的思路一样，每当preLine和当前Line值不同的时候就输出一句话～保存preTransfer表示上一个换乘站，最后不要忘记输
出preTransfer和最后一个站之间的路即使最后一个站并不是换乘站～
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<vector<int>> v(10000);
int visit[10000], minCnt, minTransfer, start, end1;
unordered_map<int, int> line;
vector<int> path, tempPath;
int transferCnt(vector<int> a) {
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i-1]*10000+a[i]] != preLine) cnt++;
        preLine = line[a[i-1]*10000+a[i]];
    }
    return cnt;
}
void dfs(int node, int cnt) {
    if (node == end1 && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer))) {
        minCnt = cnt;
        minTransfer = transferCnt(tempPath);
        path = tempPath;
    }
    if (node == end1) return;
    for (int i = 0; i < v[node].size(); i++) {
        if (visit[v[node][i]] == 0) {
            visit[v[node][i]] = 1;
            tempPath.push_back(v[node][i]);
            dfs(v[node][i], cnt + 1);
            visit[v[node][i]] = 0;
            tempPath.pop_back();
        }
    }
}
int main() {
    int n, m, k, pre, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &m, &pre);
        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre*10000+temp] = line[temp*10000+pre] = i + 1;
            pre = temp;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &start, &end1);
        minCnt = 99999, minTransfer = 99999;
        tempPath.clear();
        tempPath.push_back(start);
        visit[start] = 1;
        dfs(start, 0);
        visit[start] = 0;
        printf("%d\n", minCnt);
        int preLine = 0, preTransfer = start;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j-1]*10000+path[j]] != preLine) {
                if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);
                preLine = line[path[j-1]*10000+path[j]];
                preTransfer = path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end1);
    }
    return 0;
}
