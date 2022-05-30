//
// Created by Fengwei Zhang on 12/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0438_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0438_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 双指针+哈希表：统计窗口[l:r]内字符种类数，若窗口长度等于p的长度、字符频率与p的字符频率相同，我们将l加入结果集
    // 优化：只用1个哈希表
public:
    vector<int> findAnagrams(const string &s, const string &p) {
        unordered_map<char, int> counter;
        for (const auto &x: p) {
            ++counter[x];
        }
        const auto type_cnt = (int) counter.size();
        vector<int> ans;
        for (int l = 0, r = 0, current_cnt = 0; r < (int) s.size(); ++r) {
            --counter[s[r]];
            if (!counter[s[r]]) {
                ++current_cnt;
            }
            if (r - l + 1 > (int) p.size()) {
                if (!counter[s[l]]) {
                    --current_cnt;
                }
                ++counter[s[l]];
                ++l;
            }
            if (current_cnt == type_cnt) {
                ans.emplace_back(l);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0438_H
