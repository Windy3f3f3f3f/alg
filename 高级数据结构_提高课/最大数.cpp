#include <iostream>
using namespace std;
typedef long long LL;
const int N = 200010;

int m, p;
struct Node{
    int l, r;
    int v;
}tr[N*4];

void pushup(int u){//由子节点的信息计算父节点的信息
    tr[u].v = max(tr[u<<1].v, tr[u<<1|1].v); // 或 (u<<1)+1 记得加括号
}

void build(int u, int l, int r){
    tr[u] = {l, r};
    if(l==r) return;
    int mid = (l+r)>>1;
    build(u<<1,l,mid), build(u<<1|1,mid+1,r);
    // push up?
    pushup(u);
}

int query(int u, int l, int r){
    if(tr[u].l>=l && tr[u].r <=r) return tr[u].v;//树中节点已经包含在l r 中了
    int mid = (tr[u].l+tr[u].r)>>1;
    int v=0;
    if(l<=mid) v = query(u<<1, l, r);
    if(r>mid) v = max(v, query(u<<1|1, l, r));
    return v;
}

void modify(int u,int x,int v){
    if(tr[u].l==x && tr[u].r==x){
        tr[u].v = v;
    }else{
        int mid=(tr[u].l + tr[u].r)>>1;
        if(x<=mid) modify(u<<1,x,v);
        else modify(u<<1|1, x,v);
        pushup(u);
    }
}

int main(){
    int n=0, last=0; // last 是放东西的位置
    scanf("%d%d",&m,&p);
    build(1,1,m); //从跟节点开始build，l是1，r是m
    int x;
    char op[2];
    while (m--){
        scanf("%s%d", op, &x);
        if(*op == 'Q'){
            last = query(1, n-x+1, n); //从1开始query，给出l和r，找最大值
            printf("%d\n", last);
        }else{
            modify(1, n+1, ((long long)last+x) % p); //从1开始找，给出要修改的东西
            n++;
        }
    }

}
