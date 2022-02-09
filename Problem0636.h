//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0636_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0636_H

#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(const int n, const vector<string> &logs) {
        vector<int> res(n, 0);
        stack<int> stk;
        int last = 0;
        for (const auto &log: logs) {
            auto c1 = log.find_first_of(':');
            auto c2 = log.find_last_of(':');
            auto id = stoi(log.substr(0, c1));
            auto t = stoi(log.substr(c2 + 1));
            if (log.substr(c1 + 1, c2 - c1 - 1) == "start") {
                if (!stk.empty()) {
                    res[stk.top()] += t - last;
                }
                last = t;
                stk.emplace(id);
            } else {
                res[stk.top()] += t - last + 1;
                stk.pop();
                last = t + 1;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0636_H
