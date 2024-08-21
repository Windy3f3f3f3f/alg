#include <bits/stdc++.h>
using namespace std;
const int N=100010,M=200010;
int n,m;
int p[N];//并查集
struct Edge{
    int a,b,w;
}edge[M];//存储边的图
bool cmp(struct Edge A, struct Edge B){//比较数据结构里的元素可以写一个这个函数用到sort里sort（a,a+m,cmp）
    return A.w<B.w;
}

int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);//查找祖宗节点+路径压缩
    return p[x];
}

int kruskal(){
    sort(edge,edge+m,cmp);//按所有边的权重大小升序排序
    //初始化并查集
    for(int i=1;i<=n;i++) p[i]=i;//每个点的祖宗都是自己
    int res=0,cnt=0;//升序枚举每条边
    int max_edge = 0 ;
    for(int i=0;i<m;i++){
        int a=edge[i].a,b=edge[i].b,w=edge[i].w;
        //判断a b是否联通，判断a b的祖宗是否相同
        a=find(a);b=find(b);
        if(a!=b){
            p[a]=b;
            cnt++;
            max_edge =max(max_edge, w);
        }
    }
    return max_edge;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edge[i]={a,b,w};
    }
    int t=kruskal();
    cout<<n-1<<" "<<t;
    return 0;
}
