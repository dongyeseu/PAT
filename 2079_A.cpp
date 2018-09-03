/*
1079 Total Sales of Supply Chain (25)（25 分）
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the total sales from all the retailers.

Input Specification:

Each input file contains one test case. For each case, the first line contains three positive numbers: N (<=10^5^), the total number of the members in the supply chain (and hence their ID's are numbered from 0 to N-1, and the root supplier's ID is 0); P, the unit price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:

K~i~ ID[1] ID[2] ... ID[K~i~]

where in the i-th line, K~i~ is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID's of these distributors or retailers. K~j~ being 0 means that the j-th member is a retailer, then instead the total amount of the product will be given after K~j~. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the total sales we can expect from all the retailers, accurate up to 1 decimal place. It is guaranteed that the number will not exceed 10^10^.

Sample Input:

10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3
Sample Output:

42.4
*/
//深度优先搜索
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

vector<vector<int>>Graph;

map<int,int>Depth;
vector<int>Book;

void DFS(int root,int depth)
{
    Depth[root] = depth;
    Book[root] = 1;
    int len = Graph[root].size() , i;
    for(i=0 ; i<len ; i++)
    {
        DFS(Graph[root][i],depth+1);
    }
}

int main()
{
    int N;
    double P,r;
    cin>>N>>P>>r;
    r = r/100;
    Graph.resize(N);
    Book.resize(N,0);
    int i,j,K,temp;
    map<int,int>Retailers;
    for(i=0 ; i<N ; i++)
    {
        cin>>K;
        if(K == 0)
        {
            cin>>temp;
            Retailers[i] = temp;
        }
        else
        {
            for(j=0 ; j<K ; j++)
            {
                cin>>temp;
                Graph[i].push_back(temp);
            }
        }
    }
    DFS(0,0);
    double total_sales = 0.0;
    for(auto z = Retailers.begin() ; z!=Retailers.end() ; z++)
    {
        int t = z->first , m = z->second;
        int d = Depth[t];
        total_sales += (m * P ) * pow(1+r,d);
    }
    printf("%.1f",total_sales);
    return 0;
}



//广度优先搜索
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int N,K,i,j,root=0,temp;
    double P,R;
    cin>>N>>P>>R;
    R  /= 100;
    map<int,vector<int>>Chain;
    map<int,int>Amount;
    for(i=0 ; i<N ; i++)
    {
        cin>>K;
        if(K==0)
        {
            scanf("%d",&temp);
            Amount[i] = temp;
        }
        else
        {
            for(j=0 ; j<K ; j++)
            {
                scanf("%d",&temp);
                Chain[i].push_back(temp);
            }
        }
    }
    queue<int>Res;
    Res.push(root);
    int cnt = 0;
    double sum = 0;
    while(!Res.empty())
    {
        cnt++;
        if(cnt!=1)
            P = P * (1 + R);
        int len = Res.size();
        for(i=0 ; i<len ;i++)
        {
            int node = Res.front();
            Res.pop();
            if(Chain.count(node)!=0)
            {
                int S = Chain[node].size();
                for(j=0 ; j<S ; j++)
                {
                    Res.push(Chain[node][j]);
                }
            }
            else
            {
                sum += P * Amount[node];
            }
        }
    }
    printf("%.1f",sum);
    return 0;

}







//他山之玉
//柳婼
/*
题目大意：给一棵树，在树根出货物的价格为p，然后从根结点开始每往下走一层，该层的货物价格将会在父亲结点的价格上增加r%，给出每个叶结点的货物量，
求他们的价格之和
分析：树的遍历，可以采用dfs或者bfs两种方法。
采用dfs，建立结构体数组保存每一个结点的孩子结点的下标，如果没有孩子结点，就保存这个叶子结点的data（销售的量）。深度优先遍历的递归出口，即当前下标
的结点没有孩子结点的时候，就把ans += data（货物量）* pow(1 + r, depth)计算货物量*价格引起的涨幅百分比。如果有孩子结点，就dfs深度优先遍历每一个孩子结点，并且在当前depth层数的基础上+1。最后输出ans * p（销售价格），即总价格。
*/
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
struct node {
    double data;
    vector<int> child;
};
vector<node> v;
double ans = 0.0, p, r;
 
void dfs(int index, int depth) {
    if(v[index].child.size() == 0) {
        ans += v[index].data * pow(1 + r, depth);
        return ;
    }
    for(int i = 0; i < v[index].child.size(); i++)
        dfs(v[index].child[i], depth + 1);
}
int main() {
    int n, k, c;
    scanf("%d %lf %lf", &n, &p, &r);
    r = r / 100;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        if(k == 0) {
            scanf("%lf", &v[i].data);
        } else {
            for(int j = 0; j < k; j++) {
                scanf("%d", &c);
                v[i].child.push_back(c);
            }
        }
    }
    dfs(0, 0);
    printf("%.1f", ans * p);
    return 0;
}
