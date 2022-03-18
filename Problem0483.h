//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0483_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0483_H

#include <string>

using namespace std;

class Solution {
    // 发现(111...11)(base=k)随k递增而递增：二分查找，注意溢出处理
public:
    string smallestGoodBase(const string &n) {
        const auto num = stoull(n);
        for (int k = 63; k > 0; --k) {
            unsigned long long l = 2, r = num;  // 注意：l等于2，千万不要写成1
            while (l < r) {
                auto mid = l + (r - l) / 2;
                if (checkBase(num, mid, k) >= 0) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (checkBase(num, r, k) == 0) {
                return to_string(r);
            }
        }
        return n;
    }

private:
    int checkBase(unsigned long long n, unsigned long long base, int k) {  // 检查由k个1组成的base进制数字是否为n
        unsigned long long res = 0;
        for (int i = 0; i < k; ++i) {
            if (res > (n - 1) / base) { // 测试 res * base + 1 > n，避免溢出
                return 1;
            }
            res = res * base + 1;
        }
        if (res == n) {
            return 0;
        }
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0483_H
