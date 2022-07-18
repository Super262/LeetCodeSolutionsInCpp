//
// Created by Fengwei Zhang on 7/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0742_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0742_H

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include  "treenode.h"

using namespace std;

class Solution {
    // 首先，我们先将这棵树转化为无向图，通过BFS实现；然后，我们以无向图中值为k的点为起点，搜索树中的叶节点，返回第1个叶节点
    // 判断叶节点：若a为根且a在图中没有邻接点，a是叶节点；若a不是根且a在图中最多有1个邻接点，a是叶节点
public:
    int findClosestLeaf(TreeNode *root, int k) {
        unordered_map<int, vector<int>> graph;
        buildGraph(root, graph);
        if (!graph.count(k)) {
            return -1;
        }
        unordered_set<int> visited;
        queue<int> q;
        q.emplace(k);  // 从值为k的点出发
        visited.insert(k);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if ((root->val == node && graph[node].empty()) || (root->val != node && graph[node].size() <= 1)) {
                return node;
            }
            for (const auto &v: graph[node]) {
                if (visited.count(v)) {
                    continue;
                }
                visited.insert(v);
                q.emplace(v);
            }
        }
        return -1;
    }

private:
    void buildGraph(TreeNode *root, unordered_map<int, vector<int>> &graph) {  // BFS建立无向图
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (!graph.count(node->val)) {
                graph[node->val] = vector<int>();
            }
            if (node->left) {
                graph[node->val].emplace_back(node->left->val);
                graph[node->left->val].emplace_back(node->val);
                q.emplace(node->left);
            }
            if (node->right) {
                graph[node->val].emplace_back(node->right->val);
                graph[node->right->val].emplace_back(node->val);
                q.emplace(node->right);
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0742_H
