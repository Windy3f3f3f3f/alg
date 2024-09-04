#include <iostream>
#include <list>
#include <unordered_map>
#include <set>
using namespace std;

struct Element {
    int id;
    int weight;
    list<Element>::iterator it;  // 存储元素在list中的迭代器
};

struct Compare {
    bool operator()(const Element* lhs, const Element* rhs) const {
        return lhs->weight < rhs->weight;
    }
};

class EfficientQueue {
private:
    list<Element> lst;
    unordered_map<int, Element*> id_map;
    set<Element*, Compare> weight_set;

public:
    // 删除队头元素
    void pop_front() {
        if (!lst.empty()) {
            Element* front = &lst.front();
            id_map.erase(front->id);
            weight_set.erase(front);
            lst.pop_front();
        }
    }

    // 加入队尾元素
    void push_back(int id, int weight) {
        lst.push_back({id, weight});
        auto it = --lst.end();
        it->it = it;  // 存储迭代器
        Element* elem = &(*it);
        id_map[id] = elem;
        weight_set.insert(elem);
    }

    // 给定标号，在标号前方插入一个新元素
    void insert_before(int target_id, int new_id, int new_weight) {
        auto it = id_map.find(target_id);
        if (it != id_map.end()) {
            Element* target = it->second;
            auto pos = lst.insert(target->it, {new_id, new_weight});
            pos->it = pos;  // 存储迭代器
            Element* new_elem = &(*pos);
            id_map[new_id] = new_elem;
            weight_set.insert(new_elem);
        }
    }

    // 删除权重最大的元素
    void erase_max_weight() {
        if (!weight_set.empty()) {
            Element* max_elem = *weight_set.rbegin();
            id_map.erase(max_elem->id);
            weight_set.erase(max_elem);
            lst.erase(max_elem->it);
        }
    }

    // 删除指定ID的元素 (O(1)操作)
    void erase_by_id(int id) {
        auto it = id_map.find(id);
        if (it != id_map.end()) {
            Element* elem = it->second;
            weight_set.erase(elem);
            lst.erase(elem->it);
            id_map.erase(it);
        }
    }

    // 打印队列中的元素（用于调试）
    void print_queue() {
        for (const auto& elem : lst) {
            cout << "ID: " << elem.id << ", Weight: " << elem.weight << endl;
        }
    }
};

int main() {
    EfficientQueue queue;
    queue.push_back(1, 10);
    queue.push_back(2, 20);
    queue.push_back(3, 15);
    
    cout << "Initial queue:" << endl;
    queue.print_queue();
    
    cout << "After popping front:" << endl;
    queue.pop_front();
    queue.print_queue();
    
    cout << "After inserting before ID 3:" << endl;
    queue.insert_before(3, 4, 18);
    queue.print_queue();
    
    cout << "After erasing max weight:" << endl;
    queue.erase_max_weight();
    queue.print_queue();
    
    cout << "After erasing ID 3:" << endl;
    queue.erase_by_id(3);
    queue.print_queue();
    
    return 0;
}
