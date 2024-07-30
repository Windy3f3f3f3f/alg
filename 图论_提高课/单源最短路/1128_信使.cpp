//
// Created by Wendy on 2024/1/20.
//
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 120;
int n,m,a,b,c;
int dist[N][N];
int main(){
    //初始化有两点，第一点是自然的，设置成所有路径为无穷。然后还需要设置自己到自己的路径长度是0，还有读入其他路径。
    memset(dist,0x3f,sizeof dist);
    cin>>n>>m;
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0; // 初始化自身到自身的距离为0
    }
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        dist[a][b]=dist[b][a]=min(dist[a][b],c); //主要是怕有坑
    }
    // 弗洛伊德算法 经过节点k，更新所有的i、j
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                // dp
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    //输出从1开始的最长路
    int max_len = 0;
    for(int i=1;i<=n;i++){
        max_len = max(max_len,dist[1][i]);
    }
    if(max_len==0x3f3f3f3f){
        printf("-1");
    }
    else{
        printf("%d",max_len);
    }
    return 0;
}