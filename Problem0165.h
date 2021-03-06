//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0165_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0165_H

#include <string>

using namespace std;

class Solution {
    // 版本号形如"a.b"，对于2个版本号v1、v2，我们分别比较它们的a部分，然后再比较b部分
public:
    int compareVersion(const string &ver1, const string &ver2) {
        int i = 0;
        int j = 0;
        while (i < ver1.size() || j < ver2.size()) {
            auto a = i;
            auto b = j;
            while (a < ver1.size() && ver1[a] != '.') {
                ++a;
            }
            while (b < ver2.size() && ver2[b] != '.') {
                ++b;
            }
            int x = a > i ? stoi(ver1.substr(i, a - i)) : 0;
            int y = b > j ? stoi(ver2.substr(j, b - j)) : 0;
            if (x < y) {
                return -1;
            }
            if (x > y) {
                return 1;
            }
            i = a + 1;
            j = b + 1;
        }
        return 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0165_H
