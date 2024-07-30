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
    for (int i=0;i<n;i++){
        if(!st[i]){
            st[i]=true;
            path[u]=i+1;//修改状态
            dfs(u+1);//递归进去
            st[i]=false;//递归完毕，恢复现场，以便以后继续使用
        }
    }

}

int main(){
    cin>>n;
    dfs(0);
    return 0;
}