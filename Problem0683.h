//
// Created by Fengwei Zhang on 7/4/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0683_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0683_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 设数组ft的前缀和为prefix，prefix[i]=sum(ft[1:i])；我们将灯泡亮起的位置ft[bulbs[i]]设置为"1"，不亮的位置为"0"；
    // 若j-i=k+1且prefix[j-1]=prefix[i]，说明i、j中间恰好有k个"0"；若ft[i]=ft[j]=1且prefix[j-1]=prefix[i]，说明位置i即为答案
    // 我们用树状数组实现动态修改、查询前缀和，从前到后遍历bulbs，找到最小的满足题意的天数i
public:
    int kEmptySlots(const vector<int> &bulbs, int k) {
        const auto n = (int) bulbs.size();
        int ft[n + 1];
        bool working[n + 1];
        memset(ft, 0, sizeof ft);
        memset(working, 0, sizeof working);
        for (int i = 0; i < n; ++i) {
            update(bulbs[i], 1, n, ft);
            working[bulbs[i]] = true;
            if (bulbs[i] - k - 1 >= 1) {
                if (working[bulbs[i] - k - 1] && prefixSum(bulbs[i] - k - 1, ft) == prefixSum(bulbs[i] - 1, ft)) {
                    return i + 1;
                }
            }
            if (bulbs[i] + k + 1 <= n) {
                if (working[bulbs[i] + k + 1] && prefixSum(bulbs[i] + k, ft) == prefixSum(bulbs[i], ft)) {
                    return i + 1;
                }
            }
        }
        return -1;
    }

private:
    int prefixSum(int idx, const int ft[]) {
        int ans = 0;
        for (int i = idx; i > 0; i -= lowBit(i)) {
            ans += ft[i];
        }
        return ans;
    }

    void update(int idx, int inc, int n, int ft[]) {
        for (auto i = idx; i <= n; i += lowBit(i)) {
            ft[i] += inc;
        }
    }

    int lowBit(int x) {
        return x & -x;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0683_H
