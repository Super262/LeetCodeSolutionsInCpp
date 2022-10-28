//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0016_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0016_H

#include <vector>
#include <algorithm>

using namespace std;

class Problem0016 {
    // 经典算法，直接背诵：双指针 + 排序
    // https://www.acwing.com/solution/content/15002/
public:
    int threeSumClosest(vector<int> &nums, const int target) {
        sort(nums.begin(), nums.end());
        int answer = 0x3f3f3f3f;
        for (int i = 0; i < (int) nums.size(); ++i) {  // 固定i
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            auto l = i + 1;
            auto r = (int) nums.size() - 1;
            while (l < r) {
                auto sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < abs(answer - target)) {
                    answer = sum;
                }
                if (sum > target) {
                    --r;
                    continue;
                }
                if (sum < target) {
                    ++l;
                    continue;
                }
                return target;
            }
        }
        return answer;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0016_H
