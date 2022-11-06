//
// Created by Fengwei Zhang on 11/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0131_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0131_H

#include <vector>
#include <string>

using namespace std;

class Problem0131 {
    // 直接DFS：枚举分界点
    // 预处理：is_pa[l][r]指示s[l][r]是否为回文串
public:
    vector<vector<string>> partition(const string &s) {
        const int n = (int) s.size();
        vector<vector<bool>> is_pa(n, vector<bool>(n, false));
        for (int r = 0; r < n; ++r) {
            for (int l = r; l >= 0; --l) {
                if (l == r) {
                    is_pa[l][r] = true;
                } else {
                    // 不要忘记l + 1 > r - 1的情况：这相当于空串
                    is_pa[l][r] = s[l] == s[r] && (is_pa[l + 1][r - 1] || (l + 1 > r - 1));
                }
            }
        }
        vector<vector<string>> result;
        vector<string> temp;
        dfs(s, 0, is_pa, temp, result);
        return result;
    }

private:
    void dfs(const string &s,
             const int idx,
             const vector<vector<bool>> &is_pa,
             vector<string> &temp,
             vector<vector<string>> &result) {
        if (idx == (int) s.size()) {
            result.emplace_back(temp);
            return;
        }
        for (int i = idx; i < (int) s.size(); ++i) {
            if (!is_pa[idx][i]) {
                continue;
            }
            temp.emplace_back(s.substr(idx, i - idx + 1));
            dfs(s, i + 1, is_pa, temp, result);
            temp.pop_back();
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0131_H
