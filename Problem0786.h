//
// Created by Fengwei Zhang on 3/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0786_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0786_H

#include <vector>
#include <cmath>

using namespace std;

class Solution {
    // 二分 + 双指针：https://www.acwing.com/solution/content/2801/
public:
    vector<int> kthSmallestPrimeFraction(const vector<int> &arr, int k) {
        double l = 0;
        double r = 1;
        vector<int> ans = {-1, -1};
        while (r - l > ZERO) {
            auto mid = l + (r - l) / 2;
            if (countLessOrEqual(arr, mid, ans) >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return ans;
    }

private:
    int countLessOrEqual(const vector<int> &arr, double t, vector<int> &ans) {
        int res = 0;
        for (int l = 0, r = 0; r < (int) arr.size(); ++r) {
            while (l < r && t - (double) arr[l] / arr[r] > ZERO) {
                ++l;
            }
            res += l;
            if (abs((double) arr[l] / arr[r] - t) < ZERO) {
                ans[0] = arr[l];
                ans[1] = arr[r];
            }
        }
        return res;
    }

    const double ZERO = 1e-8;
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0786_H
