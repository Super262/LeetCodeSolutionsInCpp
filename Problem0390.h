//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0390_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0390_H

class Solution {
    // https://www.acwing.com/solution/content/14240/
    // f(n) 代表将1-n先从左到右再从右到左遍历最后剩下来的数字
    // b(n) 代表将1-n先从右到左再从左到右遍历最后剩下来的数字
    // f(1) = 1, b(1) = 1; f(n) = 2 * b(n / 2); f(n) + b(n) = n + 1
public:
    int lastRemaining(const int &n) {
        if (n == 1) {
            return 1;
        }
        return 2 * (n / 2 + 1 - lastRemaining(n / 2));
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0390_H
