#include <iostream>
using namespace std;

const int N = 1e5+10;
int n,k;
int a[N];

int q_select(int* a, int k, int l, int r){
    if(l==r) return a[l];
    int x = a[l], i = l-1, j = r+1;
    //i<j的话就继续找
    while(i<j){
        while(a[++i]<x);
        //找到a[i]>=x
        while(a[--j]>x);
        //找到a[j]<=x
        if(i<j) swap(a[i],a[j]);
    }
    int sl=j-l+1;
    if(k<=sl) return q_select(a,l,j,k);
    else return q_select(a,j+1,r,k-sl);
}
int main(){
    //用快排的思路来快速选择
    cin>>n>>k;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    cout<<q_select(a,k,0,n-1);

    return 0;
}
