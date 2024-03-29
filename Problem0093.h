//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0093_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0093_H

#include <vector>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

class Problem0093 {
    // 直接DFS：尝试当前段的长度为1~3，避免包含前导零的数字、大于255的数字
public:
    vector<string> restoreIpAddresses(const string &s) {
        vector<string> result;
        string temp;
        dfs(s, 0, 0, temp, result);
        return result;
    }

private:
    void dfs(const string &s, const int ch_idx, const int num_idx, string &temp, vector<string> &res) {
        if (num_idx == 4) {
            if (ch_idx == (int) s.size()) {
                temp.pop_back();  // 弹出分隔符
                res.emplace_back(temp);
            }
            return;
        }

        auto input_size = (int) temp.size();
        for (int i = ch_idx, t = 0; i < (int) s.size(); ++i) {
            t = t * 10 + (s[i] - '0');
            if (i > ch_idx && s[ch_idx] == '0') {  // 每位地址可以是0，但不能是0开头的多位数
                break;
            }
            if (t > 255) {
                break;
            }
            temp.push_back(s[i]);
            temp.push_back('.');
            dfs(s, i + 1, num_idx + 1, temp, res);
            temp.pop_back();  // 弹出分隔符
        }

        // 恢复现场
        while (temp.size() > input_size) {
            temp.pop_back();
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0093_H
