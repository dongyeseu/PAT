/*
时间：2018/6/24 22点34分
作者：楼浩然
题目：
1067 试密码（20 分）
当你试图登录某个系统却忘了密码时，系统一般只会允许你尝试有限多次，当超出允许次数时，账号就会被锁死。本题就请你实现这个小功能。

输入格式：
输入在第一行给出一个密码（长度不超过 20 的、不包含空格、Tab、回车的非空字符串）和一个正整数 N（≤ 10），分别是正确的密码和系统允许尝试的次数。随后每行给出一个以回车结束的非空字符串，是用户尝试输入的密码。输入保证至少有一次尝试。当读到一行只有单个 # 字符时，输入结束，并且这一行不是用户的输入。

输出格式：
对用户的每个输入，如果是正确的密码且尝试次数不超过 N，则在一行中输出 Welcome in，并结束程序；如果是错误的，则在一行中按格式输出 Wrong password: 用户输入的错误密码；当错误尝试达到 N 次时，再输出一行 Account locked，并结束程序。

输入样例 1：
Correct%pw 3
correct%pw
Correct@PW
whatisthepassword!
Correct%pw
#
输出样例 1：
Wrong password: correct%pw
Wrong password: Correct@PW
Wrong password: whatisthepassword!
Account locked
输入样例 2：
cool@gplt 3
coolman@gplt
coollady@gplt
cool@gplt
try again
#
输出样例 2：
Wrong password: coolman@gplt
Wrong password: coollady@gplt
Welcome in
*/

//最后一个测试点过不去
#include <stdio.h>
#include <string.h>

int main(void)
{
    char password[21];  //正确的密码
    int N; //能够尝试的次数
    scanf("%s %d",password,&N);
    while(getchar()!='\n')
        continue;
    char try[N+1][1000];// 尝试输入的密码
    int i = 0; // 循环计数
    char t[1000];
    while(gets(t)&&t[0]!='#')
    {
        if(i<N+1)
        {
            strcpy(try[i],t);
            i++;
        }
    }
 //   int r = i; //r代表try数组中有多少字符串
    for(i=0 ; i<N ; i++)
    {
        if(strcmp(password,try[i])==0)
        {
            printf("Welcome in\n");
            break;
        }
        else
        {
            printf("Wrong password: %s\n",try[i]);
//            puts(try[i]);
            if(i==N-1)
            {
                printf("Account locked\n");
                break;
            }

        }
    }

    return 0;

}


/*
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main()
{
    int N;
    char c, correct[21], user[21];

    scanf("%s %d", correct, &N);
    while(getchar() != '\n');
    while(N--)
    {
        scanf("%20[^\n]", user);
        c = ungetc(getchar(), stdin);
        if(!strcmp(user, "#") && c == '\n')
        {
            break;
        }
        else if(!strcmp(correct, user) && c == '\n')
        {
            puts("Welcome in");
            break;
        }
        else
        {
            printf("Wrong password: %s", user);
            while(putchar(getchar()) != '\n') ;
            if(!N)  puts("Account locked");
        }
    }

    return 0;
}

*/
