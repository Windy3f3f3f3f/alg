#include<iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;
/*
 * vector 变长数组
 * pair<类型1,类型2> 序偶，比较也是按字典序比，即first是第一关键字，second是第二关键字
 * string 字符串 substr(), C_str()
 * queue push(),front(),pop()
 * priority_queue(堆) push(),top(),pop()
 * stack push() pop() top()
 * deque 双端队列，队头队尾都可以插入删除，支持随机访问
 * set,map,multiset,multimap 基于平衡二叉树（红黑树）实现，动态维护有序序列
 * unordered_set,unordered_map,unordered_multiset,unordered_multimap 基于哈希表实现
 * bitset 压位
 */

void about_vector(){
    vector<int> a(10,0);
    a.size();//元素个数 O(1)
    a.empty();// bool
    a.clear();//
}

void about_pair(){
    pair<int,string>p;
    p=make_pair(10,"yxc");
    p={20,"abc"};
    //如果想存三个属性也行
    pair<int,pair<string,string>>;
}

void about_string(){
    //size()
    //empty()
    //clear()
    string a="yxc";
    a+="def";
    a+='c';
    //substr()返回子串，第一个参数是以0开始的起始位置，第二个参数是长度
    //如果第二个参数省略，则返回从1开始的子串
    cout<<a.substr(1,2)<<endl;//返回xc

    //c_str()返回字符串的起始地址
    printf("%s\n",a.c_str());
}

void about_queue(){
    /*
     * size()
     * empty()
     * push()
     * front()
     * back()
     * pop()
     * 没有clear函数
     */
    queue<int> q;
    q=queue<int>();

}

void about_priority_queue(){
    /*
     * 定义时默认大根堆，如果想要小的呢？直接将数字前面加一个负号，或者定义小根堆
     * push()插入一个元素
     * top()返回堆顶元素
     * pop()弹出堆顶元素
     */
    priority_queue<int> heap;
    heap = priority_queue<int>();
    priority_queue<int,vector<int>,greater<int>> heap2;//这样子定义的就是小根堆
}

void about_stack(){
    /*
     * size()
     * empty()
     * push()向栈顶插入一个元素
     * top()返回栈顶元素
     * pop()弹出栈顶元素
     */
}

void about_deque(){
    /*
     * 效率很低，比一般的数组慢好几倍
     * size()
     * empty()
     * clear()
     * front()
     * back()
     * push_back()/pop_back()
     * push_front()/pop_front()
     * 随机寻址 []
     * begin()/end()迭代器
     */
}

void about_set(){
    /*
     * size()
     * empty()
     * clear()
     * insert() 插入一个数 logn
     * find() 查找一个数 logn 不存在的时候返回and迭代器
     * count() 返回某个数的个数 logn
     * erase()
     *  (1) 输入是一个数，删除所有等于这个数的节点 O(k+logn)
     *  (2) 输入是一个迭代器，删除这个迭代器
     * lower_bound()/upper_bound()
     *  lower_bound()返回大于等于x的最小的数的迭代器
     *  upper_bound()返回大于x的最小的数的迭代器
     */

    set<int> S;
    multiset<int> MS;
    //区别在于是否可以有重复元素
}

void about_map(){
    /*
     * ++ --都是log n
     * insert()  插入的数是一个pair
     * erase()  erase的东西是一个pair或者迭代器
     * find()
     * [] 特别牛逼，像用数组一样用map，时间复杂度是logn
     * lower_bound()/upper_bound()
     */
    map<string,int> a;
    a["yxc"]=1;//插入
    cout<<a["yxc"]<<endl;
}

void about_unordered(){
    //不支持bound、不支持++ --
    //但是增删改查时间复杂度都是O(1)
}

void about_bitset(){
    //压位，bool默认是用一个B来存，而如果用压位，则只需要一个bit来存
    //可以省8倍空间
    bitset<10000> s;
    // ~ 取反, & 与, | 或, ^ 异或, ==, !=
    // []取出某一位，count() 返回有多少个1
    // any/none() any返回是否至少有一个1，none返回是否全为空
    // set()把所有位置成1
    // set(k,v) 将第k位置成v
    // reset() 把所有位变成0
    // flip() 等价于 ~  ;  flip(k) 把第k位取反
}
int main(){


}