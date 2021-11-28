//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0429_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0429_H

#include <vector>
#include <queue>

using namespace std;


class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<Node *> q;
        q.emplace(root);
        while (!q.empty()) {
            auto current = (int) q.size();
            vector<int> level;
            while (current--) {
                auto node = q.front();
                q.pop();
                level.emplace_back(node->val);
                for (const auto child: node->children) {
                    q.emplace(child);
                }
            }
            res.emplace_back(level);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0429_H
