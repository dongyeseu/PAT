#include <stdio.h>

long long GCD(long long a, long long b) {   //求最大公约数
    long long m = a%b;
    while(m) {
        a=b;
        b=m;
        m=a%b;
    }
    return b;
}
void printFraction(long long a, long long b){//分数形式打印
    long long k=1;
    long long gcd;
    if(b==0){
        printf("Inf");
        return;
    }
    if(a<0){
        a=-a;
        k=-1;
    }
    gcd = GCD(a,b);
    a=a/gcd;
    b=b/gcd;
    if(a/b==0&&a!=0){//真分数
        if(k > 0)  //一开始写的时候少了这个判断导致两个测试点错误（题目给的测试点通过）
            printf("%lld/%lld", a, b);
        else
            printf("(-%lld/%lld)", a, b);
        return;
    }
    k=k*a/b;//假分数
    a=a%b;
    if(b == 1 && k < 0)
        printf("(%lld)", k);
    else if(b == 1 && k >= 0)    //分子为0,或者分母为1，结果都是整数，直接输出分子部分（不输出分母）
        printf("%lld", k);
    else if(k < 0)
        printf("(%lld %lld/%lld)", k, a, b);
    else
        printf("%lld %lld/%lld", k, a, b);
}

void Print(long long a1, long long b1, long long a2, long long b2, char ch) {   //输出一个表达式
    long long n1,n2;
    printFraction(a1,b1);
    printf(" %c ",ch);
    printFraction(a2,b2);
    printf(" = ");
    switch(ch){
        case '+':
            n1=a1*b2+a2*b1;
            n2=b1*b2;
            printFraction(n1,n2);
            printf("\n");
            break;
        case '-':
            n1=a1*b2-a2*b1;
            n2=b1*b2;
            printFraction(n1,n2);
            printf("\n");
            break;
        case '*':
            n1=a1*a2;
            n2=b1*b2;
            printFraction(n1,n2);
            printf("\n");
            break;
        case '/':
            n1=a1*b2;
            n2=b1*a2;
            if(n2<0){
                n1=-n1;
                n2=-n2;
            }
            printFraction(n1,n2);
            printf("\n");
            break;
    }
}

int main(){
    long long a1,b1,a2,b2;
    scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
    Print(a1, b1, a2, b2, '+');
    Print(a1, b1, a2, b2, '-');
    Print(a1, b1, a2, b2, '*');
    Print(a1, b1, a2, b2, '/');
    return 0;
}
