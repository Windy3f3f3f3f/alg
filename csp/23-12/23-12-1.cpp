#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <deque>
using namespace std;


int n,m;
const int N = 1010, M = 15;
int f[N][M];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&f[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        int found = 0;
        for(int j=1;j<=n;j++){
            if(i==j){
                continue;
            }
            for(int k=1;k<=m;k++){
                if(f[i][k]<f[j][k]&&k==m){
                    found = j;
                    break;
                }
                else if(f[i][k]>=f[j][k]){
                    break;
                }
            }
            if(found!=0){
                break;
            }
        }
        cout<<found<<endl;
    }
    return 0;
}
