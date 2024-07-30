#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
const int N = 210*210;
int p[N];
int s[N];
int find(int x){
    if(p[x]!=x){
        p[x]=find(p[x]);
    }
    return p[x];
}
int main(){
    cin>>n>>m;
    for(int i=0;i<N;i++){
        p[i]=i;
        s[i] = 1;
    }
    for(int i=1;i<=m;i++){
        int x,y,xx,yy;
        char c[2];
        cin>>x>>y>>c;
        if(c[0]=='D'){
            xx=x+1, yy=y;
        }else if(c[0]=='R'){
            xx=x, yy=y+1;
        }

        if(find(x*n+y)==find(xx*n+yy)){
            cout<< i <<endl;
            return 0;
        }else{
            int a = find(x*n+y);
            int b = find(xx*n+yy);
            if (s[a] > s[b]){ // 小的接到大的上面
                swap(a, b); // a < b
            }
            p[a] = b;
            s[b] += s[a];
        }
    }
    cout<<"draw"<<endl;
    return 0;
}
