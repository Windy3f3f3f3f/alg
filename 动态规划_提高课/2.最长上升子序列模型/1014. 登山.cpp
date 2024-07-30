#include <iostream>
#include <algorithm>
using namespace std;

//即要求序号单调递增，爬山的高度也是先单调递增，再单调递减，不能相同
//其实就是单调子序列问题，不过要先增再减
//暴力：遍历所有的中间点，求出两个以这个中间点为端点的最长单调递增、最长单调递减
//n<=1000，说明要n^2、n^2logn的算法，暴力算法是n^3的不行

//优化，求出以每个点结尾的上升子序列最大值，以每个点开头的下降子序列最大值，然后相加即可
//这个优化其实就是利用了求出上升子序列最大值的过程的中间结果
// 复杂度n^2
const int N =  1010;
int a[N];
int n;
int up[N];
int down[N];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i =0;i<n;i++){
        up[i]=1;
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                up[i]=max(up[i],up[j]+1);
            }
        }
    }

    for(int i=n-1;i>=0;i--){
        down[i]=1;
        for(int j=n-1;j>i;j--){
            if(a[i]>a[j]){
                down[i]=max(down[i],down[j]+1);
            }
        }
    }
    int x = 1;
    for(int i =0;i<n;i++){
        x = max(x,down[i]+up[i]-1);
    }
    printf("%d",x);

}