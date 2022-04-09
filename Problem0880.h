//
// Created by Fengwei Zhang on 4/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0880_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0880_H

#include <string>

using namespace std;

class Solution {
    // 模拟
public:
    string decodeAtIndex(const string &s, int k) {
        unsigned long long decoded_length = 0;
        for (const auto &ch: s) {
            if (isdigit(ch)) {
                decoded_length *= ch - '0';
            } else {
                ++decoded_length;
            }
        }
        for (auto i = (int) s.size() - 1; i >= 0; --i) {
            k = (int) (k % decoded_length);
            if (isdigit(s[i])) {
                decoded_length /= s[i] - '0';
                continue;
            }
            if (!k) {
                return string(1, s[i]);
            }
            --decoded_length;
        }
        return "";
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0880_H
