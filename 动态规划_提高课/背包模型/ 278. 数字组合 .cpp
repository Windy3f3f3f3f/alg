//
// Created by Wendy on 2023/8/6.
//
#include <iostream>
using namespace std;
const int N = 110,M=10010;
int a[N];
int f[M];

int main(){
    int n,m;
    cin>>n>>m;
    f[0]=1;

    for(int i=1;i<=n;i++){
        int v;
        cin>>v;
        for(int j=m;j>=v;j--){
            f[j]=f[j]+f[j-v];
        }
    }
    printf("%d",f[m]);
}