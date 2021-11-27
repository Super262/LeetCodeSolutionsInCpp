//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0409_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0409_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 理解思路，背诵代码！
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
