//
// Created by Fengwei Zhang on 2/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0731_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0731_H

#include <map>

using namespace std;

class MyCalendarTwo {
    // 最优解是线段树；本题数据范围小，可以用差分数组解决；为区间(start,end-1)加入事件后，修改头、尾的差分值；差分数组用map实现，保证索引有序
    // 差分数组的前缀和prefix[i]表示时刻i被事件覆盖的次数；我们计算prefix[start]~prefix[end]，若发现prefix[i]>=3，撤销修改，返回false
    // 细节：book(i,j)表示预订了区间(i,j-1)
public:
    MyCalendarTwo() = default;

    bool book(int start, int end) {
        diff[start]++;
        diff[end]--;
        int prefix = 0;  // 当前点被所有日程覆盖的次数
        for (const auto &d: diff) {
            if (d.first >= end) {
                break;
            }
            prefix += d.second;
            if (d.first < start) {
                continue;
            }
            if (prefix >= 3) {
                diff[start]--;
                diff[end]++;
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
