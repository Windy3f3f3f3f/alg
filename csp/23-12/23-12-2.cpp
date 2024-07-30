#include <iostream>

using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        int n;
        int k;
        cin>>n>>k;

        int p=2;
        int t=0;
        int d=1;
        int x = 1;
        while(p*p<=n){
            int f=1;
            while(n%p==0){
                n=n/p;
                f=f*p;
                t++;
            }
            if(t>=k){
                x=x*f;
            }
            p++;
            t=0;
            d=1;
        }
        cout<<n<<endl;
    }
}
