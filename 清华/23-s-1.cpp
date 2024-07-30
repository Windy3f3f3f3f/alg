#include <iostream>
using namespace std;
const int N = 7;
int n=5;
int m;
int path[N];
bool st[N];
int cnt;
typedef pair<int, pair<int, int>> PIII;
PIII rules[5];

bool check(){
    for(int i=0;i<m;i++){
        int rule = rules[i].first;
        int A = rules[i].second.first;
        int B = rules[i].second.second;

        int ret=0;
        int flag = 0;
        for(int j=0;j<n;j++){
            if(path[j]==A || path[j]==B){
                if(flag==1){
                    ret = 1;
                    break;
                }else{
                    flag=1;
                }
            }else{
                flag=0;
            }
        }
        if(rule==1)
            return ret;
        else
            return !ret;
    }
}
void dfs(int u){
    if(u==n){
        // for(int i=0;i<n;i++){
        //     printf("%d ", path[i]);
        // }
        // puts("");
        if(check()){
            cnt++;
        }
        
    }
    for(int i=0;i<n;i++){
        if(!st[i]){
            st[i]=true;
            path[u]=i;
            dfs(u+1);
            st[i]=false;
        }
    }
}
int main(){
    cin>>m;
    for(int i=0;i<m;i++){
        int type; cin>>type;
        rules[i].first = type;
        char A, B;
        cin>>A>>B;
        rules[i].second.first=A-'A';
        rules[i].second.second=B-'A';
    }
    dfs(0);
    cout<<cnt;
    return 0;
}
