////
//// Created by Wendy on 2023/7/24.
////
//
//#include <iostream>
//using namespace std;
//const int N = 1000010;
//int n;
//int q[N],tmp[N];
//
//void merge_sort(int q[],int l,int r){
//    if(l>=r) return;
//    int mid=l+r>>1;
//    merge_sort(q,l,mid),merge_sort(q,mid+1,r);
//    int k=0,i=l,j=mid+1;
//    while(i<=mid&&j<=r){
//        if(q[i]<=q[j]){
//            tmp[k++]=q[i++];
//        }
//        else{
//            tmp[k++]=q[j++];
//        }
//    }
//    while(i<=mid) tmp[k++]=q[i++];
//    while(j<=r) tmp[k++]=q[j++];
//    for(int i=l,j=0;i<=r;i++,j++){
//        q[i]=tmp[j];
//    }
//}
//int main(){
//    scanf("%d",&n);
//    for(int i=0;i<n;i++) scanf("%d",&q[i]);
//    merge_sort(q,0,n-1);
//    for(int i=0;i<n;i++) printf("%d ",q[i]);
//}

#include <iostream>
using namespace std;
const int N = 100010;
int a[N],tmp[N];
int n;
void merge_sort(int l,int r){
    if(l>=r) return;
    int mid = l+r>>1;
    merge_sort(l,mid), merge_sort(mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(a[i]<a[j]){
          tmp[k++]=a[i++];
        }
        else{
            tmp[k++]=a[j++];
        }
    }
    while(i<=mid){
        tmp[k++]=a[i++];
    }
    while(j<=r){
        tmp[k++]=a[j++];
    }
    for(int i=l,k=0;i<=r;i++,k++){
        a[i]=tmp[k];
    }



}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    merge_sort(0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

}


