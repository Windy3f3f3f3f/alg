#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
int A[N],B[N];
double P[N];
int n, x;

double solve(int* state, int i){
    double res = 0;
    //当前状态是state，当前 要买i，然后最后买到我们要的x花掉的钱
    int state_new[N];
    for(int i=1;i<=n;i++){
        state_new[i] = state[i];
    }
    res += A[i];
    if(!state[i]&&!state[B[i]]){
        return res;
    }
    else if(!state[i]){
        state_new[B[i]]=0;//拿到货
        if(B[i]==x){
            return res;
        }else{
            res += solve(state_new, B[i]);
        }
    }
    else if(!state[B[i]]){
        state_new[i]=0;
        if(i==x){
            return res;
        }else{
            res += solve(state_new, i);
        }
    }
    else{
        //两个都有货
        //概率为p
         state_new[i]=0;
         if(i==x){
            res+=P[i]*0;
         }else{
            res+=P[i]*solve(state_new, i);
         }
        //概率为1-p
        state_new[i]=1;
        state_new[B[i]]=0;
        if(B[i]==x){
            res+=0;
        }else{
            res+=(1-P[i])*solve(state_new,B[i]);
        }
    }
    return res;
}

int main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>A[i]>>B[i]>>P[i];
    }
    double res = 0;
    double n_inv = 1/(double)n;
    for(int i=1;i<=n;i++){
        int state[N];
        for(int j=1;j<=n;j++){
            state[j] = 1;
        }
        res = res + n_inv *  solve(state, i);
    }
    printf("%lf",res);

}
