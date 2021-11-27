//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0410_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0410_H

#include <vector>

using namespace std;

class Solution {
    // 二分算法求解符合条件的分段序列中段元素和的最大值的最小值
public:
    int splitArray(const vector<int> &nums, const int &m) {
        int l = 0;
        int r = INT_MAX;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (checkSegments(nums, mid, m)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }

private:
    bool checkSegments(const vector<int> &nums, const int &limit, const int &m) {
        // 确认每段数字和不超过limit时，nums被分成的段数是否不超过m
        // 若当前分cnt段满足条件，则再分成cnt + 1段也满足条件
        int cnt = 0;  // 当前段数
        int sum = 0;  // 当前段内数字和
        // 所有数均为正数：贪心思想
        for (const auto &x: nums) {
            if (x > limit) {  // 不要忘记这个边界条件！
                return false;
            }
            if ((long long) sum + x > limit) {
                ++cnt;
                sum = x;
            } else {
                sum += x;
            }
        }
        if (sum) {
            ++cnt;
        }
        return cnt <= m;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0410_H
