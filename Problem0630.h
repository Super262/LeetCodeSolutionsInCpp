//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0630_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0630_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 经典贪心，必须掌握
    // 类似动态规划的思考方式：https://www.acwing.com/solution/content/526/
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
