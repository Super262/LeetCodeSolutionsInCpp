//
// Created by Fengwei Zhang on 12/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0443_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0443_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 双指针：i指示当前的可写位置，chars[l:r]是一段重复字符，我们在chars[i]保存当前字符
    // 当chars[l:r]长度大于1时，我们将数字(r-l+1)存储到i后面的可写位置，然后更新l=r-1，处理新字符
    // 细节：由于这里要求我们使用O(1)空间，我们不能使用to_string函数
public:
    int compress(vector<char> &chars) {
        int i = 0;
        for (int l = 0; l < (int) chars.size(); ++l) {
            auto r = l;
            while (r < (int) chars.size() && chars[r] == chars[l]) {
                ++r;
            }
            if (r - l > 0) {
                chars[i] = chars[l];
                ++i;
            }
            if (r - l > 1) {
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
        chars.erase(chars.begin() + i, chars.end());
        return i;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0443_H
