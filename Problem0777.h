//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0777_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0777_H

#include <string>

using namespace std;

class Solution {
    // L、R相对顺序不变的必要条件：删除X后，start=end；在操作过程中，L只能向左，R只能向右
public:
    bool canTransform(const string &start, const string &end) {
        string a;
        string b;
        a.reserve(start.size());
        b.reserve(end.size());
        for (const auto &ch: start) {
            if (ch == 'X') {
                continue;
            }
            a += ch;
        }
        for (const auto &ch: end) {
            if (ch == 'X') {
                continue;
            }
            b += ch;
        }
        if (a != b) {
            return false;
        }
        for (int i = 0, j = 0; i < start.size() && j < end.size(); ++i, ++j) {
            while (i < start.size() && start[i] != 'L') {
                ++i;
            }
            while (j < end.size() && end[j] != 'L') {
                ++j;
            }
            if (i < j) {
                return false;
            }
        }
        for (int i = (int) start.size() - 1, j = (int) end.size() - 1; i >= 0 && j >= 0; --i, --j) {
            while (i >= 0 && start[i] != 'R') {
                --i;
            }
            while (j >= 0 && end[j] != 'R') {
                --j;
            }
            if (i > j) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0777_H
