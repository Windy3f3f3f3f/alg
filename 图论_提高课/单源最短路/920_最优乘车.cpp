//
// Created by Wendy on 2024/1/21.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
using namespace std;

const int N = 510;
int m,n;
bool g[N][N];
int dist[N];
int stop[N];
int q[N];
void bfs(){
    //初始化队列
    int hh=0,tt=1;
    q[hh]=1;
    //初始化dist为无穷大，然后加上根节点的dist
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    //循环...
    while(hh!=tt){
        int head = q[hh++];
        for(int i=1;i<=n;i++){
            if(g[head][i]&&dist[i]>dist[head]+1){
                dist[i]=dist[head]+1;
                q[tt++] = i;
            }
        }
    }
}
int main(){
    cin>>m>>n;
    string line;
    getline(cin,line);//读取换行符
    while(m--){
        getline(cin,line);//读了一行
        stringstream ssin(line);//把这个line字符串 传给stringstream
        int cnt = 0,p;
        while(ssin>>p){
            stop[cnt++]=p;
        }
        for(int j=0;j<cnt;j++)
            for(int k=j+1;k<cnt;k++)
                g[stop[j]][stop[k]]=true;
    }
    bfs();
    if (dist[n] == 0x3f3f3f3f) puts("NO");
    else cout << max(dist[n] - 1, 0) << endl;

    return 0;
}
