#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+10;
int a[N];
int s[N];
int q[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        s[i]=s[i-1]+a[i];
    }
    int res=INT_MIN;
    int hh, tt;
    hh=0, tt=-1;
    for(int i=0;i<=n;i++){//为什么要从0开始呢？因为从1-n的和只能通过s[n]或者s[n]-s[0]表示！，因此s[0]也要放进来的
        if(q[hh]<i-m) hh++;//如果不在窗口里了，弹出
        if(i==0){
            //但是i==0的时候没东西，此时不能更新res
        }
        else res = max(res, s[i]-s[q[hh]]); //q[hh]是最小值，单调队列是要维护最小值的，这会导致进来一个元素时，之前比他大的元素都要删掉，因此队头就是最小的。
        while(hh<=tt &&s[q[tt]]>=s[i]) tt--; //如果比要加的大，都删了
        q[++tt]=i;//加进来
    }
    printf("%d\n",res);
    
}
