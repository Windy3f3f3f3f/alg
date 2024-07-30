#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5e5+10;
const int M = 1e4+10;
int n;
int a[N], cnt[M];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    a[0]=0;
    a[n+1]=0;
    // 去除相等的
    n = unique(a,a+n+2)-a; // 剩下n个数了，那么a[0]-a[n-1]
    // 统计每个数字对应有几个山峰几个山谷
    for(int i=1;i<n-1;i++){
        // 如果是山峰，那么到这里应该会+1
        // 如果是山谷，那么-1
        // 其他则不变
        if(a[i-1]<a[i] && a[i]>a[i+1]){
            cnt[a[i]]++;
        }
        else if(a[i-1]>a[i] && a[i]<a[i+1]){
            cnt[a[i]]--;
        }
    }
    int res, sum = 0;

    for(int i=M;i>0;i--){
        sum+=cnt[i];
        res = max(res, sum);
    }
    cout<<res<<endl;

}
