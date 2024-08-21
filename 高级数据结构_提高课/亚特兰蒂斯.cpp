#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int n;
struct Segment
{
    double x, y1, y2;
    int k;
    bool operator< (const Segment &t)const
    {
        return x < t.x;
    }
}seg[N * 2];
struct Node
{
    int l, r;
    int cnt;
    double len;
}tr[N * 8];

vector<double> ys;

int find(double y)
{
    return lower_bound(ys.begin(), ys.end(), y) - ys.begin();
}

void pushup(int u)//如果当前是cnt>0，那么表示全都覆盖了，则len直接计算出。如果不是的话，根据左右孩子覆盖长度算出来。
{
    if (tr[u].cnt) tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
    else if (tr[u].l != tr[u].r)
    {
        tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
    }
    else tr[u].len = 0;
}

void build(int u, int l, int r)
{
    tr[u] = {l, r, 0, 0};
    if (l != r)
    {
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }
}

void modify(int u, int l, int r, int k)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].cnt += k;//如果在区间里,cnt+
        //这里是否要添加懒标记来pushdown？
        pushup(u);//cnt>0，更新一下当前len
    }
    else
    {
        //为什么不pushdown？pushdown是把节点修改的信息放在懒标记，你猜这里有懒标记吗？
        //为什么不需要懒标记？
        //思考这个查询的特殊性质，如果改了某一个区间了，后面
        int mid = tr[u].l + tr[u].r >> 1;//如果不在区间里，要改这个区间的lens信息
        if (l <= mid) modify(u << 1, l, r, k);//递归改两个孩子的len
        if (r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);//更新当前区间信息
    }
}

int main()
{
    int T = 1;
    while (scanf("%d", &n), n)
    {
        ys.clear();
        for (int i = 0, j = 0; i < n; i ++ )
        {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            seg[j ++ ] = {x1, y1, y2, 1};
            seg[j ++ ] = {x2, y1, y2, -1};
            ys.push_back(y1), ys.push_back(y2);
        }

        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        build(1, 0, ys.size() - 2);

        sort(seg, seg + n * 2);

        double res = 0;
        for (int i = 0; i < n * 2; i ++ )
        {
            if (i > 0) res += tr[1].len * (seg[i].x - seg[i - 1].x);
            modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);
        }

        printf("Test case #%d\n", T ++ );
        printf("Total explored area: %.2lf\n\n", res);
    }

    return 0;
}

