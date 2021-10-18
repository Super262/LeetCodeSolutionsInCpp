//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0415_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0415_H

#include <string>
#include <vector>

using namespace std;

class Problem0415 {
public:
    string addStrings(string num1, string num2) {
        vector<int> temp;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num1.size() || i < num2.size(); ++i) {
            int t = 0;
            if (i < num1.size()) {
                t += (num1[i] - '0');
            }
            if (i < num2.size()) {
                t += (num2[i] - '0');
            }
            temp.emplace_back(t);
        }
        string result;
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
