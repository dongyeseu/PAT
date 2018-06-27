/*
时间：2018/6/27 15点39分
作者：楼浩然
题目：
1043 输出PATest(20)（20 分）
给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按“PATestPATest....”这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按PATest的顺序打印，直到所有字符都被输出。

输入格式：

输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。

输出格式：

在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：

redlesPayBestPATTopTeePHPereatitAPPT
输出样例：

PATestPATestPTetPTePePee
*/
#include <stdio.h>
#include <string.h>
int cmp(const void * a,const void * b){return (*(int *)b - *(int *)a);}

int IsMax(int * num,int N)
{
    int max = 0;
    int i;
    for(i=0 ; i<N ; i++)
    {
        if(num[i]>max)
            max = num[i];
    }
    return max;
}

int main(void)
{
    char PATest[10001];
    scanf("%s",PATest);
    int num[6]={0};
    int len = strlen(PATest);
    int i;
    for(i=0 ; i<len ; i++)
    {
        char ch = PATest[i];
        switch(ch)
        {
        case 'P':
            num[0]++;
            break;
        case 'A':
            num[1]++;
            break;
        case 'T':
            num[2]++;
            break;
        case 'e':
            num[3]++;
            break;
        case 's':
            num[4]++;
            break;
        case 't':
            num[5]++;
            break;
        default:
            break;
        }
    }
    int Max = IsMax(num,6);
//    for(i=0 ; i<6 ; i++)
//        printf("%d\n",num[i]);
    for(i=0; i<Max ; i++)
    {
        if(num[0]!=0)
        {
            printf("P");
            num[0]--;
        }
        if(num[1]!=0)
        {
            printf("A");
            num[1]--;
        }
        if(num[2]!=0)
        {
            printf("T");
            num[2]--;
        }
        if(num[3]!=0)
        {
            printf("e");
            num[3]--;
        }
        if(num[4]!=0)
        {
            printf("s");
            num[4]--;
        }
        if(num[5]!=0)
        {
            printf("t");
            num[5]--;
        }
    }
    printf("\n");
    return 0;

}
