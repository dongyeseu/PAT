/*
1144 The Missing Number（20 分）
Given N integers, you are supposed to find the smallest positive integer that is NOT in the given list.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N . Then N integers are given in the next line, separated by spaces. All the numbers are in the range of int.

Output Specification:
Print in a line the smallest positive integer that is missing from the input list.

Sample Input:
10
5 -25 9 6 1 3 4 2 5 17
Sample Output:
7
*/

#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

int main()
{
    map<int,int>num;
    int N;
    cin>>N;
    int i,temp;
    for(i=0 ; i<N ; i++)
    {
        scanf("%d",&temp);
        num[temp]++;
    }
    for(i=1 ; i<=N+1 ; i++)
    {
        if(num.count(i)==0)
        {
            cout<<i<<"\n";
            return 0;
        }
    }
    return 0;
}

//他山之玉
//柳婼
/*
题目大意：给n个数字，找到不在这个数字列表里面的最小的正整数
分析：将每个数字出现的次数存储在map里面，num从1开始，如果m[num] == 0说明不存在，则输出这个num～
/*
#include <iostream>
#include <map>
using namespace std;
int main() {
    int n, a, num = 0;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> a;
        m[a]++;
    }
    while(++num)
        if (m[num] == 0) break;
    cout << num;
    return 0;
}
