//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0424_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0424_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 双指针：设目标字符是ch，我们要找到最长的区间[l:r]，区间[l:r]最多包含k个不是ch的字符
    // 我们可以暴力枚举所有可能的ch（'A'～'Z'），也可以贪心优化：目标字符ch必是当前窗口内频率最高的字符，所以我们只关注字符频率的最大值
public:
    int characterReplacement(const string &s, const int &k) {
        int counter[26];
        int l = 0;
        int r = 0;
        int max_f = 0;
        memset(counter, 0, sizeof counter);
        while (r < (int) s.size()) {
            ++counter[s[r] - 'A'];
            max_f = max(max_f, counter[s[r] - 'A']);
            while (r - l + 1 - max_f > k) {  // 这里写if也可以，因为这个循环最多被执行1次
                --counter[s[l] - 'A'];
                ++l;
            }
            ++r;
        }
        return r - l;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0424_H
