//
// Created by Fengwei Zhang on 12/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0298_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0298_H

#include <algorithm>

using namespace std;

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
    int longestConsecutive(TreeNode *root) {
        int answer = 0;
        dfs(root, answer);
        return answer;
    }

private:
    int dfs(TreeNode *root, int &answer) {
        if (!root) {
            return 0;
        }
        int result = 1;
        auto a = dfs(root->left, answer);
        auto b = dfs(root->right, answer);
        if (root->left && root->left->val == root->val + 1) {
            result = max(result, a + 1);
        }
        if (root->right && root->right->val == root->val + 1) {
            result = max(result, b + 1);
        }
        answer = max(answer, result);
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0298_H
