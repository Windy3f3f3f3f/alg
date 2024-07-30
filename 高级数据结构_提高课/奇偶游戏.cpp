#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>

using namespace std;
const int N = 20010;
int n, m, nn;
int p[N], d[N];
unordered_map<int, int> S;
int get(int x)
{
    if (S.count(x) == 0) S[x] = ++nn;
    return S[x];
}
int find(int x){
    if (p[x]!=x){
        int t = p[x];
        p[x] = find(p[x]);
        d[x] ^= d[t];
    }
    return p[x];
}
int main(){
    cin>>n>>m;
    for(int i = 0; i < N; i++){
        p[i] = i;
        d[i] = 0; // 0表示奇偶性相同
    }
    for(int i=1;i<=m;i++){
        int x, y;
        char op[10];
        cin>>x>>y>>op;
        int xx, yy, x_root, y_root;
        
        xx = get(x-1), yy = get(y);
        x_root = find(xx), y_root = find(yy);
        if (x_root==y_root){
            if (op[0]=='o'){
                if (d[xx]^d[yy]^1){
                    cout<<i-1<<endl;
                    return 0;
                }
            }
            else if (op[0]=='e'){
                if (d[xx]^d[yy]){
                    cout<<i-1<<endl;
                    return 0;
                }
            }
        }
        else{
            if (op[0]=='o'){
                p[x_root] = y_root;
                d[x_root] = d[xx]^d[yy]^1;
            }
            else if (op[0]=='e'){
                p[x_root] = y_root;
                d[x_root] = d[xx]^d[yy];
            }
        }
    }
    cout<<m<<endl;
    return 0;
}
