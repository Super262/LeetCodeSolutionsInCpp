//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0202_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0202_H

class Problem0202 {
public:
    int squareSum(int x) {
        int result = 0;
        while (x) {
            result += (x % 10) * (x % 10);
            x /= 10;
        }
        return result;
    }

    bool isHappy(int n) {  // 类似于142题（Linked List Cycle II）
        // 注意：这里的快慢指针的起点不能相同
        auto slowP = n;
        auto fastP = squareSum(slowP);
        while (fastP != slowP) {
            slowP = squareSum(slowP);
            fastP = squareSum(squareSum(fastP));
        }
        return fastP == 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0202_H
