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
    vector<string> findStrobogrammatic(const int &n) {
        vector<vector<string>> memo(max(n + 1, 3), vector<string>());  // 创建最小为3的字典
        memo[1] = {"0", "1", "8"};  // 长度为1的对称数
        memo[2] = {"00", "11", "69", "88", "96"};  // 长度为2的对称数（暂不考虑前导0）
        auto ans = dfs(n, memo);  // 临时存储结果
        int res_top = 0;
        for (int i = 0; i < (int) ans.size(); ++i) {
            // 去除包含前导0的非法数字
            if (ans[i][0] == '0' && ans[i].size() > 1) {
                continue;
            }
            ans[res_top++] = ans[i];
        }
        ans.erase(ans.begin() + res_top, ans.end());
        return ans;
    }

private:
    vector<string> dfs(const int &n, vector<vector<string>> &memo) {
        if (!memo[n].empty()) {
            return memo[n];
        }
        vector<string> mid;
        vector<string> sides;
        if (n % 2) {
            sides = dfs(n - 1, memo);
            mid = dfs(1, memo);
        } else {
            sides = dfs(n - 2, memo);
            mid = dfs(2, memo);
        }
        // 拼接
        memo[n].reserve(mid.size() * sides.size());
        for (const auto &y: sides) {
            auto a = y.substr(0, y.size() / 2);
            auto b = y.substr(y.size() / 2);
            for (const auto &x: mid) {
                memo[n].emplace_back(a + x + b);
            }
        }
        return memo[n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0247_H
