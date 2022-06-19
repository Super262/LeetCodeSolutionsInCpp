//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0554_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0554_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 根据题意，若垂直线穿过某块砖的边缘，我们认为垂直线未穿过这块砖
    // 因此，若要使垂直线穿过最少的砖，它应穿过最多的边缘；我们用哈希表统计每个横坐标x处的边缘的个数pos_freq[x]，找出最大值
    // 细节：为避免重复计数，我们只统计每块砖的左边缘，因为当前砖的右边缘和下块砖的左边缘相等
public:
    int leastBricks(const vector<vector<int>> &wall) {
        unordered_map<int, int> pos_freq;
        for (const auto &line: wall) {
            int x = 0;
            for (int i = 0; i < (int) line.size() - 1; ++i) {
                x += line[i];
                ++pos_freq[x];
            }
        }
        int max_edges = 0;
        for (const auto &x: pos_freq) {
            max_edges = max(max_edges, x.second);
        }
        return (int) (wall.size() - max_edges);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0554_H
