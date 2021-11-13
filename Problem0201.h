//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0201_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0201_H

class Solution {
public:
    int rangeBitwiseAnd(const int &m, const int &n) {
        // https://www.acwing.com/solution/content/19514/
        int result = 0;
        for (int i = 30; i >= 0; --i) {
            if ((m >> i & 1) != (n >> i & 1)) {
                break;
            }
            if ((n >> i & 1) == 1) {
                result += (1 << i);
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0201_H
