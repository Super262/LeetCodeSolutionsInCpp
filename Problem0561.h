//
// Created by Fengwei Zhang on 1/27/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0561_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0561_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 经典贪心算法，利用"交换"可证明：https://www.acwing.com/solution/content/436/
public:
    int arrayPairSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            res += nums[i];
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0561_H
