//
// Created by Wendy on 2023/10/27.
//

#include <iostream>
#include <cstring>

using namespace std;
int n,m;
const int N = 510;
int g[N][N];
int st[N];
int d[N];

int dij(){
    memset(d,0x3f,sizeof d);
    d[1]=0;
    // n times
    for(int i=0;i<n;i++){
        // find the shortest
        int t = -1;
        for(int j=1;j<=n;j++){
            if(!st[j] && (t==-1||d[j]<d[t])){
                t=j;
            }
        }
        st[t]=true;
        // find the neighborhood of t
        for(int j=1;j<=n;j++){
            d[j] = min(d[j],d[t]+g[t][j]);
        }
    }
    if(d[n]==0x3f3f3f3f) return -1;
    return d[n];
}
int main(){
    cin>>n>>m;
    int a,b,w;
    memset(g,0x3f,sizeof g);

    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&w);
        g[a][b]=min(g[a][b],w);
//        g[a][b]=w;
    }
    dij();
    if(d[n]!=0x3f3f3f3f){
        printf("%d",d[n]);
    }
    else{
        printf("-1");
    }
    return 0;
}