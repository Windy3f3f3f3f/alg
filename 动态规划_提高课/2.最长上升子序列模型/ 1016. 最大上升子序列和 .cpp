#include <iostream>
#include <algorithm>

using namespace std;

//集合：以i结尾的上升子序列的集合
//集合属性：和的最大值
//状态转移，思考f[i]，可以划分为子序列中倒数第二个数具体是什么
//方程 f[i] = max (f[j]+a[i]), where j<i

const int N = 1010;
int n;
int a[N];
int s[N];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }


    for(int i=0;i<n;i++){
        s[i]=a[i];
        for(int j=0;j<i;j++){
            if(a[i]>a[j])
                s[i]=max(s[i],s[j]+a[i]);
        }
    }
    int ret=0;
    for(int i=0;i<n;i++){
        ret = max(ret,s[i]);
    }
    printf("%d",ret);
}