//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0350_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0350_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersect(const vector<int> &nums1, const vector<int> &nums2) {
        unordered_multiset<int> allNums(nums1.begin(), nums1.end());
        vector<int> res;
        for (const auto &x: nums2) {
            if (!allNums.count(x)) {
                continue;
            }
            allNums.erase(allNums.find(x));
            res.push_back(x);
        }
        return res;
    }
};


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0350_H
