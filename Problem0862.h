//
// Created by Fengwei Zhang on 4/7/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0862_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0862_H

#include <vector>
#include <deque>

using namespace std;

class Solution {
    // 特殊的单调队列q：s[q[-1]] - s[q[0]] >= k，且s[q[-1]] - s[q[0]]最小
public:
    int shortestSubarray(const vector<int> &nums, int k) {
        const auto n = (int) nums.size();
        long long s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        deque<int> q;
        int ans = INT_MAX;
        q.emplace_back(0);
        for (int i = 1; i <= n; ++i) {
            while (!q.empty() && s[i] - s[q.front()] >= k) {
                ans = min(ans, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && s[i] <= s[q.back()]) {
                q.pop_back();
            }
            q.emplace_back(i);
        }
        if (ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0862_H
