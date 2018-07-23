/*
1089 Insert or Merge（25 分）
According to Wikipedia:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

Merge sort works as follows: Divide the unsorted list into N sublists, each containing 1 element (a list of 1 element is considered sorted). Then repeatedly merge two adjacent sublists to produce new sorted sublists until there is only 1 sublist remaining.

Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in the first line either "Insertion Sort" or "Merge Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resuling sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
Sample Output 2:
Merge Sort
1 2 3 8 4 5 7 9 0 6
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

void MergeSort(int A[],int B[] , int N)
{
    int left_min,left_max,right_min,right_max;
    int i;
    int * temp = (int *)malloc(sizeof(int)*N);
    int flag = 0;
    for(i=1 ; i<N ; i*=2)
    {
        for(left_min = 0 ; left_min < N-i ; left_min = right_max)
        {
            left_max = right_min = left_min + i;
            right_max = right_min + i;
            if(right_max>N)
                right_max = N;
            int k = 0;
            while(left_min < left_max && right_min < right_max)
            {
                if(A[left_min] < A[right_min])
                    temp[k++] = A[left_min++];
                else
                    temp[k++] = A[right_min++];
            }
            while(left_min < left_max)
            {
                A[--right_min] = A[--left_max];
            }
            while(k>0)
            {
                A[--right_min] = temp[--k];
            }
        }
        if(flag == 1)
            break;
        int z;
        for(z=0 ; z<N ; z++)
        {
            if(A[z]!=B[z])
                break;
        }
        if(z==N)
            flag = 1;
    }
}

int main()
{
    int N;
    cin>>N;
    int A[N],B[N],i,temp,flag = 0;
    for(i=0 ; i<N ; i++)
        scanf("%d",&A[i]);
    for(i=0 ; i<N ; i++)
        scanf("%d",&B[i]);
    for(i=1 ; i<N ; i++)
    {
        temp = i;
        if(B[i]<B[i-1])
            break;
    }
    for(i=temp ; i<N ; i++)
    {
        if(B[i]!=A[i])
            break;
    }
    if(i==N)
        flag = 1;
    if(flag)
    {
        cout<<"Insertion Sort\n";
        sort(A,A+temp+1);
        for(i=0 ; i<N ; i++)
        {
            if(i!=0)
                cout<<" "<<A[i];
            else
                cout<<A[i];
        }
        cout<<"\n";
    }
    else
    {
        cout<<"Merge Sort\n";
        MergeSort(A,B,N);
        for(i=0 ; i<N ; i++)
        {
            if(i!=0)
                cout<<" "<<A[i];
            else
                cout<<A[i];
        }
        cout<<"\n";
    }
    return 0;
}



//他山之玉
//柳婼
/*
题目大意：现给定原始序列和由某排序算法产生的中间序列，请你判断该算法是插入算法还是归并算法。首先在第1行中输出“Insertion Sort”表示插入排序、或“Merge Sort”表示归并排序；然后在第2行中输出用该排序算法再迭代一轮的结果序列

分析：先将i指向中间序列中满足从左到右是从小到大顺序的最后一个下标，再将j指向从i+1开始，第一个不满足a[j] == b[j]的下标，如果j顺利到达了下标n，说明是插入排序，再下一次的序列是sort(a, a+i+2);否则说明是归并排序。归并排序就别考虑中间序列了，直接对原来的序列进行模拟归并时候的归并过程，i从0到n/k，每次一段段得sort(a + i * k, a + (i + 1) * k);最后别忘记还有最后剩余部分的sort(a + n / k * k, a + n);这样是一次归并的过程。直到有一次发现a的顺序和b的顺序相同，则再归并一次，然后退出循环～

注意：一开始第三个测试点一直不过，天真的我以为可以模拟一遍归并的过程然后在过程中判断下一步是什么。。然而真正的归并算法它是一个递归过程。。也就是先排左边一半，把左边的完全排列成正确的顺序之后，再排右边一半的。。而不是左右两边一起排列的。。后来改了自己的归并部分判断的代码就过了。。。｡◕‿◕｡
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int *a = new int [n];
    int *b = new int [n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int i, j;
    for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++);
    for (j = i + 1; a[j] == b[j] && j < n; j++);
    if (j == n) {
        cout << "Insertion Sort" << endl;
        sort(a, a + i + 2);
    } else {
        cout << "Merge Sort" << endl;
        int k = 1, flag = 1;
        while(flag) {
            flag = 0;
            for (i = 0; i < n; i++) {
                if (a[i] != b[i])
                    flag = 1;
            }
            k = k * 2;
            for (i = 0; i < n / k; i++)
                sort(a + i * k, a + (i + 1) * k);
            sort(a + n / k * k, a + n);
        }
    }
    for (j = 0; j < n; j++) {
        if (j != 0) printf(" ");
        printf("%d", a[j]);
    }
    delete [] a;
    delete [] b;
    return 0;
}
