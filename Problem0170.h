//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0170_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0170_H

class TwoSum {
private:
    unordered_map<long, int> numsCount;

public:
    TwoSum() {

    }

    void add(const int &number) {
        ++numsCount[number];
    }

    bool find(const int &value) {
        for (const auto &item: numsCount) {
            auto target = value - item.first;
            if (target == item.first && item.second >= 2) {
                return true;
            } else if (target != item.first && numsCount.count(target)) {
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0170_H
