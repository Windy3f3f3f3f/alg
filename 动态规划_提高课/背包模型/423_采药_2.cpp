#include <iostream>
using namespace std;
const int T = 1010;
const int M = 110;

int f[T];
int w[M];
int v[M];
int main(){
    int n,m;
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(j-w[i]>=0){
                f[j] = max(f[j],f[j-w[i]]+v[i]);
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
