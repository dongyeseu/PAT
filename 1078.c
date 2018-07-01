/*
时间：2018/7/1
作者：楼浩然
题目：
1078 字符串压缩与解压（20 分）
文本压缩有很多种方法，这里我们只考虑最简单的一种：把由相同字符组成的一个连续的片段用这个字符和片段中含有这个字符的个数来表示。例如 ccccc 就用 5c 来表示。如果字符没有重复，就原样输出。例如 aba 压缩后仍然是 aba。

解压方法就是反过来，把形如 5c 这样的表示恢复为 ccccc。

本题需要你根据压缩或解压的要求，对给定字符串进行处理。这里我们简单地假设原始字符串是完全由英文字母和空格组成的非空字符串。

输入格式：
输入第一行给出一个字符，如果是 C 就表示下面的字符串需要被压缩；如果是 D 就表示下面的字符串需要被解压。第二行给出需要被压缩或解压的不超过 1000 个字符的字符串，以回车结尾。题目保证字符重复个数在整型范围内，且输出文件不超过 1MB。

输出格式：
根据要求压缩或解压字符串，并在一行中输出结果。

输入样例 1：
C
TTTTThhiiiis isssss a   tesssst CAaaa as
输出样例 1：
5T2h4is i5s a3 te4st CA3a as
输入样例 2：
D
5T2h4is i5s a3 te4st CA3a as10Z
输出样例 2：
TTTTThhiiiis isssss a   tesssst CAaaa asZZZZZZZZZZ
*
*/

#include <stdio.h>
#include <string.h>

void encode(char * code,int N)
{
    int i;
    int j=1;
    for(i=0;i<N-1;i++)
    {
        if(code[i]!=code[i+1])
        {
            if(j==1)
                printf("%c",code[i]);
            else
                printf("%d%c",j,code[i]);
            j = 1;
        }
        else
        {
            j++;
        }

    }
    if(j==1)
        printf("%c\n",code[N-1]);
    else
        printf("%d%c\n",j,code[N-1]);
}

void decode(char * code, int N)
{
    int i;
    int j = -1;
    for(i=0 ; i<N ; i++)
    {
        if(code[i]>='0' && code[i]<='9')
        {
            if(j==-1)
                j = code[i]-'0';  //当数字还为1位时
            else
                j = j*10 + code[i] - '0';  //当数字大于1位时
        }
        else
        {
            if(j==-1)
                printf("%c",code[i]);
            else
            {
                int z;
                for(z=0 ; z<j ; z++)
                    printf("%c",code[i]);
            }
            j = -1;
        }
    }
    printf("\n");
}


int main(void)
{
    char ch;
    scanf(" %c",&ch);
    while(getchar()!='\n')
        continue;
    char code[2000];
    gets(code);
//    printf("%s",code);
    int len = strlen(code);
    switch(ch)
    {
    case 'C':
        encode(code,len);
        break;
    case 'D':
        decode(code,len);
        break;
    }

    return 0;
}

/*
1.使用switch语句来判断是解码还是加码
2.使用gets()语句来保证整条语句的输入
3.使用decode和encode函数来解码和加码
*/

/*
#include <stdio.h>

void compress()
{
    char previous = getchar(), current;
    int count = 1;
    
    while((current = getchar()))
    {
        if(current == previous)
        {
            count++;                /* Increament count 
        }
        else
        {
            if(count > 1)           /* Only print if count > 1 
                printf("%d", count);
            putchar(previous);
            previous = current;
            count = 1;
        }
        
        if(current == '\n')         /* Don't put this in while() 
            break;
    }
}

void decompress()
{
    char c;
    int count = 0;
    
    while((c = getchar()) != '\n')
    {
        if(c >= '0' && c <= '9') /* If it is number 
        {
            count = count * 10 + c - '0';    Accumulate count 
        }
        else                     If it is not number 
        {
            if(count == 0)                   No number before char 
                count = 1;                      /* print once 
            for(int i = 0; i < count; i++)  /* Or print 'count' times 
                putchar(c);
            count = 0;                      /* Reset 'count' 
        }
    }
}

int main()
{
    switch(getchar())
    {
        case 'C':
            while(getchar() != '\n');
            compress();
            break;
        case 'D':
            while(getchar() != '\n');
            decompress();
            break;
        default:
            break;
    }
    
    return 0;
}
*/
