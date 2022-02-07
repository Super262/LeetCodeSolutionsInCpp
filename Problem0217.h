//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0217_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0217_H

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(const vector<int> &nums) {
        unordered_set<int> s;
        for (const auto &x: nums) {
            if (s.count(x)) {
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0217_H
