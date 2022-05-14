//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0214_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0214_H

#include <string>

using namespace std;

class Solution {
    // 加强对KMP算法的理解，背诵代码：https://www.acwing.com/solution/content/19819/
    // 设输入为s，我们在头部添加的字符串为a，最终结果为ans=a+s；进一步分析，我们发现ans=a+c+a'，设c是某个回文串，a'是a的反序
    // 因此，我们需要在s中找到最长的前缀，该前缀是回文串（c），这样会使得a最短；我们可以利用KMP算法的性质解决问题
public:
    string shortestPalindrome(const string &s) {
        const string temp = s + "#" + string(s.rbegin(), s.rend());  // 关键操作
        const auto m = (int) temp.size();
        int fail[m];
        buildFail(temp, fail);
        auto left = s.substr(0, fail[m - 1]);
        auto right = s.substr(fail[m - 1]);
        return string(right.rbegin(), right.rend()) + left + right;
    }

private:
    void buildFail(const string &s, int fail[]) {
        int l = 0;
        int r = 1;
        fail[l] = 0;
        while (r < (int) s.size()) {
            if (s[l] == s[r]) {
                ++l;
                fail[r] = l;
                ++r;
            } else if (l) {
                l = fail[l - 1];
            } else {
                fail[r] = 0;
                ++r;
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0214_H
