#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1010;
const int P = 20010;
int n,p,k;
int dist[N];
int state[N];
int h[P], ne[P], e[P], w[P], idx;
deque<int> q;
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int check(int mid){
    memset(state, 0, sizeof state);
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    q.push_back(1);
    while(q.size()){
        int t = q.front();
        q.pop_front();
        if(state[t]) continue;
        state[t] = true;
        for(int i=h[t];~i;i = ne[i]){
            int j = e[i];
            int v = w[i] > mid;
            if(dist[j] > dist[t] + v){
                dist[j] = dist[t]+v;
                if(!v) q.push_front(j);
                else q.push_back(j);
            }
        }
    }
    return dist[n]<=k;
}

int main(){
    cin>>n>>p>>k;
    memset(h,-1,sizeof h);
    while(p--){
        int a, b, c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    int l=0, r = 1000001;
    while(l<r){
        int mid = l+r >> 1;
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    if (r==1e6+1) r = -1;
    cout << r << endl;
    return 0;
}
