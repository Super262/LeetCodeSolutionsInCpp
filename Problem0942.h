//
// Created by Fengwei Zhang on 4/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0942_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0942_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 设当前可用的最小值为l，最大值为r
    // 贪心：遇到'I'，添加最小值l，可保证在后面添加任何在[l+1:r]范围内的数字都是合法的；同理，遇到'D'，添加最大值r
public:
    vector<int> diStringMatch(const string &s) {
        vector<int> ans;
        const auto n = (int) s.size();
        ans.reserve(n + 1);
        int l = 0;
        auto r = n;
        for (const auto &x: s) {
            if (x == 'I') {
                ans.emplace_back(l);
                ++l;
            } else {
                ans.emplace_back(r);
                --r;
            }
        }
        ans.emplace_back(l);
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0942_H
