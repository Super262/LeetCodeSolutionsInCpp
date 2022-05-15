//
// Created by Fengwei Zhang on 5/15/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0249_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0249_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 对于任意的字符串s，我们将其映射到以'a'开头的新字符串key；因此，我们可以根据key对输入分类
    // 优化，我们可以直接计算出key的哈希值，加快查找速度
    // 细节："z"的后继是"a"
public:
    vector<vector<string>> groupStrings(const vector<string> &strings) {
        unordered_map<unsigned long long, vector<int>> memo;
        for (int i = 0; i < (int) strings.size(); ++i) {  // 根据哈希值分类，记录索引
            memo[backToStart(strings[i])].emplace_back(i);
        }
        vector<vector<string>> ans;
        ans.reserve(memo.size());
        for (const auto &item: memo) {  // 根据索引，构造答案
            vector<string> cur;
            for (const auto &i: item.second) {
                cur.emplace_back(strings[i]);
            }
            ans.emplace_back(cur);
        }
        return ans;
    }

private:
    unsigned long long backToStart(const string &s) {  // 返回以'a'开头的key的哈希值
        const int P = 131;
        const int M = 26;
        const char t = 'a';
        unsigned long long ans = 0;
        const auto d = s[0] - t;  // 全局偏移量
        for (const auto &ch: s) {
            auto i = (((ch - t) - d) % M + M) % M;  // 根据偏移量"搬移"字符
            ans = ans * P + (i + t);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0249_H
