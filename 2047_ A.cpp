/*
1047 Student List for Course (25)（25 分）
Zhejiang University has 40000 students and provides 2500 courses. Now given the registered course list of each student, you are supposed to output the student name lists of all the courses.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=40000), the total number of students, and K (<=2500), the total number of courses. Then N lines follow, each contains a student's name (3 capital English letters plus a one-digit number), a positive number C (<=20) which is the number of courses that this student has registered, and then followed by C course numbers. For the sake of simplicity, the courses are numbered from 1 to K.

Output Specification:

For each test case, print the student name lists of all the courses in increasing order of the course numbers. For each course, first print in one line the course number and the number of registered students, separated by a space. Then output the students' names in alphabetical order. Each name occupies a line.

Sample Input:

10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5
Sample Output:

1 4
ANN0
BOB5
JAY9
LOR6
2 7
ANN0
BOB5
FRA8
JAY9
JOE4
KAT3
LOR6
3 1
BOB5
4 7
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
5 9
AMY7
ANN0
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
*/

//依然超时
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdio.h>
using namespace std;
int main()
{
    int N,K;
    scanf("%d %d",&N,&K);
    vector<set<string>>student(K+1);
    int i = 0;
    for(i=0 ; i<N ; i++)
    {
        char Name[5];
        string name;
        int M;
        scanf("%s %d",Name,&M);
        name = Name;
        int j;
        for(j=0 ; j<M ; j++)
        {
            int temp;
            scanf("%d",&temp);
            student[temp].insert(name);
        }
    }
    for(i=1 ; i<=K ; i++)
    {
        int j , len = student[i].size();
        printf("%d %d\n",i,len);
        auto k = student[i].begin(),l = student[i].end();
        for( ; k!=l ; k++)
            cout<<*k<<"\n";
    }
    return 0;
}


/*测试点2答案错误，测试点4运行超时
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string a,string b)
{
    return a<b;
}
int main()
{
    int N,K;
    cin>>N>>K;
    map<int,vector<string>>course;
    int i;
    for(i=0 ; i<N ; i++)
    {
        string name;
        cin>>name;
        int n,temp;
        cin>>n;
        while(n--)
        {
            cin>>temp;
            course[temp].push_back(name);
        }
    }
    auto j = course.begin(),k = course.end();
    for( j ; j!=k ; j++)
    {
        cout<<j->first<<" "<<j->second.size()<<"\n";
        sort(j->second.begin(),j->second.end(),cmp);
        int len = j->second.size();
        int z;
        for(z=0 ; z<len ; z++)
        {
            cout<<j->second[z]<<"\n";
        }
    }
    return 0;
}
*/
/* 最后一个测试点运行超时
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmp(string a,string b)
{
    return a<b;
}
int main()
{
    int N,K;
    cin>>N>>K;
    vector<vector<string>>student(K+1);
    int i = 0;
    for(i=0 ; i<N ; i++)
    {
        string name;
        int M;
        cin>>name>>M;
        int j;
        for(j=0 ; j<M ; j++)
        {
            int temp;
            cin>>temp;
            student[temp].push_back(name);
        }
    }
    for(i=1 ; i<=K ; i++)
    {
        int j , len = student[i].size();
        printf("%d %d\n",i,len);
        sort(student[i].begin(),student[i].end(),cmp);
        for(j=0 ; j<len ; j++)
            cout<<student[i][j]<<"\n";
    }
    return 0;
}
*/


//他山之玉
//柳婼
/*
题目大意：给出选课人数和课程数目，然后再给出每个人的选课情况，请针对每门课程输出选课人数以及所有选该课的学生姓名，按照字典序~~~
分析：建立int的二维数组，course[i][j] = k表示第i号课程上的人的一个列表，k是上这个课的学生的姓名所在的字符数组name[i][j]的i下标~~
注意：strcmp返回的不一定是-1，0，1这几个数字，要返回bool变量还需要在后面添加strcmp是大于0还是小于0~~~
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
char name[40010][5];
vector<int> course[2510];
bool cmp1(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        int cnt, temp;
        scanf("%s %d", name[i], &cnt);
        for(int j = 0; j < cnt; j++) {
            scanf("%d", &temp);
            course[temp].push_back(i);
        }
    }
    for(int i = 1; i <= k; i++) {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp1);
        for(int j = 0; j < course[i].size(); j++)
            printf("%s\n", name[course[i][j]]);
    }
    return 0;
}
