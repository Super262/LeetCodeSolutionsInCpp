//
// Created by Fengwei Zhang on 1/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0447_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0447_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(const vector<vector<int>> &points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<int, int> counter;
            for (int j = 0; j < points.size(); ++j) {
                if (j == i) {
                    continue;
                }
                auto dx = points[j][0] - points[i][0];
                auto dy = points[j][1] - points[i][1];
                ++counter[dx * dx + dy * dy];
            }
            for (auto item: counter) {
                res += item.second * (item.second - 1);
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0447_H
