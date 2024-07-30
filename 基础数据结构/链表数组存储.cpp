#include<iostream>
using namespace std;
const int N =100010;

///head 表示头节点的下标
///e[i]表示 节点i 的值
///ne[i]表示节点i的下一个节点的下标
///idx[i]存储当前应当分配哪儿个节点
int head,e[N],ne[N],idx;

void init(){
    head = -1;
    idx = 0;
}
///将x插到头节点
void add_to_head(int x){
    e[idx]=x;
    ne[idx]=head;
    head = idx;
    idx++;
}
///将x插到下标是k的点的后面
void add(int k, int x){
    e[idx]=x;
    ne[idx] = ne[k];
    ne[k]=idx;
    idx++;
}

///将下标是k的后面的点删掉
void remove(int k){
    ne[k]=ne[ne[k]];
}

///