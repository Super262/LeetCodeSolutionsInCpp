//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0769_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0769_H

#include <vector>

using namespace std;

class Problem0769 {
    // 设分段{a}排序后为{b}，根据题意，任意长度为l的{b}分段等于{x, x+1, ..., x+l-1}
    // 我们可以用{a}的前缀最大值s来对比当前分段{a}和目标分段{b}，s=l-1时，{a}和{b}的所有元素相同
public:
    int maxChunksToSorted(const vector<int> &a) {
        int ans = 0;
        for (int i = 0, s = -1; i < (int) a.size(); ++i) {
            s = max(s, a[i]);
            if (s == i) {
                ++ans;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0769_H
