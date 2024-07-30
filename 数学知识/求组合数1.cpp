#include <iostream>
using namespace std;
const int N = 2010;
int c[N][N];
int M = 1e9+7;
// int main(){
//     int n; cin>>n;
//     for(int i=0;i<=2000;i++){
//         for(int j=0;j<=i;j++){
//             if(j==0) c[i][j]=1;
//             else c[i][j] = (c[i-1][j-1] + c[i-1][j]) % M;
//         }
//     }
//     while(n--){
//         int a, b;
//         cin >> a >> b;
//         cout<<c[a][b]<<endl;
//     }
// }

int main(){
    int n; cin>>n;
    for(int i=1;i<=2000;i++){
        
        // 初始化，因为是迭代式，取值是跟上一行有关的，且j=0时为1
        c[0][0] = 1;c[1][0] = 1;c[1][1] = 1;
        for(int i=0;i<=2000;i++){
            c[i][0] = 1;
        }
        
        // 方程
        for(int j=1;j<=i;j++){
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % M;
        }
    }
    while(n--){
        int a, b;
        cin >> a >> b;
        cout<<c[a][b]<<endl;
    }
}

