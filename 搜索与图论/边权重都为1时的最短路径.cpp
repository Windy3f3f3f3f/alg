#include <cstring>
#include <iostream>
using namespace std;
#include <algorithm>


const int N = 100010;
int n,m;//分别是点和边

int h[N],e[N],ne[N],idx;//存图

int d[N],q[N];//d是距离，q是队列

void add(int a, int b){
    //即在a对应的链表中插入一个b
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int bfs(){
    int hh=0,tt=0;
    q[0]=1;
    memset(d,-1,sizeof d);
    d[1]=0;
    while(hh<=tt){
        int t=q[hh++];
        for(int i = h[t];i!=-1;i=ne[i]){

        }
    }
}

int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    cout<<bfs()<< endl;
}