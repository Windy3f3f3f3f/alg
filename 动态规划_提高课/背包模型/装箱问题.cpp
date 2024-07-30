// Windy 3/10
#include <iostream>

using namespace std;
const int V = 20010;
const int N = 35;
int w;
int f[V];
int main(){
    int n,m;
    cin>>m>>n;
    // f[i][j]表示前i个物体，空间为j，能装多少
    // f[i][j] = max(f[i-1][j],f[i-1][j-w[i]]+w[i])

    for(int i=1;i<=n;i++){
        int w;
        cin>>w;
        for(int j=m;j>=w;j--){
            f[j] = max(f[j], f[j-w]+w);
        }
    }    
    cout<< m - f[m]<<endl;
    return 0;
}
