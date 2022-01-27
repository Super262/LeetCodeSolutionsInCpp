//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0554_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0554_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 记录每个缝隙的横坐标，选择频率最高的
public:
    int leastBricks(const vector<vector<int>> &wall) {
        unordered_map<int, int> pos_freq;
        for (const auto &w: wall) {
            int s = 0;
            for (int i = 0; i < w.size() - 1; ++i) {  // 跳过最后砖的右侧缝隙
                s += w[i];
                ++pos_freq[s];
            }
        }
        int maximal = 0;
        for (auto &x: pos_freq) {
            maximal = max(maximal, x.second);
        }
        return (int) (wall.size() - maximal);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0554_H
