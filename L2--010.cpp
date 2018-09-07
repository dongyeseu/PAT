/*
布置宴席最微妙的事情，就是给前来参宴的各位宾客安排座位。无论如何，总不能把两个死对头排到同一张宴会桌旁！这个艰巨任务现在就交给你，对任何一对客人，请编写程序告诉主人他们是否能被安排同席。

输入格式：
输入第一行给出3个正整数：N（≤100），即前来参宴的宾客总人数，则这些人从1到N编号；M为已知两两宾客之间的关系数；K为查询的条数。随后M行，每行给出一对宾客之间的关系，格式为：宾客1 宾客2 关系，其中关系为1表示是朋友，-1表示是死对头。注意两个人不可能既是朋友又是敌人。最后K行，每行给出一对需要查询的宾客编号。

这里假设朋友的朋友也是朋友。但敌人的敌人并不一定就是朋友，朋友的敌人也不一定是敌人。只有单纯直接的敌对关系才是绝对不能同席的。

输出格式：
对每个查询输出一行结果：如果两位宾客之间是朋友，且没有敌对关系，则输出No problem；如果他们之间并不是朋友，但也不敌对，则输出OK；如果他们之间有敌对，然而也有共同的朋友，则输出OK but...；如果他们之间只有敌对关系，则输出No way。

输入样例：
7 8 4
5 6 1
2 7 -1
1 3 1
3 4 1
6 7 -1
1 2 1
1 4 1
2 3 -1
3 4
5 7
2 3
7 2
输出样例：
No problem
OK
OK but...
No way
*/

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
int Father[10010] = {0};
void Init()
{
    for(int i=0 ; i<10010 ; i++)
        Father[i] = i;
}
int FindFather(int i)
{
    int x = i;
    while(x!=Father[x])
        x = Father[x];
    int z = i,a;
    while(z!=Father[z])
    {
        a = Father[z];
        Father[z] = x;
        z = a;
    }
    return x;
}
void Union(int x,int y)
{
    int a= FindFather(x);
    int b = FindFather(y);
    if(a != b)
        Father[a] = b;
    return;
}

int main()
{
    int N,M,K;
    cin>>N>>M>>K;
    Init();
    int A,B,relation;
    int Relation[N+1][N+1];
    memset(Relation,0,sizeof(Relation));
    for(int i=0 ; i<M ; i++)
    {
        cin>>A>>B>>relation;
        Relation[A][B] = Relation[B][A] = relation;
        if(relation == 1)
        {
            Union(A,B);
        }
    }
    for(int i=0 ; i<K ;i++)
    {
        cin>>A>>B;
        if(Relation[A][B] == 1)
            cout<<"No problem\n";
        else if(Relation[A][B] == 0)
            cout<<"OK\n";
        else if(Relation[A][B] == -1 && FindFather(A) == FindFather(B))
        {
            cout<<"OK but...\n";
        }
        else
            cout<<"No way\n";
    }
    return 0;
}
