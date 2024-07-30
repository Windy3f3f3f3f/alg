//
// Created by Wendy on 2024/1/21.
//
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 810, M = 3000;
int n,p,m;
int id[N];
int h[N],w[M],e[M],ne[M],idx;
bool st[N];
int dist[N];
int q[N];
int spfa(int node){
    //多次调用，还要初始化st
    memset(st,0,sizeof st);

    //初始化循环队列
    int hh=0,tt=1;
    q[0]=node;//q里面存的是节点，不是idx
    st[node] = true;//在队列里

    //初始化dist
    memset(dist,0x3f,sizeof dist);
    dist[node]=0;

    //while循环队列，取出队列头元素，看看跟他相邻的节点，更新距离。并且如果更新了距离并且不在队列里，就把他们入队。
    while(hh!=tt){
        int x = q[hh];
        st[x]=false;
        hh=(hh+1)%N;

        for(int i=h[x];i!=-1;i=ne[i]){
            //注意i是idx
            if(dist[x]+w[i]<dist[e[i]]){
                dist[e[i]]=dist[x]+w[i];
                if(!st[e[i]]){
                    st[e[i]]=true;
                    q[tt]=e[i];
                    tt=(tt+1)%N;
                }
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        int j = id[i];
        // 注意这里要判断dist是不是0x3f3f3f3f，不然会上溢出
        if(dist[j]==0x3f3f3f3f) return 0x3f3f3f3f;
        sum+=dist[j];
    }
    return sum;
}

void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int main(){
    cin>>n>>p>>m;
    for(int i=0;i<n;i++) cin>>id[i];
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
        // 这里的a,b是牧场号，不是其他奇奇怪怪的东西
    }
    int res = 0x3f3f3f3f;
    for(int i=1;i<=p;i++){
        res = min(res,spfa(i));
    }
    cout<<res<<endl;
    return 0;
}
