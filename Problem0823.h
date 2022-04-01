//
// Created by Fengwei Zhang on 4/1/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0823_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0823_H

#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        const auto n = (int) arr.size();
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
