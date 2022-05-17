//
// Created by Fengwei Zhang on 5/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0270_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0270_H

#include "treenode.h"
#include <algorithm>

using namespace std;

class Solution {
    // 类似二分查找
public:
    int closestValue(TreeNode *root, double target) {
        int ans = 0;
        double dist = 2e9;
        while (root) {
            auto t = abs(root->val - target);
            if (t < dist) {
                ans = root->val;
                dist = t;
            }
            if (target > root->val) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0270_H
