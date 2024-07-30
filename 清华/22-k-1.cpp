#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin>>n>>m;
    string x;
    cin>>x;
    int res=0;
    int cnt=0;
    for(int i=0;i<x.length();i++){
        if(x[i]=='1'){
            cnt++;
        }
        if(x[i]=='0'){
            if(cnt>=m)
                res+=(cnt-m+2)*(cnt-m+1)/2;
            cnt=0;
        }
    }
    if (cnt>=m){
        res+=(n-m+2)*(n-m+1)/2;
    }
    cout<<res;
}

/*
10 3
0111011110
*/
