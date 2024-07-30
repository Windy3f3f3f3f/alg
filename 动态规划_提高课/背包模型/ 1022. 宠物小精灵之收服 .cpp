//
// Created by Wendy on 2023/8/6.
//
# include <iostream>
using namespace std;
const int M = 1010, K = 510;
int f[M][K];
int main(){
    //v1是精灵球数量，v2是体力值，v2尽可能大
    int n,m1,m2;
    scanf("%d%d%d",&m1,&m2,&n);
    int v1,v2;

    for(int i=1;i<=n;i++){
        cin>>v1>>v2;
        //如果要写2维的，就要从小变大
        for(int j=m1;j>=v1;j--){
            for(int k=m2;k>v2;k--){
                f[j][k]=max(f[j][k],f[j-v1][k-v2]+1);
            }
        }
    }
    for(int i=0;i<=m2;i++){
        if(f[m1][m2]==f[m1][i]){
            if(i!=0)
                printf("%d %d",f[m1][m2],m2-(i-1));
            else{
                printf("%d %d",f[m1][m2],m2);
            }

            return 0;
        }
    }


}