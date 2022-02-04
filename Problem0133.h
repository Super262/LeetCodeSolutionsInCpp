//
// Created by Fengwei Zhang on 11/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0133_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0133_H

#include <vector>
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
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0133_H
