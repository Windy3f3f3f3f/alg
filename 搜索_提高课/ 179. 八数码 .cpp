//
// Created by Wendy on 2023/9/13.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;
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
string bfs(string start){
    string end = "12345678x";
//    int dx[] = {0, 0, -1, 1};
//    int dy[]= {1,-1,0,0};
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
//    char op[] = "udlf";
    char op[4] = {'u', 'r', 'd', 'l'};
    unordered_map<string, int> dist;
    unordered_map<string, pair<string, char>> prev;
    priority_queue<pair<int, string>,vector<pair<int, string>>, greater<pair<int, string>>> heap;
    heap.push({f(start),start});
    dist[start] = 0;//记录从初始状态距离
    while(heap.size()){
        auto t = heap.top();
        heap.pop();//pop不直接返回元素
        string state = t.second;
        if(state == end) break;
        int step = dist[state];
        int x,y;
        for(int i=0;i<state.size();i++){
            if(state[i]=='x'){
                x=i/3,y=i%3;
                break;
            }
        }
        string source = state;
        //宽搜更多状态
        for(int i=0;i<4;i++){
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < 3 && b >= 0 && b < 3){
                swap(state[x * 3 + y], state[a * 3 + b]);
                //什么时候加入队列（1.没搜到过这个状态，2.当前这个状态被搜过了，但是距离比较大？）
                if(!dist.count(state) || dist[state] > step + 1){
                    dist[state] = step + 1;
                    prev[state] = {source, op[i]};
                    heap.push({dist[state] + f(state), state});
                }
                swap(state[x*3+y],state[a*3+b]);
            }
        }
    }

    string res;
    while(end != start){
        res += prev[end].second;
        end = prev[end].first;
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    string g, c, seq;
    char cc;
    while((cc = getchar()) != '\n' && cc != EOF) { // 读取直到行尾或文件尾
        if(cc != ' ') {
            g += cc;
            if(cc!='x') {
                seq += cc;
            }
        }
    }
    cout<<g<<endl<<seq;
    int t = 0;
    //求一下seq中逆序对数量
    for(int i=0;i<seq.size();i++){
        for(int j=i+1;j<seq.size();j++)
            if(seq[i] > seq[j])
                t++;
    }
    if(t%2)
        puts("unsolvable");
    else
        cout << bfs(g) <<endl;
    return 0;
}