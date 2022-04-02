//
// Created by Fengwei Zhang on 4/2/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0829_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0829_H

class Solution {
    // 数学：https://www.acwing.com/solution/content/621/
    // 公差为1的数列首项是x，项数是k，数列和为k*(2*x+k-1)/2；设数列和为n
    // 我们可以枚举2*n的因子，较小因子为k，验证较大因子是否为2*x+k-1
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        for (int k = 1; k <= 2 * n / k; ++k) {
            if (2 * n % k) {
                continue;
            }
            auto y = 2 * n / k;
            if ((y - k + 1) % 2) {
                continue;
            }
            ++ans;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0829_H
