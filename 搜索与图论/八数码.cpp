#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
using namespace std;

int bfs(string state)
{
    queue<string> q; //定义队列
    unordered_map<string,int> d; //通过哈希表来让字符串变化时和移动的距离数值关联

    q.push(state); //将字符串入队
    d[state]=0; //将初始状态的字符串的哈希值设定为1

    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1}; //定义四个方向向量

    string end="12345678x"; //定义宽度优先搜素的终止状态
    while(q.size()) //循环终止状态
    {
        auto t=q.front(); //将队列中存着的字符串赋值给t
        q.pop(); //队头元素弹出

        if( t==end ) return d[t]; //如果当前字符串等于终止状态搜索结束返回该字符串对应的哈希值
        //此处的哈希函数值对应于字符串移动的次数
        int distance = d[t]; //定义一个临时变量distance存储形成t字符串当前的移动次数
        int k = t.find('x'); //k表示'x'字符在字符串当前的下标
        int x = k/3,y = k%3; //由于字符串当前是一维的将一维下标转化为二维坐标
        for(int i=0;i<4;i++) //分别遍历四个方向
        {
            int a=x+dx[i],b=y+dy[i]; //将下一个搜索位置的x,y坐标表示
            if(a>=0&&a<3&&b>=0&&b<3) //当二维坐标满足位于3X3矩阵中时
            {
                swap(t[a*3+b],t[k]); //将字符串中的搜索位置与字符'x'交换
                if(!d.count(t)) //如果当前的字符串的哈希值为0
                {
                    d[t]=distance+1; //将该字符串对应的哈希值在原字符串对应的哈希值基础上加1
                    q.push(t); //将该字符串入队
                }
                swap(t[a*3+b],t[k]); //恢复现场，返回位置判断其他方向
            }
        }
    }
    return -1; //如果无法移动到终止位置返回-1
}

int main()
{
    char s[2];

    string state;
    for(int i=0;i<9;i++)
    {
        cin>>s;
        state+=s; //逐个输入字符串
    }

    cout<<bfs(state)<<endl; //输出宽度优先搜索的数值

    return 0;
}
