//
// Created by Fengwei Zhang on 12/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0253_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0253_H

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> heap;
        for (const auto &x: intervals) {
            if (heap.empty()) {
                heap.emplace(x[1]);
                continue;
            }
            if (heap.top() > x[0]) {
                heap.emplace(x[1]);
            } else {
                heap.pop();
                heap.emplace(x[1]);
            }
        }
        return (int) heap.size();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0253_H
