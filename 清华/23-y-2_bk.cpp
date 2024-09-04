#include <bits/stdc++.h>
using namespace std;

#define x first 
#define y second 
typedef pair<int, int> PII;

const int N = 1e3+10; //这里开不到1e5，因为1e5*1e5太大，爆内存。这题的部分分是1000，这里拿部分分
int arr[N][N];//这是飞镖地图
int n,m,q;

map<char, vector<PII>> all_actions;//存一下不同类型的飞镖的移动方向，不一定要用map
void init_actions(){
    all_actions['+'] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    all_actions['x'] = {{-1,-1}, {1,-1}, {-1,1}, {1,1}};
    all_actions['*'] = {{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {1,-1}, {-1,1}, {1,1}};
}

int main(){
    init_actions();
    cin>>n>>m>>q;
    while(q--){
        int x,y;
        char tmp[3];
        char t;
        scanf("%d%d%s",&x,&y,tmp); //有坑，如果%c读，会读到空格我去
        t = tmp[0];

        // 如果该飞镖覆盖了投掷位置 的原有标记，则输出原有的标记字符，否则输出 . ；
        if(arr[x][y]!=0){
            printf("%c ",arr[x][y]);
        }else{
            printf(". ");
        }
        arr[x][y]=t;
        
        vector<PII> actions = all_actions[t];// 当前飞镖类型的移动方向

        //找到最早碰撞/出界的时间（也就是移动的最大距离）
        int time = 0;
        bool flag = false;
        while(!flag){
            time++;
            for(auto action: actions){
                int new_x, new_y;
                new_x = x+action.x * time;
                new_y = y+action.y * time;
                if(new_x<1 || new_x>n || new_y<1||new_y>m || arr[new_x][new_y]!=0){
                    //如果出界，或者碰到有东西的地方，则应该停下。
                    flag=true; break;
                }
            }
        }
        //输出时间
        printf("%d ",time);
        //此时超出边界或者发生了碰撞，看一个此时分出的各个方向的飞镖的情况
        for(auto action: actions){
            int new_x, new_y;
            new_x = x+action.x * time;
            new_y = y+action.y * time;
            if(new_x<1 || new_x>n || new_y<1||new_y>m ){//出界，输出o
                printf("o");
            }
            else if(arr[new_x][new_y]!=0){//没出界，且有东西，输出原来的东西，清除该地点
                printf("%c",arr[new_x][new_y]);
                arr[new_x][new_y] = 0;
            }
            else{//如果该小飞镖未碰撞也未出界则输出 .  并标记
                printf(".");
                arr[new_x][new_y] = t;
            }
        }
        printf("\n");
    }
}
