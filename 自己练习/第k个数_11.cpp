#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e9+10;
int a[N];
int find_k(int l,int r,int s){
    if(l-r+1<=1&&s==1){
        return a[0];
    }
    int i=l-1,j=r+1;
    int p = l;
    while(i<=j){
        while(a[++i]<=a[p]);
        while(a[++j]>=a[p]);
        if(i<j){
            swap(a[i],a[j]);
        }
    }
    int sl = j-l+1;
    if(s<=sl){
        return find_k(l,j,s);
    }
    else{
        return find_k(j+1,r,s-sl);
    }
}


int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int x = find_k(0,n-1,k);
    printf("%d",x);
}