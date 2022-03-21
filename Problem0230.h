//
// Created by Fengwei Zhang on 9/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0230_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0230_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        int answer = -1;
        dfs(root, k, answer);
        return answer;
    }

private:
    bool dfs(TreeNode *root, int &k, int &answer) {
        if (!root) {
            return false;
        }
        if (dfs(root->left, k, answer)) {
            return true;
        }
        --k;
        if (k == 0) {
            answer = root->val;
            return true;
        }
        return dfs(root->right, k, answer);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0230_H
