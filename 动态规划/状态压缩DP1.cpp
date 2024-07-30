#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
int n,m;
const int N = 12, M =1<<N;
long long f[N][M];
vector<int> state[M];
bool st[M];

int main(){
    while(cin>>n>>m,n||m){
        // 预处理判断是否满足条件
        for(int i=0;i<1<<n;i++){
            int cnt = 0; // 记录当前有几个连续0
            bool is_valid = true;
            for(int j=0;j<n;j++){
                if(i>>j&1){ //如果是1
                    if(cnt&1){ //那么判断是否是奇数个cnt
                        is_valid=false;
                        break;
                    }
                    cnt=0;
                }
                else cnt++; //有0，++
            }
            // 处理最后的0
            if(cnt&1) is_valid = false;
            st[i] = is_valid;
        }

        // 得到相容的state
        for(int i=0;i<1<<n;i++){
            state[i].clear();
            for(int j=0;j<1<<n;j++){
                if((i&j)==0 &&st[i|j]){
                    state[i].push_back(j);
                }
            }
        }

        // 进行dp
        memset(f,0,sizeof f);
        f[0][0] = 1;
        for(int i=1;i<=m;i++){
            for(int j=0;j<1<<n;j++){
                for(auto k:state[j]){
                    f[i][j] += f[i-1][k];
                }
            }
        }
        cout<<f[m][0]<<endl;
    }
    return 0;
}
