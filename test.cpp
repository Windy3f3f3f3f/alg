#include <iostream>
#include <map>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

void testMapIteration(const std::map<int, std::string>& myMap) {
    // 使用 ++ 操作符遍历 map
    std::cout << "Forward iteration:" << std::endl;
    for (std::map<int, std::string>::const_iterator it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
    }

    // 使用 -- 操作符反向遍历 map
    std::cout << "Backward iteration:" << std::endl;
    for (std::map<int, std::string>::const_reverse_iterator rit = myMap.rbegin(); rit != myMap.rend(); ++rit) {
        std::cout << rit->first << " => " << rit->second << std::endl;
    }
}

int main() {
    // 初始化随机数生成器
    std::srand(std::time(0));

    // 测试空 map
    std::map<int, std::string> emptyMap;
    std::cout << "Testing empty map:" << std::endl;
    testMapIteration(emptyMap);

    // 测试只有一个元素的 map
    std::map<int, std::string> singleElementMap;
    singleElementMap[1] = "one";
    std::cout << "\nTesting single element map:" << std::endl;
    testMapIteration(singleElementMap);

    // 测试包含多个元素的 map
    std::map<int, std::string> multipleElementsMap;
    multipleElementsMap[1] = "one";
    multipleElementsMap[2] = "two";
    multipleElementsMap[3] = "three";
    std::cout << "\nTesting multiple elements map:" << std::endl;
    testMapIteration(multipleElementsMap);

    // 测试包含大量元素的 map
    std::map<int, std::string> largeMap;
    for (int i = 0; i < 1000; ++i) {
        largeMap[i] = "value" + std::to_string(i);
    }
    std::cout << "\nTesting large map:" << std::endl;
    testMapIteration(largeMap);

    // 测试随机插入和删除的 map
    std::map<int, std::string> randomMap;
    for (int i = 0; i < 100; ++i) {
        int key = std::rand() % 200; // 随机生成一个键
        randomMap[key] = "value" + std::to_string(key);
    }
    std::cout << "\nTesting random insertion map:" << std::endl;
    testMapIteration(randomMap);

    // 随机删除一些元素
    for (int i = 0; i < 50; ++i) {
        int key = std::rand() % 200;
        randomMap.erase(key);
    }
    std::cout << "\nTesting random deletion map:" << std::endl;
    testMapIteration(randomMap);

    return 0;
}
