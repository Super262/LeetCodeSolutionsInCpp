//
// Created by Fengwei Zhang on 2/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0670_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0670_H

#include <string>

using namespace std;

class Solution {
    // 设输入为x，若x中所有位是降序排列的，x就是最大数，即无法通过交换某两位来生成更大的数字；若x的所有位不是严格降序，我们从最高位（0）开始查找第1个逆序点t
    // 找到逆序点t（x[t]>x[t-1]），更新t为右侧最大数字的索引；再从最高位（0）开始找到第一个小于x[t]的数字x[j]，交换x[t]、x[j]
public:
    int maximumSwap(int num) {
        auto str = to_string(num);
        for (int i = 1; i < (int) str.size(); ++i) {
            if (str[i] <= str[i - 1]) {
                continue;
            }
            auto t = i;  // 逆序点
            for (auto j = t + 1; j < (int) str.size(); ++j) {
                if (str[j] < str[t]) {
                    continue;
                }
                t = j;  // 低位部分的最大值
            }
            for (int j = 0; j < t; ++j) {  // 找到高位部分第一个小于num[t]的位置
                if (str[j] >= str[t]) {
                    continue;
                }
                swap(str[j], str[t]);
                return stoi(str);
            }
        }
        return num;  // 数字降序，直接返回
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0670_H
