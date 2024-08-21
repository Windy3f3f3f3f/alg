#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
bool st[N];

int main(){
    int k, n;
    cin>>n>>k;
    int res=0;
    for(int i=1;i<=k;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        if(st[r]!=true&&r!=0){
            res++;
        }
        st[l]=true;
    }
    cout<<res;
}
