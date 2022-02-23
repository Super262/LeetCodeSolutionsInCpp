//
// Created by Fengwei Zhang on 2/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0729_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0729_H

#include <set>
#include <algorithm>

using namespace std;

class MyCalendar {
    // 区间问题，细节：2个哨兵结点（-INF和INF）
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

    static bool hasIntersection(pair<int, int> a, pair<int, int> b) {  // 判断a、b是否相交，注意细节
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
