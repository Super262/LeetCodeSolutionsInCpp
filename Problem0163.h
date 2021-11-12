//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0163_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0163_H

#include <vector>
#include <string>

using namespace std;

class Problem0163 {
public:
    vector<string> findMissingRanges(const vector<int> &nums, int lower, int upper) {
        vector<string> result;
        for (const int &x: nums) {
            if (x == lower) {
                ++lower;
            } else {
                result.emplace_back(createRange(lower, x - 1));
                lower = x + 1;
            }
        }
        if (lower <= upper) {
            result.emplace_back(createRange(lower, upper));
        }
        return result;
    }

private:
    string createRange(const int &lower, const int &upper) {
        if (lower == upper) {
            return to_string(lower);
        }
        return to_string(lower) + "->" + to_string(upper);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0163_H
