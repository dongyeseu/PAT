/*
1129 Recommendation System£¨25 ·Ö£©
Recommendation system predicts the preference that a user would give to an item. Now you are asked to program a very simple recommendation system that rates the user's preference by the number of times that an item has been accessed by this user.

Input Specification:
Each input file contains one test case. For each test case, the first line contains two positive integers: N (¡Ü 50,000), the total number of queries, and K (¡Ü 10), the maximum number of recommendations the system must show to the user. Then given in the second line are the indices of items that the user is accessing -- for the sake of simplicity, all the items are indexed from 1 to N. All the numbers in a line are separated by a space.

Output Specification:
For each case, process the queries one by one. Output the recommendations for each query in a line in the format:

query: rec[1] rec[2] ... rec[K]
where query is the item that the user is accessing, and rec[i] (i=1, ... K) is the i-th item that the system recommends to the user. The first K items that have been accessed most frequently are supposed to be recommended in non-increasing order of their frequencies. If there is a tie, the items will be ordered by their indices in increasing order.

Note: there is no output for the first item since it is impossible to give any recommendation at the time. It is guaranteed to have the output for at least one query.

Sample Input:
12 3
3 5 7 5 5 3 2 1 8 3 8 12
Sample Output:
5: 3
7: 3 5
5: 3 5 7
5: 5 3 7
3: 5 3 7
2: 5 3 7
1: 5 3 2
8: 5 3 1
3: 5 3 1
8: 3 5 1
12: 3 5 8
*/


//运行超时
#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;
    map<int,vector<int>>time;
    map<int,int>num;
    int i,temp;
    cin>>temp;
    num[temp]++;
    time[num[temp]].push_back(temp);
    for(i=0 ; i<N-1 ; i++)
    {
        cin>>temp;
        set<int>Recomentation;
        vector<int>Res;
        auto j = time.rbegin();
        int flag = 1;
        for( ; j!=time.rend() ; j++)
        {
            int s = j->second.size();
            sort(j->second.begin(),j->second.end());
            int k;
            for(k = 0 ; k<s ; k++)
            {
                if(Recomentation.count(j->second[k]) == 0)
                {
                    Recomentation.insert(j->second[k]);
                    Res.push_back(j->second[k]);
                }
                if(Recomentation.size()==K)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
                break;
        }
        printf("%d:",temp);
        for(auto c : Res)
            cout<<" "<<c;
        num[temp]++;
        time[num[temp]].push_back(temp);
        cout<<"\n";
    }
    return 0;
}


//最后一个测试点运行超时
#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;
    map<int,set<int>>time;
    map<int,int>num;
    int i,temp;
    cin>>temp;
    num[temp]++;
    time[num[temp]].insert(temp);
    for(i=0 ; i<N-1 ; i++)
    {
        cin>>temp;
        set<int>Recomentation;
        vector<int>Res;
        auto j = time.rbegin();
        int flag = 1;
        for( ; j!=time.rend() ; j++)
        {
            auto k = j->second.begin();
            for( ; k!=j->second.end() ; k++)
            {
                if(Recomentation.count(*k) == 0)
                {
                    Recomentation.insert(*k);
                    Res.push_back(*k);
                }
                if(Recomentation.size()==K)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
                break;
        }
        printf("%d:",temp);
        for(auto c : Res)
            cout<<" "<<c;
        num[temp]++;
        time[num[temp]].insert(temp);
        cout<<"\n";
    }
    return 0;
}

//他山之玉
//柳婼
/*
题目大意：根据用户每次点击的东西的编号，输出他在点当前编号之前应该给这个用户推荐的商品的编号～只推荐k个～也就是输出用户曾经点击过的商品编号的最多的
前k个～如果恰好两个商品有相同的点击次数，就输出编号较小的那个～
分析：【并不复杂～只是写的比较详细～不怕不怕～(摸头…】因为每个商品有两个属性：编号value和出现的次数cnt，编号具有唯一性，然后set又会根据大小自动排序
，所以我们可以考虑将value和cnt组成一个node属性，把所有商品编号和它对应的次数变成node放入set里面，重载小于号，使<根据set中node的cnt排序，如果cnt相
等就按照node的value排序～
这样set里面就是按照出现次数排序好的商品node，每次输出set的前k个node的value值就可以～（要记住，因为是点击前推荐，所以我们在接收完num的值后，应该先
输出再插入让set帮忙排序当前num，当前的这个点击编号暂时先不算在输出结果里面的～）
首先在struct node里面重载<号，如果当前cnt不等于a.cnt就将cnt大的排在前，否则将value小的排在前面～
每次输入的时候，先不插入，先输出，当i != 0时候开始输出，因为i==0时候用户才第一次点击，没有可以推荐的～(沮丧脸…) 输出的同时记录输出过的个数tempCnt，
当tempCnt < k的时候输出，因为只要前k个～所以就从头到尾依次输出set中的值就可以啦～
book[num]标记num出现的次数，每次寻找set中当前值为num和次数为book[num]的那个值，如果找到了就把他移除，（找到说明这个数已经出现过啦，cnt已经不对啦，
先移除掉吧～）然后将book[num]+1，在将node(num, book[num])插入到set中，set会帮忙根据我们自定义的<的规则自动排序哒～
/*
#include <iostream>
#include <set>
using namespace std;
int book[50001];
struct node {
    int value, cnt;
    bool operator < (const node &a) const {
        return (cnt != a.cnt) ? cnt > a.cnt : value < a.value;
    }
};
int main() {
    int n, k, num;
    scanf("%d%d", &n, &k);
    set<node> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (i != 0) {
            printf("%d:", num);
            int tempCnt = 0;
            for(auto it = s.begin(); tempCnt < k && it != s.end(); it++) {
                printf(" %d", it->value);
                tempCnt++;
            }
            printf("\n");
        }
        auto it = s.find(node{num, book[num]});
        if (it != s.end()) s.erase(it);
        book[num]++;
        s.insert(node{num, book[num]});
    }
    return 0;
}
