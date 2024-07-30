#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int N=510,M=10010;
int n,m,k;
int dist[N],backup[N];
struct Edge
{
    int a, b, w;
}edges[M];

int bellman_ford(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for(int i=0;i<k;i++){
        //防止发生串联，每次更新的每个边的距离都是看上一轮迭代的结果，因此需要备份
        memcpy(backup,dist,sizeof dist);
        for(int j=0;j<m;j++){
            int a=edges[j].a,b=edges[j].b,w=edges[j].w;
            dist[b]=min(dist[b],backup[a]+w);

        }
    }
    if(dist[n]>0x3f3f3f3f/2) return -0x3f3f3f3f;
    return dist[n];
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edges[i]={a,b,w};
    }
    int t=bellman_ford();
    if(t==-0x3f3f3f3f){
        puts("impossible");
    }
    else{
        printf("%d\n",t);
    }
    return 0;
}