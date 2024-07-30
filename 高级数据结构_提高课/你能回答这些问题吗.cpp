#include <bits/stdc++.h>
using namespace std;
const int N = 500010;

int n, m;
int w[N];

struct Node{
    int l, r;
    int sum, lmax, rmax, max;
}tr[N*4];

void pushup(Node &u, Node &l, Node &r){//同样是计算信息，并且这还可以用在query
    u.sum=l.sum+r.sum;
    u.max=max({l.max, r.max, l.rmax+r.lmax});
    u.lmax=max(l.lmax, l.sum+r.lmax);
    u.rmax=max(r.rmax, r.sum+l.rmax);
}

void pushup(int u){//由子节点的信息计算父节点的信息，这个是用在build的时候
    pushup(tr[u], tr[u<<1], tr[u<<1|1]);
}

void build(int u, int l, int r){ //build的过程其实是递归的过程，build的l,r前要build [l,mid], [mid+1,r]
    if(l==r){
        tr[u] = {l,r,w[l],w[l],w[l],w[l]};//注意这里是改位置!!!他的坐标是根据l/r知道的，而不是数的节点编号u
    }else{
        tr[u] ={l, r};//这里一定要记得写，因为push up只改值!
        int mid = (l+r)>>1;
        build(u<<1,l,mid), build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int x,int v){ // 单点修改其实是找节点的过程，因此要二分，找的去区间要变
    if(tr[u].l==x && tr[u].r==x){
        tr[u] = {x,x,v,v,v,v};
    }else{
        int mid=(tr[u].l + tr[u].r)>>1;
        if(x<=mid) modify(u<<1,x,v);
        else modify(u<<1|1, x,v);
        pushup(u);
    }
}

Node query(int u, int l, int r){ //query里l和r一直不变，当区间 被包含于 [l,r]时，可以从该节点得到信息，因此return
    if(l<=tr[u].l && tr[u].r <=r) {
        cout<<"now l: "<<tr[u].l<<" r: "<<tr[u].r<<endl;
        return tr[u];//树中节点已经包含在l r 中了
    }
    else{
        int mid = (tr[u].l+tr[u].r)>>1;
        if(l>mid) return query(u<<1|1,l , r);
        else if(r<=mid) return query(u<<1, l, r);
        else{
            Node res;
            auto left = query(u<<1, l, r);
            auto right = query(u<<1|1, l, r);
            pushup(res, left, right);
            return res;
        }
    }

}


int main(){
    cin>>n>>m;
    cout<<"here"<<endl;
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    build(1, 1, n);
    while(m--){
        int op, x, y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1){
            if(x>y){
                swap(x,y);
            }
            cout<<query(1, x, y).max<<endl;
        }else{
            modify(1, x, y);
        }
    }
    return 0;
}

