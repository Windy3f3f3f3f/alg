//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int N = 100010;
//int arr[N];
//
//void quick_sort(int l,int r){
//    if(l>=r){
//        return;
//    }
//    int x=arr[(l+r)>>1];
//    int i=l,k=r;
//    l=l-1;
//    r=r+1;
//    while(l<r){
//        while(arr[++l]<x);
//        while(arr[--r]>x);
//        if(l<r){
//            swap(arr[l],arr[r]);
//        }
//    }
//    quick_sort(i,r);
//    quick_sort(r+1,k);
//}
//
//int main(){
//    int n;
//    cin>>n;
//    for(int i=0;i<n;i++){
//        scanf("%d",&arr[i]);
//    }
//    quick_sort(0,n-1);
//    for(int i=0;i<n;i++){
//        printf("%d ",arr[i]);
//    }
//}

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int n;
int q[N];
void quick_sort(int l,int r){
    if(l>=r){
        return;
    }
    int i = l-1, j=r+1;
    int x = q[(i+j)>>1];
    while(i<j) {
        while (q[++i] < x);
        while (q[--j] > x);
        if (i < j) {
            swap(q[i], q[j]);
        }
    }
    quick_sort(l,j);
    quick_sort(j+1,r);
}
int main(){

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&q[i]);
    }
    quick_sort(0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",q[i]);
    }

}