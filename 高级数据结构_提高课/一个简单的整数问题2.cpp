#include<iostream>
#define int long long
using namespace std;
const int N = 100050;
int n, m;
int tr[N], tri[N];
int a[N];

int lowbit(int x){
    return x&-x;
}
int sum(int* tr, int x){
    int res = 0;
    for(int i=x; i; i-=lowbit(i)){
        res+=tr[i];
    }
    return res;
}

void add(int*tr, int x, int c){
    for(int i=x; i<=n; i+=lowbit(i)){
        tr[i] += c;
    }
}

int get_sum(int n){
    return (n+1)*sum(tr, n) - sum(tri, n);
}

signed main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        //初始化树状数组要用add
        add(tr, i, a[i]-a[i-1]);
        add(tri, i, i*(a[i]-a[i-1]));
    }
    while(m--){
        char op[2];
        cin>>op;
        if(op[0] == 'Q'){
            int a,b;
            cin>>a>>b;
            int res = get_sum(b) - get_sum(a-1);
            cout<<res<<endl;
        }
        else if(op[0] == 'C'){
            int a, b, c;
            cin>>a>>b>>c;
            add(tr, a, c), add(tr, b+1, -c);
            add(tri, a, c*(a)), add(tri, b+1, -c*(b+1));
        }
    }    
}
