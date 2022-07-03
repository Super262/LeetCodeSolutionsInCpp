//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0653_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0653_H

#include <unordered_set>
#include "treenode.h"

using namespace std;

class Solution {
    // 若给定有序数组a，找到和为k的2个数字，我们可以通过集合（保存已经遍历过的元素）实现
    // BST的中序是有序的，我们通过"中序遍历+集合"找到和为k的2个数字
public:
    bool findTarget(TreeNode *root, int k) {
        unordered_set<int> nums;
        return dfs(root, k, nums);
    }

private:
    bool dfs(TreeNode *root, int k, unordered_set<int> &nums) {  // 中序遍历，保证有序性
        if (!root) {
            return false;
        }
        if (dfs(root->left, k, nums)) {
            return true;
        }
        if (nums.count(k - root->val)) {
            return true;
        }
        nums.insert(root->val);
        return dfs(root->right, k, nums);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0653_H
