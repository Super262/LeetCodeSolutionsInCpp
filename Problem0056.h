//
// Created by Fengwei Zhang on 9/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0056_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0056_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 经典算法，直接背诵
public:
    // We can sort vectors!
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (unsigned long long i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= result.back()[1]) {
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0056_H
