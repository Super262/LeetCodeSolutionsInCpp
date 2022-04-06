//
// Created by Fengwei Zhang on 4/6/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0854_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0854_H

#include <string>

using namespace std;

class Solution {
    // 将原问题转换为图论问题：建立边(s1[i], s2[i])；最终目标是整个图中只包含自环
    // 构建自环的方式：交换字符，使得s1[i] == s2[i]成立
    // 因此，本题使用DFS计算最小的交换次数，使用期望函数提高搜索速度，即IDA*算法
public:
    int kSimilarity(string s1, string s2) {
        int d = 0;
        while (!dfs(s1, s2, d)) {
            ++d;
        }
        return d;
    }

private:
    // 需要的交换次数t >= ceil(s1和s2中不同的字符数d / 2)
    // exp = (d + 1) // 2 <= t，exp是合法的估价函数
    int exp(const string &s1, const string &s2) {
        int ans = 0;
        for (int i = 0; i < (int) s1.size(); ++i) {
            if (s1[i] == s2[i]) {
                continue;
            }
            ++ans;
        }
        return (ans + 1) / 2;
    }

    bool dfs(string &s1, string &s2, int d) {
        if (!d) {
            return s1 == s2;
        }
        if (exp(s1, s2) > d) {
            return false;
        }
        const auto n = (int) s1.size();
        for (int i = 0; i < n; ++i) {
            if (s1[i] == s2[i]) {
                continue;
            }
            // 发现非自环
            for (auto j = i + 1; j < n; ++j) {
                if (s1[j] != s2[i]) {
                    continue;
                }
                swap(s1[j], s1[i]);
                if (dfs(s1, s2, d - 1)) {  // 探索剩余部分
                    return true;
                }
                swap(s1[j], s1[i]);
            }
            // 重要剪枝：若无法使s1[i]==s2[i]成立，这已经注定此搜索无法到达最终结果，直接退出
            return false;
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0854_H
