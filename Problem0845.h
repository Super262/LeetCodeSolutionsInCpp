//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0845_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0845_H

#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int> &arr) {
        const auto n = (int) arr.size();
        int l_inc[n];
        int r_dec[n];
        memset(l_inc, 0, sizeof l_inc);
        memset(r_dec, 0, sizeof r_dec);
        l_inc[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                l_inc[i] = l_inc[i - 1] + 1;
            } else {
                l_inc[i] = 1;
            }
        }
        r_dec[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] > arr[i + 1]) {
                r_dec[i] = r_dec[i + 1] + 1;
            } else {
                r_dec[i] = 1;
            }
        }
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            if (l_inc[i] <= 1 || r_dec[i] <= 1) {
                continue;
            }
            ans = max(ans, l_inc[i] + r_dec[i] - 1);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0845_H
