//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0374_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0374_H

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 */
int guess(int num);

class Solution {
    // 一定要使用二分法，否则会超时
public:
    int guessNumber(const int &n) {
        int l = 1;
        int r = n;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            auto t = guess(mid);
            if (t == 0) {
                return mid;
            } else if (t == -1) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0374_H
