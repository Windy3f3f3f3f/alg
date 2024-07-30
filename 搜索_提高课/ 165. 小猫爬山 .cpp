//
// Created by Wendy on 2023/10/11.
//

#include<iostream>
#include <algorithm>
using namespace std;

const int N =25;
int c[N];
int s[N];
int n,w;
int ans=N;
//k是当前缆车数
//ans是最低缆车数
//u是在搜第u个点，从0开始记录，因此实际上只有0~u-1
void dfs(int u, int k){
    if(k>=ans){
        return;
    }
    if(u==n){
        if(ans>k)
            ans=k;
        return;
    }
    for(int i=0;i<k;i++){
        if(s[i]+c[u]<=w){
            s[i]=s[i]+c[u];
            dfs(u+1,k);
            s[i]=s[i]-c[u];
        }
    }
    s[k]=c[u];
    dfs(u+1,k+1);
    s[k]=s[k]-c[u];
}
int main(){
    cin>>n>>w;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    sort(c,c+n,greater<int>());
    dfs(0,0);
    cout<<ans;
    return 0;
}