/*
1052 Linked List Sorting (25)（25 分）
A linked list consists of a series of structures, which are not necessarily adjacent in memory. We assume that each structure contains an integer key and a Next pointer to the next structure. Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive N (< 10^5^) and an address of the head node, where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Key Next

where Address is the address of the node in memory, Key is an integer in [-10^5^, 10^5^], and Next is the address of the next node. It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.

Output Specification:

For each test case, the output format is the same as that of the input, where N is the total number of nodes in the list and all the nodes must be sorted order.

Sample Input:

5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
Sample Output:

5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct ListNode
{
    int address;
    int value;
    int next;
    bool flag;
};

typedef struct ListNode List;
bool cmp(List a,List b)
{
    if(!a.flag || !b.flag)
    {
        return a.flag > b.flag;
    }
    else
    {
        return a.value < b.value;
    }
}
int main()
{
    int N,FirstAdress;
    cin>>N>>FirstAdress;
    int i;
    int cnt = 0;
    vector<List>num(100000);
    for(i=0 ; i<N ; i++)
    {
        List temp;
        cin>>temp.address>>temp.value>>temp.next;
        temp.flag = false;
        num[temp.address] = temp;
    }
    for(i=FirstAdress ; i!=-1 ; i = num[i].next)
    {
        num[i].flag = true;
        cnt++;
    }
    sort(num.begin(),num.end(),cmp);

    if(cnt == 0)
        printf("0 -1");
    else
    {
        printf("%d %05d\n",cnt,num[0].address);
        for(i=0 ; i<cnt ; i++)
        {
            if(i!=cnt-1)
                printf("%05d %d %05d\n",num[i].address,num[i].value,num[i+1].address);
            else
                printf("%05d %d -1\n",num[i].address,num[i].value);
        }
    }
    return 0;
}


/*运行超时，最后一个测试点答案错误
int cmp(List a,List b)
{
    return a.value < b.value;
}

int main()
{
    int N,FirstAdress;
    cin>>N>>FirstAdress;
    int i;

    vector<List>num;
    vector<int>Next;
    for(i=0 ; i<N ; i++)
    {
        List temp;
        cin>>temp.address>>temp.value>>temp.next;
        num.push_back(temp);
        Next.push_back(temp.next);
    }
    auto j = num.begin();
    for(i=0 ; j!=num.end() ; )
    {
        if(num[i].address!=FirstAdress && find(Next.begin(),Next.end(),num[i].address) == Next.end())
        {
            j = num.erase(j);
            N--;
        }
        else
        {
            i++;
            j++;
        }
    }
    sort(num.begin(),num.end(),cmp);
    printf("%d %05d\n",N,num[0].address);
    for(i=0 ; i<N ; i++)
    {
        if(i!=N-1)
            printf("%05d %d %05d\n",num[i].address,num[i].value,num[i+1].address);
        else
            printf("%05d %d -1\n",num[i].address,num[i].value);
    }
    return 0;
}
*/


//他山之玉
//柳婼
题目大意：给出一个链表，将链表排序，然后把链表上的结点按照data值的从小到大顺序输出
分析：建立结构体数组，按照从首地址开始的顺序（直到-1）遍历一遍整个链表，将在链表中的结点的flag标记为true，并且统计cnt（有效结点的个数）。（因为有的结点根本不在链表中）
然后将链表进行排序，如果flag == false就把他们移动到后面（即：reuturn a.flag > b.flag）,最后只输出前cnt个链表的信息~~~
#include <iostream>
#include <algorithm>
using namespace std;
struct NODE {
    int address, key, next;
    bool flag;
}node[100000];
int cmp1(NODE a, NODE b) {
    return !a.flag || !b.flag ? a.flag > b.flag : a.key < b.key;
}
int main() {
    int n, cnt = 0, s, a, b, c;
    scanf("%d%d", &n, &s);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        node[a] = {a, b, c, false};
    }
    for(int i = s; i != -1; i = node[i].next) {
        node[i].flag = true;
        cnt++;
    }
    if(cnt == 0) {
        printf("0 -1");
    } else {
        sort(node, node + 100000, cmp1);
        printf("%d %05d\n", cnt, node[0].address);
        for(int i = 0; i < cnt; i++) {
            printf("%05d %d ", node[i].address, node[i].key);
            if(i != cnt - 1)
                printf("%05d\n", node[i + 1].address);
            else
                printf("-1\n");
        }
    }
    return 0;
}
