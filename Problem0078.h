//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0078_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0078_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    // 利用二进制状态表示每个数是否被选择
    vector<vector<int>> subsets(const vector<int> &nums) {
        vector<vector<int>> result;
        const int n = (int) nums.size();
        for (int s = 0; s < (1 << n); ++s) {
            vector<int> temp;
            for (int i = 0; i < n; ++i) {
                if (((s >> i) & 1) == 0) {
                    continue;
                }
                temp.emplace_back(nums[i]);
            }
            result.emplace_back(temp);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0078_H
