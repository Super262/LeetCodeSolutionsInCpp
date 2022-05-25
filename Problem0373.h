//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0373_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0373_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 多路归并：初始时，压入所有a[0]+b[i]（0<=i<m）
public:
    vector<vector<int>> kSmallestPairs(const vector<int> &a, const vector<int> &b, const int &k) {
        const auto &n = (int) a.size();
        const auto &m = (int) b.size();
        priority_queue<Node, vector<Node>, nodeGreater> heap;
        for (int i = 0; i < m; ++i) {
            heap.push({a[0] + b[i], 0, i});
        }
        vector<vector<int>> ans;
        while (!heap.empty() && (int) ans.size() < k) {
            auto t = heap.top();
            heap.pop();
            ans.push_back({a[t.p1], b[t.p2]});
            if (t.p1 + 1 < n) {
                heap.push({a[t.p1 + 1] + b[t.p2], t.p1 + 1, t.p2});
            }
        }
        return ans;
    }

private:
    struct Node {
        int sum;
        int p1;
        int p2;
    };

    struct nodeGreater {
        bool operator()(const Node &a, const Node &b) {
            return a.sum > b.sum;
        }
    };
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0373_H
