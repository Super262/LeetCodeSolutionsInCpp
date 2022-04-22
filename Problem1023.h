//
// Created by Fengwei Zhang on 4/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1023_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1023_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 子序列模版题，跳过q中不和p中大写字母匹配的小写字母
    // 设q被大写字母分成的段落为q1，q2，……qn，设p被大写字母分成的段落是p1，p2，……，pn，我们要检查pi是否为qi的子序列
public:
    vector<bool> camelMatch(const vector<string> &queries, const string &pattern) {
        vector<bool> ans(queries.size());
        for (int k = 0; k < (int) queries.size(); ++k) {
            int i = 0;
            int j = 0;
            bool is_matched = true;
            while (i < (int) queries[k].size()) {  // 遍历查询
                if (j < (int) pattern.size() && queries[k][i] == pattern[j]) {  // 相等，直接跳过
                    ++i;
                    ++j;
                    continue;
                }
                if (isupper(queries[k][i])) {  // 发现不相等的大写字母，非法
                    is_matched = false;
                    break;
                }
                ++i;
            }
            ans[k] = is_matched && j == (int) pattern.size();
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1023_H
