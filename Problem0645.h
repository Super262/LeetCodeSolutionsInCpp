//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0645_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0645_H

#include <vector>

using namespace std;

class Solution {
    // 设x=nums[i]，翻转x的符号位后，若nums[x-1]符号为正，则x出现0次或2次
public:
    vector<int> findErrorNums(vector<int> &nums) {
        vector<int> ans(2, 0);
        for (const auto &x: nums) {
            auto k = abs(x);
            nums[k - 1] *= -1;
            if (nums[k - 1] > 0) {  // 发现第1个正数
                ans[0] = k;
            }
        }
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (nums[i] > 0 && i + 1 != ans[0]) {  // 发现第2个正数
                ans[1] = i + 1;
                break;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0645_H
