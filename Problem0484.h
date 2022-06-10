//
// Created by Fengwei Zhang on 6/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0484_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0484_H

#include<vector>
#include <string>

using namespace std;

class Solution {
    // 设s的长度为n，答案ans应是[1:n+1]的某个排列；为使字典序尽可能的小，我们尽量将较小的数字放在前面
    // 由于所有数字不同，我们采取贪心策略：ans初始值为[1:n+1]，若s[i:j]全为"D"，我们翻转ans[i:j+1]
public:
    vector<int> findPermutation(const string &s) {
        const auto n = (int) s.size() + 1;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = i + 1;
        }
        for (int i = 1; i < n; ++i) {
            if (s[i - 1] == 'I') {
                continue;
            }
            auto j = i + 1;
            while (j < n && s[j - 1] == 'D') {
                ++j;
            }
            reverse(ans.begin() + (i - 1), ans.begin() + j);
            i = j;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0484_H
