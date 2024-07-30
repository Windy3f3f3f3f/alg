#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct Element {
    int id;
    int weight;
};

// 自定义比较函数
struct Compare {
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
        return lhs.first < rhs.first;
    }
};

vector<Element> vec;
map<int, int> id_map; // id到索引的映射
set<pair<int, int>, Compare> weight_set; // 权重到索引的映射

// 删除队头元素
void pop_front() {
    if (!vec.empty()) {
        auto it = vec.begin();
        int index = 0;
        id_map.erase(it->id);
        weight_set.erase({it->weight, index});
        vec.erase(it);

        // 更新所有受影响的索引
        for (auto& entry : id_map) {
            if (entry.second > index) {
                entry.second--;
            }
        }

        set<pair<int, int>, Compare> new_weight_set;
        for (const auto& entry : weight_set) {
            if (entry.second > index) {
                new_weight_set.insert({entry.first, entry.second - 1});
            } else {
                new_weight_set.insert(entry);
            }
        }
        weight_set = new_weight_set;
    }
}

// 加入队尾元素
void push_back(int id, int weight) {
    vec.push_back({id, weight});
    int index = vec.size() - 1;
    id_map[id] = index;
    weight_set.insert({weight, index});
}

// 给定标号，在标号前方插入一个新元素
void insert_before(int target_id, int new_id, int new_weight) {
    auto it = id_map.find(target_id);
    if (it != id_map.end()) {
        int index = it->second;
        vec.insert(vec.begin() + index, {new_id, new_weight});
        id_map[new_id] = index;
        weight_set.insert({new_weight, index});

        // 更新所有受影响的索引
        for (auto& entry : id_map) {
            if (entry.second >= index && entry.first != new_id) {
                entry.second++;
            }
        }

        set<pair<int, int>, Compare> new_weight_set;
        for (const auto& entry : weight_set) {
            if (entry.second >= index && entry.first != new_weight) {
                new_weight_set.insert({entry.first, entry.second + 1});
            } else {
                new_weight_set.insert(entry);
            }
        }
        weight_set = new_weight_set;
    }
}

// 删除权重最大的元素
void erase_max_weight() {
    if (!weight_set.empty()) {
        auto it = prev(weight_set.end()); // 获取最大权重的元素
        int index = it->second;
        id_map.erase(vec[index].id);
        vec.erase(vec.begin() + index);
        weight_set.erase(it); // 删除最大权重的元素

        // 更新所有受影响的索引
        for (auto& entry : id_map) {
            if (entry.second > index) {
                entry.second--;
            }
        }

        set<pair<int, int>, Compare> new_weight_set;
        for (const auto& entry : weight_set) {
            if (entry.second > index) {
                new_weight_set.insert({entry.first, entry.second - 1});
            } else {
                new_weight_set.insert(entry);
            }
        }
        weight_set = new_weight_set;
    }
}

// 打印队列中的元素（用于调试）
void print_queue() {
    for (const auto& elem : vec) {
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
