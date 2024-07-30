//
// Created by Wendy on 2023/9/12.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> PII;//定义序偶
const int N = 110;
int g[N][N], d[N][N];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&g[i][j]);
        }
    }
    //广搜
    queue<PII> q;
    memset(d,-1,sizeof d);
    d[0][0]=0;
    q.push({0,0});
    int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=t.first+dx[i],y=t.second+dy[i];
            if(x>=0&&x<n&&y<m&&y>=0&&g[x][y]==0&&d[x][y]==-1){
                d[x][y]=d[t.first][t.second]+1;
                q.push({x,y});
            }
        }
    }
    printf("%d",d[n-1][m-1]);
}