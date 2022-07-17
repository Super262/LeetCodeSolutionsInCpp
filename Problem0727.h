//
// Created by Fengwei Zhang on 7/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0727_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0727_H

#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Problem0727 {
    // 双指针+预处理；我们先从一个简单例子入手：s2="ab"；当遍历到s1[k]='b'时，只需要知道s1[0:k-1]中最近的'a'的位置
    // 若包含'a'的窗口是s1[i:j]，那么包含"ab"的窗口就是[i:k]；因此，我们先计算包含s2的前缀子串的窗口w，再根据前缀子串不断拓展，找到包含整个字符串的窗口
    // 为加快查找速度，我们预处理出next_idx[i][ch]，它表示s1[i:n-1]内字符ch的最近的（相对于i）索引
public:
    string minWindow(const string &s1, const string &s2) {
        const auto n = (int) s1.size();
        const int k = 26;
        int last_idx[k];  // last_idx[ch]：字符ch的上次出现位置
        int next_idx[n][k];
        memset(last_idx, -1, sizeof last_idx);
        memset(next_idx, -1, sizeof next_idx);
        for (int i = n - 1; i >= 0; --i) {
            auto ch = s1[i] - 'a';
            last_idx[ch] = i;
            for (int j = 0; j < k; ++j) {
                next_idx[i][j] = last_idx[j];
            }
        }
        vector<pair<int, int>> windows;
        for (int i = 0; i < n; ++i) {
            if (s1[i] == s2[0]) {
                windows.emplace_back(i, i);
            }
        }
        for (int j = 1; j < (int) s2.size(); ++j) {
            auto ch = s2[j] - 'a';
            for (auto &w: windows) {
                if (w.second + 1 < n && next_idx[w.second + 1][ch] != -1) {
                    w.second = next_idx[w.second + 1][ch];
                } else {
                    w.first = -1;
                    w.second = -1;
                    break;
                }
            }
        }
        pair<int, int> ans = {-1, n};
        for (const auto &w: windows) {
            if (w.first == -1) {
                break;
            }
            if (ans.second - ans.first > w.second - w.first) {
                ans = w;
            }
        }
        if (ans.first == -1) {
            return "";
        }
        return s1.substr(ans.first, ans.second - ans.first + 1);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0727_H
