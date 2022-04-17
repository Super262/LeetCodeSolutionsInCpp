//
// Created by Fengwei Zhang on 4/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0955_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0955_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 贪心思想：若当前列不递减，我们可保留当前列
    // 注意字典序的规则：两个字符串a、b，若a的前缀pa严格大于b的前缀pb（pa、pb长度相同），就可以确定a>b成立
public:
    int minDeletionSize(const vector<string> &strs) {
        const auto m = (int) strs.size();
        const auto n = (int) strs[0].size();
        bool is_asc[m];  // is_asc[i] = s[i] > s[i - 1]
        memset(is_asc, 0, sizeof is_asc);
        int ans = 0;
        for (int i = 0; i < n; ++i) {  // 遍历所有列
            bool is_ok = true;  // 判断当前列是否满足要求
            for (int j = 1; j < m; ++j) {
                if (!is_asc[j] && strs[j - 1][i] > strs[j][i]) {  // s[j]和s[j - 1]的大小关系不定，出现递减，非法
                    is_ok = false;
                    break;
                }
            }
            if (!is_ok) {
                ++ans;
                continue;
            }
            for (int j = 1; j < m; ++j) {
                // 依字典序的定义，字符串a、b，前缀pa严格大于pb时，a > b成立
                if (!is_asc[j] && strs[j - 1][i] < strs[j][i]) {
                    is_asc[j] = true;
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0955_H
