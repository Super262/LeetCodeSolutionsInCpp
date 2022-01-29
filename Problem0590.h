//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0590_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0590_H

#include <vector>

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
    vector<int> postorder(Node *root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

private:
    void dfs(Node *root, vector<int> &ans) {
        if (!root) {
            return;
        }
        for (const auto &ch: root->children) {
            dfs(ch, ans);
        }
        ans.emplace_back(root->val);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0590_H
