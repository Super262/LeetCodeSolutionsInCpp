//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0202_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0202_H

class Solution {
    // 经典算法，直接背诵
    // 类似于142题（Linked List Cycle II）
public:
    bool isHappy(const int n) {
        // 注意：这里的快慢指针的起点不能相同
        auto slow = n;
        auto fast = squareSum(slow);
        while (fast != slow) {
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        }
        return fast == 1;
    }

private:
    int squareSum(int x) {
        int result = 0;
        while (x) {
            result += (x % 10) * (x % 10);
            x /= 10;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0202_H
