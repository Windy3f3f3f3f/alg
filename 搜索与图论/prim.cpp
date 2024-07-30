#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 510,INF = 0x3f3f3f3f;
int n,m;
//看到是稠密图，因此用邻接矩阵
int g[N][N];
int dist[N];
bool st[N];

int prim(){
    memset(dist,0x3f,sizeof dist);
    int res=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[t]>dist[j]))
                t=j;
        }

        if(i&&dist[t]==INF) return INF;
        if(i) res+=dist[t];

        //小心不能乱更新自己到自己的距离，即小心自环，因此要先加，再累加
        for(int j=1;j<=n;j++)
            dist[j]=min(dist[j],g[t][j]);

        st[i]=true;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    memset(g,0x3f,sizeof g);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=g[b][a]=min(g[a][b],c);
    }
    int t=prim();
    if(t==INF)puts("impossible");//也就是所有点不联通
    else printf("%d\n",t);
    return 0
}