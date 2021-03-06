//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0354_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0354_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 1. 排序：消除宽度的影响
    //    对宽度升序，并且在宽度相同时对高度降序的目的：
    //       保证迭代排序后的envelopes时，宽度是非递减的（注意：相邻的两个envelope可能宽度相同）
    //       在相邻两个envelope宽度相同的情况时，两者的高度是非递增的，比如(3, 5), (3, 3), 不会出现“相同高度，后者套前者”的情况。
    // 2. 寻找LIS
    // https://leetcode.cn/problems/russian-doll-envelopes/solution/e-luo-si-tao-wa-xin-feng-wen-ti-by-leetc-wj68/
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        const auto n = (int) envelopes.size();
        int lis_tail[n + 1];
        memset(lis_tail, 0x3f, sizeof lis_tail);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int l = 0;
            auto r = ans;
            while (l < r) {
                auto mid = l + (r - l + 1) / 2;
                if (lis_tail[mid] < envelopes[i][1]) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            ans = max(ans, l + 1);
            if (lis_tail[l + 1] > envelopes[i][1]) {
                lis_tail[l + 1] = envelopes[i][1];
            }
        }
        return ans;
    }

private:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0354_H
