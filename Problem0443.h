//
// Created by Fengwei Zhang on 12/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0443_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0443_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 双指针经典应用
public:
    int compress(vector<char> &chars) {
        int i = 0;
        for (int l = 0; l < chars.size(); ++l) {
            auto r = l;
            while (r < chars.size() && chars[r] == chars[l]) {
                ++r;
            }
            if (r - l > 0) {
                chars[i] = chars[l];
                ++i;
            }
            if (r - l > 1) {
                // 这里不要使用to_string方法：不满足空间为O(1)
                auto len = r - l;
                auto t = i;
                while (len) {
                    chars[i] = (char) ('0' + (len % 10));
                    len /= 10;
                    ++i;
                }
                reverse(chars.begin() + t, chars.begin() + i);
            }
            l = r - 1;
        }
        while (chars.size() > i) {
            chars.pop_back();
        }
        return (int) chars.size();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0443_H
