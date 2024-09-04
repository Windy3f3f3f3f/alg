#include <cstring>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>//万能头文件
using namespace std;
constexpr int N=100010;
int n,m;
int h[N],e[N],ne[N],idx;
int in[N];//每一个点的入度，拓扑排序需要这个东西
vector<int> res;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
bool topsort(){//1. 找到入度为0的点入队 2. bfs //判断是不是拓扑结构 是不是所有的点都实现了入度为0并入队
    // std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    set<int> q;

    for(int i=1;i<=n;i++){//因为数字是从1到n的，所以一定要从1开始
        if(!in[i]){
            q.insert(i);
        }
    }

    while(!q.empty()){
        auto small_iter = q.begin();
        int t = *(small_iter);
        q.erase(small_iter);
        cout<<t;
        res.push_back(t);
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];//很玄妙
            in[j]--;
            if(in[j]==0) q.insert(j);//tt总是先++，hh总是后++
        }
    }
    return 1;
}

int main(){
    cin>>n>>m;
    memset(h,-1, sizeof h);//一定要初始化不然TLE
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        in[b]++;//b的入度+1
    }
    if(!topsort()){
        cout<<-1<<endl;
    }
    else {
        for(auto result: res){
            cout<<result;
        }
    }
}
