//
// Created by Wendy on 2023/10/12.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 9;
string str;
//1的地方都是可以放的
int col[N],row[N];
int sub[N];
int count[N*N];
int ones[2<<N];
int map[2<<N];
void init() {
    for (int i = 0; i < N; i++) {
        sub[i] = col[i] = row[i] = (1 << 9) - 1;
    }
}

void draw(int i,int j,int k,int draw){
    if(draw){
        str[i*9+j]='1'+k;
        //把那些位置置成0
        k=1<<k;
        row[i]=row[i]& ~k;
        col[j]=col[j]& ~k;
        sub[i/3*3+j/3]=sub[i/3*3+j/3]& ~k;
    }
    else{
        //这里应该改成把那位置成1
        str[i*9+j]='.';
        k=1<<k;
        row[i]=row[i]|k;
        col[j]=col[j]|k;
        sub[i/3*3+j/3]=sub[i/3*3+j/3]|k;
    }
}

int lowbit(int x)
{
    return x & -x;
}

int dfs(int cnt){
    if(cnt==0){
        cout<<str<<endl;
        return 1;
    }

    //找到1最少的
    int minc = 10;
    int x, y;
    int state;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(str[i*9+j]=='.'){
                state = row[i]&col[j]&sub[i/3*3+j/3];
                int num = ones[state];
                if(num<minc){
                    x=i,y=j;
                    minc=num;
                }
            }
        }
    }
    state = row[x] & col[y] & sub[x/3*3+y/3];
    for (int i = state; i; i -= lowbit(i)){
        int k = map[lowbit(i)];
        draw(x,y,k,1);
        if(dfs(cnt-1)){
            return 1;
        }
        draw(x,y,k,0);
    }
    return 0;
}

int main(){
    //初始化count
    for(int i=0;i<=(1<<N)-1;i++){
        for(int j=0;j<N;j++){
            ones[i] += i >> j & 1;
        }
    }
    //初始化map
    for(int i=0;i<N;i++){
        map[1 << i] = i;
    }

    while(cin>>str,str[0]!='e'){
        init();
        int cnt = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(str[i*N+j]!='.'){
                    draw(i,j,str[i*N+j]-'1',1);
                }
                else{
                    cnt++;
                }
            }
        }
        dfs(cnt);
    }
}