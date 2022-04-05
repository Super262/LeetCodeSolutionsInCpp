//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0837_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0837_H

#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
    // 概率题常用思路：找到递推式，依据等式计算最终结果、优化复杂度
    // f[i]：获得分数i的概率（i >= k）；f[i] = (1 / max_pts) * (f[i - max_pts] + ... + f[i - 1])
    // 使用前缀和优化上述计算
public:
    double new21Game(int n, int k, int max_pts) {
        if (!k) {  // 必须判断这个特殊情况
            return 1;
        }
        double prefix[n + 1];
        memset(prefix, 0, sizeof prefix);
        prefix[0] = 1;
        for (int i = 1; i <= n; ++i) {
            auto l = max(0, i - max_pts);
            auto r = min(k - 1, i - 1);
            double f = 0;
            if (l <= r) {
                if (!l) {
                    f = prefix[r] / max_pts;
                } else {
                    f = (prefix[r] - prefix[l - 1]) / max_pts;
                }
            }
            prefix[i] = prefix[i - 1] + f;
        }
        return prefix[n] - prefix[k - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0837_H
