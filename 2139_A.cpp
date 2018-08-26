/*
1139 First Contact（30 分）
Unlike in nowadays, the way that boys and girls expressing their feelings of love was quite subtle in the early years. When a boy A had a crush on a girl B, he would usually not contact her directly in the first place. Instead, he might ask another boy C, one of his close friends, to ask another girl D, who was a friend of both B and C, to send a message to B -- quite a long shot, isn't it? Girls would do analogously.

Here given a network of friendship relations, you are supposed to help a boy or a girl to list all their friends who can possibly help them making the first contact.

Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers N (1 < N ≤ 300) and M, being the total number of people and the number of friendship relations, respectively. Then M lines follow, each gives a pair of friends. Here a person is represented by a 4-digit ID. To tell their genders, we use a negative sign to represent girls.

After the relations, a positive integer K (≤ 100) is given, which is the number of queries. Then K lines of queries follow, each gives a pair of lovers, separated by a space. It is assumed that the first one is having a crush on the second one.

Output Specification:
For each query, first print in a line the number of different pairs of friends they can find to help them, then in each line print the IDs of a pair of friends.

If the lovers A and B are of opposite genders, you must first print the friend of A who is of the same gender of A, then the friend of B, who is of the same gender of B. If they are of the same gender, then both friends must be in the same gender as theirs. It is guaranteed that each person has only one gender.

The friends must be printed in non-decreasing order of the first IDs, and for the same first ones, in increasing order of the seconds ones.

Sample Input:
10 18
-2001 1001
-2002 -2001
1004 1001
-2004 -2001
-2003 1005
1005 -2001
1001 -2003
1002 1001
1002 -2004
-2004 1001
1003 -2002
-2003 1003
1004 -2002
-2001 -2003
1001 1003
1003 -2001
1002 -2001
-2002 -2003
5
1001 -2001
-2003 1001
1005 -2001
-2002 -2004
1111 -2003
Sample Output:
4
1002 2004
1003 2002
1003 2003
1004 2002
4
2001 1002
2001 1003
2002 1003
2002 1004
0
1
2003 2001
0
*/
#include <vector>
#include <map>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
using namespace std;

struct node
{
    int first_friend;
    int second_friend;
};

bool cmp(struct node a,struct node b) //结果排序方式
{
    if(abs(a.first_friend) != abs(b.first_friend))
        return abs(a.first_friend) < abs(b.first_friend);
    else
        return abs(a.second_friend )<abs(b.second_friend);
}

vector<vector<int>>Graph;

int main()
{
    int N,K,M,i,j;
    scanf("%d %d",&N,&K);
    map<int,int>Name_num;
    map<int,int>Name_string;
    Graph.resize(N);
    int id = 0,name_1,name_2;
    string n1,n2;
    for(i=0 ; i<K ; i++)
    {
        cin>>n1>>n2;
        name_1 = stoi(n1),name_2 = stoi(n2);
        if(name_1 == 0)
        {
            if(n1[0] == '-')
                name_1 = -10000;
        }
        if(name_2 == 0)
        {
            if(n2[0] == '-')
                name_2 = -10000;
        }
        if(Name_string.find(name_1)==Name_string.end())
        {
            Name_num[id] = name_1;
            Name_string[name_1] = id++;
        }
        if(Name_string.find(name_2)==Name_string.end())
        {
            Name_num[id] = name_2;
            Name_string[name_2] = id++;
        }
        Graph[Name_string[name_2]].push_back(Name_string[name_1]);
        Graph[Name_string[name_1]].push_back(Name_string[name_2]);
    }
    cin>>M;
    for(i=0 ; i<M ; i++)
    {
        cin>>n1>>n2;
        name_1 = stoi(n1),name_2 = stoi(n2);
        if(name_1 == 0)
        {
            if(n1[0] == '-')
                name_1 = -10000;
        }
        if(name_2 == 0)
        {
            if(n2[0] == '-')
                name_2 = -10000;
        }
        vector<struct node>Res;
        if(Name_string.find(name_1)==Name_string.end() || Name_string.find(name_2)==Name_string.end() )
        {
            cout<<0<<"\n";
            continue;
        }
        int id_1 = Name_string[name_1] , id_2 = Name_string[name_2];
        for(auto c:Graph[id_1])
        {
            if((Name_num[c]<0&&name_1<0) || (Name_num[c]>=0&&name_1>=0))
            {
                for(auto d : Graph[id_2])
                {
                    if(c==id_2 || d ==id_1)
                            continue;
                    if((Name_num[d]<0&&name_2<0) || (Name_num[d]>=0&&name_2>=0))
                    {
                        for(auto e : Graph[c])
                        {
                            if(e == d)
                            {
                                struct node temp;
                                temp.first_friend = Name_num[c]==-10000?0:Name_num[c];
                                temp.second_friend = Name_num[d]==-10000?0:Name_num[d];
                                Res.push_back(temp);
                            }
                        }
                    }
                }
            }
        }
        int S = Res.size();
        cout<<S<<"\n";
        sort(Res.begin(),Res.end(),cmp);
        for(j=0 ; j<S ; j++)
        {
            printf("%04d %04d\n",abs(Res[j].first_friend),abs(Res[j].second_friend));
        }
    }
    return 0;
}


