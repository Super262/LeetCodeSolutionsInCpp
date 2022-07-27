//
// Created by Fengwei Zhang on 7/27/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0759_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0759_H

#include <vector>
#include <queue>

using namespace std;

class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

class Problem0759 {
    // 多路归并算法；我们将多个有序的区间序列归并为1个有序序列，在这个过程中得出答案；小根堆保存区间r所在的索引i、j和指向r的只读指针
    // 首先我们将所有员工的第1个区间存入堆，再从堆内弹出最左区间t；将t和当前有序序列尾部prev比较，将prev和t之间的区间存入答案ans
public:
    vector<Interval> employeeFreeTime(const vector<vector<Interval>> &schedule) {
        priority_queue<Node, vector<Node>, greater<Node>> heap;
        for (int i = 0; i < (int) schedule.size(); ++i) {
            heap.push({i, 0, &(schedule[i][0])});
        }
        vector<Interval> ans;
        Interval prev(-1, -1);
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            if (prev.start < 0 || prev.end < t.r->start) {
                if (prev.start >= 0) {
                    ans.emplace_back(prev.end, t.r->start);
                }
                prev = *t.r;
            } else {
                prev.end = max(prev.end, t.r->end);
            }
            if (t.j + 1 < (int) schedule[t.i].size()) {
                heap.push({t.i, t.j + 1, &(schedule[t.i][t.j + 1])});
            }
        }
        return ans;
    }

private:
    struct Node {
        int i;
        int j;  // r=&schedule[i][j]
        const Interval *r;

        bool operator>(const Node &b) const {
            return r->start > b.r->start || (r->start == b.r->start && r->end < b.r->end);
        }
    };
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0759_H
