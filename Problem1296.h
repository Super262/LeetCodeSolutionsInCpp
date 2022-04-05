//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1296_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1296_H

#include <vector>
#include <set>

using namespace std;

class Solution {
    // 解法同 846 题
public:
    bool isPossibleDivide(const vector<int> &nums, int k) {
        multiset<int> s(nums.begin(), nums.end());
        if (s.size() % k) {
            return false;
        }
        while (!s.empty()) {
            auto x = *s.begin();
            for (int i = 0; i < k; ++i) {
                const auto &it = s.find(x + i);
                if (it == s.end()) {
                    return false;
                }
                s.erase(it);
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1296_H
