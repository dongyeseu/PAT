/*
时间：2018/7/1
作者：楼浩然
题目：
1055 集体照 (25)（25 分）
拍集体照时队形很重要，这里对给定的N个人K排的队形设计排队规则如下：

每排人数为N/K（向下取整），多出来的人全部站在最后一排；
后排所有人的个子都不比前排任何人矮；
每排中最高者站中间（中间位置为m/2+1，其中m为该排人数，除法向下取整）；
每排其他人以中间人为轴，按身高非增序，先右后左交替入队站在中间人的两侧（例如5人身高为190、188、186、175、170，则队形为175、188、190、186、170。这里假设你面对拍照者，所以你的左边是中间人的右边）；
若多人身高相同，则按名字的字典序升序排列。这里保证无重名。
现给定一组拍照人，请编写程序输出他们的队形。

输入格式：

每个输入包含1个测试用例。每个测试用例第1行给出两个正整数N（<=10000，总人数）和K（<=10，总排数）。随后N行，每行给出一个人的名字（不包含空格、长度不超过8个英文字母）和身高（[30, 300]区间内的整数）。

输出格式：

输出拍照的队形。即K排人名，其间以空格分隔，行末不得有多余空格。注意：假设你面对拍照者，后排的人输出在上方，前排输出在下方。

输入样例：

10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159
输出样例：

Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John
*/

//思路：先对其排序，然后按照规则输出

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char Name[9];
    int height;
};

int cmp(const void * a, const void * b)
{
    struct student * s1 = *(struct student **)a;    //重点，船舰一个新的结构体指针变量
    struct student * s2 = *(struct student **)b;
    if(s1->height != s2->height)
        return s2->height - s1->height;    //按照身高从大到小排序
    else
        return strcmp(s1->Name,s2->Name);  //按照字母升序排序
}

int main(void)
{
    int N,K;//分别代表学生人数和队伍列数
    scanf("%d %d",&N,&K);
    struct student * std[N]; //创建一个指针变量结构体组
    int i;
    for(i=0 ; i<N ; i++)
    {
        std[i] = malloc(sizeof(struct student));
        scanf("%s %d",std[i]->Name,&std[i]->height);
    }
    qsort(std,N,sizeof(struct student *),cmp);
//    printf("按照身高从大到小排序\n");          //排序没有问题
//    for(i=0 ; i<N ; i++)
 //       printf("%s %d\n",std[i]->Name,std[i]->height);
    int num[K];//每行人数；
    for(i=0 ; i<K ; i++)
    {
        if(i==0)
            num[i] = N/K + N%K;
        else
            num[i] = N/K;
    }
    int z = 0;
    for(i=0 ; i<K; i++)
    {
        char temp[num[i]][9];
        int j ;
        int k = 0;
        int flag = 1;
        for(j=num[i]/2 ; j<num[i] && j>=0 ;)
        {
//            j += k*flag;
//            k++;
 //           if(k>num[i])
 //               break;
//            flag = -flag;
            strcpy(temp[j],std[z++]->Name);
            k++;
            flag = -flag;
            j+=k*flag;

        }
        for(j=0 ; j<num[i] ; j++)
        {
            printf("%s%c",temp[j],j==num[i]-1?'\n':' ');
        }
    }
    return 0;

}

/*
总结：
1.创建结构体指针变量，逐一分配内村
2.qsort()函数，cmp函数中结构体指针的指针的取值
3.创建一个新数组来保存每一行要输出的名字的顺序
*/
