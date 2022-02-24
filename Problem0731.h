//
// Created by Fengwei Zhang on 2/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0731_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0731_H

#include <map>

using namespace std;

class MyCalendarTwo {
    // 最优解是线段树；本题数据范围小，可以用差分数组算法
    // 使用map
public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        ++diff[start];
        --diff[end];
        int counter = 0;  // 当前点被所有日程覆盖的次数
        for (const auto &d: diff) {
            counter += d.second;
            if (counter >= 3) {
                --diff[start];
                ++diff[end];
                return false;
            }
        }
        return true;
    }

private:
    map<int, int> diff;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0731_H
