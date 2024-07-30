#include <iostream>
#include <algorithm>
using namespace std;

//其实就是N个同学，找出K个，先递增再下降，并且数量最多
//其实就是上一题
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
    printf("%d",n-x);

}