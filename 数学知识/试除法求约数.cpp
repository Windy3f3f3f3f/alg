#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        vector<int> ans;
        cin>>x;
        for(int i=1;i<=x/i;i++){
            if(x%i==0){
                ans.push_back(i);
                if(i!=x/i) ans.push_back(x/i);
            }
        }
        sort(ans.begin(), ans.end());
        for(auto x : ans) cout<<x<<" ";
        cout<<endl;
    }
}
