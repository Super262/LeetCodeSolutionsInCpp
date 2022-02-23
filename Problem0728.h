
//
// Created by Fengwei Zhang on 2/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0728_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0728_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int x = left; x <= right; ++x) {
            if (checkSelf(x)) {
                res.emplace_back(x);
            }
        }
        return res;
    }

private:
    static bool checkSelf(int x) {
        for (const auto &ch: to_string(x)) {
            if (ch == '0' || x % (ch - '0')) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0728_H
