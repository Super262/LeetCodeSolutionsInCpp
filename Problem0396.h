//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0396_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0396_H

#include <vector>

using namespace std;

class Solution {
    // 找规律：https://www.acwing.com/solution/content/22401/
public:
    int maxRotateFunction(const vector<int> &nums) {
        long long sum = 0;
        long long res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res += i * nums[i];
        }
        auto temp = res;
        for (int i = (int) nums.size() - 1; i >= 0; --i) {
            temp = temp + sum - (long long) nums.size() * nums[i];
            res = max(res, temp);
        }
        return (int) res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0396_H
