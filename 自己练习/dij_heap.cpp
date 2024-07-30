//
// Created by Wendy on 2023/11/10.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010;
typedef pair<int, int> PII; //(距离,节点编号)
int n,m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c){
    /*
     * h[N]：头结点数组。对于图中的每一个节点i，h[i]存储的是节点i的出边链表的第一条边的索引。如果h[i]为-1，表示节点i没有出边。
     * e[N]：边的目标节点数组。对于每一条边的索引k，e[k]表示这条边指向的目标节点。
     * w[N]：边的权重数组。对于每一条边的索引k，w[k]表示这条边的权重。
     * ne[N]：链表的下一条边的索引数组。对于每一条边的索引k，ne[k]表示与这条边同起点的下一条边的索引。如果ne[k]为-1，表示这是链表的最后一条边。
     * idx：边的索引计数器。每添加一条边，idx就会递增。它相当于边数组e和w的当前填充位置，同时也是ne数组的下标。
     */
    e[idx] = b; // 设置边的目标节点为b
    w[idx] = c; // 设置边的权重为c
    ne[idx] = h[a]; // 将新边链接到节点a的出边链表
    h[a] = idx; // 更新头结点数组，使得节点a的出边链表的头部是这条新边
    idx++; // 递增边的索引计数器
}

int main(){

}