/*
时间：2018/7/2
作者：楼浩然
题目：
1081 检查密码（15 分）
本题要求你帮助某网站的用户注册模块写一个密码合法性检查的小功能。该网站要求用户设置的密码必须由不少于6个字符组成，并且只能有英文字母、数字和小数点 .，还必须既有字母也有数字。

输入格式：
输入第一行给出一个正整数 N（≤ 100），随后 N 行，每行给出一个用户设置的密码，为不超过 80 个字符的非空字符串，以回车结束。

输出格式：
对每个用户的密码，在一行中输出系统反馈信息，分以下5种：

如果密码合法，输出Your password is wan mei.；
如果密码太短，不论合法与否，都输出Your password is tai duan le.；
如果密码长度合法，但存在不合法字符，则输出Your password is tai luan le.；
如果密码长度合法，但只有字母没有数字，则输出Your password needs shu zi.；
如果密码长度合法，但只有数字没有字母，则输出Your password needs zi mu.。
输入样例：
5
123s
zheshi.wodepw
1234.5678
WanMei23333
pass*word.6
输出样例：
Your password is tai duan le.
Your password needs shu zi.
Your password needs zi mu.
Your password is wan mei.
Your password is tai luan le.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check(char * password)
{
    int len = strlen(password);
    if(len<6)
        return 1;
    int i;
    int count_num = 0 , count_alp = 0;
    for(i=0 ; i<len ; i++)
    {
        if(!isalpha(password[i])&&!isdigit(password[i])&&password[i]!='.')
            return 2;
        else if(isalpha(password[i]))
            count_alp++;
        else if(isdigit(password[i]))
            count_num++;
    }
    if(count_alp!=0 && count_num == 0)
        return 3;
    else if(count_alp == 0 && count_num != 0 )
        return 4;
    else
        return 0;
}

int main(void)
{
    int N;//代表输入的密码个数
    scanf("%d",&N);
    int i;
    while(getchar()!='\n')
        continue;
    for(i=0 ; i<N ; i++)
    {
        char password[90];
        gets(password);
        switch(check(password))
        {
        case 0:
            printf("Your password is wan mei.\n");
            break;
        case 1:
            printf("Your password is tai duan le.\n");
            break;
        case 2:
            printf("Your password is tai luan le.\n");
            break;
        case 3:
            printf("Your password needs shu zi.\n");
            break;
        case 4:
            printf("Your password needs zi mu.\n");
            break;
        default:
            break;
        }
    }
    return 0;

}

/*
总结：
1.学会使用《ctype.h>中的isalpha()和isdigit()来判断字符中的字母和数字
2.在使用gets()函数整行输入字符串时，一开始前面必要要用getchar()清除上次输入留下的不法字符
*/
