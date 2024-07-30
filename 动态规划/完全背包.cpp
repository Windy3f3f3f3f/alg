#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int n,m;
int v[N],w[N];
int f[N];

//int main(){
//    cin>>n>>m;
//    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
//    for(int i=1;i<=n;i++){
//        for(int j=0;j<=m;j++){
//            for(int k=0;k*v[i]<=j;k++)
//                f[i][j]=max(f[i][j],f[i-1][j-v[i]*k]+w[i]*k);
//        }
//    }
//    cout<<f[n][m]<<endl;
//}

//int main(){
//    cin>>n>>m;
//    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
//    for(int i=1;i<=n;i++){
//        for(int j=0;j<=m;j++){
//            f[i][j]=f[i-1][j];
//            if(j>=v[i])
//                f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);
//        }
//    }
//    cout<<f[n][m]<<endl;
//}


int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++){
        for(int j=v[i];j<=m;j++){
                f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    cout<<f[m]<<endl;
}