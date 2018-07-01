/*
时间：2018/7/1
作者：楼浩然
题目：
1069 微博转发抽奖（20 分）
小明 PAT 考了满分，高兴之余决定发起微博转发抽奖活动，从转发的网友中按顺序每隔 N 个人就发出一个红包。请你编写程序帮助他确定中奖名单。

输入格式：
输入第一行给出三个正整数 M（≤ 1000）、N 和 S，分别是转发的总量、小明决定的中奖间隔、以及第一位中奖者的序号（编号从 1 开始）。随后 M 行，顺序给出转发微博的网友的昵称（不超过 20 个字符、不包含空格回车的非空字符串）。

输出格式：
按照输入的顺序输出中奖名单，每个昵称占一行。如果没有人中奖，则输出 Keep going...。

输入样例 1：
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
输出样例 1：
PickMe
Imgonnawin!
TryAgainAgain
输入样例 2：
2 3 5
Imgonnawin!
PickMe
输出样例 2：
Keep going...
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    int M,N,S; //分别代表转发的总量，小明决定的中奖间隔，以及第一位中奖者的序号
    scanf("%d %d %d",&M,&N,&S);
    char ID[M][21];
    char id[M*22];  //用于记录获奖ID
    id[0] = '\0';
    int i;
    for(i=0 ; i<M ; i++)
        scanf("%s",ID[i]);
    if(S>M)
        printf("Keep going...\n");
    else
    {
        while(S<=M)
        {
            if(strstr(id,ID[S-1])==0)
            {
                strcat(id,ID[S-1]);
                strcat(id," ");
                printf("%s\n",ID[S-1]);
                S = S + N;
            }
            else
            {
                S = S + 1;
            }
        }
    }
    return 0;

}

/*
总结：
1.第二次获奖会被忽略，选择后面的网友
2.用strcat()函数将获奖ID合并为一个长字符串，然后用strstr()函数来判断新的ID是否存在于获奖ID字符串中
*/
