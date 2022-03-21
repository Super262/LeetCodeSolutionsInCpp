//
// Created by Fengwei Zhang on 11/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0282_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0282_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 巧妙的常数优化：https://www.acwing.com/solution/content/332/
public:
    vector<string> addOperators(const string &num, const int &target) {
        vector<string> result;
        string path(100, '\0');
        dfs(num, target, 0, 0, 1, path, 0, result);
        return result;
    }

private:
    void dfs(const string &num,
             const int &target,
             const int &cur_idx,
             const long long &a,
             const long long &b,
             string &path,
             const int &len,
             vector<string> &result) {
        if (cur_idx == num.size()) {
            if (target == a) {
                result.emplace_back(path.substr(0, len - 1));  // 需要排除最后的“+”
            }
            return;
        }
        long long c = 0;
        for (auto i = cur_idx; i < (int) num.size(); ++i) {
            c = c * 10 + (num[i] - '0');
            path[len + i - cur_idx] = num[i];
            path[len + i - cur_idx + 1] = '+';
            dfs(num, target, i + 1, a + b * c, 1, path, len + i - cur_idx + 2, result);
            if (i + 1 < num.size()) {
                path[len + i - cur_idx + 1] = '-';
                dfs(num, target, i + 1, a + b * c, -1, path, len + i - cur_idx + 2, result);
            }
            if (i + 1 < num.size()) {
                path[len + i - cur_idx + 1] = '*';
                dfs(num, target, i + 1, a, b * c, path, len + i - cur_idx + 2, result);
            }
            if (num[cur_idx] == '0') {
                break;
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0282_H
