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
    // 根据题意，在任意时段，我们只能执行1个程序；若当前正执行程序a，新程序b开始执行，我们需要将a入栈，并记录a的执行时长
    // 我们维护栈stk和变量last；新程序启动时，我们入栈新程序，更新last为当前时刻，并记录上个程序的执行时长
    // 某个程序终止时，我们记录上个程序的执行时长，弹出栈顶，更新last为下个时刻
public:
    vector<int> exclusiveTime(const int n, const vector<string> &logs) {
        vector<int> ans(n, 0);
        stack<int> stk;
        int last = 0;
        for (const auto &log: logs) {
            auto c1 = log.find_first_of(':');
            auto c2 = log.find_last_of(':');
            auto id = stoi(log.substr(0, c1));
            auto t = stoi(log.substr(c2 + 1));
            if (log.substr(c1 + 1, c2 - c1 - 1) == "start") {
                if (!stk.empty()) {
                    ans[stk.top()] += t - last;
                }
                last = t;
                stk.emplace(id);
            } else {
                ans[stk.top()] += t - last + 1;
                stk.pop();
                last = t + 1;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0636_H
