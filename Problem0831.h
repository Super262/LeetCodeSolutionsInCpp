//
// Created by Fengwei Zhang on 4/4/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0831_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0831_H

#include <string>

using namespace std;

class Solution {
public:
    string maskPII(const string &s) {
        if (s.find_first_of('@') != string::npos) {
            return maskEmail(s);
        }
        return maskPhone(s);
    }

private:
    static string maskEmail(const string &s) {
        auto a_idx = s.find_first_of('@');
        auto d_idx = s.find_first_of('.');
        // 将s分成3段，全部转换为小写字母
        auto s1 = (char) tolower(s[0]) + string(5, '*') + (char) tolower(s[a_idx - 1]);
        auto s2 = s.substr(a_idx + 1, d_idx - a_idx - 1);
        auto s3 = s.substr(d_idx + 1);
        for (auto &ch: s2) {
            if (islower(ch)) {
                continue;
            }
            ch = (char) tolower(ch);
        }
        for (auto &ch: s3) {
            if (islower(ch)) {
                continue;
            }
            ch = (char) tolower(ch);
        }
        return s1 + '@' + s2 + '.' + s3;
    }

    static string maskPhone(const string &s) {
        string digits;
        for (const auto &ch: s) {
            if (!isdigit(ch)) {
                continue;
            }
            digits += ch;
        }
        if (digits.size() == 10) {  // 没有国家代码
            return "***-***-" + digits.substr(6);
        }
        return '+' + string(digits.size() - 10, '*') + "-***-***-" + digits.substr(digits.size() - 4);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0831_H
