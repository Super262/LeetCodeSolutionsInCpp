//
// Created by Fengwei Zhang on 4/7/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0861_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0861_H

#include <vector>

using namespace std;

class Solution {
    // 贪心算法：我们需要尽量使高位变为 1，即从高到低位选择，如果高位能变成 1，则变成 1，不需要考虑对低位的影响。
    // 因此，最终状态的矩阵的第0列全部为1，再通过变换使得其他列中1的个数多于0的个数
public:
    int matrixScore(vector<vector<int>> &grid) {
        for (auto &row: grid) {  // 翻转行，使第0列全部为1
            if (row[0]) {
                continue;
            }
            for (auto &x: row) {
                x ^= 1;
            }
        }
        for (int j = 0; j < grid[0].size(); ++j) {  // 翻转列，使其他列中1的个数多于0的个数
            int cnt = 0;
            for (auto &row: grid) {
                if (row[j]) {
                    ++cnt;
                }
            }
            if (cnt >= (grid.size() + 1) / 2) {
                continue;
            }
            for (auto &row: grid) {
                row[j] ^= 1;
            }
        }
        int ans = 0;
        for (const auto &row: grid) {
            int num = 0;
            for (const auto &x: row) {
                num <<= 1;
                if (x) {
                    ++num;
                }
            }
            ans += num;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0861_H
