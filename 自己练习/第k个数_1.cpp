//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//const int N = 1e5+10;
//int a[N];
//int find_k(int l,int r,int s){
//    if(r-l+1<=1&&s==1){
//        return a[l];
//    }
//    int i=l-1,j=r+1;
//    int p = a[l];
//    while(i<j){
//        while(a[++i]<p);
//        while(a[--j]>p);
//        if(i<j){
//            swap(a[i],a[j]);
//        }
//    }
//    int sl = j-l+1;
//    if(s<=sl){
//        return find_k(l,j,s);
//    }
//    else{
//        return find_k(j+1,r,s-sl);
//    }
//}
//
//
//int main(){
//    int n,k;
//    cin>>n>>k;
//    for(int i=0;i<n;i++){
//        scanf("%d",&a[i]);
//    }
//    int x = find_k(0,n-1,k);
//    printf("%d",x);
//}

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100000+10;
int q[N];

int quick_find(int l,int r, int k){
    if(l==r)
        return q[l];
    int i=l-1,j=r+1;
    int x = q[i+j>>1];
    while(i<j){
        while(q[++i]<x);
        while(q[--j]>x);
        if(i<j){
            swap(q[i],q[j]);
        }
    }
    int sl=j-l+1;
    if(k<=sl) return quick_find(l,j,k);
    else return quick_find(j+1,r,k-sl);




}


int main(){
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    for(int i=0;i<n;i++) cin>>q[i];
    cout<<quick_find(0,n-1,k)<<endl;
    return 0;
}
