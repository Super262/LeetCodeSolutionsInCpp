//
// Created by Fengwei Zhang on 11/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0318_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0318_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int maxProduct(const vector<string> &words) {
        // 二进制统计每个字符
        const auto n = (int) words.size();
        int state[n];
        memset(state, 0, sizeof state);
        for (int i = 0; i < n; ++i) {
            for (auto ch: words[i]) {
                state[i] |= 1 << (ch - 'a');  // 使用或运算，不能用加运算（即使h出现多次，种类只有1个）
            }
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (state[i] & state[j]) {
                    continue;
                }
                result = max(result, (int) (words[i].size() * words[j].size()));
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0318_H
