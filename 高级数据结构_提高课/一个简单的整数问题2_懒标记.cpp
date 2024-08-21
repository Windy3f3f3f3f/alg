#include <bits/stdc++.h>
using namespace std;
const long long N = 500010;

long long n, m;
long long w[N];
struct Node{
    long long l, r;
    long long sum, add;// add 表示不包括该节点的子节点需要加，因此在修改的时候，如果要改下面的，要先把下面改了(pushdown)，才接着改
}tr[N*4];


void pushup(Node &u, Node &l, Node &r){//同样是计算信息，并且这还可以用在query 
    u.sum = l.sum+r.sum;
}

void pushup(long long u){//由子节点的信息计算父节点的信息，这个是用在build的时候
    pushup(tr[u], tr[u<<1], tr[u<<1|1]);
}

void pushdown(long long u){
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add)
    {
        left.add += root.add, left.sum += (left.r - left.l + 1) * root.add;
        right.add += root.add, right.sum += (right.r - right.l + 1) * root.add;
        root.add = 0;
    }
}

void build(long long u, long long l, long long r){ //build的过程其实是递归的过程，build的l,r前要build [l,mid], [mid+1,r]
    if(l==r){
        tr[u] = {l,r,w[l],0};//注意这里是改位置!!!他的坐标是根据l/r知道的，而不是数的节点编号u
    }else{
        tr[u] ={l, r};//这里一定要记得写，因为push up只改值!
        long long mid = (l+r)>>1;
        build(u<<1,l,mid), build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(long long u,long long l, long long r, long long d){ // 单点修改其实是找节点的过程，因此要二分，找的去区间要变
    if(l<=tr[u].l && tr[u].r<=r){
        tr[u].sum += (tr[u].r-tr[u].l+1)*d;
        tr[u].add += d;
    }else{
        pushdown(u);
        long long mid=(tr[u].l + tr[u].r)>>1;
        if(l<=mid) modify(u<<1,l,r,d);
        if(r>mid) modify(u<<1|1, l,r,d);
        pushup(u);
    }
}

Node query(long long u, long long l, long long r){ //query里l和r一直不变，当区间 被包含于 [l,r]时，可以从该节点得到信息，因此return
    if(l<=tr[u].l && tr[u].r <=r) {
        return tr[u];//树中节点已经包含在l r 中了
    }
    else{
        //要操作某个地方前，都要pushdown，包括query
        pushdown(u);
        long long mid = (tr[u].l+tr[u].r)>>1;
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

void print_tree(long long u, long long depth = 0) {
    // 打印当前节点的缩进
    for (long long i = 0; i < depth; i++) cout << "  ";
    
    // 打印节点信息
    cout << "Node " << u << ": [" << tr[u].l << ", " << tr[u].r << "]  sum: " << tr[u].sum<<endl;
    
    // 如果不是叶子节点，继续打印子节点
    if (tr[u].l != tr[u].r) {
        print_tree(u * 2, depth + 1);     // 左子节点
        print_tree(u * 2 + 1, depth + 1); // 右子节点
    }
}

signed main(){
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    build(1, 1, n);
    while(m--){
        char op[2];
        long long l, r;
        scanf("%s%lld%lld",op,&l,&r);
        if(op[0]=='C'){
            long long d;
            scanf("%lld", &d);
            modify(1, l, r, d);
        }else{
            cout<<query(1, l, r).sum<<endl;
        }

    }
    return 0;
}
 
