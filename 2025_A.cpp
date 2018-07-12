/*
1025 PAT Ranking (25)（25 分）
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

Output Specification:

For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:

registration_number final_rank location_number local_rank

The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

Sample Input:

2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:

9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct stduent
{
    string id;
    int score;
    int location;
    int rk;
};

typedef struct stduent Stu;

bool cmp(Stu a, Stu b)
{
    if(a.score == b.score)
        return a.id < b.id;
    else
        return a.score > b.score;
}

int main()
{
    int N;
    cin>>N;
    vector<Stu>num;
    vector<Stu>Temp;
    int i;
    int sum = 0;
    for(i=1 ; i<=N ; i++)
    {
        int K;
        cin>>K;
        sum+=K;
        int j;
        for(j=0 ; j<K ; j++)
        {
            Stu temp;
            cin>>temp.id>>temp.score;
            temp.location = i;
            Temp.push_back(temp);
        }
        sort(Temp.begin(),Temp.end(),cmp);
        int k;
        int te = 1;
        for(k=0 ; k<K ; k++)
        {
            if(k!=0 && Temp[k].score == Temp[k-1].score)
                Temp[k].rk = te;
            else
            {
                te = k+1;
                Temp[k].rk = te;
            }
            num.push_back(Temp[k]);
        }
        Temp.clear();

    }
    sort(num.begin(),num.end(),cmp);
    cout<<sum<<"\n";
    int temp = 1;
    for(i=0 ; i<sum ; i++)
    {
        if(i!=0 &&num[i].score == num[i-1].score)
        {
            cout<<num[i].id<<" "<<temp<<" "<<num[i].location<<" "<<num[i].rk<<"\n";
        }
        else
        {
            temp = i+1;
            cout<<num[i].id<<" "<<temp<<" "<<num[i].location<<" "<<num[i].rk<<"\n";
        }
    }
    return 0;
}


//他山之玉
//柳婼
/*
题目大意：有n个考场，每个考场有若干数量的学生，给出每个考场中考生的编号和分数，要求算排名，输出所有考生的编号、排名、考场号、考场内排名
分析：先按照考场内排名 然后赋值给总数组fin，然后总排名，最后输出。注意相同的分数情况下按照学号的从小到大排列，但是他们的排名应该是一样的数字~~~
*/

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct student {
    long long int no;
    int score, finrank, loca, locarank;
};
bool cmp1(student a, student b) {
    return a.score != b.score ? a.score > b.score : a.no < b.no;
}
int main() {
    int n, m;
    scanf("%d", &n);
    vector<student> fin;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &m);
        vector<student> v(m);
        for(int j = 0; j < m; j++) {
            scanf("%lld %d", &v[j].no, &v[j].score);
            v[j].loca = i;
        }
        sort(v.begin(), v.end(), cmp1);
        v[0].locarank = 1;
        fin.push_back(v[0]);
        for(int j = 1; j < m; j++) {
            v[j].locarank = (v[j].score == v[j - 1].score) ? (v[j - 1].locarank) : (j + 1);
            fin.push_back(v[j]);
        }
    }
    sort(fin.begin(), fin.end(), cmp1);
    fin[0].finrank = 1;
    for(int j = 1; j < fin.size(); j++)
        fin[j].finrank = (fin[j].score == fin[j - 1].score) ? (fin[j - 1].finrank) : (j + 1);
    printf("%d\n", fin.size());
    for(int i = 0; i < fin.size(); i++)
        printf("%013lld %d %d %d\n", fin[i].no, fin[i].finrank, fin[i].loca, fin[i].locarank);
    return 0;
}
