//
// Created by Wendy on 2023/10/1.
//
#include <iostream>
using namespace std;
#include <cstring>
int k,n,xa,ya,xb,yb;
const int N = 110;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int st[N][N];
char g[N][N];
int dfs(int xa,int ya){
    if(g[xa][ya]=='#'){
        return 0;
    }
    if(g[xb][yb]=='#'){
        return 0;
    }
    if(xa==xb&&ya==yb){
        return 1;
    }
    int p = 0;
    for(int i=0;i<4;i++){
        int nx = xa+dx[i];
        int ny = ya+dy[i];
        if(nx>=n||nx<0||ny>=n||ny<0){
            continue;
        }
        if(st[nx][ny]==1){
            continue;
        }
        if(g[nx][ny]=='#'){
            continue;
        }
        st[nx][ny]=1;
        if(dfs(nx,ny)){
            return 1;
        }
    }
    return 0;
}
int main(){
    cin>>k;
    for(int i=0;i<k;i++){
        //关键，每次都要初始化一下st...
        memset(st, 0, sizeof(st));
        cin>>n;
        for(int j=0;j<n;j++){
            for(int q=0;q<n;q++){
                cin>>g[j][q];
            }
        }
        cin>>xa>>ya>>xb>>yb;
        if(dfs(xa,ya)){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
}