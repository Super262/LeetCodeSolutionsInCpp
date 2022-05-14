//
// Created by Fengwei Zhang on 9/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0233_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0233_H

#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 数位DP，必须掌握
    // 设10进制数n共有m位，从高位开始遍历n，设第i位为x，[0:i-1]为left_num，[i+1:m-1]为right_num
    // 我们希望构造a<=n且a[i]=1，答案为a的个数；我们根据x的数值来进行分类讨论；right_num是k位10进制数，设right_base=10^k
    // x=1：若a[0:i-1]=left_num，应使a[i+1:m-1]<=right_num，即0<=a[i+1:m-1]<=right_num，共right_num+1种方案
    //      若0<=a[0:i-1]<=left_num-1，应使0<=a[i+1:m-1]<=right_base-1，共left_num*right_base种方案
    //      综上所述，x=1时，共left_num*right_base+right_num+1种方案
    // x<1：题目要求a<=n，若a[i]=1，则0<=a[0:i-1]<=left_num-1，0<=a[i+1:m-1]<=right_base-1，共left_num*right_base种方案
    // x>1：题目要求a<=n，若a[i]=1，则0<=a[0:i-1]<=left_num，0<=a[i+1:m-1]<=right_base-1，共(left_num+1)*right_base种方案
public:
    int countDigitOne(const int &n) {
        if (n <= 0) {
            return 0;
        }
        vector<int> digits;
        auto t = n;
        while (t > 0) {  // 提取10进制数字n的每位
            digits.emplace_back(t % 10);
            t /= 10;
        }
        reverse(digits.begin(), digits.end());
        int result = 0;
        int left_num = 0;
        auto right_base = (int) pow(10, digits.size() - 1);
        for (const auto &x: digits) {  // 从最高位开始枚举
            auto right_num = n % right_base;
            if (x < 1) {
                result += left_num * right_base;
            } else if (x == 1) {
                result += left_num * right_base + right_num + 1;
            } else {
                result += (left_num + 1) * right_base;
            }
            left_num = left_num * 10 + x;
            right_base /= 10;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0233_H
