// #include<iostream>
// #include<cstring>
// #include<algorithm>
// using namespace std;
// const int N = 1e5+10;
// int f[N], w[N];
// int t,n;
// int main(){
//     cin>>t;
//     while(t--){
//         cin>>n;
//         memset(f,0,sizeof f);
//         for(int i=1;i<=n;i++){
//             cin>>w[i];
//         }
//         // f[n] = max(f[n-1],f[n-2]+w[n]);
//         // 两个状态，抢了和没抢
//         // 
//         f[1] = w[1];
//         for(int i=2;i<=n;i++){
//             f[i] = max(f[i-1],f[i-2]+w[i]);
//         }
//         cout<<f[n]<<endl;
//     }
//     return 0;
// }


#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
int f[N][2], w[N];
int t,n;

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        memset(f,0,sizeof f);
        for(int i=1;i<=n;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){
            f[i][0] = max(f[i-1][0],f[i-1][1]);
            f[i][1] = f[i-1][0]+w[i];
        }
        cout<<max(f[n][0],f[n][1])<<endl;
    }
    return 0;
}
