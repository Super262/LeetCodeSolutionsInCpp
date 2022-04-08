//
// Created by Fengwei Zhang on 4/7/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0870_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0870_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 贪心：若 nums1[i] > min(nums2)，则 res[idx(min(nums2))] = nums1[i]；否则，res[idx(max(nums2))] = nums1[i]
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
        const auto n = (int) nums2.size();
        int idx[n];
        for (int i = 0; i < n; ++i) {
            idx[i] = i;
        }
        sort(nums1.begin(), nums1.end());
        sort(idx, idx + n, [&](const int &a, const int &b) {
            return nums2[a] < nums2[b];
        });
        vector<int> ans(n);
        int l = 0;
        auto r = n - 1;
        for (const auto &x: nums1) {
            if (x > nums2[idx[l]]) {
                ans[idx[l]] = x;
                ++l;
            } else {
                ans[idx[r]] = x;
                --r;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0870_H
