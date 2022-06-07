//
// Created by Fengwei Zhang on 1/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0472_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0472_H

#include <vector>
#include <string>
#include <cstring>
#include <unordered_set>

using namespace std;

class Solution {
    // 任意单词s，若s能分割成多个更短单词，s是属于答案的；f[i]=k表示s[0:i-1]最多可被分割为k个其它更短单词
    // f[i]=max{f[j]+1}，若s[j:i-1]是合法单词；因此，我们计算所有单词的哈希值，并逐一计算f，记录答案
    // 细节：枚举j的顺序应和计算哈希值时的枚举顺序相同
public:
    vector<string> findAllConcatenatedWordsInADict(const vector<string> &words) {
        unordered_set<unsigned long long> dict;
        for (const auto &w: words) {
            unsigned long long hash = 0;
            for (const auto &ch: w) {
                hash = hash * P + ch;
            }
            dict.insert(hash);
        }
        vector<string> ans;
        for (const auto &w: words) {
            if (isDividable(w, dict)) {
                ans.emplace_back(w);
            }
        }
        return ans;
    }

private:
    const unsigned long long P = 131;

    bool isDividable(const string &s, const unordered_set<unsigned long long> &dict) {
        const auto n = (int) s.size();
        int f[n + 1];
        memset(f, -1, sizeof f);
        f[0] = 0;
        for (int i = 0; i <= n; ++i) {
            if (f[i] < 0) {
                continue;
            }
            unsigned long long hash = 0;
            for (auto j = i + 1; j <= n; ++j) {
                hash = hash * P + s[j - 1];
                if (!dict.count(hash)) {
                    continue;
                }
                f[j] = max(f[i] + 1, f[j]);
            }
            if (f[n] > 1) {
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0472_H
