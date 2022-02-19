//
// Created by Fengwei Zhang on 2/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0682_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0682_H

#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Solution {
    // 技巧：accumulate函数求和
public:
    int calPoints(const vector<string> &ops) {
        vector<int> stk;
        for (const auto &x: ops) {
            auto p = (int) stk.size() - 1;
            if (x == "+") {
                stk.emplace_back(stk[p - 1] + stk[p]);
            } else if (x == "D") {
                stk.emplace_back(2 * stk[p]);
            } else if (x == "C") {
                stk.pop_back();
            } else {
                stk.emplace_back(stoi(x));
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0682_H
