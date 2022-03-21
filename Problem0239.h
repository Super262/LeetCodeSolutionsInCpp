//
// Created by Fengwei Zhang on 11/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0239_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0239_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(const vector<int> &nums, const int &k) {
        deque<int> q;
        vector<int> result;
        result.reserve(nums.size() - (k - 1));
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (!q.empty() && q.back() - q.front() + 1 == k) {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.emplace_back(i);
            if (i >= k - 1) {
                result.emplace_back(nums[q.front()]);
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0239_H
