//
// Created by Fengwei Zhang on 3/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0805_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0805_H

#include <vector>
#include <set>
#include <numeric>

using namespace std;

class Solution {
    // 技巧：折半搜索（AcWing 163）
    // https://www.acwing.com/solution/content/2627/
public:
    bool splitArraySameAverage(const vector<int> &nums) {
        const auto n = (int) nums.size();
        auto m = n / 2;
        set<pair<int, int>> sum_set;
        for (int s = 0; s < (1 << m); ++s) {
            int sum = 0;
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                if ((s >> i) & 1) {
                    ++cnt;
                    sum += nums[i];
                }
            }
            sum_set.insert({sum, cnt});
        }
        auto all_sum = accumulate(nums.begin(), nums.end(), 0);
        for (int s = 0; s < (1 << (n - m)); ++s) {
            int sum = 0;
            int cnt = 0;
            for (int i = m; i < n; ++i) {
                if ((s >> (i - m)) & 1) {
                    ++cnt;
                    sum += nums[i];
                }
            }
            for (auto c = max(1, cnt); c < n; ++c) {
                if (c * all_sum % n) {  // 无法整除，avg*c无效
                    continue;
                }
                auto t = c * all_sum / n;  // 当前数组的总和
                pair<int, int> left = {t - sum, c - cnt};
                if (sum_set.find(left) != sum_set.end()) {
                    return true;
                }
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0805_H
