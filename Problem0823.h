//
// Created by Fengwei Zhang on 4/1/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0823_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0823_H

#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Problem0823 {
    // 动态规划；f[i]：以有序数组第i个元素为根的树的个数
    // 设d=arr[i]/arr[j]，若arr[i]是arr[j]的倍数，且d存在于arr中，f[i]+=f[j]*f[idx(d)]
    // 由于我们要遍历比当前元素arr[i]小的元素arr[j]，我们应先把arr升序排序，简化搜索过程，同时不增加复杂度
public:
    int numFactoredBinaryTrees(vector<int> &arr) {
        const auto n = (int) arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, int> val_to_idx;
        for (int i = 0; i < n; ++i) {
            val_to_idx[arr[i]] = i;
        }
        int ans = 0;
        const int M = 1e9 + 7;
        int f[n];
        for (int i = 0; i < n; ++i) {
            f[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j]) {
                    continue;
                }
                auto d = arr[i] / arr[j];
                if (!val_to_idx.count(d)) {
                    continue;
                }
                f[i] = (int) ((f[i] + (long long) f[j] * f[val_to_idx[d]]) % M);
            }
            ans = (ans + f[i]) % M;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0823_H
