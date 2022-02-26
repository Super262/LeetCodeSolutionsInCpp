//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0768_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0768_H

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    // 贪心算法：对于分段s，当原数组中这段的数字集合与s的数字集合相等时，s最长
    // 判断区间a、b元素相同：若x在a中出现，cnt[x]--；若x在b出现，cnt[x]++；我们维护非零元素数量s；s=0，说明{a}={b}
public:
    int maxChunksToSorted(const vector<int> &a) {
        auto b = a;
        unordered_map<int, int> counter;
        int res = 0;
        sort(b.begin(), b.end());
        for (const auto &x: a) {  // 初始化
            counter[x] = 0;
        }
        for (int i = 0, s = 0; i < (int) a.size(); ++i) {
            if (counter[a[i]] == 1) {  // 更新后，非零元素减少
                --s;
            } else if (!counter[a[i]]) {  // 更新后，非零元素增加
                ++s;
            }
            --counter[a[i]];
            if (counter[b[i]] == -1) {  // 更新后，非零元素减少
                --s;
            } else if (!counter[b[i]]) {  // 更新后，非零元素增加
                ++s;
            }
            ++counter[b[i]];
            if (!s) {  // 发现{a}={b}
                ++res;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0768_H
