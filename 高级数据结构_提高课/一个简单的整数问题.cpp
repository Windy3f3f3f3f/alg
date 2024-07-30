#include <iostream>
using namespace std;
#define int long long
const int N = 1e5+10;

int a[N], n;
int m;
int tr[N];
int lowbit(int x){
    return x&-x;
}

void add(int x, int c){
    for(int i=x; i<=n; i+=lowbit(i)){
        tr[i] += c;
    }
}

int sum(int x){
    int res = 0;
    for(int i=x; i; i-=lowbit(i)){
        res+=tr[i];
    }
    return res;
}


signed main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++){
        add(i, a[i]-a[i-1]);
    }
    while(m--){
        char op[2];
        cin>>op;
        if(op[0] == 'Q'){
            int x; cin>>x; //输出第x个数，也就是区间和
            int res = sum(x);
            cout<<res<<endl;
        }
        else if(op[0] == 'C'){
            int a,b,c;
            cin>>a>>b>>c;//区间[a,b]每个数加c，也就是tr[a]+=c, tr[b+1]-=c
            add(a, c);
            add(b+1, -c);
        }
    }
    return 0;
}
