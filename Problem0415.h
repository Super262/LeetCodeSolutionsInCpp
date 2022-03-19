//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0415_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0415_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string addStrings(const string &num1, const string &num2) {
        vector<int> temp;
        temp.reserve(max(num1.size(), num2.size()));
        for (auto i = num1.rbegin(), j = num2.rbegin(); i != num1.rend() || j != num2.rend();) {
            int t = 0;
            if (i != num1.rend()) {
                t += (*i - '0');
                ++i;
            }
            if (j != num2.rend()) {
                t += (*j - '0');
                ++j;
            }
            temp.emplace_back(t);
        }
        string result;
        result.reserve(temp.size());
        int t = 0;
        for (auto d: temp) {
            d += t;
            result.push_back((char) ('0' + d % 10));
            t = d / 10;
        }
        if (t) {
            result.push_back((char) ('0' + t));
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0415_H
