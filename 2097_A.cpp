/*
1097 Deduplication on a Linked List (25)（25 分）
Given a singly linked list L with integer keys, you are supposed to remove the nodes with duplicated absolute values of the keys. That is, for each value K, only the first node of which the value or absolute value of its key equals K will be kept. At the mean time, all the removed nodes must be kept in a separate list. For example, given L being 21→-15→-15→-7→15, you must output 21→-15→-7, and the removed list -15→15.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, and a positive N (<= 10^5^) which is the total number of nodes. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Key Next

where Address is the position of the node, Key is an integer of which absolute value is no more than 10^4^, and Next is the position of the next node.

Output Specification:

For each case, output the resulting linked list first, then the removed list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:

00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
Sample Output:

00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
#include <cmath>
using namespace std;

struct ListNode
{
    int Address,value,Next;
    bool Flag;
};

int main()
{
    int FirstAddress,N;
    cin>>FirstAddress>>N;
    vector<struct ListNode>List(100001);
    vector<struct ListNode>Remove;
    map<int,int>duplication;
    int i;
    for(i=0 ; i<N ; i++)
    {
        struct ListNode temp;
        scanf("%d %d %d",&temp.Address,&temp.value,&temp.Next);
        temp.Flag = false;
        List[temp.Address] = temp;
    }
    for(i=FirstAddress ; i!=-1; i = List[i].Next)
    {
        if(duplication.find(abs(List[i].value))==duplication.end())
        {
            List[i].Flag = true;
            duplication[abs(List[i].value)]++;
        }
        else
            Remove.push_back(List[i]);
    }
    for(i=FirstAddress ; i!=-1 ; i = List[i].Next)
    {
        if(i!=FirstAddress && List[i].Flag)
            printf("%05d\n%05d %d ",List[i].Address,List[i].Address,List[i].value);
        else if(i==FirstAddress)
            printf("%05d %d ",List[i].Address,List[i].value);
    }
    cout<<"-1\n";
    int Size = Remove.size();
    for(i=0 ; i<Size ; i++)
    {
        if(i!=Size-1)
            printf("%05d %d %05d\n",Remove[i].Address,Remove[i].value,Remove[i+1].Address);
        else
            printf("%05d %d -1",Remove[i].Address,Remove[i].value);
    }

}


//他山之玉
//柳婼

#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 100000;
struct NODE {
    int address, key, next, num = 2 * maxn;
}node[maxn];
bool exist[maxn];
int cmp1(NODE a, NODE b){
    return a.num < b.num;
}
int main() {
    int begin, n, cnt1 = 0, cnt2 = 0, a;
    scanf("%d%d", &begin, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        scanf("%d%d", &node[a].key, &node[a].next);
        node[a].address = a;
    }
    for(int i = begin; i != -1; i = node[i].next) {
        if(exist[abs(node[i].key)] == false) {
            exist[abs(node[i].key)] = true;
            node[i].num = cnt1;
            cnt1++;
        }
        else {
            node[i].num = maxn + cnt2;
            cnt2++;
        }
    }
    sort(node, node + maxn, cmp1);
    int cnt = cnt1 + cnt2;
    for(int i = 0; i < cnt; i++) {
        if(i != cnt1 - 1 && i != cnt - 1) {
            printf("%05d %d %05d\n", node[i].address, node[i].key, node[i+1].address);
        } else {
            printf("%05d %d -1\n", node[i].address, node[i].key);
        }
    }
    return 0;
}
