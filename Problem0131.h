//
// Created by Fengwei Zhang on 11/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0131_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0131_H

#include <vector>
#include <string>

using namespace std;

class Problem0131 {
public:
    vector<vector<string>> partition(const string &s) {
        const int n = (int) s.size();
        vector<vector<bool>> isPa(n, vector<bool>(n, false));
        // 预处理：isPa[l][r]指示s[l][r]是否为回文串
        for (int r = 0; r < n; ++r) {
            for (int l = r; l >= 0; --l) {
                if (l == r) {
                    isPa[l][r] = true;
                } else {
                    // 不要忘记l + 1 > r - 1的情况：这相当于空串
                    isPa[l][r] = s[l] == s[r] && (isPa[l + 1][r - 1] || (l + 1 > r - 1));
                }
            }
        }
        vector<vector<string>> result;
        vector<string> temp;
        dfs(s, 0, isPa, temp, result);
        return result;
    }

    void dfs(const string &s,
             const int &startIdx,
             const vector<vector<bool>> &isPa,
             vector<string> &temp,
             vector<vector<string>> &result) {
        if (startIdx == (int) s.size()) {
            result.emplace_back(temp);
            return;
        }
        for (int i = startIdx; i < (int) s.size(); ++i) {
            if (!isPa[startIdx][i]) {
                continue;
            }
            temp.emplace_back(s.substr(startIdx, i - startIdx + 1));
            dfs(s, i + 1, isPa, temp, result);
            temp.pop_back();
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0131_H
