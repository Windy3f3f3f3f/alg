//
// Created by Wendy on 2023/10/1.
//
#include <iostream>
#include <cstring>
using namespace std;
const int N = 10;
bool st[N][N];
int x,y;
int n,m;
int cnt;
int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {-2,-1,1,2,2,1,-1,-2};
void dfs(int x, int y){
    //搜到了，改状态
    st[x][y]=true;

    //终止条件
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(st[i][j]==false){
                goto label;
            }
        }
    }
    cnt ++;
    label:
    //找新路
    for(int i=0;i<8;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=m)
            continue;
        if(st[nx][ny])
            continue;
        dfs(nx,ny);
    }
    //回溯
    st[x][y]=false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>x>>y;
        dfs(x,y);
        printf("%d\n",cnt);
        memset(st,0,sizeof(st));
        cnt=0;
    }
}