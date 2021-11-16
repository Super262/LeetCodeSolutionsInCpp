//
// Created by Fengwei Zhang on 11/15/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0258_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0258_H

class Solution {
public:
    int addDigits(int num) {
        // 模9运算等价性：https://www.acwing.com/solution/content/20137/
        if (num == 0) {
            return num;
        }
        if (num % 9 != 0) {
            return num % 9;
        }
        return 9;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0258_H
