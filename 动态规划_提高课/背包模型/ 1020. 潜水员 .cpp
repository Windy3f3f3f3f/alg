//
// Created by Wendy on 2023/8/6.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=22 ,M=80;
int n,m,k;
int f[N][M];


int main(){
    cin>>n>>m>>k;
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    for(int i=1;i<=k;i++){
        int v1,v2,w;
        cin>>v1>>v2>>w;
        for(int j=n;j>=0;j--){
            for(int k=m;k>=0;k--){
                //从i-1这层转移过来的，因此要从大到小循环，如果从i层转移过来，就从小到大循环
                f[j][k]=min(f[j][k],f[max(0,j-v1)][max(0,k-v2)]+w);
            }
        }
    }
    cout<<f[n][m]<<endl;

}