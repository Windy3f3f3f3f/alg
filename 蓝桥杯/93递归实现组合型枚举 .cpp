#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 25;
int n,m;
int st[N];
int used[N];
//树有m层，每层的分支是从之前没选过的里面选，easy
//从下标0开始
void dfs(int u){
    if(u==m){
        //print
        for(int i=0;i<m;i++){
            printf("%d ",st[i]);
        }
        puts("");
    }

    for(int i=1;i<=n;i++){
        //只输出一次，这里要判断一下的
        if(!used[i]&&(u==0||i>st[u-1])){
            st[u]=i;
            used[i]=true;
            dfs(u+1);
            st[u]=0;
            used[i]=false;
        }
    }
}

int main()
{
    scanf("%d%d", &n,&m);
    dfs(0);
    return 0;
}
