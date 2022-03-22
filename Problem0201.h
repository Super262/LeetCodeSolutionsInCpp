//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0201_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0201_H

class Solution {
    // https://www.acwing.com/solution/content/19514/
public:
    int rangeBitwiseAnd(const int m, const int n) {
        int result = 0;
        for (int i = 30; i >= 0; --i) {
            if (((m >> i) & 1) != ((n >> i) & 1)) {  // 高位不同，说明已达到某个数字的尽头
                return result;
            }
            if (((n >> i) & 1) == 1) {
                result += 1 << i;
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0201_H
