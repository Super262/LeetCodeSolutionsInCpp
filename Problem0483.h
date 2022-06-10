//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0483_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0483_H

#include <string>

using namespace std;

class Solution {
    // 题目要求我们找到最小的进制k，满足"n (base=10)"等于"111...11 (base=k)"
    // 我们从大到小枚举"111...11"的长度m，二分查找最小的k值（2<=k<=n）
public:
    string smallestGoodBase(const string &n) {
        const auto num = stoull(n);
        for (int m = 63; m > 0; --m) {
            unsigned long long l = 2;  // k的下限不能为1，因为不能存在"一进制"
            unsigned long long r = num;
            while (l < r) {
                auto mid = l + (r - l) / 2;
                if (checkBase(num, mid, m) >= 0) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (checkBase(num, r, m) == 0) {
                return to_string(r);
            }
        }
        return n;
    }

private:
    int checkBase(unsigned long long n, unsigned long long base, int m) {  // 检查由m个1组成的base进制数字是否为n
        unsigned long long num = 0;
        for (int i = 0; i < m; ++i) {
            if (num > (n - 1) / base) { // 测试 num * base + 1 > n，避免溢出
                return 1;
            }
            num = num * base + 1;
        }
        if (num == n) {
            return 0;
        }
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0483_H
