//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0378_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0378_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 巧妙二分，采用寻找下界的模版：O(n * logV)，V是数值范围
    // 性质：对于目标值x，若第i行中有k个元素大于x，第i+1行至少有k个元素大于x；我们可以利用这个性质减少搜索时间
public:
    int kthSmallest(const vector<vector<int>> &matrix, const int &k) {
        int l = -1e9;
        int r = 1e9;
        const auto n = (int) matrix[0].size();
        while (l < r) {
            auto mid = l + (r - l) / 2;
            auto prev_st = n - 1;  // 利用性质：每行的搜索起点随行数不增
            int cnt = 0;
            for (const auto &row: matrix) {
                while (prev_st >= 0 && row[prev_st] > mid) {
                    --prev_st;
                }
                cnt += prev_st + 1;
            }
            if (cnt >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0378_H
