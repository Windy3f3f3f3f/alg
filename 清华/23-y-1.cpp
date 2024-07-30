#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 7;
bool st[N];
int path[N];
typedef pair<int, int> PII;
PII f[N];
int min_num = 0x3f3f3f3f;

// path[i]

void cal(){
    int finished_time_1[N];
    int finished_time_2[N];
    for(int index=0;index<n;index++){
        int i = path[index];
        if(index>0)
            finished_time_1[index] = finished_time_1[index-1] + f[i].first;
        else
            finished_time_1[index] = f[i].first;
    }
    for(int index=0;index<n;index++){
        int i = path[index];
        if(index>0)
            finished_time_2[index] = max(finished_time_1[index]+f[i].second, finished_time_2[index-1]+f[i].second);
        else
            finished_time_2[index] = finished_time_1[index]+f[i].second;
    }

    min_num = min(finished_time_2[n-1], min_num);
}
void dfs(int u){
    if(u==n){
        cal();
        return;
    }
    for(int i=0;i<n;i++){
        if(!st[i]){
            path[u]=i;
            st[i]=true;
            dfs(u+1);
            st[i]=false;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        min_num=0x3f3f3f3f;
        memset(st,0,sizeof st);
        memset(path,0,sizeof path);
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            f[i].first=a, f[i].second=b;
        }
        dfs(0);
        cout<<min_num<<endl;
    }

    return 0;
}

/*
2
3
10 20
25 40
20 30
3
30 35
25 25
25 30
*/
