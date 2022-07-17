//
// Created by Fengwei Zhang on 2/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0729_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0729_H

#include <set>
#include <algorithm>

using namespace std;

class MyCalendar {
    // 我们用平衡树（set）保存区间；设当前区间为t=(start,end)，通过二分查找（lower_bound），找到可能和t相交的区间i、i-1
    // 细节：初始化时，向集合加入2个"哨兵"，使得所有查找操作不会返回"空值"；查找距离t最近的区间时，关键字为(start,-INF)
public:
    MyCalendar() {
        s.insert({-INF, -INF});
        s.insert({INF, INF});
    }

    bool book(int start, int end) {
        auto i = s.lower_bound({start, -INF});
        auto j = i;
        --j;
        pair<int, int> t(start, end);
        if (hasIntersection(t, *i) || hasIntersection(t, *j)) {
            return false;
        }
        s.insert(t);
        return true;
    }

private:
    set<pair<int, int>> s;
    static const int INF = 0x3f3f3f3f;

    static bool hasIntersection(const pair<int, int> &a, const pair<int, int> &b) {  // 判断a、b是否相交，注意细节
        if (a.second <= b.first || b.second <= a.first) {
            return false;
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0729_H
