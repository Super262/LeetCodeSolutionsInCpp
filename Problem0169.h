//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0169_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0169_H

#include <vector>

using namespace std;

class Solution {
    // 摩尔投票法：统计出现次数超过(n/k)的数
    // 可以证明，出现次数超过(n/k)的数最多只有(k-1)个，因此我们可以使用有限变量来表示这些数x及其出现次数fx
    // 我们遍历数组nums，假设当前遍历到的元素为x：如果x是候选者，++fx；否则，检查是否有候选者的出现次数为0
    // 若有，则让x替代它，设置fx=1；否则，让所有候选者的出现次数减1
    // 当处理完整个数组后，这k−1个数可能会被填满，但不一定都是符合要求的，需要进行二次遍历，来确定候选者是否符合要求，将符合要求的数加到答案
    // 上述做法正确性的关键是：若存在出现次数超过n/k的数，最后必然会成为这k−1个候选者之一
    // https://leetcode.cn/problems/majority-element-ii/solution/gong-shui-san-xie-noxiang-xin-ke-xue-xi-ws0rj/
public:
    int majorityElement(const vector<int> &nums) {
        int x;
        int r = 0;
        for (const auto &num: nums) {
            if (r == 0) {
                x = num;
                r = 1;
                continue;
            }
            if (x == num) {
                ++r;
                continue;
            }
            --r;
        }
        return x;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0169_H
