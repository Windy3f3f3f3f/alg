#include <iostream>
using namespace std;

const int N = 20, M = 3010;
int f[N][M];
int v[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    // f[i][j] = f[i-1][j] + f[i-1][j-v[i]] + ... + f[i-1][j-k*v[i]]
    // f[i][j-v[i]] = f[i-1][j-v[i]] + ... f[i-1][j-k*v[i]]
    // f[i][j] = f[i-1][j] + f[i][j-v[i]]
    f[0][0]=1;//方案问题特殊的初始化方式
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j-v[i]>=0)
                f[i][j] = f[i-1][j] + f[i][j-v[i]];
            else
                f[i][j] = f[i-1][j];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<f[n][m]<<endl;
}
