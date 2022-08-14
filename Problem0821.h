//
// Created by Fengwei Zhang on 4/1/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0821_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0821_H

#include <string>
#include <vector>

using namespace std;

class Problem0821 {
    // 双指针，2次遍历；第1次遍历，从左至右，在i的左侧找到距离当前字符s[i]最近的目标字符
    // 第2次遍历，从右至左，在i的右侧找到距离当前字符s[i]最近的目标字符
public:
    vector<int> shortestToChar(const string &s, char ch) {
        const auto n = (int) s.size();
        vector<int> ans(n, INT_MAX);
        for (int i = 0, j = -1; i < n; ++i) {
            if (s[i] == ch) {
                j = i;
            }
            if (j != -1) {
                ans[i] = min(ans[i], i - j);
            }
        }
        for (int i = n - 1, j = n; i >= 0; --i) {
            if (s[i] == ch) {
                j = i;
            }
            if (j != n) {
                ans[i] = min(ans[i], j - i);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0821_H
