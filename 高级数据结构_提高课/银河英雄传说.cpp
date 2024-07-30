#include <iostream>
using namespace std;
const int N = 30010;
int t;
int p[N], w[N], s[N];
// w[i]表示节点到p[i]的距离，如果i是根节点，则表示集合大小

int find(int x)
{
    if (p[x] != x)
    {
        // 错误写法
        // p[x] = find(p[x]);
        // w[x] += w[p[x]];
        // 正确写法
        int root = find(p[x]);
        w[x] += w[p[x]]; //这里要注意，要先在更新px前，根据当前px的节点的距离更新x的距离，然后再更新px
        p[x] = root;
    }
    return p[x];
}
int main()
{
    cin >> t;
    for (int i = 1; i <= N; i++)
    {
        p[i] = i;
        s[i] = 1;
    }
    for (int i = 0; i < t; i++)
    {
        char op[3];
        int a, b, pa, pb;
        cin >> op >> a >> b;
        if (op[0] == 'M')
        {
            pa = find(a);
            pb = find(b);
            if (pa != pb)
            {
                p[pa] = pb;           // 将pa的根节点更新为pb的根节点
                w[pa] = s[pb];     // 更新pa的距离
                s[pb] += s[pa]; // 更新pb的集合大小
            }
        }
        else if (op[0] == 'C')
        {
            // 输出a到b的距离
            int pa = find(a);
            int pb = find(b);
            if (pa != pb)
            {
                cout << "-1" << endl;
            }
            else
            {
                cout << max(0,abs(w[a] - w[b]) - 1) << endl;
            }
        }
    }
    return 0;
}
