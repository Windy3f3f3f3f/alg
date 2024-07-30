#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 12, M = 1<<N, K = N*N;
int cnt[M];
vector<int> states;
vector<int> prev_states[M];
long long f[N][K][M];
int n,m;
bool check(int state){
    for (int i = 0; i < n; i ++ )
        if ((state >> i & 1) && (state >> i + 1 & 1))
            return false;
    return true;
}

int count(int state){
    int res = 0;
    for(int i=0;i<n;i++){
        res+=state>>i&1;
    }
    return res;
}


int main(){
    cin>>n>>m;

    //预处理出合法的state
    for(int i=0;i<1 << n;i++){
        if(check(i)){
            states.push_back(i);
            cnt[i] = count(i);
        }
    }

    //预处理出某个合法state的前置state
    for(int a: states){
        for(int b:states){
            if((a&b)==0 && check(a|b))
                prev_states[a].push_back(b);
        }
    }
    f[0][0][0] = 1;
    //DP
    for(int i=1;i<=n+1;i++){
        for(int j=0;j<=m;j++){
            for(int state: states){
                for(int prev: prev_states[state]){
                    int c = cnt[state];
                    if(j>=c){
                        f[i][j][state]+=f[i-1][j-c][prev];
                    }
                }                
            }
        }
    }
    cout<<f[n+1][m][0]<<endl;
    return 0;
}
