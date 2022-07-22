//
// Created by Fengwei Zhang on 2/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0754_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0754_H

#include <cmath>

using namespace std;

class Problem0754 {
    // 假设我们移动了k次，每次任意地向左或向右移动，那么最终到达的位置实际上就是将1，2，3，……，k这k个数添加正号或负号后求和的值
    // 若最终到达的位置为t且t<0，那么我们可以将这k个数的负号全部取反，这样求和的值为-t>0。因此，我们只考虑target>0的情况
    // 首先，我们要求出最小的满足s=1+2+3+...+k>=target的k值；若s=target，那么答案就是k；若s>target，那么我们应将部分数字设置为负数
    // 设D=a+b+...+x，若更改a～x的符号为负号后满足s=target，说明target=s-2*D；因此，我们给s增加k，直到当2*D为偶数时，存在使得s=target的方案
public:
    int reachNumber(int target) {
        if (target == 0) {
            return 0;
        }
        target = abs(target);  // target的正、负情况对结果没有影响
        auto k = (int) sqrt(2ll * target) - 1;
        while ((k + 1ll) * k / 2 < target) {  // 利用求和公式找到满足 s = k*(k+1)/2 >= target 的最小k
            ++k;
        }
        auto d = (int) ((k + 1ll) * k / 2 - target);  // 设D=(a+b+c+...+x)，若更改a～x的符号为负号后满足题意，则target=s-2*D
        while (d % 2) {
            ++k;
            d += k;
        }
        return k;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0754_H
