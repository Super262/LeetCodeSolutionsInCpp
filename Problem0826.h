//
// Created by Fengwei Zhang on 4/1/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0826_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0826_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 工人和工人间无关，我们可以独立处理每个工人：对每个工人，找到比难度比worker[i]低的、收益最大的工作
    // 不能用暴力法（O(n^2)），需要优化；我们观察到：worker[i]越大，其对应的收益最大值p越大，即p随worker[i]不减，而且每种工作可以被多次完成
    // 因此，我们可以用排序 + 双指针解决
public:
    int maxProfitAssignment(const vector<int> &difficulty, const vector<int> &profit, vector<int> &worker) {
        vector<pair<int, int>> tasks(difficulty.size());
        for (int i = 0; i < (int) difficulty.size(); ++i) {
            tasks[i].first = difficulty[i];
            tasks[i].second = profit[i];
        }
        sort(worker.begin(), worker.end());
        sort(tasks.begin(), tasks.end());
        int ans = 0;
        int prev = 0;
        for (int i = 0, j = 0; i < worker.size(); ++i) {
            while (j < tasks.size() && tasks[j].first <= worker[i]) {
                prev = max(prev, tasks[j].second);
                ++j;
            }
            ans += prev;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0826_H
