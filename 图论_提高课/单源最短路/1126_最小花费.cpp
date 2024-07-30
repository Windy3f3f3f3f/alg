//
// Created by Wendy on 2024/1/21.
//

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 2010;
int n,m,S,T;
double g[N][N];
double d[N];
bool st[N];
void dij(){
    //dist初始化成0就行，然后初始化一下与S相连的
    d[S] = 1;
    for(int i=0;i<n;i++){//循环n次
        //首先找到非S集中最大的d
        int t = -1;
        for(int j=1;j<=n;j++){
            if(!st[j] && (t==-1||d[j]>d[t])){
                t=j;
            }
        }
        st[t]=true;
        //再更新与S相连的非S集的节点
        for(int j=1;j<=n;j++){
            d[j]=max(d[j],d[t]*g[t][j]);
        }
    }
}
int main(){
    cin>>n>>m;
    // g 初始化成0，表示没有边
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        double z = (100.0-c)/100;
        g[a][b] = g[b][a] = max(g[a][b],z);
    }
    cin>> S >>T;
    dij();
    printf("%.8lf\n",100.0/d[T]);
    return 0;
}