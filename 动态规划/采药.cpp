
// int n, t;
// int tcost[103], mget[103];
// int ans = 0;

// void dfs(int pos, int tleft, int tans) {
//   if (tleft < 0) return;
//   if (pos == n + 1) {
//     ans = max(ans, tans);
//     return;
//   }
//   dfs(pos + 1, tleft, tans);
//   dfs(pos + 1, tleft - tcost[pos], tans + mget[pos]);
// }

// int main() {
//   cin >> t >> n;
//   for (int i = 1; i <= n; i++) cin >> tcost[i] >> mget[i];
//   dfs(1, t, 0);
//   cout << ans << endl;
//   return 0;
// }


// int n, t;
// int tcost[103], mget[103];
// int mem[103][1003];

// int dfs(int pos, int tleft) {
//   if (mem[pos][tleft] != -1)
//     return mem[pos][tleft];  // 已经访问过的状态，直接返回之前记录的值
//   if (pos == n + 1) return mem[pos][tleft] = 0;
//   int dfs1, dfs2 = -INF;
//   dfs1 = dfs(pos + 1, tleft);
//   if (tleft >= tcost[pos])
//     dfs2 = dfs(pos + 1, tleft - tcost[pos]) + mget[pos];  // 状态转移
//   return mem[pos][tleft] = max(dfs1, dfs2);  // 最后将当前状态的值存下来
// }

// int main() {
//   memset(mem, -1, sizeof(mem));
//   cin >> t >> n;
//   for (int i = 1; i <= n; i++) cin >> tcost[i] >> mget[i];
//   cout << dfs(1, t) << endl;
//   return 0;
// }


#include <iostream>
#include <algorithm>
using namespace std;

int n, t;
int tcost[103], mget[103];

int dfs(int pos, int tleft) {
    if (pos == n + 1) return 0;
    int res2, res1;
    res1 = dfs(pos + 1, tleft);
    if (tleft >= tcost[pos])
        res2 = dfs(pos + 1, tleft - tcost[pos]) + mget[pos];
    return max(res1, res2);
}


int main() {
    cin >> t >> n;
    for (int i = 1; i <= n; i++) cin >> tcost[i] >> mget[i];
    int res = dfs(1, t);
    cout << res << endl;
    return 0;
}
