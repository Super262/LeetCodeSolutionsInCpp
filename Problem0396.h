//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0396_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0396_H

#include <vector>

using namespace std;

class Solution {
    // 找规律：https://www.acwing.com/solution/content/22401/
    // 先计算出f(0)，再根据f(i)=f(i-1)+sum-n*nums[i]递推
public:
    int maxRotateFunction(const vector<int> &nums) {
        long long sum = 0;
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ans += i * nums[i];
        }
        auto temp = ans;
        for (int i = (int) nums.size() - 1; i >= 0; --i) {
            temp = temp + sum - (long long) nums.size() * nums[i];
            ans = max(ans, temp);
        }
        return (int) ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0396_H
