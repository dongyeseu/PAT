/*
1133 Splitting A Linked List（25 分）
Given a singly linked list, you are supposed to rearrange its elements so that all the negative values appear before all of the non-negatives, and all the values in [0, K] appear before all those greater than K. The order of the elements inside each class must not be changed. For example, given the list being 18→7→-4→0→5→-6→10→11→-2 and K being 10, you must output -4→-6→-2→7→0→5→10→18→11.

Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10
​5
​​ ) which is the total number of nodes, and a positive K (≤10
​3
​​ ). The address of a node is a 5-digit nonnegative integer, and NULL is represented by −1.

Then N lines follow, each describes a node in the format:

Address Data Next
where Address is the position of the node, Data is an integer in [−10
​5
​​ ,10
​5
​​ ], and Next is the position of the next node. It is guaranteed that the list is not empty.

Output Specification:
For each case, output in order (from beginning to the end of the list) the resulting linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
Sample Output:
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1
*/

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

struct Link
{
    int addre;
    int value;
    int next;
};

int main()
{
    int first_address,N,K;
    vector<struct Link>stu(100001);
    int i;
    scanf("%d %d %d",&first_address,&N,&K);
    int address,vle,nxt;
    for(i=0 ; i<N ; i++)
    {
        scanf("%d %d %d",&address,&vle,&nxt);
        stu[address].addre =  address;
        stu[address].value = vle;
        stu[address].next = nxt;
    }
    vector<struct Link>Res[3];
    for(i=first_address ; i!=-1 ; i = stu[i].next)
    {
        if(stu[i].value < 0)
            Res[0].push_back(stu[i]);
        else if(stu[i].value<=K)
            Res[1].push_back(stu[i]);
        else
            Res[2].push_back(stu[i]);
    }
    vector<struct Link>res;
    for(i=0 ; i<3 ; i++)
    {
        int len = Res[i].size();
        int j;
        for(j=0 ; j<len ; j++)
        {
            res.push_back(Res[i][j]);
        }
    }
    int len = res.size();
    for(i=0 ; i<len ; i++)
    {
        if(i!=len-1)
            printf("%05d %d %05d\n",res[i].addre,res[i].value,res[i+1].addre);
        else
            printf("%05d %d -1\n",res[i].addre,res[i].value);
    }
    return 0;
}


//他山之玉
//柳婼
/*
题目大意：给一个链表和K，遍历链表后将<0的结点先输出，再将0～k区间的结点输出，最后输出>k的结点
分析：将结点用list[10000]保存，list为node类型，node中保存结点的值value和它的next地址。list的下标就是结点的地址。将<0、0～k、>k三部分的结点地址分别保存在v[0]、v[1]、v[2]中，最后将vector中的值依次输出即可～
*/
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int data, next;
}list[100000];
vector<int> v[3];
int main() {
    int start, n, k, a;
    scanf("%d%d%d", &start, &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        scanf("%d%d", &list[a].data, &list[a].next);
    }
    int p = start;
    while(p != -1) {
        int data = list[p].data;
        if (data < 0)
            v[0].push_back(p);
        else if (data >= 0 && data <= k)
            v[1].push_back(p);
        else
            v[2].push_back(p);
        p = list[p].next;
    }
    int flag = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (flag == 0) {
                printf("%05d %d ", v[i][j], list[v[i][j]].data);
                flag = 1;
            } else {
                printf("%05d\n%05d %d ", v[i][j], v[i][j], list[v[i][j]].data);
            }
        }
    }
    printf("-1");
    return 0;
}
