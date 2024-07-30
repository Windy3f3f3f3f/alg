#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
const int N = 100010, M = 500010*3;
int h[N], e[M], ne[M], idx;
int dmin[N], dmax[N];
int rh[N];
int v[N];

queue<int> q;

void add(int *h, int a, int b){
    e[idx] = b, ne[idx] = h[a],  h[a] = idx++;
}
void spfa(int* dist, int s){
    if(dist == dmin){
        memset(dmin, 0x3f, sizeof dmin);
    }else{
        memset(dmax, 0, sizeof dmax);
    }
    dist[s] = v[s];
    q.push(s);
    
    while(!q.empty()){
        int ver = q.front();
        q.pop();
        int * h_;
        if(dist == dmin){
            h_ = h;
        }
        else{
            h_ = rh;
        }
        for(int t = h_[ver]; ~t; t = ne[t]){
            int to = e[t];
            if(dist == dmin){
                if(dist[to]>min(dist[ver],v[to])){
                    dist[to] = min(dist[ver],v[to]);
                    q.push(to);
                }
            }
            else if(dist==dmax){
                if(dist[to]<max(dist[ver],v[to])){
                    dist[to] = max(dist[ver],v[to]);
                    q.push(to);
                }
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(c==1){
            add(h,a,b);
            add(rh,b,a);
        }
        else{
            add(h,a,b),add(h,b,a),add(rh,a,b),add(rh,b,a);
        }
    }    
    spfa(dmin,1);
    spfa(dmax,n);
    int answer=0;
    for(int k=1;k<=n;k++){
        answer = max(dmax[k]-dmin[k],answer); 
    }
    cout<<answer<<endl;
}
