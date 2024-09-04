/*
从2023考研机试T2拓展的：（其实这题就是考 双向链表、平衡树的使用），又是一道模拟+数据结构
对了，这道题也是今年机考模拟的T3，我当时就是考场做不出来晚上速度学的STL😭
这个程序实现了一个高效的双向链表数据结构，具有以下特点：

1. 元素特性：
   - 每个元素都有唯一的ID和一个权重值
   - 支持快速按ID查找和按权重排序

2. 核心操作：
   - 在队列的头部和尾部进行插入和删除
   - 在指定元素之前或之后插入新元素
   - 根据ID查找和删除元素
   - 删除权重最大或最小的元素（支持删除所有相同权重的元素）

3. 高级功能：
   - 范围查询：查找指定权重范围内的所有元素
   - 范围删除：删除指定权重范围内的所有元素
   - 获取队列中的最大和最小权重值

4. 性能优化：
   - 使用双向链表实现O(1)时间复杂度的插入和删除
   - 利用multiset维护元素权重，支持O(log n)时间复杂度的权重相关操作
   - 使用哈希表实现平均O(1)时间复杂度的ID查找

这个数据结构适用于需要频繁插入、删除、和基于权重查询的场景，如任务调度系统、缓存管理等。
*/

#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <limits>
using namespace std;

const int N = 100010;

struct Element {
    int id;     // 元素的唯一标识符
    int weight; // 元素的权重
};

int head, tail, idx;
Element e[N];
int l[N], r[N];
multiset<pair<int, int>> weight_set;  // pair<weight, idx>
unordered_map<int, int> id_to_idx;
const int INT_MAX = 0x3f3f3f3f;

// 初始化队列
void __init() {
    head = 0;
    tail = 1;
    r[head] = tail;
    l[tail] = head;
    idx = 2;
    weight_set.clear();
    id_to_idx.clear();
}

// 在指定idx的右侧插入新元素
// k: 插入位置的索引
// id: 新元素的唯一标识符
// weight: 新元素的权重
void __insert(int k, int id, int weight) {
    e[idx] = {id, weight};
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    weight_set.insert({weight, idx});
    id_to_idx[id] = idx;
    idx++;
}

