#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
const int M = 2*N;
int w[M],e[M],ne[M],h[N],idx;
int n;
int d1[N], d2[N], up[N];
int s1[N], s2[N];
void add(int a, int b, int c){
    w[idx]=c, e[idx]=b, ne[idx]=h[a], h[a]=idx++;
}

int brutal(int root, int parent){
    int res = 0;
    for(int i=h[root];~i;i=ne[i]){
        if(e[i]==parent) continue;
        res = max(res, w[i]+brutal(e[i], root));
    }
    return res;
}
void dfs1(int u, int father)
{
    // d1[u] = d2[u] = -INF;  //这题所有边权都是正的，可以不用初始化为负无穷
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == father) continue;
        dfs1(j, u);
        if (d1[j] + w[i] >= d1[u])
        {
            d2[u] = d1[u], s2[u] = s1[u];
            d1[u] = d1[j] + w[i], s1[u] = j;
        }
        else if (d1[j] + w[i] > d2[u])
        {
            d2[u] = d1[j] + w[i], s2[u] = j;
        }
    }
    // if (d1[u] == -INF) d1[u] = d2[u] = 0; //特判叶子结点
}
void dfs2(int u, int father)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == father) continue;
        if (s1[u] == j) up[j] = w[i] + max(up[u], d2[u]);   //son_u  = j，则用次大更新
        else up[j] = w[i] + max(up[u], d1[u]);              //son_u != j，则用最大更新
        dfs2(j, u);
    }
}


int main(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c), add(b,a,c);
    }
    int res = 0x3f3f3f3f;
    // for(int i=1;i<=n;i++){
    //     res = min(res, brutal(i, -1));
    // }
    dfs1(1, -1);
    dfs2(1, -1);
    for (int i = 1; i <= n; i ++ ) res = min(res, max(d1[i], up[i]));
    cout<<res;
    return 0;
}
