//
// Created by Fengwei Zhang on 3/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0789_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0789_H

#include <vector>
#include <cmath>

using namespace std;

class Problem0789 {
    // 贪心思想：若ghost距终点的距离比人更短，人无法逃脱
public:
    bool escapeGhosts(const vector<vector<int>> &ghosts, const vector<int> &target) {
        for (const auto &g: ghosts) {
            if (getDist(g[0], g[1], target[0], target[1]) <= getDist(0, 0, target[0], target[1])) {
                return false;
            }
        }
        return true;
    }

private:
    int getDist(int x1, int y1, int x2, int y2) {
        return abs(x2 - x1) + abs(y2 - y1);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0789_H
