//
// Created by Fengwei Zhang on 11/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0133_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0133_H


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

class Problem0133 {
public:
    Node *cloneGraph(Node *root) {
        if (!root) {
            return root;
        }
        unordered_map < Node * , Node * > nodesCopied;
        dfs(root, nodesCopied);  // 复制所有点
        for (auto item: nodesCopied) {
            auto a = item.first;
            auto b = item.second;
            for (auto node: a->neighbors) {
                b->neighbors.emplace_back(nodesCopied[node]);
            }
        }
        return nodesCopied[root];
    }

    void dfs(Node *root, unordered_map<Node *, Node *> &nodesCopied) {
        nodesCopied[root] = new Node(root->val);
        for (auto node: root->neighbors) {
            if (nodesCopied.count(node)) {
                continue;
            }
            dfs(node, nodesCopied);
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0133_H
