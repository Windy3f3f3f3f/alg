#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
typedef pair<double, double> PDD;

const int N = 18, M = 1<<18;
const double eps = 1e-8;

int n, m;
PDD q[N];
int path[N][N];
int f[M];

int cmp(double x, double y){
    if(fabs(x-y)<eps) return 0;
    else if(x<y) return -1;
    else return 1;
}

//path[i][j]代表经过 i j 这条线（行）所经过的列的压缩表示
int dfs(int state) {
    if (state == (1 << n) - 1) return 0; //此时已经被算好了的
    if (f[state] != 0x3f3f3f3f) return f[state];//记忆化搜索
    int x = 0;
    for (int j = 0; j < n; j++) {
        if (!(state >> j & 1)) {
            x = j;
            break;
        }
    }
    //找到还没经过的列
    for (int j = 0; j < n; j++) {
        //遍历所有这个列对应的行
        int new_state = state | path[x][j];
        if (new_state != state) {  // Only proceed if the state actually changes
            f[state] = min(f[state], dfs(new_state) + 1);
        }
    }
    return f[state];
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> q[i].x >> q[i].y;
        }
        memset(path, 0, sizeof path);
        
        for(int i = 0; i < n; i++){
            path[i][i] = 1 << i;
            for(int j = 0; j < n; j++){
                double x1 = q[i].x, y1 = q[i].y;
                double x2 = q[j].x, y2 = q[j].y;
                if(!cmp(x1,x2)) continue;
                double a = (y1/x1-y2/x2)/(x1-x2);
                double b = y1/x1-a*x1;
                if(cmp(a,0) >= 0) continue;
                int state = 0;
                for(int k = 0; k < n; k++){
                    double x = q[k].x, y = q[k].y;
                    if(!cmp(a*x*x+b*x, y)) state += 1 << k;
                }
                path[i][j] = state;
            }
        }
        
        memset(f, 0x3f, sizeof f);
        cout << dfs(0) << endl;
    }
    return 0;
}
