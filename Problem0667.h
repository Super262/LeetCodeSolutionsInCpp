//
// Created by Fengwei Zhang on 2/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0667_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0667_H

#include <vector>

using namespace std;

class Solution {
    // 直接背诵：https://www.acwing.com/solution/content/18507/
public:
    vector<int> constructArray(const int n, const int k) {
        vector<int> res;
        res.reserve(n);
        res.emplace_back(1);
        for (int i = 0; i < k; ++i) {
            if (i % 2) {
                res.emplace_back(2 + i / 2);
            } else {
                res.emplace_back(k + 1 - i / 2);
            }
        }
        for (auto i = k + 2; i <= n; ++i) {
            res.emplace_back(i);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0667_H
