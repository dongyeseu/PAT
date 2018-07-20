/*
1078 Hashing (25)（25 分）
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers. The hash function is defined to be "H(key) = key % TSize" where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.

Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers: MSize (<=10^4^) and N (<=MSize) which are the user-defined table size and the number of input numbers, respectively. Then N distinct positive integers are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print "-" instead.

Sample Input:

4 4
10 6 4 15
Sample Output:

0 1 4 -
*/

#include <iostream>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

bool IsPrime(int m)
{
    int item = (int)sqrt(m)+1;
    int j;
    if(m<=1)
        return false;
    else if(m==2 || m==3)
        return true;
    else if(m%6!=1 && m%6!=5)
        return false;
    for(j=5 ; j<=item ; j+=6)
    {
        if(m%j==0 || m%(j+2)==0)
            return false;
    }
    return true;
}

int Prime(int m)
{
    while(!IsPrime(m))
        m++;
    return m;
}

int main()
{
    int MSize,NSize;
    cin>>MSize>>NSize;
    vector<int>Temp(NSize);
    MSize = Prime(MSize);
    set<int>HASH;
    int i , temp;
    for(i=0 ; i<NSize ; i++)
    {
        cin>>Temp[i];
    }
    for(i=0 ; i<NSize ; i++)
    {
        temp = Temp[i];
        temp = temp % MSize;
        if(i!=0)
            cout<<" ";
        if(HASH.count(temp)!=0)
        {
            int z;
            int flag = 0;
            for(z=1 ; z<MSize ; z++)
            {
                temp = Temp[i];
                temp = temp + pow(z,2);
                temp = temp %MSize;
                if(HASH.count(temp)==0)
                {
                    flag = 1;
                    HASH.insert(temp);
                    cout<<temp;
                    break;
                }
            }
            if(flag)
                continue;
            else
                cout<<"-";
        }
        else
        {
            cout<<temp;
            HASH.insert(temp);
        }
    }
    cout<<"\n";
    return 0;
}


//他山之玉
//柳婼
/*
分析：先解决size是否为素数，不是素数就要重新赋值的问题
然后根据二次方探查法：
– 如果hashTable里面key % size的下标对应的hashTable为false,说明这个下标没有被使用过，直接输出。否则step步长从1加到size-1，一次次尝试是否能使index = (key + step * step) % size;所对应的位置没有元素，如果都没有找到就输出“-”，否则就输出这个找到的元素的位置。~~~~
– 注意 是(key + step * step) % size 而不是(key % size + step * step) 
*/
#include <iostream>
bool isprime(int a) {
    if(a == 1) return false;
    for(int i = 2; i * i <= a; i++)
        if(a % i == 0)
            return false;
    return true;
}
int func(int a) {
    while(isprime(a) == false) a++;
    return a;
}
bool hashTable[10010];
int main() {
    int MSize, n, key;
    scanf("%d %d", &MSize, &n);
    int size = func(MSize);
    for(int i = 0; i < n; i++) {
        scanf("%d", &key);
        int index = key % size;
        if(hashTable[index] == false) {
            hashTable[index] = true;
            if(i != 0) printf(" ");
            printf("%d", index);
        } else {
            int flag = 0;
            for(int step = 1; step < size; step++) {
                index = (key + step * step) % size;
                if(hashTable[index] == false) {
                    hashTable[index] = true;
                    flag = 1;
                    if(i != 0) printf(" ");
                    printf("%d", index);
                    break;
                }
            }
            if(flag == 0) {
                if(i != 0) printf(" ");
                printf("-");
            }
        }
    }
    return 0;
}
