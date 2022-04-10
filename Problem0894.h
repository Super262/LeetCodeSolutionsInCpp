//
// Created by Fengwei Zhang on 4/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0894_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0894_H

#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
  */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // DFS，枚举左右子树的节点数量
    // 注意边界：n为偶数时，无解
public:
    vector<TreeNode *> allPossibleFBT(int n) {
        if (n % 2 == 0) {
            return {};
        }
        if (n == 1) {
            return {new TreeNode(0)};
        }
        vector<TreeNode *> ans;
        for (int length = 1; length <= n - 2; length += 2) {  // 枚举左子树的长度（1， 3， 5，……）
            auto lc = allPossibleFBT(length);
            auto rc = allPossibleFBT(n - 1 - length);
            for (const auto &l: lc) {
                for (const auto &r: rc) {
                    ans.emplace_back(new TreeNode(0, l, r));
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0894_H
