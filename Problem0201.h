//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0201_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0201_H

class Solution {
    // 对于二进制数m、n，因为m<n，存在第i位，m[i] = 0 且 n[i] = 1，并且m[0:i-1] = n[0:i-1]
    // m可表示为"xxx1..."，n可表示为"xxx0..."，因此存在数字t（m<=t<=n），t可表示为"xxx10...0"（低位全部为0）
    // 因此，我们需要求m、n的公共前缀
    // https://www.acwing.com/solution/content/19514/
public:
    int rangeBitwiseAnd(const int m, const int n) {
        int ans = 0;
        for (int i = 30; i >= 0; --i) {
            if (((m >> i) & 1) != ((n >> i) & 1)) {  // 高位不同，说明已达到某个数字的尽头
                return ans;
            }
            if (((n >> i) & 1) == 1) {
                ans += 1 << i;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0201_H
