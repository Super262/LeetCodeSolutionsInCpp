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
        int k = 0;
        for (int l = 0; l < chars.size(); ++l) {
            auto r = l;
            while (r < chars.size() && chars[r] == chars[l]) {
                ++r;
            }
            if (r - l > 0) {
                chars[k] = chars[l];
                ++k;
            }
            if (r - l > 1) {
                auto temp = to_string(r - l);
                for (const auto &ch: temp) {
                    chars[k] = ch;
                    ++k;
                }
            }
            l = r - 1;
        }
        while (chars.size() > k) {
            chars.pop_back();
        }
        return (int) chars.size();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0443_H
