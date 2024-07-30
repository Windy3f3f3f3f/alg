// Created on 2024/3/5
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int t,r,c;
const int N = 110;
int g[N][N];
int f[N][N];
int main(){
    cin>>t;
    while(t--){
        cin>>r>>c;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cin>>g[i][j];
            }
        }
        // dp
        memset(f,0,sizeof f);
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                f[i][j]=max(f[i-1][j],f[i][j-1])+g[i][j];
            }
        }
        cout<<f[r][c]<<endl;
    }
}
