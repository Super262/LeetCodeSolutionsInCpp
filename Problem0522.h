//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0522_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0522_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 核心思想：若s的一个子序列是特殊序列，则s也是特殊序列
    // https://www.acwing.com/solution/content/25297/
public:
    int findLUSlength(const vector<string> &strs) {
        int res = -1;
        const auto n = (int) strs.size();
        for (int i = 0; i < n; ++i) {
            bool selected = true;
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                if (isSubSeq(strs[j], strs[i])) {
                    selected = false;
                    break;
                }
            }
            if (!selected) {
                continue;
            }
            res = max(res, (int) strs[i].size());
        }
        return res;
    }

private:
    bool isSubSeq(const string &a, const string &b) {  // 判断b是否为a的子序列
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                ++j;
            }
            ++i;
        }
        return j >= b.size();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0522_H
