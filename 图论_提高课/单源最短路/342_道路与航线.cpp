#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int M = 50010 * 3;
const int N = 25010;
int n,r,p,s;
int h[N], w[M], e[M], ne[M], idx;
int id2group_id[N];
int groupId2degree[N];
int dist[N];
int st[N];
queue<int> q;
vector<int> block[N];
typedef pair<int,int> PII;
void add(int a, int b, int c){
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int i, int tuan_idx){
    id2group_id[i] = tuan_idx;
    block[tuan_idx].push_back(i);
    for(int t = h[i]; ~t; t = ne[t]){
        int to = e[t];
        if(id2group_id[to]==0 && w[t]>=0){
            dfs(to, tuan_idx);
        }
    }
}

void dijkstra(int tuan_idx){
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    for(auto u : block[tuan_idx]){
        heap.push({dist[u], u});
    }
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i=h[ver];~i;i=ne[i]){
            int j = e[i];
            if(id2group_id[j]!=id2group_id[ver] && -- groupId2degree[id2group_id[j]]==0){
                q.push(id2group_id[j]);
            }
            if(dist[j] > dist[ver] + w[i]){
                dist[j] = dist[ver] + w[i];
                if(id2group_id[j] == id2group_id[ver]) heap.push({dist[j],j});
            }
        }
    }
}

void topsort(int tuan_idx){
    // 
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    // 队列来放拓扑序
    for(int i=1;i<=tuan_idx;i++){
        if(!groupId2degree[i]){
            q.push(i);
        }
    }
    // 
    while(q.size()){
        int t = q.front();
        q.pop();
        dijkstra(t);
    }
}

int main(){
    // 读题可以看出来，航线是单向的，因此求距离的时候是可以用拓扑顺序去求距离
    // 可以定义连通块，在连通块内部用Dij算法去计算最短路，在不同连通块之间用拓扑顺序
    cin >> n >> r >> p >> s;
    // !图一定要先memset
    memset(h, -1, sizeof h);
    while(r--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c),add(b,a,c);
    }    


    //1.dfs一下，给每个点一个连通块的id，并记录入度和出度
    int tuan_idx = 0;
    for(int i=1;i<=n;i++){
        if(id2group_id[i]==0){
            dfs(i,++tuan_idx);
        }
    }
    
    while(p--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        groupId2degree[id2group_id[b]]++;
    }
    //2.找到入度为0的连通块，作为第一个搜的连通块开始
    topsort(tuan_idx);
    //2.1 使用dij，先在第一个连通块内部开始搜

    //2.2 如果有某一个连通块的入度的节点的最短路都被求出来了，就可以进一步求那个新的连通块的最短路
    //因此管理这些连通块用队列
    for (int i=1;i<=n;i++){
        if(dist[i]>0x3f3f3f3f/2) cout<<"NO PATH"<<endl;
        else cout<< dist[i]<<endl;
    }
    return 0;
}
