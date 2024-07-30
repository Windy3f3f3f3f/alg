#include <iostream>
using namespace std;
const int N = 1000010;
int primes[N], cnt; //记录得到的素数
bool st[N]; //标记元素是否被筛掉
void get_primes(int n){
    // 外层从2到n开始遍历
    for(int i=2;i<=n;i++){
        if(!st[i]) primes[cnt++]=i; //每一个数，如果之前没被筛掉，那么就加入素数列表
        for(int j=0;primes[j]<=n/i;j++){ //遍历当前的每一个素数，这里加了一个上界条件
            st[primes[j]*i]=true;
            if(i%primes[j]==0) break; //如果i是他的倍数的话，直接break
        }
    }
}
int main(){
    int n;
    cin>>n;
    get_primes(n);
    cout<<cnt;
}
