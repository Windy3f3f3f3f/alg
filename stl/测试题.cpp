/*
我现在需要维护一个队列，队列里每个元素都有一个标号和一个权重，我要求我的队列能执行以下操作

1.能删掉队头元素
2.能加入队尾元素
3.能快速地给定标号，再标号前方插入一个新的元素
4.能快速删掉权重最大的元素（每个元素的权重唯一，因此只有一个权重最大的元素）

*/

#include <iostream>
#include <list>
#include <map>
#include <set>

using namespace std;

struct Element {
    int id;
    int weight;
};

// 自定义比较函数
struct Compare {
    bool operator()(const pair<int, list<Element>::iterator>& lhs,
                    const pair<int, list<Element>::iterator>& rhs) const {
        return lhs.first < rhs.first;
    }
};

list<Element> lst;
map<int, list<Element>::iterator> id_map;
set<pair<int, list<Element>::iterator>, Compare> weight_set;

// 删除队头元素
void pop_front() {
    if (!lst.empty()) {
        auto it = lst.begin();
        id_map.erase(it->id);
        weight_set.erase({it->weight, it});
        lst.pop_front();
    }
}

// 加入队尾元素
void push_back(int id, int weight) {
    lst.push_back({id, weight});
    auto it = --lst.end();
    id_map[id] = it;
    weight_set.insert({weight, it});
}

// 给定标号，在标号前方插入一个新元素
void insert_before(int target_id, int new_id, int new_weight) {
    auto it = id_map.find(target_id);
    if (it != id_map.end()) {
        auto pos = it->second;
        lst.insert(pos, {new_id, new_weight});
        auto new_pos = prev(pos);
        id_map[new_id] = new_pos;
        weight_set.insert({new_weight, new_pos});
    }
}

// 删除权重最大的元素
void erase_max_weight() {
    if (!weight_set.empty()) {
        auto it = prev(weight_set.end()); // 获取最大权重的元素
        auto elem_it = it->second;
        id_map.erase(elem_it->id);
        lst.erase(elem_it);
        weight_set.erase(it); // 删除最大权重的元素
    }
}

// 打印队列中的元素（用于调试）
void print_queue() {
    for (const auto& elem : lst) {
        cout << "ID: " << elem.id << ", Weight: " << elem.weight << endl;
    }
}

int main() {
    push_back(1, 10);
    push_back(2, 20);
    push_back(3, 15);

    cout << "Initial queue:" << endl;
    print_queue();

    cout << "After popping front:" << endl;
    pop_front();
    print_queue();

    cout << "After inserting before ID 3:" << endl;
    insert_before(3, 4, 18);
    print_queue();

    cout << "After erasing max weight:" << endl;
    erase_max_weight();
    print_queue();

    return 0;
}
