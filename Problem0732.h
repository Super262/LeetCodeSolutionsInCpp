//
// Created by Fengwei Zhang on 2/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0732_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0732_H

#include <map>

using namespace std;

class MyCalendarThree {
public:
    MyCalendarThree() {

    }

    int book(int start, int end) {
        ++diff[start];
        --diff[end];
        int counter = 0;
        int res = 0;
        for (const auto &d: diff) {
            counter += d.second;
            res = max(res, counter);
        }
        return res;
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
