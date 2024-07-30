#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define eps 1e-9
const int MAXN = 220;
double a[MAXN][MAXN], x[MAXN];
int equ,var;
int Gauss(){
    int i,j,k,col,max_r;
    for(k=0,col=0;k<equ&&col<var;k++,col++){
        max_r = k;
        //行第一个元素中绝对值最大那个
        for(i=k+1;i<equ;i++){
            if(fabs(a[i][col])>fabs(a[max_r][col]))
                max_r = i;
        }
        if(fabs(a[max_r][col])<eps) return 0; // 不是唯一解
        
        if(k!=max_r){//如果有更大的，则交换
            for(j=col;j<var;j++)
                swap(a[k][j], a[max_r][j]);
            swap(x[k],x[max_r]);
        }
        // 归一化成1
        x[k] /= a[k][col];
        for(j=col+1;j<var;j++){
            a[k][j]/=a[k][col];
        }
        a[k][col]=1;
        for(i=0;i<equ;i++){
            if(i!=k){
                x[i]-=x[k]*a[i][col];
                for(j=col+1;j<var;j++){
                    a[i][j]-=a[k][j]*a[i][col];
                }
                a[i][col]=0;
            }
        }
    }
    return 1;
}

int main() {
    // 输入方程数和变量数
    cout << "Enter the number of equations and variables: ";
    cin >> equ >> var;

    // 输入增广矩阵
    cout << "Enter the augmented matrix row by row:\n";
    for (int i = 0; i < equ; i++) {
        for (int j = 0; j < var; j++) {
            cin >> a[i][j];
        }
        cin >> x[i]; // 常数项
    }

    // 调用Gauss函数
    int result = Gauss();
    if (result == 0) {
        cout << "No unique solution exists.\n";
    } else {
        cout << "Solution:\n";
        for (int i = 0; i < var; i++) {
            cout << "x[" << i << "] = " << x[i] << "\n";
        }
    }

    return 0;
}
