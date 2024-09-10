#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 110*2;
int n;
int w[N];
int f[N][N];

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld", &w[i]);
        w[i+n]=w[i];
    }
    memset(f, 0,sizeof f);
    for(int len=3;len<=n+1;len++){
        for(int l=1;l+len-1<=2*n;l++){
            int r = l+len-1;
            for(int mid=l+1;mid<=r-1;mid++){
                f[l][r] = max(f[l][r], f[l][mid]+f[mid][r]+w[l]*w[r]*w[mid]);
            }
        }
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        res = max(res, f[i][i+n]);
    }
    cout<<res;
}
