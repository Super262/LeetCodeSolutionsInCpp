//
// Created by Fengwei Zhang on 3/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0798_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0798_H

#include <vector>
#include <cstring>

using namespace std;

class Problem0798 {
    // 对于每个数字，求出其可以得分的轮调区间；再通过标记区间所有点的方式，得到被标记次数最多的点；我们通过查分数组实现区间标记
    // 若nums[i]>=n，这个区间不存在；若i<nums[i]<n，得分区间为[i+1,n-nums[i]+i]；若0<=nums[i]<i，得分区间为[0:i-nums[i]]和[i+1,n-1]
    // 对于差分数组，若我们要标记区间[l:r]，执行a[r+1]--、a[l]++
public:
    int bestRotation(const vector<int> &nums) {
        const auto n = (int) nums.size();
        int counter[n + 1];  // 差分数组，记录区间[l:r]被覆盖的次数
        memset(counter, 0, sizeof counter);
        for (int i = 0; i < n; ++i) {
            if (nums[i] > n - 1) {
                continue;
            }
            if (nums[i] > i) {
                ++counter[i + 1];
                --counter[i + n - nums[i] + 1];
            } else {
                ++counter[0];
                --counter[i - nums[i] + 1];
                ++counter[i + 1];
                --counter[n];
            }
        }
        auto score = counter[0];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            counter[i] += counter[i - 1];
            if (score < counter[i]) {
                ans = i;
                score = counter[i];
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0798_H
