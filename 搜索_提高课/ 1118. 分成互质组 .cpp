//
// Created by Wendy on 2023/10/3.
//
//先预处理出每个数与哪儿些数互质
//然后dfs
#include <iostream>

using namespace std;

const int N = 15;

int n;
int p[N]; // 存放数
int group[N][N]; // 存放每个组
bool st[N]; // 标记每个数是否被放进了组内
int ans; // 当前所存在的最优解

int gcd(int a, int b) { // gcd求最大公约数
    return b ? gcd(b, a % b) : a;
}

bool check(int g[], int gc, int num) { // 判断当前组中的数是否和该数都互质(即该数能否放进该组)
    for (int i = 0; i < gc; ++ i) // 枚举此组组内每个数
        if (gcd(g[i], p[num]) > 1 ) // 只要组内有数和该数不互质了就 return false
            return false;
    return true; // 否则 return true
}

void dfs(int g, int gc, int tc, int start) {
    // g为当前的最后一组的组的序号, gc为当前组内搜索到的数的序号；
    // tc为当前搜索过的数的数量, start为当前组开始搜索的数的序号

    if (g >= ans) return ; // 如果有比当前最优解所需的组数更多的解法说明此解不为最优解-->直接return即可
    if (tc == n) ans = g; // 如果搜完了所有点了,说明此解为当前的最优解,更新最优解

    bool flag = true; // flag标记是否能新开一组
    for (int i = start; i < n; ++ i) // 枚举每个数
        if (!st[i] && check(group[g], gc, i)) { // 如果当前数还未被放进组里 且 与当前的组中的数都互质
            st[i] = true; // 将该数标记为被放进组里的状态
            group[g][gc] = p[i]; // 将该数放进该组
            dfs(g, gc + 1, tc + 1, i + 1);
            // 继续搜索该组,组内数的数量gc + 1,总的数的数量tc + 1,搜索的数的序号i + 1
            st[i] = false; // 恢复
            flag = false; // 如果能放进当前最后一组,则不用新开一组,故flag标记为false
        }

    if (flag) dfs(g + 1, 0, tc, 0);
    // 如果无法放进最后一组,则新开一组来搜索
    // 当前最后一组的组的序号g + 1, 组内搜索的数的序号gc为0；
    // 搜索到的数tc未变, 当前组内开始搜索的数的序号start为0
    /* 此时的dfs操作其实就相当于开了一个组开始搜索的操作,还没有放数进来 */
}

int main() {
    cin >> n;
    ans = n; // 还未搜索时,假定最优解为最坏的情况每个数都分一组

    for (int i = 0; i < n; ++ i) scanf("%d", p + i);

    dfs(1, 0, 0, 0);
    // 从第一个组g = 1, 组内没有数gc = 0；
    // 还没搜索到点tc = 0, 当前组还未开始遍历数start = 0的初始状态开始搜索

    cout << ans << endl; // 输出搜索完后的最优解

    return 0; // 结束快乐~
}