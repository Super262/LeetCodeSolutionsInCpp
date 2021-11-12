//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0165_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0165_H

#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(const string &version1, const string &version2) {
        int i = 0;
        int j = 0;
        while (i < version1.size() || j < version2.size()) {
            auto a = i;
            auto b = j;
            while (a < version1.size() && version1[a] != '.') {
                ++a;
            }
            while (b < version2.size() && version2[b] != '.') {
                ++b;
            }
            int x = a > i ? stoi(version1.substr(i, a - i)) : 0;
            int y = b > j ? stoi(version2.substr(j, b - j)) : 0;
            if (x < y) {
                return -1;
            } else if (x > y) {
                return 1;
            }
            i = a + 1;
            j = b + 1;
        }
        return 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0165_H
