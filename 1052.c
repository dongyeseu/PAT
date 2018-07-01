/*
时间：2018/6/30
作者：楼浩然
题目：
1052 卖个萌 (20)（20 分）
萌萌哒表情符号通常由“手”、“眼”、“口”三个主要部分组成。简单起见，我们假设一个表情符号是按下列格式输出的：

[左手]([左眼][口][右眼])[右手]
现给出可选用的符号集合，请你按用户的要求输出表情。

输入格式：

输入首先在前三行顺序对应给出手、眼、口的可选符号集。每个符号括在一对方括号[]内。题目保证每个集合都至少有一个符号，并不超过10个符号；每个符号包含1到4个非空字符。

之后一行给出一个正整数K，为用户请求的个数。随后K行，每行给出一个用户的符号选择，顺序为左手、左眼、口、右眼、右手——这里只给出符号在相应集合中的序号（从1开始），数字间以空格分隔。

输出格式：

对每个用户请求，在一行中输出生成的表情。若用户选择的序号不存在，则输出“Are you kidding me? @\/@”。

输入样例：

[╮][╭][o][~\][/~]  [<][>]
 [╯][╰][^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^]  ...
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3
输出样例：

╮(╯▽╰)╭
<(@Д=)/~
o(^ε^)o
Are you kidding me? @\/@
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char symbol[3][10][5]={0};
    int i,j;
    char ch;
    int length[3]={0};
 //   int z=0;
    for(i=0 ; i<3 ; i++)
    {
        for(j=0 ; (ch=getchar())!='\n';)
        {
            if(ch=='[')
                scanf("%[^]]",symbol[i][j++]);
        }
    }
    int N;
    int m[5];
    scanf("%d",&N);
    for(i=0 ; i<N ; i++){
        int j;
        for(j=0 ; j<5 ; j++)
            scanf("%d",&m[j]);
        if(m[0]>0&&m[0]<=10&&*symbol[0][--m[0]]&&m[1]>0&&m[1]<=10&&*symbol[1][--m[1]]&&m[2]>0&&m[2]<=10&&*symbol[2][--m[2]]&&m[3]>0&&m[3]<=10&&*symbol[1][--m[3]]&&m[4]>0&&m[4]<=10&&*symbol[0][--m[4]])
            printf("%s(%s%s%s)%s\n",symbol[0][m[0]],symbol[1][m[1]],symbol[2][m[2]],symbol[1][m[3]],symbol[0][m[4]]);
        else
            printf("Are you kidding me? @\\/@\n");
    }
    return 0;
}

/*
总结：
1.scanf("%[^]]")输入函数的应用，意思是到输入到']'为止
2.判断条件的使用：*数组元素意味着取出该元素
*/



/*
#include <stdio.h>
//https://en.wikipedia.org/wiki/Variable-width_encoding
int main()
{
    char c, symbols[3][10][5] = {0};
    int symbol,index;
    for(symbol = 0; symbol < 3; symbol++)
        for(index = 0; (c = getchar()) != '\n'; )
            if(c == '[') scanf("%[^]]", symbols[symbol][index++]);

    int N, m[5];
    scanf("%d", &N);
    int i,j;
    for(i = 0; i < N; i++)
    {
        for(j = 0;j < 5; j++)  scanf("%d", m + j);
        if(m[0] > 0 && m[0] <= 10 && *symbols[0][--m[0]]
        && m[1] > 0 && m[0] <= 10 && *symbols[1][--m[1]]
        && m[2] > 0 && m[0] <= 10 && *symbols[2][--m[2]]
        && m[3] > 0 && m[0] <= 10 && *symbols[1][--m[3]]
        && m[4] > 0 && m[0] <= 10 && *symbols[0][--m[4]])
            printf("%s(%s%s%s)%s\n", symbols[0][m[0]], symbols[1][m[1]],
                   symbols[2][m[2]], symbols[1][m[3]], symbols[0][m[4]]);
        else
            puts("Are you kidding me? @\\/@");
    }

    return 0;
}

*/
