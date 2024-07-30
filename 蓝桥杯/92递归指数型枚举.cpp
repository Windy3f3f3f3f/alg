#include <iostream>
using namespace std;

int n;
const int N = 15;
int st[N];//状态，记录每个位置当前的状态，0表示没考虑，1表示选，2表示不选

void dfs(int u){
    if(u==n){
        //这里是到了递归树的树底了，这里就要进行输出，输出的时候路径要存一些状态信息到st里
        for(int i=0;i<n;i++){
            if(st[i]==1)
                printf("%d ",i+1);
        }
        return;



    }
    st[u]=2;
    dfs(u+1);//第一个分支，不选
    st[u]=0;//恢复状态 (为什么要恢复呢？因为还有其他孩子需要用到父节点的状态）

    st[u]=1;//第二个分支，选
    dfs(u+1);
    st[u]=0;//恢复状态
}
int main(){
    scanf("%d", &n);
    dfs(0);
    return 0;
}