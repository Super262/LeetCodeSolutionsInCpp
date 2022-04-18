//
// Created by Fengwei Zhang on 4/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0974_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0974_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 模k运算下的前缀和问题：若(s[i] - s[j - 1]) % k == 0，s[i] % k == s[j - 1] % k
public:
    int subarraysDivByK(const vector<int> &nums, int k) {
        const auto n = (int) nums.size();
        int s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        unordered_map<int, int> counter;
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            auto t = (s[i] % k + k) % k;
            ans += counter[t];
            counter[t]++;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0974_H
