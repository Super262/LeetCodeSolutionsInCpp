//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0399_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0399_H

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    // 1. 转化为图论问题：变量为点，比值（乘法）为边
    // 2. Floyd 求解最短距离
public:
    vector<double> calcEquation(const vector<vector<string>> &equations,
                                const vector<double> &values,
                                const vector<vector<string>> &queries) {
        unordered_set<string> vertices;
        unordered_map<string, unordered_map<string, double>> dist;
        const auto n = (int) equations.size();
        vertices.reserve(n * 2);
        dist.reserve(n * 2);
        for (int i = 0; i < n; ++i) {
            auto &edge = equations[i];
            auto &d = values[i];
            vertices.insert(edge[0]);
            vertices.insert(edge[1]);
            dist[edge[0]][edge[1]] = d;
            dist[edge[1]][edge[0]] = 1 / d;
        }
        for (const auto &mid: vertices) {
            for (const auto &st: vertices) {
                for (const auto &ed: vertices) {
                    if (!dist[st].count(mid) || !dist[mid].count(ed)) {
                        continue;
                    }
                    dist[st][ed] = dist[st][mid] * dist[mid][ed];
                }
            }
        }
        vector<double> res;
        res.reserve(queries.size());
        for (const auto &q: queries) {
            if (!vertices.count(q[0]) || !vertices.count(q[1]) || !dist[q[0]].count(q[1])) {
                res.emplace_back(-1);
                continue;
            }
            res.emplace_back(dist[q[0]][q[1]]);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0399_H
