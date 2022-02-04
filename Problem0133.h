//
// Created by Fengwei Zhang on 11/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0133_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0133_H

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    // BFS 解法
public:
    Node *cloneGraph(Node *root) {
        if (!root) {
            return root;
        }
        auto nodes_copied = bfs(root);
        for (const auto &item: nodes_copied) {
            for (const auto &ne: item.first->neighbors) {
                item.second->neighbors.emplace_back(nodes_copied[ne]);
            }
        }
        return nodes_copied[root];
    }

private:
    unordered_map<Node *, Node *> bfs(Node *root) {
        unordered_map<Node *, Node *> nodes_copied;
        queue<Node *> q;
        nodes_copied[root] = new Node(root->val);
        q.emplace(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (const auto &ne: node->neighbors) {
                if (nodes_copied.count(ne)) {
                    continue;
                }
                nodes_copied[ne] = new Node(ne->val);
                q.emplace(ne);
            }
        }
        return nodes_copied;
    }
};

/*class Solution {
    // DFS解法
public:
    Node *cloneGraph(Node *root) {
        if (!root) {
            return root;
        }
        unordered_map<Node *, Node *> nodes_copied;
        dfs(root, nodes_copied);  // 复制所有点
        for (auto item: nodes_copied) {
            auto a = item.first;
            auto b = item.second;
            for (auto node: a->neighbors) {
                b->neighbors.emplace_back(nodes_copied[node]);
            }
        }
        return nodes_copied[root];
    }

private:
    void dfs(Node *root, unordered_map<Node *, Node *> &nodes_copied) {
        nodes_copied[root] = new Node(root->val);
        for (auto node: root->neighbors) {
            if (nodes_copied.count(node)) {
                continue;
            }
            dfs(node, nodes_copied);
        }
    }
};*/

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0133_H
