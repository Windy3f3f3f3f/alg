//
// Created by Wendy on 2023/8/6.
//
#include <iostream>
using namespace std;
const int N = 20010;
int f[N];
int main(){
    int n,m;
    cin>>m>>n;
    int v,w;
    for(int i=1;i<=n;i++){
        cin>>v;
        w=v;
        for(int j=m;j>=v;j--){
            f[j]=max(f[j],f[j-v]+w);
        }
    }
    printf("%d",m-f[m]);
}