//
// Created by Wendy on 2023/9/28.
//

#include<iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1010, M = 200010;
int n, m, S, T, K;
int h[N], rh[N], e[M], w[M], ne[M], idx;
int dist[N], cnt[N];
bool st[N];
void add(int h[], int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    memset(rh, -1, sizeof rh);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(h,a,b,c);
        add(rh,b,a,c);
    }

}