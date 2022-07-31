//
// Created by Fengwei Zhang on 2/27/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0779_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0779_H

class Problem0779 {
    // 经观察，我们发现任意行s，s左部与前行相等，右部为左部按位取反后的结果；因此我们可以递归处理，这里使用迭代模拟递归
public:
    int kthGrammar(int n, int k) {
        int ans = 0;
        while (n > 1) {
            int mid = 1 << (n - 2);  // 第n行的长度是1<<(n-1)，那么左半部的长度就是1<<(n-2)
            if (k > mid) {  // k在在第n行的右半部
                ans ^= 1;  // 取反的逆运算也是取反
                k -= mid;
            }
            --n;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0779_H
