//Windy 3/10
#include <iostream>
using namespace std;
const int N = 110;
const int M = 10010;
int f[N][M];//前N个数中，使得和为M的方案数目
int n,m;
int w[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if(j-w[i]>0){
                f[i][j] = f[i-1][j] + f[i-1][j-w[i]];
            }
            else if(j-w[i]==0){
                f[i][j] = f[i-1][j]+1;
            }
            else{
                f[i][j] = f[i-1][j];
            }
        }
    }
    cout<<f[n][m];
}
