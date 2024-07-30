#include<iostream>
using namespace std;


int main(){
    int n,m,q;
    cin>>n>>m>>q;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    long long sum[n][m];
    sum[0][0]=arr[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0&&j!=0){
                sum[0][j]=sum[0][j-1]+arr[0][j];
            }
            else if(j==0&&i!=0){
                sum[i][0]=sum[i-1][0]+arr[i][0];
            }
            else if(i!=0&&j!=0)
                sum[i][j]=sum[i-1][j]-sum[i-1][j-1]+sum[i][j-1]+arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",sum[i][j]);
        }
        cout<<endl;
    }
    for(int z=0;z<q;z++){
        int i,j,x,y;
        cin>>i>>j>>x>>y;
        i--; j--; x--; y--;  // Adjust for 0-indexing
        long long s = sum[x][y];
        if(i > 0) s -= sum[i-1][y];
        if(j > 0) s -= sum[x][j-1];
        if(i > 0 && j > 0) s += sum[i-1][j-1];
        cout<<s<<endl;
    }
}