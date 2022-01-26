//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0537_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0537_H

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(const string &x, const string &y) {
        int a, b, c, d;
        sscanf(x.c_str(), "%d+%di", &a, &b);
        sscanf(y.c_str(), "%d+%di", &c, &d);
        return to_string(a * c - b * d) + "+" + to_string(a * d + b * c) + "i";
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0537_H
