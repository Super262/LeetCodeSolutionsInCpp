//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0349_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0349_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    // 统计nums1中的数字种类；遍历nums2，查找交集
public:
    vector<int> intersection(const vector<int> &nums1, const vector<int> &nums2) {
        vector<int> ans;
        unordered_set<int> unique_nums(nums1.begin(), nums1.end());
        for (const auto &x: nums2) {
            if (!unique_nums.count(x)) {
                continue;
            }
            ans.push_back(x);
            unique_nums.erase(x);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0349_H
