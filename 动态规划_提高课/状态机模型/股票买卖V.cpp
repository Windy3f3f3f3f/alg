#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int w[N];
int f[N][3];
#define free 0
#define hold 1
#define selled 2
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    memset(f,-0x3f,sizeof f);
    f[0][free] = 0, f[0][hold]=-0x3f3f3f3f,f[0][selled]=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        f[i][free] = max(f[i-1][free],f[i-1][selled]);
        f[i][hold] = max(f[i-1][free]-w[i],f[i-1][hold]);
        f[i][selled] = f[i-1][hold]+w[i];
    }
    cout<<max(f[n][selled],f[n][free])<<endl;
    return 0;
}
