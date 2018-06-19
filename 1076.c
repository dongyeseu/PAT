/*
时间：2018/6/19 22点04分
作者：楼浩然
题目：
输入格式：
输入第一行给出一个正整数 N（≤ 100），随后 N 行，每行按照 编号-答案 的格式给出一道题的 4 个选项，T 表示正确选项，F 表示错误选项。选项间用空格分隔。

输出格式：
在一行中输出 wifi 密码。

输入样例：
8
A-T B-F C-F D-F
C-T B-F A-F D-F
A-F D-F C-F B-T
B-T A-F C-F D-F
B-F D-T A-F C-F
A-T C-F B-F D-F
D-T B-F C-F A-F
C-T A-F B-F D-F
输出样例：
13224143
*/
#include <stdio.h>
int pan_duan(char n){
    if (n == 'A')
        return 1;
    else if (n == 'B')
        return 2;
    else if (n == 'C')
        return 3;
    else if (n == 'D')
        return 4;
}
int main(void)
{
    int N;
    scanf("%d",&N);
    int i,j;
    char ans[8];
    int res[N];
    for(i=0 ; i<N ; i++)
    {
        scanf(" %c-%c %c-%c %c-%c %c-%c",&ans[0],&ans[1],&ans[2],&ans[3],&ans[4],&ans[5],&ans[6],&ans[7]);
        //第一个%c前面要有空格
        for(j=1 ; j<8 ; j+=2)
        {
            if(ans[j] == 'T')
                res[i] = pan_duan(ans[j-1]);
        }
    }
    for (j=0 ; j<N; j++)
        printf("%d",res[j]);
    printf("\n");
    return 0;
}
