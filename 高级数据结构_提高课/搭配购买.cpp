#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 10010;
int n,m,w;
int c[N], d[N];
int p[N];
int s[N];
int f[N];
int find(int x){
    if(x!=p[x]){
        p[x]=find(p[x]);
    }
    return p[x];
}
int main(){
    cin>>n>>m>>w;
    int cc,dd;
    for(int i=1;i<N;i++){
        p[i] = i;
        s[i] = 1;
    }
    for(int i=1;i<=n;i++){
        scanf("%d%d",&cc,&dd);
        c[i] = cc, d[i] = dd;
    }
    int uu,vv;
    for(int i=0;i<m;i++){
        scanf("%d%d",&uu,&vv);
        int puu = find(uu), pvv = find(vv);
        if(puu!=pvv){
            if (s[puu] > s[pvv]){
                swap(puu, pvv);
            }
            c[puu] += c[pvv];
            d[puu] += d[pvv];
            s[puu] += s[pvv];
            p[pvv] = puu;
        }
    }
    // 0 - 1 背包
    for(int i=1;i<=n;i++){
        if(p[i]==i){
            for(int j=w;j>=c[i];j--){
                f[j] = max(f[j],f[j-c[i]]+d[i]);
            }
        }
    }
    cout<<f[w]<<endl;
    return 0;
}
