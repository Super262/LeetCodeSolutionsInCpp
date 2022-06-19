//
// Created by Fengwei Zhang on 1/27/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0561_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0561_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 很容易想到，让两个比较小的数在一起比一个小的一个大的数放在一起产生的结果要大
    // 经典贪心算法：若原数组可以被分成n/2对，那么满足题意的sum是有序数组偶数位置元素的和
    // 利用"交换"可证明：https://www.acwing.com/solution/content/436/
public:
    int arrayPairSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < (int) nums.size(); i += 2) {
            ans += nums[i];
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0561_H
