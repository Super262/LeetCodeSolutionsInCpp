//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0217_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0217_H

#include <unordered_set>
#include <vector>

class Problem0217 {
private:
    bool containsDuplicate(std::vector<int> &nums) {
        std::unordered_set<int> S;
        for (auto x: nums) {
            if (S.count(x)) {
                return true;
            }
            S.insert(x);
        }
        return false;
    }
};


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0217_H
