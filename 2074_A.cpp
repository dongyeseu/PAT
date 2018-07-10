/*
1074 Reversing Linked List (25)（25 分）
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K = 3, then you must output 3→2→1→6→5→4; if K = 4, you must output 4→3→2→1→5→6.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 10^5^) which is the total number of nodes, and a positive K (<=N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:

00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:

00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct ListNode
{
    int id;
    int value;
    int next;
};

int main()
{
    vector<struct ListNode>num(100000);
    vector<struct ListNode>res;
    int FirstAdrres,N,K;
    cin>>FirstAdrres>>N>>K;
    int i;
    for(i=0 ; i<N ; i++)
    {
        struct ListNode temp;
        cin>>temp.id>>temp.value>>temp.next;
        num[temp.id] = temp;
    }
    for(i=FirstAdrres ; i!=-1 ; i = num[i].next)
    {
        res.push_back(num[i]);
    }
    num.clear();
    int lne = res.size();
    auto k = res.begin();
    for(i = K ; i<=lne ; i+=K)     //这里的判断条件必须为<=，否则有可能最后一部分数据无法reverse
    {
        reverse(k,k+K);
        k = k+K;
    }
    for(i=0 ; i<lne ; i++)
    {
        if(i!=lne-1)
            printf("%05d %d %05d\n",res[i].id,res[i].value,res[i+1].id);
        else
            printf("%05d %d -1\n",res[i].id,res[i].value);
    }
    return 0;
}

//他山之玉
//柳婼
/*
#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
    int first, k, n, sum = 0;
    cin >> first >> n >> k;
    int temp, data[100005], next[100005], list[100005], result[100005];
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> data[temp] >> next[temp];
    }
    while (first != -1) {
        list[sum++] = first;
        first = next[first];
    }
    for (int i = 0; i < sum; i++) result[i] = list[i];
    for (int i = 0; i < (sum - sum % k); i++)
        result[i] = list[i / k * k + k - 1 - i % k];
    for (int i = 0; i < sum - 1; i++)
        printf("%05d %d %05d\n", result[i], data[result[i]], result[i + 1]);
    printf("%05d %d -1", result[sum - 1], data[result[sum - 1]]);
    return 0;
}*/
