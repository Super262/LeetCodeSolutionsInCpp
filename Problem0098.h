//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0098_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0098_H

#include <vector>
#include <stack>
#include <string>
#include <cstring>

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
    bool isValidBST(const TreeNode *root) {
        if (!root) {
            return true;
        }
        return dfs(root)[0] == 1;
    }

private:
    vector<int> dfs(const TreeNode *root) {
        // result[0]：是否为BST
        // result[1]：当前树最大值
        // result[2]：当前树最小值
        vector<int> result = {1, root->val, root->val};

        if (root->left) {
            auto lt = dfs(root->left);
            if (lt[0] == 0 || lt[1] >= root->val) {
                result[0] = 0;
            }
            result[1] = max(result[1], lt[1]);
            result[2] = min(result[2], lt[2]);
        }
        if (root->right) {
            auto rt = dfs(root->right);
            if (rt[0] == 0 || rt[2] <= root->val) {
                result[0] = 0;
            }
            result[1] = max(result[1], rt[1]);
            result[2] = min(result[2], rt[2]);
        }

        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0098_H
