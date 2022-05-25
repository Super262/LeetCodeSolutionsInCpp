//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0363_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0363_H

#include <vector>
#include <cstring>
#include <set>

using namespace std;

class Solution {
    // 设矩阵有m行、n列，二维前缀和为prefix；我们用set结合二分查找来优化搜索子矩阵的过程
    // 首先，我们固定子矩阵的上、下边界为top、bottom，渐进移动右边界right到n，在right左侧查找左边界left，满足子矩阵的和小于k且最大
    // 此时，时间复杂度为O((m^2)*n*logn)；若m远大于n，我们可以交换顺序：固定子矩阵的左、右边界，渐进下移下边界，查找上边界（O((n^2)*m*logm)）
public:
    int maxSumSubmatrix(const vector<vector<int>> &mat, int k) {
        const auto m = (int) mat.size();
        const auto n = (int) mat[0].size();
        int prefix[m + 1][n + 1];
        memset(prefix, 0, sizeof prefix);
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                prefix[i][j] = mat[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
        bool row_first = n > m;
        int ans = INT_MIN;
        for (int top = 1; top <= (row_first ? m : n); ++top) {
            for (auto bottom = top; bottom <= (row_first ? m : n); ++bottom) {
                set<int> prev;
                prev.insert(0);
                for (int right = 1; right <= (row_first ? n : m); ++right) {
                    auto a = row_first ? prefix[bottom][right] - prefix[top - 1][right] :
                             prefix[right][bottom] - prefix[right][top - 1];
                    auto b = prev.lower_bound(a - k);
                    if (b != prev.end()) {
                        ans = max(ans, a - *b);
                    }
                    prev.insert(a);
                }
            }
        }
        return ans;
    }
};

/*class Solution {
    // 固定右边界，暴力枚举子矩阵
public:
    int maxSumSubmatrix(const vector<vector<int>> &matrix, const int &k) {
        const int n = (int) matrix.size();
        const int m = (int) matrix[0].size();
        int result = INT_MIN;
        int row_sum[n];
        // 行数多于列数，先枚举列
        for (int left = 0; left < m; ++left) {  // 渐进扩展左边界
            memset(row_sum, 0, sizeof row_sum);
            for (int right = left; right < m; ++right) {  // 渐进扩展右端边界
                for (int i = 0; i < n; ++i) {
                    row_sum[i] += matrix[i][right];
                }
                // 此时，row_sum[i]为matrix[i][left:right]的和
                result = max(result, getMaxSumOfSubSeq(row_sum, n, k));  // 相当于枚举子矩阵的和
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
};*/

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0363_H
