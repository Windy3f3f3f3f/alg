#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int n;
int a[N],f[N];
//复杂度 n^2，因此可以算1000的规模
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    for(int i=1;i<=n;i++){
        f[i]=1;
        for(int j=1;j<i;j++){
            if(a[j]<a[i]){
                f[i]=max(f[i],f[j]+1);
            }
        }
    }

    int res=0;
    for(int i=1;i<=n;i++)
        res=max(res,f[i]);
    printf("%d\n",res);
}