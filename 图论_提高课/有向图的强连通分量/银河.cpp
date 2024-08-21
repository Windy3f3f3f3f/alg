#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+10;
const int M = 2e6+10;
int mod;
int n,m;
typedef long long LL;
int h[N], hs[N], e[M], ne[M], idx, w[M];
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, scc_size[N];
int dist[N];

void add(int h[], int a, int b, int c){
    e[idx]=b, w[idx]=c, ne[idx]=h[a], h[a]=idx++; //记住，这里h一定要初始化
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
            scc_size[scc_cnt]++;
        }while(y!=u); //弹出，包括弹他自己
    }
}



int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    memset(hs, -1, sizeof hs);

    for (int i = 1; i <= n; i ++ ) add(h, 0, i, 1);

    while (m -- )
    {
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);
        if (t == 1) add(h, b, a, 0), add(h, a, b, 0);
        else if (t == 2) add(h, a, b, 1);
        else if (t == 3) add(h, b, a, 0);
        else if (t == 4) add(h, b, a, 1);
        else add(h, a, b, 0);
    }

    tarjan(0);

    bool success = true;
    for (int i = 0; i <= n; i ++ )
    {
        for (int j = h[i]; ~j; j = ne[j])
        {
            int k = e[j];
            int a = id[i], b = id[k];
            if (a == b)
            {
                if (w[j] > 0)
                {
                    success = false;
                    break;
                }
            }
            else add(hs, a, b, w[j]);
        }
        if (!success) break;
    }

    if (!success) puts("-1");
    else
    {
        for (int i = scc_cnt; i; i -- )
        {
            for (int j = hs[i]; ~j; j = ne[j])
            {
                int k = e[j];
                dist[k] = max(dist[k], dist[i] + w[j]);
            }
        }

        LL res = 0;
        for (int i = 1; i <= scc_cnt; i ++ ) res += (LL)dist[i] * scc_size[i];

        printf("%lld\n", res);
    }

    return 0;
}
