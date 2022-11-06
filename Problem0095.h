//
// Created by Fengwei Zhang on 10/31/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0095_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0095_H

#include <vector>
#include "treenode.h"

using namespace std;

class Problem0095 {
    // DFS：设根结点的值为idx，那么左子树的节点值为[l:idx-1]、右子树[idx+1:r]
public:
    vector<TreeNode *> generateTrees(const int n) {
        return dfs(1, n);
    }

private:
    vector<TreeNode *> dfs(const int l, const int r) {
        vector<TreeNode *> res;
        if (l > r) {
            res.emplace_back(nullptr);
        }
        for (int idx = l; idx <= r; ++idx) {
            auto left_kids = dfs(l, idx - 1);
            auto right_kids = dfs(idx + 1, r);
            for (auto lk: left_kids) {
                for (auto rk: right_kids) {
                    res.emplace_back(new TreeNode(idx, lk, rk));
                }
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0095_H
