//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0373_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0373_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 多路归并
public:
    vector<vector<int>> kSmallestPairs(const vector<int> &a, const vector<int> &b, const int &k) {
        const auto &n = (int) a.size();
        const auto &m = (int) b.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
        for (int i = 0; i < m; ++i) {
            heap.push({a[0] + b[i], 0, i});
        }
        vector<vector<int>> res;
        while (!heap.empty() && res.size() < k) {
            auto t = heap.top();
            heap.pop();
            res.push_back({a[t[1]], b[t[2]]});
            if (t[1] + 1 < n) {
                heap.push({a[t[1] + 1] + b[t[2]], t[1] + 1, t[2]});
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0373_H
