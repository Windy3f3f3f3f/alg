#include <iostream>
#include <algorithm>
using namespace std;
const int N= 100000 + 10;
int q[N];
//step1:初始化一个pivot
//step2:使得pivot左边都<=pivot，pivot右边都>=pivot
//step3:考查此时的j，l->j里有j-l+1个，如果j-l+1<=sl，则结果就在左边，否则结果在右边j+1,r，并且k-sl即可
int quick_find(int l,int r, int k){
    if(l==r) return q[l];
    int x = q[l],i=l-1,j=r+1;
    while(i<j){
        while(q[++i]<x);
        while(q[--j]>x);
        if(i<j){
            swap(q[i],q[j]);
        }
    }
    int sl=j-l+1;
    if(k<=sl) return quick_find(l,j,k);
    else return quick_find(j+1,r,k-sl);
}

int main(){
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    for(int i=0;i<n;i++) cin>>q[i];
    cout<<quick_find(0,n-1,k)<<endl;
    return 0;
}