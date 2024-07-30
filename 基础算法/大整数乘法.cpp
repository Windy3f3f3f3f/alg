#include<iostream>
#include <vector>
using namespace std;
//C=A*b, A是大整数，b是int型的小整数
vector<int> mul(vector<int> &A,int b){
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size()||t!=0;i++){
        if(i<A.size()) t+=A[i]*b;
        C.push_back(t%10);
        t/=10;
    }
    return C;
}
int main(){
    string a;
    int b;
    cin>>a>>b;
    vector<int> A;
    for(int i=a.size()-1;i>=0;i--)
        A.push_back(a[i]-'0');
    auto C=mul(A,b);
    for(int i=C.size()-1;i>=0;i--)
        printf("%d",C[i]);
    return 0;

}