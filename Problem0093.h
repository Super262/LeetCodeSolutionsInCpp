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
private:
    void dfs(const string &s, const int chIdx, const int numIdx, string &temp, vector<string> &result) {
        if (chIdx == (int) s.size()) {
            if (numIdx == 4) {
                temp.pop_back();  // 弹出分隔符
                result.emplace_back(string(temp));
            }
            return;
        }
        if (numIdx == 4) {
            return;
        }

        int inputSize = (int) temp.size();

        for (int i = chIdx, t = 0; i < s.size(); ++i) {
            t = t * 10 + (s[i] - '0');
            if (i > chIdx && s[chIdx] == '0') {  // 每位地址可以是0，但不能是0开头的多位数
                break;
            }
            if (t > 255) {
                break;
            }
            temp.push_back(s[i]);
            temp.push_back('.');
            dfs(s, i + 1, numIdx + 1, temp, result);
            temp.pop_back();  // 弹出分隔符
        }

        // 恢复现场
        while (temp.size() > inputSize) {
            temp.pop_back();
        }
    }

    vector<string> restoreIpAddresses(const string &s) {
        vector<string> result;
        string temp;
        dfs(s, 0, 0, temp, result);
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0093_H
