//
// Created by Fengwei Zhang on 1/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0462_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0462_H

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
    // 转化为货仓选址问题，类似AcWing 104
    // 贪心算法：找到序列的中位数x（快速选择），累计其它点到x的距离
public:
    int minMoves2(vector<int> &nums) {
        // 利用快速选择找到中位数
        auto k = (int) (nums.size() + 1) / 2;
        quickSelect(nums, 0, (int) nums.size() - 1, k);
        int res = 0;
        for (auto &x: nums) {
            res += abs(x - nums[k - 1]);
        }
        return res;
    }

private:
    void quickSelect(vector<int> &nums, int st, int ed, int k) {
        if (st >= ed) {
            return;
        }
        auto p = nums[st + (ed - st) / 2];
        auto l = st - 1;
        auto r = ed + 1;
        while (l < r) {
            while (nums[++l] < p);
            while (nums[--r] > p);
            if (l < r) {
                swap(nums[l], nums[r]);
            }
        }
        if (k <= r - st + 1) {
            quickSelect(nums, st, r, k);
        } else {
            quickSelect(nums, r + 1, ed, k - (r - st + 1));
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0462_H
