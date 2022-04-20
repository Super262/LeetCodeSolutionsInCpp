//
// Created by Fengwei Zhang on 4/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0989_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0989_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 依次枚举，从低位开始处理进位
public:
    vector<int> addToArrayForm(const vector<int> &num, int k) {
        vector<int> ans;
        ans.reserve(num.size());
        for (auto i = (int) num.size() - 1; i >= 0 || k; --i) {
            if (i >= 0) {
                k += num[i];
            }
            ans.emplace_back(k % 10);
            k /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0989_H
