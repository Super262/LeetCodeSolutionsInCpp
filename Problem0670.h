//
// Created by Fengwei Zhang on 2/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0670_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0670_H

#include <string>

using namespace std;

class Solution {
    // 经典算法，直接背诵
    // 找到逆序点t（num[t]>num[t-1]），更新t为右侧最大数字的索引；再从最高位开始找到第一个小于num[t]的数字num[j]，交换t、j
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
