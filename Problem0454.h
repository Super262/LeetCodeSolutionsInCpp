//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0454_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0454_H

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int fourSumCount(const vector<int> &a, const vector<int> &b, const vector<int> &c, const vector<int> &d) {
        unordered_map<int, int> counter;
        for (const auto &x: a) {
            for (const auto &y: b) {
                ++counter[x + y];
            }
        }
        int res = 0;
        for (const auto &x: c) {
            for (const auto &y: d) {
                if (!counter.count(-(x + y))) {
                    continue;
                }
                res += counter[-(x + y)];
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0454_H
