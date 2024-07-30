#include <iostream>
using namespace std;
const int N = 1e5+10;
int tr[N], n;
int a[N];
int answer[N];
int lowbit(int x){
    return x & -x;
}
void add(int x, int y){
    for(int i=x;i<=n;i+=lowbit(i)){
        tr[i]+=y;
    }
}
int sum(int x){
    int res = 0;
    for(int i=x;i;i-=lowbit(i)){
        res+=tr[i];
    }
    return res;
}

int main(){
    cin>>n;
    for(int i=2; i<=n; i++) cin>>a[i];//表示第i头牛前有a[i]头牛比他低
    for(int i=1;i<=n;i++) tr[i] = lowbit(i);

    for(int i=n;i;i--){
        // int l=1, r=n;
        // int mid;
        // while(l<r){
        //     mid = l+r+1 >> 1;
        //     int num = sum(mid);
        //     if(num<=a[i]+1){
        //         l=mid; //l=mid，没有+1，因此mid要+1
        //     }else{
        //         r=mid-1;
        //     }
        // }
        int l=1, r=n;
        int mid;
        while(l<r){
            mid = l+r >> 1;
            int num = sum(mid);
            if(num>=a[i]+1){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        add(l,-1);
        answer[i]=l;
    }
    for(int i=1;i<=n;i++){
        cout<<answer[i]<<endl;
    }    
    return 0;
}
