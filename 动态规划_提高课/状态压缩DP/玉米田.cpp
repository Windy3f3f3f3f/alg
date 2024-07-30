#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int N = 14, M = 1<<N;
int f[N][M];
int g[N];
int n,m;
int mod = 1e8;
vector<int> states;
vector<int> prevs[M];

bool check(int state){
    for(int i=0;i<1<<m;i++){
        if( ((state>>i) &1) && ((state>>(i+1))&1) ){
            return false;
        }
    }
    return true;
}
int main(){
    cin>>n>>m;
    // 读取，例如如果是110，就会读一个(110)_2进g数组里
    for(int i=0;i<n;i++){
        int x=0;
        int y=0;
        for(int i=0;i<m;i++){
            cin>>y;
            x = (x << 1) | y;
        }
        g[i] = x;
    }    
    // 预处理合法状态
    for(int i=0;i<1<<m;i++){
        if(check(i)){
            states.push_back(i);            
        }
    }
    // 得到状态的合法前缀
    for(int a : states){
        for(int b : states){
            if((a&b)==0){
                prevs[a].push_back(b);
            }
        }
    }
    // dp
    f[0][0]=1;
    for(int i=1;i<=n+1;i++){
        for(int a : states){
            for(int prev : prevs[a]){
                if((a|g[i-1])==g[i-1]){
                    f[i][a] = (f[i][a]+f[i-1][prev])%(mod);
                }
            }
        }
    }
    cout<<f[n+1][0]<<endl;
    return 0;
}
