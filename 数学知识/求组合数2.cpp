#include <iostream>


using namespace std;

const int M = 1e9 + 7, N = 1e5+10;
typedef long long LL;
LL fact[N], infact[N]; // i! mod M, i!^(-1) mod M

int qpow(int a, int b, int p){
    int res = 1;
    while(b){
        if(b&1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }
    return res;

}

int main(){
    int n; cin>>n;
    //先预处理，再查表
    fact[0] = 1;
    infact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = (LL)fact[i-1] * i % M;
        infact[i] = (LL)infact[i-1] * qpow(i, M-2, M) % M;
    }

    while(n--){
        int a, b;
        // 1 <= n <= 10000;
        // 1 <= b <= a <= 10e5;
        //显然需要一个O(max{a,b})的算法
        cin >> a >> b;
        // C(a,b) = a!/b!(a-b)! = a! * inverse(b!) * inverse((a-b)!)
        // inverse(b!) = inverse((b-1)!) * inverse(b) = inverse((b-1)!) * b^(M-2)
        // 其实就是逆元用费马小定理求解，然后用快速幂求
        cout<<fact[a] * infact[b] % M * infact[a-b] % M<<endl;
    }
    return 0;
}
