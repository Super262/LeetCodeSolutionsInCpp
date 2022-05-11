//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0088_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0088_H

#include <vector>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 经典算法，直接背诵：二路归并，注意细节
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (n == 0) {
            return;
        }
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        // 技巧：从后向前合并数字，避免未实用的数被覆盖
        int tt = m + n - 1;
        int h2 = n - 1;
        int h1 = m - 1;
        while (h2 >= 0 && h1 >= 0) {
            if (nums1[h1] > nums2[h2]) {
                nums1[tt--] = nums1[h1--];
            } else {
                nums1[tt--] = nums2[h2--];
            }
        }
        while (h1 >= 0) {
            nums1[tt--] = nums1[h1--];
        }
        while (h2 >= 0) {
            nums1[tt--] = nums2[h2--];
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0088_H
