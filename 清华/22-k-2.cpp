#include <iostream>
#include <list>
using namespace std;
typedef pair<int,int> PII;


const int N = 2e5+10;

list<pair<int,int>> s[N];
int sum[N];

void op1(int x,int w,int c){
    sum[x]+=c*w;
    s[x].push_back({c,w});
}
void op2(int x, int c){
    int res=0;
    while(1){
        PII poped = s[x].back();
        s[x].pop_back();
        if(poped.first>c){
            poped.first-=c;
            sum[x]-=c*poped.second;
            res+=c*poped.second;
            s[x].push_back(poped);
            break;
        }else if(poped.first==c){
            sum[x]-=c*poped.second;
            res+=c*poped.second;
            break;
        }else{
            sum[x]-=poped.first*poped.second;
            c = c - poped.first;
            res+=poped.first*poped.second;
        }
    }
    cout<<res<<endl;
}

void op3(int x, int y) {
    // 反转 s[x]，然后拼接到 s[y] 但是现在翻转复杂度是 O(n) 的，手写一个O1的，因此要重新写链表
    s[x].reverse();
    s[y].splice(s[y].end(), s[x]);
    sum[y] += sum[x];
    sum[x] = 0;
}

int main(){
    int n,m; cin>>n>>m;
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int x,w,c;
            cin>>x>>w>>c;
            op1(x,w,c);
            cout<<sum[x]<<endl;
        }else if(op==2){
            int x,c;
            cin>>x>>c;
            op2(x,c);
        }else if(op==3){
            int x,y;
            cin>>x>>y;
            op3(x,y);
            cout<<sum[y]<<endl;
        }
    }
}
