//
// Created by Wendy on 2023/11/6.
//
#include <iostream>
#include <cstring>
using namespace std;
const int N = 510;
int g[N][N];
int d[N];
bool st[N];
int n,m;
int dij(){
    //初始化开始的节点
    d[1]=0;
    // 执行n次
    for(int i=0;i<n;i++){
        // 每次找到没查过的最小的
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||d[t]>d[j])) {
                t=j;
            }
        }
        // 用它来更新其他节点
        st[t] = true;
        for(int j=1;j<=n;j++){
            if(!st[j]){
                // 妙啊
                d[j] = min(d[j],d[t]+g[t][j]);
            }
        }
    }
    if(d[n]==0x3f3f3f3f) return -1;
    return d[n];
}
int main(){
    cin>>n>>m;
    int x,y,z;
    memset(g,0x3f,sizeof g);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        g[x][y]=min(z,g[x][y]);//有坑这里的
    }
    memset(d,0x3f,sizeof d);
    cout<<dij()<<endl;
    return 0;
}