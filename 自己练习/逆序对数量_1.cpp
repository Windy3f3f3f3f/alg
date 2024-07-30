#include <iostream>
using namespace std;
const int N = 100010;
int n;
int q[N],tmp[N];

long long merge_sort(int q[],int l,int r){
    long long number=0;
    if(l>=r){
        return 0;
    }
    int mid = l+r>>1;
    number+= merge_sort(q,l,mid);
    number+= merge_sort(q,mid+1,r);
    int i=l,j=mid+1,k=0;
    while(i<=mid&&j<=r){
        if(q[i]>q[j]){
            number+=mid-i+1;
            tmp[k++]=q[j++];
        }
        else{
            tmp[k++]=q[i++];
        }
    }
    while(i<=mid){
        tmp[k++]=q[i++];

    }

    while(j<=r) {
        tmp[k++]=q[j++];

    }
    for(int i=l,j=0;i<=r;i++,j++){
        q[i]=tmp[j];
    }
    return number;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&q[i]);
    long long  x = merge_sort(q,0,n-1);
    cout<<x;
    return 0;
}