#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
deque<PII> deq;
priority_queue<int> imp;
int n,m;//n:执行的操作个数 m:队伍的最大容量
int idx=1;
int main()
{
   scanf("%d%d",&n,&m);
    while(n--){
        int op;
        cin>>op;
        if(op==1)
        {
            int importance;cin>>importance;
            if(deq.size()>=m) cout<<"ERR"<<endl, idx++;
            else 
            {
                deq.push_back({importance,idx});
                imp.push(importance);
                cout<<idx<<endl;
                idx++;
            }
        }
        if(op==2)
        {
            int importance;cin>>importance;
            int xi;cin>>xi;
            auto it=find_if(deq.begin(),deq.end(),[xi](const PII& p){
                return p.second==xi;
            });
            if(deq.size()>=m||it==deq.end()) cout<<"ERR"<<endl, idx++;
            else
            {
                deq.insert(it,{importance,idx});
                imp.push(importance);
                cout<<idx<<endl;
                idx++;
            }
        }
        if(op==3)
        {
            if(deq.size()==0) cout<<"ERR"<<endl;
            else
            {
                cout<<deq.front().second<<endl;
                priority_queue<int> temp;
                while(!imp.empty()){
                    if(imp.top()!=deq.front().first){
                        temp.push(imp.top());
                    }
                    imp.pop();
                }
                imp=temp;
                deq.pop_front();
            }
        }
        if(op==4)
        {
            if(deq.size()==0) cout<<"ERR"<<endl;
            else{
                int max_imp=imp.top();
                imp.pop();
                auto it= find_if(deq.begin(),deq.end(),[max_imp](const PII&p){
                    return p.first==max_imp;
                });
                cout<<it->second<<endl;
                deq.erase(it);
            }
        }
    }
    return 0;
}
