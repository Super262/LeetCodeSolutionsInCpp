//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0016_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0016_H

#include <vector>
#include <algorithm>

using namespace std;

class Problem0016 {
public:
    int threeSumClosest(vector<int> &nums, const int &target) {
        sort(nums.begin(), nums.end());
        pair<int, int> res(INT_MAX, INT_MAX);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1, k = (int) nums.size() - 1; j < k; ++j) {
                while (j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= target) {
                    --k;
                }
                auto s1 = nums[i] + nums[j] + nums[k];
                res = min(res, make_pair(abs(s1 - target), s1));  // s may be less than target, use abs.
                if (j == k - 1) {
                    continue;
                }
                auto s2 = nums[i] + nums[j] + nums[k - 1];
                res = min(res, make_pair(abs(s2 - target), s2));
            }
        }
        return res.second;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0016_H
