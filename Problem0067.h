//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0067_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0067_H

#include <string>

using namespace std;

class Problem0067 {
    // 类似大整数加法：从低位到高位依次进位
public:
    string addBinary(const string &a, const string &b) {
        string res;
        res.reserve(max(a.size(), b.size()));
        int t = 0;
        for (int i = 1; i <= a.size() || i <= b.size() || t; ++i) {
            if (i <= a.size()) {
                t += (int) (a[a.size() - i] - '0');
            }
            if (i <= b.size()) {
                t += (int) (b[b.size() - i] - '0');
            }
            res += (char) (t % 2 + '0');
            t /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0067_H
