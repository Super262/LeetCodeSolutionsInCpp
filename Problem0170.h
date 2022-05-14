//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0170_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0170_H

#include <unordered_map>

using namespace std;

class TwoSum {
    // 输入可能有重复数字，要注意细节
public:
    TwoSum() = default;

    void add(const int &number) {
        ++counter[number];
    }

    bool find(const int &value) {
        for (const auto &item: counter) {
            auto target = value - item.first;
            if (target == item.first && item.second >= 2) {  // a == b
                return true;
            }
            if (target != item.first && counter.count(target)) {  // a != b
                return true;
            }
        }
        return false;
    }

private:
    unordered_map<long, int> counter;
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0170_H
