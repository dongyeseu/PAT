/*
1055 The World's Richest (25)（25 分）
Forbes magazine publishes every year its list of billionaires based on the annual ranking of the world's wealthiest people. Now you are supposed to simulate this job, but concentrate only on the people in a certain range of ages. That is, given the net worths of N people, you must find the M richest people in a given range of their ages.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=10^5^) - the total number of people, and K (<=10^3^) - the number of queries. Then N lines follow, each contains the name (string of no more than 8 characters without space), age (integer in (0, 200]), and the net worth (integer in [-10^6^, 10^6^]) of a person. Finally there are K lines of queries, each contains three positive integers: M (<= 100) - the maximum number of outputs, and [Amin, Amax] which are the range of ages. All the numbers in a line are separated by a space.

Output Specification:

For each query, first print in a line "Case #X:" where X is the query number starting from 1. Then output the M richest people with their ages in the range [Amin, Amax]. Each person's information occupies a line, in the format

Name Age Net_Worth
The outputs must be in non-increasing order of the net worths. In case there are equal worths, it must be in non-decreasing order of the ages. If both worths and ages are the same, then the output must be in non-decreasing alphabetical order of the names. It is guaranteed that there is no two persons share all the same of the three pieces of information. In case no one is found, output "None".

Sample Input:

12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50
Sample Output:

Case #1:
Alice 18 88888
Billy 24 5888
Bob_Volk 24 5888
Dobby 24 5888
Case #2:
Joe_Mike 32 3222
Zoe_Bill 35 2333
Williams 30 -22
Case #3:
Anny_Cin 95 999999
Michael 5 300000
Alice 18 88888
Cindy 76 76000
Case #4:
None
*/
//2，3测试点超时
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

struct Wealth{
    char name[40];
    int age;
    int wealth;
};
bool cmp(struct Wealth a, struct Wealth b)
{

    if(a.wealth!=b.wealth)
    {
        return a.wealth > b.wealth;
    }
    else
    {
        if(a.age != b.age)
            return a.age<b.age;
        else
            return strcmp(a.name,b.name)<0;
    }
}
int main()
{
    vector<struct Wealth>Rank;
    vector<vector<struct Wealth>>Age(201);
    int N,K;
    scanf("%d %d",&N,&K);
    int i;
    for(i=0 ; i<N; i++)
    {
        struct Wealth temp;
        scanf("%s %d %d",temp.name,&temp.age,&temp.wealth);
        Age[temp.age].push_back(temp);
    }
    for(i=0 ; i<K ; i++)
    {
        int cnt = 0;
        int s,first,last;
        scanf("%d %d %d",&s,&first,&last);
        printf("Case #%d:\n",i+1);
        int j;
        vector<struct Wealth>Tp;
        for(j=first ; j<=last ; j++)
        {
            if(Age[j].size()!=0)
            {
                int z;
                for(z=0 ; z<Age[j].size() ; z++)
                {
                    Tp.push_back(Age[j][z]);
                }
            }
        }
        sort(Tp.begin(),Tp.end(),cmp);
        if(Tp.begin()==Tp.end())
            cout<<"None\n";
        else{
            for(j=0 ; j<s&&j<Tp.size() ; j++)
            {
                printf("%s %d %d\n",Tp[j].name,Tp[j].age,Tp[j].wealth);
            }
        }
    }
    return 0;
}




//他山之玉
//柳婼
//2，3测试点超时
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct node {
    char name[10];
    int age, money;
};
int cmp1(node a, node b) {
    if(a.money != b.money)
        return a.money > b.money;
    else if(a.age != b.age)
        return a.age < b.age;
    else
        return (strcmp(a.name, b.name) < 0);
}
 
int main() {
    int n, k, num, amin, amax;
    scanf("%d %d", &n, &k);
    vector<node> vt(n), v;
    vector<int> book(205, 0);
    for(int i = 0; i < n; i++)
        scanf("%s %d %d", vt[i].name, &vt[i].age, &vt[i].money);
    sort(vt.begin(), vt.end(), cmp1);
    for(int i = 0; i < n; i++) {
        if(book[vt[i].age] < 100) {
            v.push_back(vt[i]);
            book[vt[i].age]++;
        }
    }
    for(int i = 0; i < k; i++) {
        scanf("%d %d %d", &num, &amin, &amax);
        vector<node> t;
        for(int j = 0; j < v.size(); j++) {
            if(v[j].age >= amin && v[j].age <= amax)
                t.push_back(v[j]);
        }
        if(i != 0) printf("\n");
        printf("Case #%d:", i + 1);
        int flag = 0;
        for(int j = 0; j < num && j < t.size(); j++) {
            printf("\n%s %d %d", t[j].name, t[j].age, t[j].money);
            flag = 1;
        }
        if(flag == 0) printf("\nNone");
    }
    return 0;
}
