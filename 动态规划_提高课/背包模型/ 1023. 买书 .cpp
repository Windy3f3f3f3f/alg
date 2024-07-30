//
// Created by Wendy on 2023/8/6.
//
//状态表示，f[i,j],表示i种书，j元钱恰好能买的书的种类。分两类，买第i类和不买第i类得到状态转移方程
//状态划分：第i个物体买0、1、2、3、4、...s 个
//f[i,j]=f[i-1,j]+f[i-1,j-v]+f[i-1,j-2*v]+f[i-1,j-3*v]+...+f[i-1,j-v*s]
//注意到：f[i,j-v]=f[i-1,j-v]+f[i-1,j-2*v]+...+f[i-1,j-s*v]

//得到f[i,j]=f[i-1,j]+f[i-1,j-v[i]]
#include <iostream>
using namespace std;

const int N = 1010;
int f[5][N];
int v[5]={0,10,20,50,100};
int main(){
    int m;
    cin>>m;
    f[0][0]=1;
    for(int i=1;i<=4;i++){
        for(int j=0;j<=m;j++){
            f[i][j]=f[i-1][j];//优化掉第一维，这个地方没问题
            if(j>=v[i]){
                f[i][j]+=f[i][j-v[i]];//这个地方也没问题，因为这层i的f已经算出来了
            }
        }
    }
    cout<<f[4][m]<<endl;
    return 0;
}


    //优化
    //
// Created by Wendy on 2023/8/6.
//
//状态表示，f[i,j],表示i种书，j元钱最多能买的书。分两类，买第i类和不买第i类得到状态转移方程
//f[i,j]=f[i-1,j]+f[i-1,j-v[i]]
#include <iostream>
using namespace std;

const int N = 1010;
int f[N];
int v[5]={0,10,20,50,100};
int main(){
    int m;
    cin>>m;
    f[0]=1;
    for(int i=1;i<=4;i++){
        for(int j=0;j<=m;j++){
            if(j>=v[i]){
                f[j]+=f[j-v[i]];
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}

