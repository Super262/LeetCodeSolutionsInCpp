//
// Created by Fengwei Zhang on 11/15/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0247_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0247_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 中心线枚举 + 记忆化搜索；细节：结果不包含无效数字（含前导0）
    // n为奇数：搜索长度为n-1的数字s，结果为s[0:(n-1)/2-1]+("0"/"1"/"8")+s[(n-1)/2:n-2]
    // n为偶数：搜索长度为n-2的数字s，结果为s[0:(n-2)/2-1]+("00"/"11"/"88"/"69"/"96")+s[(n-2)/2:n-3]
public:
    vector<string> findStrobogrammatic(int n) {
        vector<vector<string>> memo(max(n + 1, 3));  // 创建最小为3的字典
        memo[1] = {"0", "1", "8"};  // 长度为1的对称数
        memo[2] = {"00", "11", "88", "69", "96"};  // 长度为2的对称数（暂不考虑前导0）
        auto ans = dfs(n, memo);
        int ans_top = 0;
        for (const auto &s: ans) {  // 去除包含前导0的非法数字
            if (s.size() > 1 && s[0] == '0') {
                continue;
            }
            ans[ans_top++] = s;
        }
        ans.erase(ans.begin() + ans_top, ans.end());
        return ans;
    }

private:
    vector<string> dfs(int n, vector<vector<string>> &memo) {
        if (!memo[n].empty()) {
            return memo[n];
        }
        vector<string> mids;
        vector<string> sides;
        if (n % 2) {
            mids = dfs(1, memo);
            sides = dfs(n - 1, memo);
        } else {
            mids = dfs(2, memo);
            sides = dfs(n - 2, memo);
        }
        memo[n].reserve(mids.size() * sides.size());
        for (const auto &y: sides) {
            auto a = y.substr(0, y.size() / 2);
            auto b = y.substr(y.size() / 2);
            for (const auto &x: mids) {
                memo[n].emplace_back(a + x + b);
            }
        }
        return memo[n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0247_H
