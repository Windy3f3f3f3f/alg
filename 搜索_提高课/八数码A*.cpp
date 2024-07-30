//
// Created by Wendy on 2023/9/28.
//
#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef pair<int, string> PIS;
typedef pair<int, int> PII;
int f(string state)
{
    int res = 0;
    for (int i = 0; i < state.size(); i ++ )
        if (state[i] != 'x')
        {
            int t = state[i] - '1';
            res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
        }
    return res;
}

void astar(string s) {
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};
    char op[] = "rlud";
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> priorityQueue;
    unordered_map<string, int> dist;
    unordered_map<string, pair<string, char>> prev;


    string target = "12345678x";
    priorityQueue.push({0+f(s), s});
    dist[s]=0;

    while(!priorityQueue.empty()){
        PIS curPIS = priorityQueue.top();
        priorityQueue.pop();
        string curS = curPIS.second;
        if(curS == target){
            string ops;
            while(curS!=s){
                ops += prev[curS].second;
                curS = prev[curS].first;
            }
            std::reverse(ops.begin(), ops.end());
            cout<<ops;
            return;
        }
        int x,y;
        int idx;
        for(int i=0;i<curS.length();i++){
            if(curS[i]=='x'){
                x=i/3;
                y=i%3;
                idx = i;
            }
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0&&nx<3&&ny>=0&&ny<3){
                int nidx;
                nidx = nx*3+ny;
                string nS = curS;
                swap(nS[idx],nS[nidx]);
                if(!dist.count(nS)||dist[nS]>dist[curS]+1){
                    dist[nS]=dist[curS]+1;
                    priorityQueue.push({dist[nS]+f(nS),nS});
                    prev[nS] = {curS, op[i]};
                }
            }
        }
    }

}

int main(){
    string s,g;
    char c;
    while((c=getchar())!='\n'&& c!=EOF){
        if(c!=' '){
            s+=c;
            if(c!='x'){
                g+=c;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<s.length();i++){
        for(int j=i+1;j<s.length();j++){
            if(g[i]>g[j]){
                cnt++;
            }
        }
    }
    if(cnt%2==1){
        printf("unsolvable");
    }else{
        astar(s);
    }
}