// 移除指定idx位置的元素
// k: 要移除的元素的索引
void __remove(int k) {
    weight_set.erase(weight_set.find({e[k].weight, k}));
    id_to_idx.erase(e[k].id);
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

// 从队列头部移除元素
void pop_front() {
    if (r[head] != tail) {
        __remove(r[head]);
    }
}

// 在队列尾部添加元素
// id: 新元素的唯一标识符
// weight: 新元素的权重
void push_back(int id, int weight) {
    __insert(l[tail], id, weight);
}

// 在指定id的元素前插入新元素
// target_id: 目标元素的唯一标识符
// new_id: 新元素的唯一标识符
// new_weight: 新元素的权重
void insert_before(int target_id, int new_id, int new_weight) {
    if (id_to_idx.count(target_id)) {
        int target_idx = id_to_idx[target_id];
        __insert(l[target_idx], new_id, new_weight);
    }
}

// 从队列尾部移除元素
void pop_back() {
    if (l[tail] != head) {
        __remove(l[tail]);
    }
}

// 在队列头部添加元素
// id: 新元素的唯一标识符
// weight: 新元素的权重
void push_front(int id, int weight) {
    __insert(head, id, weight);
}

// 在指定id的元素后插入新元素
// target_id: 目标元素的唯一标识符
// new_id: 新元素的唯一标识符
// new_weight: 新元素的权重
void insert_after(int target_id, int new_id, int new_weight) {
    if (id_to_idx.count(target_id)) {
        int target_idx = id_to_idx[target_id];
        __insert(target_idx, new_id, new_weight);
    }
}

// 删除权重最小的一个元素
void erase_min_weight() {
    if (!weight_set.empty()) {
        auto it = weight_set.begin();
        int min_weight_idx = it->second;
        __remove(min_weight_idx);
    }
}

// 删除所有权重最小的元素
void erase_all_min_weight() {
    if (!weight_set.empty()) {
        int min_weight = weight_set.begin()->first;
        vector<int> to_remove;
        for (auto it = weight_set.begin(); it != weight_set.end() && it->first == min_weight; ++it) {
            to_remove.push_back(it->second);
        }
        for (int idx : to_remove) {
            __remove(idx);
        }
    }
}

// 删除权重最大的一个元素
void erase_max_weight() {
    if (!weight_set.empty()) {
        auto it = prev(weight_set.end());
        int max_weight_idx = it->second;
        __remove(max_weight_idx);
    }
}

// 删除所有权重最大的元素
void erase_all_max_weight() {
    if (!weight_set.empty()) {
        int max_weight = prev(weight_set.end())->first;
        vector<int> to_remove;
        for (auto it = weight_set.rbegin(); it != weight_set.rend() && it->first == max_weight; ++it) {
            to_remove.push_back(it->second);
        }
        for (int idx : to_remove) {
            __remove(idx);
        }
    }
}

// 根据id查找元素的位置和权重
// id: 要查找的元素的唯一标识符
// 返回: pair<int, int>，第一个int是元素的索引，第二个int是元素的权重
pair<int, int> find_by_id(int id) {
    if (id_to_idx.count(id)) {
        int idx = id_to_idx[id];
        return {idx, e[idx].weight};
    }
    return {-1, -1}; // 如果未找到，返回 {-1, -1}
}

// 根据id移除元素
void remove_by_id(int id) {
    if (id_to_idx.count(id)) {
        __remove(id_to_idx[id]);
    }
}

// 获取队列中的最大权重值
// 返回: int，最大权重值，如果队列为空则返回-1
int get_max_weight() {
    if (!weight_set.empty()) {
        return prev(weight_set.end())->first;
    }
    return -1; // 如果队列为空，返回 -1
}

// 获取队列中的最小权重值
// 返回: int，最小权重值，如果队列为空则返回-1
int get_min_weight() {
    if (!weight_set.empty()) {
        return weight_set.begin()->first;
    }
    return -1; // 如果队列为空，返回 -1
}

// 移除指定权重范围内的所有元素
// low: 权重下限
// high: 权重上限
void remove_weight_range(int low, int high) {
    auto it_low = weight_set.lower_bound({low, 0});
    auto it_high = weight_set.upper_bound({high, INT_MAX});
    
    vector<int> to_remove;
    for (auto it = it_low; it != it_high; ++it) {
        to_remove.push_back(it->second);
    }
    
    for (int idx : to_remove) {
        __remove(idx);
    }
}

// 查询指定权重范围内的所有元素
// low: 权重下限
// high: 权重上限
// 返回: vector<pair<int, int>>，每个pair包含元素的id和权重
vector<pair<int, int>> query_weight_range(int low, int high) {
    vector<pair<int, int>> result;
    auto it_low = weight_set.lower_bound({low, 0});
    auto it_high = weight_set.upper_bound({high, INT_MAX});
    
    for (auto it = it_low; it != it_high; ++it) {
        int idx = it->second;
        result.push_back({e[idx].id, e[idx].weight});
    }
    
    return result;
}


// 打印队列中的所有元素（用于调试）
void print_queue() {
    for (int i = r[head]; i != tail; i = r[i]) {
        cout << "ID: " << e[i].id << ", Weight: " << e[i].weight << endl;
    }
    cout << endl;
}



int main() {
    __init();
    
    cout << "Testing push_back:" << endl;
    push_back(1, 10);
    push_back(2, 20);
    push_back(3, 15);
    push_back(4, 20);  // 测试权重不唯一
    print_queue();
    
    cout << "Testing pop_front:" << endl;
    pop_front();
    print_queue();
    
    cout << "Testing push_front:" << endl;
    push_front(5, 5);
    print_queue();
    
    cout << "Testing insert_before ID 3:" << endl;
    insert_before(3, 6, 18);
    print_queue();
    
    cout << "Testing insert_after ID 3:" << endl;
    insert_after(3, 7, 16);
    print_queue();
    
    cout << "Testing pop_back:" << endl;
    pop_back();
    print_queue();
    
    cout << "Testing erase_min_weight:" << endl;
    erase_min_weight();
    print_queue();
    
    cout << "Testing erase_max_weight:" << endl;
    erase_max_weight();
    print_queue();
    
    cout << "Testing erase_all_min_weight:" << endl;
    push_back(8, 15);
    push_back(9, 15);
    print_queue();
    erase_all_min_weight();
    print_queue();
    
    cout << "Testing erase_all_max_weight:" << endl;
    push_back(10, 20);
    push_back(11, 20);
    print_queue();
    erase_all_max_weight();
    print_queue();
    
    __init();
    // 测试基本操作
    push_back(1, 10);
    push_back(2, 20);
    push_back(3, 15);
    push_back(4, 25);
    push_back(5, 5);
    
    cout << "Initial queue:" << endl;
    print_queue();
    
    // 测试根据ID查找元素
    int search_id = 3;
    auto result = find_by_id(search_id);
    if (result.first != -1) {
        cout << "Element with ID " << search_id << " found at position " << result.first 
             << " with weight " << result.second << endl;
    } else {
        cout << "Element with ID " << search_id << " not found" << endl;
    }
    
    // 测试获取最大和最小权重
    cout << "Max weight: " << get_max_weight() << endl;
    cout << "Min weight: " << get_min_weight() << endl;
    
    // 测试范围查询
    cout << "Elements with weight between 10 and 20:" << endl;
    auto range_result = query_weight_range(10, 20);
    for (const auto& elem : range_result) {
        cout << "ID: " << elem.first << ", Weight: " << elem.second << endl;
    }
    
    // 测试范围删除
    cout << "Removing elements with weight between 15 and 25" << endl;
    remove_weight_range(15, 25);
    cout << "Queue after removal:" << endl;
    print_queue();
    
    return 0;
}
