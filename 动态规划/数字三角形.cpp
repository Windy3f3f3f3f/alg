#include <iostream>
#include <algorithm>
using namespace std;
const int N = 510, INF = 1e9;
int n; //存储三角形的行数
int a[N][N]; // 定义二维数组a，用于存储三角形中的数字
int f[N][N]; // 定义二维数组f，用于存储动态规划过程中的状态


int main(){
    // 输入数，输入并存入
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            scanf("%d",&a[i][j]);
    }
    // 初始化动态规划数组
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i+1;j++)
            f[i][j]=-INF; // 将f数组初始化为-INF，表示还未计算过的状态
    }
    // DP
    f[1][1]=a[1][1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            // 状态转移方程，考虑从左上和正上方转移过来的情况，取两者的最大值，并加上当前的数字
            f[i][j]=max(f[i-1][j-1]+a[i][j],f[i-1][j]+a[i][j]);
        }
    }
    // 在三角形的最后一行中寻找最大的路径和
    int res=-INF;
    for(int i=1;i<=n;i++){
        res=max(res,f[n][i]);
    }
    printf("%d\n",res);
    return 0;

}