//
// Created by Fengwei Zhang on 4/6/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0858_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0858_H

class Solution {
    // 数学方法：https://leetcode-cn.com/problems/mirror-reflection/solution/jing-mian-fan-she-by-leetcode/
public:
    int mirrorReflection(int p, int q) {
        auto h = p * q / gcd(p, q);
        auto x = h / q;
        auto y = h / p;
        if (x % 2) {
            if (y % 2) {
                return 1;
            }
            return 0;
        }
        return 2;
    }

private:
    static int gcd(int a, int b) {
        while (b) {
            auto t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0858_H
