//
// Created by Wendy on 2024/1/20.
//
#include <iostream>
#include <cstring>
using namespace std;
const int N = 2510, M = 6200*2+10;
int n,m,S,T;
int h[N],e[M],ne[M],w[M],idx;
int dist[N], q[N];
bool st[N];
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void spfa(){
    // 初始化dist为无穷大
    memset(dist, 0x3f, sizeof dist);
    // 初始化循环队列，循环队列有hh 和tt。当hh==tt时，表示没有东西。循环队列是当hh或者tt等于n的时候，把他们改成0
    int hh=0, tt=1;
    q[hh] = S;
    st[S] = true;
    dist[S] = 0;
    //for循环一直去for循环队列，每次取出队头，然后判断一下与这条边相连的dist这个dist是不是可以被这个队头更新，可以的话就更新
    //并且更新之后，如果这个被更新距离了的节点不在队列里，就把他加进队列里。
    while(hh!=tt){
        int x = q[hh];
        hh = (hh+1)%N;
        st[x] = false;
        for(int i=h[x]; i!=-1; i=ne[i]){
            int bb = e[i];
            if(dist[x]+w[i]<dist[bb]){
                dist[bb] = dist[x]+w[i];
                if(!st[bb]){
                    //加进来
                    q[tt]=bb;
                    st[bb]=true;
                    tt = (tt+1)%N;
                }
            }
        }
    }
}
int main(){
    cin>>n>>m>>S>>T;
    memset(h, -1, sizeof h);

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    spfa();
    cout<<dist[T]<<endl;
}