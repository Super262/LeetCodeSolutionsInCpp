//
// Created by Fengwei Zhang on 3/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0781_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0781_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // https://www.acwing.com/solution/content/24647/
public:
    int numRabbits(const vector<int> &nums) {
        unordered_map<int, int> counter;
        for (const auto &x: nums) {
            ++counter[x];
        }
        int ans = 0;
        for (const auto &item: counter) {
            auto x = item.first + 1;
            auto y = item.second;
            if (y % x) {
                ans += (y / x + 1) * x;
            } else {
                ans += y;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0781_H
