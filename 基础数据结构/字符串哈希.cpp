#include<iostream>
using namespace std;

///当需要快速判断两个字符串是否相等的时候，就需要使用这个算法，O(1)的时间
///KMP求循环节，其他都用哈希做

const int N = 100010,P=131;
typedef unsigned long long ull;
int n,m;
char str[N];

ull h[N],p[N];

ull get(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}
int main(){
    scanf("%d%d%s",&n,&m,str+1);
    p[0]=1;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]*P;
        h[i]=h[i-1]*P+str[i];
    }


    while(m--){
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(get(l1,r1)==get(l2,r2)) puts("Yes");
        else puts("No");
    }
}