#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
#define x first
#define y second
typedef pair<double, double> PII;
const int N = 160;
PII coord[N];

int g[N][N];

double INF = 1e200;
double dist[N][N];
double gd[N][N];
double startD[N];

int n;
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            gd[i][j] = INF;
        }
    }
}
double get_dist(int i, int j){
    int xi = coord[i].x, yi = coord[i].y;
    int xj = coord[j].x, yj = coord[j].y;
    return sqrt(abs(xi-xj)*abs(xi-xj)+abs(yi-yj)*abs(yi-yj));
}

int main(){
    init();
    // cin>>n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        coord[i].x = a, coord[i].y = b;
    }

    for(int i=0;i<n;i++){
        char tmp[N+3];
        scanf("%s",tmp);
        for(int j=0;j<n;j++){
            g[i][j] = tmp[j]-'0';
            // 预处理出距离
            if(i==j){
                dist[i][j] = 0;
            }
            else if(g[i][j]==1){
                dist[i][j] = get_dist(i,j);
            }
            else{
                dist[i][j] = INF;
            }
        }
    }
    // - 先用floyd求出任意两点之间的最短距离
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    // - 就可以求出以某个节点为起点的最远路
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]<INF/2){
                startD[i] = max(startD[i],dist[i][j]);
            }
        }
    }
    // - 进而可以求出连通块的最大直径
    double maxBlock = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]<INF/2){
                maxBlock = max(maxBlock, dist[i][j]);
            }
        }
    }

    // - 接着求枚举连边之后的结果
    //     - 挑什么样的边？INF
    //     - min(maxd[i] + dist[i,j] + maxd[j])
    double minAcross = INF;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]>INF/2){
                minAcross = min(minAcross, startD[i]+startD[j]+get_dist(i,j));
            }
        }
    }
    
    printf("%lf",max(maxBlock,minAcross));
    return 0;
}
