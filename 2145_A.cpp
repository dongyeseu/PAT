/*
1145 Hashing - Average Search Time（25 分）提问
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table first. Then try to find another sequence of integer keys from the table and output the average search time (the number of comparisons made to find whether or not the key is in the table). The hash function is defined to be H(key)=key%TSize where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.

Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.

Input Specification:
Each input file contains one test case. For each case, the first line contains 3 positive numbers: MSize, N, and M, which are the user-defined table size, the number of input numbers, and the number of keys to be found, respectively. All the three numbers are no more than 10
​4
​​ . Then N distinct positive integers are given in the next line, followed by M positive integer keys in the next line. All the numbers in a line are separated by a space and are no more than 10
​5
​​ .

Output Specification:
For each test case, in case it is impossible to insert some number, print in a line X cannot be inserted. where X is the input number. Finally print in a line the average search time for all the M keys, accurate up to 1 decimal place.

Sample Input:
4 5 4
10 6 4 15 11
11 4 15 2
Sample Output:
15 cannot be inserted.
2.8
*/

//题目大意理解很重要
//第一行数据考察其是否能够插入
//第二行考察这个数字书否存在于哈希表中
#include <iostream>
#include <math.h>
#include <vector>
#include <cstdio>
using namespace std;
bool IsPrime(int n)
{
    int k, item = (int)sqrt(n)+1;
    if(n<=1)
        return false;
    else if (n==2 || n==3)
        return true;
    else if (n%6!=1 && n%6!=5)
        return false;
    for(k = 5 ; k<=item ; k+=6)
    {
        if(n%k==0 || n%(k+2)==0)
            return false;
    }
    return true;
}
int Size(int MSize)
{
    while(!IsPrime(MSize))
        MSize++;
    return MSize;
}

int main()
{
    int MSize,N,M; // the user-defined table size, the number of input numbers, and the number of keys to be found
    cin>>MSize>>N>>M;
    MSize = Size(MSize);
    vector<int>Hash(MSize,0);
    int i,j,t,cnt,temp;//分别为循环计数，插入寻找次数，临时变量
    for(i=0;i<N;i++)
    {
        cin>>temp;
        int flag = 0;
        for(j=0 ; j<MSize ; j++)
        {
            t = (temp + j*j)%MSize;
            if(Hash[t]==0)
            {
                Hash[t] = temp;
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            printf("%d cannot be inserted.\n",temp);
        }
    }
    double sum = 0;
    for(i=0 ; i<M ; i++)
    {
        cin>>temp;
        int cnt = 1;
        for(j=0 ; j<MSize ; j++)
        {
            t = (temp + j*j) % MSize;
            if(Hash[t]==0 || Hash[t] == temp)
                break;
            cnt++;
        }
        sum += cnt;
    }

    printf("%.1f",sum/M);
    return 0;
}


//他山之玉
//刘畴
/*
题目大意：给定一个序列，用平方探测法解决哈希冲突，然后给出m个数字，如果这个数字不能够被插入就输出”X cannot be inserted.”，然后输出这m个数字的平均
查找时间
分析：先找到大于tsize的最小的素数为真正的tsize，然后建立一个tsize长度的数组。首先用平方探测法插入数字a，每次pos = (a + j * j) % tsize，j是
从0～tsize-1的数字，如果当前位置可以插入就将a赋值给v[pos]，如果一次都没有能够插入成功就输出”X cannot be inserted.”。其次计算平均查找时间，一开
始cnt=1表示查找一次，每次计算pos = (a + j * j) % tsize，如果v[pos]处正是a则查找到了，所以退出循环，如果v[pos]处不存在数字表示没查找到，那么也要
退出循环，最后将cnt累加到ans里表示总的查找时间，最后除以m得到平均查找时间然后输出～
*/
#include <iostream>
#include <vector>
using namespace std;
bool isprime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
int main() {
    int tsize, n, m, a;
    scanf("%d %d %d", &tsize, &n, &m);
    while(!isprime(tsize)) tsize++;
    vector<int> v(tsize);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        int flag = 0;
        for (int j = 0; j < tsize; j++) {
            int pos = (a + j * j) % tsize;
            if (v[pos] == 0) {
                v[pos] = a;
                flag = 1;
                break;
            }
        }
        if (!flag) printf("%d cannot be inserted.\n", a);
    }
    double ans = 0.0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        int cnt = 1;
        for (int j = 0; j < tsize; j++) {
            int pos = (a + j * j) % tsize;
            if (v[pos] == a || v[pos] == 0) break;
            cnt++;
        }
        ans += cnt;
    }
    printf("%.1lf\n", ans / m);
    return 0;
}
