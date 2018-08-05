/*
1034 Head of a Gang (30)（30 分）
One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the number of phone calls and the weight threshold, respectively. Then N lines follow, each in the following format:

Name1 Name2 Time

where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.

Output Specification:

For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names of the heads.

Sample Input 1:

8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:

2
AAA 3
GGG 3
Sample Input 2:

8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:

0
*/
//一个测试点段错误，是由于数组越界，MAXN设置太小
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
#define MAXN 1100
using namespace std;

int Graph[MAXN][MAXN];
int Visited[MAXN];
set<int>vertex; //用于记录每次遍历过程中的顶点

void DFS(int st,int N)
{
    int i;
    for(i=0 ; i<N ; i++)
    {
        if(!Visited[i] && Graph[st][i] == 1)
        {
            Visited[i] = 1;
            vertex.insert(i);
            DFS(i,N);
        }
    }
}

struct people
{
    string name;
    int wgt;
};

bool cmp(struct people a,struct people b)
{
    return a.name < b.name;
}
int main()
{
    int N,Max;
    cin>>N>>Max;
    map<string,int>Weight; //用于记录每个人总共打过多长时间电话
    int num = 0; //用于记录每个人的编号
    map<string,int>id_num;
    map<int,string>id_string; //数字和字符串编号的互相识别
    memset(Graph,0,sizeof(Graph));
    int i;
    for(i=0 ; i<N ; i++)
    {
        string a,b;
        int wei;
        cin>>a>>b>>wei;
        if(id_num.count(a)==0)
        {
            id_num[a] = num;
            id_string[num++] = a;
        }
        if(id_num.count(b)==0)
        {
            id_num[b] = num;
            id_string[num++] = b;
        }
        Weight[a] += wei;
        Weight[b] += wei;
        Graph[id_num[a]][id_num[b]] = Graph[id_num[b]][id_num[a]] = 1;
    }
    N = num; //N现在代表共有多少个顶点
    memset(Visited,0,sizeof(Visited));
    int cnt = 0;
    vector<struct people>Res;
    for(i=0 ; i<N ; i++)
    {
        if(!Visited[i])
        {
            vertex.clear();
            vertex.insert(i);
            DFS(i,N);
            auto k = vertex.begin();
            int total_weight = 0;
            int Max_weight = 0;
            string Max_num ;
            for( ; k!=vertex.end() ; k++)
            {
                string name = id_string[*k];
                total_weight += Weight[name];
                if(Weight[name] > Max_weight)
                {
                    Max_weight = Weight[name];
                    Max_num = name;
                }
            }
            total_weight /= 2;
            if(total_weight > Max && vertex.size()>2)
            {
                cnt++;
                struct people temp;
                temp.name = Max_num;
                temp.wgt = vertex.size();
                Res.push_back(temp);
            }
        }
    }
    int len = Res.size();
    sort(Res.begin(),Res.end(),cmp);
    cout<<cnt<<"\n";
    for(i=0 ; i<len ; i++)
    {
        cout<<Res[i].name<<" "<<Res[i].wgt<<"\n";
    }
    return 0;
}



#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
#define MAXN 2100
using namespace std;

vector<vector<int>>Graph(MAXN);
int Visited[MAXN];
set<int>vertex; //用于记录每次遍历过程中的顶点

void DFS(int st,int N)
{
    int i;
    int len = Graph[st].size();
    for(i=0 ; i<len ;i++)
    {
        if(!Visited[Graph[st][i]])
        {
            Visited[Graph[st][i]] = 1;
            vertex.insert(Graph[st][i]);
            DFS(Graph[st][i],N);
        }
    }
}

struct people
{
    string name;
    int wgt;
};

