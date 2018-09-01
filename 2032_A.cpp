/*
1032 Sharing (25)（25 分）
To store English words, one method is to use linked lists and store a word letter by letter. To save some space, we may let the words share the same sublist if they share the same suffix. For example, "loading" and "being" are stored as showed in Figure 1.

\ Figure 1

You are supposed to find the starting position of the common suffix (e.g. the position of "i" in Figure 1).

Input Specification:

Each input file contains one test case. For each case, the first line contains two addresses of nodes and a positive N (<= 10^5^), where the two addresses are the addresses of the first nodes of the two words, and N is the total number of nodes. The address of a node is a 5-digit positive integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is the letter contained by this node which is an English letter chosen from {a-z, A-Z}, and Next is the position of the next node.

Output Specification:

For each case, simply output the 5-digit starting position of the common suffix. If the two words have no common suffix, output "-1" instead.

Sample Input 1:

11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010
Sample Output 1:

67890
Sample Input 2:

00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1
Sample Output 2:

-1
*/
//复习时写的，OK
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct node
{
    int address;
    char value;
    int next;
    bool flag = false;
};

int main()
{
    int first,second,N;
    cin>>first>>second>>N;
    int res;
    vector<struct node>line(1000000);
    int i;
    int ad,nt;
    char ch;
    for(i=0 ; i<N ; i++)
    {
        cin>>ad>>ch>>nt;
        line[ad].address = ad;
        line[ad].value = ch;
        line[ad].next = nt;
    }
    for(i=first ; i!=-1 ; i = line[i].next)
        line[i].flag = true;
    for(i=second ; i!=-1 ; i=line[i].next)
    {
        if(line[i].flag)
        {
            printf("%05d",i);
            return 0;
        }
    }
    cout<<-1;
    return 0;

}



/*最后一个测试点运行超时
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
struct ListNode{
    int address,next;
    string value;
};
typedef struct ListNode List;

int main()
{
    int FirstAdress_1,FirstAdress_2,N;
    cin>>FirstAdress_1>>FirstAdress_2>>N;
    vector<List>alpha(100000);
    int i = 0;
    for(i=0 ; i<N ; i++)
    {
        List temp;
        cin>>temp.address>>temp.value>>temp.next;
        alpha[temp.address] = temp;
    }
    string a="",b="";
    for(i=FirstAdress_1 ; i!=-1 ; i = alpha[i].next)
    {
        a+=alpha[i].value;
    }
    for(i=FirstAdress_2 ; i!=-1 ; i = alpha[i].next)
    {
        b+=alpha[i].value;
    }
    int len_a = a.size() , len_b = b.size();
    if(a[--len_a]!=b[--len_b])
        cout<<"-1";
    else
    {
        int flag = 1;
        while(a[len_a] == b[len_b])
        {
            if(len_a>0&&len_b>0)
            {
                len_a--;
                len_b--;
            }
            else
            {
                flag = 0;
                break;
            }

        }
        char ch;
        if(flag)
            ch = a[++len_a];
        else
            ch = a[len_a];
        for(i=FirstAdress_1 ; alpha[i].value[0]!=ch ; i = alpha[i].next)
            continue;
        printf("%05d",alpha[i].address);
    }
    return 0;
}
*/





