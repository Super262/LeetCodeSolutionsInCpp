//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0719_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0719_H

#include <vector>
#include <algorithm>

using namespace std;

class Problem0719 {
    // 贪心：设d是最小的数对距离，易知若(a,b)满足d=b-a，那么a、b在有序数组中相邻；因此，我们可以先将输入的nums排序，再进行其他操作
    // 二分：二分查找d，计算nums中满足b-a>d的数对(a,b)的个数ans；若ans>=k，尝试减少d；我们可以将d逼近到第k个数对距离
public:
    int smallestDistancePair(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = 1e6;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (countPairs(nums, mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }

private:
    int countPairs(const vector<int> &nums, const int d) {
        int res = 0;
        for (int l = 0, r = 1; r < nums.size(); ++r) {
            while (nums[r] - nums[l] > d) {  // 若nums[r]-nums[l]<=d，那么nums[l:r]中满足数对差不大于d的数对(a,nums[r])有(r-l)个
                ++l;
            }
            res += r - l;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0719_H
