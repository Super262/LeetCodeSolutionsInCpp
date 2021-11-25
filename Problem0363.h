//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0363_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0363_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, const int &k) {
        const int n = (int) matrix.size();
        const int m = (int) matrix[0].size();
        int result = INT_MIN;
        int rowSum[n];
        // 行数多于列数，先枚举列
        for (int left = 0; left < m; ++left) {  // 渐进扩展左边界
            memset(rowSum, 0, sizeof rowSum);
            for (int right = left; right < m; ++right) {  // 渐进扩展右端边界
                for (int i = 0; i < n; ++i) {
                    rowSum[i] += matrix[i][right];
                }
                // 此时，rowSum[i]为matrix[i][left:right]的和
                result = max(result, getMaxSumOfSubSeq(rowSum, n, k));  // 相当于枚举子矩阵的和
            }
        }
        return result;
    }

private:
    int getMaxSumOfSubSeq(const int seq[], const int &n, const int &upperBound) {
        int result = INT_MIN;
        int prefix[n + 1];
        prefix[0] = 0;
        for (int i = 1; i <= n; ++i) {
            prefix[i] = seq[i - 1] + prefix[i - 1];
        }
        for (int st = 1; st <= n; ++st) {
            for (int ed = st; ed <= n; ++ed) {
                if (prefix[ed] - prefix[st - 1] <= result || prefix[ed] - prefix[st - 1] > upperBound) {
                    continue;
                }
                result = max(result, prefix[ed] - prefix[st - 1]);
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0363_H
