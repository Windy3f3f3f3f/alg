#include <bits/stdc++.h>

using namespace std;
const int N = 110;
const int M = N * N;
int n,m;

int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, Size[N];
int dout[N], din[N];

void add(int a, int b){
    e[idx]=b, ne[idx]=h[a], h[a]=idx++; //记住，这里h一定要初始化
}

void tarjan(int u){
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u, in_stk[u] = true;
    for(int i=h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(!dfn[j]){//如果没有遍历过，继续tarjan
            tarjan(j);
            low[u] = min(low[u],low[j]);//可能存在更高的反向边、跨边
        }else if(in_stk[j]){
            //如果是反向边
            low[u] = min(low[u],dfn[j]);//直接用j的时间戳更新u
        }
    }
    // 所以当遍历完u的所有能到的点后 发现u最高能到的点是自己
    // 1 则u为强连通分量中的最高点,则以u为起点往下把该强连通分量所有节点都找出来
    // 2 要么它就没有环,就是一个正常的往下的点
    if(dfn[u]==low[u]){
        int y;
        ++scc_cnt;
        do{
            y = stk[top--];
            in_stk[y]=false;
            id[y]=scc_cnt;
            Size[scc_cnt]++;
        }while(y!=u); //弹出，包括弹他自己
    }
}

int main(){
    cin>>n;
    memset(h, -1, sizeof h);
    for(int i=1;i<=n;i++){
        int j;
        while(cin>>j,j) add(i,j);//逗号运算符，表达式的值是逗号后面的
    }

    //求一遍tarjan
    for(int i=1;i<=n;i++){
        if(!dfn[i])
            tarjan(i);
    }

    //缩点
    for(int a=1;a<=n;a++){
        for(int idx=h[a];idx!=-1;idx=ne[idx]){
            int b = e[idx];
            int aa=id[a], bb=id[b];
            if(aa!=bb){
                dout[aa]++;
                din[bb]++;
            }
        }
    }
    int a = 0, b = 0;
    for (int i = 1; i <= scc_cnt; i ++ )
    {
        if (!din[i]) a ++ ;
        if (!dout[i]) b ++ ;
    }

    printf("%d\n", a);
    if (scc_cnt == 1) puts("0");
    else printf("%d\n", max(a, b));

    return 0;
}
