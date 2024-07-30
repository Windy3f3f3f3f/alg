//#include <iostream>
//#include <cstring>
//#include <unordered_map>
//#include <queue>
//
//using namespace std;
//int main(){
//    char s[2];
//    string x;
//    for(int i=0;i<9;i++){
//        cin>>s;
//        x+=*s;
//    }
//    int dx[] = {0,0,1,-1},dy[] = {1,-1,0,0};
//    unordered_map<string, int> map;
//    unordered_map<string,int> dis;
//    string obj = "12345678x";
//    queue<string> q;
//    dis[x]=0;
//    q.push(x);
//    while(!q.empty()){
//        string f = q.front();
//        q.pop();
//        int idx = f.find('x');
//        int x_idx = idx /3 , y_idx = idx %3;
//        for(int i=0;i<4;i++){
//            int to_x = x_idx + dx[i], to_y = y_idx + dy[i];
//            if(to_x>=0&&to_x<=2&&to_y>=0&&to_y<=2){
//                if(f==obj){
//                    //todo
//                    printf("%d",dis[f]+1);
//                    return 0;
//                }
//                else if(dis.count(f)>0){
//                    //剪枝掉了
//                }
//                else {
//                    int new_idx = to_x*3+to_y;
//                    int dis_old = dis[f];
//                    swap(f[idx],f[new_idx]);
//                    q.push(f);
//                    dis[f] = dis_old+1;
//                    swap(f[idx],f[new_idx]);
//                }
//            }
//        }
//    }
//}
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <queue>

using namespace std;
int main(){
    char s[2];
    string x;
    for(int i=0;i<9;i++){
        cin>>s;
        x+=*s;
    }
    int dx[] = {0,0,1,-1},dy[] = {1,-1,0,0};
    unordered_map<string,int> dis;
    string obj = "12345678x";
    queue<string> q;
    dis[x]=0;
    q.push(x);
    while(!q.empty()){
        string f = q.front();
        q.pop();

        // 先检查是否已经找到目标
        if(f == obj) {
            printf("%d", dis[f]);
            return 0;
        }

        int idx = f.find('x');
        int x_idx = idx /3 , y_idx = idx %3;
        for(int i=0;i<4;i++){
            int to_x = x_idx + dx[i], to_y = y_idx + dy[i];
            if(to_x >= 0 && to_x <= 2 && to_y >= 0 && to_y <= 2) {
                int new_idx = to_x * 3 + to_y;
                swap(f[idx], f[new_idx]);

                // 在这里做剪枝
                if (dis.count(f) == 0) {
                    dis[f] = dis[q.front()] + 1;
                    q.push(f);
                }

                // 恢复字符串状态
                swap(f[idx], f[new_idx]);
            }
        }
    }
    return 0;  // 没有找到解
}
