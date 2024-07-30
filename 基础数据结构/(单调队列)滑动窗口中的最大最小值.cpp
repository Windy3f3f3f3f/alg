#include <iostream>

using namespace std;

const int N = 1000010;

int a[N], q[N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);


    int hh = 0, tt = -1;//初始化队头为0，队尾-1
    for (int i = 0; i < n; i ++ )
    {
        //如果队列不空并且当前队头元素对应的下标已经被移除了，队头指针++（队头出队）
        if (hh <= tt && i - k + 1 > q[hh]) hh ++ ;

        //当队列不空，并且队尾比新元素大时，出队
        while (hh <= tt && a[q[tt]] >= a[i]) tt -- ;
        q[ ++ tt] = i;

        //输出队头，队头永远是当前滑动窗口中最小的元素
        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }

    puts("");

    hh = 0, tt = -1;
    for (int i = 0; i < n; i ++ )
    {
        if (hh <= tt && i - k + 1 > q[hh]) hh ++ ;

        while (hh <= tt && a[q[tt]] <= a[i]) tt -- ;
        q[ ++ tt] = i;

        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }

    puts("");

    return 0;
}

