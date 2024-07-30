//
// Created by Wendy on 2023/8/6.
//
#include <iostream>
using namespace std;
const int N =6010;
int n,m;
int f[N];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int v,w,s;
        cin>>v>>w>>s;
        for(int j=m;j>=1;j--){
            for(int k=0;k<=s&&k*v<=j;k++){
                f[j]=max(f[j],f[j-k*v]+k*w);
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}