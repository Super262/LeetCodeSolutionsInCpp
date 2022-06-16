//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0502_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0502_H

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
    // 贪心算法：在本金一定时，尽量选择花费最小、收益最大的项目；将profits和capital组合为projects（projects[i]=(capital[i],profits[i])），再排序为升序
    // 初始化大根堆heap，设当前本金为w，当前正处理projects[i]；若projects[i].first（花费）小于w，将projects[i].second（收益）压入heap，递增i，直到i越界或花费超过w
    // 不断重复上述操作，直到被处理的项目个数达到k，或没有待处理的项目（堆为空）
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
        vector<pair<int, int>> projects(profits.size());
        for (int i = 0; i < projects.size(); ++i) {
            projects[i].first = capital[i];
            projects[i].second = profits[i];
        }
        sort(projects.begin(), projects.end(), less<pair<int, int>>());  // 升序排序
        priority_queue<int, vector<int>, less<int>> heap;  // 大根堆
        for (int i = 0, j = 0; j < k; ++j) {
            while (i < (int) projects.size() && projects[i].first <= w) {  // 遍历所有可行项
                heap.emplace(projects[i].second);
                ++i;
            }
            if (heap.empty()) {  // 没有待处理的项目
                return w;
            }
            w += heap.top();
            heap.pop();
        }
        return w;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0502_H
