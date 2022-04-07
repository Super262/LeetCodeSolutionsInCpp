//
// Created by Fengwei Zhang on 4/7/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0863_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0863_H

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    // 通过DFS建立无向图，保存前驱和后继关系
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        if (!root) {
            return {};
        }
        unordered_map<TreeNode *, vector<TreeNode *>> graph;
        buildGraph(root, graph);
        return bfs(target, k, graph);
    }

private:
    void buildGraph(TreeNode *root, unordered_map<TreeNode *, vector<TreeNode *>> &graph) {
        if (root->left) {
            graph[root].emplace_back(root->left);
            graph[root->left].emplace_back(root);
            buildGraph(root->left, graph);
        }
        if (root->right) {
            graph[root].emplace_back(root->right);
            graph[root->right].emplace_back(root);
            buildGraph(root->right, graph);
        }
    }

    vector<int> bfs(TreeNode *target, int k, unordered_map<TreeNode *, vector<TreeNode *>> &graph) {
        if (!graph.count(target)) {
            return {};
        }
        if (!k) {
            return {target->val};
        }
        vector<int> ans;
        unordered_map<TreeNode *, int> dist;
        queue<TreeNode *> q;
        dist[target] = 0;
        q.emplace(target);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            auto ud = dist[u];
            for (const auto &v: graph[u]) {
                if (dist.count(v)) {
                    continue;
                }
                dist[v] = ud + 1;
                q.emplace(v);
                if (ud + 1 == k) {
                    ans.emplace_back(v->val);
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0863_H
