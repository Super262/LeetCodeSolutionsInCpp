//
// Created by Fengwei Zhang on 4/15/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0937_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0937_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    // 不能使用sort函数，因为这里要求稳定排序，要使用stable_sort()
    // 注意：STL排序函数的比较器，若返回true，表示a<b成立；返回false，表示a>=b成立
public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        stable_sort(logs.begin(), logs.end(), [&](const string &a, const string &b) {
            auto xa = a.find_first_of(' ');
            auto xb = b.find_first_of(' ');
            auto a_is_d = isdigit(a[xa + 1]);
            auto b_is_d = isdigit(b[xb + 1]);
            if (a_is_d && b_is_d) {
                return false;
            }
            if (a_is_d) {
                return false;
            }
            if (b_is_d) {
                return true;
            }
            auto ida = a.substr(0, xa);
            auto idb = b.substr(0, xb);
            auto sa = a.substr(xa + 1);
            auto sb = b.substr(xb + 1);
            if (sa == sb) {
                return ida < idb;
            }
            return sa < sb;
        });
        return logs;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0937_H
