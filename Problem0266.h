//
// Created by Fengwei Zhang on 5/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0266_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0266_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 直接统计字符频率：频率为奇数的字符最多有1个
public:
    bool canPermutePalindrome(const string &s) {
        unordered_map<char, int> counter;
        for (const auto &ch: s) {
            ++counter[ch];
        }
        bool has_single = false;
        for (const auto &item: counter) {
            if (item.second % 2) {
                if (has_single) {
                    return false;
                }
                has_single = true;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0266_H
