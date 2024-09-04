#include <bits/stdc++.h>
using namespace std;

typedef struct Node_ {
    int key;
    int val;
} Node_;
const int N = 100;

Node_ arr[N]={{1,1},{2,2},{3,3},{3,4},{4,4},{4,5}};


bool check(int mid){
    return arr[mid].key>=3;
}
int main(){

    int l=0, r=5;
    while(l<r){
        int mid = l+r>>1;
        if(arr[mid].key>=3) r=mid;
        else l=mid+1;
    }
    cout<<arr[l].key<<" "<<arr[l].val<<endl;

    l=0, r=5;
    while(l<r){
        int mid = l+r+1 >> 1;
        if(arr[mid].key<=3) l=mid;
        else r=mid-1;
    }
    cout<<arr[l].key<<" "<<arr[l].val<<endl;


}
