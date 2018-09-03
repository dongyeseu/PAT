/*
1090 Highest Price in Supply Chain（25 分）
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in
moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute
them in a price that is r% higher than P. It is assumed that each member in the supply chain has exactly one supplier except
the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the highest price we can expect from some retailers.

Input Specification:
Each input file contains one test case. For each case, The first line contains three positive numbers: N (≤10 the total 
number of the members in the supply chain (and hence they are numbered from 0 to N−1); P, the price given by the root 
supplier; and r, the percentage rate of price increment for each distributor or retailer. Then the next line contains N 
numbers, each number S
is the index of the supplier for the i-th member. S
for the root supplier is defined to be −1. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the highest price we can expect from some retailers, accurate up to 2 decimal places, and the number of retailers that sell at the highest price. There must be one space between the two numbers. It is guaranteed that the price will not exceed 10

Sample Input:
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
Sample Output:
1.85 2
*/

//BFS
#include <iostream>
#include <cstdio>
#include <map>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int N,root,temp,i;
    double Price,rcent;      //必须使用double，否则精度不够
    cin>>N>>Price>>rcent;
    rcent /= 100;
    map<int,vector<int>>chain;
    for(i=0 ; i<N ; i++)
    {
        cin>>temp;
        if(temp == -1)
            root = i;
        else
            chain[temp].push_back(i);
    }
    int cnt = 0;
    int num;
    queue<int>Res;
    Res.push(root);
    while(!Res.empty())
    {
        int len = Res.size();
        int j,node;
        cnt++;
        num = len;
        for(j=0 ; j<len ; j++)
        {
            node = Res.front();
            Res.pop();
            if(chain.count(node)!=0)
            {
                int z, l = chain[node].size();
                for(z=0 ; z<l ; z++)
                {
                    Res.push(chain[node][z]);
                }
            }
        }
    }
    printf("%.2f %d",Price*pow(rcent+1,cnt-1),num);
    return 0;
}


//DFS
#include <iostream>
#include <map>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
vector<vector<int>>Graph;
int maxdepth = 0;
map<int,int>Depth;
void DFS(int root,int depth)
{
    if(depth > maxdepth)
        maxdepth = depth;
    Depth[depth]++;
    for(int i=0 ; i<Graph[root].size() ; i++)
        DFS(Graph[root][i],depth+1);
}

int main()
{
    int N;
    double P,r;
    cin>>N>>P>>r;
    r = r/100;
    int Book[N] = {0};
    Graph.resize(N);
    int i,temp,root;
    for(i=0 ; i<N ; i++)
    {
        cin>>temp;
        if(temp == -1)
            root = i;
        else
            Graph[temp].push_back(i);
    }
    DFS(root,0);
    printf("%.2f %d",pow(r+1,maxdepth)*P,Depth[maxdepth]);
    return 0;

}
