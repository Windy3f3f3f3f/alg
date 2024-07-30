//
// Created by Wendy on 2023/9/12.
//
#include <iostream>
using namespace std;
const int N = 20;
int n;
bool col[N], dg[N],udg[N];
char g[N][N];
//从1开始
void dfs(int x){
    if(x==n+1){
        //print
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout << g[i][j];
            }
            cout << endl;
        }
        puts("");
        return;
    }
    //搜索是按照行层次遍历
    for(int y=1;y<=n;y++){
        // x,y -> x-y+n;x+y;
        if(!col[y]&&!dg[x-y+n]&&!udg[x+y]){
            g[x][y]='Q';
            col[y]=dg[x-y+n]=udg[x+y]=true;
            dfs(x+1);
            col[y]=dg[x-y+n]=udg[x+y]=false;
            g[x][y]='.';
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[i][j]='.';
        }
    }
    dfs(1);
    return 0;
}