/*
总结：
我的思路出现了一些问题，相同字符可以以不同的地址存储，但是如果两个链表遇到相同地址，就说明接下来的字符都是一样的


//他山之玉
//柳婼
/*
题目大意：求两个链表的首个共同结点的地址。如果没有，就输出-1
分析：用结构体数组存储，node[i]表示地址为i的结点，key表示值，next为下一个结点的地址，flag表示第一条链表有没有该结点
遍历第一条链表，将访问过的结点的flag都标记为true，当遍历第二条结点的时候，如果遇到了true的结点就输出并结束程序，没有遇到就输出-1
*/
#include <cstdio>
using namespace std;
struct NODE {
    char key;
    int next;
    bool flag;
}node[100000];
int main() {
    int s1, s2, n, a, b;
    scanf("%d%d%d", &s1, &s2, &n);
    char data;
    for(int i = 0; i < n; i++) {
        scanf("%d %c %d", &a, &data, &b);
        node[a] = {data, b, false};
    }
    for(int i = s1; i != -1; i = node[i].next)
        node[i].flag = true;
    for(int i = s2; i != -1; i = node[i].next) {
        if(node[i].flag == true) {
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}


//他山之玉
//日沉云起
/*
算法设计：
首先假设存储两个链表结点地址的数组分别为list1和list2，我们知道如果这两个链表有重复的结点，则重复的结点必然为于这两个链表的末尾部分，
所以根据这个性质，我们可以从两个链表的末端开始同时从后向前遍历，如果两个链表中有空链表或者末端结点地址不同，显然，两个链表没有相同结
点，直接输出-1，否则不断向前遍历直到到达一个不同的结点地址，那么所要求的相同结点的起始地址就在该不同节点地址的下一个地址。
*/
#include<bits/stdc++.h>
using namespace std;
char data[1000000];//结点地址有5位数字，故这个哈希表数组至少要开到10的6次方
int Next[1000000];//结点地址有5位数字，故这个哈希表数组至少要开到10的6次方
int main(){
    int begin1,begin2,N;//链表1起始地址、链表2起始地址，给出的结点总数
    vector<int> list1,list2;//存储2个链表所有结点地址的vector
    scanf("%d%d%d",&begin1,&begin2,&N);
    while(N--){
        int a;
        scanf("%d",&a);
        scanf(" %c %d",&data[a],&Next[a]);
    }
    while(begin1!=-1){//存储链表1的所有结点地址
        list1.push_back(begin1);
        begin1=Next[begin1];
    }
    while(begin2!=-1){//存储链表2的所有结点地址
        list2.push_back(begin2);
        begin2=Next[begin2];
    }
    int i=list1.size()-1,j=list2.size()-1;//定义两个索引指向两个链表末端节点
    if(i<0||j<0||list1[i]!=list2[j])//如果两个链表中有空链表或者末端结点地址不同
        printf("-1");//直接输出-1
    else{//两个链表末端节点地址相同
        for(--i,--j;i>=0&&j>=0&&list1[i]==list2[j];--i,--j);//不断向前遍历直到到达一个不同的结点地址
        printf("%05d",list1[i+1]);//输出下一个相同结点的地址
    }
    return 0;
}

/*
算法设计：
还有一种方法是利用set的去重特性，将两个链表中所有节点都放入set中，比较两个链表结点总数和set中结点数量的多少，显然，如果两者相等，
说明没有重复结点，输出-1；否则用两个链表结点总数减去set中结点数量得到的差（假设为k）即为相同结点的数量，任意一个链表中其从末尾向前
的第k个结点即为相同结点的起始结点，输出该结点的地址即可。
*/
#include<bits/stdc++.h>
using namespace std;
char data[1000000];//结点地址有5位数字，故这个哈希表数组至少要开到10的6次方
int Next[1000000];//结点地址有5位数字，故这个哈希表数组至少要开到10的6次方
int main(){
    int begin1,begin2,N;//链表1起始地址、链表2起始地址，给出的结点总数
    vector<int> list1,list2;//存储2个链表所有结点地址的vector
    unordered_set<int>s;//不需要对set中结点排序，可以用unordered_set
    scanf("%d%d%d",&begin1,&begin2,&N);
    while(N--){
        int a;
        scanf("%d",&a);
        scanf(" %c %d",&data[a],&Next[a]);
    }
    while(begin1!=-1){
        list1.push_back(begin1);
        s.insert(begin1);
        begin1=Next[begin1];
    }
    while(begin2!=-1){
        list2.push_back(begin2);
        s.insert(begin2);
        begin2=Next[begin2];
    }
    int k=list1.size()+list2.size()-s.size();//相同结点的数量
    if(k>0)//有相同结点
        printf("%05d",list1[list1.size()-k]);//输出
    else if(k==0)//没有相同结点
        printf("-1");//输出-1
    return 0;
}


/*
算法设计：
定义一个bool类型的辅助数组hashTable，数组下标表示地址，元素均初始化为false。首先遍历第一个链表的所有节点地址，将hashTable中对应地址
下的元素置为true。遍历第二个链表节点地址，如果遇到对应的hashTable元素为true的即为第一个相同结点地址，直接输出即可；如果第二个链表所
有节点均遍历完仍没有找到，输出-1。
*/
#include<bits/stdc++.h>
using namespace std;
char data[1000000];//结点地址有5位数字，故这个哈希表数组至少要开到10的6次方
int Next[1000000];//结点地址有5位数字，故这个哈希表数组至少要开到10的6次方
bool hashTable[1000000];//结点地址有5位数字，故这个哈希表数组至少要开到10的6次方
int main(){
    int begin1,begin2,N;//链表1起始地址、链表2起始地址，给出的结点总数
    scanf("%d%d%d",&begin1,&begin2,&N);
    while(N--){
        int a;
        scanf("%d",&a);
        scanf(" %c %d",&data[a],&Next[a]);
    }
    while(begin1!=-1){
        hashTable[begin1]=true;
        begin1=Next[begin1];
    }
    while(begin2!=-1){
        if(hashTable[begin2]){
            printf("%05d",begin2);
            return 0;
        }
        begin2=Next[begin2];
    }
    printf("-1");//输出-1
    return 0;
}








