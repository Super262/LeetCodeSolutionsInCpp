//
// Created by Fengwei Zhang on 12/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0470_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0470_H

// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

class Solution {
    // https://leetcode-cn.com/problems/implement-rand10-using-rand7/solution/yong-rand7-shi-xian-rand10-by-leetcode-s-qbmd/
public:
    int rand10() {
        int value = 49;
        while (true) {
            auto row_idx = rand7() - 1;
            auto col_idx = rand7() - 1;
            value = row_idx * 7 + col_idx;
            if (value < 40) {
                break;
            }
        }
        return value % 10 + 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0470_H
