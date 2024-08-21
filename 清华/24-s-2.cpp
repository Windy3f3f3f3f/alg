#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>
#include <random>

using namespace std;

struct Node {
    int id;
    int weight;
    int depth;
    vector<int> children;
    int parent;
};

vector<Node> tree;
vector<multiset<int>> weights;

void updateWeight(int id) {
    if (tree[id].children.empty()) return;

    int depth = tree[id].depth;
    int oldWeight = tree[id].weight;
    if (depth % 2 == 0) {
        tree[id].weight = *weights[id].rbegin();
    } else {
        tree[id].weight = *weights[id].begin();
    }

    if (tree[id].parent != -1 && oldWeight != tree[id].weight) {
        int parent = tree[id].parent;
        auto it = weights[parent].find(oldWeight);
        if (it != weights[parent].end()) {
            weights[parent].erase(it);
        }
        weights[parent].insert(tree[id].weight);
        updateWeight(parent);
    }
}

void addLeaf(int parent_id, int weight) {
    int id = tree.size();
    tree.push_back({id, weight, tree[parent_id].depth + 1, {}, parent_id});
    tree[parent_id].children.push_back(id);
    
    if (weights.size() <= parent_id) {
        weights.resize(parent_id + 1);
    }
    weights[parent_id].insert(weight);
    weights.push_back(multiset<int>());
    
    updateWeight(parent_id);
}

void modifyLeaf(int id, int new_weight) {
    assert(tree[id].children.empty());
    int parent = tree[id].parent;
    auto it = weights[parent].find(tree[id].weight);
    if (it != weights[parent].end()) {
        weights[parent].erase(it);
    }
    tree[id].weight = new_weight;
    weights[parent].insert(new_weight);
    updateWeight(parent);
}

void printTree(int id = 0, string prefix = "", bool isLast = true) {
    cout << prefix;
    cout << (isLast ? "└── " : "├── ");
    cout << id << "(" << tree[id].weight << ")" << endl;

    for (size_t i = 0; i < tree[id].children.size(); ++i) {
        printTree(tree[id].children[i], 
                  prefix + (isLast ? "    " : "│   "), 
                  i == tree[id].children.size() - 1);
    }
}

void runTestCases() {
    // 初始化根节点
    int root_weight = 10;
    tree.clear();
    weights.clear();
    tree.push_back({0, root_weight, 0, {}, -1});
    weights.push_back(multiset<int>());

    cout << "初始状态:" << endl;
    printTree();
    cout << endl;

    // 测试用例1: 基本操作
    addLeaf(0, 5);
    assert(tree[0].weight == 5);
    cout << "测试1通过: 添加叶子节点 (5) 到根节点" << endl;
    printTree();
    cout << endl;

    addLeaf(0, 3);
    assert(tree[0].weight == 5);
    cout << "测试2通过: 添加另一个叶子节点 (3) 到根节点" << endl;
    printTree();
    cout << endl;

    modifyLeaf(1, 6);
    assert(tree[0].weight == 6);
    cout << "测试3通过: 修改叶子节点 1 的权重为 6" << endl;
    printTree();
    cout << endl;

    // 测试用例2: 多层树结构
    addLeaf(1, 2);
    assert(tree[0].weight == 3 && tree[1].weight == 2);
    cout << "测试4通过: 添加叶子节点 (2) 到节点 1" << endl;
    printTree();
    cout << endl;

    addLeaf(2, 8);
    assert(tree[0].weight == 8 && tree[2].weight == 8);
    cout << "测试5通过: 添加叶子节点 (8) 到节点 2" << endl;
    printTree();
    cout << endl;

    modifyLeaf(4, 1);
    assert(tree[0].weight == 2 && tree[2].weight == 1);
    cout << "测试6通过: 修改叶子节点 4 的权重为 1" << endl;
    printTree();
    cout << endl;

    // 测试用例3: 边界情况
    addLeaf(0, 0);
    assert(tree[0].weight == 2);
    cout << "测试7通过: 添加权重为 0 的叶子节点到根节点" << endl;
    printTree();
    cout << endl;

    modifyLeaf(5, 1000);
    assert(tree[0].weight == 1000);
    cout << "测试8通过: 修改叶子节点权重为很大的值" << endl;
    printTree();
    cout << endl;

    // 测试用例4: 复杂树结构
    addLeaf(3, 4);
    addLeaf(3, 1);
    assert(tree[1].weight == 4 && tree[0].weight == 1000);
    cout << "测试9通过: 向节点 3 添加多个子节点" << endl;
    printTree();
    cout << endl;

    modifyLeaf(6, 3);
    assert(tree[1].weight == 3 && tree[0].weight == 1000);
    cout << "测试10通过: 修改深层叶子节点的权重" << endl;
    printTree();
    cout << endl;

    // 测试用例5: 随机测试
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < 20; ++i) {
        int parent = dis(gen) % tree.size();
        int weight = dis(gen);
        addLeaf(parent, weight);
    }

    cout << "测试11通过: 随机添加 20 个节点" << endl;
    printTree();
    cout << endl;

    for (int i = 0; i < 10; ++i) {
        int leaf = dis(gen) % tree.size();
        while (!tree[leaf].children.empty()) {
            leaf = dis(gen) % tree.size();
        }
        int weight = dis(gen);
        modifyLeaf(leaf, weight);
    }

    cout << "测试12通过: 随机修改 10 个叶子节点的权重" << endl;
    printTree();
    cout << endl;

    // 新增测试用例：测试重复权重
    addLeaf(0, 2);
    addLeaf(0, 2);
    assert(tree[0].weight == 1000);
    cout << "测试13通过: 添加重复权重的叶子节点" << endl;
    printTree();
    cout << endl;

    cout << "所有测试用例通过!" << endl;
}

int main() {
    runTestCases();
    return 0;
}
