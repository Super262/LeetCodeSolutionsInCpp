//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0777_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0777_H

#include <string>

using namespace std;

class Problem0777 {
    // 经观察，我们可以得出L、R相对顺序不变的必要条件：删除X后，start=end成立；由题意可知，每次操作后，L只能向左，R只能向右
    // 因此，我们首先比较删去"X"后的字符串，再判断变换后的"L"是否未向右、变换后的"R"是否未向左
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
        for (int i = 0, j = 0; i < (int) start.size() && j < (int) end.size(); ++i, ++j) {
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
