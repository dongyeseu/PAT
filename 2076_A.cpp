/*
1076 Forwards on Weibo (30)（30 分）
Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. 
Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and 
forward his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate 
the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=1000), the number of users;
and L (<=6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 
to N. Then N lines follow, each in the format:

M[i] user_list[i]

where M[i] (<=100) is the total number of people that user[i] follows; and user_list[i] is a list of the M[i] users that are followed
by user[i]. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.

Then finally a positive K is given, followed by K UserID's for query.

Output Specification:

For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can triger, assuming that 
everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted.


Sample Input:

7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
Sample Output:

4
5
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#define MAXN 1010
using namespace std;

vector<vector<int>>Graph;
int N,L;

void BFS(int root)
{
    vector<bool>Visited(N+1,false);
    queue<int>Res;
    int level=0; //顶点所在的层
    Res.push(root);
    Visited[root] = true;
    int cnt = 0;
    while(!Res.empty())
    {
        level++;
        if(level>L)
            break;
        int Size = Res.size();
        int i;
        for(i=0 ; i<Size ; i++)
        {
            int node = Res.front();
            Res.pop();
            for(auto c : Graph[node])
            {
                if(!Visited[c])
                {
                    cnt++;
                    Res.push(c);
                    Visited[c] = true;
                }
            }
        }
    }
    cout<<cnt<<"\n";
}

int main()
{
    scanf("%d %d",&N,&L);
    Graph.resize(N+1);
    int K,i,j,num,temp;
    for(i=1 ; i<=N ; i++) //建立图
    {
        cin>>temp;
        for(j=0 ; j<temp ; j++)
        {
            scanf("%d",&num);
            Graph[num].push_back(i);
        }
    }
    cin>>K;
    for(i=0 ; i<K ; i++)
    {
        scanf("%d",&num); //查询的根
        BFS(num);
    }
    return 0;

}


//他山之玉
//柳婼
/*
题目大意：给出每个用户关注的人的id，和转发最多的层数，求一个id发了条微博最多会有多少个人转发
分析：带层数的广度优先，因为一个用户只能转发一次，所以用inq判断当前结点是否入队过了，如果入队过了就不能重复入队（重复转发消息），inq 邻接表v 都
可以使用int只存储id，queue的数据类型必须为node，同时保存它的id和layer层数，控制不超过L层~~
*/
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int n, l, m, k;
struct node {
    int id, layer;
};
vector<vector<int>> v;
int bfs(node tnode) {
    bool inq[1010] = {false};
    queue<node> q;
    q.push(tnode);
    inq[tnode.id] = true;
    int cnt = 0;
    while(!q.empty()) {
        node top = q.front();
        q.pop();
        int topid = top.id;
        for(int i = 0; i < v[topid].size(); i++) {
            int nextid = v[topid][i];
            if(inq[nextid] == false && top.layer < l) {
                node next = {nextid, top.layer + 1};
                q.push(next);
                inq[next.id] = true;
                cnt++;
            }
        }
    }
    return cnt;
}
 
int main() {
    scanf("%d %d", &n, &l);
    v.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            int temp;
            scanf("%d", &temp);
            v[temp].push_back(i);
        }
    }
    scanf("%d", &k);
    int tid;
    for(int i = 0; i < k; i++) {
        scanf("%d", &tid);
        node tnode = {tid, 0};
        printf("%d\n", bfs(tnode));
    }
    return 0;
}
