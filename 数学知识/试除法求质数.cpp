#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool is_prime(int n){
    if(n < 2) return false; //2是最小的质数，如果n小于2，那n肯定就不是质数
    int x = sqrt(n);
    for(int i = 2;i <= x;i ++){ //优化部分
        if(n % i == 0){ //如果可以被i整除，说明这个数不是质数
            return false; //返回不是
        }
    }
    return true; //返回是
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++){
        int x;
        scanf("%d",&x);
        if(is_prime(x)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
