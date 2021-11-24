//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0344_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0344_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        int l = 0;
        int r = (int) s.size() - 1;
        while (l < r) {
            swap(s[l], s[r]);
            ++l;
            --r;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0344_H
