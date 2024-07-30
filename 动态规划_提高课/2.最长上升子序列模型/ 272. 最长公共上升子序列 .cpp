////
//// Created by Wendy on 2023/8/2.
////
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 3010;
int n;
int a[N],b[N];
int f[N][N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){

        for(int j=1;j<=n;j++){
            f[i][j]=f[i-1][j];
            if(a[i]==b[j]){
                f[i][j]=max(f[i][j],1);

                //这个地方是能在j层循环中顺带算出来的
                for(int k=1;k<j;k++){
                    if(b[k]<b[j]){//这个地方b[j]可以换成a[i]
// 这样子就是自身处理f[i][j]这个数组了,就是要求出对任意k<j，b[k]<a[i]的f[i][k]+1的最大值
// 这个其实也是可以迭代求出的 当b[j]!<a[i]时,g[i][j]=g[i][j-1]，当b[j]<a[i]时，g[i][j]=g[i][j-1]+1
                        f[i][j]=max(f[i][j],f[i][k]+1);
                    }
                }

            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++) res = max(res,f[n][i]);
    printf("%d\n",res);
    return 0;
}




#include <algorithm>
#include <iostream>
using namespace std;

const int N = 3010;
int n;
int a[N],b[N];
int f[N][N];
int g[N][N];//g[i][j]表示满足a[i]>b[j]的所有(f[i][j]+1)的最大值
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        g[i][0]=1;
        for(int j=1;j<=n;j++){
            f[i][j]=f[i-1][j];
            if(a[i]==b[j]){
                f[i][j]=max(f[i][j],g[i][j-1]);
            }
            //之前所有的最大值
            g[i][j]=g[i][j-1];
            //如果满足，就换成这个
            if(b[j]<a[i]) g[i][j]=max(g[i][j],f[i][j]+1);
        }
    }
    int res=0;
    for(int i=1;i<=n;i++) res = max(res,f[n][i]);
    printf("%d\n",res);
    return 0;
}


#include <algorithm>
#include <iostream>
using namespace std;

const int N = 3010;
int n;
int a[N],b[N];
int f[N][N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        int maxv = 1;
        for(int j=1;j<=n;j++){
            f[i][j]=f[i-1][j];
            if(a[i]==b[j]){
                f[i][j]=max(f[i][j],maxv);
            }
            if(b[j]<a[i]) maxv=max(maxv,f[i][j]+1);
        }
    }
    int res=0;
    for(int i=1;i<=n;i++) res = max(res,f[n][i]);
    printf("%d\n",res);
    return 0;
}