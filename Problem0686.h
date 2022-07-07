//
// Created by Fengwei Zhang on 2/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0686_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0686_H

#include <string>

using namespace std;

class Solution {
    // KMP算法，将a看作是1个"循环字符串"（长度无限）s，我们在s上寻找匹配位置i，s[0:i]是包含b的最短字符串，答案为ceil((i+1)/a.size())
    // 对索引取余，实现循环遍历；若答案存在，那么a的某个后缀一定等于b的某个前缀；因此，i的上限为n=(k+1)*a.size()，k=ceil(b.size()/a.size())
public:
    int repeatedStringMatch(const string &a, const string &b) {
        // 计算n=(ceil(b.size()/a.size())+1)*a.size()
        const auto n = (int) (((b.size() + a.size() - 1) / a.size() + 1) * a.size());
        const auto m = (int) b.size();
        int fail[m];
        buildFail(b, fail);
        int i = 0;
        int j = 0;
        while (i < n) {
            if (a[i % a.size()] == b[j]) {
                ++i;
                ++j;
            } else if (j) {
                j = fail[j - 1];
            } else {
                ++i;
            }
            if (j == m) {
                return (int) ((i + (a.size() - 1)) / a.size());
            }
        }
        return -1;
    }

private:
    void buildFail(const string &s, int fail[]) {
        int l = 0;
        int r = 1;
        fail[l] = 0;
        while (r < (int) s.size()) {
            if (s[r] == s[l]) {
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

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0686_H
