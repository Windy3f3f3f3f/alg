#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
//spfa可以用来做正权的题，不过在某些情况会被卡
const int N = 100010;
typedef pair<int, int> PII;
int n,m;
//稀疏图
int h[N],w[N],e[N],ne[N],idx;
int dist[N];
bool st[N];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    queue<int> q;
    q.push(1);
    st[1]=true;

    while(q.size()){
        int t=q.front();
        q.pop();
        st[t]=false;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[t]+w[i]){
                dist[j]=dist[t]+w[i];
                if(!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }

        }
    }
    if(dist[n]==0x3f3f3f3f)
        return -1;
    return dist[n];
}

int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    int t=spfa();
    if(t==-1){
        printf("impossible");
    }
    else{
        printf("%d\n",t);
    }
    return 0;
}
