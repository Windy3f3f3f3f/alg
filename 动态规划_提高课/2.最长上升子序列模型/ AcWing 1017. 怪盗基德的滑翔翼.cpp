#include <iostream>
#include <algorithm>

using namespace std;

//暴力：数组a[N],n个元素，遍历所有的元素，再往左、往右分别求下降子序列长度
//优化：直接求最长上升/下降子序列长度即可，这个长度就是我们要求的

int main(){
    int k,h;
    const int N = 110;
    int n;
    int a[N];
    int up[N];
    int down[N];
    scanf("%d",&k);
    for(int ii=0;ii<k;ii++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }

        for(int i=0;i<n;i++){
            up[i]=1;
            down[i]=1;
            for(int j=0;j<i;j++){
                if(a[i]>a[j]){
                    up[i]=max(up[i],up[j]+1);
                }
                if(a[i]<a[j]){
                    down[i]=max(down[i],down[j]+1);
                }
            }
        }

        int x = 1;
        for(int i=0;i<n;i++){
            x = max(x,up[i]);
        }
        for(int i=0;i<n;i++){
            x = max(x,down[i]);
        }
        printf("%d\n",x);
    }

}