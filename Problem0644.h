//
// Created by Fengwei Zhang on 6/28/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0644_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0644_H

#include <vector>

using namespace std;

class Solution {
    // 若长度大于或等于k的数组nums的平均值是avg，那么对于任意元素(nums[i]-avg)，满足sum({nums[i]-avg | 0<=i<=n-1})>=0
    // 因此，我们可以通过二分avg、验证avg和nums是否满足题意来找到最大的avg；易知minimal<=avg<=maximal，我们采用贪心的方式验证avg是否满足题意
    // 若avg满足题意，那么nums中存在1个长度为j的子数组S，满足sum({nums[i]-avg | 0<=i<=j-1})>=0，j>=k；
    // 遍历数组nums时，我们累加(nums[i]-avg)；若前k项的和是非负数，avg合法；否则，继续累加(nums[i]-avg)；设前i项的和为Pi
    // 我们希望找到区间[i:j]，满足j-i>=k且Pj-Pi>=0；因此，我们在累加(nums[j]-avg)得到Pj时，用变量min_sum保存最小的Pi，min_sum初值为0
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
