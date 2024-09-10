#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];

int main(){
    int n;
    int q;
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    while(q--){
        int k;
        cin>>k;
        //找>=k的绿色边界点
        int l = 1, r = n;
        while(l<r){
            int mid = l+r>>1;
            if(a[mid]>=k) r=mid;
            else l=mid+1;
        }
        if (a[l] != k) {
            printf("-1 -1\n");
            continue;
        }else{
            cout<<l-1<<" ";
        }
        // 找<=k的红色边界点

        l = 1, r= n;
        while(l<r){
            int mid = l+r+1>>1;
            if(a[mid]<=k) l=mid;
            else r=mid-1;
        }
        cout<<l-1<<endl;
    }

}
