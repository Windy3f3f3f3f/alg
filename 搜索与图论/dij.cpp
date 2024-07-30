#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510;
int n,m;
int g[N][N];//因为是稠密图，用邻接矩阵写
int dist[N];
bool st[N];
int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for(int i=0;i<n;i++){
        int t=-1;
        // find out the nearest point
        for(int j=1;j<=n;j++)
            if(!st[j]&&(t==-1||dist[t]>dist[j]))
                t=j;
        // set
        st[t]=true;
        // use the new point to update all dist
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],dist[t]+g[t][j]);
        }
    }
    // if not link
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}


int main(){
    scanf("%d%d",&n,&m);
    // initialize to 0x3f3f3f3f3f
    memset(g,0x3f,sizeof g);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=min(g[a][b],c);
    }
    int t=dijkstra();
    printf("%d\n",t);
    return 0;
}
