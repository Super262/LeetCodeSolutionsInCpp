//
// Created by Fengwei Zhang on 4/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0996_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0996_H

#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>

using namespace std;

class Solution {
    // 若我们不考虑重复的情况，即假设若排列的下标不同就是不同的排列，得到f个可行的排列，
    // 由排列转组合的经验得知，满足题意的组合的个数是f/{(a!)...(x!)}，a是数字a出现的次数
    // f[s][i]：当前排列包含的数字是s（状态压缩），最后的数字的索引是i，合法的方案数
public:
    int numSquarefulPerms(const vector<int> &nums) {
        const auto n = (int) nums.size();
        int f[1 << n][n];
        int fact[n + 1];
        memset(f, 0, sizeof f);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fact[i] = fact[i - 1] * i;
        }
        for (int i = 0; i < n; ++i) {
            f[1 << i][i] = 1;
        }
        for (int s = 1; s < (1 << n); ++s) {
            for (int i = 0; i < n; ++i) {
                if (!((s >> i) & 1)) {
                    continue;
                }
                for (int j = 0; j < n; ++j) {
                    if (((s >> j) & 1) || !isSquareful(nums[j] + nums[i])) {
                        continue;
                    }
                    f[s | (1 << j)][j] += f[s][i];
                }
            }
        }
        unordered_map<int, int> counter;
        for (const auto &x: nums) {
            counter[x]++;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += f[(1 << n) - 1][i];
        }
        for (const auto &item: counter) {
            ans /= fact[item.second];
        }
        return ans;
    }

private:
    bool isSquareful(int x) {
        auto y = (int) sqrt(x);
        return x == y * y;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0996_H
