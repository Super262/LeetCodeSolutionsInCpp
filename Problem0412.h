//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0412_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0412_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(const int &n) {
        vector<string> res(n);
        for (int i = 0; i < n; ++i) {
            if ((i + 1) % 15 == 0) {
                res[i] = "FizzBuzz";
            } else if ((i + 1) % 3 == 0) {
                res[i] = "Fizz";
            } else if ((i + 1) % 5 == 0) {
                res[i] = "Buzz";
            } else {
                res[i] = to_string(i + 1);
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0412_H
