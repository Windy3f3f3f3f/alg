//
// Created by Wendy on 2023/7/7.
//
#include <iostream>

#include <vector>
using namespace std;
const int N = 1e6+10;

//C=A+B
vector<int> sub(vector<int> &A, vector<int> &B){
    int t=0;
    vector<int> C;
    for(int i=0;i<A.size()||i<B.size();i++){
        if(i<A.size()) t+=A[i];
        if(i<B.size()) t+=B[i];
        C.push_back(t%10);
        t/=10;
    }
    if(t==1){
        C.push_back(1);
    }
    return C;
}

int main(){
    string a,b;
    vector<int>A,B;
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--)
        A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)
        B.push_back(b[i]-'0');
    auto C = sub(A, B);
    for(int i=C.size()-1;i>=0;i--)
        printf("%d",C[i]);
    return 0;
}