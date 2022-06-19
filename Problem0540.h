//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0540_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0540_H

#include <vector>

using namespace std;

class Solution {
    // 设单独元素为c，我们将原数组中相同的元素归为一组，得到以下分组：(a,a)，(b,b)，(c)，(d,d)，……，
    // 我们观察到如下规律：设索引为i的元素在c左侧，若i为偶数，nums[i]=nums[i+1]成立
    // 若索引为i的元素在c右侧（包括c），若i为偶数，nums[i]!=nums[i+1]成立
    // 因此，本题目可以用二分解决，查找满足nums[i]!=nums[i+1]成立的最小的i
public:
    int singleNonDuplicate(const vector<int> &nums) {
        int l = 0;
        auto r = (int) nums.size() - 1;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (mid % 2) {
                --mid;
            }
            if (nums[mid] == nums[mid + 1]) {
                l = mid + 2;
            } else {
                r = mid;
            }
        }
        return nums[r];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0540_H
