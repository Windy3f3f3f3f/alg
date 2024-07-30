#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int N = 102, M = 1<<11;
int g[N];
int n,m;
vector<int> states;
vector<pair<int,int> > prevs[M];
int cnt[M];
int f[2][M][M];

bool check(int state){
    for(int i=0;i<m;i++){
        if ((state >> i & 1) && ((state >> i + 1 & 1) || (state >> i + 2 & 1))){
            return false;
        }
    }
    return true;
}

int count(int state){
    int res=0;
    for(int i=0;i<m;i++){
        res+=(state>>i) &1;
    }
    return res;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            switch(c){
                // p 可以放东西
                case 'P':c=0;
                break;
                case 'H':c=1;
                break;
                default: cout<<"error";
            }
            g[i] += c<<j;
        }
    }

    //预处理出可以放东西的状态
    for(int i=0;i<1<<m;i++){
        if(check(i)){
            cnt[i]=count(i);
            states.push_back(i);
        }
    }

    //预处理出可以放东西之前的状态
    for(int a: states){
        for(int b: states){
            for(int c: states){
                // a <-- b, c
                if( ((a&b)==0  && (a&c)==0 && (b&c)== 0)){
                    //可以更新
                    pair<int,int> x;
                    x.first = b;x.second=c;
                    prevs[a].push_back(x);
                }
            }
        }
    }
    
    // dp
    for(int i=1;i<=n+2;i++){
        for(int a: states){
            for(pair<int,int> prev :prevs[a]){
                int b = prev.first;
                int c = prev.second;
                //更新, f[i][b][a], where a是i行, b是i-1行, c是i-2行
                if((b&g[i-1])==0 && (a&g[i])==0){
                    f[i&1][b][a] = max(f[i&1][b][a], f[(i-1)&1][c][b]+cnt[a]);
                }
            }
        }
        for(int a: states){
            for(int b:states){
                f[(i-1)&1][a][b]=0;
            }
        }
    }
    cout<<f[(n+2)&1][0][0]<<endl;
}




