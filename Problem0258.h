//
// Created by Fengwei Zhang on 11/15/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0258_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0258_H

class Solution {
    // 模9运算等价性：https://www.acwing.com/solution/content/20137/
    // 若x="abc..."，x=a*(10^n)+b*(10^(n-1))+c*(10^(n-2))+...，x%9=a+b+c+...，；因此，题目要求的运算等价于"模9"
public:
    int addDigits(int num) {
        if (num == 0) {
            return 0;
        }
        if (num % 9 != 0) {
            return num % 9;
        }
        return 9;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0258_H
