/*
时间：2018/6/24 10点01分
作者：楼浩然
题目：
输入格式：
输入第一行给出两个正整数 N（≤ 1000）和 M（≤ 6），分别是学生人数和需要被查缴的物品种类数。第二行给出 M 个需要被查缴的物品编号，其中编号为 4 位数字。随后 N 行，每行给出一位学生的姓名缩写（由 1-4 个大写英文字母组成）、个人物品数量 K（0 ≤ K ≤ 10）、以及 K 个物品的编号。

输出格式：
顺次检查每个学生携带的物品，如果有需要被查缴的物品存在，则按以下格式输出该生的信息和其需要被查缴的物品的信息（注意行末不得有多余空格）：

姓名缩写: 物品编号1 物品编号2 ……
最后一行输出存在问题的学生的总人数和被查缴物品的总数。

输入样例：
4 2
2333 6666
CYLL 3 1234 2345 3456
U 4 9966 6666 8888 6666
GG 2 2333 7777
JJ 3 0012 6666 2333
输出样例：
U: 6666 6666
GG: 2333
JJ: 6666 2333
3 5
*/

#include <stdio.h>
#include <string.h>

struct student{
    char Name[5];
    int d; //学生物品数量
    int thing[10];
};

int IsIn(int i,int * n, int m)
{
    int j;
    for(j=0 ; j<m ;j++)
    {
        if(i==n[j])
            return 1;
    }
    return 0;
}

int main(void)
{
    int N,m;//N 代表学生人数，m代表需要查询的物品数目
    scanf("%d %d",&N,&m);
    struct student Stu[N];
    int check[m];  //存放需要查询的物品编号
    int i,j; //循环计数
    int total_s=0,total_t = 0;//分别记录查询到的学生人数和物品总数
    for(i=0 ; i<m ; i++)
        scanf("%d",&check[i]);
//    for(i=0 ; i<m ; i++)       //说明cheak数组没有问题
 //       printf("%d",check[i]);
    for(i=0 ; i<N ;i++)
    {
        scanf("%s",Stu[i].Name);
        scanf("%d",&Stu[i].d);
        for(j=0 ; j<Stu[i].d ;j++)
            scanf("%d",&Stu[i].thing[j]);
    }

    for(i=0 ; i<N ; i++)
    {
        int flag = 0;
        int t = 0; //记录每个学胜被 查到的物品数量
        for(j=0 ; j<Stu[i].d ; j++)
        {
 //           printf("%d\n",Stu[i].thing[j]);  //说明结构体中thing数组输入没有问题
            if(IsIn(Stu[i].thing[j],check,m))
            {
                if(t==0)
                    printf("%s: %04d",Stu[i].Name,Stu[i].thing[j]);
                else
                    printf(" %04d",Stu[i].thing[j]);
                t+=1;
                flag = 1;
                total_t += 1;
            }
        }
        if(flag == 1)
        {
            total_s += 1;
            printf("\n");
        }

    }
    printf("%d %d",total_s,total_t);
    return 0;


}