//思路二
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

struct node
{
    int first_friend;
    int second_friend;
};

bool cmp(struct node a,struct node b) //结果排序方式
{
    if(abs(a.first_friend) != abs(b.first_friend))
        return abs(a.first_friend) < abs(b.first_friend);
    else
        return abs(a.second_friend )<abs(b.second_friend);
}

vector<vector<int>>Graph(10000);

int main()
{
    int N,K,M,i,j,k;
    scanf("%d %d",&N,&K);
    map<int,bool>RelationShip;
    string name_1,name_2;
    for(i=0 ; i<K ; i++)
    {
        cin>>name_1>>name_2;
        if(name_1.length() == name_2.length())
        {
            Graph[abs(stoi(name_1))].push_back(abs(stoi(name_2)));
            Graph[abs(stoi(name_2))].push_back(abs(stoi(name_1)));
        }
        RelationShip[abs(stoi(name_1))*10000+abs(stoi(name_2))] = RelationShip[abs(stoi(name_2))*10000+abs(stoi(name_1))] = true;
    }
    cin>>M;
    for(i=0 ; i<M ; i++)
    {
        int c,d;
        cin>>c>>d;
        vector<struct node>Res;
        for(j=0 ; j<Graph[abs(c)].size() ; j++)
        {
            for(k=0 ; k<Graph[abs(d)].size() ; k++)
            {
                if(abs(d)== Graph[abs(c)][j] || abs(c)==Graph[abs(d)][k])
                    continue;
                if(RelationShip[Graph[abs(c)][j]*10000+Graph[abs(d)][k]])
                    Res.push_back(node{Graph[abs(c)][j],Graph[abs(d)][k]});
            }
        }
        int S = Res.size();
        cout<<S<<"\n";
        sort(Res.begin(),Res.end(),cmp);
        for(j=0 ; j<S ; j++)
        {
            printf("%04d %04d\n",abs(Res[j].first_friend),abs(Res[j].second_friend));
        }

    }
    return 0;
}

//他山之玉
//柳婼
/*
分析：1.用数组arr标记两个人是否是朋友（邻接矩阵表示），用v标记所有人的同性朋友（邻接表表示）
2.对于一对想要在一起的A和B，他们需要先找A的所有同性朋友C，再找B的所有同性朋友D，当C和D两人是朋友的时候则可以输出C和D
3.A在寻找同性朋友时，需要避免找到他想要的伴侣B，所以当当前朋友就是B或者B的同性朋友就是A时舍弃该结果
4.输出时候要以4位数的方式输出，所以要%04d
5.如果用int接收一对朋友，-0000和0000对于int来说都是0，将无法得知这个人的性别，也就会影响他找他的同性朋友的那个步骤，所以考虑用字符串接收，因为题目中已经表示会以符号位加四位的方式给出输入，所以只要判断字符串是否大小相等，如果大小相等说明这两个人是同性
6.结果数组因为必须按照第一个人的编号从小到大排序（当第一个相等时按照第二个人编号的从小到大排序），所以要用sort对ans数组排序后再输出结果

Update: 新PAT系统中原代码导致了一个测试点内存超限，使用unordered_map<int, bool> arr 替代二维数组可避免内存超限（2018-05-28更新）
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<int, bool> arr;
struct node {
    int a, b;
};
bool cmp(node x, node y) {
    return x.a != y.a ? x.a < y.a : x.b < y.b;
}
int main() {
    int n, m, k;
    scanf("%d%d", &n, &m);
    vector<int> v[10000];
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        if (a.length() == b.length()) {
            v[abs(stoi(a))].push_back(abs(stoi(b)));
            v[abs(stoi(b))].push_back(abs(stoi(a)));
        }
        arr[abs(stoi(a)) * 10000 + abs(stoi(b))] = arr[abs(stoi(b)) * 10000 + abs(stoi(a))] = true;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int c, d;
        cin >> c >> d;
        vector<node> ans;
        for (int j = 0; j < v[abs(c)].size(); j++) {
            for (int k = 0; k < v[abs(d)].size(); k++) {
                if (v[abs(c)][j] == abs(d) || abs(c) == v[abs(d)][k]) continue;
                if (arr[v[abs(c)][j] * 10000 + v[abs(d)][k]] == true)
                    ans.push_back(node{v[abs(c)][j], v[abs(d)][k]});
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", int(ans.size()));
        for(int j = 0; j < ans.size(); j++)
            printf("%04d %04d\n", ans[j].a, ans[j].b);
    }
    return 0;
}
