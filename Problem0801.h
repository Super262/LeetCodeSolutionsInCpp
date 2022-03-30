//
// Created by Fengwei Zhang on 3/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0801_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0801_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 当前操作只与前1项有关，可采用动态规划：https://www.acwing.com/solution/content/2630/
    // f[i][0]：不交换第i项，使得nums1和nums2为递增序列；f[i][1]：交换第i项，使得nums1和nums2为递增序列
public:
    int minSwap(const vector<int> &nums1, const vector<int> &nums2) {
        const auto n = (int) nums1.size();
        int f[n][2];
        memset(f, 0x3f, sizeof f);
        f[0][1] = 1;
        f[0][0] = 0;
        for (int i = 1; i < n; ++i) {
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {  // 保持原序时递增
                f[i][0] = min(f[i][0], f[i - 1][0]);
                f[i][1] = min(f[i][1], f[i - 1][1] + 1);
            }
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {  // 交换后递增
                f[i][0] = min(f[i][0], f[i - 1][1]);
                f[i][1] = min(f[i][1], f[i - 1][0] + 1);
            }
        }
        return min(f[n - 1][0], f[n - 1][1]);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0801_H
