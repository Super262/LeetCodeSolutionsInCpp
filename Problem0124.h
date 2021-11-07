//
// Created by Fengwei Zhang on 11/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0124_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0124_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Problem0124 {
public:
    int maxPathSum(TreeNode *root) {
        int answer = -0x3f3f3f3f;
        dfs(root, answer);
        return answer;
    }

    int dfs(TreeNode *root, int &answer) {
        if (!root) {
            return 0;
        }
        auto ls = max(0, dfs(root->left, answer));
        auto rs = max(0, dfs(root->right, answer));
        answer = max(answer, ls + rs + root->val);
        return max(ls, rs) + root->val;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0124_H
