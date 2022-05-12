//
// Created by Fengwei Zhang on 11/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0110_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0110_H

#include <algorithm>
#include "treenode.h"

using namespace std;

class Solution {
    // 经典算法，直接背诵
    // 自底向上，时间复杂度O(n)
public:
    bool isBalanced(TreeNode *root) {
        bool ans = true;
        dfs(root, ans);
        return ans;
    }

private:
    int dfs(TreeNode *root, bool &ans) {
        if (!root) {
            return 0;
        }
        auto lh = dfs(root->left, ans);
        if (lh == -1) {
            ans = false;
            return -1;
        }
        auto rh = dfs(root->right, ans);
        if (rh == -1) {
            ans = false;
            return -1;
        }
        if (abs(rh - lh) > 1) {
            ans = false;
            return -1;
        }
        return max(lh, rh) + 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0110_H
