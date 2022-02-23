//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0719_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0719_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 二分 + 双指针
public:
    int smallestDistancePair(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = 1e6;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (countPairs(nums, mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }

private:
    int countPairs(const vector<int> &nums, const int d) {
        int res = 0;
        for (int l = 0, r = 1; r < nums.size(); ++r) {
            while (nums[r] - nums[l] > d) {
                ++l;
            }
            res += r - l;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0719_H
