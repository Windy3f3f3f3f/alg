#include<iostream>
using namespace std;
#include<algorithm>
#include <string.h>

const int N = 100010;
int h[N],size_;
int ph[N];
int hp[N];

void heap_swap(int a,int b){
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);

}

void down(int u){
    int t=u;
    if(u*2<=size_ && h[u*2]<h[t]) t=u*2;
    if(u*2+1<=size_ && h[u*2+1]<h[t]) t=u*2+1;
    if(u!=t){
        heap_swap(u,t);
        down(t);
    }
}

void up(int u){
    while(u/2&&h[u/2]>h[u]){
        heap_swap(u/2,u);
        u=u/2;
    }
}



int main(){
    int n,m=0;
    scanf("%d",&n);
    while(n--){
        char op[10];
        int k,x;

        scanf("%s",op);
        if(!strcmp(op,"I")){
            scanf("%d",&x);
            size_++;
            m++;
            ph[m]=size_;
            hp[size_]=m;
            h[size_]=x;
            up(size_);
        }
        else if(!strcmp(op,"PM"))
            printf("%d\n",h[1]);
        else if(!strcmp(op,"DM")){
            heap_swap(1,size_);
            size_--;
            down(1);
        }
        else if (!strcmp(op,"D")){
            scanf("%d",&k);
            k=ph[k];
            heap_swap(k,size_);
            size_--;
            down(k),up(k);
        }
        else{
            scanf("%d%d",&k,&x);
            k=ph[k];
            h[k]=x;
            down(k),up(k);
        }
    }
    return 0;
}