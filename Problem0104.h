//
// Created by Fengwei Zhang on 11/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0104_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0104_H

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

class Problem0104 {
public:
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0104_H
