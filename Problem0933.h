//
// Created by Fengwei Zhang on 4/15/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0933_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0933_H

#include <queue>

using namespace std;

class RecentCounter {
    // 使用队列来维护一个长度为3001ms的滑动窗口
public:
    RecentCounter() = default;

    int ping(int t) {
        while (!q.empty() && t - q.front() > 3000) {
            q.pop();
        }
        q.emplace(t);
        return (int) q.size();
    }

private:
    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0933_H
