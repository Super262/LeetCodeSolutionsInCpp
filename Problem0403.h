//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0403_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0403_H

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
    // BFS：https://www.acwing.com/solution/content/4597/
    // 现在所处的石子编号为 i 时，上一次跳跃距离 k 必定满足 k ≤ i
public:
    bool canCross(const vector<int> &stones) {
        unordered_map<int, int> pos2Idx;
        const int n = (int) stones.size();
        for (int i = 0; i < n; ++i) {
            pos2Idx[stones[i]] = i;
        }
        queue<pair<int, int>> q;  // q 存放当前节点索引和上一步的步数
        // visited[i][k] = true 表示索引为i的石子在上次步数为时被访问
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.emplace(0, 0);
        visited[0][0] = true;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t.first == n - 1) {
                return true;
            }
            auto idx = t.first;
            auto steps = t.second;
            for (int d = -1; d <= 1; ++d) {
                auto ns = steps + d;
                if (ns <= 0 || !pos2Idx.count(stones[idx] + ns)) {
                    continue;
                }
                auto nidx = pos2Idx[stones[idx] + ns];
                if (visited[nidx][ns]) {
                    continue;
                }
                visited[nidx][ns] = true;
                q.emplace(nidx, ns);
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0403_H
