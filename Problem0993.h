//
// Created by Fengwei Zhang on 4/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0993_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0993_H

#include <algorithm>
#include "treenode.h"

using namespace std;

class Problem0993 {
    // 直接遍历，分别寻找x、y的父节点和深度
public:
    bool isCousins(TreeNode *root, int x, int y) {
        if (!root) {
            return false;
        }
        int p1 = -1;
        int l1 = 0;
        dfs(root, x, -1, 1, p1, l1);
        if (p1 == -1 || l1 == 0) {
            return false;
        }
        int p2 = -1;
        int l2 = 0;
        dfs(root, y, -1, 1, p2, l2);
        if (p2 == -1 || l2 == 0) {
            return false;
        }
        return p1 != p2 && l1 == l2;
    }

private:
    bool dfs(TreeNode *u, int x, int prev, int d, int &parent, int &level) {
        if (u->val == x) {
            level = d;
            parent = prev;
            return true;
        }
        if (u->left && dfs(u->left, x, u->val, d + 1, parent, level)) {
            return true;
        }
        if (u->right && dfs(u->right, x, u->val, d + 1, parent, level)) {
            return true;
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0993_H
