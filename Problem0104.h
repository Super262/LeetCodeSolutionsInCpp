//
// Created by Fengwei Zhang on 11/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0104_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0104_H

#include <algorithm>
#include "treenode.h"

using namespace std;

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
