#include<iostream>

using namespace std;
const int N = 100010;
int n;
int q[N],tmp[N];

//分而治之，分为两部分，各子部分 分别求出逆序对数量
//在合并的时候，由于左边子部分是顺序递增的，则右边的某个元素小于左边时，他也小于左边该元素后面的所有元素
long long  merge_sort(int q[],int l,int r){
    long long  number = 0;
    if(l>=r) return 0;
    int mid=l+r>>1;
    number+=merge_sort(q,l,mid);
    number+=merge_sort(q,mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(q[i]<=q[j])
            tmp[k++]=q[i++];
        else{
            tmp[k++]=q[j++];
            number += mid-i+1;
        }
    }
    while(i<=mid){
        tmp[k++]=q[i++];
    }
    while(j<=r) tmp[k++]=q[j++];
    for(i=l,j=0;i<=r;i++,j++)
        q[i]=tmp[j];
    return number;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&q[i]);
    long long  x = merge_sort(q,0,n-1);
    cout<<x;
}