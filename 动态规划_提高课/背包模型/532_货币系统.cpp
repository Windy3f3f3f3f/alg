#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[110];
int f[110][25010];
int st[110];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);//要排序
        int k = 0;
        memset(f,0,sizeof f);
        f[0][0]=1;
        for(int i=1;i<n;i++){
            //f[i][j]，前i个可以表示j
            for(int j=0;j<=25010;j++){
                if(j-a[i]>=0){
                    f[i][j] = f[i-1][j] + f[i][j-a[i]];
                }
                else{
                    f[i][j] = f[i-1][j];
                }
            }
            if(!f[i][a[i+1]]) k++;
        }
        cout<<k+1<<endl;
        
    }

}
