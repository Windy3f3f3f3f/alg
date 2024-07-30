#include <iostream>
#include <algorithm>
using namespace std;
void divide(int x){
    for(int i=2;i<=x/i;i++){ //用i<=x/i而不是i*i<=x是因为防止越界
        if(x%i==0){
            int s=0;
            while(x%i==0) x/=i, s++;
            cout << i << ' ' << s << endl;
        }
    }
    // 这里是把2到sqrt x的搞定
    // 最多只有一个>sqrt x的
    if(x>1) cout<<x<<' '<<1<<endl;
}
int main(){
    divide(86);
    return 0;
}
