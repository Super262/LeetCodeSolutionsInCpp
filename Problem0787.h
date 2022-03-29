//
// Created by Fengwei Zhang on 10/19/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0787_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0787_H

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        int dist[2][n + 1];
        memset(dist[0], 0x3f, sizeof dist[0]);
        dist[0][src] = 0;
        for (int i = 1; i <= k + 1; ++i) {
            memcpy(dist[i % 2], dist[(i - 1) % 2], sizeof dist[(i - 1) % 2]);
            for (auto &e: flights) {
                dist[i % 2][e[1]] = min(dist[i % 2][e[1]], dist[(i - 1) % 2][e[0]] + e[2]);
            }
        }
        if (dist[(k + 1) % 2][dst] == 0x3f3f3f3f) {
            return -1;
        }
        return dist[(k + 1) % 2][dst];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0787_H
