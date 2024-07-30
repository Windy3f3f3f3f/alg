#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e5+10;
const int K = 110;
int f[N][K][2];
int w[N];
#define hold 0
#define wait 1

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    memset(f, -0x3f, sizeof f);
    for (int i = 0; i <= n; i ++ ) f[i][0][wait] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            f[i][j][wait]=max(f[i-1][j][wait],f[i-1][j][hold]+w[i]);
            f[i][j][hold]=max(f[i-1][j][hold],f[i-1][j-1][wait]-w[i]);
        }
    }
    int res = 0;
    for(int i=0;i<=k;i++){
        res = max(res,f[n][i][1]);
    }
    cout<<res;
    return 0;
}
