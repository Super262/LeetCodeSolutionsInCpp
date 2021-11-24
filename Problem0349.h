//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0349_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0349_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(const vector<int> &nums1, const vector<int> &nums2) {
        vector<int> result;
        unordered_set<int> uniqueNums(nums1.begin(), nums1.end());
        for (const auto &x: nums2) {
            if (!uniqueNums.count(x)) {
                continue;
            }
            result.push_back(x);
            uniqueNums.erase(x);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0349_H
