#include <bits/stdc++.h>
using namespace std;

#define x first 
#define y second 
typedef pair<int, int> PII;

const int N = 1e3+10;
// int arr[N][N];
map<int, char> arr_x[N]; //下
map<int, char> arr_y[N]; //右
map<int, char> arr_x_y[2*N]; //方向为右下的一条直线，数组下标对应截距，同时为了防止截距负数，计算方法为y-x+n
map<int, char> arr_x_not_y[2*N]; //方向为左下的一条直线，数组下标为截距，计算公式为 x+y
int n,m,q;

map<char, vector<PII>> all_actions; // 存一下不同类型的飞镖的移动方向
void init_actions(){
    all_actions['+'] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    all_actions['x'] = {{-1,-1}, {1,-1}, {-1,1}, {1,1}};
    all_actions['*'] = {{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {1,-1}, {-1,1}, {1,1}};
}

void set_x_y(int x, int y, char t){//把所有的树中的x,y位置的值都设置为t
    //x,y
    arr_x[x][y] = t;
    arr_y[y][x] = t;
    arr_x_y[y-x+n][x] = t;
    arr_x_not_y[x+y][x] = t;
}

void delete_x_y(int x, int y){//删掉所有树中的x,y位置的值
    arr_x[x].erase(y);
    arr_y[y].erase(x);
    arr_x_y[y-x+n].erase(x);
    arr_x_not_y[x+y].erase(x);
}


int get_min_time(int x, int y, const PII& action) {
    // 到边界或者到某个元素的距离
    if (x < 1 || x > n || y < 1 || y > m) {
        return 0; // 起始点已经在边界外
    }
    int min_time = INT_MAX;
    if(action.x==0 && action.y>0){
        //只有y方向移动，找到最近的边界 arr_x 里找到
        auto it = arr_x[x].upper_bound(y);//第x行中是否存在一个 第一个大于y的
        if(it!=arr_x[x].end()){
            min_time = min(min_time, (it->first-y));}
        else{
            min_time = min(min_time, m-y+1);//没有的话，就是到边界
        }
    }
    else if(action.x ==0 && action.y<0){
        auto it = arr_x[x].find(y);//找到等于y的
        if(it!=arr_x[x].begin()){//如果不是第一个，那么就找到前一个（这一个是小于y的）
            it = prev(it);
            min_time = min(min_time, (y-it->first));
        }else{
            min_time = min(min_time, y);
        }
    }
    else if(action.x > 0 && action.y == 0){
        auto it = arr_y[y].upper_bound(x);
        if(it!=arr_y[y].end()){
            min_time = min(min_time, (it->first-x));
        }else{
            min_time = min(min_time, n-x+1);
        }
    }
    else if(action.x < 0 && action.y == 0) {
        auto it = arr_y[y].find(x);
        if (it != arr_y[y].begin()) {
            it = prev(it);
            min_time = min(min_time, (x - it->first));
        } else {
            min_time = min(min_time, x);
        }
    }
    else if(action.x>0 && action.y>0){
        auto it = arr_x_y[y-x+n].upper_bound(x);
        if(it!=arr_x_y[y-x+n].end()){
            min_time = min(min_time, (it->first-x));
        }else{
            min_time = min(min_time, min(n-x+1, m-y+1));
        }
    }
    else if(action.x<0 && action.y<0){
        auto it = arr_x_y[y-x+n].find(x);
        if(it!=arr_x_y[y-x+n].begin()){
            it = prev(it);
            min_time = min(min_time, (x-it->first));
        }else{
            min_time = min(min_time, min(x,y));
        }
    }
    else if(action.x>0 && action.y<0){
        auto it = arr_x_not_y[x+y].upper_bound(x);
        if(it!=arr_x_not_y[x+y].end()){
            min_time = min(min_time, (it->first-x));
        }else{
            min_time = min(min_time, min(n-x+1, y));
        }
    }
    else if(action.x<0 && action.y>0){
        auto it = arr_x_not_y[x+y].find(x);
        if(it!=arr_x_not_y[x+y].begin()){
            it = prev(it);
            min_time = min(min_time, (x-it->first));
        }else{
            min_time = min(min_time, min(x, m-y+1));
        }
    }
    return min_time;
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
        // if(arr[x][y]!=0){
        //     printf("%c ",arr[x][y]);
        // }else{
        //     printf(". ");
        // }
        if(arr_x[x].find(y)!=arr_x[x].end()){
            //如果存在
            printf("%c ", arr_x[x][y]);
        }else{
            printf(". ");
        }
        // arr[x][y]=t;
        set_x_y(x,y,t);
        vector<PII> actions = all_actions[t];
        // bool flag = false;
        // while(!flag){
        //     time++;
        //     for(auto action: actions){
        //         int new_x, new_y;
        //         new_x = x+action.x * time;
        //         new_y = y+action.y * time;
        //         if(new_x<1 || new_x>n || new_y<1||new_y>m || arr[new_x][new_y]!=0){
        //             //如果出界，或者碰到有东西的地方，则应该停下。
        //             flag=true; break;
        //         }
        //     }
        // }
        //在各个方向上找离他最近的边界，求出所画的距离/时间
        int min_time = 1e9;
        for (auto action: actions){
            min_time = min(min_time, get_min_time(x, y, action));
        }
        int time = min_time;
        //输出时间
        printf("%d ",time);
        //此时超出边界或者发生了碰撞
        for(auto action: actions){
            int new_x, new_y;
            new_x = x+action.x * time;
            new_y = y+action.y * time;
            if(new_x<1 || new_x>n || new_y<1||new_y>m ){//出界，输出o
                printf("o");
            }
            // else if(arr[new_x][new_y]!=0){//没出界，且有东西，输出原来的东西，清楚该地点
            //     printf("%c",arr[new_x][new_y]);
            //     arr[new_x][new_y] = 0;
            // }
            else if (arr_x[new_x].find(new_y)!=arr_x[new_x].end()){
                printf("%c", arr_x[new_x][new_y]);
                delete_x_y(new_x, new_y);//从所有涉及的树中删除这个节点
            }
            // else{//如果该小飞镖未碰撞也未出界则输出 .  并标记
            //     printf(".");
            //     arr[new_x][new_y] = t;
            // }
            else{
                printf(".");
                set_x_y(new_x, new_y, t);//在所有涉及的树中添加这个节点
            }
        }
        printf("\n");
    }
}
