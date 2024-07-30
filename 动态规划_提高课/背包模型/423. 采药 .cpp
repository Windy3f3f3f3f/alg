////
//// Created by Wendy on 2023/8/6.
////
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//const int M = 110;
//const int T = 1010;
//int v[M],w[M];
//int f[M][T];
//int t,m;
////0-1背包问题，easy
//int main(){
//    cin>>t>>m;
//
//    for(int i=1;i<=m;i++){
//        scanf("%d%d",&v[i],&w[i]);
//    }
//    //f[i][j]=max(f[i-1][j]，f[i-1][j-v[i]]+w[i])
//    int maxx=0;
//    for(int i=1;i<=m;i++){
//        for(int j=1;j<=t;j++){
//            f[i][j]=f[i-1][j];
//            if(j>=v[i]){
//                f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
//            }
//            maxx=max(maxx,f[i][j]);
//        }
//    }
//    printf("%d",maxx);
//
//
//    return 0;
//}

#include <iostream>
using namespace std;
const int N = 1010;
int n,m;
int f[N];
int main(){
    cin>>m>>n;
    for(int i=0;i<n;i++){
        int v,w;
        cin>>v>>w;
        for(int j=m;j>=v;j--)
            f[j]=max(f[j],f[j-v]+w);
    }
    cout<<f[m]<<endl;
}
