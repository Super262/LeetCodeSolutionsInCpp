//
// Created by Fengwei Zhang on 4/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0943_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0943_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 类比求最短Hamilton路径：状态压缩DP
    // 设字符串的个数是n；f[s][i]：当前状态是s（0 <= s < 2^n），结尾字符串是words[i]的结果长度；p[s][i]：i的前驱字符串的索引
    // 我们可以预处理出任意2个字符串的首尾重叠部分的长度
public:
    string shortestSuperstring(const vector<string> &words) {
        const auto n = (int) words.size();
        int intersection[n][n];  // 预处理：任意两个单词的头尾交集的长度
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                intersection[i][j] = countIntersection(words[i], words[j]);
            }
        }
        const int ANS_STATE = (1 << n) - 1;
        int f[ANS_STATE + 1][n];
        int p[ANS_STATE + 1][n];
        memset(f, 0x3f, sizeof f);
        memset(p, -1, sizeof p);
        for (int i = 0; i < n; ++i) {  // 初始状态
            f[1 << i][i] = (int) words[i].size();
        }
        for (int s = 0; s <= ANS_STATE; ++s) {
            for (int i = 0; i < n; ++i) {
                if (!((s >> i) & 1)) {
                    continue;
                }
                for (int j = 0; j < n; ++j) {
                    if (((s >> j) & 1) || f[s | (1 << j)][j] <= f[s][i] + (int) words[j].size() - intersection[i][j]) {
                        continue;
                    }
                    f[s | (1 << j)][j] = f[s][i] + (int) words[j].size() - intersection[i][j];
                    p[s | (1 << j)][j] = i;
                }
            }
        }
        int ans_len = INT_MAX;
        int cur_w = -1;
        for (int i = 0; i < n; ++i) {
            if (ans_len > f[ANS_STATE][i]) {
                ans_len = f[ANS_STATE][i];
                cur_w = i;
            }
        }
        string ans(ans_len, '\0');
        auto st = ans_len - (int) words[cur_w].size();  // 当前输出的起点
        auto cur_s = ANS_STATE;  // 当前的状态
        while (cur_s) {
            if (cur_w == -1) {
                break;
            }
            for (int i = 0; i < words[cur_w].size(); ++i) {
                ans[st + i] = words[cur_w][i];
            }
            auto next_w = p[cur_s][cur_w];  // 更新状态
            cur_s -= 1 << cur_w;
            if (next_w == -1) {
                break;
            }
            st -= (int) words[next_w].size() - intersection[next_w][cur_w];
            cur_w = next_w;
        }
        return ans;
    }

private:
    static int countIntersection(const string &a, const string &b) {
        const auto n = (int) a.size();
        const auto m = (int) b.size();
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[0]) {
                continue;
            }
            bool is_matched = true;
            for (int j = 0; j < m && i + j < n; ++j) {
                if (a[i + j] != b[j]) {
                    is_matched = false;
                    break;
                }
            }
            if (!is_matched) {
                continue;
            }
            return n - i;
        }
        return 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0943_H
