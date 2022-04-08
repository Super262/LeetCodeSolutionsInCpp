//
// Created by Fengwei Zhang on 4/7/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0871_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0871_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 贪心算法：若当前在位置i、目的地是j、fuel小于j，为减少加油次数，我们应在[i:j]段储量最多的一个加油站加油
public:
    int minRefuelStops(int target, int fuel, vector<vector<int>> &stations) {
        stations.push_back({target, 0});  // target > stations[i]
        int ans = 0;
        priority_queue<int, vector<int>, less<int>> heap;
        for (const auto &s: stations) {
            while (!heap.empty() && fuel < s[0]) {
                ++ans;
                fuel += heap.top();
                heap.pop();
            }
            if (fuel < s[0]) {
                return -1;
            }
            heap.emplace(s[1]);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0871_H
