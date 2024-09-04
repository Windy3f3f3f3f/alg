#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, k;
const int N = 5010;
typedef pair<int, int> PII;
pair<int, int> x[N];
int f[N][N];
bool cmp(PII x1, PII x2){
    return x1.second<x2.second;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int ai,bi;
        cin>>ai>>bi;
        x[i].first = ai;
        x[i].second = bi;
    }
    sort(x+1, x+n+1, cmp);
    // // 看看排序对不对
    // for(int i=1;i<=n;i++){
    //     cout<<x[i].second<<endl;
    // }
    //初始化边界：
    for(int i=1;i<=n;i++){
        f[i][1] = max(f[i-1][1], x[i].first);
    }
    //求最大收益
    for(int i=1;i<=n;i++){
        for(int k=2;k<=i;k++){
            for(int t=k-1;t<i;t++){
                f[i][k] = max(f[t][k-1]-(x[i].second-x[t].second)+x[i].first, f[i][k]);
            }
        }
    }

    int res = 0;
    for(int i=1;i<=n;i++){
        res = max(res, f[i][k]);
    }
    cout<<res;
}

/*
5 5
1 5
2 4
3 3
4 2
5 1

5 2
1 5
2 4
3 3
4 2
5 1
*/
