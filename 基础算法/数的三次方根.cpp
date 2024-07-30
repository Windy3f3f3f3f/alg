#include<iostream>
using namespace std;
double n;
double fun1(double n,double l,double r){
    double mid = (l+r)/2 ;
    while(abs(mid*mid*mid-n)>=1e-10){
        if (mid*mid*mid<=n){
            l=mid;
        }
        else{
            r=mid;
        }
        mid = (l+r)/2;
    }
    return mid;
}




double tri(double n){
    if(n<=1){
        return fun1(n,0,1);
    }
    else if(n>1){
        return fun1(n,1,n);
    }
}
int main(){
    scanf("%lf",&n);
    if(n<0){
        n=-n;
        printf("-%.6lf",tri(n));
    }
    else{
        printf("%.6lf",tri(n));
    }
}