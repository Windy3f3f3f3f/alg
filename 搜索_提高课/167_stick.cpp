//
// Created by Wendy on 2023/10/13.
//

#include <iostream>
using namespace std;
#include <cstring>
#include <algorithm>

int n;
const int N = 70;
int w[N];
int total_length;
int st[N];
int dfs(int n_small, int now_length, int length){
    if(n_small*length==total_length){
        printf("%d\n",length);
        return 1;
    }
    if(now_length==length){
        return dfs(n_small+1,0,length);
    }
    for(int i=0;i<n;i++){
        if(st[i]){
            continue;
        }
        if(now_length+w[i]>length){
            continue;
        }
        st[i]=1;
        if(dfs(n_small,now_length+w[i],length)){
            return 1;
        }
        st[i]=0;
        if(now_length==0){
            return 0;
        }
        if(now_length+w[i]==length){
            return 0;
        }
        int j=i;
        while(j<n && w[j]==w[i]) j++;
        i=j-1;
    }
    return 0;
}
int main(){
    while(cin>>n,n!=0){
        //memset()
        total_length=0;
        memset(st,0,sizeof(st));
        for(int i=0;i<n;i++){
            cin>>w[i];
            total_length+=w[i];
        }
        sort(w,w+n,greater<int>());
        int length=1;
        while(true){
            if(total_length%length==0){
                if(dfs(0,0,length)==1){
                    break;
                }
            }
            length++;
        }

    }
}