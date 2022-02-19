//
// Created by Fengwei Zhang on 2/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0690_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0690_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(const vector<Employee *> &employees, const int id) {
        unordered_map<int, Employee *> graph;
        for (const auto &e: employees) {
            graph[e->id] = e;
        }
        int res = 0;
        unordered_set<int> visited;
        queue<int> q;
        q.emplace(id);
        visited.insert(id);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            res += graph[t]->importance;
            for (const auto &e: graph[t]->subordinates) {
                if (visited.count(e)) {
                    continue;
                }
                q.emplace(e);
                visited.insert(e);
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0690_H
