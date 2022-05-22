//
// Created by Fengwei Zhang on 11/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0318_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0318_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // state[i]：二进制数，表示words[i]包含的字符种类（state[i]的第k位为1，表示words[i]包含('a'+k)）
    // 细节：更新state[i]时，使用或运算，不能用加运算（即使'a'出现多次，种类只有1个）
public:
    int maxProduct(const vector<string> &words) {
        const auto n = (int) words.size();
        int state[n];
        for (int i = 0; i < n; ++i) {
            state[i] = 0;
            for (auto ch: words[i]) {
                state[i] |= 1 << (ch - 'a');
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (state[i] & state[j]) {
                    continue;
                }
                ans = max(ans, (int) (words[i].size() * words[j].size()));
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0318_H
