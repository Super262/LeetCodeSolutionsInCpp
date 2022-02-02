//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0067_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0067_H

#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res;
        int t = 0;
        for (int i = 0; i < a.size() || i < b.size(); ++i) {
            if (i < a.size()) {
                t += (int) (a[i] - '0');
            }
            if (i < b.size()) {
                t += (int) (b[i] - '0');
            }
            res.push_back((char) (t % 2 + '0'));
            t /= 2;
        }
        if (t) {
            res.push_back((char) (t % 2 + '0'));
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0067_H
