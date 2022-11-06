//
// Created by Fengwei Zhang on 11/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0135_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0135_H

#include <vector>
#include <cstring>

using namespace std;

class Problem0135 {
    // 贪心算法，直接背诵：我们从左到右枚举每一个同学，记前个同学分得的糖果数量为pre，当前递减序列长度为dec，最近递增序列的长度为inc
    // 如果当前同学比上个同学评分高，说明我们就在最近的递增序列中，直接分配给该同学pre+1个糖果
    // 否则，我们就在一个递减序列中，我们直接分配给当前同学一个糖果，并把该同学所在的递减序列中所有的同学都再多分配一个糖果，以保证糖果数量还是满足条件
    // 我们无需显式地额外分配糖果，只需要记录当前的递减序列长度，即可知道需要额外分配的糖果数量。
    // 注意：当当前的递减序列长度和上一个递增序列等长时，需要把最近的递增序列的最后一个同学也并进递减序列中
    // https://leetcode-cn.com/problems/candy/solution/fen-fa-tang-guo-by-leetcode-solution-f01p/
public:
    int candy(const vector<int> &ratings) {
        int ans = 1;
        int pre = 1;
        int inc = 1;
        int dec = 0;
        for (int i = 1; i < (int) ratings.size(); ++i) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                ans += pre;
                inc = pre;
            } else {
                ++dec;
                if (dec == inc) {
                    ++dec;
                }
                ans += dec;
                pre = 1;
            }
        }
        return ans;
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
