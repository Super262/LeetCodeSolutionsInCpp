//
// Created by Fengwei Zhang on 10/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0038_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0038_H

#include <string>

using namespace std;

class Problem0038 {
public:
    string countAndSay(const int &n) {
        string s = "1";
        for (int i = 0; i < n - 1; ++i) {
            string t;
            for (int j = 0, k = j + 1; j < (int) s.size(); ++j) {
                while (k < (int) s.size() && s[j] == s[k]) {
                    ++k;
                }
                t += to_string(k - j) + s[j];
                j = k - 1;
            }
            s = t;
        }
        return s;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0038_H
