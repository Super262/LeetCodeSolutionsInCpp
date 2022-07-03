//
// Created by Fengwei Zhang on 7/3/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0656_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0656_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 由于要找到字典序最小的序列，我们应从后向前逐渐解决子问题；动态规划，f[i]表示从i跳到n-1的最小花费，ne[i]表示i的后继位置
    // f[i]=min({f[i+b]+coins[i+b]})，i+b<=n-1，花费相同时选择字典序较小的
    // 最后从前向后遍历ne，若cur!=n-1且ne[cur]=-1，说明我们无法到达位置n-1，直接返回空数组
public:
    vector<int> cheapestJump(const vector<int> &coins, int b) {
        const auto n = (int) coins.size();
        int f[n];
        int ne[n];
        memset(f, 0x3f, sizeof f);
        memset(ne, -1, sizeof ne);
        f[n - 1] = 0;
        for (auto i = n - 1; i >= 0; --i) {
            for (int j = min(n - 1, i + b); j > i; --j) {
                if (coins[j] == -1) {
                    continue;
                }
                if (f[i] > f[j] + coins[j]) {
                    ne[i] = j;
                    f[i] = f[j] + coins[j];
                } else if (f[i] == f[j] + coins[j] && (ne[i] == -1 || ne[i] > j)) {
                    ne[i] = j;
                }
            }
        }
        vector<int> ans;
        int cur = 0;
        while (cur != n - 1 && ne[cur] != -1) {
            ans.emplace_back(cur + 1);
            cur = ne[cur];
        }
        if (cur != n - 1) {
            return {};
        }
        ans.emplace_back(n);
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0656_H
