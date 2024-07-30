#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 9, M = 1 << N;

int ones[M], map[M];
int row[N], col[N], cell[3][3];
char str[100];

void init()
{
    // 都初始化为全1
    for (int i = 0; i < N; i ++ )
        row[i] = col[i] = (1 << N) - 1;
    //都初始化为全1
    for (int i = 0; i < 3; i ++ )
        for (int j = 0; j < 3; j ++ )
            cell[i][j] = (1 << N) - 1;
}

//画进去
void draw(int x, int y, int t, bool is_set)
{
    if (is_set) str[x * N + y] = '1' + t;
    else str[x * N + y] = '.';

    int v = 1 << t;
    if (!is_set) v = -v;

    row[x] -= v;
    col[y] -= v;
    cell[x / 3][y / 3] -= v;
}

int lowbit(int x)
{
    return x & -x;
}

int get(int x, int y)
{
    return row[x] & col[y] & cell[x / 3][y / 3];
}

bool dfs(int cnt)
{
    //判断填完了的条件
    if (!cnt) return true;
    //
    int minv = 10;
    int x, y;
    //找到要填的地方，要填的地方应该是1最多少的一块？
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j < N; j ++ )
            //如果是空的，可以填的话
            if (str[i * N + j] == '.')
            {
                //得到一个9位二进制串，1的地方就是还能填的地方
                int state = get(i, j);
                //得到1的个数，即还能填的地方的数量
                if (ones[state] < minv)
                {
                    minv = ones[state];
                    x = i, y = j;
                }
            }

    int state = get(x, y);
    //将里面的所有1对应的数字，即可以填的数字一个一个来dfs
    for (int i = state; i; i -= lowbit(i))
    {
        // 得到他对应的值，填进去
        int t = map[lowbit(i)];
        draw(x, y, t, true);
        // 搜索，如果搜到了，return true即可
        if (dfs(cnt - 1)) return true;
        // 外部搜索，你搜过了之后要把状态给改回来
        draw(x, y, t, false);
    }
    //都搜不到就return false
    return false;
}

int main()
{
    //预处理出log2(N)的值
    for (int i = 0; i < N; i ++ ) map[1 << i] = i;

    //外层循环，从0到 < 1<<N的值，即从0到9个1，
    for (int i = 0; i < 1 << N; i ++ )
        //对于每一个这样的值，去看他的每一位上的1的个数
        for (int j = 0; j < N; j ++ )
            ones[i] += i >> j & 1;

    //while循环读输入，str是整个棋盘，通过判断到end来结尾
    while (cin >> str, str[0] != 'e')
    {
        //每一次都得初始化所有变量
        init();
        int cnt = 0;
        for (int i = 0, k = 0; i < N; i ++ )
            for (int j = 0; j < N; j ++, k ++ )
                if (str[k] != '.')
                {
                    //填进去
                    int t = str[k] - '1';
                    draw(i, j, t, true);
                }
                else cnt ++ ;
        //开始搜
        dfs(cnt);

        puts(str);
    }

    return 0;
}
