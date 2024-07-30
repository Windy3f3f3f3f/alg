#include <iostream>
#include "map"
#include "queue"
#include <cstring>
#include <cassert>
using namespace std;
const int N = 50010;
const int M = 200010;

typedef pair<int,int> PII;
int node[5];
int n,m;
int h[N], e[M], ne[M], w[M], idx;
int dest[N];
int st[N];
int minDest[6][6];
int state[5];
int ans = 0x3f3f3f3f;
void add(int a, int b, int c){
    w[idx] = c;
    ne[idx] = h[a];
    e[idx] = b;
    h[a]=idx++;
}

void dfs(int u,int s,int from){

    if(u==5){
        // s = s + minDest[5][from];
        if(s<ans) ans = s;
    }
    for(int i=0;i<5;i++){
        if(state[i]==0){
            s=s+minDest[from][i];
            state[i]=1;
            dfs(u+1,s,i);
            s=s-minDest[from][i];
            state[i]=0;
        }
    }
    
}

void f(int ver){
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push(make_pair(0, ver));
    
    memset(dest, 0x3f, sizeof dest);
    memset(st,0,sizeof st);
    dest[ver]=0;
    while(heap.size()!=0){
        auto t=heap.top();
        heap.pop();
        int ver_ = t.second;
        int d_ = t.first;
        if(st[ver_]==0){
            for(int i = h[ver_]; i != -1; i = ne[i]){
                int w_=w[i];
                if(dest[e[i]]>d_+w_){
                    dest[e[i]] = d_+w_;
                    heap.push(make_pair(dest[e[i]],e[i]));
                }
            }
            st[ver_]=1;
        }
    }
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for (int i = 0; i < 5; i++)
    {
        cin>>node[i];
    }
    while(m--){
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        add(x,y,t),add(y,x,t);
        
    }
    for(int i=0;i<5;i++){
        f(node[i]);
        for(int j=0;j<5;j++){
            minDest[i][j] = dest[node[j]];
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            assert(minDest[i][j]==minDest[j][i]);
        }
    }
    f(1);
    for(int i=0;i<5;i++){
        minDest[5][i] = dest[node[i]];
    }
    int res = 0x3f3f3f3f;

    //dfs一下
    int u=0;
    dfs(u, 0,5);
    cout<<ans;
    return 0;
}
