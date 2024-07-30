#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;
const double eps = 1e-8;

int n,m;
double a[N][N];

int gauss()  // 高斯消元，答案存于a[i][n]中，0 <= i < n
{
    int c, r;
    for (c = 0, r = 0; c < m; c ++ )
    {
        int t = r;
        for (int i = r; i < n; i ++ )  // 找绝对值最大的行
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;

        if (fabs(a[t][c]) < eps) continue;

        for (int i = c; i <= m; i ++ ) swap(a[t][i], a[r][i]);  // 将绝对值最大的行换到最顶端
        for (int i = m; i >= c; i -- ) a[r][i] /= a[r][c];  // 将当前行的首位变成1
        for (int i = r + 1; i < n; i ++ )  // 用当前行将下面所有的列消成0
            if (fabs(a[i][c]) > eps)
                for (int j = m; j >= c; j -- )
                    a[i][j] -= a[r][j] * a[i][c];

        r ++ ;
    }
    for (int i = r; i < n; i ++ )
        if (fabs(a[i][m]) > eps) 
            return 2; // 无解

    if(r<m){
        return 1;// 有解的情况下，r<m就是无穷多组解
    }
    if(r==m){
        //唯一解
        for (int i = n - 1; i >= 0; i -- )
            for (int j = i + 1; j < m; j ++ )
                a[i][m] -= a[i][j] * a[j][m];
    }


    return 0; // 有唯一解
}


int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    // m=n;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m + 1; j ++ )
            scanf("%lf", &a[i][j]);

    int t = gauss();
    if (t == 2) puts("No solution");
    else if (t == 1) puts("Infinite group solutions");
    else
    {
        for (int i = 0; i < m; i ++ ) //m个变量
            printf("%.2lf\n", a[i][m]);
    }

    return 0;
}

