// Created by Wendy on 2023/7/6.
#include <iostream>
#include "cmath"
using namespace std;
const int N = 1e6+10;
int n;
int q[N];
//快速排序思想：分治：
//step1：初始化一个pivot，将数组分为两部分，左边那部分比他小，右边那部分比他大
//step2：递归
void quick_sort(int q[], int l, int r){
    //迭代终止条件，l>=r
    if(l>=r){
        return;
    }
    int i=l-1,j=r+1;
    int x=q[((i+j)/2)];//这里会影响，i有可能就是0了，i-1=-1，就出边界了
    while(i<j) {
        while (q[++i] < x);
        while (q[--j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&q[i]);
    }
    quick_sort(q,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",q[i]);
    }
}
