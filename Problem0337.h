//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0337_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0337_H

#include <vector>
#include "treenode.h"

using namespace std;

class Solution {
    // f[u][0]：以u为根的树，不盗窃u时的最大获利；f[u][1]：以u为根的树，盗窃u时的最大获利
public:
    int rob(TreeNode *root) {
        if (!root) {
            return 0;
        }
        auto f = dfs(root);
        return max(f[0], f[1]);
    }

private:
    vector<int> dfs(TreeNode *root) {
        vector<int> f(2);
        f[0] = 0;
        f[1] = root->val;
        if (root->left) {
            auto t = dfs(root->left);
            f[1] += t[0];
            f[0] += max(t[0], t[1]);
        }
        if (root->right) {
            auto t = dfs(root->right);
            f[1] += t[0];
            f[0] += max(t[0], t[1]);
        }
        return f;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0337_H
