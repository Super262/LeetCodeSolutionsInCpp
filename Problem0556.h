//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0556_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0556_H

#include <string>

using namespace std;

class Solution {
    // 直接背诵：类似LeetCode 31的做法
public:
    int nextGreaterElement(int n) {
        auto s = to_string(n);
        auto k = (int) s.size() - 1;
        while (k && s[k - 1] >= s[k]) {  // 寻找递减序列的起点
            --k;
        }
        if (!k) { // 当前数已经是最大数
            return -1;
        }
        auto t = k;
        while (t + 1 < s.size() && s[t + 1] > s[k - 1]) {  // 在递减序列中找到比s[k-1]大的最小数
            ++t;
        }
        swap(s[k - 1], s[t]);
        reverse(s.begin() + k, s.end());
        auto res = stoll(s);  // 检测溢出，暂存在long long变量里
        if (res > INT_MAX) {
            return -1;
        }
        return (int) res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0556_H
