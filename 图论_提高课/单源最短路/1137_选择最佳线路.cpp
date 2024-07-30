#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1010;
const int M = 20010;
int S[N];
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
int st[N];
int nS;
queue<int> q;
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void spfa(){
    memset(dist, 0x3f, sizeof dist);
    for(int i=1;i<=nS;i++){
        q.push(S[i]);
        st[S[i]] = true;
        dist[S[i]] = 0;
    }
    while(!q.empty()){
        int ver = q.front();
        q.pop();
        st[ver] = false;
        for(int t = h[ver]; ~t; t = ne[t]){
            int to = e[t], weight = w[t];
            if(dist[to]>dist[ver]+weight){
                dist[to]=dist[ver]+weight;
                if(!st[to]){
                    q.push(to);
                    st[to] = true;
                }
            }
        }

    }
}
int main(){
    int n,m,s;
    while(scanf("%d%d%d",&n,&m,&s)!=EOF){
        memset(h, -1, sizeof h);
        idx = 0;
        while(m--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
        }
        scanf("%d",&nS);
        for(int i=1;i<=nS;i++){
            scanf("%d",&S[i]);
        }
        spfa();
        if(dist[s]<0x3f3f3f3f/2){
            cout<<dist[s]<<endl;
        }
        else{
            puts("-1");
        }
    }
    return 0;
}
