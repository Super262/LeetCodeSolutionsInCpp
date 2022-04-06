//
// Created by Fengwei Zhang on 4/6/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0857_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0857_H

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
    // 根据题目要求，被选取的k名工人的薪资应满足 quality[i] * t >= wage[i]
    // 因此，为了尽可能减少工资总数，我们应选取最小的t：枚举所有可能的t，选取k个最小薪资的工人
public:
    double mincostToHireWorkers(const vector<int> &quality, const vector<int> &wage, int k) {
        const auto n = (int) quality.size();
        pair<double, int> workers[n];
        for (int i = 0; i < n; ++i) {
            workers[i].first = (double) wage[i] / quality[i];
            workers[i].second = quality[i];
        }
        sort(workers, workers + n);
        priority_queue<int, vector<int>, greater<int>> heap;  // 大顶堆
        auto sum = 0;
        double ans = 0x3f3f3f3f;
        for (const auto &w: workers) {
            heap.emplace(w.second);
            sum += w.second;
            if (heap.size() > k) {
                sum -= heap.top();
                heap.pop();
            }
            if (heap.size() == k) {
                ans = min(ans, sum * w.first);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0857_H
