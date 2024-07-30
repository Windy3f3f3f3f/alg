#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N =100010,M=N*2;

int h[N],e[N],ne[M],idx;//h是头，e是节点，ne是边，idx是待分配


void add(int a, int b){
    //即在a对应的链表中插入一个b
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool st[N];//哪儿点已经被遍历过了
void dfs(int u){//深度优先搜索
    st[u]=true;
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(!st[j])
            dfs(j);
    }
}


int main(){
    memset(h,-1,sizeof h);
}