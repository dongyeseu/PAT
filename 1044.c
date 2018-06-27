/*
时间：2018/6/27 16点34分
作者：楼浩然
题目：
1044 火星数字(20)（20 分）
火星人是以13进制计数的：

地球人的0被火星人称为tret。
地球人数字1到12的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的12个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
例如地球人的数字“29”翻译成火星文就是“hel mar”；而火星文“elo nov”对应地球数字“115”。为了方便交流，请你编写程序实现地球和火星数字之间的互译。

输入格式：

输入第一行给出一个正整数N（<100），随后N行，每行给出一个[0, 169)区间内的数字 —— 或者是地球文，或者是火星文。

输出格式：

对应输入的每一行，在一行中输出翻译后的另一种语言的数字。

输入样例：

4
29
5
elo nov
tam
输出样例：

hel mar
may
115
13
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    int N;//输入样例数量
    scanf("%d",&N);
    while(getchar()!='\n')
        continue;
    char a[N][8];
    int i;
    int sum[N];
    char Marz_1[13][5] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
    char Marz_2[13][4] = {"0","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
    for(i=0 ; i<N ; i++)
    {
        int j=0;
        char ch;
        while((ch = getchar())!='\n')
        {
            a[i][j] = ch;
            j++;
        }
        a[i][j] = '\0';
    }
//    for(i=0 ; i<N ; i++)
 //       printf("%s\n",a[i]);
    for(i=0 ; i<N ; i++)
    {
        int len = strlen(a[i]);
        if(len<=3 && a[i][0]>='0'&&a[i][0]<='9')
        {
            int res = 0;
            int j;
            for(j=0 ; j<len ; j++)
            {
                res = res*10 + (a[i][j] - '0');
            }
            if(res<=12)
                printf("%s\n",Marz_1[res]);
            else
            {
                int r1 = res%13;
                int r2 = res/13;
                if(r1!=0)
                    printf("%s %s\n",Marz_2[r2],Marz_1[r1]);
                else
                    printf("%s\n",Marz_2[r2]);

            }
        }
        else
        {
            char s1[4];
            char s2[4];
            int j = 0;
            int len = strlen(a[i]);
            if(len==3)
            {
                for(j ; j<4 ; j++)
                {
                    s1[j] = a[i][j];
                }
                int z;
                for(z=0 ; z<13 ; z++)
                {
                    if(!strcmp(s1,Marz_1[z]))
                    {
                        printf("%d\n",z);
                        break;
                    }
                    if(!strcmp(s1,Marz_2[z]))
                    {
                        printf("%d\n",(z)*13);
                        break;
                    }

                }
            }
            else
            {
                for(j=0 ; j<3 ; j++)
                {
                    s1[j] = a[i][j];
                }
                s1[3] = '\0';
                for(j=4;j<7;j++)
                {
                    s2[j-4] = a[i][j];
                }
                s2[3] = '\0';
                int r_1 = 0;
                int r_2 = 0;
                int z;
                for(z=0 ; z<13 ; z++)
                {
                    if(!strcmp(s1,Marz_2[z]))
                    {
                        r_1 = z;
                    }
                    if(!strcmp(s2,Marz_1[z]))
                    {
                        r_2 = z;
                    }
                }
                int r3 = r_1*13+r_2;
                printf("%d\n",r3);

            }

        }
    }
    return 0;
}

//更简洁的版本
/*
#include<stdio.h>
#include<string.h>
typedef struct tempString
{
    char *mars;
}tempString;
int main(){
    int n,i,j,num=0,len;
    char temp[10];
    tempString low[13]={"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    tempString high[13]={0,"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    scanf("%d",&n);
    gets(temp);
    for(i=0;i<n;i++){
        gets(temp);
        num=0;
        len=strlen(temp);
        if(temp[0]>='0'&&temp[0]<='9'){//数字
            for(j=0;j<len;j++){
                num=num*10+temp[j]-'0';
            }
            if(num<13)
                printf("%s\n",low[num]);
            else{
                if(num%13==0) printf("%s\n",high[num/13]);
                else printf("%s %s\n",high[num/13],low[num%13]);
            }
        }else{//火星数字
            for(j=1;j<13;j++){
                if(strstr(temp,high[j].mars)!=NULL){
                    num=num+j*13;
                    break;
                }
            }
            for(j=0;j<13;j++){
                if(strstr(temp,low[j].mars)!=NULL){
                    num=num+j;
                    break;
                }
            }
            printf("%d\n",num);
        }
    }
    return 0;
}
*/
