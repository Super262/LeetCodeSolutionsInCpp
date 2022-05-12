//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0098_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0098_H

#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include "treenode.h"

using namespace std;

class Solution {
    // DFS：记录子树的最值、合法性
public:
    bool isValidBST(const TreeNode *root) {
        if (!root) {
            return true;
        }
        return dfs(root).is_bst;
    }

private:
    struct Triad {
        bool is_bst;  // 是否为BST
        int maximal;  // 当前树最大值
        int minimal;  // 当前树最小值
    };

    Triad dfs(const TreeNode *root) {
        Triad ans = {true, root->val, root->val};

        if (root->left) {
            auto lt = dfs(root->left);
            if (!lt.is_bst || lt.maximal >= root->val) {  // 右子树最大值大于根，非法
                ans.is_bst = false;
                return ans;
            }
            ans.minimal = min(ans.minimal, lt.minimal);
        }
        if (root->right) {
            auto rt = dfs(root->right);
            if (!rt.is_bst || rt.minimal <= root->val) {  // 右子树最小值小于根，非法
                ans.is_bst = false;
                return ans;
            }
            ans.maximal = max(ans.maximal, rt.maximal);
        }

        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0098_H
