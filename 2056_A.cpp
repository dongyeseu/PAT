#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;
//map<int,int>ID; //!!!!!!!!!!!!!!!!!!!!!!!!deleted
vector<int> ID; //!!!!!!!!!!!!!!!!!!!!!!!appended
//返回以temp数组元素作为索引的ID数组的最大值的索引（temp数组数据）
int MAX(vector<int>temp){
    int Max_num = -100,index=-1;
    for(auto c : temp){
        if(ID[c] > Max_num){
            Max_num = ID[c];
            index = c;
        }
    }
    return index;
}
int main(){
    int NP,NG;
    scanf("%d %d",&NP,&NG);
    vector<int>programmer;
    vector<int>Res(NP,0); //Res[player-id]=player-rank
    ID.resize(NP); //!!!!!!!!!!!!!!!!!!!!!!!appended
    int rk = 1,t;
    int i;
    for(i=0 ; i<NP ; i++){
        cin>>t;
        ID[i] = t; //programmer id 为 i的weight是多少，最好使用数组 ID[programmer-id]=weight
    }
    vector<int>temp;
    int cnt = 0,num;
    for(i=0 ; i<NP ; i++){
        scanf("%d",&num);
        programmer.push_back(num); //programmer[play-order]=programmer-id;
    }
    while(programmer.size()!=1){ //如果等于1的情况呢？
        vector<int>Winner;
        for(i=0 ; i<programmer.size() ; i++){
            //把所有player-order里面的player-id按order推入temp
            temp.push_back(programmer[i]);
            cnt++; //将cnt 初始化为1
            if(cnt == NG || i == programmer.size()-1){ //如果round正常结束或强制结束
                int r = MAX(temp); //temp 里面存的是该round内的player-id，获取最大weight的id
                for(auto c:temp){
                    if(c == r)
                        Winner.push_back(c);    //Winner 进入下一轮
                    else
                        //loser 设置名次为进入下一轮的个数+1
                        //进入下一轮的数量为 (当前评比的数量+group_nos-1)/group_nos
                        //Res[c] = (programmer.size()+2)/3+1; //Res[player-id]=player-rank //!!!!!!!!!!!!!!!!!!!!!!!!deleted
                        Res[c] = (programmer.size()+NG-1)/NG+1; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!this line is changed
                }
                temp.clear();
                cnt = 0;
            }
        }
        programmer.clear();//清空当前回合player-id
        /*for(i=0 ; i<Winner.size() ; i++){
            programmer.push_back(Winner[i]); //将这一轮的winner压入新的回合
        }*/
        programmer=Winner; //changed!!!!!!!!!!!!! '=' operator for vector is overloaded as copy of data, not reference, use native statement to speed up
    }
    Res[programmer[0]] = 1;
    for(i=0 ; i<NP ; i++){
        if(i==0)
            cout<<Res[i];
        else
            cout<<" "<<Res[i];
    }
    return 0; //the absence of return value in main function may lead to system error in on-line judge systems
}


//他山之玉
//柳婼
/*
题目大意：np为老鼠的数量，ng为每组最多g个老鼠。先给出np个老鼠的重量，再给出老鼠的初始顺序（第i名的老鼠是第j号，j从0开始）。每ng个老鼠分为一组，
对于每组老鼠，选出最重的那个，晋级下一轮比赛，然后依次再以np个老鼠一组分类，然后选出重量最大的。。。直到只剩下一只老鼠，排名为1.输出为老鼠的排名，
这个排名是按照原输入老鼠的顺序输出的。
分析：设立结构体node表示老鼠，里面包括weight重量，index是按照排名后的顺序的老鼠的下标，index0是排名前老鼠的下标。rank是最终要输出的老鼠的排名。
先将所有的老鼠按照排名后的顺序依次放入队列中，对于队列中的每一个老鼠，按照分组后选择最大重量的比赛规则，将每次分组获得第一的老鼠放入队列尾部。此处有
一点，如果当前剩下的老鼠可以分为group组，那么这一组里面没有晋级的老鼠排名就是group+1.此处解释一下：
因为对于共有group组的老鼠，每组晋级一个，也就是说最终这一轮能晋级的是group个老鼠，那么没有晋级的所有人就是group+1名，就像有4个人晋级下一轮，那么所
有没晋级的这一轮就都是并列第5名。
group的计算方法是：如果当前轮次的人数正好可以被每组ng人的ng整除，那么就有人数/ng个组。如果不能被整除，就有剩下来的一些老鼠分为一组，就是人数/ng + 1
组。（这是求得group的方法）
cnt用来控制当前的组内第几个人，如果cnt能够被ng整除了说明已经是下一组了，就cnt = 0；否则cnt不断++，同时将最重的老鼠体重赋值给maxn，最重的老鼠的node
赋值给maxnode。
最后将结果结构体w排序，按照先前保存的index0的顺序排序，因为题目要求是必须按照题目所给的输入顺序输出的，排序后即可按序输出。
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int weight, index, rank, index0;
};
bool cmp1(node a, node b) {
    return a.index0 < b.index0;
}
int main() {
    int n, g, num;
    scanf("%d%d", &n, &g);
    vector<int> v(n);
    vector<node> w(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        w[i].weight = v[num];
        w[i].index = i;
        w[i].index0 = num;
    }
    queue<node> q;
    for(int i = 0; i < n; i++)
        q.push(w[i]);
    while(!q.empty()) {
        int size = q.size();
        if(size == 1) {
            node temp = q.front();
            w[temp.index].rank = 1;
            break;
        }
        int group = size / g;
        if(size % g != 0)
            group += 1;
        node maxnode;
        int maxn = -1, cnt = 0;
        for(int i = 0; i < size; i++) {
            node temp = q.front();
            w[temp.index].rank = group + 1;
            q.pop();
            cnt++;
            if(temp.weight > maxn) {
                maxn = temp.weight;
                maxnode = temp;
            }
            if(cnt == g || i == size - 1) {
                cnt = 0;
                maxn = -1;
                q.push(maxnode);
            }
        }
    }
    sort(w.begin(), w.end(), cmp1);
    for(int i = 0; i < n; i++) {
        if(i != 0) printf(" ");
        printf("%d", w[i].rank);
    }
    return 0;
}
