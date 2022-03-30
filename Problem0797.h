//
// Created by Fengwei Zhang on 3/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0797_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0797_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(const vector<vector<int>> &graph) {
        vector<int> path;
        vector<vector<int>> ans;
        dfs(0, (int) graph.size() - 1, graph, path, ans);
        return ans;
    }

private:
    void dfs(int st, int ed, const vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &ans) {
        path.emplace_back(st);
        if (st == ed) {
            ans.emplace_back(path);
        }
        for (const auto &nv: graph[st]) {
            dfs(nv, ed, graph, path, ans);
        }
        path.pop_back();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0797_H
