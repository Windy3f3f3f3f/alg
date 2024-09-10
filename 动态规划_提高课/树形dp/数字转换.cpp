#include <iostream>
#include <cstring>

using namespace std;

const int N = 5e4 + 10;  // 定义常量N，表示最大范围

int n, fsum[N];  // 定义变量n和数组fsum，用于存储每个数的约数之和
int h[N], e[N], ne[N], idx;  // 定义邻接表相关数组和索引
int d1[N], d2[N], res;  // 定义数组d1和d2，用于存储每个节点的最长和次长路径长度，res用于存储最终结果

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
void dfs(int u)
{
    if (d1[u]) return;  // 记忆化搜索，避免重复计算
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        if (d1[j] + 1 >= d1[u]) d2[u] = d1[u], d1[u] = d1[j] + 1;
        else if (d1[j] + 1 > d2[u]) d2[u] = d1[j] + 1;
    }
    res = max(res, d1[u] + d2[u]);
}
int main()
{
    memset(h, -1, sizeof h);  // 初始化邻接表的头节点数组
    scanf("%d", &n);  // 输入n
    for (int i = 1; i <= n; i ++ )
        for (int j = 2; j <= n / i; j ++ )
            fsum[i * j] += i;  // 计算每个数的约数之和
    for (int i = 2; i <= n; i ++ )
        if (fsum[i] < i)
            add(fsum[i], i);  // 构建邻接表
    for (int i = 1; i <= n; i ++ ) dfs(i);  // 对每个节点进行DFS
    printf("%d\n", res);  // 输出结果
    return 0;
}
