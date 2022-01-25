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
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
        vector<pair<int, int>> projects(profits.size());
        for (int i = 0; i < projects.size(); ++i) {
            projects[i].first = capital[i];
            projects[i].second = profits[i];
        }
        sort(projects.begin(), projects.end(), greater<pair<int, int>>());
        priority_queue<int, vector<int>, less<int>> heap;  // 大根堆
        while (k--) {
            while (!projects.empty() && projects.back().first <= w) {
                heap.emplace(projects.back().second);
                projects.pop_back();
            }
            if (heap.empty()) {
                return w;
            }
            auto t = heap.top();
            w += t;
            heap.pop();
        }
        return w;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0502_H
