//windy 3/10
#include <iostream>
using namespace std;
const int N = 1010, M = 510, K = 110;
int f[M][N];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int m_i,n_i;
    for(int i=1;i<=k;i++){
        // f[i][j][k] 表示前i个精灵，有m血量,n精灵球
        cin>>n_i>>m_i;
        for(int j=m;j>m_i;j--){
            for(int t=n;t>=n_i;t--){
                f[j][t]=max(f[j][t],f[j-m_i][t-n_i]+1);
            }
        }
    }
    for(int j=0;j<=m;j++){
        if(f[j][n]==f[m][n]){
            if(j!=0){
                cout<<f[j][n]<<" "<<m-j+1;
            }
            else if(j==0){
                cout<<f[j][n]<<" "<<m;
            }
            return 0;
        }
    }

    return 0;
}
