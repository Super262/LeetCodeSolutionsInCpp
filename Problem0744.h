//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0744_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0744_H

#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(const vector<char> &letters, const char t) {
        int l = 0;
        auto r = (int) letters.size() - 1;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (letters[mid] > t) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (letters[r] <= t) {
            return letters[0];
        }
        return letters[r];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0744_H
