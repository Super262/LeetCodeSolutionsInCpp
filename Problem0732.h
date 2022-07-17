//
// Created by Fengwei Zhang on 2/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0732_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0732_H

#include <map>

using namespace std;

class MyCalendarThree {
public:
    MyCalendarThree() = default;

    int book(int start, int end) {
        ++diff[start];
        --diff[end];
        int prefix = 0;
        int ans = 0;
        for (const auto &d: diff) {
            prefix += d.second;
            ans = max(ans, prefix);
        }
        return ans;
    }

private:
    map<int, int> diff;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0732_H
