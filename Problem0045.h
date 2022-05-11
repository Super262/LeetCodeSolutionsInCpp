//
// Created by Fengwei Zhang on 10/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0045_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0045_H

#include <vector>

using namespace std;

class Solution {
    // DP + 贪心：f[i]表示到达i所需要的最少步数；last为第一次到达i时，上一步所在的索引；f[i] = f[last] + 1
    // https://www.acwing.com/solution/content/107/
public:
    int jump(const vector<int> &nums) {
        const auto n = (int) nums.size();
        int f[n];
        f[0] = 0;
        for (int i = 1, last = 0; i < n; ++i) {
            while (last < i && last + nums[last] < i) {  // 找到最近的last
                ++last;
            }
            f[i] = f[last] + 1;
        }
        return f[n - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0045_H
