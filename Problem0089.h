//
// Created by Fengwei Zhang on 10/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0089_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0089_H

#include <vector>

using namespace std;

class Solution {
    // 特殊规律，要牢记：移出一位，再补上一位
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1, 0);
        ans.reserve(n);
        while (n) {
            for (int i = (int) ans.size() - 1; i >= 0; --i) {
                ans[i] <<= 1;
                ans.emplace_back(ans[i] + 1);
            }
            --n;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0089_H
