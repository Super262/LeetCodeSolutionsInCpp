//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0514_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0514_H

#include <cstring>
#include <string>

using namespace std;

class Solution {
    // f[i][j]：拼写出key的前i个字符、ring指示在索引为j的位置时的最少操作步数
    // 初始化时，f[0][j]=j；转移时，设第key的第i-1个字符对应ring[k]，设t=abs(j-k)，f[i][j]=min{f[i-1][k]+min(t,n-t)+1}
public:
    int findRotateSteps(const string &ring, const string &key) {
        const auto m = (int) key.size();
        const auto n = (int) ring.size();
        int f[m + 1][n];
        memset(f, 0x3f, sizeof f);
        for (int j = 0; j < n; ++j) {  // 初始化
            f[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (key[i - 1] != ring[j]) {
                    continue;
                }
                for (int k = 0; k < n; ++k) {
                    auto t = abs(j - k);
                    f[i][j] = min(f[i][j], f[i - 1][k] + min(t, n - t) + 1);
                }
            }
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, f[m][i]);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0514_H
