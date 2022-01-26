//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0543_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0543_H

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
    int diameterOfBinaryTree(TreeNode *root) {
        int answer = 0;
        dfs(root, answer);
        return answer;
    }

private:
    int dfs(TreeNode *root, int &answer) {
        if (!root) {
            return 0;
        }
        auto l = dfs(root->left, answer);
        auto r = dfs(root->right, answer);
        answer = max(answer, l + r);
        return max(l, r) + 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0543_H
