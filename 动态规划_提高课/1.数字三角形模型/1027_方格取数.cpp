// 2024.3.5
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 12;
int g[N][N];
int n;
int f[N][N][2*N];
int main(){
    cin>>n;
    int a,b,c;
    while(cin>>a>>b>>c,a||b||c) g[a][b]=c;
    //编号从1开始
    
    for(int k=2;k<=2*n;k++){
        for(int i1=1;i1<=n;i1++){
            for(int i2=1;i2<=n;i2++){
                int j1=k-i1, j2=k-i2;
                if(j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n) { // 添加边界检查
                    f[i1][i2][k] = max(f[i1][i2][k], f[i1][i2][k-1]);
                    f[i1][i2][k] = max(f[i1][i2][k], f[i1-1][i2][k-1]);
                    f[i1][i2][k] = max(f[i1][i2][k], f[i1][i2-1][k-1]);
                    f[i1][i2][k] = max(f[i1][i2][k], f[i1-1][i2-1][k-1]);
                    if(i1==i2) f[i1][i2][k] += g[i1][j1];
                    else f[i1][i2][k] += g[i1][j1]+g[i2][j2];
                }
            }
        }
    }
    cout<<f[n][n][2*n]<<endl;
    return 0;
}
