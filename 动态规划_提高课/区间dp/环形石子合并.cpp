#include<bits/stdc++.h>
using namespace std;
const int N = 410;
int n;
int s[N], w[N];
int f_min[N][N];
int f_max[N][N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        w[i+n]=i;
    }
    for(int i=1;i<=n*2;i++){
        s[i] = s[i-1]+w[i];
    }
    for(int i=1;i<=n*2;i++){
        s[i]=s[i-1]+w[i];
    }
    memset(f_min, 0x3f, sizeof f_min);
    memset(f_max, -0x3f, sizeof f_max);
    for(int len=1;len<=n;len++){
        for(int l=1;l+len-1<=n*2;l++){
            int r = l+len-1;
            if(len==1) f_min[l][r] = f_max[l][r]=0;
            else{
                for(int k=l;k<r;k++){ //
                    f_min[l][r] = min(f_min[l][r],f_min[l][k]+f_min[k+1][r]+s[r]-s[l-1]);
                    f_max[l][r] = max(f_max[l][r], f_max[l][k]+f_max[k+1][r]+s[r]-s[l-1]);
                }
            }
        }
    }
    int res_min = 
    for(int i=0;i<=n;i++){

    }
    cout<<f_min[1][n]<<endl<<f_max[1][n];
}
