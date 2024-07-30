#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5+10;
const int M = 4e5+20;
int n,m;
int h[N], e[M], ne[M], idx;
int dist[N],f[N];

queue<int> q;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void bfs(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    q.push(1);

    f[1] = 1;
    while(!q.empty()){
        int ver = q.front();
        q.pop();
        for(int t = h[ver];~t;t=ne[t]){
            int to = e[t];
            if(dist[ver]+1<dist[to]){
                dist[to] = dist[ver] + 1;
                f[to] = f[ver];
                q.push(to);
            }
            else if(dist[ver]+1==dist[to]){
                f[to] = (f[to]+f[ver])%100003;
            }
        }
    }

}
int main(){
    cin>>n>>m;
    memset(h, -1, sizeof h);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);
    }
    bfs();
    for(int i=1;i<=n;i++){
        cout<<f[i]<<endl;
    }
    return 0;
}
