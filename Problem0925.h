//
// Created by Fengwei Zhang on 4/14/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0925_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0925_H

#include <string>

using namespace std;

class Solution {
public:
    bool isLongPressedName(const string &name, const string &typed) {
        int i = 0;
        int j = 0;
        while (i < name.size() && j < typed.size()) {
            if (name[i] != typed[j]) {
                return false;
            }
            auto x = i + 1;
            auto y = j + 1;
            while (x < name.size() && name[x] == name[i]) {
                ++x;
            }
            while (y < typed.size() && typed[y] == typed[j]) {
                ++y;
            }
            if (x - i > y - j) {
                return false;
            }
            i = x;
            j = y;
        }
        return i == (int) name.size() && j == (int) typed.size();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0925_H
