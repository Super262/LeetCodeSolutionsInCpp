//
// Created by Fengwei Zhang on 5/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0379_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0379_H

#include <unordered_set>
#include <queue>

using namespace std;

class PhoneDirectory {
    // 队列 + 哈希表；O(n)初始化，O(1)查询/修改
    // 队列保存所有可用的数字，哈希表判断当前数字是否被使用；若数字x被释放，x入队
public:
    PhoneDirectory(int max_numbers) {
        for (int i = 0; i < max_numbers; ++i) {
            candidates.emplace(i);
        }
    }

    int get() {
        if (candidates.empty()) {
            return -1;
        }
        auto x = candidates.front();
        candidates.pop();
        used.insert(x);
        return x;
    }

    bool check(int number) {
        return used.count(number) == 0;
    }

    void release(int number) {
        if (!used.count(number)) {
            return;
        }
        used.erase(number);
        candidates.emplace(number);
    }

private:
    queue<int> candidates;
    unordered_set<int> used;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0379_H
