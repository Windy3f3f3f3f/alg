#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 2e5+10;
LL n,m,k;
LL tr[N];
LL lowbit(LL x){
    return x&-x;
}
void add(LL x, LL c){
    for(LL i=x; i<N; i+=lowbit(i)){
        tr[i]+=c;
    }
}
LL sum(LL x){
    LL res = 0;
    for(LL i=x; i; i-=lowbit(i)){
        res+=tr[i];
    }
    return res;
}

int main(){
    cin>>n>>m>>k;
    //是否需要初始化树状数组？
    for(int i=1;i<=n;i++){
        LL t,c;
        scanf("%lld%lld",&t,&c);
        LL a = t-c+1;
        LL b = t;
        if(a<=0) a=1;
        // 区间[a,b]? 
        add(a,1);
        add(b+1,-1);
    }
    for(int i=1;i<=m;i++){
        LL q;
        scanf("%lld",&q);
        // 单点 q+k 获得结果
        cout<<sum(q+k)<<endl;
    }
    return 0;
}
