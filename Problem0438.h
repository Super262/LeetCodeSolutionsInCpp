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
    // 双指针统计窗口内字符种类数，并且只使用一个哈希表完成
public:
    vector<int> findAnagrams(const string &s, const string &p) {
        unordered_map<char, int> counter;
        for (const auto &x: p) {
            ++counter[x];
        }
        const int type_cnt = (int) counter.size();
        vector<int> result;
        for (int l = 0, r = 0, current_cnt = 0; r < s.size(); ++r) {
            --counter[s[r]];
            if (counter[s[r]] == 0) {
                ++current_cnt;
            }
            if (r - l + 1 > p.size()) {
                if (counter[s[l]] == 0) {
                    --current_cnt;
                }
                ++counter[s[l]];
                ++l;
            }
            if (current_cnt == type_cnt) {
                result.emplace_back(l);
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0438_H
