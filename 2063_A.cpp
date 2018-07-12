/*
1063 Set Similarity (25)（25 分）
Given two sets of integers, the similarity of the sets is defined to be N~c~/N~t~*100%, where N~c~ is the number of distinct common numbers shared by the two sets, and N~t~ is the total number of distinct numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.

Input Specification:

Each input file contains one test case. Each case first gives a positive integer N (<=50) which is the total number of sets. Then N lines follow, each gives a set with a positive M (<=10^4^) and followed by M integers in the range [0, 10^9^]. After the input of sets, a positive integer K (<=2000) is given, followed by K lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to N). All the numbers in a line are separated by a space.

Output Specification:

For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.

Sample Input:

3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
Sample Output:

50.0%
33.3%
*/
//思路：用map函数来记录出现的元素
#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<map<int,int>>Set(N+1);
    vector<float>Res;
    int i;
    for(i=1 ; i<=N ; i++)
    {
        int num;
        cin>>num;
        int j,temp;
        for(j=0 ; j<num ; j++)
        {
            cin>>temp;
            if(Set[i][temp]!=1)
                Set[i][temp]++;
            else
                continue;
        }
    }
    int K,t1,t2;
    cin>>K;
    for(i=0 ; i<K ; i++)
    {
        cin>>t1>>t2;
        int sum = Set[t1].size() + Set[t2].size();
        int sum_1 = 0;
        for(auto k = Set[t1].begin() ; k!=Set[t1].end() ; k++)
        {
            if(Set[t2].find(k->first)!=Set[t2].end())  //注意这里的判断条件，刚开始写成==1是不可以的；用find函数来判断是否含有该元素
                sum_1++;
        }
        float res = sum_1*100.0/(sum-sum_1);
        Res.push_back(res);
    }
    for(auto z = Res.begin() ; z!=Res.end() ; z++)
        printf("%.1f\%\n",*z);
    return 0;
}


//他山之玉
//柳婼
/*
题目大意：给定两个整数集合，它们的相似度定义为：Nc/Nt*100%。其中Nc是两个集合都有的不相等整数的个数，Nt是两个集合一共有的不相等整数的个数。你的任务就是计算任意一对给定集合的相似度。
nc是两个集合的公共元素个数，nt是两个集合的所有包含的元素个数（其中元素个数表示各个元素之间互不相同）。

分析：因为给出的集合里面含有重复的元素，而计算nc和nt不需要考虑两个集合里面是否分别有重复的元素，所以可以直接使用set存储每一个集合，然后把set放进一个数组里面存储。当需要计算集合a和集合b的相似度nc和nt的时候，遍历集合a中的每一个元素，寻找集合b中是否有该元素，如果有，说明是两个人公共的集合元素，则nc++，否则nt++（nt的初值为b集合里面本有的元素）。
*/
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int main() {
    int n, m, k, temp, a, b;
    scanf("%d", &n);
    vector<set<int>> v(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        set<int> s;
        for(int j = 0; j < m; j++) {
            scanf("%d", &temp);
            s.insert(temp);
        }
        v[i] = s;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        int nc = 0, nt = v[b-1].size();
        for(auto it = v[a-1].begin(); it != v[a-1].end(); it++) {
            if(v[b-1].find(*it) == v[b-1].end())
                nt++;
            else
                nc++;
        }
        double ans = (double)nc / nt * 100;
        printf("%.1f%%\n", ans);
    }
    return 0;
}
