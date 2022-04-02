//
// Created by Fengwei Zhang on 4/1/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0825_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0825_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 统计每个年龄出现的频率
public:
    int numFriendRequests(const vector<int> &ages) {
        const auto n = (int) ages.size();
        unordered_map<int, int> f;
        for (const auto &x: ages) {
            ++f[x];
        }
        auto ans = n * n;
        for (const auto &x: f) {
            for (const auto &y: f) {
                if (y.first <= 0.5 * x.first + 7 || y.first > x.first || (y.first > 100 && x.first < 100)) {
                    ans -= x.second * y.second;
                    continue;
                }
                if (y.first == x.first) {
                    ans -= x.second;
                }
            }
        }
        return ans;
    }
};


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0825_H
