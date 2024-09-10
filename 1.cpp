#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
int A[N],B[N];
double P[N];
int n, x;

double solve(int* state, int i){// solve要返回 当前状态是state，当前 要买i，然后最后买到我们要的x花掉的钱
    double res = 0;
    
    int state_new[N];
    for(int i=1;i<=n;i++){
        state_new[i] = state[i];
    }
    res += A[i];//购买i花的钱
    if(!state[i]&&!state[B[i]]){//如果i和他相关联的bi都没有
        return res;//停止
    }
    else if(!state[i]){//如果i没有 且bi有
        state_new[B[i]]=0;//拿到bi
        if(B[i]==x){//如果bi就是我们要的x
            return res;//停止
        }else{
            res += solve(state_new, B[i]);//按照题意去买bi
        }
    }
    else if(!state[B[i]]){//如果i有 且bi没有
        state_new[i]=0;
        if(i==x){
            return res;
        }else{
            res += solve(state_new, i);
        }
    }
    else{
        //如果两个都有货
        //概率为p，买到i
         state_new[i]=0;//买到i了要设置成0
         if(i==x){
            res+=P[i]*0;
         }else{
            res+=P[i]*solve(state_new, i);
         }

        //概率为1-p，没买到i，买到bi
        state_new[i]=1;//要把i复原，因为之前设置成0了
        state_new[B[i]]=0;//买了bi
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
    for(int i=1;i<=n;i++){//遍历每一个第一个要买的东西
        int state[N];
        for(int j=1;j<=n;j++){
            state[j] = 1; //存哪儿些是有放东西的
        }
        res = res + n_inv *  solve(state, i);
    }
    printf("%lf",res);

}
