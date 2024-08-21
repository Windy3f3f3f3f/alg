#include <bits/stdc++.h>
using namespace std;
const int N=310;
int n,m;
int g[N][N];
int dist[N];
bool st[N];
int prim(){
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;//第一个点一定在最小生成树中

    int sum = 0;//距离之和
    for (int i = 0; i < n+1; i++) {
        int t = -1;
        for (int j = 0; j <= n; j ++)
            if (!st[j] && (t == -1 ||dist[t] > dist[j])) t = j;//确保j不在树的集合里最开始的时候dist[t]也就是dist[0]是无穷

        sum += dist[t], st[t] = true;

        for (int j = 0; j <= n; j ++)
            dist[j] = min(dist[j], g[t][j]);
    }

    return sum;

}
int main(){
    cin>>n;
    memset(g,0x3f,sizeof g);
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%d", &g[0][i]);
        g[i][0] = g[0][i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    int i=prim();
    if(i == 0x3f3f3f3f) puts("impossible");
    else cout << i << endl;

}
