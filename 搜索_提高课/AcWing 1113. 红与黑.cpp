//
// Created by Wendy on 2023/10/1.
//
#include <iostream>
#include <cstring>
using namespace std;

const int N = 25;
int n,m;
char g[N][N]={0};
bool st[N][N];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dfs(int x, int y){
    int cnt = 1;
    st[x][y]=true;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=m)
            continue;
        if(g[nx][ny]=='#')
            continue;
        if(st[nx][ny])
            continue;
        st[nx][ny]=true;
        cnt+=dfs(nx,ny);
    }
    return cnt;
}

int main(){
    while(true){
        cin>>m>>n;
        if(n==0 && m==0)
            break;
        memset(st, 0, sizeof(st)); // 重置 st 数组
        int x,y;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                cin>>g[i][j];
                if(g[i][j]=='@'){
                    x=i,y=j;
                }
            }
        printf("%d\n",dfs(x,y)); // 对每个数据集合，分别输出一行
    }
    return 0;
}