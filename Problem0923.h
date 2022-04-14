//
// Created by Fengwei Zhang on 4/14/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0923_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0923_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 数学法：统计每个数出现的次数，对于每种 x+y+z == target，统计有多少种可能的组合
public:
    int threeSumMulti(const vector<int> &arr, int target) {
        unordered_map<int, int> counter;
        int maximal = INT_MIN;
        int minimal = INT_MAX;
        for (const auto &x: arr) {
            counter[x]++;
            maximal = max(maximal, x);
            minimal = min(minimal, x);
        }
        int ans = 0;
        const int M = 1e9 + 7;
        for (auto x = minimal; x <= target; ++x) {
            for (auto y = x; y <= target - x - y; ++y) {  // 避免重复枚举：x <= y <= z
                auto z = target - x - y;
                if (x == y && y == z) {
                    ans = (int) ((ans + comb(counter[x], 3)) % M);
                    continue;
                }
                if (x == y) {
                    ans = (int) ((ans + comb(counter[x], 2) * counter[z]) % M);
                    continue;
                }
                if (y == z) {
                    ans = (int) ((ans + comb(counter[y], 2) * counter[x]) % M);
                    continue;
                }
                ans = (int) ((ans + (long long) counter[x] * counter[y] * counter[z]) % M);
            }
        }
        return ans;
    }

private:
    static long long comb(long long a, long long b) {  // 在线求解组合数，必须掌握
        long long ans = 1;
        for (auto i = a, j = 1ll; j <= b; --i, ++j) {
            ans = ans * i / j;
        }
        return ans;
    }
};


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0923_H
