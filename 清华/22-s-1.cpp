#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int L,R;
int h[N], e[N], ne[N], idx, n;
int st[N];//记录哪儿些节点被访问过
int cnt[N];//记录包括其自身的子节点数目
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
//返回u为根节点的子树的节点数
int dfs(int u){
    int res = 1;
    st[u]=0;//标记一下访问过了
    for(int i=h[u]; i!=-1; i=ne[i]){//访问每个子节点
        int j=e[i];
        int s = dfs(j);
        res += s;
    }
    cnt[u] = res;
    return res;
}


int main(){
    memset(h, -1, sizeof h);
    cin>>n>>L>>R;
    for(int i=2;i<n+2-1;i++){
        int tmp; cin>>tmp;
        add(tmp, i);
    }
    dfs(1);
    int res = 0;
    for(int i=1;i<=n;i++){
        if(cnt[i]>=L && cnt[i]<=R)
            res++;
    }
    cout<<res;
}
