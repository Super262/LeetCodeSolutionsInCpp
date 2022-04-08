//
// Created by Fengwei Zhang on 4/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0873_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0873_H

#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

class Solution {
    // 类比最长上升子序列：由于Fib序列[a,b,c]需要满足c=a+b，我们定义转移方程f[i][j]，arr[i]、arr[j]是Fib序列最后的2个数
public:
    int lenLongestFibSubseq(const vector<int> &arr) {
        unordered_map<int, int> pos;
        const auto n = (int) arr.size();
        for (int i = 0; i < n; ++i) {
            pos[arr[i]] = i;
        }
        int f[n][n];
        memset(f, 0, sizeof f);
        int ans = 0;
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                f[i][j] = 2;
                auto x = arr[j] - arr[i];
                if (pos.count(x) && pos[x] < i) {
                    f[i][j] = max(f[i][j], f[pos[x]][i] + 1);
                }
                ans = max(ans, f[i][j]);
            }
        }
        if (ans < 3) {
            return 0;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0873_H
