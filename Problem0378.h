//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0378_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0378_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 巧妙二分，采用寻找下界的模版：O(n * logV)
public:
    int kthSmallest(const vector<vector<int>> &matrix, const int &k) {
        int l = -1e9;
        int r = 1e9;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            int prevSt = (int) matrix[0].size() - 1;  // 利用性质：每行的搜索起点随行数不增
            int cnt = 0;
            for (const auto &row: matrix) {
                while (prevSt >= 0 && row[prevSt] > mid) {
                    --prevSt;
                }
                cnt += prevSt + 1;
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
