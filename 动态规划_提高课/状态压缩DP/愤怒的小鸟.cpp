#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
typedef pair<double, double> PDD;

const int N = 18, M = 1<<18;
const double eps = 1e-8;

int n,m;
PDD q[N];
int path[N][N];
int f[M];

int cmp(double x, double y){
    if(fabs(x-y)<eps) return 0;
    else if(x<y) return -1;
    else return 1;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>q[i].x>>q[i].y;
        }
        memset(path, 0, sizeof path); 
        
        //得到所有的线 经过哪儿些点 <--> 哪儿些行里对应哪儿些列是1
        for(int i=0;i<n;i++){
            path[i][i] = 1 <<i;//自己自己的线，不妨定义为经过自己
            for(int j=0;j<n;j++){
                double x1 = q[i].x, y1 = q[i].y;
                double x2 = q[j].x, y2 = q[j].y;
                if(!cmp(x1,x2)) continue;
                double a = (y1/x1-y2/x2)/(x1-x2);
                double b = y1/x1-a*x1;
                if(cmp(a,0)>=0) continue;
                int state = 0;
                for(int k=0;k<n;k++){
                    double x = q[k].x, y=q[k].y;
                    if(!cmp(a*x*x+b*x, y)) state+=1<<k;
                }
                path[i][j] = state;
            }
        }
        memset(f, 0x3f, sizeof f);// f[i]表示当前已经覆盖的列是i时的最小行数
        f[0] = 0;
        for(int i=0;i<(1<<n)-1;i++){//求出每一个f，最后要求到f[(i<<n)-1]
            int x=0;
            for(int j=0;j<n;j++){
                if(!(i>>j&1)){ //找出某一个没被覆盖的列
                    x=j;
                    break;
                }
            }
            //x是某一个没有被覆盖的列
            for(int j=0;j<n;j++)
                //枚举所有能覆盖列x的抛物线，更新一下他
                f[i|path[x][j]] = min(f[i|path[x][j]], f[i]+1);
        }
        cout<<f[(1<<n)-1]<<endl;
    }
    return 0;
}
