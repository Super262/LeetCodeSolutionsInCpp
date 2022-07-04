//
// Created by Fengwei Zhang on 2/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0667_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0667_H

#include <vector>

using namespace std;

class Solution {
    // 找规律，先构造出k+1个数字的序列让相邻的两个数字之间的差值不同（共k种差值，范围为1~k），再依次排列剩余的数字
    // 构造规律如下：1,k+1,2,k,3,k-1,...,k+2,k+3,...,n，相邻数字的差值为k,k-1,...,2,1,1,...,1
public:
    vector<int> constructArray(const int n, const int k) {
        vector<int> ans;
        ans.reserve(n);
        ans.emplace_back(1);
        for (int i = 0; i < k; ++i) {
            if (i % 2) {
                ans.emplace_back(2 + i / 2);
            } else {
                ans.emplace_back(k + 1 - i / 2);
            }
        }
        for (auto i = k + 2; i <= n; ++i) {
            ans.emplace_back(i);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0667_H
