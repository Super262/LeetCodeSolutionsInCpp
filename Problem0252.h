//
// Created by Fengwei Zhang on 12/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0252_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0252_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>> &intervals) {
        if (intervals.size() < 2) {
            return true;
        }
        sort(intervals.begin(), intervals.end());
        auto prev = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prev[1]) {
                return false;
            }
            prev = intervals[i];
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0252_H
