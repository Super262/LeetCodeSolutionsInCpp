//
// Created by Fengwei Zhang on 4/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1006_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1006_H

class Problem1006 {
    // 直接模拟，根据余数处理尾部
public:
    int clumsy(int n) {
        int ans = 0;
        int t = 1;  // 每组头部的符号
        for (auto x = n; x >= 4; x -= 4, t = -1) {  // 4数字个1组
            auto a = x * t;
            auto b = x - 1;
            auto c = x - 2;
            auto d = x - 3;
            ans += a * b / c + d;
        }
        auto k = n % 4;  // 余数
        if (k == 1) {
            return ans + t * 1;
        }
        if (k == 2) {
            return ans + t * 2 * 1;
        }
        if (k == 3) {
            return ans + t * 3 * 2 / 1;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1006_H
