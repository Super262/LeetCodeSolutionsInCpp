//
// Created by Fengwei Zhang on 6/28/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0644_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0644_H

#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(const vector<int> &nums, int k) {
        double l = INT_MAX;
        double r = INT_MIN;
        for (const auto &x: nums) {
            l = min(l, (double) x);
            r = max(r, (double) x);
        }
        auto pre_mid = r;
        double err = INT_MAX;
        while (err > 1e-5) {
            auto mid = (l + r) / 2;
            if (checkAvg(nums, k, mid)) {
                l = mid;
            } else {
                r = mid;
            }
            err = abs(pre_mid - mid);
            pre_mid = mid;
        }
        return l;
    }

private:
    bool checkAvg(const vector<int> &nums, int k, double avg) {
        double cur = 0;
        for (int i = 0; i < k; ++i) {
            cur += nums[i] - avg;
        }
        if (cur >= 0) {
            return true;
        }
        double min_sum = 0;
        double prev = 0;
        for (int i = k; i < (int) nums.size(); ++i) {
            cur += nums[i] - avg;
            prev += nums[i - k] - avg;
            min_sum = min(min_sum, prev);
            if (cur - min_sum >= 0) {
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0644_H
