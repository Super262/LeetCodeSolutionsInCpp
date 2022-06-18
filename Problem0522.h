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
    // 对于每个strs[i]，若不存在j（i!=j）使得strs[i]是strs[j]的子序列，strs[i]是特殊序列
public:
    int findLUSlength(const vector<string> &strs) {
        int ans = -1;
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
            ans = max(ans, (int) strs[i].size());
        }
        return ans;
    }

private:
    bool isSubSeq(const string &a, const string &b) {  // 判断b是否为a的子序列
        int j = 0;
        for (int i = 0; i < (int) a.size() && j < (int) b.size(); ++i) {
            if (a[i] == b[j]) {
                ++j;
            }
        }
        return j >= (int) b.size();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0522_H
