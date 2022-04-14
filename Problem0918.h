//
// Created by Fengwei Zhang on 4/14/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0918_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0918_H

#include <vector>
#include <deque>

using namespace std;

class Solution {
    // 求以nums[i]结尾的、和最大的子数组 === 求最小的prefix[j]，使得prefix[i] - prefix[j]最大
    // 破环成链：长度为n的环形数组 === 长度为2n的普通数组
public:
    int maxSubarraySumCircular(const vector<int> &nums) {
        const auto n = (int) nums.size();
        int prefix[2 * n + 1];
        prefix[0] = 0;
        for (int i = 1; i <= 2 * n; ++i) {
            prefix[i] = prefix[i - 1] + nums[(i - 1) % n];
        }
        deque<int> q;
        int ans = INT_MIN;
        q.emplace_back(0);
        for (int i = 1; i <= 2 * n; ++i) {  // 注意：这里遍历的是前缀和的索引，长度限制是i - j + 1 <= n + 1！
            while (!q.empty() && i - q.front() + 1 > n + 1) {
                q.pop_front();
            }
            ans = max(ans, prefix[i] - prefix[q.front()]);
            while (!q.empty() && prefix[q.back()] >= prefix[i]) {
                q.pop_back();
            }
            q.emplace_back(i);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0918_H
