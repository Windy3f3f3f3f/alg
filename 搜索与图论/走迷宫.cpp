#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII; // 定义一个类型别名，表示一个由两个整数构成的对

const int N = 110; // 定义迷宫大小的最大值

int n,m; // n和m分别表示迷宫的行数和列数
int g[N][N]; // g数组用于存储迷宫的信息，0表示通路，1表示墙壁
int d[N][N]; // d数组用于存储从起点到每一个位置的最短距离
PII q[N*N]; // q数组是一个队列，用于存储待处理的点
PII Prev[N][N]; // Prev数组用于存储每一个位置是从哪个位置来的，即记录路径信息

int bfs() { // 广度优先搜索的主函数
    int hh = 0, tt = 0; // hh和tt分别表示队列的头和尾
    q[0] = {0, 0}; // 初始时，把起点（0，0）加入队列
    memset(d, -1, sizeof d); // 初始化d数组，全部填充为-1，表示所有的位置都还没有被访问过
    d[0][0]=0; // 起点到自身的距离是0
    int dx[4] = {-1,0,1,0}, dy[4]={0,1,0,-1}; // dx和dy数组用于表示四个方向的移动
    while(hh<=tt){ // 当队列不为空时
        auto t = q[hh++]; // 取出队列的头部元素
        for(int i=0;i<4;i++){ // 尝试向四个方向移动
            int x=t.first+dx[i],y=t.second+dy[i]; // 得到移动后的位置
            if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]==0&&d[x][y]==-1){ // 如果这个位置在迷宫内，并且不是墙壁，并且没有被访问过
                d[x][y]=d[t.first][t.second]+1; // 更新距离，新位置的距离等于原位置的距离+1
                Prev[x][y]=t; // 记录新位置是从哪个位置来的
                q[++tt]={x,y}; // 将新位置加入队列
            }
        }
    }
    int x=n-1,y=m-1; // 从终点开始
    while(x||y){ // 当还没有到达起点时
        cout<<x<<' '<<y<<endl; // 输出当前位置
        auto t=Prev[x][y]; // 得到当前位置是从哪个位置来的
        x = t.first; // 更新x和y
        y = t.second;
    }

    return d[n-1][m-1]; // 返回起点到终点的最短距离
}

int main(){
    cin>>n>>m; // 读入行数和列数
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j]; // 读入迷宫的信息
        }
    }

    cout<<bfs()<<endl; // 输出起点到终点的最短距离
}
