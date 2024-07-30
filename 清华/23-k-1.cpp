#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int path[N];
bool st[N];
int pk[N][N];
int n;
int cnt=0;

void cal(){
    if(n==2){
        if(pk[0][1]==1){
            cnt++;
        }
    }else if(n==4){
        //round one
        if(pk[0][1]==1){
            int another = -1;
            if(pk[2][3]==1){
                another = 2;
            }else{
                another = 3;
            }
            if(pk[0][another]==1){
                cnt++;
            }
        }
    }else if(n==8){
        // round one
        if(pk[0][1]==1){
            int another1=-1, another2=-1, another3=-1;
            if(pk[2][3]==1)
                another1 = 2;
            else
                another1 = 3;
            if(pk[4][5]==1)
                another2 = 4;
            else
                another2 = 5;
            if(pk[6][7]==1)
                another3=6;
            else
                another3=7;
            // rount two
            if(pk[0][another1]==1){
                int another = -1;
                if(pk[another2][another3]==1)
                    another = another2;
                else
                    another = another3;
                if(pk[0][another]==1){
                    cnt++;
                }
            }
        }
    }
}

void dfs(int u){
    if(u==n){
        cal();
        return;
    }
    for(int i=0;i<n;i++){
        if(!st[i]){
            st[i]=true;
            path[u] = i;
            dfs(u+1);
            st[i]=false;
        }
    }
    return;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>pk[i][j];
    dfs(0);
    if(n==2) cnt=cnt/2;
    if(n==4) cnt=cnt/2/2;
    if(n==8) cnt=cnt/2/2/2;
    cout<<cnt;
    return 0;
}

/*
4
0 1 1 1
-1 0 1 1
-1 -1 0 1
-1 -1 -1 0
*/
