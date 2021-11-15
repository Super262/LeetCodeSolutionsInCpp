//
// Created by Fengwei Zhang on 11/15/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0247_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0247_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findStrobogrammatic(const int &n) {
        vector<vector<string>> dicts(max(n + 1, 3), vector<string>());  // 创建最小为3的字典
        dicts[1] = {"0", "1", "8"};  // 长度为1的对称数
        dicts[2] = {"00", "11", "69", "88", "96"};  // 长度为2的对称数（暂不考虑前导0）
        auto result = dfs(n, dicts);  // 临时存储结果
        int resTop = 0;
        for (int i = 0; i < (int) result.size(); ++i) {
            // 去除包含前导0的非法数字
            if (result[i][0] == '0' && result[i].size() > 1) {
                continue;
            }
            result[resTop++] = result[i];
        }
        result.erase(result.begin() + resTop, result.end());
        return result;
    }

private:
    vector<string> dfs(const int &n, vector<vector<string>> &dicts) {
        if (!dicts[n].empty()) {
            return dicts[n];
        }
        vector<string> mid;
        vector<string> sides;
        if (n % 2) { // 奇数长度：s[n / 2]和(s[0, n / 2 - 1] + s[n / 2 + 1, n - 1])是对称串
            sides = dfs(n - 1, dicts);
            mid = dfs(1, dicts);
        } else { // 奇数长度：s[n / 2 - 1, n / 2]和(s[0, n / 2 - 2] + s[n / 2 + 1, n - 1])是对称串
            sides = dfs(n - 2, dicts);
            mid = dfs(2, dicts);
        }
        // 拼接
        for (const auto &y: sides) {
            string temp;
            if (mid[0].size() == 1) {
                temp = y.substr(0, y.size() / 2) + "0" + y.substr(y.size() / 2);
            } else {
                temp = y.substr(0, y.size() / 2) + "00" + y.substr(y.size() / 2);
            }
            for (const auto &x: mid) {
                if (x.size() == 1) {
                    temp[y.size() / 2] = x[0];
                } else {
                    temp[y.size() / 2] = x[0];
                    temp[y.size() / 2 + 1] = x[1];
                }
                dicts[n].emplace_back(temp);
            }
        }
        return dicts[n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0247_H
