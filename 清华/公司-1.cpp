#include <iostream>
using namespace std;
int n, m;
const int N = 1e5+10;
const int M = 2e5+10;

typedef long long LL;
typedef struct Info{
    LL a;
    LL sum;
    LL n;
    double mean;
}Info;

Info f[N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld", &f[i].a);
    }
    for(int i=1;i<=m;i++){
        LL a, b;
        scanf("%lld%lld",&a,&b);
        f[a].n++;
        f[a].sum+=f[b].a;
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        if(f[i].n!=0){
            f[i].mean = (double)f[i].sum / f[i].n;
        }
        else{
            f[i].mean = 0;
        }
        if(f[i].mean>f[i].a) res++;
    }
    cout<<res;
}
