#include <iostream>
#include <algorithm>
using namespace std;
const int N = 55;
int n;
int q[N];
int up[N],down[N];
int ans;
//遍历所有点(深搜)，每个点有可能放在上升子序列/下降子序列中
void dfs(int u,int su,int sd){
    if(su+sd>=ans) return;//剪枝，剪掉已经超过局部最小值的
    if(u==n){
        ans=su+sd;
        return;
    }
    int k=0;
    while(k<su && up[k]>=q[u]) k++;
    int t = up[k];
    up[k]=q[u];
    if(k<su) dfs(u+1,su,sd);
    else dfs(u+1,su+1,sd);
    up[k]=t;

    k=0;
    while(k<sd && down[k]<=q[u]) k++;
    t=down[k];
    down[k]=q[u];
    if(k<sd) dfs(u+1,su,sd);
    else dfs(u+1,su,sd+1);
    down[k]=t;

}


int main(){
    while(cin>>n,n){
        for(int i=0;i<n;i++) cin>>q[i];
        ans = n;
        dfs(0,0,0);
        cout<<ans<<endl;
    }

    return 0;

}