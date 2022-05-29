//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0414_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0414_H

#include <vector>

using namespace std;

class Solution {
    // 变量a、b、c分别保存当前的最大值、次大值、第三大值，unique_cnt统计当前参与到比较过程中的数字的个数
    // 比较大小时，只使用">"或"<"，不使用">="或"=<"，避免记录重复数字；若无法避开重复数字，我们返回最大值a
    // 根据数据范围，a、b、c的初始值是(INT_MAX-1)
public:
    int thirdMax(const vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        auto a = INT_MIN - 1ll;
        auto b = INT_MIN - 1ll;
        auto c = INT_MIN - 1ll;
        int unique_cnt = 0;
        for (const auto &x: nums) {
            if (x > a) {
                c = b;
                b = a;
                a = x;
                ++unique_cnt;
            } else if (x < a && x > b) {
                c = b;
                b = x;
                ++unique_cnt;
            } else if (x < b && x > c) {
                c = x;
                ++unique_cnt;
            }
        }
        if (unique_cnt < 3) {
            return (int) a;
        }
        return (int) c;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0414_H
