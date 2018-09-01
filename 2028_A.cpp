/*
1028 List Sorting (25)（25 分）
Excel can sort records according to any column. Now you are supposed to imitate this function.

Input

Each input file contains one test case. For each case, the first line contains two integers N (<=100000) and C, where N is the number of records and C is the column that you are supposed to sort the records with. Then N lines follow, each contains a record of a student. A student's record consists of his or her distinct ID (a 6-digit number), name (a string with no more than 8 characters without space), and grade (an integer between 0 and 100, inclusive).

Output

For each test case, output the sorting result in N lines. That is, if C = 1 then the records must be sorted in increasing order according to ID's; if C = 2 then the records must be sorted in non-decreasing order according to names; and if C = 3 then the records must be sorted in non-decreasing order according to grades. If there are several students who have the same name or grade, they must be sorted according to their ID's in increasing order.

Sample Input 1

3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
Sample Output 1

000001 Zoe 60
000007 James 85
000010 Amy 90
Sample Input 2

4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
Sample Output 2

000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
Sample Input 3

4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
Sample Output 3

000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90
*/
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

struct node
{
    char id[7];
    char Name[9]; //这里必须大于8，否则会出现错误；原因是存在字符'\0'
    int grade;
};
int flag = 0;
bool cmp(struct node a,struct node b)
{
    if(flag == 1)
    {
        return strcmp(a.id,b.id)<0;
    }
    else if(flag == 2)
    {
        if(strcmp(a.Name,b.Name)!=0)
        {
            return strcmp(a.Name,b.Name)<0;
        }
        else
        {
            return strcmp(a.id,b.id)<0;
        }
    }
    else if(flag == 3)
    {
        if(a.grade!=b.grade)
            return a.grade < b.grade;
        else
            return strcmp(a.id,b.id)<0;
    }
}

int main()
{
    int N,K;
    cin>>N>>K;
    flag = K;
    vector<struct node>Student(N);
    int i;
    while(getchar()!='\n')
        continue;
    for(i=0 ; i<N ; i++)
    {
        scanf("%s %s %d",&Student[i].id,&Student[i].Name,&Student[i].grade);
    }
    sort(Student.begin(),Student.end(),cmp);
    for(i=0 ; i<N ; i++)
        printf("%s %s %d\n",Student[i].id,Student[i].Name,Student[i].grade);
    return 0;
}

*/
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

struct node
{
    int id;
    char Name[9]; //这里必须大于8，否则会出现错误；原因是存在字符'\0'
    int grade;
};
int flag = 0;
bool cmp(struct node a,struct node b)
{
    if(flag == 1)
    {
        return a.id < b.id;
    }
    else if(flag == 2)
    {
        if(strcmp(a.Name,b.Name)!=0)
        {
            return strcmp(a.Name,b.Name)<0;
        }
        else
        {
            return a.id < b.id;
        }
    }
    else if(flag == 3)
    {
        if(a.grade!=b.grade)
            return a.grade < b.grade;
        else
            return a.id < b.id;
    }
}

int main()
{
    int N,K;
    cin>>N>>K;
    flag = K;
    vector<struct node>Student(N);
    int i;
    while(getchar()!='\n')
        continue;
    for(i=0 ; i<N ; i++)
    {
        scanf("%d %s %d",&Student[i].id,&Student[i].Name,&Student[i].grade);
    }
    sort(Student.begin(),Student.end(),cmp);
    for(i=0 ; i<N ; i++)
        printf("%06d %s %d\n",Student[i].id,Student[i].Name,Student[i].grade);
    return 0;
}
*/
//最后一个测试点超时了
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct Node
{
    int Id;
    string Name;
    int score;
};
typedef struct Node Student;

bool cmp1(Student x,Student y)
{
    return x.Id < y.Id;
}

bool cmp2(Student x,Student y)
{
    if(x.Name!=y.Name)
        return x.Name < y.Name;
    else
        return x.Id < y.Id;
}

bool cmp3(Student x,Student y)
{
    if(x.score != y.score)
        return x.score < y.score;
    else
        return x.Id < y.Id;
}

int main()
{
    vector<Student>stu;
    int N,K;
    cin>>N>>K;
    int i;
    for(i=0 ; i<N ; i++)
    {
        Student tmp;
        cin>>tmp.Id>>tmp.Name>>tmp.score;
        stu.push_back(tmp);
    }
    switch(K)
    {
    case 1:
        sort(stu.begin(),stu.end(),cmp1);
        break;
    case 2:
        sort(stu.begin(),stu.end(),cmp2);
        break;
    case 3:
        sort(stu.begin(),stu.end(),cmp3);
        break;
    }
    for(i=0 ; i<N ; i++)
    {
        printf("%06d",stu[i].Id);
        cout<<" "<<stu[i].Name<<" "<<stu[i].score<<"\n";
    }
    return 0;
}

//他山之玉
//柳婼
/*
题目大意：根据c的值是1还是2还是3，对相应的列排序。第一列升序，第二列不降序，第三列不降序。
分析：注意，按照名称的不降序排序，因为strcmp比较的是ACSII码，所以A < Z。写cmp函数的时候return strcmp(a.name, b.name) <= 0; return语句返回的是true或者false的值，所以要写 <= 0 这样的形式。比较ACSII码的大小，strcmp(‘a’, ‘z’)返回负值，因为a<z a – z < 0
按照分数的不降序排序，a.score <= b.score
*/
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn = 100001;
struct NODE {
    int no, score;
    char name[10];
}node[maxn];
int c;
int cmp1(NODE a, NODE b) {
    if(c == 1) {
        return a.no < b.no;
    } else if(c == 2) {
        if(strcmp(a.name, b.name) == 0) return a.no < b.no;
        return strcmp(a.name, b.name) <= 0;
    } else {
        if(a.score == b.score) return a.no < b.no;
        return a.score <= b.score;
    }
}
int main() {
    int n;
    scanf("%d%d", &n, &c);
    for(int i = 0; i < n; i++)
        scanf("%d %s %d", &node[i].no, node[i].name, &node[i].score);
    sort(node, node + n, cmp1);
    for(int i = 0; i < n; i++)
        printf("%06d %s %d\n", node[i].no, node[i].name, node[i].score);
    return 0;
}
