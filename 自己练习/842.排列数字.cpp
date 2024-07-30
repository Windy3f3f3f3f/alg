#include <iostream>
using namespace std;
const int N = 10;
int n;
int path[N];
bool st[N];
void dfs(int u){
    if(u==n){
        for(int i=0;i<n;i++){
            printf("%d ",path[i]);
        }
        puts("");
    }
    for(int i=0;i<n;i++){
        if(st[i+1]!=true){
            st[i+1]=true;
            path[u]=i+1;
            dfs(u+1);
            st[i+1]=false;
        }
    }
}
int main(){
    cin>>n;
    dfs(0);
    return 0;
}