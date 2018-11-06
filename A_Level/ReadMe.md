# PAT目录

## 1001

- **字符串问题**，核心在于字符串的循环找点

*核心代码*

```c++
    for (int i = 0; i < len; i++) {
        cout << s[i];
        if (s[i] == '-') continue;
        if ((i + 1) % 3 == len % 3 && i != len - 1) cout << ",";
    }
```

**重点**

```C++
char s[20];
sprintf(s,"%d",c);   //从int中获取字符串
```



## 1002

- 数组表示多项式（多项式问题）
- 浮点数的精度问题

*核心代码*

```C++
for(int i=0 ; i<2 ; i++)
    {
        cin>>K;
        for(int j=0 ; j<K ; j++)
        {
            //scanf("%d%f",&coef,&index);
            cin>>coef>>index;
            Poly[coef] += index;
        }
    }
```

**重点**

```c++
if(abs(Poly[i] - 0.0) > 1e-32)  //判断浮点数是否为0的方法；因为浮点数存储精度不够
```



## 1003

- 深度优先搜索（图）
- 迪杰斯特拉算法

*核心代码*

```c++
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int N,M,C1,C2;
int Graph[510][510],weight[510],dist[510],num[510],w[510];
bool visit[510];
const int INF = 999999;

int main()
{
    scanf("%d %d %d %d",&N,&M,&C1,&C2);
    for(int i=0 ; i<N ; i++)
        scanf("%d",&weight[i]); //每个城市中的救护车数量
    memset(Graph,INF,sizeof(Graph)) ; //初始化图
    fill(dist,dist+510,INF) ; //初始化每个城市的初始距离
    int a,b,c;
    for(int i=0 ; i<M ; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        Graph[a][b] = Graph[b][a] = c;
    }
    num[C1] = 1;
    dist[C1] = 0;
    w[C1] = weight[C1];
    for(int i=0 ; i<N ; i++)  //这里是有所变形的，请注意
    {
        int minweight = INF,minnum = -1;
        for(int j = 0 ; j <N ; j++)
        {
            if(!visit[j] && dist[j] < minweight)
            {
                minweight = dist[j];
                minnum = j;
            }
        }
        if(minnum == -1)
            break;
        visit[minnum] = true;
        for(int j = 0; j < N; j++)
        {
            if(Graph[minnum][j] != INF && !visit[j] && dist[j] > dist[minnum] + Graph[minnum][j])      //判断条件
            {
                dist[j] = dist[minnum] + Graph[minnum][j]; //更新路径
                w[j] = w[minnum] + weight[j]; //更新权值
                num[j] = num[minnum]; //更新最新路径次数
            }
            else if(Graph[minnum][j] != INF && !visit[j] && dist[j] == dist[minnum] + Graph[minnum][j])
            {
                num[j] = num[minnum] + num[j];
                if(w[j] < w[minnum] + weight[j])
                    w[j] = w[minnum] + weight[j];
            }
        }

    }
    printf("%d %d\n",num[C2],w[C2]);
    return 0;
}
```





# 博客攻略

[PAT甲级一个月攻略](https://blog.csdn.net/yinghuoai/article/details/78510094)