bool cmp(struct people a,struct people b)
{
    return a.name < b.name;
}
int main()
{
    int N,Max;
    cin>>N>>Max;
    map<string,int>Weight; //用于记录每个人总共打过多长时间电话
    int num = 0; //用于记录每个人的编号
    map<string,int>id_num;
    map<int,string>id_string; //数字和字符串编号的互相识别
    int i;
    for(i=0 ; i<N ; i++)
    {
        string a,b;
        int wei;
        cin>>a>>b>>wei;
        if(id_num.count(a)==0)
        {
            id_num[a] = num;
            id_string[num++] = a;
        }
        if(id_num.count(b)==0)
        {
            id_num[b] = num;
            id_string[num++] = b;
        }
        Weight[a] += wei;
        Weight[b] += wei;
        Graph[id_num[b]].push_back(id_num[a]);
        Graph[id_num[a]].push_back(id_num[b]);
    }
    N = num; //N现在代表共有多少个顶点
    memset(Visited,0,sizeof(Visited));
    int cnt = 0;
    vector<struct people>Res;
    for(i=0 ; i<N ; i++)
    {
        if(!Visited[i])
        {
            vertex.clear();
            vertex.insert(i);
            DFS(i,N);
            auto k = vertex.begin();
            int total_weight = 0;
            int Max_weight = 0;
            string Max_num ;
            for( ; k!=vertex.end() ; k++)
            {
                string name = id_string[*k];
                total_weight += Weight[name];
                if(Weight[name] > Max_weight)
                {
                    Max_weight = Weight[name];
                    Max_num = name;
                }
            }
            total_weight /= 2;
            if(total_weight > Max && vertex.size()>2)
            {
                cnt++;
                struct people temp;
                temp.name = Max_num;
                temp.wgt = vertex.size();
                Res.push_back(temp);
            }
        }
    }
    int len = Res.size();
    sort(Res.begin(),Res.end(),cmp);
    cout<<cnt<<"\n";
    for(i=0 ; i<len ; i++)
    {
        cout<<Res[i].name<<" "<<Res[i].wgt<<"\n";
    }
    return 0;
}






//他山之玉
//柳婼
/*
题目大意：给出1000条以内的通话记录A B和权值w，和阈值k，如果一个团伙人数超过2人并且通话总权值超过k，令团伙里面的自身权值的最大值为头目，输出所有满足条件的团伙的头目，和他们团伙里面的人数
分析：总的来说是一个判断一个图的连通分量的个数，用图的遍历解决，深度优先遍历。
1.因为给的是字母，要用两个map把它们转换成数字，从1开始排列命名所有不同的人的id，存储在两个map里面，一个字符串对应id，一个id对应字符串，方便查找，正好顺便统计了总共的人数idNumber。
2.建立两个数组，weight和G，分别存储每条边的权值和每个结点的权值，因为这两个题目中都要求得后判断。
3.用传递引用的方法深度优先dfs，这样传入的参数在dfs后还能保存想要求得的值
4.遍历过一条边之后就把这条边的权值设为0（ G[u][v] = G[v][u] = 0;）防止出现回路遍历死循环
*/
#include <iostream>
#include <map>
using namespace std;
map<string, int> stringToInt;
map<int, string> intToString;
map<string, int> ans;
int idNumber = 1, k;
int stoifunc(string s) {
    if(stringToInt[s] == 0) {
        stringToInt[s] = idNumber;
        intToString[idNumber] = s;
        return idNumber++;
    } else {
        return stringToInt[s];
    }
}
int G[2010][2010], weight[2010];
bool vis[2010];
void dfs(int u, int &head, int &numMember, int &totalweight) {
    vis[u] = true;
    numMember++;
    if(weight[u] > weight[head])
        head = u;
    for(int v = 1; v < idNumber; v++) {
        if(G[u][v] > 0) {
            totalweight += G[u][v];
            G[u][v] = G[v][u] = 0;
            if(vis[v] == false)
                dfs(v, head, numMember, totalweight);
        }
    }
}
void dfsTrave() {
    for(int i = 1; i < idNumber; i++) {
        if(vis[i] == false) {
            int head = i, numMember = 0, totalweight = 0;
            dfs(i, head, numMember, totalweight);
            if(numMember > 2 && totalweight > k)
                ans[intToString[head]] = numMember;
        }
    }
}
int main() {
    int n, w;
    cin >> n >> k;
    string s1, s2;
    for(int i = 0; i < n; i++) {
        cin >> s1 >> s2 >> w;
        int id1 = stoifunc(s1);
        int id2 = stoifunc(s2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    dfsTrave();
    cout << ans.size() << endl;
    for(auto it = ans.begin(); it != ans.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}
