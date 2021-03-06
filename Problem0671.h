//
// Created by Fengwei Zhang on 2/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0671_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0671_H

#include <algorithm>
#include "treenode.h"

using namespace std;

class Solution {
    // 先序遍历，记录最小值和次小值；注意细节：x>d1&&x<d2时，更新d2=x
public:
    int findSecondMinimumValue(TreeNode *root) {
        long long d1 = 1ll + INT_MAX;
        auto d2 = d1;
        dfs(root, d1, d2);
        if (d2 == 1ll + INT_MAX) {
            return -1;
        }
        return (int) d2;
    }

private:
    void dfs(TreeNode *root, long long &d1, long long &d2) {
        if (!root) {
            return;
        }
        auto x = root->val;
        if (x < d1) {
            d2 = d1;
            d1 = x;
        } else if (x > d1 && x < d2) {
            d2 = x;
        }
        dfs(root->left, d1, d2);
        dfs(root->right, d1, d2);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0671_H
