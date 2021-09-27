//
// Created by Fengwei Zhang on 9/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0230_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0230_H

class Problem0230 {
private:
    bool dfs(TreeNode *root, int &k, int &answer) {
        if (!root) {
            return false;
        }
        dfs(root->left, k, answer);
        --k;
        if (k == 0) {
            answer = root->val;
            return true;
        }
        return dfs(root->right, k, answer);
    }

    int kthSmallest(TreeNode *root, int k) {
        int answer = -1;
        dfs(root, k, answer);
        return answer;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0230_H
