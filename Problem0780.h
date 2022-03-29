//
// Created by Fengwei Zhang on 3/28/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0780_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0780_H

class Solution {
    // 辗转相除：https://www.acwing.com/solution/content/8753/
    // 技巧：用取模运算替代减法运算，避免超时
    // 根据题意，整个变换过程中，所有可能的(x,y)满足x>=0且y>=0
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == ty) {
                break;
            }
            if (tx > ty) {
                if (ty > sy) {
                    tx %= ty;
                } else {
                    return (tx - sx) % ty == 0;
                }
            } else {
                if (tx > sx) {
                    ty %= tx;
                } else {
                    return (ty - sy) % tx == 0;
                }
            }
        }
        return sx == tx && sy == ty;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0780_H
