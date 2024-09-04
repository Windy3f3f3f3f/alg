#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 2e6+10;

int n;
int o[N], d[N];
LL s[N];
int q[N];
bool st[N];

int main(){
    cin>>n;
    for( int i=1;i<=n;i++) scanf("%d%d", &o[i], &d[i]);
    //顺时针做的时候是oi-di，你是真的的时候是oi-d[i-1]
    for(int i=1; i<=n; i++){
        s[i] = s[i+1]=o[i]-d[i];
    }
    for(int i=1;i<=n*2;i++){
        s[i] +=s[i-1];
    }
    int hh=0, tt=0;
    for(int i=n*2;)
}
