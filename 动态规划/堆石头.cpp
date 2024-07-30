#include <iostream>
#include <algorithm>

using namespace std;
const int N = 310;
int n;
int s[N];
int f[N][N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);

    //前缀和
    for(int i=1;i<=n;i++)
        s[i]=s[i]+s[i-1];

    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1)
    }

    for(int len=2;len<=n;len++){
        for()
    }
}
