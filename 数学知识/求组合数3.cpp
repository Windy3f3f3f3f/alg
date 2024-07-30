#include <iostream>
using namespace std;
typedef long long LL;


LL qpow(LL a, LL b, LL p){
    LL res = 1;
    while(b){
        if(b&1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

LL c(LL a, LL b, int p){
    LL res = 1;
    for(int i=1, j=a; i<=b; i++, j--){
        res = res * j % p * qpow(i, p-2, p) % p;
    }
    return res;
}

LL lucas(LL a, LL b, int p){
    if (a < p && b < p) return c(a, b, p);
    return c(a % p, b % p, p)*lucas(a/p, b/p, p) % p;
}
// 但当问题规模很大，而模数是一个不大的质数的时候，就不能简单地通过递推求解来得到答案，需要用到 Lucas 定理。

int main(){
    int n; cin>>n;
    while(n--){
        LL a, b;
        int p;
        cin >> a >> b >> p;
        cout<<lucas(a,b,p)<<endl;
    }
    return 0;
}
