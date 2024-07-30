////
//// Created by Wendy on 2023/8/1.
////
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 1010;
//int a[N];
//int s[N];
//int t[N];
////贪心法
//
//int main(){
//    int n=0;
//    do {
//        scanf("%d",&a[n]);
//        n++;
//    }
//    while(getchar()!='\n');
//    int x=0;
//    for(int i=0;i<n;i++){
//        t[i]=1;
//        for(int j=0;j<i;j++){
//            if(a[j]>=a[i]){
//                t[i]=max(t[i],t[j]+1);
//            }
//        }
//        x=max(x,t[i]);
//    }
//    printf("%d\n",x);
//
//
//    // 贪心算法需要多少个序列能遍历完
//    for(int i = 0; i < n; i++){
//        int minDiff = 0x2f2f2f, j_best = -1;
//        for(int j = 0; j < n && s[j] != 0; j++){
//            int diff = s[j] - a[i];
//            //这里想找一个最接近的
//            if(diff >= 0 && diff < minDiff){
//                j_best = j;
//                minDiff = diff;
//            }
//        }
//        if(j_best == -1){
//            s[j_best + 1] = a[i];
//        }
//        else{
//            s[j_best] = a[i];
//        }
//    }
//
//    for(int i=0;i<n+1;i++){
//        if(s[i]==0){
//            printf("%d",i);
//            return 0;
//        }
//    }
//
//}

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;

int n;
int q[N];
int f[N],g[N];

int main(){
    while(cin>>q[n]) n++;
    int res = 0;
    for(int i=0;i<n;i++){
        f[i]=1;
        for(int j=0;j<i;j++){
            if(q[j]>=q[i])
                f[i]=max(f[i],f[j]+1);
        }
        res = max(res,f[i]);
    }
    cout<<res<<endl;

    int cnt =0;
    for(int i=0;i<n;i++){
        int k=0;
        while(k<cnt&&g[k]<q[i]) k++;
        g[k]=q[i];
        if(k>=cnt) cnt++;
    }
    cout <<cnt <<endl;
    return 0;
}

