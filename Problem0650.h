//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0650_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0650_H

class Solution {
    // 经典算法，直接背诵：试除法求解质因子
    // https://www.acwing.com/solution/content/502/
public:
    int minSteps(int n) {
        int ans = 0;
        int f = 2;
        while (n > 1) {
            while (n % f == 0) {
                ans += f;
                n /= f;
            }
            ++f;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0650_H
