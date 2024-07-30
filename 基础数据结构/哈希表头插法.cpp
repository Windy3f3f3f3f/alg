#include<iostream>
#include <cstring>
using namespace std;

///N取2~3倍数据量，这样减少冲突的可能
const int N = 200003, null = 0x3f3f3f3f;
int h[N];

int find(int x){
    int k=(x%N+N)%N;
    while(h[k]!=null && h[k]!=x){
        k++;
        if(k==N) k = 0;
    }
    return k;
}


int main(){
    int n ;
    scanf("%d",&n);
    ///对于0，每一个字节都是0，那么int就是0了
    ///对于-1，每一个字节都是1，那么int就是-1了
    memset(h, 0x3f,sizeof h);

    while(n--){
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        int k=find(x);
        if(*op=='I')
            h[k]=x;
        else{
            if(h[k]!=null){
                puts("Yes");
            }
            else{
                puts("No");
            }
        }
    }
}