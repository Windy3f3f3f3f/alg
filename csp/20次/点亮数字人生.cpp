#include <iostream>
#include <assert.h>
#include <cstring>
#include <vector>

using namespace std;
// 只要连接关系上存在环路，电路就无法正常工作。
const int Nmax = 510, kmax=5, Smax=10010, Qmax=5;
const int Nnodemax = Nmax+kmax*Nmax; //输入数量比元器件多？
int h[Nnodemax], e[Nnodemax], ne[Nnodemax], idx;//图
int in[Nnodemax];//每个节点的入度
int q[Nnodemax], hh=1, tt=0; //队列
int st[Nnodemax];
string f[Nnodemax];
int Q;
int M, N;
int Nnode;
vector<int> in_[Smax];
vector<int> out_[Smax];
void add(int a, int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
bool topsort(){
    //1.找到入度为0的节点入队
    //2.bfs //判断是不是拓扑结构，是不是所有的点都实现了入度为0并入队
    for(int i=1;i<=Nnode;i++){//从1开始
        if(!in[i]){
            q[++tt]=i;//入队
        }
    }
    while(hh<=tt){
        int t=q[hh++];
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            in[j]--;
            if(in[j]==0) q[++tt]=j;
        }
    }
    return tt==Nnode;

}

int main(){
    cin>>Q;
    while(Q--){
        cin>>M>>N;
        Nnode = M+N;
        memset(h, -1, sizeof h);
        for(int i=1;i<=N;i++){
            string func;
            cin>>func;
            f[i] = func;
            if(f[i]=="NOT"){
                st[i] = 0;//随意
            }
            else if(f[i]=="AND"){
                st[i] = 1; // 处理初始化为1
            }
            else if(f[i]=="OR"){
                st[i] = 0; //初始化为0
            }
            else if(f[i]=="XOR"){
                st[i] = 0; //初始化为0
            }
            else if(f[i]=="NAND"){
                st[i] = 0; //初始化为0
            }
            else if(f[i]=="NOR"){
                st[i] = 1; //初始化为1
            }
            int k;
            scanf("%d",&k);
            while(k--){
                string tmp;
                int a;
                cin>>tmp;
                assert(tmp[0]=='I' or tmp[0]=='O');
                if(tmp[0]=='I'){
                    a=tmp[1]-'0';//从1开始计数
                }else{
                    a=tmp[1]-'0'+ M;//从M+1开始计数
                }
                add(a, i+M);
                in[i+M]++;
            }
        }
        if(!topsort()){
            cout<<"LOOP";
        }
        int S;
        cin>>S;
        for(int i=1;i<=S;i++){
            //q从1开始
            for(int j=1;j<=M;j++){
                in_[i].clear();
                int i_; scanf("%d",&i_);
                in_[i].push_back(i_);
            }
            int s_i; scanf("%d",&s_i);
            for(int j=1;j<=s_i;j++){
                out_[i].clear();
                int i_; scanf("%d",&i_);
                out_[i].push_back(i_);
            }
        }
        for(int i=1;i<=S;i++){
            //得到各个信号的值
            for(int j=1;j<=Nnode;j++){
                if(q[j]<=M){
                    st[q[j]]=in_[i][q[j]];
                }
                int cur_node = q[j];
                for(int i=h[cur_node];i!=-1;i=ne[i]){
                    int next_node=e[i];
                    if(f[next_node]=="NOT"){
                        st[next_node] = !st[cur_node];
                    }
                    else if(f[next_node]=="AND"){
                        st[next_node] &= st[cur_node]; // 处理初始化为1
                    }
                    else if(f[next_node]=="OR"){
                        st[next_node] |= st[cur_node]; //初始化为0
                    }
                    else if(f[next_node]=="XOR"){
                        st[next_node] ^= st[cur_node]; //初始化为0
                    }
                    else if(f[next_node]=="NAND"){
                        st[next_node] |= !st[cur_node]; //初始化为0
                    }
                    else if(f[next_node]=="NOR"){
                        st[next_node] &= !st[cur_node]; //初始化为1
                    }
                }
            }
            //打印
            for(auto loc: out_[i]){
                printf("%d ",st[loc]);
            }
            puts("");
        }
    }
    return 0;
}

/*

1 #一个问题
3 5 # M=3: 3个电路输入。t N=5: 5个器件。
XOR 2 I1 I2 # 这里读五行，XOR是功能，2是两个输入信号，I1、I2对应两个电路输入
XOR 2 O1 I3 # O1对应电路输出
AND 2 O1 I3
AND 2 I1 I2
OR 2 O3 O4
4 # 运行四次
0 1 1
1 0 1
1 1 1
0 0 0 
2 5 2 # 这四次的输出，输出第五个和第二个元器件
2 5 2
2 5 2
2 5 2
*/
