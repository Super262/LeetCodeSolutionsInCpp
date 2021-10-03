//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0067_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0067_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Problem0067 {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string result;
        for (int i = 0, t = 0; i < a, size() || i < b.size(); ++i) {
            if (i < a.size()) {
                t += (int) (a[i] - '0');
            }
            if (i < b.size()) {
                t += (int) (b[i] - '0');
            }
            result.push_back((char) (t % 10 + '0'));
            t /= 10;
        }
        if (t) {
            result.push_back((char) (t % 10 + '0'));
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0067_H
