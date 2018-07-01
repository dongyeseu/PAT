/*
时间：2018/7/1
作者：楼浩然
题目：
1059 C语言竞赛（20 分）

输入格式：
输入第一行给出一个正整数,是参赛者人数。随后 N 行给出最终排名，每行按排名顺序给出一位参赛者的 ID（4 位数字组成）。接下来给出一个正整数 K 以及 K 个需要查询的 ID。

输出格式：
对每个要查询的 ID，在一行中输出 ID: 奖品，其中奖品或者是 Mystery Award（神秘大奖）、或者是 Minion（小黄人）、或者是 Chocolate（巧克力）。如果所查 ID 根本不在排名里，打印 Are you kidding?（耍我呢？）。如果该 ID 已经查过了（即奖品已经领过了），打印 ID: Checked（不能多吃多占）。

输入样例：
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
输出样例：
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?
*/
#include <stdio.h>
#include <math.h>

//思路：用一个大数组的下标存储标号，用1~N代表排名，用-1代表已经查询过了
int Is_prime(int z)
{
    int item = (int)sqrt(z)+1;
    int j;
    if (z<2)
        return 0;
    else if (z == 2 || z == 3)
        return 1;
    else if (z%6!=1 && z%6!=5)
        return 0;
    for (j = 5; j < item; j+=6)
    {
        if (z%j==0 || z%(j+2)==0)
            return 0;
    }
    return 1;
}

int main(void)
{
    int ID[10000] = {0};
    int N;//代表学生人数
    scanf("%d",&N);
    int i;
    int id;
    for(i=1 ; i<=N ; i++)
    {
        scanf("%d",&id);
        ID[id] = i;
    }
    int K; //需要查询的ID个数
    scanf("%d",&K);
    for(i=0 ; i<K ; i++)
    {
        scanf("%d",&id);
        if(ID[id] == 0)
            printf("%04d: Are you kidding?\n",id);
        else if(ID[id] == -1)
            printf("%04d: Checked\n",id);
        else if(ID[id] == 1)
        {
            printf("%04d: Mystery Award\n",id);
            ID[id] = -1;
        }
        else if(Is_prime(ID[id]))
        {
            printf("%04d: Minion\n",id);
            ID[id] = -1;
        }
        else
        {
            printf("%04d: Chocolate\n",id);
            ID[id] = -1;
        }
    }
    return 0;
}
/*
总结：
1.用大数组的下标来记录ID，根据值的不同来确定是否存在、是否查询过或者排名
*/




/*
用新的数组来记录查询过的ID，这样就不会破坏ID的排名了

#include <iostream>
#include <set>
#include <cmath>
using namespace std;
int ran[10000];
bool isprime(int a) {
    if(a <= 1) return false;
    int Sqrt = sqrt((double)a);
    for(int i = 2; i <= Sqrt; i++) {
        if(a % i == 0)
            return false;
    }
    return true;
}
int main() {
    int n, k;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int id;
        scanf("%d", &id);
        ran[id] = i + 1;
    }
    scanf("%d", &k);
    set<int> ss;
    for(int i = 0; i < k; i++) {
        int id;
        scanf("%d", &id);
        printf("%04d: ", id);
        if(ran[id] == 0) {
            printf("Are you kidding?\n");
            continue;
        }
        if(ss.find(id) == ss.end()) {
            ss.insert(id);
        } else {
            printf("Checked\n");
            continue;
        }
        if(ran[id] == 1) {
            printf("Mystery Award\n");
        }else if(isprime(ran[id])) {
            printf("Minion\n");
        }else {
            printf("Chocolate\n");
        }
    }
    return 0;
}
*/

/*
给数组元素赋值时，就用不同情况代表的数字进行分类，然后使用switch函数判断输出
#include <stdio.h>

int isPrime(int n)
{
    if(n == 1) return 0;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int main()
{
    int award[10000] = {0}, N, K, ID;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &ID);
        if(i == 0)              award[ID] = 1;
        else if(isPrime(i + 1)) award[ID] = 2;
        else                    award[ID] = 3;
    }
    scanf("%d", &K);
    for(int i = 0; i < K; i++)
    {
        scanf("%d", &ID);
        switch(award[ID])
        {
            case 0: printf("%04d: Are you kidding?\n", ID);               break;
            case 1: printf("%04d: Mystery Award\n", ID);  award[ID] = 4;  break;
            case 2: printf("%04d: Minion\n", ID);         award[ID] = 4;  break;
            case 3: printf("%04d: Chocolate\n", ID);      award[ID] = 4;  break;
            case 4: printf("%04d: Checked\n", ID);                        break;
        }
    }

    return 0;
}

*/
