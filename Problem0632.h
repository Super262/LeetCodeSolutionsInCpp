//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0632_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0632_H

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
    // 经典算法，必须掌握：K路归并算法
public:
    vector<int> smallestRange(const vector<vector<int>> &nums) {
        const int INF = 0x3f3f3f3f;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
        auto maximal = -INF;
        for (int i = 0; i < (int) nums.size(); ++i) {
            heap.push({nums[i][0], i, 0});
            maximal = max(maximal, nums[i][0]);
        }
        vector<int> res = {-INF, INF};
        while (!heap.empty()) {
            const auto t = heap.top();
            heap.pop();
            auto l = t[0];
            if (maximal - l < res[1] - res[0]) {
                res[1] = maximal;
                res[0] = l;
            }
            auto i = t[1];
            auto j = t[2];
            if (j + 1 >= (int) nums[i].size()) {
                return res;
            }
            heap.push({nums[i][j + 1], i, j + 1});
            maximal = max(maximal, nums[i][j + 1]);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0632_H
