//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0769_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0769_H

#include <vector>

using namespace std;

class Solution {
    // 设a排序后为b，根据题意，任意长度为l的b的分段等于{x, x+1, ..., x+l-1}
    // 我们可以用前缀最大值s来对比当前分段和目标分段，s=l-1时，所有元素相同
public:
    int maxChunksToSorted(const vector<int> &a) {
        int res = 0;
        for (int i = 0, s = -1; i < (int) a.size(); ++i) {
            s = max(s, a[i]);
            if (s == i) {
                ++res;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0769_H
