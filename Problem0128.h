//
// Created by Fengwei Zhang on 11/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0128_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0128_H

#include <vector>
#include <unordered_set>

using namespace std;

class Problem0128 {
public:
    int longestConsecutive(const vector<int> &nums) {
        // 巧妙的做法，要牢记！
        unordered_set<int> S;
        for (const auto &x: nums) {
            S.insert(x);
        }
        int result = 0;
        for (const auto &x: nums) {
            if (!S.count(x) || S.count(x - 1)) {
                continue;
            }
            S.erase(x);
            auto y = x;
            while (S.count(y + 1)) {
                S.erase(y);
                ++y;
            }
            result = max(result, y - x + 1);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0128_H
