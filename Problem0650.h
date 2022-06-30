//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0650_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0650_H

class Solution {
    // 试除法求解质因子；假设当前已经得到了n的所有质因数a1，a2，……，ai，n的分解方式可能如下：最后一步必定是由a1次n/a1个"A"操作而成，
    // 倒数第二步一定是由a2次n/(a1*a2)个"A"操作而成，直到第一步为止；可以发现不管分解顺序如何，最终答案都是质因数之和
    // 因此本题的核心思想即粘贴的次数为质数次，否则可以有更有的分解方式；设当前字符串的长度为l，目标长度为l*p；若直接拷贝达到目标长度，需要p次操作
    // 若p是合数，即p=i*j（i>1，j>1），那么可以将拷贝分成2次，先操作i次，再操作j次，这样只需要i+j次操作；显然i*j>=i+j，因此上述思想正确
public:
    int minSteps(int n) {
        int ans = 0;
        int f = 2;
        while (n > 1) {
            while (n % f == 0) {
                ans += f;
                n /= f;
            }
            ++f;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0650_H
