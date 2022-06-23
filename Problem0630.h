//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0630_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0630_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 贪心算法，假设现在有2节课，(d1,t1)、(d2,t2)，t1<t2；若d1+d2<=t1，可以任意安排这2节课；若d1+d2>t1且d1+d2<=t2，应先上第1节课，再上第2节课
    // 若d1+d2>t2，只能上1门课，即时间最短的课；因此，我们可以按照课程的结束时间对所有课程排序，用大根堆记录被选择的课程的时长
    // 从头遍历课程，维护总的上课时间total；设当前课程为(di,ti)，若total+di<=ti，证明当前课程可选；若total+di>ti，若堆顶课程耗时更长，则用当前课程替换堆顶课程
public:
    int scheduleCourse(vector<vector<int>> &courses) {
        sort(courses.begin(), courses.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        priority_queue<int, vector<int>, less<int>> heap;
        int total = 0;
        for (const auto &c: courses) {
            if (total + c[0] <= c[1]) {
                total += c[0];
                heap.emplace(c[0]);
            } else {
                if (!heap.empty() && heap.top() > c[0]) {
                    total -= heap.top() - c[0];
                    heap.pop();
                    heap.emplace(c[0]);
                }
            }
        }
        return (int) heap.size();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0630_H
