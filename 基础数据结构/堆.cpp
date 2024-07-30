#include<iostream>
using namespace std;
#include<algorithm>
const int N = 100010;
int n,m;
int h[N],size_;

void down(int u){
    int t=u;
    if(u*2<=size_ && h[u*2]<h[t]) t=u*2;
    if(u*2+1<=size_ && h[u*2+1]<h[t]) t=u*2+1;
    if(u!=t){
        swap(h[u],h[t]);
        down(t);
    }
}

void up(int u){
    while(u/2&&h[u/2]>h[u]){
        swap(h[u/2],h[u]);
        u=u/2;
    }
}



int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&n);
    }
    size_ = n;
    for(int i=n/2;i;i--){
       down(i);
    }
    while(m--){
        printf("%d",h[1]);
        h[1]=h[size_];
        size_--;
        down(1);
    }
    return 0;

}