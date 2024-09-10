// 暴力
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e4+10;
// const int M = N;
// int h[N], w[M], ne[M], e[M], idx;
// int n;

// void add(int a, int b, int c){
//     w[idx]=c, e[idx]=b, ne[idx]=h[a], h[a] =idx, idx++;
// }

// int dfs(int s, int father){
//     int res = 0;
//     for(int i=h[s];i!=-1;i=ne[i]){
//         if(father!=e[i]){
//             res = max(res, w[i]+dfs(e[i], s));
//         }
//     }
//     return res;
// }

// int get_len(int s){
//     int first=0, second=0;
//     for(int i=h[s];i!=-1;i=ne[i]){
//         int b = e[i];
//         int len = w[i]+dfs(b, s);
//         if(len>=first){
//             second=first;
//             first=len;
//         }else if(len>=second){
//             second=len;
//         }
//     }
//     return first+second;
// }
// int main(){
//     cin>>n;
//     memset(h, -1, sizeof h);
//     for(int i=0;i<n-1;i++){
//         int a,b,c;
//         scanf("%d%d%d",&a,&b,&c);
//         add(a,b,c);
//         add(b,a,c);
//     }
//     int res = 0;
//     for(int i=1;i<=n;i++){
//         res = max(res, get_len(i));
//     }
//     cout<<res;
// }

// DP

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10, M = 2*N;
int h[N], w[N], e[M], ne[M], idx;
int f[3][N];

void add(int a, int b, int c){
    w[idx] = c, ne[idx] = h[a], e[idx] = b, h[a] = idx, idx++;
}

void dfs(int u, int father){
    for(int i=h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(j==father) continue;
        dfs(j,u);//求解出顺着顺序的最优解
        if(f[1][j]+w[i]>=f[1][u]){//如果某一条路能让最大值更新
            f[2][u] = f[1][u];
            f[1][u] = f[1][j]+w[i];
        }else if(f[1][j]+w[i]>=f[2][u]){//如果只能更新次大值
            f[2][u] = f[1][j] + w[i];
        }
    }
}

int main(){
    memset(h, -1, sizeof h);
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    int res = 0;
    dfs(1,-1);
    for(int i=1;i<=n;i++){
        res = max(f[1][i]+f[2][i], res);
    }
    cout<<res<<endl;
    return 0;
}
