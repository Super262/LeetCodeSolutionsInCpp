//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0409_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0409_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 贪心：哈希表统计所有成对出现的字符（频率为偶数）；回文串中至多有1种字符频率为奇数，可将这个字符加入结果
public:
    int longestPalindrome(const string &s) {
        unordered_map<char, int> counter;
        for (const auto &ch: s) {
            ++counter[ch];
        }
        int res = 0;
        for (const auto &item: counter) {
            res += item.second / 2 * 2;  // 统计字符对的数量
        }
        if (res < s.size()) {  // 还可以再加入1个字符作为中心点
            ++res;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0409_H
