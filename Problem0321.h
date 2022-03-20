//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0321_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0321_H

#include <vector>
#include <climits>

using namespace std;

class Solution {
    // 贪心算法：https://www.acwing.com/solution/content/347/
public:
    vector<int> maxNumber(const vector<int> &nums1, const vector<int> &nums2, const int &k) {
        const auto n = (int) nums1.size();
        const auto m = (int) nums2.size();
        vector<int> res(k, INT_MIN);
        vector<int> temp(k, INT_MIN);
        for (int i = max(0, k - m); i <= min(k, n); ++i) {  // 枚举从nums1中选取的数字个数
            auto a = maxArray(nums1, i);
            auto b = maxArray(nums2, k - i);
            merge(a, b, temp);
            res = max(res, temp);
        }
        return res;
    }

private:
    vector<int> maxArray(const vector<int> &nums, const int &k) {  // 贪心算法
        vector<int> res(k);
        const int n = (int) nums.size();
        for (int i = 0, j = 0; i < n; ++i) {
            auto x = nums[i];
            while (j > 0 && res[j - 1] < x && j + n - i > k) {  //后继数字更大且候选者的数量充足
                --j;
            }
            if (j < k) {
                res[j++] = x;
            }
        }
        return res;
    }

    void merge(vector<int> &a, vector<int> &b, vector<int> &dest) {
        int i = 0;
        while (!a.empty() && !b.empty()) {
            if (a > b) {  // 字典序更大
                dest[i++] = a[0];
                a.erase(a.begin());
            } else {
                dest[i++] = b[0];
                b.erase(b.begin());
            }
        }
        if (!a.empty()) {
            for (const auto &x: a) {
                dest[i++] = x;
            }
        }
        if (!b.empty()) {
            for (const auto &x: b) {
                dest[i++] = x;
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0321_H
