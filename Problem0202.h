//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0202_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0202_H

class Solution {
    // 经典算法，直接背诵：若两指针相遇时均为1，说明不存在环；若两指针相遇时均不为1，则表示存在环
    // 类似于142题（Linked List Cycle II）：https://www.acwing.com/solution/content/19516/
public:
    bool isHappy(const int n) {
        auto slow = n;
        auto fast = n;
        do {
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        } while (fast != slow);
        return fast == 1;
    }

private:
    int squareSum(int x) {
        int ans = 0;
        while (x) {
            ans += (x % 10) * (x % 10);
            x /= 10;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0202_H
