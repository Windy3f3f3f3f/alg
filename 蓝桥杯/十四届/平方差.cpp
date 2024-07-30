#include <iostream>
#include <set>
using namespace std;
// x = (y-z)(y+z)
const int N = 1e9;
set<int> s;
int main(){
    int L,R;
    cin>>L>>R;
    int res=0;
    for(int y=0;y<=R;y++){
        for(int z=0;z<=y;z++){
            
            int x = (y-z)*(y+z);
            if(x>=L && x<=R){
                if(s.count(x)==0){
                    res++;
                    s.insert(x);                
                }
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
