//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0173_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0173_H


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {  // 类似第94题
private:
    TreeNode *root;
    stack<TreeNode *> stk;

public:
    BSTIterator(TreeNode *r) {
        root = r;
    }

    int next() {
        while (root) {
            stk.emplace(root);
            root = root->left;
        }

        root = stk.top();
        stk.pop();
        auto res = root->val;
        root = root->right;
        return res;
    }

    bool hasNext() {
        return !stk.empty() || root;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0173_H
