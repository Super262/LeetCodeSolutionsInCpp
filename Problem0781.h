//
// Created by Fengwei Zhang on 3/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0781_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0781_H

#include <vector>
#include <unordered_map>

using namespace std;

class Problem0781 {
    // 数学：统计每种数字x出现的次数num；若num是x+1的倍数，说明这num只兔子正好有num/(x+1)种颜色，需要num只兔子
    // 否则，说明这些兔子有t=num/(x+1)+1种颜色，需要t*(x+1)只兔子
public:
    int numRabbits(const vector<int> &nums) {
        unordered_map<int, int> counter;
        for (const auto &x: nums) {
            counter[x]++;
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
