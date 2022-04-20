//
// Created by Fengwei Zhang on 4/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0992_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0992_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 双指针：设r为右指针，l1、l2为左指针
    // 借助哈希表，我们保证：l1是最靠左的、保证[l1:r]段有k种数字的位置，l2是最靠左的、保证[l2:r]段有k-1种数字的位置（l1 < l2）
    // [l1:l2-1]和r分别构成合法子数组的起点和终点
public:
    int subarraysWithKDistinct(const vector<int> &nums, int k) {
        unordered_map<int, int> counter1;
        unordered_map<int, int> counter2;
        int ans = 0;
        for (int l1 = 0, l2 = 0, r = 0, cnt1 = 0, cnt2 = 0; r < (int) nums.size(); ++r) {
            if (!counter1.count(nums[r]) || !counter1[nums[r]]) {  // 发现新元素，更新cnt1
                ++cnt1;
            }
            counter1[nums[r]]++;
            if (!counter2.count(nums[r]) || !counter2[nums[r]]) {  // 发现新元素，更新cnt2
                ++cnt2;
            }
            counter2[nums[r]]++;
            while (l1 <= r && cnt1 > k) {  // cnt1大于k且子数组长度大于0，左移l1
                if (counter1[nums[l1]] == 1) {
                    --cnt1;
                }
                counter1[nums[l1]]--;
                ++l1;
            }
            while (l2 <= r && cnt2 > k - 1) {  // cnt2大于k-1且子数组长度大于0，左移l2
                if (counter2[nums[l2]] == 1) {
                    --cnt2;
                }
                counter2[nums[l2]]--;
                ++l2;
            }
            ans += l2 - l1;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0992_H
