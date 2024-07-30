#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1010;

int m,n;
int v[N],w[N];
int f[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            f[i][j]=f[i-1][j];
            if(j>=v[i])
                f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
        }
    }
    cout<<f[n][m]<<endl;

//    for(int i=1;i<=n;i++){
//        for(int j=v[i];j<=m;j++){
//                f[j]=max(f[j],f[j-v[i]]+w[i]);//这样是有问题的f[j-v[i]]已经在这层被算过了
//        }
//    }

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);//这样正确，此时f[j-v[i]]还是上一层未更新的}
    cout<<f[m]<<endl;
    }