#include<iostream>
using namespace std;
const int N = 110;
int a[N], b[N];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    // 如果b在增加，那么新的一定就是那个b
    // 如果b没变，那么新的可以是0或者那个b
    a[0]=b[0];
    int min=a[0], max=a[0];
    for(int i=1;i<n;i++){
        if(b[i]>b[i-1]){
            max+=b[i];min+=b[i];
        }
        else{
            max+=b[i];
        }
    }
    cout<<max<<endl<<min;
}
