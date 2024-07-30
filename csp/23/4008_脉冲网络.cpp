#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

/*
check out
可能出现自环和重边？

*/
static unsigned long next_ = 1;

/* RAND_MAX assumed to be 32767 */
int myrand() {
    next_ = next_ * 1103515245 + 12345;
    return((unsigned)(next_/65536) % 32768);
}

typedef struct Node{
    double v;
    double u;
    double a;
    double b;
    double c;
    double d;
    int r;
    double i[2020];
    int cnt;
} Node;

typedef struct W{
    double w;
    double d;
} W;

Node node[2*1000+10];// 存神经元和脉冲源
const int N = 2010, M = 1010;
int ne[M], e[M], idx, h[N]; W w[M];

void add_node(int i, double v, double u, double a, double b, double c, double d){
    node[i].v=v,node[i].u=u,node[i].a=a,node[i].b=b,node[i].c=c,node[i].d=d;
}
void add_edge(int ss, int tt, double ww, int dd){
    w[idx].d=dd,w[idx].w=ww,e[idx]=tt,ne[idx]=h[ss],h[ss]=idx++;
}
int main(){
    memset(h,-1,sizeof h);
    int n,s,p,t;//神经元、突触、脉冲源、输出时刻
    double dt;//时间间隔
    cin>>n>>s>>p>>t>>dt;
    for(int i=0;i<n;){
        int rn; double vv,uu,aa,bb,cc,dd;
        scanf("%d%lf%lf%lf%lf%lf%lf",&rn,&vv,&uu,&aa,&bb,&cc,&dd);
        for(int j=0;j<rn;j++,i++){
            add_node(i,vv,uu,aa,bb,cc,dd);
        }
    }
    // cout<<"debug 1 n、p"<<n<<p<<endl;
    for(int i=n;i<n+p;i++){//[n,n+p)存脉冲源
        int rr;
        scanf("%d",&rr);
        node[i].r=rr;
    }
    while(s--){
        int ss,tt;double ww;int dd;
        scanf("%d%d%lf%d",&ss,&tt,&ww,&dd);
        add_edge(ss,tt,ww,dd);
    }
    //从 1 时刻开始按照上述规则进行计算，直到完成 T 时刻的计算，再输出 T 时刻神经元的 v 值和发放的脉冲次数分别的最小值和最大值。
    for(int i=1;i<=t;i++){
        for(int n_i=0;n_i<n;n_i++){
            //处理神经元
            double v_ = node[n_i].v;
            node[n_i].v = node[n_i].v + dt * (0.04*node[n_i].v*node[n_i].v+5*node[n_i].v+140-node[n_i].u)+node[n_i].i[i];
            node[n_i].u = node[n_i].u + dt * node[n_i].a*(node[n_i].b*v_-node[n_i].u);
            // printf("debug v %lf \n",node[n_i].v);
            if(node[n_i].v>=30){
                // printf("debug 神经元发脉冲 %d",i);
                for(int idx=h[n_i];idx!=-1;idx=ne[idx]){
                    int next_node_i = e[idx];
                    int delay = w[idx].d;
                    double qiangdu = w[idx].w;
                    node[next_node_i].i[i+delay]+=qiangdu;
                }
                node[n_i].v=node[n_i].c;
                node[n_i].u += node[n_i].d;
                node[n_i].cnt++;
            }
        }
        for(int n_i=n;n_i<n+p;n_i++){
            //处理脉冲源
            int rand = myrand();
            // cout<<"debug"<<rand<<endl;
            // cout<<"debug r is"<<node[n_i].r<<endl;
            if(node[n_i].r > rand){
                // cout<<"debug: 脉冲"<<i<<endl;
                for(int idx=h[n_i];idx!=-1;idx=ne[idx]){
                    int next_node_i = e[idx];
                    int delay = w[idx].d;
                    double qiangdu = w[idx].w;
                    node[next_node_i].i[i+delay]+=qiangdu;
                }
            }
        }
        for(int n_i=0;n_i<n+p;n_i++){
            node[n_i].i[i]=0;
        }
    }
    double min = 1e11, max = -1e11;
    for(int i=0;i<n;i++){
        if(node[i].v<min) min = node[i].v;
        if(node[i].v>max) max = node[i].v;
    }
    printf("%.3lf %.3lf\n", min, max);
    int min_=0x3f3f3f3f,max_=-0x3f3f3f3f;
    for(int i=0;i<n;i++){
        if(node[i].cnt<min_) min_ = node[i].cnt;
        if(node[i].cnt>max_) max_ = node[i].cnt;
    }
    printf("%d %d", min_, max_);
}
