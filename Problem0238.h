//
// Created by Fengwei Zhang on 11/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0238_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0238_H

#include <vector>

using namespace std;

class Solution {
    // prefix[i]：[0:i-1]所有数的乘积；suffix[i]：[i+1:n-1]所有数的乘积；prefix[0] = suffix[n-1] = 1
    // 因此，最终答案ans[i]=prefix[i]*suffix[i]
public:
    vector<int> productExceptSelf(const vector<int> &nums) {
        vector<int> ans(nums.size(), 1);
        int prefix = 1;
        for (int i = 1; i < (int) nums.size(); ++i) {
            prefix *= nums[i - 1];
            ans[i] *= prefix;
        }
        int suffix = 1;
        for (int i = (int) nums.size() - 2; i >= 0; --i) {
            suffix *= nums[i + 1];
            ans[i] *= suffix;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0238_H
