//
// Created by Fengwei Zhang on 11/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0135_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0135_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 经典算法，直接背诵
    // https://leetcode-cn.com/problems/candy/solution/fen-fa-tang-guo-by-leetcode-solution-f01p/
public:
    int candy(const vector<int> &ratings) {
        int result = 1;
        int pre = 1, inc = 1, dec = 0;
        for (int i = 1; i < (int) ratings.size(); ++i) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                result += pre;
                inc = pre;
            } else {
                ++dec;
                if (dec == inc) {
                    ++dec;
                }
                result += dec;
                pre = 1;
            }
        }
        return result;
    }
};

/*class Solution {
    // 经典算法，直接背诵
    // 转化为AcWing0901（https://www.acwing.com/solution/content/18288/）
public:
    int candy(const vector<int> &ratings) {
        const int n = (int) ratings.size();
        int dp[n];
        memset(dp, -1, sizeof dp);
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += dfs(ratings, i, dp);
        }
        return result;
    }

private:
    int dfs(const vector<int> &ratings, const int &idx, int dp[]) {
        if (dp[idx] != -1) {
            return dp[idx];
        }
        dp[idx] = 1;
        const int n = (int) ratings.size();
        if (idx > 0 && ratings[idx - 1] < ratings[idx]) { // 向左搜索下降序列
            dp[idx] = max(dp[idx], dfs(ratings, idx - 1, dp) + 1);
        }
        if (idx + 1 < n && ratings[idx + 1] < ratings[idx]) { // 向右搜索下降序列
            dp[idx] = max(dp[idx], dfs(ratings, idx + 1, dp) + 1);
        }
        return dp[idx];
    }
};*/

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0135_H
