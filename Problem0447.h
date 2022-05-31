//
// Created by Fengwei Zhang on 1/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0447_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0447_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 对每个点points[i]，统计其它所有点与points[i]的距离的频率；我们可任选2个点points[j]、points[k]，它们与points[i]的距离相等
    // 因此，对于points[i]，若距离d的频率是f，答案增加f*(f-1)
public:
    int numberOfBoomerangs(const vector<vector<int>> &points) {
        int ans = 0;
        for (int i = 0; i < (int) points.size(); ++i) {
            unordered_map<int, int> counter;
            for (int j = 0; j < (int) points.size(); ++j) {
                if (j == i) {
                    continue;
                }
                auto dx = points[j][0] - points[i][0];
                auto dy = points[j][1] - points[i][1];
                ++counter[dx * dx + dy * dy];
            }
            for (const auto &item: counter) {
                ans += item.second * (item.second - 1);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0447_H
