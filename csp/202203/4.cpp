#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int n, m;
const int N = 1e5+10;
const int M = 2 * N;
int h[N], w[M], e[M], ne[N], idx;
int from[M];
vector<PII> to_deletes[N]; //每天要删的点
multiset<PII> sets[N]; //w, to
map<int, int> maps[N]; //
void delete_edge(int index, int c){
    w[index]-=c;
}

void update_edge(int day){
    for(auto recode: to_deletes[day]){
        sets[from[recode.first]].erase({w[recode.first],e[recode.first]});
        delete_edge(recode.first, recode.second);
        sets[from[recode.first]].insert({w[recode.first],e[recode.first]});
    }
}

pair<int,int> add_edge_(int a, int b, int c){
    auto it = maps[a].find(b);
    if(it!=maps[a].end()){
        //如果有，更新一下内容
        int idx_ = maps[a][b];
        sets[a].erase({w[idx_],b});
        w[idx_]+=c;
        sets[a].insert({w[idx_],b});
        return {idx_, c};
    }else{
        pair<int,int> res = {idx,c};
        from[idx]=a;
        e[idx]=b;w[idx]=c;ne[idx]=h[a];h[a]=idx++;
        maps[a][b] = idx;
        sets[a].insert({c,b});

        return res;
    }
}

void applyFor(int u, int v, int x, int y, int day){
    pair<int,int> recode_a = add_edge_(u,v,x);
    PII recode_b = add_edge_(v,u,x);
    to_deletes[day+y].push_back(recode_a);
    to_deletes[day+y].push_back(recode_b);
}

void query(int a){
    if(sets[a].size()==0||sets[a].rbegin()->first==0){
        cout<<"0"<<endl;
    }
    else{
        auto it = sets[a].rbegin();
        int max_w = it->first;
        cout<<max_w<<endl;
    }

}

int get_who_are_max_to(int i){
    auto it = sets[i].rbegin();
    if(sets[i].size()==0 || it->first==0){
        return -1;
    }
    int to = it->second;
    int max_w = it->first;
    while(1){
        it=++it; // 不能写it=it++，错误
        if (it == sets[i].rend()) break;
        if(it->first<max_w) break;
        if(it->second<to){
            to=it->second;
        }
    }
    return to;
}
void num_of_main(){
    int res = 0;
    for(int i=1;i<=n;i++){
        auto it = sets[i].rbegin();
        if(sets[i].size()==0 || it->first==0){
            continue;
        }
        else{
            int to = get_who_are_max_to(i);
            if(get_who_are_max_to(to)==i){
                res++;
            }
        }
    }
    cout<<res/2<<endl;

}

void num_of_iso(){
    int res = 0;
    for(int i=1;i<=n;i++){
        auto it = sets[i].rbegin();
        if(sets[i].size()==0 || sets[i].rbegin()->first==0){
            res++;
        }
    }
    cout<<res<<endl;
}

int main(){
    cin>>n>>m;
    for(int day=1;day<=m;day++){//每天
        update_edge(day);
        int k=0;
        scanf("%d",&k);
        for(int apply=1; apply<=k; apply++){
            //每个申请 u v x y, y表示从申请当天到申请后y-1天有效
            int u,v,x,y;
            scanf("%d%d%d%d",&u,&v,&x,&y);
            applyFor(u,v,x,y,day);
        }
        
        int l; scanf("%d",&l);
        for(int i=1;i<=l;i++){
            int id; scanf("%d",&id);
            query(id);
        }
        int p, q;
        scanf("%d%d",&p,&q);
        if(p==1){
            num_of_iso();
        }
        if(q==1){
            num_of_main();
        }
    }
}
