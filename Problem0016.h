//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0016_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0016_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 经典算法，直接背诵：双指针 + 排序
    // https://www.acwing.com/solution/content/15002/
public:
    int threeSumClosest(vector<int> &nums, const int target) {
        sort(nums.begin(), nums.end());
        int answer = 0x3f3f3f3f;
        for (int i = 0; i < nums.size(); ++i) {  // 固定i
            for (auto l = i + 1, r = (int) nums.size() - 1; l < r; ++l) {
                while (l < r - 1 && nums[i] + nums[l] + nums[r - 1] >= target) {  // 固定l，移动r
                    --r;
                }
                auto s1 = nums[i] + nums[l] + nums[r];
                if (abs(s1 - target) < abs(answer - target)) {
                    answer = s1;
                }
                if (l == r - 1) {  // 若nums[l]和nums[r]间无其他数字，继续
                    continue;
                }
                auto s2 = nums[i] + nums[l] + nums[r - 1];
                if (abs(s2 - target) < abs(answer - target)) {
                    answer = s2;
                }
            }
        }
        return answer;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0016_H
