#include<iostream>
using namespace std;
const int N =100010;

int m;
int e[N],l[N],r[N],idx;
///初始化 不妨定义0号点为head，1号点为tail，head and tail 不存储内容
void init(){

}
///在下标为k的右边插入 x
void add(int k,int x){
    e[idx]=x;
    r[idx]=r[k];
    l[idx]=k;
    l[r[k]]=idx;
    r[k]=idx;
    idx++;
}

///删除第k个点
void remove(int k){
    r[l[k]]=r[k];
    l[r[k]]=l[k];
}