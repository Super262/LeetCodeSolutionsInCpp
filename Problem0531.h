//
// Created by Fengwei Zhang on 6/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0531_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0531_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 开辟数组row_sum和col_sum，遍历pic，row_sum[i]和col_sum[j]分别记录第i行、第j列含"W"的个数
    // 再次遍历pic，若pic[i][j]='B'、row_sum[i]=col_sum[j]=1，答案加1
public:
    int findLonelyPixel(const vector<vector<char>> &pic) {
        const auto m = (int) pic.size();
        const auto n = (int) pic[0].size();
        int row_sum[m];
        int col_sum[n];
        memset(row_sum, 0, sizeof row_sum);
        memset(col_sum, 0, sizeof col_sum);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pic[i][j] == 'W') {
                    continue;
                }
                ++row_sum[i];
                ++col_sum[j];
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            if (row_sum[i] != 1) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (col_sum[j] != 1) {
                    continue;
                }
                if (pic[i][j] == 'B') {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0531_H
