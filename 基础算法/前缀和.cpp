///a0 -> an
///s0 -> sn
/// al+...+ar = sr - s(l-1)
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    long long s[n];
    s[0]=arr[0];
    for(int i=1;i<n;i++){
        s[i]=s[i-1]+arr[i];
    }
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        if(l>=2){
            cout<<s[r-1]-s[l-2]<<endl;
        }
        else{
            cout<<s[r-1]<<endl;
        }
    }
}
