#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long LL;
const int N = 110, mod = 1e9+7;

// 约数个数
// int main(){
//     int n;
//     cin>>n;

//     unordered_map<int, int> primes;

//     for(int i=0;i<n;i++){
//         int x;
//         cin>>x;
//         for(int j=2;j<=x/j;j++){
//             while(x%j==0){
//                 x/=j;
//                 primes[j]++;
//             }
//         }
//         if (x>1) primes[x]++;
//     }
//     LL res = 1;
//     for (auto p:primes) res=res*(p.second+1)%mod;
//     cout << res << endl;
//     return 0;
// }

// 约数和
int main(){
    int n;
    cin>>n;

    unordered_map<int, int> primes;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        for(int j=2;j<=x/j;j++){
            while(x%j==0){
                x/=j;
                primes[j]++;
            }
        }
        if (x>1) primes[x]++;
    }
    LL res = 1;
    for (auto p:primes){
        LL a=p.first, b=p.second;
        LL t=1;
        while(b--) t=(t*a+1) % mod;
        res = res * t % mod;
    }
    cout << res << endl;
    return 0;
}
